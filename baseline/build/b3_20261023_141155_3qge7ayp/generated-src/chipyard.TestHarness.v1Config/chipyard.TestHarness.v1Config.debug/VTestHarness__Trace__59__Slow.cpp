// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "VTestHarness__Syms.h"


VL_ATTR_COLD void VTestHarness___024root__trace_full_sub_36(VTestHarness___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root__trace_full_sub_36\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    VlWide<3>/*95:0*/ __Vtemp_h625a5317__0;
    VlWide<3>/*95:0*/ __Vtemp_h87c3cf5c__0;
    VlWide<4>/*127:0*/ __Vtemp_h63bd5b97__1;
    VlWide<4>/*127:0*/ __Vtemp_he59c122e__0;
    VlWide<4>/*127:0*/ __Vtemp_h06eca2c9__0;
    VlWide<3>/*95:0*/ __Vtemp_hb40f5a47__0;
    VlWide<4>/*127:0*/ __Vtemp_h609d58e5__0;
    VlWide<4>/*127:0*/ __Vtemp_hdd2fea63__0;
    VlWide<8>/*255:0*/ __Vtemp_hd2f4e267__0;
    VlWide<8>/*255:0*/ __Vtemp_hc0264752__0;
    VlWide<16>/*511:0*/ __Vtemp_he1409196__0;
    VlWide<4>/*127:0*/ __Vtemp_had263a02__0;
    VlWide<3>/*95:0*/ __Vtemp_hfced7cac__0;
    VlWide<3>/*95:0*/ __Vtemp_h2114abef__0;
    VlWide<4>/*127:0*/ __Vtemp_h30fe9863__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__0;
    VlWide<4>/*127:0*/ __Vtemp_h525c8084__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__1;
    VlWide<4>/*127:0*/ __Vtemp_hddf42d01__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__2;
    VlWide<4>/*127:0*/ __Vtemp_h104e453a__0;
    VlWide<3>/*95:0*/ __Vtemp_ha148f9f6__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__3;
    VlWide<4>/*127:0*/ __Vtemp_h6538aca7__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__4;
    VlWide<4>/*127:0*/ __Vtemp_h1c4b2ef6__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__5;
    VlWide<4>/*127:0*/ __Vtemp_h1d30006e__0;
    VlWide<4>/*127:0*/ __Vtemp_h155f73d9__0;
    VlWide<4>/*127:0*/ __Vtemp_hc9e6dfeb__0;
    VlWide<4>/*127:0*/ __Vtemp_h0e0d11fb__0;
    VlWide<5>/*159:0*/ __Vtemp_hd6f6d71f__0;
    VlWide<3>/*95:0*/ __Vtemp_h9e2d2b73__0;
    VlWide<8>/*255:0*/ __Vtemp_ha67e93b3__0;
    // Body
    bufp->fullBit(oldp+106221,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_taken));
    bufp->fullIData(oldp+106222,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_imm_packed),20);
    bufp->fullSData(oldp+106223,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_csr_addr),12);
    bufp->fullCData(oldp+106224,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_rob_idx),7);
    bufp->fullCData(oldp+106225,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_ldq_idx),5);
    bufp->fullCData(oldp+106226,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_stq_idx),5);
    bufp->fullCData(oldp+106227,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_rxq_idx),2);
    bufp->fullCData(oldp+106228,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_pdst),7);
    bufp->fullCData(oldp+106229,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_prs1),7);
    bufp->fullCData(oldp+106230,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_prs2),7);
    bufp->fullCData(oldp+106231,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_prs3),7);
    bufp->fullCData(oldp+106232,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_ppred),5);
    bufp->fullBit(oldp+106233,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_prs1_busy));
    bufp->fullBit(oldp+106234,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_prs2_busy));
    bufp->fullBit(oldp+106235,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_prs3_busy));
    bufp->fullBit(oldp+106236,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_ppred_busy));
    bufp->fullCData(oldp+106237,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_stale_pdst),7);
    bufp->fullBit(oldp+106238,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_exception));
    bufp->fullQData(oldp+106239,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_exc_cause),64);
    bufp->fullBit(oldp+106241,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_bypassable));
    bufp->fullCData(oldp+106242,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_mem_cmd),5);
    bufp->fullCData(oldp+106243,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_mem_size),2);
    bufp->fullBit(oldp+106244,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_mem_signed));
    bufp->fullBit(oldp+106245,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_is_fence));
    bufp->fullBit(oldp+106246,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_is_fencei));
    bufp->fullBit(oldp+106247,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_is_amo));
    bufp->fullBit(oldp+106248,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_is_csr));
    bufp->fullBit(oldp+106249,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_uses_ldq));
    bufp->fullBit(oldp+106250,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_uses_stq));
    bufp->fullBit(oldp+106251,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_is_sys_pc2epc));
    bufp->fullBit(oldp+106252,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_is_unique));
    bufp->fullBit(oldp+106253,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_flush_on_commit));
    bufp->fullBit(oldp+106254,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_ldst_is_rs1));
    bufp->fullCData(oldp+106255,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_ldst),6);
    bufp->fullCData(oldp+106256,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_lrs1),6);
    bufp->fullCData(oldp+106257,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_lrs2),6);
    bufp->fullCData(oldp+106258,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_lrs3),6);
    bufp->fullBit(oldp+106259,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_ldst_val));
    bufp->fullCData(oldp+106260,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_dst_rtype),2);
    bufp->fullCData(oldp+106261,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_lrs1_rtype),2);
    bufp->fullCData(oldp+106262,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_lrs2_rtype),2);
    bufp->fullBit(oldp+106263,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_frs3_en));
    bufp->fullBit(oldp+106264,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_fp_val));
    bufp->fullBit(oldp+106265,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_fp_single));
    bufp->fullBit(oldp+106266,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_xcpt_pf_if));
    bufp->fullBit(oldp+106267,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_xcpt_ae_if));
    bufp->fullBit(oldp+106268,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_xcpt_ma_if));
    bufp->fullBit(oldp+106269,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_bp_debug_if));
    bufp->fullBit(oldp+106270,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_bp_xcpt_if));
    bufp->fullCData(oldp+106271,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_debug_fsrc),2);
    bufp->fullCData(oldp+106272,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_uop_debug_tsrc),2);
    bufp->fullBit(oldp+106273,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_addr_valid));
    bufp->fullQData(oldp+106274,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_addr_bits),40);
    bufp->fullQData(oldp+106276,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_vaddr_bits),40);
    bufp->fullBit(oldp+106278,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_addr_is_virtual));
    bufp->fullBit(oldp+106279,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_data_valid));
    bufp->fullQData(oldp+106280,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_data_bits),64);
    bufp->fullBit(oldp+106282,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_committed));
    bufp->fullBit(oldp+106283,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_succeeded));
    bufp->fullBit(oldp+106284,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_valid));
    bufp->fullCData(oldp+106285,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_uopc),7);
    bufp->fullIData(oldp+106286,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_inst),32);
    bufp->fullIData(oldp+106287,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_debug_inst),32);
    bufp->fullBit(oldp+106288,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_is_rvc));
    bufp->fullQData(oldp+106289,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_debug_pc),40);
    bufp->fullCData(oldp+106291,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_iq_type),3);
    bufp->fullSData(oldp+106292,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_fu_code),10);
    bufp->fullCData(oldp+106293,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_ctrl_br_type),4);
    bufp->fullCData(oldp+106294,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_ctrl_op1_sel),2);
    bufp->fullCData(oldp+106295,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_ctrl_op2_sel),3);
    bufp->fullCData(oldp+106296,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_ctrl_imm_sel),3);
    bufp->fullCData(oldp+106297,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_ctrl_op_fcn),4);
    bufp->fullBit(oldp+106298,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_ctrl_fcn_dw));
    bufp->fullCData(oldp+106299,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_ctrl_csr_cmd),3);
    bufp->fullBit(oldp+106300,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_ctrl_is_load));
    bufp->fullBit(oldp+106301,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_ctrl_is_sta));
    bufp->fullBit(oldp+106302,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_ctrl_is_std));
    bufp->fullCData(oldp+106303,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_iw_state),2);
    bufp->fullBit(oldp+106304,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_iw_p1_poisoned));
    bufp->fullBit(oldp+106305,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_iw_p2_poisoned));
    bufp->fullBit(oldp+106306,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_is_br));
    bufp->fullBit(oldp+106307,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_is_jalr));
    bufp->fullBit(oldp+106308,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_is_jal));
    bufp->fullBit(oldp+106309,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_is_sfb));
    bufp->fullSData(oldp+106310,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_br_mask),16);
    bufp->fullCData(oldp+106311,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_br_tag),4);
    bufp->fullCData(oldp+106312,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_ftq_idx),5);
    bufp->fullBit(oldp+106313,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_edge_inst));
    bufp->fullCData(oldp+106314,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_pc_lob),6);
    bufp->fullBit(oldp+106315,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_taken));
    bufp->fullIData(oldp+106316,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_imm_packed),20);
    bufp->fullSData(oldp+106317,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_csr_addr),12);
    bufp->fullCData(oldp+106318,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_rob_idx),7);
    bufp->fullCData(oldp+106319,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_ldq_idx),5);
    bufp->fullCData(oldp+106320,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_stq_idx),5);
    bufp->fullCData(oldp+106321,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_rxq_idx),2);
    bufp->fullCData(oldp+106322,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_pdst),7);
    bufp->fullCData(oldp+106323,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_prs1),7);
    bufp->fullCData(oldp+106324,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_prs2),7);
    bufp->fullCData(oldp+106325,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_prs3),7);
    bufp->fullCData(oldp+106326,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_ppred),5);
    bufp->fullBit(oldp+106327,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_prs1_busy));
    bufp->fullBit(oldp+106328,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_prs2_busy));
    bufp->fullBit(oldp+106329,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_prs3_busy));
    bufp->fullBit(oldp+106330,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_ppred_busy));
    bufp->fullCData(oldp+106331,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_stale_pdst),7);
    bufp->fullBit(oldp+106332,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_exception));
    bufp->fullQData(oldp+106333,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_exc_cause),64);
    bufp->fullBit(oldp+106335,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_bypassable));
    bufp->fullCData(oldp+106336,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_mem_cmd),5);
    bufp->fullCData(oldp+106337,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_mem_size),2);
    bufp->fullBit(oldp+106338,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_mem_signed));
    bufp->fullBit(oldp+106339,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_is_fence));
    bufp->fullBit(oldp+106340,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_is_fencei));
    bufp->fullBit(oldp+106341,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_is_amo));
    bufp->fullBit(oldp+106342,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_is_csr));
    bufp->fullBit(oldp+106343,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_uses_ldq));
    bufp->fullBit(oldp+106344,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_uses_stq));
    bufp->fullBit(oldp+106345,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_is_sys_pc2epc));
    bufp->fullBit(oldp+106346,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_is_unique));
    bufp->fullBit(oldp+106347,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_flush_on_commit));
    bufp->fullBit(oldp+106348,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_ldst_is_rs1));
    bufp->fullCData(oldp+106349,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_ldst),6);
    bufp->fullCData(oldp+106350,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_lrs1),6);
    bufp->fullCData(oldp+106351,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_lrs2),6);
    bufp->fullCData(oldp+106352,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_lrs3),6);
    bufp->fullBit(oldp+106353,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_ldst_val));
    bufp->fullCData(oldp+106354,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_dst_rtype),2);
    bufp->fullCData(oldp+106355,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_lrs1_rtype),2);
    bufp->fullCData(oldp+106356,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_lrs2_rtype),2);
    bufp->fullBit(oldp+106357,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_frs3_en));
    bufp->fullBit(oldp+106358,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_fp_val));
    bufp->fullBit(oldp+106359,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_fp_single));
    bufp->fullBit(oldp+106360,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_xcpt_pf_if));
    bufp->fullBit(oldp+106361,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_xcpt_ae_if));
    bufp->fullBit(oldp+106362,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_xcpt_ma_if));
    bufp->fullBit(oldp+106363,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_bp_debug_if));
    bufp->fullBit(oldp+106364,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_bp_xcpt_if));
    bufp->fullCData(oldp+106365,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_debug_fsrc),2);
    bufp->fullCData(oldp+106366,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_uop_debug_tsrc),2);
    bufp->fullBit(oldp+106367,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_addr_valid));
    bufp->fullQData(oldp+106368,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_addr_bits),40);
    bufp->fullQData(oldp+106370,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_vaddr_bits),40);
    bufp->fullBit(oldp+106372,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_addr_is_virtual));
    bufp->fullBit(oldp+106373,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_data_valid));
    bufp->fullQData(oldp+106374,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_data_bits),64);
    bufp->fullBit(oldp+106376,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_committed));
    bufp->fullBit(oldp+106377,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_succeeded));
    bufp->fullBit(oldp+106378,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_valid));
    bufp->fullCData(oldp+106379,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_uopc),7);
    bufp->fullIData(oldp+106380,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_inst),32);
    bufp->fullIData(oldp+106381,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_debug_inst),32);
    bufp->fullBit(oldp+106382,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_is_rvc));
    bufp->fullQData(oldp+106383,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_debug_pc),40);
    bufp->fullCData(oldp+106385,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_iq_type),3);
    bufp->fullSData(oldp+106386,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_fu_code),10);
    bufp->fullCData(oldp+106387,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_ctrl_br_type),4);
    bufp->fullCData(oldp+106388,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_ctrl_op1_sel),2);
    bufp->fullCData(oldp+106389,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_ctrl_op2_sel),3);
    bufp->fullCData(oldp+106390,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_ctrl_imm_sel),3);
    bufp->fullCData(oldp+106391,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_ctrl_op_fcn),4);
    bufp->fullBit(oldp+106392,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_ctrl_fcn_dw));
    bufp->fullCData(oldp+106393,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_ctrl_csr_cmd),3);
    bufp->fullBit(oldp+106394,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_ctrl_is_load));
    bufp->fullBit(oldp+106395,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_ctrl_is_sta));
    bufp->fullBit(oldp+106396,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_ctrl_is_std));
    bufp->fullCData(oldp+106397,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_iw_state),2);
    bufp->fullBit(oldp+106398,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_iw_p1_poisoned));
    bufp->fullBit(oldp+106399,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_iw_p2_poisoned));
    bufp->fullBit(oldp+106400,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_is_br));
    bufp->fullBit(oldp+106401,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_is_jalr));
    bufp->fullBit(oldp+106402,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_is_jal));
    bufp->fullBit(oldp+106403,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_is_sfb));
    bufp->fullSData(oldp+106404,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_br_mask),16);
    bufp->fullCData(oldp+106405,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_br_tag),4);
    bufp->fullCData(oldp+106406,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_ftq_idx),5);
    bufp->fullBit(oldp+106407,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_edge_inst));
    bufp->fullCData(oldp+106408,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_pc_lob),6);
    bufp->fullBit(oldp+106409,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_taken));
    bufp->fullIData(oldp+106410,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_imm_packed),20);
    bufp->fullSData(oldp+106411,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_csr_addr),12);
    bufp->fullCData(oldp+106412,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_rob_idx),7);
    bufp->fullCData(oldp+106413,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_ldq_idx),5);
    bufp->fullCData(oldp+106414,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_stq_idx),5);
    bufp->fullCData(oldp+106415,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_rxq_idx),2);
    bufp->fullCData(oldp+106416,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_pdst),7);
    bufp->fullCData(oldp+106417,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_prs1),7);
    bufp->fullCData(oldp+106418,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_prs2),7);
    bufp->fullCData(oldp+106419,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_prs3),7);
    bufp->fullCData(oldp+106420,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_ppred),5);
    bufp->fullBit(oldp+106421,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_prs1_busy));
    bufp->fullBit(oldp+106422,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_prs2_busy));
    bufp->fullBit(oldp+106423,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_prs3_busy));
    bufp->fullBit(oldp+106424,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_ppred_busy));
    bufp->fullCData(oldp+106425,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_stale_pdst),7);
    bufp->fullBit(oldp+106426,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_exception));
    bufp->fullQData(oldp+106427,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_exc_cause),64);
    bufp->fullBit(oldp+106429,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_bypassable));
    bufp->fullCData(oldp+106430,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_mem_cmd),5);
    bufp->fullCData(oldp+106431,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_mem_size),2);
    bufp->fullBit(oldp+106432,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_mem_signed));
    bufp->fullBit(oldp+106433,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_is_fence));
    bufp->fullBit(oldp+106434,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_is_fencei));
    bufp->fullBit(oldp+106435,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_is_amo));
    bufp->fullBit(oldp+106436,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_is_csr));
    bufp->fullBit(oldp+106437,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_uses_ldq));
    bufp->fullBit(oldp+106438,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_uses_stq));
    bufp->fullBit(oldp+106439,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_is_sys_pc2epc));
    bufp->fullBit(oldp+106440,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_is_unique));
    bufp->fullBit(oldp+106441,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_flush_on_commit));
    bufp->fullBit(oldp+106442,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_ldst_is_rs1));
    bufp->fullCData(oldp+106443,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_ldst),6);
    bufp->fullCData(oldp+106444,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_lrs1),6);
    bufp->fullCData(oldp+106445,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_lrs2),6);
    bufp->fullCData(oldp+106446,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_lrs3),6);
    bufp->fullBit(oldp+106447,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_ldst_val));
    bufp->fullCData(oldp+106448,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_dst_rtype),2);
    bufp->fullCData(oldp+106449,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_lrs1_rtype),2);
    bufp->fullCData(oldp+106450,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_lrs2_rtype),2);
    bufp->fullBit(oldp+106451,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_frs3_en));
    bufp->fullBit(oldp+106452,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_fp_val));
    bufp->fullBit(oldp+106453,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_fp_single));
    bufp->fullBit(oldp+106454,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_xcpt_pf_if));
    bufp->fullBit(oldp+106455,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_xcpt_ae_if));
    bufp->fullBit(oldp+106456,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_xcpt_ma_if));
    bufp->fullBit(oldp+106457,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_bp_debug_if));
    bufp->fullBit(oldp+106458,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_bp_xcpt_if));
    bufp->fullCData(oldp+106459,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_debug_fsrc),2);
    bufp->fullCData(oldp+106460,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_uop_debug_tsrc),2);
    bufp->fullBit(oldp+106461,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_addr_valid));
    bufp->fullQData(oldp+106462,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_addr_bits),40);
    bufp->fullQData(oldp+106464,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_vaddr_bits),40);
    bufp->fullBit(oldp+106466,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_addr_is_virtual));
    bufp->fullBit(oldp+106467,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_data_valid));
    bufp->fullQData(oldp+106468,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_data_bits),64);
    bufp->fullBit(oldp+106470,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_committed));
    bufp->fullBit(oldp+106471,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_succeeded));
    bufp->fullBit(oldp+106472,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_valid));
    bufp->fullCData(oldp+106473,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_uopc),7);
    bufp->fullIData(oldp+106474,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_inst),32);
    bufp->fullIData(oldp+106475,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_debug_inst),32);
    bufp->fullBit(oldp+106476,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_is_rvc));
    bufp->fullQData(oldp+106477,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_debug_pc),40);
    bufp->fullCData(oldp+106479,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_iq_type),3);
    bufp->fullSData(oldp+106480,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_fu_code),10);
    bufp->fullCData(oldp+106481,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_ctrl_br_type),4);
    bufp->fullCData(oldp+106482,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_ctrl_op1_sel),2);
    bufp->fullCData(oldp+106483,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_ctrl_op2_sel),3);
    bufp->fullCData(oldp+106484,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_ctrl_imm_sel),3);
    bufp->fullCData(oldp+106485,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_ctrl_op_fcn),4);
    bufp->fullBit(oldp+106486,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_ctrl_fcn_dw));
    bufp->fullCData(oldp+106487,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_ctrl_csr_cmd),3);
    bufp->fullBit(oldp+106488,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_ctrl_is_load));
    bufp->fullBit(oldp+106489,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_ctrl_is_sta));
    bufp->fullBit(oldp+106490,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_ctrl_is_std));
    bufp->fullCData(oldp+106491,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_iw_state),2);
    bufp->fullBit(oldp+106492,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_iw_p1_poisoned));
    bufp->fullBit(oldp+106493,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_iw_p2_poisoned));
    bufp->fullBit(oldp+106494,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_is_br));
    bufp->fullBit(oldp+106495,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_is_jalr));
    bufp->fullBit(oldp+106496,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_is_jal));
    bufp->fullBit(oldp+106497,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_is_sfb));
    bufp->fullSData(oldp+106498,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_br_mask),16);
    bufp->fullCData(oldp+106499,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_br_tag),4);
    bufp->fullCData(oldp+106500,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_ftq_idx),5);
    bufp->fullBit(oldp+106501,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_edge_inst));
    bufp->fullCData(oldp+106502,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_pc_lob),6);
    bufp->fullBit(oldp+106503,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_taken));
    bufp->fullIData(oldp+106504,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_imm_packed),20);
    bufp->fullSData(oldp+106505,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_csr_addr),12);
    bufp->fullCData(oldp+106506,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_rob_idx),7);
    bufp->fullCData(oldp+106507,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_ldq_idx),5);
    bufp->fullCData(oldp+106508,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_stq_idx),5);
    bufp->fullCData(oldp+106509,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_rxq_idx),2);
    bufp->fullCData(oldp+106510,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_pdst),7);
    bufp->fullCData(oldp+106511,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_prs1),7);
    bufp->fullCData(oldp+106512,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_prs2),7);
    bufp->fullCData(oldp+106513,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_prs3),7);
    bufp->fullCData(oldp+106514,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_ppred),5);
    bufp->fullBit(oldp+106515,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_prs1_busy));
    bufp->fullBit(oldp+106516,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_prs2_busy));
    bufp->fullBit(oldp+106517,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_prs3_busy));
    bufp->fullBit(oldp+106518,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_ppred_busy));
    bufp->fullCData(oldp+106519,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_stale_pdst),7);
    bufp->fullBit(oldp+106520,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_exception));
    bufp->fullQData(oldp+106521,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_exc_cause),64);
    bufp->fullBit(oldp+106523,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_bypassable));
    bufp->fullCData(oldp+106524,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_mem_cmd),5);
    bufp->fullCData(oldp+106525,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_mem_size),2);
    bufp->fullBit(oldp+106526,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_mem_signed));
    bufp->fullBit(oldp+106527,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_is_fence));
    bufp->fullBit(oldp+106528,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_is_fencei));
    bufp->fullBit(oldp+106529,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_is_amo));
    bufp->fullBit(oldp+106530,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_is_csr));
    bufp->fullBit(oldp+106531,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_uses_ldq));
    bufp->fullBit(oldp+106532,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_uses_stq));
    bufp->fullBit(oldp+106533,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_is_sys_pc2epc));
    bufp->fullBit(oldp+106534,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_is_unique));
    bufp->fullBit(oldp+106535,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_flush_on_commit));
    bufp->fullBit(oldp+106536,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_ldst_is_rs1));
    bufp->fullCData(oldp+106537,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_ldst),6);
    bufp->fullCData(oldp+106538,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_lrs1),6);
    bufp->fullCData(oldp+106539,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_lrs2),6);
    bufp->fullCData(oldp+106540,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_lrs3),6);
    bufp->fullBit(oldp+106541,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_ldst_val));
    bufp->fullCData(oldp+106542,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_dst_rtype),2);
    bufp->fullCData(oldp+106543,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_lrs1_rtype),2);
    bufp->fullCData(oldp+106544,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_lrs2_rtype),2);
    bufp->fullBit(oldp+106545,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_frs3_en));
    bufp->fullBit(oldp+106546,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_fp_val));
    bufp->fullBit(oldp+106547,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_fp_single));
    bufp->fullBit(oldp+106548,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_xcpt_pf_if));
    bufp->fullBit(oldp+106549,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_xcpt_ae_if));
    bufp->fullBit(oldp+106550,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_xcpt_ma_if));
    bufp->fullBit(oldp+106551,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_bp_debug_if));
    bufp->fullBit(oldp+106552,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_bp_xcpt_if));
    bufp->fullCData(oldp+106553,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_debug_fsrc),2);
    bufp->fullCData(oldp+106554,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_uop_debug_tsrc),2);
    bufp->fullBit(oldp+106555,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_addr_valid));
    bufp->fullQData(oldp+106556,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_addr_bits),40);
    bufp->fullQData(oldp+106558,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_vaddr_bits),40);
    bufp->fullBit(oldp+106560,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_addr_is_virtual));
    bufp->fullBit(oldp+106561,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_data_valid));
    bufp->fullQData(oldp+106562,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_data_bits),64);
    bufp->fullBit(oldp+106564,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_committed));
    bufp->fullBit(oldp+106565,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_succeeded));
    bufp->fullBit(oldp+106566,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_valid));
    bufp->fullCData(oldp+106567,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_uopc),7);
    bufp->fullIData(oldp+106568,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_inst),32);
    bufp->fullIData(oldp+106569,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_debug_inst),32);
    bufp->fullBit(oldp+106570,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_is_rvc));
    bufp->fullQData(oldp+106571,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_debug_pc),40);
    bufp->fullCData(oldp+106573,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_iq_type),3);
    bufp->fullSData(oldp+106574,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_fu_code),10);
    bufp->fullCData(oldp+106575,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_ctrl_br_type),4);
    bufp->fullCData(oldp+106576,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_ctrl_op1_sel),2);
    bufp->fullCData(oldp+106577,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_ctrl_op2_sel),3);
    bufp->fullCData(oldp+106578,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_ctrl_imm_sel),3);
    bufp->fullCData(oldp+106579,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_ctrl_op_fcn),4);
    bufp->fullBit(oldp+106580,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_ctrl_fcn_dw));
    bufp->fullCData(oldp+106581,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_ctrl_csr_cmd),3);
    bufp->fullBit(oldp+106582,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_ctrl_is_load));
    bufp->fullBit(oldp+106583,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_ctrl_is_sta));
    bufp->fullBit(oldp+106584,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_ctrl_is_std));
    bufp->fullCData(oldp+106585,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_iw_state),2);
    bufp->fullBit(oldp+106586,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_iw_p1_poisoned));
    bufp->fullBit(oldp+106587,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_iw_p2_poisoned));
    bufp->fullBit(oldp+106588,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_is_br));
    bufp->fullBit(oldp+106589,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_is_jalr));
    bufp->fullBit(oldp+106590,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_is_jal));
    bufp->fullBit(oldp+106591,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_is_sfb));
    bufp->fullSData(oldp+106592,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_br_mask),16);
    bufp->fullCData(oldp+106593,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_br_tag),4);
    bufp->fullCData(oldp+106594,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_ftq_idx),5);
    bufp->fullBit(oldp+106595,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_edge_inst));
    bufp->fullCData(oldp+106596,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_pc_lob),6);
    bufp->fullBit(oldp+106597,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_taken));
    bufp->fullIData(oldp+106598,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_imm_packed),20);
    bufp->fullSData(oldp+106599,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_csr_addr),12);
    bufp->fullCData(oldp+106600,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_rob_idx),7);
    bufp->fullCData(oldp+106601,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_ldq_idx),5);
    bufp->fullCData(oldp+106602,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_stq_idx),5);
    bufp->fullCData(oldp+106603,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_rxq_idx),2);
    bufp->fullCData(oldp+106604,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_pdst),7);
    bufp->fullCData(oldp+106605,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_prs1),7);
    bufp->fullCData(oldp+106606,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_prs2),7);
    bufp->fullCData(oldp+106607,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_prs3),7);
    bufp->fullCData(oldp+106608,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_ppred),5);
    bufp->fullBit(oldp+106609,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_prs1_busy));
    bufp->fullBit(oldp+106610,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_prs2_busy));
    bufp->fullBit(oldp+106611,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_prs3_busy));
    bufp->fullBit(oldp+106612,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_ppred_busy));
    bufp->fullCData(oldp+106613,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_stale_pdst),7);
    bufp->fullBit(oldp+106614,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_exception));
    bufp->fullQData(oldp+106615,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_exc_cause),64);
    bufp->fullBit(oldp+106617,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_bypassable));
    bufp->fullCData(oldp+106618,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_mem_cmd),5);
    bufp->fullCData(oldp+106619,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_mem_size),2);
    bufp->fullBit(oldp+106620,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_mem_signed));
    bufp->fullBit(oldp+106621,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_is_fence));
    bufp->fullBit(oldp+106622,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_is_fencei));
    bufp->fullBit(oldp+106623,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_is_amo));
    bufp->fullBit(oldp+106624,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_is_csr));
    bufp->fullBit(oldp+106625,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_uses_ldq));
    bufp->fullBit(oldp+106626,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_uses_stq));
    bufp->fullBit(oldp+106627,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_is_sys_pc2epc));
    bufp->fullBit(oldp+106628,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_is_unique));
    bufp->fullBit(oldp+106629,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_flush_on_commit));
    bufp->fullBit(oldp+106630,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_ldst_is_rs1));
    bufp->fullCData(oldp+106631,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_ldst),6);
    bufp->fullCData(oldp+106632,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_lrs1),6);
    bufp->fullCData(oldp+106633,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_lrs2),6);
    bufp->fullCData(oldp+106634,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_lrs3),6);
    bufp->fullBit(oldp+106635,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_ldst_val));
    bufp->fullCData(oldp+106636,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_dst_rtype),2);
    bufp->fullCData(oldp+106637,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_lrs1_rtype),2);
    bufp->fullCData(oldp+106638,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_lrs2_rtype),2);
    bufp->fullBit(oldp+106639,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_frs3_en));
    bufp->fullBit(oldp+106640,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_fp_val));
    bufp->fullBit(oldp+106641,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_fp_single));
    bufp->fullBit(oldp+106642,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_xcpt_pf_if));
    bufp->fullBit(oldp+106643,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_xcpt_ae_if));
    bufp->fullBit(oldp+106644,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_xcpt_ma_if));
    bufp->fullBit(oldp+106645,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_bp_debug_if));
    bufp->fullBit(oldp+106646,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_bp_xcpt_if));
    bufp->fullCData(oldp+106647,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_debug_fsrc),2);
    bufp->fullCData(oldp+106648,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_uop_debug_tsrc),2);
    bufp->fullBit(oldp+106649,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_addr_valid));
    bufp->fullQData(oldp+106650,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_addr_bits),40);
    bufp->fullQData(oldp+106652,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_vaddr_bits),40);
    bufp->fullBit(oldp+106654,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_addr_is_virtual));
    bufp->fullBit(oldp+106655,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_data_valid));
    bufp->fullQData(oldp+106656,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_data_bits),64);
    bufp->fullBit(oldp+106658,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_committed));
    bufp->fullBit(oldp+106659,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_succeeded));
    bufp->fullBit(oldp+106660,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_valid));
    bufp->fullCData(oldp+106661,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_uopc),7);
    bufp->fullIData(oldp+106662,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_inst),32);
    bufp->fullIData(oldp+106663,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_debug_inst),32);
    bufp->fullBit(oldp+106664,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_is_rvc));
    bufp->fullQData(oldp+106665,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_debug_pc),40);
    bufp->fullCData(oldp+106667,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_iq_type),3);
    bufp->fullSData(oldp+106668,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_fu_code),10);
    bufp->fullCData(oldp+106669,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_ctrl_br_type),4);
    bufp->fullCData(oldp+106670,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_ctrl_op1_sel),2);
    bufp->fullCData(oldp+106671,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_ctrl_op2_sel),3);
    bufp->fullCData(oldp+106672,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_ctrl_imm_sel),3);
    bufp->fullCData(oldp+106673,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_ctrl_op_fcn),4);
    bufp->fullBit(oldp+106674,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_ctrl_fcn_dw));
    bufp->fullCData(oldp+106675,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_ctrl_csr_cmd),3);
    bufp->fullBit(oldp+106676,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_ctrl_is_load));
    bufp->fullBit(oldp+106677,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_ctrl_is_sta));
    bufp->fullBit(oldp+106678,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_ctrl_is_std));
    bufp->fullCData(oldp+106679,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_iw_state),2);
    bufp->fullBit(oldp+106680,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_iw_p1_poisoned));
    bufp->fullBit(oldp+106681,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_iw_p2_poisoned));
    bufp->fullBit(oldp+106682,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_is_br));
    bufp->fullBit(oldp+106683,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_is_jalr));
    bufp->fullBit(oldp+106684,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_is_jal));
    bufp->fullBit(oldp+106685,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_is_sfb));
    bufp->fullSData(oldp+106686,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_br_mask),16);
    bufp->fullCData(oldp+106687,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_br_tag),4);
    bufp->fullCData(oldp+106688,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_ftq_idx),5);
    bufp->fullBit(oldp+106689,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_edge_inst));
    bufp->fullCData(oldp+106690,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_pc_lob),6);
    bufp->fullBit(oldp+106691,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_taken));
    bufp->fullIData(oldp+106692,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_imm_packed),20);
    bufp->fullSData(oldp+106693,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_csr_addr),12);
    bufp->fullCData(oldp+106694,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_rob_idx),7);
    bufp->fullCData(oldp+106695,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_ldq_idx),5);
    bufp->fullCData(oldp+106696,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_stq_idx),5);
    bufp->fullCData(oldp+106697,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_rxq_idx),2);
    bufp->fullCData(oldp+106698,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_pdst),7);
    bufp->fullCData(oldp+106699,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_prs1),7);
    bufp->fullCData(oldp+106700,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_prs2),7);
    bufp->fullCData(oldp+106701,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_prs3),7);
    bufp->fullCData(oldp+106702,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_ppred),5);
    bufp->fullBit(oldp+106703,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_prs1_busy));
    bufp->fullBit(oldp+106704,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_prs2_busy));
    bufp->fullBit(oldp+106705,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_prs3_busy));
    bufp->fullBit(oldp+106706,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_ppred_busy));
    bufp->fullCData(oldp+106707,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_stale_pdst),7);
    bufp->fullBit(oldp+106708,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_exception));
    bufp->fullQData(oldp+106709,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_exc_cause),64);
    bufp->fullBit(oldp+106711,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_bypassable));
    bufp->fullCData(oldp+106712,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_mem_cmd),5);
    bufp->fullCData(oldp+106713,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_mem_size),2);
    bufp->fullBit(oldp+106714,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_mem_signed));
    bufp->fullBit(oldp+106715,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_is_fence));
    bufp->fullBit(oldp+106716,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_is_fencei));
    bufp->fullBit(oldp+106717,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_is_amo));
    bufp->fullBit(oldp+106718,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_is_csr));
    bufp->fullBit(oldp+106719,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_uses_ldq));
    bufp->fullBit(oldp+106720,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_uses_stq));
    bufp->fullBit(oldp+106721,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_is_sys_pc2epc));
    bufp->fullBit(oldp+106722,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_is_unique));
    bufp->fullBit(oldp+106723,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_flush_on_commit));
    bufp->fullBit(oldp+106724,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_ldst_is_rs1));
    bufp->fullCData(oldp+106725,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_ldst),6);
    bufp->fullCData(oldp+106726,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_lrs1),6);
    bufp->fullCData(oldp+106727,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_lrs2),6);
    bufp->fullCData(oldp+106728,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_lrs3),6);
    bufp->fullBit(oldp+106729,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_ldst_val));
    bufp->fullCData(oldp+106730,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_dst_rtype),2);
    bufp->fullCData(oldp+106731,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_lrs1_rtype),2);
    bufp->fullCData(oldp+106732,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_lrs2_rtype),2);
    bufp->fullBit(oldp+106733,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_frs3_en));
    bufp->fullBit(oldp+106734,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_fp_val));
    bufp->fullBit(oldp+106735,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_fp_single));
    bufp->fullBit(oldp+106736,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_xcpt_pf_if));
    bufp->fullBit(oldp+106737,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_xcpt_ae_if));
    bufp->fullBit(oldp+106738,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_xcpt_ma_if));
    bufp->fullBit(oldp+106739,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_bp_debug_if));
    bufp->fullBit(oldp+106740,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_bp_xcpt_if));
    bufp->fullCData(oldp+106741,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_debug_fsrc),2);
    bufp->fullCData(oldp+106742,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_uop_debug_tsrc),2);
    bufp->fullBit(oldp+106743,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_addr_valid));
    bufp->fullQData(oldp+106744,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_addr_bits),40);
    bufp->fullQData(oldp+106746,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_vaddr_bits),40);
    bufp->fullBit(oldp+106748,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_addr_is_virtual));
    bufp->fullBit(oldp+106749,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_data_valid));
    bufp->fullQData(oldp+106750,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_data_bits),64);
    bufp->fullBit(oldp+106752,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_committed));
    bufp->fullBit(oldp+106753,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_succeeded));
    bufp->fullCData(oldp+106754,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_head),5);
    bufp->fullCData(oldp+106755,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_head),5);
    bufp->fullCData(oldp+106756,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_commit_head),5);
    bufp->fullCData(oldp+106757,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_execute_head),5);
    bufp->fullCData(oldp+106758,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__hella_state),3);
    bufp->fullBit(oldp+106759,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__hella_req_phys));
    bufp->fullQData(oldp+106760,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__hella_data_data),64);
    bufp->fullIData(oldp+106762,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__hella_paddr),32);
    bufp->fullBit(oldp+106763,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__hella_xcpt_ma_ld));
    bufp->fullBit(oldp+106764,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__hella_xcpt_ma_st));
    bufp->fullBit(oldp+106765,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__hella_xcpt_pf_ld));
    bufp->fullBit(oldp+106766,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__hella_xcpt_pf_st));
    bufp->fullBit(oldp+106767,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__hella_xcpt_gf_ld));
    bufp->fullBit(oldp+106768,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__hella_xcpt_gf_st));
    bufp->fullBit(oldp+106769,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__hella_xcpt_ae_ld));
    bufp->fullBit(oldp+106770,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__hella_xcpt_ae_st));
    bufp->fullIData(oldp+106771,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__live_store_mask),24);
    bufp->fullBit(oldp+106772,((0x17U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_tail))));
    bufp->fullBit(oldp+106773,((0x17U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_tail))));
    bufp->fullBit(oldp+106774,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dis_ld_val));
    bufp->fullBit(oldp+106775,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dis_st_val));
    bufp->fullBit(oldp+106776,((0x17U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___T_35))));
    bufp->fullBit(oldp+106777,((0x17U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___T_42))));
    bufp->fullBit(oldp+106778,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dis_ld_val_1));
    bufp->fullBit(oldp+106779,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dis_st_val_1));
    bufp->fullBit(oldp+106780,((0x17U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___T_75))));
    bufp->fullBit(oldp+106781,((0x17U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___T_82))));
    bufp->fullBit(oldp+106782,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dis_ld_val_2));
    bufp->fullBit(oldp+106783,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dis_st_val_2));
    bufp->fullBit(oldp+106784,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p1_block_load_mask_0));
    bufp->fullBit(oldp+106785,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p1_block_load_mask_1));
    bufp->fullBit(oldp+106786,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p1_block_load_mask_2));
    bufp->fullBit(oldp+106787,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p1_block_load_mask_3));
    bufp->fullBit(oldp+106788,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p1_block_load_mask_4));
    bufp->fullBit(oldp+106789,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p1_block_load_mask_5));
    bufp->fullBit(oldp+106790,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p1_block_load_mask_6));
    bufp->fullBit(oldp+106791,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p1_block_load_mask_7));
    bufp->fullBit(oldp+106792,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p1_block_load_mask_8));
    bufp->fullBit(oldp+106793,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p1_block_load_mask_9));
    bufp->fullBit(oldp+106794,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p1_block_load_mask_10));
    bufp->fullBit(oldp+106795,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p1_block_load_mask_11));
    bufp->fullBit(oldp+106796,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p1_block_load_mask_12));
    bufp->fullBit(oldp+106797,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p1_block_load_mask_13));
    bufp->fullBit(oldp+106798,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p1_block_load_mask_14));
    bufp->fullBit(oldp+106799,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p1_block_load_mask_15));
    bufp->fullBit(oldp+106800,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p1_block_load_mask_16));
    bufp->fullBit(oldp+106801,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p1_block_load_mask_17));
    bufp->fullBit(oldp+106802,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p1_block_load_mask_18));
    bufp->fullBit(oldp+106803,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p1_block_load_mask_19));
    bufp->fullBit(oldp+106804,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p1_block_load_mask_20));
    bufp->fullBit(oldp+106805,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p1_block_load_mask_21));
    bufp->fullBit(oldp+106806,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p1_block_load_mask_22));
    bufp->fullBit(oldp+106807,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p1_block_load_mask_23));
    bufp->fullBit(oldp+106808,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p2_block_load_mask_0));
    bufp->fullBit(oldp+106809,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p2_block_load_mask_1));
    bufp->fullBit(oldp+106810,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p2_block_load_mask_2));
    bufp->fullBit(oldp+106811,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p2_block_load_mask_3));
    bufp->fullBit(oldp+106812,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p2_block_load_mask_4));
    bufp->fullBit(oldp+106813,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p2_block_load_mask_5));
    bufp->fullBit(oldp+106814,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p2_block_load_mask_6));
    bufp->fullBit(oldp+106815,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p2_block_load_mask_7));
    bufp->fullBit(oldp+106816,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p2_block_load_mask_8));
    bufp->fullBit(oldp+106817,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p2_block_load_mask_9));
    bufp->fullBit(oldp+106818,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p2_block_load_mask_10));
    bufp->fullBit(oldp+106819,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p2_block_load_mask_11));
    bufp->fullBit(oldp+106820,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p2_block_load_mask_12));
    bufp->fullBit(oldp+106821,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p2_block_load_mask_13));
    bufp->fullBit(oldp+106822,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p2_block_load_mask_14));
    bufp->fullBit(oldp+106823,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p2_block_load_mask_15));
    bufp->fullBit(oldp+106824,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p2_block_load_mask_16));
    bufp->fullBit(oldp+106825,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p2_block_load_mask_17));
    bufp->fullBit(oldp+106826,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p2_block_load_mask_18));
    bufp->fullBit(oldp+106827,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p2_block_load_mask_19));
    bufp->fullBit(oldp+106828,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p2_block_load_mask_20));
    bufp->fullBit(oldp+106829,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p2_block_load_mask_21));
    bufp->fullBit(oldp+106830,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p2_block_load_mask_22));
    bufp->fullBit(oldp+106831,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__p2_block_load_mask_23));
    bufp->fullCData(oldp+106832,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx),5);
    bufp->fullCData(oldp+106833,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_retry_idx),5);
    bufp->fullCData(oldp+106834,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_wakeup_idx),5);
    bufp->fullCData(oldp+106835,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_ldq_retry_e_out_bits_uop_stq_idx),5);
    bufp->fullCData(oldp+106836,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_ldq_retry_e_out_bits_uop_mem_size),2);
    bufp->fullBit(oldp+106837,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__can_fire_load_retry_REG));
    bufp->fullCData(oldp+106838,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_stq_retry_e_out_bits_uop_rob_idx),7);
    bufp->fullCData(oldp+106839,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_stq_retry_e_out_bits_uop_stq_idx),5);
    bufp->fullCData(oldp+106840,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_stq_retry_e_out_bits_uop_mem_size),2);
    bufp->fullBit(oldp+106841,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_stq_retry_e_out_bits_uop_is_amo));
    bufp->fullBit(oldp+106842,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__can_fire_sta_retry_REG));
    bufp->fullBit(oldp+106843,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__can_fire_store_commit_0));
    bufp->fullCData(oldp+106844,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_ldq_wakeup_e_out_bits_uop_stq_idx),5);
    bufp->fullCData(oldp+106845,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_ldq_wakeup_e_out_bits_uop_mem_size),2);
    bufp->fullIData(oldp+106846,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_ldq_wakeup_e_out_bits_st_dep_mask),24);
    bufp->fullBit(oldp+106847,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__will_fire_load_incoming_0_will_fire));
    bufp->fullBit(oldp+106848,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__will_fire_stad_incoming_0_will_fire));
    bufp->fullBit(oldp+106849,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__will_fire_sta_incoming_0_will_fire));
    bufp->fullBit(oldp+106850,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__will_fire_std_incoming_0_will_fire));
    bufp->fullBit(oldp+106851,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__will_fire_sfence_0_will_fire));
    bufp->fullBit(oldp+106852,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__will_fire_hella_incoming_0_will_fire));
    bufp->fullBit(oldp+106853,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__will_fire_hella_wakeup_0_will_fire));
    bufp->fullBit(oldp+106854,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__will_fire_load_retry_0_will_fire));
    bufp->fullBit(oldp+106855,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__will_fire_sta_retry_0_will_fire));
    bufp->fullBit(oldp+106856,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__will_fire_load_wakeup_0_will_fire));
    bufp->fullBit(oldp+106857,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__will_fire_store_commit_0_will_fire));
    bufp->fullSData(oldp+106858,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__exe_tlb_uop_0_br_mask),16);
    bufp->fullQData(oldp+106859,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__exe_tlb_vaddr_0),40);
    bufp->fullCData(oldp+106861,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_uopc),7);
    bufp->fullIData(oldp+106862,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_inst),32);
    bufp->fullIData(oldp+106863,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_debug_inst),32);
    bufp->fullBit(oldp+106864,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_is_rvc));
    bufp->fullQData(oldp+106865,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_debug_pc),40);
    bufp->fullCData(oldp+106867,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_iq_type),3);
    bufp->fullSData(oldp+106868,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_fu_code),10);
    bufp->fullCData(oldp+106869,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_ctrl_br_type),4);
    bufp->fullCData(oldp+106870,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_ctrl_op1_sel),2);
    bufp->fullCData(oldp+106871,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_ctrl_op2_sel),3);
    bufp->fullCData(oldp+106872,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_ctrl_imm_sel),3);
    bufp->fullCData(oldp+106873,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_ctrl_op_fcn),4);
    bufp->fullBit(oldp+106874,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_ctrl_fcn_dw));
    bufp->fullCData(oldp+106875,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_ctrl_csr_cmd),3);
    bufp->fullBit(oldp+106876,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_ctrl_is_load));
    bufp->fullBit(oldp+106877,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_ctrl_is_sta));
    bufp->fullBit(oldp+106878,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_ctrl_is_std));
    bufp->fullCData(oldp+106879,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_iw_state),2);
    bufp->fullBit(oldp+106880,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_iw_p1_poisoned));
    bufp->fullBit(oldp+106881,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_iw_p2_poisoned));
    bufp->fullBit(oldp+106882,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_is_br));
    bufp->fullBit(oldp+106883,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_is_jalr));
    bufp->fullBit(oldp+106884,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_is_jal));
    bufp->fullBit(oldp+106885,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_is_sfb));
    bufp->fullSData(oldp+106886,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_br_mask),16);
    bufp->fullCData(oldp+106887,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_br_tag),4);
    bufp->fullCData(oldp+106888,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_ftq_idx),5);
    bufp->fullBit(oldp+106889,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_edge_inst));
    bufp->fullCData(oldp+106890,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_pc_lob),6);
    bufp->fullBit(oldp+106891,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_taken));
    bufp->fullIData(oldp+106892,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_imm_packed),20);
    bufp->fullSData(oldp+106893,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_csr_addr),12);
    bufp->fullCData(oldp+106894,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_rob_idx),7);
    bufp->fullCData(oldp+106895,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_ldq_idx),5);
    bufp->fullCData(oldp+106896,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_stq_idx),5);
    bufp->fullCData(oldp+106897,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_rxq_idx),2);
    bufp->fullCData(oldp+106898,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_pdst),7);
    bufp->fullCData(oldp+106899,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_prs1),7);
    bufp->fullCData(oldp+106900,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_prs2),7);
    bufp->fullCData(oldp+106901,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_prs3),7);
    bufp->fullCData(oldp+106902,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_ppred),5);
    bufp->fullBit(oldp+106903,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_prs1_busy));
    bufp->fullBit(oldp+106904,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_prs2_busy));
    bufp->fullBit(oldp+106905,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_prs3_busy));
    bufp->fullBit(oldp+106906,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_ppred_busy));
    bufp->fullCData(oldp+106907,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_stale_pdst),7);
    bufp->fullBit(oldp+106908,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_exception));
    bufp->fullBit(oldp+106909,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_bypassable));
    bufp->fullCData(oldp+106910,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_mem_cmd),5);
    bufp->fullCData(oldp+106911,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_mem_size),2);
    bufp->fullBit(oldp+106912,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_mem_signed));
    bufp->fullBit(oldp+106913,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_is_fence));
    bufp->fullBit(oldp+106914,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_is_fencei));
    bufp->fullBit(oldp+106915,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_is_amo));
    bufp->fullBit(oldp+106916,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_is_csr));
    bufp->fullBit(oldp+106917,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_uses_ldq));
    bufp->fullBit(oldp+106918,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_uses_stq));
    bufp->fullBit(oldp+106919,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_is_sys_pc2epc));
    bufp->fullBit(oldp+106920,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_is_unique));
    bufp->fullBit(oldp+106921,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_flush_on_commit));
    bufp->fullBit(oldp+106922,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_ldst_is_rs1));
    bufp->fullCData(oldp+106923,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_ldst),6);
    bufp->fullCData(oldp+106924,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_lrs1),6);
    bufp->fullCData(oldp+106925,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_lrs2),6);
    bufp->fullCData(oldp+106926,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_lrs3),6);
    bufp->fullBit(oldp+106927,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_ldst_val));
    bufp->fullCData(oldp+106928,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_dst_rtype),2);
    bufp->fullCData(oldp+106929,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_lrs1_rtype),2);
    bufp->fullCData(oldp+106930,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_lrs2_rtype),2);
    bufp->fullBit(oldp+106931,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_frs3_en));
    bufp->fullBit(oldp+106932,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_fp_val));
    bufp->fullBit(oldp+106933,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_fp_single));
    bufp->fullBit(oldp+106934,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_xcpt_pf_if));
    bufp->fullBit(oldp+106935,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_xcpt_ae_if));
    bufp->fullBit(oldp+106936,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_xcpt_ma_if));
    bufp->fullBit(oldp+106937,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_bp_debug_if));
    bufp->fullBit(oldp+106938,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_bp_xcpt_if));
    bufp->fullCData(oldp+106939,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_debug_fsrc),2);
    bufp->fullCData(oldp+106940,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_uops_0_debug_tsrc),2);
    bufp->fullCData(oldp+106941,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_causes_0),4);
    bufp->fullQData(oldp+106942,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_xcpt_vaddrs_0),40);
    bufp->fullBit(oldp+106944,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__exe_tlb_miss_0));
    bufp->fullIData(oldp+106945,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__exe_tlb_paddr_0),32);
    bufp->fullBit(oldp+106946,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__REG));
    bufp->fullBit(oldp+106947,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__fp_stdata_fire));
    bufp->fullCData(oldp+106948,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__sidx),5);
    bufp->fullBit(oldp+106949,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__fired_load_incoming_REG));
    bufp->fullBit(oldp+106950,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__fired_stad_incoming_REG));
    bufp->fullBit(oldp+106951,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__fired_sta_incoming_REG));
    bufp->fullBit(oldp+106952,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__fired_std_incoming_REG));
    bufp->fullBit(oldp+106953,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__fired_stdf_incoming));
    bufp->fullBit(oldp+106954,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__fired_sfence_0));
    bufp->fullBit(oldp+106955,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__fired_release_0));
    bufp->fullBit(oldp+106956,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__fired_load_retry_REG));
    bufp->fullBit(oldp+106957,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__fired_sta_retry_REG));
    bufp->fullBit(oldp+106958,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__fired_load_wakeup_REG));
    bufp->fullSData(oldp+106959,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_incoming_uop_0_br_mask),16);
    bufp->fullCData(oldp+106960,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_incoming_uop_0_rob_idx),7);
    bufp->fullCData(oldp+106961,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_incoming_uop_0_ldq_idx),5);
    bufp->fullCData(oldp+106962,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_incoming_uop_0_stq_idx),5);
    bufp->fullBit(oldp+106963,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_incoming_uop_0_fp_val));
    bufp->fullSData(oldp+106964,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_ldq_incoming_e_0_bits_uop_br_mask),16);
    bufp->fullCData(oldp+106965,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_ldq_incoming_e_0_bits_uop_stq_idx),5);
    bufp->fullCData(oldp+106966,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_ldq_incoming_e_0_bits_uop_mem_size),2);
    bufp->fullIData(oldp+106967,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_ldq_incoming_e_0_bits_st_dep_mask),24);
    bufp->fullBit(oldp+106968,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_stq_incoming_e_0_valid));
    bufp->fullSData(oldp+106969,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_stq_incoming_e_0_bits_uop_br_mask),16);
    bufp->fullCData(oldp+106970,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_stq_incoming_e_0_bits_uop_rob_idx),7);
    bufp->fullCData(oldp+106971,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_stq_incoming_e_0_bits_uop_stq_idx),5);
    bufp->fullCData(oldp+106972,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_stq_incoming_e_0_bits_uop_mem_size),2);
    bufp->fullBit(oldp+106973,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_stq_incoming_e_0_bits_uop_is_amo));
    bufp->fullBit(oldp+106974,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_stq_incoming_e_0_bits_addr_valid));
    bufp->fullBit(oldp+106975,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_stq_incoming_e_0_bits_addr_is_virtual));
    bufp->fullBit(oldp+106976,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_stq_incoming_e_0_bits_data_valid));
    bufp->fullSData(oldp+106977,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_ldq_wakeup_e_bits_uop_br_mask),16);
    bufp->fullCData(oldp+106978,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_ldq_wakeup_e_bits_uop_stq_idx),5);
    bufp->fullCData(oldp+106979,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_ldq_wakeup_e_bits_uop_mem_size),2);
    bufp->fullIData(oldp+106980,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_ldq_wakeup_e_bits_st_dep_mask),24);
    bufp->fullSData(oldp+106981,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_ldq_retry_e_bits_uop_br_mask),16);
    bufp->fullCData(oldp+106982,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_ldq_retry_e_bits_uop_stq_idx),5);
    bufp->fullCData(oldp+106983,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_ldq_retry_e_bits_uop_mem_size),2);
    bufp->fullIData(oldp+106984,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_ldq_retry_e_bits_st_dep_mask),24);
    bufp->fullBit(oldp+106985,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_stq_retry_e_valid));
    bufp->fullSData(oldp+106986,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_stq_retry_e_bits_uop_br_mask),16);
    bufp->fullCData(oldp+106987,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_stq_retry_e_bits_uop_rob_idx),7);
    bufp->fullCData(oldp+106988,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_stq_retry_e_bits_uop_stq_idx),5);
    bufp->fullCData(oldp+106989,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_stq_retry_e_bits_uop_mem_size),2);
    bufp->fullBit(oldp+106990,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_stq_retry_e_bits_uop_is_amo));
    bufp->fullBit(oldp+106991,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_stq_retry_e_bits_data_valid));
    bufp->fullIData(oldp+106992,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__lcam_st_dep_mask_0),24);
    bufp->fullSData(oldp+106993,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_stdf_uop_br_mask),16);
    bufp->fullCData(oldp+106994,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_stdf_uop_rob_idx),7);
    bufp->fullCData(oldp+106995,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_stdf_uop_stq_idx),5);
    bufp->fullBit(oldp+106996,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_tlb_miss_0));
    bufp->fullBit(oldp+106997,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_tlb_uncacheable_0));
    bufp->fullQData(oldp+106998,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__mem_paddr_0),40);
    bufp->fullBit(oldp+107000,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__clr_bsy_valid_0));
    bufp->fullSData(oldp+107001,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__clr_bsy_brmask_0),16);
    bufp->fullBit(oldp+107002,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_core_clr_bsy_0_valid_REG));
    bufp->fullBit(oldp+107003,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_core_clr_bsy_0_valid_REG_1));
    bufp->fullBit(oldp+107004,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_core_clr_bsy_0_valid_REG_2));
    bufp->fullBit(oldp+107005,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stdf_clr_bsy_valid));
    bufp->fullSData(oldp+107006,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stdf_clr_bsy_brmask),16);
    bufp->fullBit(oldp+107007,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_core_clr_bsy_1_valid_REG));
    bufp->fullBit(oldp+107008,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_core_clr_bsy_1_valid_REG_1));
    bufp->fullBit(oldp+107009,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_core_clr_bsy_1_valid_REG_2));
    bufp->fullBit(oldp+107010,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__do_st_search_0));
    bufp->fullBit(oldp+107011,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__do_ld_search_0));
    bufp->fullIData(oldp+107012,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__lcam_addr_REG),32);
    bufp->fullIData(oldp+107013,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__lcam_addr_REG_1),32);
    bufp->fullQData(oldp+107014,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__lcam_addr_0),40);
    bufp->fullCData(oldp+107016,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__lcam_mask_0),8);
    bufp->fullCData(oldp+107017,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__lcam_ldq_idx_REG),5);
    bufp->fullCData(oldp+107018,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__lcam_ldq_idx_REG_1),5);
    bufp->fullCData(oldp+107019,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__lcam_ldq_idx_0),5);
    bufp->fullCData(oldp+107020,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__lcam_stq_idx_REG),5);
    bufp->fullCData(oldp+107021,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__lcam_stq_idx_0),5);
    bufp->fullBit(oldp+107022,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__s1_executing_loads_0));
    bufp->fullBit(oldp+107023,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__s1_executing_loads_1));
    bufp->fullBit(oldp+107024,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__s1_executing_loads_2));
    bufp->fullBit(oldp+107025,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__s1_executing_loads_3));
    bufp->fullBit(oldp+107026,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__s1_executing_loads_4));
    bufp->fullBit(oldp+107027,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__s1_executing_loads_5));
    bufp->fullBit(oldp+107028,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__s1_executing_loads_6));
    bufp->fullBit(oldp+107029,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__s1_executing_loads_7));
    bufp->fullBit(oldp+107030,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__s1_executing_loads_8));
    bufp->fullBit(oldp+107031,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__s1_executing_loads_9));
    bufp->fullBit(oldp+107032,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__s1_executing_loads_10));
    bufp->fullBit(oldp+107033,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__s1_executing_loads_11));
    bufp->fullBit(oldp+107034,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__s1_executing_loads_12));
    bufp->fullBit(oldp+107035,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__s1_executing_loads_13));
    bufp->fullBit(oldp+107036,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__s1_executing_loads_14));
    bufp->fullBit(oldp+107037,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__s1_executing_loads_15));
    bufp->fullBit(oldp+107038,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__s1_executing_loads_16));
    bufp->fullBit(oldp+107039,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__s1_executing_loads_17));
    bufp->fullBit(oldp+107040,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__s1_executing_loads_18));
    bufp->fullBit(oldp+107041,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__s1_executing_loads_19));
    bufp->fullBit(oldp+107042,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__s1_executing_loads_20));
    bufp->fullBit(oldp+107043,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__s1_executing_loads_21));
    bufp->fullBit(oldp+107044,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__s1_executing_loads_22));
    bufp->fullBit(oldp+107045,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__s1_executing_loads_23));
    bufp->fullBit(oldp+107046,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__wb_forward_valid_0));
    bufp->fullCData(oldp+107047,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__wb_forward_ldq_idx_0),5);
    bufp->fullQData(oldp+107048,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__wb_forward_ld_addr_0),40);
    bufp->fullCData(oldp+107050,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__wb_forward_stq_idx_0),5);
    bufp->fullBit(oldp+107051,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forwarders_0));
    bufp->fullBit(oldp+107052,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__block_addr_matches_0));
    bufp->fullBit(oldp+107053,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_0));
    bufp->fullBit(oldp+107054,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__searcher_is_older));
    bufp->fullBit(oldp+107055,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__older_nacked_REG));
    bufp->fullBit(oldp+107056,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG));
    bufp->fullBit(oldp+107057,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forwarders_1_0));
    bufp->fullBit(oldp+107058,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__block_addr_matches_1_0));
    bufp->fullBit(oldp+107059,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_1_0));
    bufp->fullBit(oldp+107060,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__searcher_is_older_1));
    bufp->fullBit(oldp+107061,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__older_nacked_REG_1));
    bufp->fullBit(oldp+107062,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_1));
    bufp->fullBit(oldp+107063,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forwarders_2_0));
    bufp->fullBit(oldp+107064,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__block_addr_matches_2_0));
    bufp->fullBit(oldp+107065,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_2_0));
    bufp->fullBit(oldp+107066,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__searcher_is_older_2));
    bufp->fullBit(oldp+107067,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__older_nacked_REG_2));
    bufp->fullBit(oldp+107068,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_2));
    bufp->fullBit(oldp+107069,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forwarders_3_0));
    bufp->fullBit(oldp+107070,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__block_addr_matches_3_0));
    bufp->fullBit(oldp+107071,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_3_0));
    bufp->fullBit(oldp+107072,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__searcher_is_older_3));
    bufp->fullBit(oldp+107073,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__older_nacked_REG_3));
    bufp->fullBit(oldp+107074,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_3));
    bufp->fullBit(oldp+107075,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forwarders_4_0));
    bufp->fullBit(oldp+107076,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__block_addr_matches_4_0));
    bufp->fullBit(oldp+107077,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_4_0));
    bufp->fullBit(oldp+107078,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__searcher_is_older_4));
    bufp->fullBit(oldp+107079,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__older_nacked_REG_4));
    bufp->fullBit(oldp+107080,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_4));
    bufp->fullBit(oldp+107081,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forwarders_5_0));
    bufp->fullBit(oldp+107082,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__block_addr_matches_5_0));
    bufp->fullBit(oldp+107083,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_5_0));
    bufp->fullBit(oldp+107084,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__searcher_is_older_5));
    bufp->fullBit(oldp+107085,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__older_nacked_REG_5));
    bufp->fullBit(oldp+107086,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_5));
    bufp->fullBit(oldp+107087,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forwarders_6_0));
    bufp->fullBit(oldp+107088,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__block_addr_matches_6_0));
    bufp->fullBit(oldp+107089,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_6_0));
    bufp->fullBit(oldp+107090,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__searcher_is_older_6));
    bufp->fullBit(oldp+107091,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__older_nacked_REG_6));
    bufp->fullBit(oldp+107092,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_6));
    bufp->fullBit(oldp+107093,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forwarders_7_0));
    bufp->fullBit(oldp+107094,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__block_addr_matches_7_0));
    bufp->fullBit(oldp+107095,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_7_0));
    bufp->fullBit(oldp+107096,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__searcher_is_older_7));
    bufp->fullBit(oldp+107097,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__older_nacked_REG_7));
    bufp->fullBit(oldp+107098,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_7));
    bufp->fullBit(oldp+107099,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forwarders_8_0));
    bufp->fullBit(oldp+107100,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__block_addr_matches_8_0));
    bufp->fullBit(oldp+107101,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_8_0));
    bufp->fullBit(oldp+107102,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__searcher_is_older_8));
    bufp->fullBit(oldp+107103,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__older_nacked_REG_8));
    bufp->fullBit(oldp+107104,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_8));
    bufp->fullBit(oldp+107105,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forwarders_9_0));
    bufp->fullBit(oldp+107106,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__block_addr_matches_9_0));
    bufp->fullBit(oldp+107107,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_9_0));
    bufp->fullBit(oldp+107108,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__searcher_is_older_9));
    bufp->fullBit(oldp+107109,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__older_nacked_REG_9));
    bufp->fullBit(oldp+107110,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_9));
    bufp->fullBit(oldp+107111,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forwarders_10_0));
    bufp->fullBit(oldp+107112,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__block_addr_matches_10_0));
    bufp->fullBit(oldp+107113,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_10_0));
    bufp->fullBit(oldp+107114,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__searcher_is_older_10));
    bufp->fullBit(oldp+107115,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__older_nacked_REG_10));
    bufp->fullBit(oldp+107116,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_10));
    bufp->fullBit(oldp+107117,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forwarders_11_0));
    bufp->fullBit(oldp+107118,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__block_addr_matches_11_0));
    bufp->fullBit(oldp+107119,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_11_0));
    bufp->fullBit(oldp+107120,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__searcher_is_older_11));
    bufp->fullBit(oldp+107121,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__older_nacked_REG_11));
    bufp->fullBit(oldp+107122,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_11));
    bufp->fullBit(oldp+107123,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forwarders_12_0));
    bufp->fullBit(oldp+107124,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__block_addr_matches_12_0));
    bufp->fullBit(oldp+107125,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_12_0));
    bufp->fullBit(oldp+107126,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__searcher_is_older_12));
    bufp->fullBit(oldp+107127,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__older_nacked_REG_12));
    bufp->fullBit(oldp+107128,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_12));
    bufp->fullBit(oldp+107129,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forwarders_13_0));
    bufp->fullBit(oldp+107130,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__block_addr_matches_13_0));
    bufp->fullBit(oldp+107131,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_13_0));
    bufp->fullBit(oldp+107132,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__searcher_is_older_13));
    bufp->fullBit(oldp+107133,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__older_nacked_REG_13));
    bufp->fullBit(oldp+107134,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_13));
    bufp->fullBit(oldp+107135,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forwarders_14_0));
    bufp->fullBit(oldp+107136,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__block_addr_matches_14_0));
    bufp->fullBit(oldp+107137,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_14_0));
    bufp->fullBit(oldp+107138,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__searcher_is_older_14));
    bufp->fullBit(oldp+107139,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__older_nacked_REG_14));
    bufp->fullBit(oldp+107140,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_14));
    bufp->fullBit(oldp+107141,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forwarders_15_0));
    bufp->fullBit(oldp+107142,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__block_addr_matches_15_0));
    bufp->fullBit(oldp+107143,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_15_0));
    bufp->fullBit(oldp+107144,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__searcher_is_older_15));
    bufp->fullBit(oldp+107145,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__older_nacked_REG_15));
    bufp->fullBit(oldp+107146,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_15));
    bufp->fullBit(oldp+107147,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forwarders_16_0));
    bufp->fullBit(oldp+107148,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__block_addr_matches_16_0));
    bufp->fullBit(oldp+107149,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_16_0));
    bufp->fullBit(oldp+107150,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__searcher_is_older_16));
    bufp->fullBit(oldp+107151,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__older_nacked_REG_16));
    bufp->fullBit(oldp+107152,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_16));
    bufp->fullBit(oldp+107153,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forwarders_17_0));
    bufp->fullBit(oldp+107154,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__block_addr_matches_17_0));
    bufp->fullBit(oldp+107155,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_17_0));
    bufp->fullBit(oldp+107156,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__searcher_is_older_17));
    bufp->fullBit(oldp+107157,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__older_nacked_REG_17));
    bufp->fullBit(oldp+107158,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_17));
    bufp->fullBit(oldp+107159,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forwarders_18_0));
    bufp->fullBit(oldp+107160,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__block_addr_matches_18_0));
    bufp->fullBit(oldp+107161,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_18_0));
    bufp->fullBit(oldp+107162,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__searcher_is_older_18));
    bufp->fullBit(oldp+107163,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__older_nacked_REG_18));
    bufp->fullBit(oldp+107164,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_18));
    bufp->fullBit(oldp+107165,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forwarders_19_0));
    bufp->fullBit(oldp+107166,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__block_addr_matches_19_0));
    bufp->fullBit(oldp+107167,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_19_0));
    bufp->fullBit(oldp+107168,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__searcher_is_older_19));
    bufp->fullBit(oldp+107169,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__older_nacked_REG_19));
    bufp->fullBit(oldp+107170,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_19));
    bufp->fullBit(oldp+107171,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forwarders_20_0));
    bufp->fullBit(oldp+107172,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__block_addr_matches_20_0));
    bufp->fullBit(oldp+107173,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_20_0));
    bufp->fullBit(oldp+107174,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__searcher_is_older_20));
    bufp->fullBit(oldp+107175,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__older_nacked_REG_20));
    bufp->fullBit(oldp+107176,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_20));
    bufp->fullBit(oldp+107177,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forwarders_21_0));
    bufp->fullBit(oldp+107178,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__block_addr_matches_21_0));
    bufp->fullBit(oldp+107179,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_21_0));
    bufp->fullBit(oldp+107180,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__searcher_is_older_21));
    bufp->fullBit(oldp+107181,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__older_nacked_REG_21));
    bufp->fullBit(oldp+107182,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_21));
    bufp->fullBit(oldp+107183,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forwarders_22_0));
    bufp->fullBit(oldp+107184,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__block_addr_matches_22_0));
    bufp->fullBit(oldp+107185,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_22_0));
    bufp->fullBit(oldp+107186,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__searcher_is_older_22));
    bufp->fullBit(oldp+107187,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__older_nacked_REG_22));
    bufp->fullBit(oldp+107188,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_22));
    bufp->fullBit(oldp+107189,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forwarders_23_0));
    bufp->fullBit(oldp+107190,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__block_addr_matches_23_0));
    bufp->fullBit(oldp+107191,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_23_0));
    bufp->fullBit(oldp+107192,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__searcher_is_older_23));
    bufp->fullBit(oldp+107193,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__older_nacked_REG_23));
    bufp->fullBit(oldp+107194,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_23));
    bufp->fullBit(oldp+107195,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__can_forward_0));
    bufp->fullBit(oldp+107196,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_24_0));
    bufp->fullBit(oldp+107197,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_24));
    bufp->fullBit(oldp+107198,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_25));
    bufp->fullBit(oldp+107199,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldst_addr_matches_0_0));
    bufp->fullBit(oldp+107200,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_26));
    bufp->fullBit(oldp+107201,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_25_0));
    bufp->fullBit(oldp+107202,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_27));
    bufp->fullBit(oldp+107203,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_28));
    bufp->fullBit(oldp+107204,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldst_addr_matches_0_1));
    bufp->fullBit(oldp+107205,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_29));
    bufp->fullBit(oldp+107206,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_26_0));
    bufp->fullBit(oldp+107207,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_30));
    bufp->fullBit(oldp+107208,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_31));
    bufp->fullBit(oldp+107209,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldst_addr_matches_0_2));
    bufp->fullBit(oldp+107210,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_32));
    bufp->fullBit(oldp+107211,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_27_0));
    bufp->fullBit(oldp+107212,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_33));
    bufp->fullBit(oldp+107213,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_34));
    bufp->fullBit(oldp+107214,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldst_addr_matches_0_3));
    bufp->fullBit(oldp+107215,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_35));
    bufp->fullBit(oldp+107216,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_28_0));
    bufp->fullBit(oldp+107217,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_36));
    bufp->fullBit(oldp+107218,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_37));
    bufp->fullBit(oldp+107219,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldst_addr_matches_0_4));
    bufp->fullBit(oldp+107220,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_38));
    bufp->fullBit(oldp+107221,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_29_0));
    bufp->fullBit(oldp+107222,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_39));
    bufp->fullBit(oldp+107223,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_40));
    bufp->fullBit(oldp+107224,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldst_addr_matches_0_5));
    bufp->fullBit(oldp+107225,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_41));
    bufp->fullBit(oldp+107226,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_30_0));
    bufp->fullBit(oldp+107227,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_42));
    bufp->fullBit(oldp+107228,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_43));
    bufp->fullBit(oldp+107229,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldst_addr_matches_0_6));
    bufp->fullBit(oldp+107230,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_44));
    bufp->fullBit(oldp+107231,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_31_0));
    bufp->fullBit(oldp+107232,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_45));
    bufp->fullBit(oldp+107233,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_46));
    bufp->fullBit(oldp+107234,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldst_addr_matches_0_7));
    bufp->fullBit(oldp+107235,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_47));
    bufp->fullBit(oldp+107236,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_32_0));
    bufp->fullBit(oldp+107237,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_48));
    bufp->fullBit(oldp+107238,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_49));
    bufp->fullBit(oldp+107239,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldst_addr_matches_0_8));
    bufp->fullBit(oldp+107240,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_50));
    bufp->fullBit(oldp+107241,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_33_0));
    bufp->fullBit(oldp+107242,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_51));
    bufp->fullBit(oldp+107243,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_52));
    bufp->fullBit(oldp+107244,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldst_addr_matches_0_9));
    bufp->fullBit(oldp+107245,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_53));
    bufp->fullBit(oldp+107246,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_34_0));
    bufp->fullBit(oldp+107247,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_54));
    bufp->fullBit(oldp+107248,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_55));
    bufp->fullBit(oldp+107249,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldst_addr_matches_0_10));
    bufp->fullBit(oldp+107250,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_56));
    bufp->fullBit(oldp+107251,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_35_0));
    bufp->fullBit(oldp+107252,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_57));
    bufp->fullBit(oldp+107253,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_58));
    bufp->fullBit(oldp+107254,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldst_addr_matches_0_11));
    bufp->fullBit(oldp+107255,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_59));
    bufp->fullBit(oldp+107256,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_36_0));
    bufp->fullBit(oldp+107257,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_60));
    bufp->fullBit(oldp+107258,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_61));
    bufp->fullBit(oldp+107259,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldst_addr_matches_0_12));
    bufp->fullBit(oldp+107260,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_62));
    bufp->fullBit(oldp+107261,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_37_0));
    bufp->fullBit(oldp+107262,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_63));
    bufp->fullBit(oldp+107263,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_64));
    bufp->fullBit(oldp+107264,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldst_addr_matches_0_13));
    bufp->fullBit(oldp+107265,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_65));
    bufp->fullBit(oldp+107266,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_38_0));
    bufp->fullBit(oldp+107267,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_66));
    bufp->fullBit(oldp+107268,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_67));
    bufp->fullBit(oldp+107269,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldst_addr_matches_0_14));
    bufp->fullBit(oldp+107270,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_68));
    bufp->fullBit(oldp+107271,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_39_0));
    bufp->fullBit(oldp+107272,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_69));
    bufp->fullBit(oldp+107273,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_70));
    bufp->fullBit(oldp+107274,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldst_addr_matches_0_15));
    bufp->fullBit(oldp+107275,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_71));
    bufp->fullBit(oldp+107276,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_40_0));
    bufp->fullBit(oldp+107277,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_72));
    bufp->fullBit(oldp+107278,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_73));
    bufp->fullBit(oldp+107279,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldst_addr_matches_0_16));
    bufp->fullBit(oldp+107280,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_74));
    bufp->fullBit(oldp+107281,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_41_0));
    bufp->fullBit(oldp+107282,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_75));
    bufp->fullBit(oldp+107283,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_76));
    bufp->fullBit(oldp+107284,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldst_addr_matches_0_17));
    bufp->fullBit(oldp+107285,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_77));
    bufp->fullBit(oldp+107286,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_42_0));
    bufp->fullBit(oldp+107287,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_78));
    bufp->fullBit(oldp+107288,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_79));
    bufp->fullBit(oldp+107289,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldst_addr_matches_0_18));
    bufp->fullBit(oldp+107290,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_80));
    bufp->fullBit(oldp+107291,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_43_0));
    bufp->fullBit(oldp+107292,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_81));
    bufp->fullBit(oldp+107293,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_82));
    bufp->fullBit(oldp+107294,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldst_addr_matches_0_19));
    bufp->fullBit(oldp+107295,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_83));
    bufp->fullBit(oldp+107296,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_44_0));
    bufp->fullBit(oldp+107297,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_84));
    bufp->fullBit(oldp+107298,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_85));
    bufp->fullBit(oldp+107299,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldst_addr_matches_0_20));
    bufp->fullBit(oldp+107300,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_86));
    bufp->fullBit(oldp+107301,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_45_0));
    bufp->fullBit(oldp+107302,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_87));
    bufp->fullBit(oldp+107303,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_88));
    bufp->fullBit(oldp+107304,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldst_addr_matches_0_21));
    bufp->fullBit(oldp+107305,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_89));
    bufp->fullBit(oldp+107306,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_46_0));
    bufp->fullBit(oldp+107307,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_90));
    bufp->fullBit(oldp+107308,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_91));
    bufp->fullBit(oldp+107309,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldst_addr_matches_0_22));
    bufp->fullBit(oldp+107310,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_92));
    bufp->fullBit(oldp+107311,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dword_addr_matches_47_0));
    bufp->fullBit(oldp+107312,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_93));
    bufp->fullBit(oldp+107313,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_94));
    bufp->fullBit(oldp+107314,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldst_addr_matches_0_23));
    bufp->fullBit(oldp+107315,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_dmem_s1_kill_0_REG_95));
    bufp->fullBit(oldp+107316,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__REG_1));
    bufp->fullBit(oldp+107317,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__REG_2));
    bufp->fullCData(oldp+107318,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__store_blocked_counter),4);
    bufp->fullBit(oldp+107319,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_valid));
    bufp->fullBit(oldp+107320,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_631))));
    bufp->fullBit(oldp+107321,((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_631))));
    bufp->fullBit(oldp+107322,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dmem_resp_fired_0));
    bufp->fullBit(oldp+107323,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__live));
    bufp->fullIData(oldp+107324,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_core_exe_0_iresp_bits_data_shifted),32);
    bufp->fullSData(oldp+107325,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_core_exe_0_iresp_bits_data_shifted_1),16);
    bufp->fullCData(oldp+107326,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_core_exe_0_iresp_bits_data_shifted_2),8);
    bufp->fullIData(oldp+107327,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_core_exe_0_fresp_bits_data_shifted),32);
    bufp->fullSData(oldp+107328,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_core_exe_0_fresp_bits_data_shifted_1),16);
    bufp->fullCData(oldp+107329,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_core_exe_0_fresp_bits_data_shifted_2),8);
    bufp->fullBit(oldp+107330,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__io_core_ld_miss_REG));
    bufp->fullBit(oldp+107331,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__spec_ld_succeed_REG));
    bufp->fullCData(oldp+107332,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__spec_ld_succeed_REG_1),5);
    bufp->fullBit(oldp+107333,((0x17U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_commit_head))));
    bufp->fullBit(oldp+107334,((0x17U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_head))));
    bufp->fullBit(oldp+107335,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__clear_store));
    bufp->fullCData(oldp+107336,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_ldq_cnt_0),5);
    bufp->fullCData(oldp+107337,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_ldq_cnt_1),5);
    bufp->fullCData(oldp+107338,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_ldq_cnt_2),5);
    bufp->fullCData(oldp+107339,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_0),5);
    bufp->fullCData(oldp+107340,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_1),5);
    bufp->fullCData(oldp+107341,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_2),5);
    bufp->fullSData(oldp+107342,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_incoming_e_0_bits_uop_br_mask),16);
    bufp->fullBit(oldp+107343,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block));
    bufp->fullBit(oldp+107344,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_1));
    bufp->fullBit(oldp+107345,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_2));
    bufp->fullBit(oldp+107346,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_3));
    bufp->fullBit(oldp+107347,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_4));
    bufp->fullBit(oldp+107348,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_5));
    bufp->fullBit(oldp+107349,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_6));
    bufp->fullBit(oldp+107350,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_7));
    bufp->fullBit(oldp+107351,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_8));
    bufp->fullBit(oldp+107352,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_9));
    bufp->fullBit(oldp+107353,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_10));
    bufp->fullBit(oldp+107354,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_11));
    bufp->fullBit(oldp+107355,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_12));
    bufp->fullBit(oldp+107356,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_13));
    bufp->fullBit(oldp+107357,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_14));
    bufp->fullBit(oldp+107358,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_15));
    bufp->fullBit(oldp+107359,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_16));
    bufp->fullBit(oldp+107360,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_17));
    bufp->fullBit(oldp+107361,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_18));
    bufp->fullBit(oldp+107362,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_19));
    bufp->fullBit(oldp+107363,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_20));
    bufp->fullBit(oldp+107364,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_21));
    bufp->fullBit(oldp+107365,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_22));
    bufp->fullBit(oldp+107366,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_23));
    bufp->fullBit(oldp+107367,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ma_ld_0));
    bufp->fullBit(oldp+107368,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ma_st_0));
    bufp->fullBit(oldp+107369,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__pf_ld_0));
    bufp->fullBit(oldp+107370,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__pf_st_0));
    bufp->fullBit(oldp+107371,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ae_ld_0));
    bufp->fullBit(oldp+107372,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dmem_req_fire_0));
    bufp->fullCData(oldp+107373,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_idx),5);
    bufp->fullCData(oldp+107374,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_idx),5);
    bufp->fullCData(oldp+107375,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forward_stq_idx),5);
    bufp->fullCData(oldp+107376,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forward_stq_idx_1),5);
    bufp->fullCData(oldp+107377,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forward_stq_idx_2),5);
    bufp->fullCData(oldp+107378,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forward_stq_idx_3),5);
    bufp->fullCData(oldp+107379,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forward_stq_idx_4),5);
    bufp->fullCData(oldp+107380,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forward_stq_idx_5),5);
    bufp->fullCData(oldp+107381,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forward_stq_idx_6),5);
    bufp->fullCData(oldp+107382,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forward_stq_idx_7),5);
    bufp->fullCData(oldp+107383,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forward_stq_idx_8),5);
    bufp->fullCData(oldp+107384,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forward_stq_idx_9),5);
    bufp->fullCData(oldp+107385,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forward_stq_idx_10),5);
    bufp->fullCData(oldp+107386,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forward_stq_idx_11),5);
    bufp->fullCData(oldp+107387,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forward_stq_idx_12),5);
    bufp->fullCData(oldp+107388,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forward_stq_idx_13),5);
    bufp->fullCData(oldp+107389,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forward_stq_idx_14),5);
    bufp->fullCData(oldp+107390,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forward_stq_idx_15),5);
    bufp->fullCData(oldp+107391,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forward_stq_idx_16),5);
    bufp->fullCData(oldp+107392,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forward_stq_idx_17),5);
    bufp->fullCData(oldp+107393,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forward_stq_idx_18),5);
    bufp->fullCData(oldp+107394,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forward_stq_idx_19),5);
    bufp->fullCData(oldp+107395,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forward_stq_idx_20),5);
    bufp->fullCData(oldp+107396,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forward_stq_idx_21),5);
    bufp->fullCData(oldp+107397,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forward_stq_idx_22),5);
    bufp->fullCData(oldp+107398,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_forward_stq_idx_23),5);
    bufp->fullBit(oldp+107399,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldst_forward_matches_0_0));
    bufp->fullCData(oldp+107400,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__l_idx),6);
    bufp->fullBit(oldp+107401,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ld_xcpt_valid));
    bufp->fullBit(oldp+107402,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__use_mem_xcpt));
    bufp->fullSData(oldp+107403,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__xcpt_uop_br_mask),16);
    bufp->fullIData(oldp+107404,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_bits_debug_wb_data_shifted),32);
    bufp->fullSData(oldp+107405,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_bits_debug_wb_data_shifted_1),16);
    bufp->fullCData(oldp+107406,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_bits_debug_wb_data_shifted_2),8);
    bufp->fullBit(oldp+107407,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___will_fire_store_commit_0_T_2)))));
    bufp->fullBit(oldp+107408,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_passthrough));
    bufp->fullCData(oldp+107409,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_size),2);
    bufp->fullCData(oldp+107410,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_cmd),5);
    bufp->fullBit(oldp+107411,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_sfence_valid));
    bufp->fullBit(oldp+107412,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_sfence_bits_rs1));
    bufp->fullBit(oldp+107413,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_sfence_bits_rs2));
    VL_EXTEND_WQ(65,64, __Vtemp_h625a5317__0, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__iregister_read__DOT__exe_reg_rs1_data_0);
    bufp->fullQData(oldp+107414,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__will_fire_sfence_0_will_fire)
                                   ? (0x7fffffffffULL 
                                      & (((QData)((IData)(
                                                          __Vtemp_h625a5317__0[1U])) 
                                          << 0x20U) 
                                         | (QData)((IData)(
                                                           __Vtemp_h625a5317__0[0U]))))
                                   : 0ULL)),39);
    bufp->fullBit(oldp+107416,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_kill));
    bufp->fullBit(oldp+107417,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__state))));
    bufp->fullBit(oldp+107418,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__resp_valid_0) 
                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__tlb_miss_0)) 
                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__multipleHits_0))));
    bufp->fullIData(oldp+107419,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___dtlb_io_resp_0_paddr),32);
    bufp->fullBit(oldp+107420,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___dtlb_io_resp_0_pf_ld));
    bufp->fullBit(oldp+107421,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___dtlb_io_resp_0_pf_st));
    bufp->fullBit(oldp+107422,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___dtlb_io_resp_0_ae_ld));
    bufp->fullBit(oldp+107423,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___dtlb_io_resp_0_ae_st));
    bufp->fullBit(oldp+107424,((0U != ((((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___GEN_17)) 
                                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__cmd_read_0))
                                         ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__eff_array_0))
                                         : 0U) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__hits_0)))));
    bufp->fullBit(oldp+107425,((0U != ((((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___GEN_17)) 
                                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__cmd_write_perms_0))
                                         ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__eff_array_0))
                                         : 0U) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__hits_0)))));
    bufp->fullBit(oldp+107426,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___dtlb_io_resp_0_cacheable));
    bufp->fullIData(oldp+107427,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_0_tag),27);
    bufp->fullQData(oldp+107428,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_0_data_0),34);
    bufp->fullQData(oldp+107430,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_0_data_1),34);
    bufp->fullQData(oldp+107432,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_0_data_2),34);
    bufp->fullQData(oldp+107434,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_0_data_3),34);
    bufp->fullBit(oldp+107436,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_0_valid_0));
    bufp->fullBit(oldp+107437,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_0_valid_1));
    bufp->fullBit(oldp+107438,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_0_valid_2));
    bufp->fullBit(oldp+107439,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_0_valid_3));
    bufp->fullIData(oldp+107440,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_1_tag),27);
    bufp->fullQData(oldp+107441,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_1_data_0),34);
    bufp->fullQData(oldp+107443,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_1_data_1),34);
    bufp->fullQData(oldp+107445,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_1_data_2),34);
    bufp->fullQData(oldp+107447,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_1_data_3),34);
    bufp->fullBit(oldp+107449,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_1_valid_0));
    bufp->fullBit(oldp+107450,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_1_valid_1));
    bufp->fullBit(oldp+107451,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_1_valid_2));
    bufp->fullBit(oldp+107452,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_1_valid_3));
    bufp->fullIData(oldp+107453,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_2_tag),27);
    bufp->fullQData(oldp+107454,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_2_data_0),34);
    bufp->fullQData(oldp+107456,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_2_data_1),34);
    bufp->fullQData(oldp+107458,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_2_data_2),34);
    bufp->fullQData(oldp+107460,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_2_data_3),34);
    bufp->fullBit(oldp+107462,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_2_valid_0));
    bufp->fullBit(oldp+107463,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_2_valid_1));
    bufp->fullBit(oldp+107464,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_2_valid_2));
    bufp->fullBit(oldp+107465,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_2_valid_3));
    bufp->fullIData(oldp+107466,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_3_tag),27);
    bufp->fullQData(oldp+107467,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_3_data_0),34);
    bufp->fullQData(oldp+107469,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_3_data_1),34);
    bufp->fullQData(oldp+107471,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_3_data_2),34);
    bufp->fullQData(oldp+107473,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_3_data_3),34);
    bufp->fullBit(oldp+107475,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_3_valid_0));
    bufp->fullBit(oldp+107476,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_3_valid_1));
    bufp->fullBit(oldp+107477,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_3_valid_2));
    bufp->fullBit(oldp+107478,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_3_valid_3));
    bufp->fullCData(oldp+107479,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_0_level),2);
    bufp->fullIData(oldp+107480,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_0_tag),27);
    bufp->fullQData(oldp+107481,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_0_data_0),34);
    bufp->fullBit(oldp+107483,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_0_valid_0));
    bufp->fullCData(oldp+107484,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_1_level),2);
    bufp->fullIData(oldp+107485,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_1_tag),27);
    bufp->fullQData(oldp+107486,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_1_data_0),34);
    bufp->fullBit(oldp+107488,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_1_valid_0));
    bufp->fullCData(oldp+107489,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_2_level),2);
    bufp->fullIData(oldp+107490,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_2_tag),27);
    bufp->fullQData(oldp+107491,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_2_data_0),34);
    bufp->fullBit(oldp+107493,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_2_valid_0));
    bufp->fullCData(oldp+107494,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_3_level),2);
    bufp->fullIData(oldp+107495,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_3_tag),27);
    bufp->fullQData(oldp+107496,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_3_data_0),34);
    bufp->fullBit(oldp+107498,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_3_valid_0));
    bufp->fullCData(oldp+107499,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__special_entry_level),2);
    bufp->fullIData(oldp+107500,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__special_entry_tag),27);
    bufp->fullQData(oldp+107501,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__special_entry_data_0),34);
    bufp->fullBit(oldp+107503,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__special_entry_valid_0));
    bufp->fullCData(oldp+107504,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__state),2);
    bufp->fullCData(oldp+107505,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__r_superpage_repl_addr),2);
    bufp->fullCData(oldp+107506,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__r_sectored_repl_addr),2);
    bufp->fullCData(oldp+107507,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__r_sectored_hit_addr),2);
    bufp->fullBit(oldp+107508,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__r_sectored_hit));
    bufp->fullBit(oldp+107509,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__vm_enabled_0));
    bufp->fullBit(oldp+107510,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__special_entry_level))));
    bufp->fullIData(oldp+107511,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__mpu_ppn_0),28);
    bufp->fullBit(oldp+107512,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__legal_address_0));
    bufp->fullBit(oldp+107513,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__newEntry_c));
    bufp->fullBit(oldp+107514,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__newEntry_pr));
    bufp->fullBit(oldp+107515,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__newEntry_pw));
    bufp->fullBit(oldp+107516,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__newEntry_pal));
    bufp->fullBit(oldp+107517,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__newEntry_paa));
    bufp->fullBit(oldp+107518,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__newEntry_eff));
    bufp->fullBit(oldp+107519,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_0_level))));
    bufp->fullBit(oldp+107520,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_1_level))));
    bufp->fullBit(oldp+107521,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_2_level))));
    bufp->fullBit(oldp+107522,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_3_level))));
    bufp->fullBit(oldp+107523,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__hitsVec_0_0));
    bufp->fullBit(oldp+107524,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__hitsVec_0_1));
    bufp->fullBit(oldp+107525,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__hitsVec_0_2));
    bufp->fullBit(oldp+107526,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__hitsVec_0_3));
    bufp->fullBit(oldp+107527,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__hitsVec_0_4));
    bufp->fullBit(oldp+107528,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__hitsVec_0_5));
    bufp->fullBit(oldp+107529,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__hitsVec_0_6));
    bufp->fullBit(oldp+107530,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__hitsVec_0_7));
    bufp->fullBit(oldp+107531,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__hitsVec_0_8));
    bufp->fullSData(oldp+107532,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__hits_0),10);
    bufp->fullSData(oldp+107533,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__priv_rw_ok_0),9);
    bufp->fullSData(oldp+107534,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__eff_array_0),10);
    bufp->fullSData(oldp+107535,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__lrscAllowed_0),10);
    bufp->fullBit(oldp+107536,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__bad_va_0));
    bufp->fullBit(oldp+107537,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__cmd_read_0));
    bufp->fullBit(oldp+107538,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__cmd_write_perms_0));
    bufp->fullSData(oldp+107539,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__ae_array_0),10);
    bufp->fullBit(oldp+107540,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__tlb_miss_0));
    bufp->fullCData(oldp+107541,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__state_reg),3);
    bufp->fullCData(oldp+107542,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__state_reg_1),3);
    bufp->fullBit(oldp+107543,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__multipleHits_leftOne_1));
    bufp->fullBit(oldp+107544,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__multipleHits_rightOne_2));
    bufp->fullBit(oldp+107545,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__multipleHits_leftOne_5));
    bufp->fullBit(oldp+107546,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__multipleHits_rightOne_5));
    bufp->fullBit(oldp+107547,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__multipleHits_rightOne_6));
    bufp->fullBit(oldp+107548,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__multipleHits_0));
    bufp->fullBit(oldp+107549,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_hits_0_1));
    bufp->fullBit(oldp+107550,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_hits_0_2));
    bufp->fullBit(oldp+107551,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_hits_0_3));
    bufp->fullCData(oldp+107552,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__hi_3),2);
    bufp->fullBit(oldp+107553,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__newEntry_px));
    bufp->fullBit(oldp+107554,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sector_hits_0_0));
    bufp->fullBit(oldp+107555,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sector_hits_0_1));
    bufp->fullBit(oldp+107556,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sector_hits_0_2));
    bufp->fullBit(oldp+107557,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sector_hits_0_3));
    bufp->fullBit(oldp+107558,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__newEntry_sr));
    bufp->fullBit(oldp+107559,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__newEntry_sw));
    bufp->fullBit(oldp+107560,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__newEntry_sx));
    bufp->fullCData(oldp+107561,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__waddr),2);
    bufp->fullCData(oldp+107562,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__hi_1),2);
    bufp->fullIData(oldp+107563,((0xfffffU & (IData)(
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_1 
                                                      >> 0xeU)))),20);
    bufp->fullBit(oldp+107564,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_1 
                                              >> 0xdU)))));
    bufp->fullBit(oldp+107565,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_1 
                                              >> 0xbU)))));
    bufp->fullBit(oldp+107566,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_1 
                                              >> 0xaU)))));
    bufp->fullBit(oldp+107567,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_1 
                                              >> 9U)))));
    bufp->fullBit(oldp+107568,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_1 
                                              >> 8U)))));
    bufp->fullBit(oldp+107569,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_1 
                                              >> 7U)))));
    bufp->fullBit(oldp+107570,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_1 
                                              >> 5U)))));
    bufp->fullBit(oldp+107571,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_1 
                                              >> 4U)))));
    bufp->fullBit(oldp+107572,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_1 
                                              >> 3U)))));
    bufp->fullBit(oldp+107573,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_1 
                                              >> 2U)))));
    bufp->fullBit(oldp+107574,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_1 
                                              >> 1U)))));
    bufp->fullIData(oldp+107575,((0xfffffU & (IData)(
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_3 
                                                      >> 0xeU)))),20);
    bufp->fullBit(oldp+107576,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_3 
                                              >> 0xdU)))));
    bufp->fullBit(oldp+107577,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_3 
                                              >> 0xbU)))));
    bufp->fullBit(oldp+107578,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_3 
                                              >> 0xaU)))));
    bufp->fullBit(oldp+107579,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_3 
                                              >> 9U)))));
    bufp->fullBit(oldp+107580,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_3 
                                              >> 8U)))));
    bufp->fullBit(oldp+107581,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_3 
                                              >> 7U)))));
    bufp->fullBit(oldp+107582,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_3 
                                              >> 5U)))));
    bufp->fullBit(oldp+107583,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_3 
                                              >> 4U)))));
    bufp->fullBit(oldp+107584,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_3 
                                              >> 3U)))));
    bufp->fullBit(oldp+107585,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_3 
                                              >> 2U)))));
    bufp->fullBit(oldp+107586,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_3 
                                              >> 1U)))));
    bufp->fullIData(oldp+107587,((0xfffffU & (IData)(
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_5 
                                                      >> 0xeU)))),20);
    bufp->fullBit(oldp+107588,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_5 
                                              >> 0xdU)))));
    bufp->fullBit(oldp+107589,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_5 
                                              >> 0xbU)))));
    bufp->fullBit(oldp+107590,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_5 
                                              >> 0xaU)))));
    bufp->fullBit(oldp+107591,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_5 
                                              >> 9U)))));
    bufp->fullBit(oldp+107592,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_5 
                                              >> 8U)))));
    bufp->fullBit(oldp+107593,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_5 
                                              >> 7U)))));
    bufp->fullBit(oldp+107594,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_5 
                                              >> 5U)))));
    bufp->fullBit(oldp+107595,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_5 
                                              >> 4U)))));
    bufp->fullBit(oldp+107596,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_5 
                                              >> 3U)))));
    bufp->fullBit(oldp+107597,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_5 
                                              >> 2U)))));
    bufp->fullBit(oldp+107598,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_5 
                                              >> 1U)))));
    bufp->fullIData(oldp+107599,((0xfffffU & (IData)(
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_7 
                                                      >> 0xeU)))),20);
    bufp->fullBit(oldp+107600,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_7 
                                              >> 0xdU)))));
    bufp->fullBit(oldp+107601,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_7 
                                              >> 0xbU)))));
    bufp->fullBit(oldp+107602,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_7 
                                              >> 0xaU)))));
    bufp->fullBit(oldp+107603,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_7 
                                              >> 9U)))));
    bufp->fullBit(oldp+107604,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_7 
                                              >> 8U)))));
    bufp->fullBit(oldp+107605,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_7 
                                              >> 7U)))));
    bufp->fullBit(oldp+107606,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_7 
                                              >> 5U)))));
    bufp->fullBit(oldp+107607,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_7 
                                              >> 4U)))));
    bufp->fullBit(oldp+107608,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_7 
                                              >> 3U)))));
    bufp->fullBit(oldp+107609,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_7 
                                              >> 2U)))));
    bufp->fullBit(oldp+107610,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_7 
                                              >> 1U)))));
    bufp->fullIData(oldp+107611,((0xfffffU & (IData)(
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_0_data_0 
                                                      >> 0xeU)))),20);
    bufp->fullBit(oldp+107612,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_0_data_0 
                                              >> 0xdU)))));
    bufp->fullBit(oldp+107613,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_0_data_0 
                                              >> 0xbU)))));
    bufp->fullBit(oldp+107614,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_0_data_0 
                                              >> 0xaU)))));
    bufp->fullBit(oldp+107615,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_0_data_0 
                                              >> 9U)))));
    bufp->fullBit(oldp+107616,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_0_data_0 
                                              >> 8U)))));
    bufp->fullBit(oldp+107617,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_0_data_0 
                                              >> 7U)))));
    bufp->fullBit(oldp+107618,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_0_data_0 
                                              >> 5U)))));
    bufp->fullBit(oldp+107619,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_0_data_0 
                                              >> 4U)))));
    bufp->fullBit(oldp+107620,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_0_data_0 
                                              >> 3U)))));
    bufp->fullBit(oldp+107621,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_0_data_0 
                                              >> 2U)))));
    bufp->fullBit(oldp+107622,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_0_data_0 
                                              >> 1U)))));
    bufp->fullIData(oldp+107623,((0xfffffU & (IData)(
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_1_data_0 
                                                      >> 0xeU)))),20);
    bufp->fullBit(oldp+107624,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_1_data_0 
                                              >> 0xdU)))));
    bufp->fullBit(oldp+107625,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_1_data_0 
                                              >> 0xbU)))));
    bufp->fullBit(oldp+107626,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_1_data_0 
                                              >> 0xaU)))));
    bufp->fullBit(oldp+107627,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_1_data_0 
                                              >> 9U)))));
    bufp->fullBit(oldp+107628,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_1_data_0 
                                              >> 8U)))));
    bufp->fullBit(oldp+107629,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_1_data_0 
                                              >> 7U)))));
    bufp->fullBit(oldp+107630,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_1_data_0 
                                              >> 5U)))));
    bufp->fullBit(oldp+107631,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_1_data_0 
                                              >> 4U)))));
    bufp->fullBit(oldp+107632,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_1_data_0 
                                              >> 3U)))));
    bufp->fullBit(oldp+107633,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_1_data_0 
                                              >> 2U)))));
    bufp->fullBit(oldp+107634,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_1_data_0 
                                              >> 1U)))));
    bufp->fullIData(oldp+107635,((0xfffffU & (IData)(
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_2_data_0 
                                                      >> 0xeU)))),20);
    bufp->fullBit(oldp+107636,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_2_data_0 
                                              >> 0xdU)))));
    bufp->fullBit(oldp+107637,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_2_data_0 
                                              >> 0xbU)))));
    bufp->fullBit(oldp+107638,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_2_data_0 
                                              >> 0xaU)))));
    bufp->fullBit(oldp+107639,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_2_data_0 
                                              >> 9U)))));
    bufp->fullBit(oldp+107640,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_2_data_0 
                                              >> 8U)))));
    bufp->fullBit(oldp+107641,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_2_data_0 
                                              >> 7U)))));
    bufp->fullBit(oldp+107642,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_2_data_0 
                                              >> 5U)))));
    bufp->fullBit(oldp+107643,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_2_data_0 
                                              >> 4U)))));
    bufp->fullBit(oldp+107644,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_2_data_0 
                                              >> 3U)))));
    bufp->fullBit(oldp+107645,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_2_data_0 
                                              >> 2U)))));
    bufp->fullBit(oldp+107646,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_2_data_0 
                                              >> 1U)))));
    bufp->fullIData(oldp+107647,((0xfffffU & (IData)(
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_3_data_0 
                                                      >> 0xeU)))),20);
    bufp->fullBit(oldp+107648,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_3_data_0 
                                              >> 0xdU)))));
    bufp->fullBit(oldp+107649,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_3_data_0 
                                              >> 0xbU)))));
    bufp->fullBit(oldp+107650,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_3_data_0 
                                              >> 0xaU)))));
    bufp->fullBit(oldp+107651,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_3_data_0 
                                              >> 9U)))));
    bufp->fullBit(oldp+107652,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_3_data_0 
                                              >> 8U)))));
    bufp->fullBit(oldp+107653,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_3_data_0 
                                              >> 7U)))));
    bufp->fullBit(oldp+107654,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_3_data_0 
                                              >> 5U)))));
    bufp->fullBit(oldp+107655,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_3_data_0 
                                              >> 4U)))));
    bufp->fullBit(oldp+107656,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_3_data_0 
                                              >> 3U)))));
    bufp->fullBit(oldp+107657,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_3_data_0 
                                              >> 2U)))));
    bufp->fullBit(oldp+107658,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_3_data_0 
                                              >> 1U)))));
    bufp->fullIData(oldp+107659,((0xfffffU & (IData)(
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__special_entry_data_0 
                                                      >> 0xeU)))),20);
    bufp->fullBit(oldp+107660,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__special_entry_data_0 
                                              >> 0xdU)))));
    bufp->fullBit(oldp+107661,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__special_entry_data_0 
                                              >> 0xbU)))));
    bufp->fullBit(oldp+107662,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__special_entry_data_0 
                                              >> 0xaU)))));
    bufp->fullBit(oldp+107663,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__special_entry_data_0 
                                              >> 9U)))));
    bufp->fullBit(oldp+107664,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__special_entry_data_0 
                                              >> 8U)))));
    bufp->fullBit(oldp+107665,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__special_entry_data_0 
                                              >> 7U)))));
    bufp->fullBit(oldp+107666,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__special_entry_data_0 
                                              >> 5U)))));
    bufp->fullBit(oldp+107667,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__special_entry_data_0 
                                              >> 4U)))));
    bufp->fullBit(oldp+107668,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__special_entry_data_0 
                                              >> 3U)))));
    bufp->fullBit(oldp+107669,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__special_entry_data_0 
                                              >> 2U)))));
    bufp->fullBit(oldp+107670,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__special_entry_data_0 
                                              >> 1U)))));
    bufp->fullCData(oldp+107671,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT____Vcellinp__pmp_0__io_prv),2);
    bufp->fullIData(oldp+107672,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT____Vcellinp__pmp_0__io_addr),32);
    bufp->fullBit(oldp+107673,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_7)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_7) 
                                          & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_cfg_r) 
                                             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_7)))
                                       : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_6)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_6) 
                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_cfg_r) 
                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_6)))
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_5)
                                               ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_5) 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_cfg_r) 
                                                     | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_5)))
                                               : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_4)
                                                   ? 
                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_4) 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_cfg_r) 
                                                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_4)))
                                                   : 
                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_3)
                                                    ? 
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_3) 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_cfg_r) 
                                                       | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_3)))
                                                    : 
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_2)
                                                     ? 
                                                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_2) 
                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_cfg_r) 
                                                        | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_2)))
                                                     : 
                                                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_1)
                                                      ? 
                                                     ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_1) 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_cfg_r) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_1)))
                                                      : 
                                                     ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit)
                                                       ? 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned) 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_cfg_r) 
                                                          | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore)))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT____Vcellinp__pmp_0__io_prv) 
                                                       >> 1U))))))))))));
    bufp->fullBit(oldp+107674,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_7)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_7) 
                                          & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_cfg_w) 
                                             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_7)))
                                       : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_6)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_6) 
                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_cfg_w) 
                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_6)))
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_5)
                                               ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_5) 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_cfg_w) 
                                                     | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_5)))
                                               : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_4)
                                                   ? 
                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_4) 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_cfg_w) 
                                                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_4)))
                                                   : 
                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_3)
                                                    ? 
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_3) 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_cfg_w) 
                                                       | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_3)))
                                                    : 
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_2)
                                                     ? 
                                                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_2) 
                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_cfg_w) 
                                                        | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_2)))
                                                     : 
                                                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_1)
                                                      ? 
                                                     ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_1) 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_cfg_w) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_1)))
                                                      : 
                                                     ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit)
                                                       ? 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned) 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_cfg_w) 
                                                          | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore)))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT____Vcellinp__pmp_0__io_prv) 
                                                       >> 1U))))))))))));
    bufp->fullBit(oldp+107675,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_7)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_7) 
                                          & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_cfg_x) 
                                             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_7)))
                                       : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_6)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_6) 
                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_cfg_x) 
                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_6)))
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_5)
                                               ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_5) 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_cfg_x) 
                                                     | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_5)))
                                               : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_4)
                                                   ? 
                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_4) 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_cfg_x) 
                                                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_4)))
                                                   : 
                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_3)
                                                    ? 
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_3) 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_cfg_x) 
                                                       | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_3)))
                                                    : 
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_2)
                                                     ? 
                                                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_2) 
                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_cfg_x) 
                                                        | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_2)))
                                                     : 
                                                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_1)
                                                      ? 
                                                     ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_1) 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_cfg_x) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_1)))
                                                      : 
                                                     ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit)
                                                       ? 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned) 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_cfg_x) 
                                                          | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore)))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT____Vcellinp__pmp_0__io_prv) 
                                                       >> 1U))))))))))));
    bufp->fullBit(oldp+107676,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit));
    bufp->fullBit(oldp+107677,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore));
    bufp->fullCData(oldp+107678,((7U & (~ ((5U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_size))
                                            ? (0x3fU 
                                               & ((IData)(7U) 
                                                  << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_size)))
                                            : 0U)))),3);
    bufp->fullBit(oldp+107679,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned));
    bufp->fullBit(oldp+107680,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_1));
    bufp->fullBit(oldp+107681,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_1));
    bufp->fullBit(oldp+107682,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_1));
    bufp->fullBit(oldp+107683,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_2));
    bufp->fullBit(oldp+107684,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_2));
    bufp->fullBit(oldp+107685,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_2));
    bufp->fullBit(oldp+107686,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_3));
    bufp->fullBit(oldp+107687,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_3));
    bufp->fullBit(oldp+107688,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_3));
    bufp->fullBit(oldp+107689,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_4));
    bufp->fullBit(oldp+107690,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_4));
    bufp->fullBit(oldp+107691,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_4));
    bufp->fullBit(oldp+107692,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_5));
    bufp->fullBit(oldp+107693,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_5));
    bufp->fullBit(oldp+107694,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_5));
    bufp->fullBit(oldp+107695,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_6));
    bufp->fullBit(oldp+107696,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_6));
    bufp->fullBit(oldp+107697,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_6));
    bufp->fullBit(oldp+107698,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_hit_7));
    bufp->fullBit(oldp+107699,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_ignore_7));
    bufp->fullBit(oldp+107700,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__pmp_0__DOT__res_aligned_7));
    bufp->fullIData(oldp+107701,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__forwarding_age_logic_0__io_addr_matches),24);
    bufp->fullCData(oldp+107702,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__forwarding_age_logic_0__io_youngest_st_idx),5);
    bufp->fullCData(oldp+107703,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___forwarding_age_logic_0_io_forwarding_idx),5);
    bufp->fullBit(oldp+107704,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__do_switch));
    bufp->fullBit(oldp+107705,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__readEnable));
    bufp->fullBit(oldp+107706,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__writeEnable));
    bufp->fullSData(oldp+107707,((0x1ffU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_req_addr)),9);
    bufp->fullBit(oldp+107708,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__l2_refill));
    bufp->fullCData(oldp+107709,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__state),3);
    bufp->fullBit(oldp+107710,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__invalidated));
    bufp->fullCData(oldp+107711,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__count),2);
    bufp->fullIData(oldp+107712,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_req_addr),27);
    bufp->fullBit(oldp+107713,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_req_need_gpa));
    bufp->fullBit(oldp+107714,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_req_vstage1));
    bufp->fullBit(oldp+107715,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_req_stage2));
    bufp->fullCData(oldp+107716,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_req_dest),2);
    bufp->fullSData(oldp+107717,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_reserved_for_future),10);
    bufp->fullCData(oldp+107718,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_reserved_for_software),2);
    bufp->fullQData(oldp+107719,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_hgatp_ppn),44);
    bufp->fullCData(oldp+107721,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_count),2);
    bufp->fullSData(oldp+107722,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_pte_reserved_for_future),10);
    bufp->fullQData(oldp+107723,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_pte_ppn),44);
    bufp->fullCData(oldp+107725,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_pte_reserved_for_software),2);
    bufp->fullBit(oldp+107726,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_pte_d));
    bufp->fullBit(oldp+107727,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_pte_a));
    bufp->fullBit(oldp+107728,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_pte_g));
    bufp->fullBit(oldp+107729,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_pte_u));
    bufp->fullBit(oldp+107730,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_pte_x));
    bufp->fullBit(oldp+107731,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_pte_w));
    bufp->fullBit(oldp+107732,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_pte_r));
    bufp->fullBit(oldp+107733,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_pte_v));
    bufp->fullBit(oldp+107734,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__stage2));
    bufp->fullBit(oldp+107735,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__stage2_final));
    bufp->fullBit(oldp+107736,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__do_both_stages));
    bufp->fullBit(oldp+107737,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__mem_resp_valid));
    bufp->fullQData(oldp+107738,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__mem_resp_data),64);
    bufp->fullBit(oldp+107740,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_pte_pte_v));
    bufp->fullBit(oldp+107741,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__invalid_paddr));
    bufp->fullBit(oldp+107742,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__traverse));
    bufp->fullSData(oldp+107743,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__pte_addr_vpn_idx),9);
    bufp->fullCData(oldp+107744,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__state_reg),7);
    bufp->fullCData(oldp+107745,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__valid),8);
    bufp->fullIData(oldp+107746,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tags_0),32);
    bufp->fullIData(oldp+107747,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tags_1),32);
    bufp->fullIData(oldp+107748,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tags_2),32);
    bufp->fullIData(oldp+107749,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tags_3),32);
    bufp->fullIData(oldp+107750,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tags_4),32);
    bufp->fullIData(oldp+107751,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tags_5),32);
    bufp->fullIData(oldp+107752,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tags_6),32);
    bufp->fullIData(oldp+107753,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tags_7),32);
    bufp->fullIData(oldp+107754,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__data_0),20);
    bufp->fullIData(oldp+107755,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__data_1),20);
    bufp->fullIData(oldp+107756,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__data_2),20);
    bufp->fullIData(oldp+107757,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__data_3),20);
    bufp->fullIData(oldp+107758,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__data_4),20);
    bufp->fullIData(oldp+107759,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__data_5),20);
    bufp->fullIData(oldp+107760,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__data_6),20);
    bufp->fullIData(oldp+107761,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__data_7),20);
    bufp->fullBit(oldp+107762,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__can_hit));
    bufp->fullQData(oldp+107763,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tag),33);
    bufp->fullCData(oldp+107765,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__hits),8);
    bufp->fullBit(oldp+107766,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__pte_cache_hit));
    bufp->fullCData(oldp+107767,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__state_reg_1),7);
    bufp->fullCData(oldp+107768,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__valid_1),8);
    bufp->fullIData(oldp+107769,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tags_1_0),32);
    bufp->fullIData(oldp+107770,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tags_1_1),32);
    bufp->fullIData(oldp+107771,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tags_1_2),32);
    bufp->fullIData(oldp+107772,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tags_1_3),32);
    bufp->fullIData(oldp+107773,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tags_1_4),32);
    bufp->fullIData(oldp+107774,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tags_1_5),32);
    bufp->fullIData(oldp+107775,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tags_1_6),32);
    bufp->fullIData(oldp+107776,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tags_1_7),32);
    bufp->fullIData(oldp+107777,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__data_1_0),20);
    bufp->fullIData(oldp+107778,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__data_1_1),20);
    bufp->fullIData(oldp+107779,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__data_1_2),20);
    bufp->fullIData(oldp+107780,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__data_1_3),20);
    bufp->fullIData(oldp+107781,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__data_1_4),20);
    bufp->fullIData(oldp+107782,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__data_1_5),20);
    bufp->fullIData(oldp+107783,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__data_1_6),20);
    bufp->fullIData(oldp+107784,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__data_1_7),20);
    bufp->fullBit(oldp+107785,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__pte_hit));
    bufp->fullWData(oldp+107786,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0),512);
    bufp->fullWData(oldp+107802,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0),512);
    bufp->fullBit(oldp+107818,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_4));
    bufp->fullBit(oldp+107819,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_5));
    bufp->fullQData(oldp+107820,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_2),45);
    bufp->fullBit(oldp+107822,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_3));
    bufp->fullBit(oldp+107823,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_4_0));
    bufp->fullBit(oldp+107824,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__l2_error));
    bufp->fullBit(oldp+107825,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__l2_hit));
    bufp->fullIData(oldp+107826,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask),32);
    bufp->fullIData(oldp+107827,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_1),32);
    bufp->fullIData(oldp+107828,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_2),32);
    bufp->fullIData(oldp+107829,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_3),32);
    bufp->fullIData(oldp+107830,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_4),32);
    bufp->fullIData(oldp+107831,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_5),32);
    bufp->fullIData(oldp+107832,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_6),32);
    bufp->fullIData(oldp+107833,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_7),32);
    bufp->fullBit(oldp+107834,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__gf));
    bufp->fullBit(oldp+107835,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__ae));
    bufp->fullBit(oldp+107836,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__pf));
    bufp->fullBit(oldp+107837,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__success));
    bufp->fullCData(oldp+107838,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r),3);
    bufp->fullCData(oldp+107839,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_1),3);
    bufp->fullBit(oldp+107840,(((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__state)) 
                                | (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__state)))));
    bufp->fullBit(oldp+107841,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___arb_io_out_bits_valid));
    bufp->fullIData(oldp+107842,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___arb_io_out_bits_bits_addr),27);
    bufp->fullBit(oldp+107843,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___arb_io_out_bits_bits_need_gpa));
    bufp->fullBit(oldp+107844,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___arb_io_out_bits_bits_vstage1));
    bufp->fullBit(oldp+107845,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___arb_io_out_bits_bits_stage2));
    bufp->fullCData(oldp+107846,(((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__state))
                                   ? 0U : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__state))
                                            ? 1U : 2U))),2);
    bufp->fullSData(oldp+107847,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT____Vcellinp__l2_tlb_ram_0__RW0_addr),9);
    bufp->fullBit(oldp+107848,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT____Vcellinp__l2_tlb_ram_0__RW0_en));
    bufp->fullQData(oldp+107849,((((QData)((IData)(
                                                   (1U 
                                                    & (((((((VL_REDXOR_32(
                                                                          (0x7fffe00U 
                                                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_req_addr)) 
                                                             ^ 
                                                             VL_REDXOR_32(
                                                                          (0xfffffULL 
                                                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_ppn))) 
                                                            ^ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_d)) 
                                                           ^ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_a)) 
                                                          ^ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_u)) 
                                                         ^ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_x)) 
                                                        ^ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_w)) 
                                                       ^ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_r))))) 
                                   << 0x2cU) | (((QData)((IData)(
                                                                 (0x3ffffU 
                                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_req_addr 
                                                                     >> 9U)))) 
                                                 << 0x1aU) 
                                                | (QData)((IData)(
                                                                  ((0x3ffffc0U 
                                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_ppn) 
                                                                       << 6U)) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_d) 
                                                                       << 5U) 
                                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_a) 
                                                                          << 4U) 
                                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_u) 
                                                                             << 3U) 
                                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_x) 
                                                                                << 2U) 
                                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_w) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_r)))))))))))),45);
    bufp->fullQData(oldp+107851,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__l2_tlb_ram_0__DOT__l2_tlb_ram_0_ext__DOT__mem_0_0__DOT__ram
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__l2_tlb_ram_0__DOT__l2_tlb_ram_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0]),45);
    bufp->fullBit(oldp+107853,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__l2_tlb_ram_0__DOT__l2_tlb_ram_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_en_pipe_0));
    bufp->fullSData(oldp+107854,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__l2_tlb_ram_0__DOT__l2_tlb_ram_0_ext__DOT__mem_0_0__DOT__ram_RW_0_r_addr_pipe_0),9);
    bufp->fullBit(oldp+107855,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT____Vcellinp__l2_tlb_ram_0__RW0_en) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__l2_refill))));
    bufp->fullSData(oldp+107856,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___GEN_13)
                                   ? 0U : (0x3ffU & 
                                           ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___GEN_12)
                                             ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_reserved_for_future)
                                             : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___r_pte_T_8)
                                                 ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_pte_reserved_for_future)
                                                 : (IData)(
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__mem_resp_data 
                                                            >> 0x36U))))))),10);
    bufp->fullQData(oldp+107857,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT____Vcellinp__r_pte_barrier__io_x_ppn),44);
    bufp->fullCData(oldp+107859,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___GEN_13)
                                   ? 0U : (3U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___GEN_12)
                                                  ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_reserved_for_software)
                                                  : 
                                                 ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___r_pte_T_8)
                                                   ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_pte_reserved_for_software)
                                                   : (IData)(
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__mem_resp_data 
                                                              >> 8U))))))),2);
    bufp->fullBit(oldp+107860,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___GEN_14)
                                       ? (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_2 
                                                  >> 5U))
                                       : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___GEN_12)
                                           ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_d)
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___r_pte_T_8)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_pte_d)
                                               : (IData)(
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__mem_resp_data 
                                                          >> 7U))))))));
    bufp->fullBit(oldp+107861,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___GEN_14)
                                       ? (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_2 
                                                  >> 4U))
                                       : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___GEN_12)
                                           ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_a)
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___r_pte_T_8)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_pte_a)
                                               : (IData)(
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__mem_resp_data 
                                                          >> 6U))))))));
    bufp->fullBit(oldp+107862,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___GEN_14)
                                       ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_4_0)
                                       : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___GEN_12)
                                           ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_g)
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___r_pte_T_8)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_pte_g)
                                               : (IData)(
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__mem_resp_data 
                                                          >> 5U))))))));
    bufp->fullBit(oldp+107863,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___GEN_14)
                                       ? (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_2 
                                                  >> 3U))
                                       : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___GEN_12)
                                           ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_u)
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___r_pte_T_8)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_pte_u)
                                               : (IData)(
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__mem_resp_data 
                                                          >> 4U))))))));
    bufp->fullBit(oldp+107864,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___GEN_14)
                                       ? (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_2 
                                                  >> 2U))
                                       : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___GEN_12)
                                           ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_x)
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___r_pte_T_8)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_pte_x)
                                               : (IData)(
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__mem_resp_data 
                                                          >> 3U))))))));
    bufp->fullBit(oldp+107865,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___GEN_14)
                                       ? (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_2 
                                                  >> 1U))
                                       : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___GEN_12)
                                           ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_w)
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___r_pte_T_8)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_pte_w)
                                               : (IData)(
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__mem_resp_data 
                                                          >> 2U))))))));
    bufp->fullBit(oldp+107866,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___GEN_14)
                                       ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_2)
                                       : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___GEN_12)
                                           ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_r)
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___r_pte_T_8)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_pte_r)
                                               : (IData)(
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__mem_resp_data 
                                                          >> 1U))))))));
    bufp->fullBit(oldp+107867,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___GEN_13) 
                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___GEN_12)
                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_v)
                                    : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___r_pte_T_8)
                                        ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_pte_v)
                                        : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_pte_pte_v))))));
    bufp->fullCData(oldp+107868,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_hellacache_s2_nack) 
                                   & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__hellaCacheArb__DOT__s2_id)))
                                   ? 1U : (7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__mem_resp_valid)
                                                  ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___GEN_15)
                                                  : 
                                                 ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___T_222)
                                                   ? 0U
                                                   : 
                                                  ((0x17U 
                                                    >= 
                                                    (0x1fU 
                                                     & ((IData)(3U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__state))))
                                                    ? 
                                                   ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__state) 
                                                      << 0x12U) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__state) 
                                                         << 0xfU) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_hellacache_s2_xcpt_ae_ld)
                                                              ? 0U
                                                              : 5U) 
                                                            << 0xcU) 
                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__state) 
                                                               << 9U) 
                                                              | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__l2_hit)
                                                                    ? 1U
                                                                    : 4U) 
                                                                  << 6U) 
                                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__pte_cache_hit)
                                                                       ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__state)
                                                                       : 
                                                                      ((0U 
                                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__hella_state))
                                                                        ? 2U
                                                                        : 1U)) 
                                                                     << 3U) 
                                                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___r_pte_T_23)
                                                                        ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___arb_io_out_bits_valid)
                                                                        : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__state)))))))) 
                                                    >> 
                                                    (0x1fU 
                                                     & ((IData)(3U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__state))))
                                                    : 0U)))))),3);
    bufp->fullBit(oldp+107869,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__respArb_io_in_0_q__DOT__enq_ptr_value));
    bufp->fullBit(oldp+107870,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__respArb_io_in_0_q__DOT__deq_ptr_value));
    bufp->fullBit(oldp+107871,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__respArb_io_in_0_q__DOT__maybe_full));
    bufp->fullBit(oldp+107872,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__respArb_io_in_0_q__DOT__ptr_match));
    bufp->fullBit(oldp+107873,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__respArb_io_in_0_q__DOT__empty));
    bufp->fullBit(oldp+107874,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__respArb_io_in_0_q__DOT__ptr_match) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__respArb_io_in_0_q__DOT__maybe_full))));
    bufp->fullBit(oldp+107875,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__respArb_io_in_0_q__DOT__do_enq));
    bufp->fullBit(oldp+107876,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__respArb_io_in_0_q__DOT__do_deq));
    __Vtemp_h87c3cf5c__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__respArb_io_in_0_q__DOT__ram_ext__DOT__Memory
        [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__respArb_io_in_0_q__DOT__deq_ptr_value][0U];
    __Vtemp_h87c3cf5c__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__respArb_io_in_0_q__DOT__ram_ext__DOT__Memory
        [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__respArb_io_in_0_q__DOT__deq_ptr_value][1U];
    __Vtemp_h87c3cf5c__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__respArb_io_in_0_q__DOT__ram_ext__DOT__Memory
        [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__respArb_io_in_0_q__DOT__deq_ptr_value][2U];
    bufp->fullWData(oldp+107877,(__Vtemp_h87c3cf5c__0),69);
    bufp->fullWData(oldp+107880,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__respArb_io_in_0_q__DOT__ram_ext__DOT__Memory[0]),69);
    bufp->fullWData(oldp+107883,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__respArb_io_in_0_q__DOT__ram_ext__DOT__Memory[1]),69);
    bufp->fullBit(oldp+107886,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeated_repeater__DOT___io_deq_valid_output));
    bufp->fullCData(oldp+107887,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT___repeated_repeater_io_deq_bits_opcode),3);
    bufp->fullCData(oldp+107888,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___widget_1_auto_out_a_bits_param),3);
    bufp->fullCData(oldp+107889,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT___repeated_repeater_io_deq_bits_size),4);
    bufp->fullBit(oldp+107890,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___widget_1_auto_out_a_bits_source));
    bufp->fullIData(oldp+107891,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT___repeated_repeater_io_deq_bits_address),32);
    bufp->fullCData(oldp+107892,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___widget_1_auto_out_a_bits_mask),8);
    bufp->fullQData(oldp+107893,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeat_index)
                                   ? (((QData)((IData)(
                                                       ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeated_repeater__DOT__full)
                                                         ? 
                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeated_repeater__DOT__saved_data[3U]
                                                         : 0U))) 
                                       << 0x20U) | (QData)((IData)(
                                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeated_repeater__DOT__full)
                                                                     ? 
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeated_repeater__DOT__saved_data[2U]
                                                                     : 0U))))
                                   : 0ULL)),64);
    bufp->fullBit(oldp+107895,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeated_repeater__DOT__full) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeated_repeater__DOT__saved_corrupt))));
    bufp->fullBit(oldp+107896,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater__DOT___io_deq_valid_output));
    bufp->fullCData(oldp+107897,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT___repeated_repeater_io_deq_bits_opcode),3);
    bufp->fullCData(oldp+107898,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___widget_auto_out_a_bits_param),3);
    bufp->fullCData(oldp+107899,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT___repeated_repeater_io_deq_bits_size),4);
    bufp->fullCData(oldp+107900,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___widget_auto_out_a_bits_source),3);
    bufp->fullIData(oldp+107901,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT___repeated_repeater_io_deq_bits_address),32);
    bufp->fullCData(oldp+107902,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___widget_auto_out_a_bits_mask),8);
    bufp->fullQData(oldp+107903,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeat_index)
                                   ? (((QData)((IData)(
                                                       ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater__DOT__full)
                                                         ? 
                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater__DOT__saved_data[3U]
                                                         : 
                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_a_bits_data[3U]))) 
                                       << 0x20U) | (QData)((IData)(
                                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater__DOT__full)
                                                                     ? 
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater__DOT__saved_data[2U]
                                                                     : 
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_a_bits_data[2U]))))
                                   : (((QData)((IData)(
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_a_bits_data[1U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_a_bits_data[0U]))))),64);
    bufp->fullBit(oldp+107905,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater__DOT__full) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater__DOT__saved_corrupt))));
    bufp->fullCData(oldp+107906,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___widget_auto_out_c_bits_source),3);
    bufp->fullBit(oldp+107907,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__x1_d_ready));
    bufp->fullBit(oldp+107908,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__portsAOI_filtered_1_0_ready));
    bufp->fullBit(oldp+107909,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__out_13_valid));
    bufp->fullBit(oldp+107910,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__portsAOI_filtered_0_ready));
    bufp->fullBit(oldp+107911,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__out_10_valid));
    bufp->fullBit(oldp+107912,((8U == (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                               >> 9U)))));
    bufp->fullSData(oldp+107913,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__beatsLeft),9);
    bufp->fullBit(oldp+107914,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__beatsLeft))));
    bufp->fullCData(oldp+107915,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__readys_valid),2);
    bufp->fullCData(oldp+107916,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__readys_mask),2);
    bufp->fullCData(oldp+107917,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__readys_readys),2);
    bufp->fullBit(oldp+107918,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__readys_readys) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater__DOT___io_deq_valid_output))));
    bufp->fullBit(oldp+107919,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__readys_readys) 
                                 >> 1U) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeated_repeater__DOT___io_deq_valid_output))));
    bufp->fullBit(oldp+107920,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__state_0));
    bufp->fullBit(oldp+107921,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__state_1));
    bufp->fullBit(oldp+107922,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__muxStateEarly_0));
    bufp->fullBit(oldp+107923,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__muxStateEarly_1));
    bufp->fullBit(oldp+107924,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__latch));
    bufp->fullBit(oldp+107925,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__winnerQual_0));
    bufp->fullBit(oldp+107926,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__winnerQual_1));
    bufp->fullSData(oldp+107927,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__a_first_counter),9);
    bufp->fullCData(oldp+107928,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__opcode),3);
    bufp->fullCData(oldp+107929,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__param),3);
    bufp->fullCData(oldp+107930,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__size),4);
    bufp->fullCData(oldp+107931,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__source),3);
    bufp->fullIData(oldp+107932,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__address),32);
    bufp->fullSData(oldp+107933,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_first_counter),9);
    bufp->fullCData(oldp+107934,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__opcode_1),3);
    bufp->fullCData(oldp+107935,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__param_1),2);
    bufp->fullCData(oldp+107936,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__size_1),4);
    bufp->fullCData(oldp+107937,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__source_1),3);
    bufp->fullCData(oldp+107938,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__sink),3);
    bufp->fullBit(oldp+107939,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__denied));
    bufp->fullSData(oldp+107940,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__c_first_counter),9);
    bufp->fullCData(oldp+107941,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__opcode_3),3);
    bufp->fullCData(oldp+107942,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__param_3),3);
    bufp->fullCData(oldp+107943,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__size_3),4);
    bufp->fullCData(oldp+107944,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__source_3),3);
    bufp->fullIData(oldp+107945,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__address_2),32);
    bufp->fullCData(oldp+107946,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__inflight),6);
    bufp->fullIData(oldp+107947,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__inflight_opcodes),24);
    bufp->fullQData(oldp+107948,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__inflight_sizes),48);
    bufp->fullSData(oldp+107950,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__a_first_counter_1),9);
    bufp->fullBit(oldp+107951,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__a_first_counter_1))));
    bufp->fullSData(oldp+107952,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_first_counter_1),9);
    bufp->fullBit(oldp+107953,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_first_counter_1))));
    bufp->fullIData(oldp+107954,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__watchdog),32);
    bufp->fullCData(oldp+107955,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__inflight_1),6);
    bufp->fullQData(oldp+107956,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__inflight_sizes_1),48);
    bufp->fullSData(oldp+107958,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__c_first_counter_1),9);
    bufp->fullBit(oldp+107959,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__c_first_counter_1))));
    bufp->fullSData(oldp+107960,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_first_counter_2),9);
    bufp->fullBit(oldp+107961,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_first_counter_2))));
    bufp->fullIData(oldp+107962,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__watchdog_1),32);
    bufp->fullCData(oldp+107963,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__inflight_2),8);
    bufp->fullSData(oldp+107964,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_first_counter_3),9);
    bufp->fullBit(oldp+107965,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_first_counter_3))));
    bufp->fullCData(oldp+107966,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_set),8);
    bufp->fullBit(oldp+107967,(((5U > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___widget_auto_out_a_bits_source)) 
                                | (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___widget_auto_out_a_bits_source)))));
    bufp->fullBit(oldp+107968,((2U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT___repeated_repeater_io_deq_bits_size)))));
    bufp->fullBit(oldp+107969,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc));
    bufp->fullBit(oldp+107970,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_1));
    bufp->fullBit(oldp+107971,((1U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT___repeated_repeater_io_deq_bits_size)))));
    bufp->fullBit(oldp+107972,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_2));
    bufp->fullBit(oldp+107973,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_2));
    bufp->fullBit(oldp+107974,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_3));
    bufp->fullBit(oldp+107975,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_3));
    bufp->fullBit(oldp+107976,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_4));
    bufp->fullBit(oldp+107977,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_4));
    bufp->fullBit(oldp+107978,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_5));
    bufp->fullBit(oldp+107979,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_5));
    bufp->fullCData(oldp+107980,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_5) 
                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_5) 
                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT___repeated_repeater_io_deq_bits_address)) 
                                   << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_5) 
                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_5) 
                                                  & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT___repeated_repeater_io_deq_bits_address))) 
                                              << 6U) 
                                             | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_4) 
                                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_4) 
                                                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT___repeated_repeater_io_deq_bits_address)) 
                                                 << 5U) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_4) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_4) 
                                                        & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT___repeated_repeater_io_deq_bits_address))) 
                                                    << 4U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_3) 
                                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_3) 
                                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT___repeated_repeater_io_deq_bits_address)) 
                                                       << 3U) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_3) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_3) 
                                                              & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT___repeated_repeater_io_deq_bits_address))) 
                                                          << 2U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_2) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_2) 
                                                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT___repeated_repeater_io_deq_bits_address)) 
                                                             << 1U) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_2) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_2) 
                                                                  & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT___repeated_repeater_io_deq_bits_address))))))))))),8);
    bufp->fullBit(oldp+107981,(((5U > (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                             >> 9U))) 
                                | (5U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                >> 9U))))));
    bufp->fullBit(oldp+107982,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_14));
    bufp->fullBit(oldp+107983,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_15));
    bufp->fullBit(oldp+107984,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_16));
    bufp->fullBit(oldp+107985,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_16));
    bufp->fullBit(oldp+107986,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_17));
    bufp->fullBit(oldp+107987,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_17));
    bufp->fullBit(oldp+107988,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_18));
    bufp->fullBit(oldp+107989,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_18));
    bufp->fullBit(oldp+107990,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_19));
    bufp->fullBit(oldp+107991,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_19));
    bufp->fullCData(oldp+107992,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_19) 
                                    << 7U) | (0x3ffff80U 
                                              & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_19) 
                                                  << 7U) 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__bundleIn_0_b_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 6U)))) 
                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_19) 
                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_19) 
                                          & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__bundleIn_0_b_q__DOT___ram_ext_R0_data[0U] 
                                                >> 0xdU)))) 
                                      << 6U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_18) 
                                                  << 5U) 
                                                 | (0xffffe0U 
                                                    & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_18) 
                                                        << 5U) 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__bundleIn_0_b_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 8U)))) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_18) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_18) 
                                                        & (~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__bundleIn_0_b_q__DOT___ram_ext_R0_data[0U] 
                                                            >> 0xdU)))) 
                                                    << 4U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_17) 
                                                        << 3U) 
                                                       | (0x3ffff8U 
                                                          & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_17) 
                                                              << 3U) 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__bundleIn_0_b_q__DOT___ram_ext_R0_data[0U] 
                                                                >> 0xaU)))) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_17) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_17) 
                                                              & (~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__bundleIn_0_b_q__DOT___ram_ext_R0_data[0U] 
                                                                  >> 0xdU)))) 
                                                          << 2U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_16) 
                                                              << 1U) 
                                                             | (0xffffeU 
                                                                & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_16) 
                                                                    << 1U) 
                                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__bundleIn_0_b_q__DOT___ram_ext_R0_data[0U] 
                                                                      >> 0xcU)))) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_16) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_16) 
                                                                  & (~ 
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__bundleIn_0_b_q__DOT___ram_ext_R0_data[0U] 
                                                                      >> 0xdU)))))))))))),8);
    bufp->fullBit(oldp+107993,(((5U > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___widget_auto_out_c_bits_source)) 
                                | (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___widget_auto_out_c_bits_source)))));
    bufp->fullCData(oldp+107994,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT___same_cycle_resp_T_1)
                                   ? ((7U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___widget_auto_out_a_bits_source))
                                       ? (0x3fU & ((IData)(1U) 
                                                   << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___widget_auto_out_a_bits_source)))
                                       : 0U) : 0U)),6);
    bufp->fullBit(oldp+107995,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__same_cycle_resp));
    bufp->fullCData(oldp+107996,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT___same_cycle_resp_T_3) 
                                   & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT___repeated_repeater_1_io_deq_bits_opcode))))
                                   ? ((7U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___widget_auto_out_c_bits_source))
                                       ? (0x3fU & ((IData)(1U) 
                                                   << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___widget_auto_out_c_bits_source)))
                                       : 0U) : 0U)),6);
    bufp->fullBit(oldp+107997,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT___same_cycle_resp_T_3) 
                                 & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT___repeated_repeater_1_io_deq_bits_opcode)))) 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___widget_auto_out_c_bits_source) 
                                   == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                             >> 9U))))));
    bufp->fullSData(oldp+107998,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__a_first_counter),9);
    bufp->fullCData(oldp+107999,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__opcode),3);
    bufp->fullCData(oldp+108000,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__param),3);
    bufp->fullCData(oldp+108001,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__size),4);
    bufp->fullBit(oldp+108002,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__source));
    bufp->fullIData(oldp+108003,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__address),32);
    bufp->fullSData(oldp+108004,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_first_counter),9);
    bufp->fullCData(oldp+108005,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__opcode_1),3);
    bufp->fullCData(oldp+108006,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__param_1),2);
    bufp->fullCData(oldp+108007,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__size_1),4);
    bufp->fullBit(oldp+108008,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__source_1));
    bufp->fullCData(oldp+108009,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__sink),3);
    bufp->fullBit(oldp+108010,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__denied));
    bufp->fullBit(oldp+108011,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__inflight));
    bufp->fullCData(oldp+108012,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__inflight_opcodes),4);
    bufp->fullCData(oldp+108013,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__inflight_sizes),8);
    bufp->fullSData(oldp+108014,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__a_first_counter_1),9);
    bufp->fullBit(oldp+108015,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__a_first_counter_1))));
    bufp->fullSData(oldp+108016,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_first_counter_1),9);
    bufp->fullBit(oldp+108017,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_first_counter_1))));
    bufp->fullIData(oldp+108018,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__watchdog),32);
    bufp->fullSData(oldp+108019,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_first_counter_2),9);
    bufp->fullBit(oldp+108020,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_first_counter_2))));
    bufp->fullBit(oldp+108021,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_clr));
    bufp->fullBit(oldp+108022,((2U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT___repeated_repeater_io_deq_bits_size)))));
    bufp->fullBit(oldp+108023,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__mask_acc));
    bufp->fullBit(oldp+108024,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__mask_acc_1));
    bufp->fullBit(oldp+108025,((1U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT___repeated_repeater_io_deq_bits_size)))));
    bufp->fullBit(oldp+108026,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__mask_eq_2));
    bufp->fullBit(oldp+108027,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__mask_acc_2));
    bufp->fullBit(oldp+108028,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__mask_eq_3));
    bufp->fullBit(oldp+108029,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__mask_acc_3));
    bufp->fullBit(oldp+108030,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__mask_eq_4));
    bufp->fullBit(oldp+108031,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__mask_acc_4));
    bufp->fullBit(oldp+108032,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__mask_eq_5));
    bufp->fullBit(oldp+108033,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__mask_acc_5));
    bufp->fullCData(oldp+108034,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__mask_acc_5) 
                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__mask_eq_5) 
                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT___repeated_repeater_io_deq_bits_address)) 
                                   << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__mask_acc_5) 
                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__mask_eq_5) 
                                                  & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT___repeated_repeater_io_deq_bits_address))) 
                                              << 6U) 
                                             | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__mask_acc_4) 
                                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__mask_eq_4) 
                                                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT___repeated_repeater_io_deq_bits_address)) 
                                                 << 5U) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__mask_acc_4) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__mask_eq_4) 
                                                        & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT___repeated_repeater_io_deq_bits_address))) 
                                                    << 4U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__mask_acc_3) 
                                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__mask_eq_3) 
                                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT___repeated_repeater_io_deq_bits_address)) 
                                                       << 3U) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__mask_acc_3) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__mask_eq_3) 
                                                              & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT___repeated_repeater_io_deq_bits_address))) 
                                                          << 2U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__mask_acc_2) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__mask_eq_2) 
                                                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT___repeated_repeater_io_deq_bits_address)) 
                                                             << 1U) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__mask_acc_2) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__mask_eq_2) 
                                                                  & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT___repeated_repeater_io_deq_bits_address))))))))))),8);
    bufp->fullBit(oldp+108035,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT___same_cycle_resp_T_1) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___widget_1_auto_out_a_bits_source)))));
    bufp->fullBit(oldp+108036,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__same_cycle_resp));
    bufp->fullBit(oldp+108037,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeat_count));
    bufp->fullBit(oldp+108038,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeat_last));
    bufp->fullBit(oldp+108039,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeat_index));
    bufp->fullBit(oldp+108040,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__count));
    bufp->fullBit(oldp+108041,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__last));
    bufp->fullBit(oldp+108042,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__corrupt_reg));
    bufp->fullBit(oldp+108043,((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                         >> 0x11U) 
                                        | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__corrupt_reg)))));
    bufp->fullBit(oldp+108044,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_d_bits_data_rdata_written_once));
    bufp->fullBit(oldp+108045,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_d_bits_data_masked_enable_0));
    bufp->fullQData(oldp+108046,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_d_bits_data_rdata_0),64);
    bufp->fullBit(oldp+108048,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_b_bits_mask_acc));
    bufp->fullBit(oldp+108049,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_b_bits_mask_acc_1));
    bufp->fullBit(oldp+108050,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_b_bits_mask_eq_2));
    bufp->fullBit(oldp+108051,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_b_bits_mask_acc_2));
    bufp->fullBit(oldp+108052,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_b_bits_mask_eq_3));
    bufp->fullBit(oldp+108053,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_b_bits_mask_acc_3));
    bufp->fullBit(oldp+108054,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_b_bits_mask_eq_4));
    bufp->fullBit(oldp+108055,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_b_bits_mask_acc_4));
    bufp->fullBit(oldp+108056,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_b_bits_mask_eq_5));
    bufp->fullBit(oldp+108057,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_b_bits_mask_acc_5));
    bufp->fullBit(oldp+108058,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_b_bits_mask_eq_6));
    bufp->fullBit(oldp+108059,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_b_bits_mask_acc_6));
    bufp->fullBit(oldp+108060,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_b_bits_mask_eq_7));
    bufp->fullBit(oldp+108061,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_b_bits_mask_acc_7));
    bufp->fullBit(oldp+108062,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_b_bits_mask_eq_8));
    bufp->fullBit(oldp+108063,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_b_bits_mask_acc_8));
    bufp->fullBit(oldp+108064,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_b_bits_mask_eq_9));
    bufp->fullBit(oldp+108065,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_b_bits_mask_acc_9));
    bufp->fullBit(oldp+108066,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_b_bits_mask_eq_10));
    bufp->fullBit(oldp+108067,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_b_bits_mask_acc_10));
    bufp->fullBit(oldp+108068,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_b_bits_mask_eq_11));
    bufp->fullBit(oldp+108069,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_b_bits_mask_acc_11));
    bufp->fullBit(oldp+108070,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_b_bits_mask_eq_12));
    bufp->fullBit(oldp+108071,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_b_bits_mask_acc_12));
    bufp->fullBit(oldp+108072,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_b_bits_mask_eq_13));
    bufp->fullBit(oldp+108073,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__bundleIn_0_b_bits_mask_acc_13));
    bufp->fullBit(oldp+108074,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeat_count_1));
    bufp->fullBit(oldp+108075,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeat_last_1));
    bufp->fullSData(oldp+108076,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT____Vcellinp__monitor__io_in_b_bits_mask),16);
    bufp->fullCData(oldp+108077,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__a_first_counter),8);
    bufp->fullCData(oldp+108078,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__opcode),3);
    bufp->fullCData(oldp+108079,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__param),3);
    bufp->fullCData(oldp+108080,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__size),4);
    bufp->fullCData(oldp+108081,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__source),3);
    bufp->fullIData(oldp+108082,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__address),32);
    bufp->fullCData(oldp+108083,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__d_first_counter),8);
    bufp->fullCData(oldp+108084,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__opcode_1),3);
    bufp->fullCData(oldp+108085,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__param_1),2);
    bufp->fullCData(oldp+108086,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__size_1),4);
    bufp->fullCData(oldp+108087,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__source_1),3);
    bufp->fullCData(oldp+108088,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__sink),3);
    bufp->fullBit(oldp+108089,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__denied));
    bufp->fullCData(oldp+108090,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__c_first_counter),8);
    bufp->fullCData(oldp+108091,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__opcode_3),3);
    bufp->fullCData(oldp+108092,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__param_3),3);
    bufp->fullCData(oldp+108093,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__size_3),4);
    bufp->fullCData(oldp+108094,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__source_3),3);
    bufp->fullIData(oldp+108095,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__address_2),32);
    bufp->fullCData(oldp+108096,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__inflight),6);
    bufp->fullIData(oldp+108097,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__inflight_opcodes),24);
    bufp->fullQData(oldp+108098,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__inflight_sizes),48);
    bufp->fullCData(oldp+108100,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__a_first_counter_1),8);
    bufp->fullBit(oldp+108101,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__a_first_counter_1))));
    bufp->fullCData(oldp+108102,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__d_first_counter_1),8);
    bufp->fullBit(oldp+108103,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__d_first_counter_1))));
    bufp->fullIData(oldp+108104,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__watchdog),32);
    bufp->fullCData(oldp+108105,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__inflight_1),6);
    bufp->fullQData(oldp+108106,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__inflight_sizes_1),48);
    bufp->fullCData(oldp+108108,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__c_first_counter_1),8);
    bufp->fullBit(oldp+108109,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__c_first_counter_1))));
    bufp->fullCData(oldp+108110,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__d_first_counter_2),8);
    bufp->fullBit(oldp+108111,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__d_first_counter_2))));
    bufp->fullIData(oldp+108112,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__watchdog_1),32);
    bufp->fullCData(oldp+108113,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__inflight_2),8);
    bufp->fullCData(oldp+108114,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__d_first_counter_3),8);
    bufp->fullBit(oldp+108115,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__d_first_counter_3))));
    bufp->fullCData(oldp+108116,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__d_set),8);
    bufp->fullBit(oldp+108117,(((5U > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_a_bits_source)) 
                                | (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_a_bits_source)))));
    bufp->fullBit(oldp+108118,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc));
    bufp->fullBit(oldp+108119,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_1));
    bufp->fullBit(oldp+108120,((2U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_a_bits_size)))));
    bufp->fullBit(oldp+108121,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_eq_2));
    bufp->fullBit(oldp+108122,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_2));
    bufp->fullBit(oldp+108123,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_eq_3));
    bufp->fullBit(oldp+108124,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_3));
    bufp->fullBit(oldp+108125,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_eq_4));
    bufp->fullBit(oldp+108126,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_4));
    bufp->fullBit(oldp+108127,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_eq_5));
    bufp->fullBit(oldp+108128,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_5));
    bufp->fullBit(oldp+108129,((1U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_a_bits_size)))));
    bufp->fullBit(oldp+108130,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_eq_6));
    bufp->fullBit(oldp+108131,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_6));
    bufp->fullBit(oldp+108132,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_eq_7));
    bufp->fullBit(oldp+108133,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_7));
    bufp->fullBit(oldp+108134,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_eq_8));
    bufp->fullBit(oldp+108135,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_8));
    bufp->fullBit(oldp+108136,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_eq_9));
    bufp->fullBit(oldp+108137,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_9));
    bufp->fullBit(oldp+108138,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_eq_10));
    bufp->fullBit(oldp+108139,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_10));
    bufp->fullBit(oldp+108140,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_eq_11));
    bufp->fullBit(oldp+108141,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_11));
    bufp->fullBit(oldp+108142,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_eq_12));
    bufp->fullBit(oldp+108143,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_12));
    bufp->fullBit(oldp+108144,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_eq_13));
    bufp->fullBit(oldp+108145,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_13));
    bufp->fullSData(oldp+108146,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask),16);
    bufp->fullBit(oldp+108147,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_30));
    bufp->fullBit(oldp+108148,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_31));
    bufp->fullBit(oldp+108149,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_eq_32));
    bufp->fullBit(oldp+108150,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_32));
    bufp->fullBit(oldp+108151,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_eq_33));
    bufp->fullBit(oldp+108152,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_33));
    bufp->fullBit(oldp+108153,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_eq_34));
    bufp->fullBit(oldp+108154,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_34));
    bufp->fullBit(oldp+108155,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_eq_35));
    bufp->fullBit(oldp+108156,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_35));
    bufp->fullBit(oldp+108157,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_eq_36));
    bufp->fullBit(oldp+108158,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_36));
    bufp->fullBit(oldp+108159,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_eq_37));
    bufp->fullBit(oldp+108160,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_37));
    bufp->fullBit(oldp+108161,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_eq_38));
    bufp->fullBit(oldp+108162,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_38));
    bufp->fullBit(oldp+108163,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_eq_39));
    bufp->fullBit(oldp+108164,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_39));
    bufp->fullBit(oldp+108165,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_eq_40));
    bufp->fullBit(oldp+108166,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_40));
    bufp->fullBit(oldp+108167,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_eq_41));
    bufp->fullBit(oldp+108168,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_41));
    bufp->fullBit(oldp+108169,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_eq_42));
    bufp->fullBit(oldp+108170,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_42));
    bufp->fullBit(oldp+108171,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_eq_43));
    bufp->fullBit(oldp+108172,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_acc_43));
    bufp->fullSData(oldp+108173,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__mask_1),16);
    bufp->fullBit(oldp+108174,(((5U > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_c_bits_source)) 
                                | (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_c_bits_source)))));
    bufp->fullBit(oldp+108175,((((((((((((((3U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_c_bits_address 
                                                   >> 0xcU)) 
                                           | (0x2010U 
                                              == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_c_bits_address 
                                                  >> 0xcU))) 
                                          | (4U == 
                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_c_bits_address 
                                              >> 0xcU))) 
                                         | (0x54000U 
                                            == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_c_bits_address 
                                                >> 0xcU))) 
                                        | (3U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_c_bits_address 
                                                  >> 0x1aU))) 
                                       | (0x200U == 
                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_c_bits_address 
                                           >> 0x10U))) 
                                      | (0U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_c_bits_address 
                                                >> 0xcU))) 
                                     | (1U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_c_bits_address 
                                               >> 0x10U))) 
                                    | (0x100U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_c_bits_address 
                                                  >> 0xcU))) 
                                   | (0x110U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_c_bits_address 
                                                 >> 0xcU))) 
                                  | (8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_c_bits_address 
                                            >> 0x1cU))) 
                                 | (0x10000U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_c_bits_address 
                                                 >> 0xcU))) 
                                | (2U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_c_bits_address 
                                          >> 0x10U)))));
    bufp->fullCData(oldp+108176,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT___same_cycle_resp_T_1)
                                   ? ((7U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_a_bits_source))
                                       ? (0x3fU & ((IData)(1U) 
                                                   << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_a_bits_source)))
                                       : 0U) : 0U)),6);
    bufp->fullBit(oldp+108177,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__same_cycle_resp));
    bufp->fullCData(oldp+108178,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT___same_cycle_resp_T_3) 
                                   & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_c_bits_opcode))))
                                   ? ((7U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_c_bits_source))
                                       ? (0x3fU & ((IData)(1U) 
                                                   << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_c_bits_source)))
                                       : 0U) : 0U)),6);
    bufp->fullBit(oldp+108179,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT___same_cycle_resp_T_3) 
                                 & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_c_bits_opcode)))) 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_c_bits_source) 
                                   == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                             >> 9U))))));
    bufp->fullBit(oldp+108180,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeat_last)))));
    bufp->fullSData(oldp+108181,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT___repeated_repeater_io_deq_bits_mask),16);
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater__DOT__full) {
        __Vtemp_h63bd5b97__1[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater__DOT__saved_data[0U];
        __Vtemp_h63bd5b97__1[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater__DOT__saved_data[1U];
        __Vtemp_h63bd5b97__1[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater__DOT__saved_data[2U];
        __Vtemp_h63bd5b97__1[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater__DOT__saved_data[3U];
    } else {
        __Vtemp_h63bd5b97__1[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_a_bits_data[0U];
        __Vtemp_h63bd5b97__1[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_a_bits_data[1U];
        __Vtemp_h63bd5b97__1[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_a_bits_data[2U];
        __Vtemp_h63bd5b97__1[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_a_bits_data[3U];
    }
    bufp->fullWData(oldp+108182,(__Vtemp_h63bd5b97__1),128);
    bufp->fullBit(oldp+108186,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater__DOT__full));
    bufp->fullCData(oldp+108187,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater__DOT__saved_opcode),3);
    bufp->fullCData(oldp+108188,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater__DOT__saved_param),3);
    bufp->fullCData(oldp+108189,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater__DOT__saved_size),4);
    bufp->fullCData(oldp+108190,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater__DOT__saved_source),3);
    bufp->fullIData(oldp+108191,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater__DOT__saved_address),32);
    bufp->fullSData(oldp+108192,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater__DOT__saved_mask),16);
    bufp->fullWData(oldp+108193,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater__DOT__saved_data),128);
    bufp->fullBit(oldp+108197,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater__DOT__saved_corrupt));
    bufp->fullBit(oldp+108198,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeat_last_1)))));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater_1__DOT__full) {
        __Vtemp_he59c122e__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater_1__DOT__saved_data[0U];
        __Vtemp_he59c122e__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater_1__DOT__saved_data[1U];
        __Vtemp_he59c122e__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater_1__DOT__saved_data[2U];
        __Vtemp_he59c122e__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater_1__DOT__saved_data[3U];
    } else {
        __Vtemp_he59c122e__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_c_bits_data[0U];
        __Vtemp_he59c122e__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_c_bits_data[1U];
        __Vtemp_he59c122e__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_c_bits_data[2U];
        __Vtemp_he59c122e__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___dcache_auto_out_c_bits_data[3U];
    }
    bufp->fullWData(oldp+108199,(__Vtemp_he59c122e__0),128);
    bufp->fullBit(oldp+108203,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater_1__DOT__full));
    bufp->fullCData(oldp+108204,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater_1__DOT__saved_opcode),3);
    bufp->fullCData(oldp+108205,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater_1__DOT__saved_param),3);
    bufp->fullCData(oldp+108206,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater_1__DOT__saved_size),4);
    bufp->fullCData(oldp+108207,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater_1__DOT__saved_source),3);
    bufp->fullIData(oldp+108208,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater_1__DOT__saved_address),32);
    bufp->fullWData(oldp+108209,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater_1__DOT__saved_data),128);
    bufp->fullBit(oldp+108213,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater_1__DOT__saved_corrupt));
    bufp->fullBit(oldp+108214,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeat_count));
    bufp->fullBit(oldp+108215,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeat_last));
    bufp->fullBit(oldp+108216,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeat_index));
    bufp->fullBit(oldp+108217,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__count));
    bufp->fullBit(oldp+108218,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__last));
    bufp->fullBit(oldp+108219,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__corrupt_reg));
    bufp->fullBit(oldp+108220,((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                         >> 0x11U) 
                                        | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__corrupt_reg)))));
    bufp->fullBit(oldp+108221,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__bundleIn_0_d_bits_data_rdata_written_once));
    bufp->fullBit(oldp+108222,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__bundleIn_0_d_bits_data_masked_enable_0));
    bufp->fullQData(oldp+108223,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__bundleIn_0_d_bits_data_rdata_0),64);
    bufp->fullBit(oldp+108225,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__monitor__DOT__a_set));
    bufp->fullCData(oldp+108226,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__monitor__DOT__d_first_counter),8);
    bufp->fullCData(oldp+108227,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__monitor__DOT__opcode_1),3);
    bufp->fullCData(oldp+108228,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__monitor__DOT__param_1),2);
    bufp->fullCData(oldp+108229,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__monitor__DOT__size_1),4);
    bufp->fullBit(oldp+108230,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__monitor__DOT__source_1));
    bufp->fullCData(oldp+108231,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__monitor__DOT__sink),3);
    bufp->fullBit(oldp+108232,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__monitor__DOT__denied));
    bufp->fullBit(oldp+108233,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__monitor__DOT__inflight));
    bufp->fullCData(oldp+108234,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__monitor__DOT__inflight_opcodes),4);
    bufp->fullCData(oldp+108235,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__monitor__DOT__inflight_sizes),8);
    bufp->fullCData(oldp+108236,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__monitor__DOT__d_first_counter_1),8);
    bufp->fullBit(oldp+108237,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__monitor__DOT__d_first_counter_1))));
    bufp->fullIData(oldp+108238,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__monitor__DOT__watchdog),32);
    bufp->fullCData(oldp+108239,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__monitor__DOT__d_first_counter_2),8);
    bufp->fullBit(oldp+108240,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__monitor__DOT__d_first_counter_2))));
    bufp->fullBit(oldp+108241,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__monitor__DOT__d_clr));
    bufp->fullBit(oldp+108242,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeat_last)))));
    bufp->fullSData(oldp+108243,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT___repeated_repeater_io_deq_bits_mask),16);
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeated_repeater__DOT__full) {
        __Vtemp_h06eca2c9__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeated_repeater__DOT__saved_data[0U];
        __Vtemp_h06eca2c9__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeated_repeater__DOT__saved_data[1U];
        __Vtemp_h06eca2c9__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeated_repeater__DOT__saved_data[2U];
        __Vtemp_h06eca2c9__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeated_repeater__DOT__saved_data[3U];
    } else {
        __Vtemp_h06eca2c9__0[0U] = 0U;
        __Vtemp_h06eca2c9__0[1U] = 0U;
        __Vtemp_h06eca2c9__0[2U] = 0U;
        __Vtemp_h06eca2c9__0[3U] = 0U;
    }
    bufp->fullWData(oldp+108244,(__Vtemp_h06eca2c9__0),128);
    bufp->fullBit(oldp+108248,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeated_repeater__DOT__full));
    bufp->fullCData(oldp+108249,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeated_repeater__DOT__saved_opcode),3);
    bufp->fullCData(oldp+108250,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeated_repeater__DOT__saved_param),3);
    bufp->fullCData(oldp+108251,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeated_repeater__DOT__saved_size),4);
    bufp->fullBit(oldp+108252,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeated_repeater__DOT__saved_source));
    bufp->fullIData(oldp+108253,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeated_repeater__DOT__saved_address),32);
    bufp->fullSData(oldp+108254,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeated_repeater__DOT__saved_mask),16);
    bufp->fullWData(oldp+108255,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeated_repeater__DOT__saved_data),128);
    bufp->fullBit(oldp+108259,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeated_repeater__DOT__saved_corrupt));
    bufp->fullBit(oldp+108260,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT___outArb_io_in_4_ready));
    bufp->fullBit(oldp+108261,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__manager_tl_d_valid));
    bufp->fullCData(oldp+108262,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                        >> 0x12U))),2);
    bufp->fullCData(oldp+108263,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                        >> 0xeU))),3);
    bufp->fullCData(oldp+108264,((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                          >> 0xaU))),4);
    bufp->fullBit(oldp+108265,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_0 
                                      >> 2U))));
    bufp->fullBit(oldp+108266,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_0 
                                      >> 1U))));
    bufp->fullBit(oldp+108267,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT__empty)))));
    bufp->fullCData(oldp+108268,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])),3);
    bufp->fullCData(oldp+108269,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                        >> 3U))),3);
    bufp->fullCData(oldp+108270,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                        >> 6U))),3);
    bufp->fullCData(oldp+108271,((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                          >> 9U))),4);
    bufp->fullIData(oldp+108272,((0x1fffffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                  << 0x13U) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0xdU)))),29);
    bufp->fullCData(oldp+108273,((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                           >> 0xaU))),8);
    bufp->fullQData(oldp+108274,((((QData)((IData)(
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                                   << 0x2eU) | (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                                                 << 0xeU) 
                                                | ((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                                   >> 0x12U)))),64);
    bufp->fullBit(oldp+108276,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                                      >> 0x12U))));
    bufp->fullBit(oldp+108277,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full)))));
    bufp->fullBit(oldp+108278,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value));
    bufp->fullBit(oldp+108279,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value));
    bufp->fullBit(oldp+108280,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__maybe_full));
    bufp->fullBit(oldp+108281,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ptr_match));
    bufp->fullBit(oldp+108282,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty));
    bufp->fullBit(oldp+108283,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full));
    bufp->fullBit(oldp+108284,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_enq));
    bufp->fullBit(oldp+108285,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_deq));
    __Vtemp_hb40f5a47__0[0U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT___inDes_io_out_bits_data) 
                                 << 0xeU) | ((0x2000U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_0 
                                                 << 0xcU)) 
                                             | ((0x1000U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_0 
                                                    << 0xaU)) 
                                                | ((0xf00U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                       >> 2U)) 
                                                   | ((0xe0U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                          >> 9U)) 
                                                      | ((0x18U 
                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                             >> 0xfU)) 
                                                         | (7U 
                                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                               >> 0x15U))))))));
    __Vtemp_hb40f5a47__0[1U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT___inDes_io_out_bits_data) 
                                 >> 0x12U) | ((IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT___inDes_io_out_bits_data 
                                                       >> 0x20U)) 
                                              << 0xeU));
    __Vtemp_hb40f5a47__0[2U] = ((0x4000U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_0 
                                            << 5U)) 
                                | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT___inDes_io_out_bits_data 
                                            >> 0x20U)) 
                                   >> 0x12U));
    bufp->fullWData(oldp+108286,(__Vtemp_hb40f5a47__0),79);
    bufp->fullWData(oldp+108289,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data),79);
    bufp->fullWData(oldp+108292,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[0]),79);
    bufp->fullWData(oldp+108295,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[1]),79);
    bufp->fullCData(oldp+108298,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__a_first_counter),3);
    bufp->fullCData(oldp+108299,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__opcode),3);
    bufp->fullCData(oldp+108300,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__param),3);
    bufp->fullCData(oldp+108301,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__size),3);
    bufp->fullCData(oldp+108302,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__source),4);
    bufp->fullIData(oldp+108303,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__address),29);
    bufp->fullCData(oldp+108304,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__d_first_counter),3);
    bufp->fullCData(oldp+108305,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__opcode_1),3);
    bufp->fullCData(oldp+108306,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__param_1),2);
    bufp->fullCData(oldp+108307,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__size_1),3);
    bufp->fullCData(oldp+108308,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__source_1),4);
    bufp->fullBit(oldp+108309,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__sink));
    bufp->fullBit(oldp+108310,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__denied));
    bufp->fullSData(oldp+108311,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__inflight),10);
    bufp->fullQData(oldp+108312,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__inflight_opcodes),40);
    bufp->fullQData(oldp+108314,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__inflight_sizes),40);
    bufp->fullCData(oldp+108316,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__a_first_counter_1),3);
    bufp->fullBit(oldp+108317,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__a_first_counter_1))));
    bufp->fullCData(oldp+108318,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__d_first_counter_1),3);
    bufp->fullBit(oldp+108319,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__d_first_counter_1))));
    bufp->fullIData(oldp+108320,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__watchdog),32);
    bufp->fullCData(oldp+108321,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__d_first_counter_2),3);
    bufp->fullBit(oldp+108322,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__d_first_counter_2))));
    bufp->fullBit(oldp+108323,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__mask_acc));
    bufp->fullBit(oldp+108324,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__mask_acc_1));
    bufp->fullBit(oldp+108325,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__mask_eq_2));
    bufp->fullBit(oldp+108326,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__mask_acc_2));
    bufp->fullBit(oldp+108327,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__mask_eq_3));
    bufp->fullBit(oldp+108328,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__mask_acc_3));
    bufp->fullBit(oldp+108329,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__mask_eq_4));
    bufp->fullBit(oldp+108330,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__mask_acc_4));
    bufp->fullBit(oldp+108331,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__mask_eq_5));
    bufp->fullBit(oldp+108332,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__mask_acc_5));
    bufp->fullCData(oldp+108333,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__mask_acc_5) 
                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__mask_eq_5) 
                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                   << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__mask_acc_5) 
                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__mask_eq_5) 
                                                  & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))) 
                                              << 6U) 
                                             | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__mask_acc_4) 
                                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__mask_eq_4) 
                                                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                                 << 5U) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__mask_acc_4) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__mask_eq_4) 
                                                        & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))) 
                                                    << 4U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__mask_acc_3) 
                                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__mask_eq_3) 
                                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                                       << 3U) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__mask_acc_3) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__mask_eq_3) 
                                                              & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))) 
                                                          << 2U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__mask_acc_2) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__mask_eq_2) 
                                                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address)) 
                                                             << 1U) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__mask_acc_2) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__mask_eq_2) 
                                                                  & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))))))))))),8);
    bufp->fullSData(oldp+108334,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT___same_cycle_resp_T_1)
                                   ? ((0xfU >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source))
                                       ? (0x3ffU & 
                                          ((IData)(1U) 
                                           << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source)))
                                       : 0U) : 0U)),10);
    bufp->fullBit(oldp+108335,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__same_cycle_resp));
    bufp->fullBit(oldp+108336,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value));
    bufp->fullBit(oldp+108337,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT__deq_ptr_value));
    bufp->fullBit(oldp+108338,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT__maybe_full));
    bufp->fullBit(oldp+108339,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT__ptr_match));
    bufp->fullBit(oldp+108340,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT__empty));
    bufp->fullBit(oldp+108341,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT__full));
    bufp->fullBit(oldp+108342,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT__do_enq));
    bufp->fullBit(oldp+108343,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT__do_deq));
    __Vtemp_h609d58e5__0[0U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_mask)) 
                                         << 0x2aU) 
                                        | (((QData)((IData)(
                                                            (0x1fffffffU 
                                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))) 
                                            << 0xdU) 
                                           | (QData)((IData)(
                                                             (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source) 
                                                               << 9U) 
                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size) 
                                                                  << 6U) 
                                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_param) 
                                                                     << 3U) 
                                                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode)))))))));
    __Vtemp_h609d58e5__0[1U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_data) 
                                 << 0x12U) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_mask)) 
                                                        << 0x2aU) 
                                                       | (((QData)((IData)(
                                                                           (0x1fffffffU 
                                                                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address))) 
                                                           << 0xdU) 
                                                          | (QData)((IData)(
                                                                            (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source) 
                                                                              << 9U) 
                                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_param) 
                                                                                << 3U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode)))))))) 
                                                      >> 0x20U)));
    __Vtemp_h609d58e5__0[2U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_data) 
                                 >> 0xeU) | ((IData)(
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_data 
                                                      >> 0x20U)) 
                                             << 0x12U));
    __Vtemp_h609d58e5__0[3U] = ((0xfffc0000U & ((0xfffc0000U 
                                                 & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_0) 
                                                     << 0x12U) 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[3U] 
                                                       << 6U))) 
                                                | (0x3ffc0000U 
                                                   & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1) 
                                                       << 0x12U) 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[3U] 
                                                         >> 2U))))) 
                                | ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_data 
                                            >> 0x20U)) 
                                   >> 0xeU));
    bufp->fullWData(oldp+108344,(__Vtemp_h609d58e5__0),115);
    bufp->fullWData(oldp+108348,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data),115);
    bufp->fullWData(oldp+108352,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[0]),115);
    bufp->fullWData(oldp+108356,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[1]),115);
    bufp->fullSData(oldp+108360,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__merged_bits_last_counter_1),9);
    bufp->fullSData(oldp+108361,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__merged_bits_last_counter_4),9);
    bufp->fullBit(oldp+108362,(((4U != (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                              >> 0x18U))) 
                                & ((3U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                 >> 0x18U)))
                                    ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full))
                                    : ((IData)(((0U 
                                                 == 
                                                 (0x7000000U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3)) 
                                                & (~ 
                                                   ((2U 
                                                     == 
                                                     (7U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                         >> 0x18U))) 
                                                    | (1U 
                                                       == 
                                                       (7U 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                                           >> 0x18U))))))) 
                                       & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__full)))))));
    bufp->fullBit(oldp+108363,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__receiving)))));
    bufp->fullCData(oldp+108364,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                        >> 0x18U))),3);
    bufp->fullIData(oldp+108365,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_0),32);
    bufp->fullIData(oldp+108366,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_1),32);
    bufp->fullIData(oldp+108367,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_2),32);
    bufp->fullIData(oldp+108368,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3),32);
    bufp->fullCData(oldp+108369,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__recvCount),2);
    bufp->fullCData(oldp+108370,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__a_first_counter),3);
    bufp->fullCData(oldp+108371,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__opcode),3);
    bufp->fullCData(oldp+108372,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__param),3);
    bufp->fullCData(oldp+108373,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__size),3);
    bufp->fullCData(oldp+108374,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__source),4);
    bufp->fullIData(oldp+108375,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__address),29);
    bufp->fullCData(oldp+108376,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__d_first_counter),3);
    bufp->fullCData(oldp+108377,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__opcode_1),3);
    bufp->fullCData(oldp+108378,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__param_1),2);
    bufp->fullCData(oldp+108379,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__size_1),3);
    bufp->fullCData(oldp+108380,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__source_1),4);
    bufp->fullBit(oldp+108381,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__sink));
    bufp->fullBit(oldp+108382,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__denied));
    bufp->fullSData(oldp+108383,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__inflight),10);
    bufp->fullQData(oldp+108384,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__inflight_opcodes),40);
    bufp->fullQData(oldp+108386,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__inflight_sizes),40);
    bufp->fullCData(oldp+108388,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__a_first_counter_1),3);
    bufp->fullBit(oldp+108389,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__a_first_counter_1))));
    bufp->fullCData(oldp+108390,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__d_first_counter_1),3);
    bufp->fullBit(oldp+108391,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__d_first_counter_1))));
    bufp->fullBit(oldp+108392,((6U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                             >> 0x15U)))));
    bufp->fullIData(oldp+108393,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__watchdog),32);
    bufp->fullCData(oldp+108394,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__d_first_counter_2),3);
    bufp->fullBit(oldp+108395,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__d_first_counter_2))));
    bufp->fullBit(oldp+108396,((2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 6U)))));
    bufp->fullBit(oldp+108397,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__mask_acc));
    bufp->fullBit(oldp+108398,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__mask_acc_1));
    bufp->fullBit(oldp+108399,((1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 6U)))));
    bufp->fullBit(oldp+108400,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__mask_eq_2));
    bufp->fullBit(oldp+108401,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__mask_acc_2));
    bufp->fullBit(oldp+108402,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__mask_eq_3));
    bufp->fullBit(oldp+108403,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__mask_acc_3));
    bufp->fullBit(oldp+108404,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__mask_eq_4));
    bufp->fullBit(oldp+108405,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__mask_acc_4));
    bufp->fullBit(oldp+108406,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__mask_eq_5));
    bufp->fullBit(oldp+108407,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__mask_acc_5));
    bufp->fullCData(oldp+108408,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__mask_acc_5) 
                                    << 7U) | (0x3ffff80U 
                                              & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__mask_eq_5) 
                                                  << 7U) 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 6U)))) 
                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__mask_acc_5) 
                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__mask_eq_5) 
                                          & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 0xdU)))) 
                                      << 6U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__mask_acc_4) 
                                                  << 5U) 
                                                 | (0xffffe0U 
                                                    & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__mask_eq_4) 
                                                        << 5U) 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 8U)))) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__mask_acc_4) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__mask_eq_4) 
                                                        & (~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                            >> 0xdU)))) 
                                                    << 4U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__mask_acc_3) 
                                                        << 3U) 
                                                       | (0x3ffff8U 
                                                          & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__mask_eq_3) 
                                                              << 3U) 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                >> 0xaU)))) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__mask_acc_3) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__mask_eq_3) 
                                                              & (~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                  >> 0xdU)))) 
                                                          << 2U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__mask_acc_2) 
                                                              << 1U) 
                                                             | (0xffffeU 
                                                                & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__mask_eq_2) 
                                                                    << 1U) 
                                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                      >> 0xcU)))) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__mask_acc_2) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__mask_eq_2) 
                                                                  & (~ 
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                      >> 0xdU)))))))))))),8);
    bufp->fullBit(oldp+108409,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__same_cycle_resp));
    bufp->fullCData(oldp+108410,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                        >> 3U))),3);
    bufp->fullCData(oldp+108411,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                        >> 9U))),4);
    bufp->fullCData(oldp+108412,(((0xeU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                           >> 9U)) 
                                  | (1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                           >> 0xdU)))),8);
    bufp->fullBit(oldp+108413,(((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__merged_bits_last_counter_1)) 
                                | (0U == ((1U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])
                                           ? (0x1ffU 
                                              & (~ 
                                                 (0xffffffU 
                                                  & (((IData)(0xfffU) 
                                                      << 
                                                      (0xfU 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                          >> 5U))) 
                                                     >> 3U))))
                                           : 0U)))));
    bufp->fullCData(oldp+108414,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                        >> 6U))),4);
    bufp->fullIData(oldp+108415,((0x1fffffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                  << 0x13U) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0xdU)))),32);
    bufp->fullBit(oldp+108416,(((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__merged_bits_last_counter_4)) 
                                | (0U == ((4U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])
                                           ? 0U : (0x1ffU 
                                                   & (~ 
                                                      (0xffffU 
                                                       & (((IData)(0xfffU) 
                                                           << 
                                                           (7U 
                                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                               >> 6U))) 
                                                          >> 3U)))))))));
    bufp->fullBit(oldp+108417,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__sending)))));
    bufp->fullBit(oldp+108418,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT___io_out_valid_output));
    bufp->fullCData(oldp+108419,(((0x17U >= (0x1fU 
                                             & ((IData)(3U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT__chosen))))
                                   ? (7U & (0x92029cU 
                                            >> (0x1fU 
                                                & ((IData)(3U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT__chosen)))))
                                   : 0U)),3);
    bufp->fullCData(oldp+108420,(((0x17U >= (0x1fU 
                                             & ((IData)(3U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT__chosen))))
                                   ? (7U & (((0x7000U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                 << 0xcU)) 
                                             | (0x38U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                   << 3U))) 
                                            >> (0x1fU 
                                                & ((IData)(3U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT__chosen)))))
                                   : 0U)),3);
    bufp->fullCData(oldp+108421,(((0x17U >= (0x1fU 
                                             & ((IData)(3U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT__chosen))))
                                   ? (7U & (((0x7000U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                 << 9U)) 
                                             | (0x18U 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                            >> (0x1fU 
                                                & ((IData)(3U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT__chosen)))))
                                   : 0U)),3);
    bufp->fullCData(oldp+108422,((0xfU & (((0x70000U 
                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                               << 0xaU)) 
                                           | (0xf0U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                 >> 1U))) 
                                          >> (0x1fU 
                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT__chosen) 
                                                 << 2U))))),4);
    bufp->fullCData(oldp+108423,((0xfU & (((0xf0000U 
                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                               << 7U)) 
                                           | (0x10U 
                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                 >> 5U))) 
                                          >> (0x1fU 
                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT__chosen) 
                                                 << 2U))))),4);
    VL_EXTEND_WI(128,29, __Vtemp_hdd2fea63__0, (0x1fffffffU 
                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                    << 0x13U) 
                                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 0xdU))));
    __Vtemp_hd2f4e267__0[0U] = 0U;
    __Vtemp_hd2f4e267__0[1U] = 0U;
    __Vtemp_hd2f4e267__0[2U] = 0U;
    __Vtemp_hd2f4e267__0[3U] = 0U;
    __Vtemp_hd2f4e267__0[4U] = __Vtemp_hdd2fea63__0[0U];
    __Vtemp_hd2f4e267__0[5U] = __Vtemp_hdd2fea63__0[1U];
    __Vtemp_hd2f4e267__0[6U] = __Vtemp_hdd2fea63__0[2U];
    __Vtemp_hd2f4e267__0[7U] = __Vtemp_hdd2fea63__0[3U];
    bufp->fullIData(oldp+108424,((((0U == (0x1fU & 
                                           ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT__chosen) 
                                            << 5U)))
                                    ? 0U : (__Vtemp_hd2f4e267__0[
                                            (((IData)(0x1fU) 
                                              + (0xffU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT__chosen) 
                                                    << 5U))) 
                                             >> 5U)] 
                                            << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT__chosen) 
                                                      << 5U))))) 
                                  | (__Vtemp_hd2f4e267__0[
                                     (7U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT__chosen))] 
                                     >> (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT__chosen) 
                                                  << 5U))))),32);
    VL_EXTEND_WQ(256,64, __Vtemp_hc0264752__0, (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                                                 << 0x2eU) 
                                                | (((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                                                    << 0xeU) 
                                                   | ((QData)((IData)(
                                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                                      >> 0x12U))));
    __Vtemp_he1409196__0[0U] = 0U;
    __Vtemp_he1409196__0[1U] = 0U;
    __Vtemp_he1409196__0[2U] = (IData)((((QData)((IData)(
                                                         vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                         << 0x32U) 
                                        | (((QData)((IData)(
                                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                            << 0x12U) 
                                           | ((QData)((IData)(
                                                              vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                              >> 0xeU))));
    __Vtemp_he1409196__0[3U] = (IData)(((((QData)((IData)(
                                                          vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                          << 0x32U) 
                                         | (((QData)((IData)(
                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                             << 0x12U) 
                                            | ((QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                               >> 0xeU))) 
                                        >> 0x20U));
    __Vtemp_he1409196__0[4U] = 0U;
    __Vtemp_he1409196__0[5U] = 0U;
    __Vtemp_he1409196__0[6U] = 0U;
    __Vtemp_he1409196__0[7U] = 0U;
    __Vtemp_he1409196__0[8U] = __Vtemp_hc0264752__0[0U];
    __Vtemp_he1409196__0[9U] = __Vtemp_hc0264752__0[1U];
    __Vtemp_he1409196__0[0xaU] = __Vtemp_hc0264752__0[2U];
    __Vtemp_he1409196__0[0xbU] = __Vtemp_hc0264752__0[3U];
    __Vtemp_he1409196__0[0xcU] = __Vtemp_hc0264752__0[4U];
    __Vtemp_he1409196__0[0xdU] = __Vtemp_hc0264752__0[5U];
    __Vtemp_he1409196__0[0xeU] = __Vtemp_hc0264752__0[6U];
    __Vtemp_he1409196__0[0xfU] = __Vtemp_hc0264752__0[7U];
    bufp->fullQData(oldp+108425,((((QData)((IData)(
                                                   __Vtemp_he1409196__0[
                                                   (((IData)(0x3fU) 
                                                     + 
                                                     (0x1ffU 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT__chosen) 
                                                         << 6U))) 
                                                    >> 5U)])) 
                                   << ((0U == (0x1fU 
                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT__chosen) 
                                                  << 6U)))
                                        ? 0x20U : ((IData)(0x40U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT__chosen) 
                                                       << 6U))))) 
                                  | (((0U == (0x1fU 
                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT__chosen) 
                                                 << 6U)))
                                       ? 0ULL : ((QData)((IData)(
                                                                 __Vtemp_he1409196__0[
                                                                 (((IData)(0x1fU) 
                                                                   + 
                                                                   (0x1ffU 
                                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT__chosen) 
                                                                       << 6U))) 
                                                                  >> 5U)])) 
                                                 << 
                                                 ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT__chosen) 
                                                      << 6U))))) 
                                     | ((QData)((IData)(
                                                        __Vtemp_he1409196__0[
                                                        (0xeU 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT__chosen) 
                                                            << 1U))])) 
                                        >> (0x1fU & 
                                            ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT__chosen) 
                                             << 6U)))))),64);
    bufp->fullBit(oldp+108427,((1U & (((0x10U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                                                 >> 0xeU)) 
                                       | (2U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                                >> 0xdU))) 
                                      >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT__chosen)))));
    bufp->fullCData(oldp+108428,((0xffU & (IData)((
                                                   ((QData)((IData)(
                                                                    ((0xff000000U 
                                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                                         << 0xeU)) 
                                                                     | ((0xeU 
                                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                            >> 9U)) 
                                                                        | (1U 
                                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                              >> 0xdU)))))) 
                                                    << 8U) 
                                                   >> 
                                                   (0x3fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT__chosen) 
                                                       << 3U)))))),8);
    bufp->fullBit(oldp+108429,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT___io_out_bits_last_output));
    bufp->fullCData(oldp+108430,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT__lockIdx),3);
    bufp->fullBit(oldp+108431,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT__locked));
    bufp->fullCData(oldp+108432,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outArb__DOT__chosen),3);
    bufp->fullWData(oldp+108433,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data),123);
    bufp->fullCData(oldp+108437,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__sendCount),2);
    bufp->fullSData(oldp+108438,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__div),16);
    bufp->fullBit(oldp+108439,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txen));
    bufp->fullBit(oldp+108440,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxen));
    bufp->fullSData(oldp+108441,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txwm),9);
    bufp->fullSData(oldp+108442,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxwm),9);
    bufp->fullBit(oldp+108443,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__nstop));
    bufp->fullWData(oldp+108444,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__inflight),1040);
    bufp->fullWData(oldp+108477,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__inflight_opcodes),4160);
    bufp->fullWData(oldp+108607,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__inflight_sizes),4160);
    bufp->fullIData(oldp+108737,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__monitor__DOT__watchdog),32);
    bufp->fullBit(oldp+108738,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxm__DOT__valid));
    bufp->fullCData(oldp+108739,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxm__DOT__shifter),8);
    bufp->fullCData(oldp+108740,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxm__DOT__debounce),2);
    bufp->fullSData(oldp+108741,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxm__DOT__prescaler),13);
    bufp->fullCData(oldp+108742,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxm__DOT__data_count),4);
    bufp->fullCData(oldp+108743,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxm__DOT__sample_count),4);
    bufp->fullCData(oldp+108744,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxm__DOT__sample),3);
    bufp->fullBit(oldp+108745,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxm__DOT__state));
    bufp->fullBit(oldp+108746,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxm__DOT__prescaler))));
    bufp->fullBit(oldp+108747,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxm__DOT__data_count))));
    bufp->fullBit(oldp+108748,((7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxm__DOT__sample_count))));
    bufp->fullBit(oldp+108749,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxq__DOT__full)))));
    bufp->fullBit(oldp+108750,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxq__DOT__empty)))));
    bufp->fullCData(oldp+108751,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxq__DOT__ram_ext__DOT__Memory
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxq__DOT__deq_ptr_value]),8);
    bufp->fullSData(oldp+108752,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxq__DOT__full) 
                                   << 8U) | (0xffU 
                                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxq__DOT__enq_ptr_value) 
                                                - (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxq__DOT__deq_ptr_value))))),9);
    bufp->fullCData(oldp+108753,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxq__DOT__enq_ptr_value),8);
    bufp->fullCData(oldp+108754,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxq__DOT__deq_ptr_value),8);
    bufp->fullBit(oldp+108755,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxq__DOT__maybe_full));
    bufp->fullBit(oldp+108756,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxq__DOT__ptr_match));
    bufp->fullBit(oldp+108757,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxq__DOT__empty));
    bufp->fullBit(oldp+108758,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxq__DOT__full));
    bufp->fullBit(oldp+108759,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxq__DOT__do_enq));
    bufp->fullBit(oldp+108760,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txq__DOT__empty)))));
    bufp->fullCData(oldp+108761,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txq__DOT__ram_ext__DOT__Memory
                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txq__DOT__deq_ptr_value]),8);
    bufp->fullBit(oldp+108762,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txm__DOT___io_in_ready_output));
    bufp->fullSData(oldp+108763,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txm__DOT__prescaler),16);
    bufp->fullCData(oldp+108764,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txm__DOT__counter),4);
    bufp->fullSData(oldp+108765,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txm__DOT__shifter),9);
    bufp->fullBit(oldp+108766,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txm__DOT__prescaler))));
    bufp->fullBit(oldp+108767,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txq__DOT__full)))));
    bufp->fullSData(oldp+108768,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txq__DOT__full) 
                                   << 8U) | (0xffU 
                                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txq__DOT__enq_ptr_value) 
                                                - (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txq__DOT__deq_ptr_value))))),9);
    bufp->fullCData(oldp+108769,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txq__DOT__enq_ptr_value),8);
    bufp->fullCData(oldp+108770,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txq__DOT__deq_ptr_value),8);
    bufp->fullBit(oldp+108771,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txq__DOT__maybe_full));
    bufp->fullBit(oldp+108772,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txq__DOT__ptr_match));
    bufp->fullBit(oldp+108773,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txq__DOT__empty));
    bufp->fullBit(oldp+108774,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txq__DOT__full));
    bufp->fullBit(oldp+108775,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txq__DOT__do_deq));
    bufp->fullBit(oldp+108776,(vlSelf->TestHarness__DOT__simdram__DOT__initialized));
    bufp->fullQData(oldp+108777,(vlSelf->TestHarness__DOT__simdram__DOT__channel),64);
    bufp->fullQData(oldp+108779,((((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_0)
                                        ? (((QData)((IData)(
                                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                                            << 0x2dU) 
                                           | (((QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                                               << 0xdU) 
                                              | ((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                                 >> 0x13U)))
                                        : 0ULL) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_1)
                                                    ? 
                                                   (((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                                                     << 0x2aU) 
                                                    | (((QData)((IData)(
                                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                                                        << 0xaU) 
                                                       | ((QData)((IData)(
                                                                          vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                                          >> 0x16U)))
                                                    : 0ULL)) 
                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2)
                                         ? (((QData)((IData)(
                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) 
                                             << 0x3fU) 
                                            | (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                                  >> 1U)))
                                         : 0ULL)) | 
                                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_3)
                                      ? (((QData)((IData)(
                                                          vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) 
                                          << 0x3fU) 
                                         | (((QData)((IData)(
                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U])) 
                                             << 0x1fU) 
                                            | ((QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                               >> 1U)))
                                      : 0ULL)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_4)
                                                   ? 
                                                  (((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) 
                                                    << 0x3fU) 
                                                   | (((QData)((IData)(
                                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U])) 
                                                       << 0x1fU) 
                                                      | ((QData)((IData)(
                                                                         vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                                         >> 1U)))
                                                   : 0ULL)) 
                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_5)
                                      ? (((QData)((IData)(
                                                          vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) 
                                          << 0x3fU) 
                                         | (((QData)((IData)(
                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U])) 
                                             << 0x1fU) 
                                            | ((QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                               >> 1U)))
                                      : 0ULL))),64);
    bufp->fullBit(oldp+108781,((((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_0) 
                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                                        >> 0x13U)) 
                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_1) 
                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                                          >> 0x16U))) 
                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2) 
                                      & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_3) 
                                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_4) 
                                    & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_5) 
                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]))));
    bufp->fullBit(oldp+108782,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__muxStateEarly_0) 
                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_a_0_bits_corrupt) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_d_0_corrupt))) 
                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__muxStateEarly_1) 
                                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___in_xbar_auto_out_a_bits_corrupt)))));
    bufp->fullBit(oldp+108783,(((2U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_s_0_state)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__out_1_earlyValid))));
    __Vtemp_had263a02__0[0U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_out_a_bits_mask)) 
                                         << 0x30U) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_out_a_bits_address)) 
                                            << 0x11U) 
                                           | (QData)((IData)(
                                                             (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_out_a_bits_source) 
                                                               << 0xaU) 
                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_out_a_bits_size) 
                                                                  << 6U) 
                                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_out_a_bits_param) 
                                                                     << 3U) 
                                                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_out_a_bits_opcode)))))))));
    __Vtemp_had263a02__0[1U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_out_a_bits_data) 
                                 << 0x18U) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_out_a_bits_mask)) 
                                                        << 0x30U) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_out_a_bits_address)) 
                                                           << 0x11U) 
                                                          | (QData)((IData)(
                                                                            (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_out_a_bits_source) 
                                                                              << 0xaU) 
                                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_out_a_bits_size) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_out_a_bits_param) 
                                                                                << 3U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_out_a_bits_opcode)))))))) 
                                                      >> 0x20U)));
    __Vtemp_had263a02__0[2U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_out_a_bits_data) 
                                 >> 8U) | ((IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_out_a_bits_data 
                                                    >> 0x20U)) 
                                           << 0x18U));
    __Vtemp_had263a02__0[3U] = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__muxStateEarly_0) 
                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_a_0_bits_corrupt) 
                                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_d_0_corrupt))) 
                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__muxStateEarly_1) 
                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___in_xbar_auto_out_a_bits_corrupt))) 
                                 << 0x18U) | ((IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_out_a_bits_data 
                                                       >> 0x20U)) 
                                              >> 8U));
    bufp->fullWData(oldp+108784,(__Vtemp_had263a02__0),121);
    bufp->fullBit(oldp+108788,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__readys_readys) 
                                 >> 1U) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__x1_2_a_valid))));
    bufp->fullBit(oldp+108789,((((((IData)(((0U == 
                                             (0x30U 
                                              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))) 
                                            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__bundleIn_0_b_q__DOT__full)))) 
                                   | (IData)(((0x1cU 
                                               == (0x3cU 
                                                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))) 
                                              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT___io_enq_ready_output)))) 
                                  | (IData)(((0x18U 
                                              == (0x3cU 
                                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))) 
                                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_b_source__DOT___io_enq_ready_output)))) 
                                 | (IData)(((0x14U 
                                             == (0x3cU 
                                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))) 
                                            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_b_source__DOT___io_enq_ready_output)))) 
                                | (IData)(((0x10U == 
                                            (0x3cU 
                                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))) 
                                           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_b_source__DOT___io_enq_ready_output))))));
    bufp->fullQData(oldp+108790,(((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_0)
                                       ? (((QData)((IData)(
                                                           vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_c_q__DOT___ram_ext_R0_data[3U])) 
                                           << 0x32U) 
                                          | (((QData)((IData)(
                                                              vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_c_q__DOT___ram_ext_R0_data[2U])) 
                                              << 0x12U) 
                                             | ((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_c_q__DOT___ram_ext_R0_data[1U])) 
                                                >> 0xeU)))
                                       : 0ULL) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_1)
                                                   ? 
                                                  (((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) 
                                                    << 0x3fU) 
                                                   | (((QData)((IData)(
                                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U])) 
                                                       << 0x1fU) 
                                                      | ((QData)((IData)(
                                                                         vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                                         >> 1U)))
                                                   : 0ULL)) 
                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_2)
                                        ? (((QData)((IData)(
                                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) 
                                            << 0x3fU) 
                                           | (((QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U])) 
                                               << 0x1fU) 
                                              | ((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                                 >> 1U)))
                                        : 0ULL)) | 
                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_3)
                                     ? (((QData)((IData)(
                                                         vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) 
                                         << 0x3fU) 
                                        | (((QData)((IData)(
                                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U])) 
                                            << 0x1fU) 
                                           | ((QData)((IData)(
                                                              vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                              >> 1U)))
                                     : 0ULL)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_4)
                                                  ? 
                                                 (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) 
                                                   << 0x3fU) 
                                                  | (((QData)((IData)(
                                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U])) 
                                                      << 0x1fU) 
                                                     | ((QData)((IData)(
                                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                                        >> 1U)))
                                                  : 0ULL))),64);
    bufp->fullBit(oldp+108792,(((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_0) 
                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_c_q__DOT___ram_ext_R0_data[3U] 
                                       >> 0xeU)) | 
                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_1) 
                                    & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_2) 
                                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_3) 
                                    & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_4) 
                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]))));
    bufp->fullQData(oldp+108793,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__maybe_full)
                                   ? (((QData)((IData)(
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                                       [0U][3U])) 
                                       << 0x29U) | 
                                      (((QData)((IData)(
                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                                        [0U][2U])) 
                                        << 9U) | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                                                  [0U][1U])) 
                                                  >> 0x17U)))
                                   : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_data)),64);
    bufp->fullBit(oldp+108795,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__maybe_full)
                                       ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                          [0U][3U] 
                                          >> 0x17U)
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_corrupt)))));
    bufp->fullBit(oldp+108796,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT___same_cycle_resp_T_3) 
                                 & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode)))) 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source) 
                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source)))));
    bufp->fullBit(oldp+108797,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__request_alloc_cases) 
                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__queue) 
                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bypassQueue) 
                                      | (0x1ffffffffULL 
                                         != vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT__used))))));
    bufp->fullBit(oldp+108798,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_24)
                                       ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___sinkC_io_req_valid))
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data)))));
    bufp->fullBit(oldp+108799,((1U & ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___T_25) 
                                          | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bypass_1))) 
                                      & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                 >> 1U))))));
    bufp->fullCData(oldp+108800,((7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_24)
                                         ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_size)
                                         : (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                    >> 0xaU))))),3);
    bufp->fullCData(oldp+108801,((0x3fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_24)
                                            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_offset)
                                            : (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                       >> 0x20U))))),6);
    bufp->fullCData(oldp+108802,((0x3fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_24)
                                            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_put)
                                            : (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                       >> 0x26U))))),6);
    bufp->fullSData(oldp+108803,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___T_25)
                                   ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__request_bits_set)
                                   : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_set))),10);
    bufp->fullBit(oldp+108804,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___T_25)) 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_5) 
                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_tag)))));
    bufp->fullBit(oldp+108805,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_25)
                                       ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___sinkC_io_req_valid))
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data)))));
    bufp->fullBit(oldp+108806,((1U & ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___T_29) 
                                          | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bypass_2))) 
                                      & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                 >> 1U))))));
    bufp->fullCData(oldp+108807,((7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_25)
                                         ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_size)
                                         : (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                    >> 0xaU))))),3);
    bufp->fullCData(oldp+108808,((0x3fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_25)
                                            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_offset)
                                            : (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                       >> 0x20U))))),6);
    bufp->fullCData(oldp+108809,((0x3fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_25)
                                            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_put)
                                            : (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                       >> 0x26U))))),6);
    bufp->fullSData(oldp+108810,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___T_29)
                                   ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__request_bits_set)
                                   : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__request_set))),10);
    bufp->fullBit(oldp+108811,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___T_29)) 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_4) 
                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__request_tag)))));
    bufp->fullBit(oldp+108812,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_26)
                                       ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___sinkC_io_req_valid))
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data)))));
    bufp->fullBit(oldp+108813,((1U & ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___T_33) 
                                          | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bypass_3))) 
                                      & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                 >> 1U))))));
    bufp->fullCData(oldp+108814,((7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_26)
                                         ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_size)
                                         : (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                    >> 0xaU))))),3);
    bufp->fullCData(oldp+108815,((0x3fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_26)
                                            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_offset)
                                            : (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                       >> 0x20U))))),6);
    bufp->fullCData(oldp+108816,((0x3fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_26)
                                            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_put)
                                            : (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                       >> 0x26U))))),6);
    bufp->fullSData(oldp+108817,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___T_33)
                                   ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__request_bits_set)
                                   : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__request_set))),10);
    bufp->fullBit(oldp+108818,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___T_33)) 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_3) 
                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__request_tag)))));
    bufp->fullBit(oldp+108819,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_27)
                                       ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___sinkC_io_req_valid))
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data)))));
    bufp->fullBit(oldp+108820,((1U & ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___T_37) 
                                          | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bypass_4))) 
                                      & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                 >> 1U))))));
    bufp->fullCData(oldp+108821,((7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_27)
                                         ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_size)
                                         : (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                    >> 0xaU))))),3);
    bufp->fullCData(oldp+108822,((0x3fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_27)
                                            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_offset)
                                            : (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                       >> 0x20U))))),6);
    bufp->fullCData(oldp+108823,((0x3fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_27)
                                            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_put)
                                            : (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                       >> 0x26U))))),6);
    bufp->fullSData(oldp+108824,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___T_37)
                                   ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__request_bits_set)
                                   : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__request_set))),10);
    bufp->fullBit(oldp+108825,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___T_37)) 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_2) 
                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__request_tag)))));
    bufp->fullBit(oldp+108826,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_28)
                                       ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___sinkC_io_req_valid))
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data)))));
    bufp->fullBit(oldp+108827,((1U & ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___T_41) 
                                          | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bypass_5))) 
                                      & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                 >> 1U))))));
    bufp->fullCData(oldp+108828,((7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_28)
                                         ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_size)
                                         : (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                    >> 0xaU))))),3);
    bufp->fullCData(oldp+108829,((0x3fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_28)
                                            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_offset)
                                            : (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                       >> 0x20U))))),6);
    bufp->fullCData(oldp+108830,((0x3fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_28)
                                            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_put)
                                            : (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                       >> 0x26U))))),6);
    bufp->fullSData(oldp+108831,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___T_41)
                                   ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__request_bits_set)
                                   : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__request_set))),10);
    bufp->fullBit(oldp+108832,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___T_41)) 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_1) 
                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__request_tag)))));
    bufp->fullBit(oldp+108833,((1U & ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___T_45) 
                                          | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bypass_6))) 
                                      & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                 >> 1U))))));
    bufp->fullCData(oldp+108834,((7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_29)
                                         ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_size)
                                         : (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                    >> 0xaU))))),3);
    bufp->fullCData(oldp+108835,((0x3fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_29)
                                            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_offset)
                                            : (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                       >> 0x20U))))),6);
    bufp->fullCData(oldp+108836,((0x3fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_29)
                                            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_put)
                                            : (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                       >> 0x26U))))),6);
    bufp->fullSData(oldp+108837,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___T_45)
                                   ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__request_bits_set)
                                   : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__request_set))),10);
    bufp->fullBit(oldp+108838,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___T_45)) 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_0) 
                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__request_tag)))));
    bufp->fullCData(oldp+108839,((7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_31)
                                         ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_size)
                                         : (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                    >> 0xaU))))),3);
    bufp->fullCData(oldp+108840,((0x3fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_31)
                                            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_offset)
                                            : (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                       >> 0x20U))))),6);
    bufp->fullCData(oldp+108841,((0x3fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_31)
                                            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_put)
                                            : (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                       >> 0x26U))))),6);
    bufp->fullSData(oldp+108842,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_30)
                                   ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__request_bits_set)
                                   : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__request_set))),10);
    bufp->fullBit(oldp+108843,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_30)) 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN) 
                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__request_tag)))));
    bufp->fullSData(oldp+108844,((0x1fffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_uses_directory_for_lb)
                                              ? (IData)(
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___data_ext_R0_data 
                                                         >> 0x13U))
                                              : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_tag)))),13);
    bufp->fullQData(oldp+108845,((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_put)) 
                                   << 0x26U) | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_offset)) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_tag) 
                                                                    << 0x13U) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_source) 
                                                                       << 0xdU) 
                                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_size) 
                                                                          << 0xaU) 
                                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_param) 
                                                                             << 7U) 
                                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_opcode) 
                                                                                << 4U) 
                                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___mshrs_6_io_allocate_bits_WIRE_control) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___sinkC_io_req_valid) 
                                                                                << 2U) 
                                                                                | (1U 
                                                                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___sinkC_io_req_valid))))))))))))))),44);
    bufp->fullCData(oldp+108847,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT__data_MPORT_en) 
                                    & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___push_valid_T) 
                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___tail_ext_R1_data) 
                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___head_ext_R0_data)))
                                   ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT__data_MPORT_addr)
                                   : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__will_pop)
                                       ? ((0x20U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___head_ext_R0_data))
                                           ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT__next_ext__DOT__Memory
                                          [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___head_ext_R0_data]
                                           : 0U) : 0U))),6);
    bufp->fullCData(oldp+108848,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__will_pop)
                                   ? ((0x20U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___head_ext_R0_data))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT__next_ext__DOT__Memory
                                      [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT___head_ext_R0_data]
                                       : 0U) : 0U)),6);
    bufp->fullCData(oldp+108849,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__will_pop)
                                   ? ((0x14U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__requests__io_pop_bits))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT__tail_ext__DOT__Memory
                                      [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__requests__io_pop_bits]
                                       : 0U) : 0U)),6);
    bufp->fullBit(oldp+108850,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___sinkA_io_req_ready_T) 
                                 & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___sinkC_io_req_valid))) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkX__DOT__x__DOT__maybe_full)))));
    __Vtemp_hfced7cac__0[0U] = (IData)(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__maybe_full)
                                         ? (((QData)((IData)(
                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                                             [0U][3U])) 
                                             << 0x29U) 
                                            | (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                                                [0U][2U])) 
                                                << 9U) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                                                  [0U][1U])) 
                                                  >> 0x17U)))
                                         : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_data));
    __Vtemp_hfced7cac__0[1U] = (IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__maybe_full)
                                          ? (((QData)((IData)(
                                                              vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                                              [0U][3U])) 
                                              << 0x29U) 
                                             | (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                                                 [0U][2U])) 
                                                 << 9U) 
                                                | ((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                                                   [0U][1U])) 
                                                   >> 0x17U)))
                                          : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_data) 
                                        >> 0x20U));
    __Vtemp_hfced7cac__0[2U] = ((0x100U & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__maybe_full)
                                             ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                                [0U][3U] 
                                                >> 0x17U)
                                             : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_corrupt)) 
                                           << 8U)) 
                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___InclusiveCache_inner_TLBuffer_auto_out_a_bits_mask));
    bufp->fullWData(oldp+108851,(__Vtemp_hfced7cac__0),73);
    bufp->fullBit(oldp+108854,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkA__DOT__putbuffer__DOT__data_MPORT_en) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkA__DOT__putbuffer__DOT___push_valid_T)))));
    bufp->fullCData(oldp+108855,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkA__DOT__putbuffer__DOT__data_MPORT_en) 
                                    & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkA__DOT__putbuffer__DOT___push_valid_T)) 
                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkA__DOT__putbuffer__DOT___tail_ext_R1_data) 
                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkA__DOT__putbuffer__DOT___head_ext_R0_data)))
                                   ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkA__DOT__putbuffer__DOT__data_MPORT_addr)
                                   : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkA__DOT___T_9)
                                       ? ((0x27U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkA__DOT__putbuffer__DOT___head_ext_R0_data))
                                           ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkA__DOT__putbuffer__DOT__next_ext__DOT__Memory
                                          [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkA__DOT__putbuffer__DOT___head_ext_R0_data]
                                           : 0U) : 0U))),6);
    bufp->fullBit(oldp+108856,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkA__DOT__putbuffer__DOT__data_MPORT_en) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkA__DOT__putbuffer__DOT___push_valid_T))));
    __Vtemp_h2114abef__0[1U] = (IData)(((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_0)
                                             ? (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_c_q__DOT___ram_ext_R0_data[3U])) 
                                                 << 0x32U) 
                                                | (((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_c_q__DOT___ram_ext_R0_data[2U])) 
                                                    << 0x12U) 
                                                   | ((QData)((IData)(
                                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_c_q__DOT___ram_ext_R0_data[1U])) 
                                                      >> 0xeU)))
                                             : 0ULL) 
                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_1)
                                               ? (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) 
                                                   << 0x3fU) 
                                                  | (((QData)((IData)(
                                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U])) 
                                                      << 0x1fU) 
                                                     | ((QData)((IData)(
                                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                                        >> 1U)))
                                               : 0ULL)) 
                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_2)
                                              ? (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) 
                                                  << 0x3fU) 
                                                 | (((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U])) 
                                                     << 0x1fU) 
                                                    | ((QData)((IData)(
                                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                                       >> 1U)))
                                              : 0ULL)) 
                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_3)
                                             ? (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) 
                                                 << 0x3fU) 
                                                | (((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U])) 
                                                    << 0x1fU) 
                                                   | ((QData)((IData)(
                                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                                      >> 1U)))
                                             : 0ULL)) 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_4)
                                            ? (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) 
                                                << 0x3fU) 
                                               | (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U])) 
                                                   << 0x1fU) 
                                                  | ((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                                     >> 1U)))
                                            : 0ULL)));
    __Vtemp_h2114abef__0[2U] = (IData)((((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_0)
                                              ? (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_c_q__DOT___ram_ext_R0_data[3U])) 
                                                  << 0x32U) 
                                                 | (((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_c_q__DOT___ram_ext_R0_data[2U])) 
                                                     << 0x12U) 
                                                    | ((QData)((IData)(
                                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_c_q__DOT___ram_ext_R0_data[1U])) 
                                                       >> 0xeU)))
                                              : 0ULL) 
                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_1)
                                                ? (
                                                   ((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) 
                                                    << 0x3fU) 
                                                   | (((QData)((IData)(
                                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U])) 
                                                       << 0x1fU) 
                                                      | ((QData)((IData)(
                                                                         vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                                         >> 1U)))
                                                : 0ULL)) 
                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_2)
                                               ? (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) 
                                                   << 0x3fU) 
                                                  | (((QData)((IData)(
                                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U])) 
                                                      << 0x1fU) 
                                                     | ((QData)((IData)(
                                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                                        >> 1U)))
                                               : 0ULL)) 
                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_3)
                                              ? (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) 
                                                  << 0x3fU) 
                                                 | (((QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U])) 
                                                     << 0x1fU) 
                                                    | ((QData)((IData)(
                                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                                       >> 1U)))
                                              : 0ULL)) 
                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_4)
                                             ? (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) 
                                                 << 0x3fU) 
                                                | (((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U])) 
                                                    << 0x1fU) 
                                                   | ((QData)((IData)(
                                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                                      >> 1U)))
                                             : 0ULL)) 
                                        >> 0x20U));
    __Vtemp_h30fe9863__0[0U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                 << 0xfU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source) 
                                              << 9U) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_size) 
                                                 << 6U) 
                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_param) 
                                                    << 3U) 
                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode)))));
    __Vtemp_h30fe9863__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                 >> 0x11U) | (__Vtemp_h2114abef__0[1U] 
                                              << 0xfU));
    __Vtemp_h30fe9863__0[2U] = ((__Vtemp_h2114abef__0[1U] 
                                 >> 0x11U) | (__Vtemp_h2114abef__0[2U] 
                                              << 0xfU));
    __Vtemp_h30fe9863__0[3U] = ((0xffff8000U & ((((
                                                   (0xffff8000U 
                                                    & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_0) 
                                                        << 0xfU) 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_c_q__DOT___ram_ext_R0_data[3U] 
                                                          << 1U))) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_1) 
                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]) 
                                                      << 0xfU)) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_2) 
                                                      & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]) 
                                                     << 0xfU)) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_3) 
                                                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]) 
                                                    << 0xfU)) 
                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_4) 
                                                    & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]) 
                                                   << 0xfU))) 
                                | (__Vtemp_h2114abef__0[2U] 
                                   >> 0x11U));
    bufp->fullWData(oldp+108857,(__Vtemp_h30fe9863__0),112);
    bufp->fullBit(oldp+108861,((1U & (((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__resp)) 
                                         & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__c__DOT__empty))) 
                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__c__DOT___ram_ext_R0_data[0U]) 
                                       & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__req_block))) 
                                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__set_block))))));
    bufp->fullBit(oldp+108862,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__putbuffer__DOT__data_MPORT_en) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__putbuffer__DOT___push_valid_T)))));
    bufp->fullCData(oldp+108863,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__putbuffer__DOT__data_MPORT_en) 
                                    & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__putbuffer__DOT___push_valid_T)) 
                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__putbuffer__DOT___tail_ext_R1_data) 
                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__putbuffer__DOT___head_ext_R0_data)))
                                   ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__putbuffer__DOT___GEN_6)
                                   : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT___T_25)
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__putbuffer__DOT__next_ext__DOT__Memory
                                      [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__putbuffer__DOT___head_ext_R0_data]
                                       : 0U))),4);
    bufp->fullBit(oldp+108864,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__putbuffer__DOT__data_MPORT_en) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__putbuffer__DOT___push_valid_T))));
    bufp->fullBit(oldp+108865,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___sinkA_io_req_ready_T) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___sinkC_io_req_valid)))));
    bufp->fullBit(oldp+108866,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__monitor__DOT___same_cycle_resp_T_3) 
                                 & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode)))) 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source) 
                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s3_req_source)))));
    bufp->fullCData(oldp+108867,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT___same_cycle_resp_T_1)
                                   ? (7U & ((IData)(1U) 
                                            << (3U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   >> 9U))))
                                   : 0U)),3);
    bufp->fullCData(oldp+108868,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT___same_cycle_resp_T_3) 
                                   & (0x1800U == (0x1800U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U])))
                                   ? (7U & ((IData)(1U) 
                                            << (3U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   >> 1U))))
                                   : 0U)),3);
    bufp->fullBit(oldp+108869,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT___same_cycle_resp_T_3) 
                                 & (0x1800U == (0x1800U 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                                & ((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          >> 1U)) == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source)))));
    bufp->fullCData(oldp+108870,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_3__DOT___same_cycle_resp_T_1)
                                   ? (7U & ((IData)(1U) 
                                            << (3U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   >> 9U))))
                                   : 0U)),3);
    bufp->fullCData(oldp+108871,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_3__DOT___same_cycle_resp_T_3) 
                                   & (0x1800U == (0x1800U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U])))
                                   ? (7U & ((IData)(1U) 
                                            << (3U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   >> 1U))))
                                   : 0U)),3);
    bufp->fullBit(oldp+108872,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_3__DOT___same_cycle_resp_T_3) 
                                 & (0x1800U == (0x1800U 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                                & ((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          >> 1U)) == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_3_d_bits_source)))));
    bufp->fullCData(oldp+108873,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_4__DOT___same_cycle_resp_T_1)
                                   ? (7U & ((IData)(1U) 
                                            << (3U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   >> 9U))))
                                   : 0U)),3);
    bufp->fullCData(oldp+108874,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_4__DOT___same_cycle_resp_T_3) 
                                   & (0x1800U == (0x1800U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U])))
                                   ? (7U & ((IData)(1U) 
                                            << (3U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   >> 1U))))
                                   : 0U)),3);
    bufp->fullBit(oldp+108875,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_4__DOT___same_cycle_resp_T_3) 
                                 & (0x1800U == (0x1800U 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                                & ((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          >> 1U)) == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_4_d_bits_source)))));
    bufp->fullCData(oldp+108876,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_5__DOT___same_cycle_resp_T_1)
                                   ? (7U & ((IData)(1U) 
                                            << (3U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   >> 9U))))
                                   : 0U)),3);
    bufp->fullCData(oldp+108877,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_5__DOT___same_cycle_resp_T_3) 
                                   & (0x1800U == (0x1800U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U])))
                                   ? (7U & ((IData)(1U) 
                                            << (3U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   >> 1U))))
                                   : 0U)),3);
    bufp->fullBit(oldp+108878,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_5__DOT___same_cycle_resp_T_3) 
                                 & (0x1800U == (0x1800U 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                                & ((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          >> 1U)) == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_5_d_bits_source)))));
    bufp->fullBit(oldp+108879,((1U & ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__beatsLeft_1))
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__readys_readys_1) 
                                          >> 5U) : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__state_1_5)))));
    bufp->fullBit(oldp+108880,((1U & ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__beatsLeft_1))
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__readys_readys_1) 
                                          >> 4U) : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__state_1_4)))));
    bufp->fullBit(oldp+108881,((1U & ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__beatsLeft_1))
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__readys_readys_1) 
                                          >> 3U) : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__state_1_3)))));
    bufp->fullBit(oldp+108882,((1U & ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__beatsLeft_1))
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__readys_readys_1) 
                                          >> 2U) : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__state_1_2)))));
    bufp->fullBit(oldp+108883,((1U & ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__beatsLeft_1))
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__readys_readys_1) 
                                          >> 1U) : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__state_1_1)))));
    bufp->fullBit(oldp+108884,((1U & ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__beatsLeft_1))
                                       ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__readys_readys_1)
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__state_1_0)))));
    bufp->fullBit(oldp+108885,((1U & ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__beatsLeft))
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__readys_readys) 
                                          >> 5U) : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__state_5)))));
    bufp->fullBit(oldp+108886,((1U & ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__beatsLeft))
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__readys_readys) 
                                          >> 4U) : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__state_4)))));
    bufp->fullBit(oldp+108887,((1U & ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__beatsLeft))
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__readys_readys) 
                                          >> 3U) : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__state_3)))));
    bufp->fullBit(oldp+108888,((1U & ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__beatsLeft))
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__readys_readys) 
                                          >> 2U) : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__state_2)))));
    bufp->fullBit(oldp+108889,((1U & ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__beatsLeft))
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__readys_readys) 
                                          >> 1U) : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__state_1)))));
    bufp->fullBit(oldp+108890,((1U & ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__beatsLeft))
                                       ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__readys_readys)
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__state_0)))));
    bufp->fullCData(oldp+108891,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_2__DOT___same_cycle_resp_T_1)
                                   ? (7U & ((IData)(1U) 
                                            << (3U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   >> 9U))))
                                   : 0U)),3);
    bufp->fullCData(oldp+108892,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_2__DOT___same_cycle_resp_T_3) 
                                   & (0x1800U == (0x1800U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U])))
                                   ? (7U & ((IData)(1U) 
                                            << (3U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   >> 1U))))
                                   : 0U)),3);
    bufp->fullBit(oldp+108893,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_2__DOT___same_cycle_resp_T_3) 
                                 & (0x1800U == (0x1800U 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                                & ((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          >> 1U)) == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_2_d_bits_source)))));
    bufp->fullCData(oldp+108894,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_3__DOT___same_cycle_resp_T_1)
                                   ? (7U & ((IData)(1U) 
                                            << (3U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   >> 9U))))
                                   : 0U)),3);
    bufp->fullCData(oldp+108895,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_3__DOT___same_cycle_resp_T_3) 
                                   & (0x1800U == (0x1800U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U])))
                                   ? (7U & ((IData)(1U) 
                                            << (3U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   >> 1U))))
                                   : 0U)),3);
    bufp->fullBit(oldp+108896,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_3__DOT___same_cycle_resp_T_3) 
                                 & (0x1800U == (0x1800U 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                                & ((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          >> 1U)) == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_3_d_bits_source)))));
    bufp->fullCData(oldp+108897,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_4__DOT___same_cycle_resp_T_1)
                                   ? (7U & ((IData)(1U) 
                                            << (3U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   >> 9U))))
                                   : 0U)),3);
    bufp->fullCData(oldp+108898,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_4__DOT___same_cycle_resp_T_3) 
                                   & (0x1800U == (0x1800U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U])))
                                   ? (7U & ((IData)(1U) 
                                            << (3U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   >> 1U))))
                                   : 0U)),3);
    bufp->fullBit(oldp+108899,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_4__DOT___same_cycle_resp_T_3) 
                                 & (0x1800U == (0x1800U 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                                & ((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          >> 1U)) == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_4_d_bits_source)))));
    bufp->fullCData(oldp+108900,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_5__DOT___same_cycle_resp_T_1)
                                   ? (7U & ((IData)(1U) 
                                            << (3U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   >> 9U))))
                                   : 0U)),3);
    bufp->fullCData(oldp+108901,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_5__DOT___same_cycle_resp_T_3) 
                                   & (0x1800U == (0x1800U 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U])))
                                   ? (7U & ((IData)(1U) 
                                            << (3U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   >> 1U))))
                                   : 0U)),3);
    bufp->fullBit(oldp+108902,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_5__DOT___same_cycle_resp_T_3) 
                                 & (0x1800U == (0x1800U 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U]))) 
                                & ((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          >> 1U)) == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_5_d_bits_source)))));
    bufp->fullCData(oldp+108903,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__fflags_val_0)
                                     ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_fflags_ext__DOT__Memory
                                    [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_head]
                                     : 0U) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__fflags_val_1)
                                               ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_fflags_1_ext__DOT__Memory
                                              [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_head]
                                               : 0U)) 
                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__fflags_val_2)
                                      ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_fflags_2_ext__DOT__Memory
                                     [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_head]
                                      : 0U))),5);
    bufp->fullBit(oldp+108904,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_ldst_val) 
                                  & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_dst_rtype))) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_0)) 
                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__rbk_valids_0))));
    bufp->fullBit(oldp+108905,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_ldst_val) 
                                  & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_dst_rtype))) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_1)) 
                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__rbk_valids_1))));
    bufp->fullBit(oldp+108906,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_ldst_val) 
                                  & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_dst_rtype))) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_2)) 
                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__rbk_valids_2))));
    __Vtemp_hc961d23f__0[0U] = 1U;
    __Vtemp_hc961d23f__0[1U] = 0U;
    __Vtemp_hc961d23f__0[2U] = 0U;
    __Vtemp_hc961d23f__0[3U] = 0U;
    VL_SHIFTL_WWI(128,128,7, __Vtemp_h525c8084__0, __Vtemp_hc961d23f__0, 
                  ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_state))
                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_pdst)
                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_stale_pdst)));
    __Vtemp_hc961d23f__1[0U] = 1U;
    __Vtemp_hc961d23f__1[1U] = 0U;
    __Vtemp_hc961d23f__1[2U] = 0U;
    __Vtemp_hc961d23f__1[3U] = 0U;
    VL_SHIFTL_WWI(128,128,7, __Vtemp_hddf42d01__0, __Vtemp_hc961d23f__1, 
                  ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_state))
                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_pdst)
                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_stale_pdst)));
    __Vtemp_hc961d23f__2[0U] = 1U;
    __Vtemp_hc961d23f__2[1U] = 0U;
    __Vtemp_hc961d23f__2[2U] = 0U;
    __Vtemp_hc961d23f__2[3U] = 0U;
    VL_SHIFTL_WWI(128,128,7, __Vtemp_h104e453a__0, __Vtemp_hc961d23f__2, 
                  ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_state))
                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_pdst)
                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_stale_pdst)));
    __Vtemp_ha148f9f6__0[0U] = ((((__Vtemp_h525c8084__0[0U] 
                                   & (- (IData)(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_ldst_val) 
                                                   & (1U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_dst_rtype))) 
                                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_0)) 
                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__rbk_valids_0))))) 
                                  | (__Vtemp_hddf42d01__0[0U] 
                                     & (- (IData)((
                                                   (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_ldst_val) 
                                                     & (1U 
                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_dst_rtype))) 
                                                    & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_1)) 
                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__rbk_valids_1)))))) 
                                 | (__Vtemp_h104e453a__0[0U] 
                                    & (- (IData)(((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_ldst_val) 
                                                    & (1U 
                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_dst_rtype))) 
                                                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_2)) 
                                                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__rbk_valids_2)))))) 
                                | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__freelist__DOT__br_deallocs[0U]);
    __Vtemp_ha148f9f6__0[1U] = ((((__Vtemp_h525c8084__0[1U] 
                                   & (- (IData)(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_ldst_val) 
                                                   & (1U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_dst_rtype))) 
                                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_0)) 
                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__rbk_valids_0))))) 
                                  | (__Vtemp_hddf42d01__0[1U] 
                                     & (- (IData)((
                                                   (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_ldst_val) 
                                                     & (1U 
                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_dst_rtype))) 
                                                    & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_1)) 
                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__rbk_valids_1)))))) 
                                 | (__Vtemp_h104e453a__0[1U] 
                                    & (- (IData)(((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_ldst_val) 
                                                    & (1U 
                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_dst_rtype))) 
                                                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_2)) 
                                                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__rbk_valids_2)))))) 
                                | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__freelist__DOT__br_deallocs[1U]);
    __Vtemp_ha148f9f6__0[2U] = ((((__Vtemp_h525c8084__0[2U] 
                                   & (- (IData)(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_ldst_val) 
                                                   & (1U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_dst_rtype))) 
                                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_0)) 
                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__rbk_valids_0))))) 
                                  | (__Vtemp_hddf42d01__0[2U] 
                                     & (- (IData)((
                                                   (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_ldst_val) 
                                                     & (1U 
                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_dst_rtype))) 
                                                    & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_1)) 
                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__rbk_valids_1)))))) 
                                 | (__Vtemp_h104e453a__0[2U] 
                                    & (- (IData)(((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_ldst_val) 
                                                    & (1U 
                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_dst_rtype))) 
                                                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_2)) 
                                                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__rbk_valids_2)))))) 
                                | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__freelist__DOT__br_deallocs[2U]);
    bufp->fullWData(oldp+108907,(__Vtemp_ha148f9f6__0),96);
    bufp->fullBit(oldp+108910,((1U & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_flush_valid_output) 
                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__jmp_pc_req_valid_REG))))));
    bufp->fullBit(oldp+108911,((((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT__fsm_state)) 
                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT___GEN_4) 
                                      << 7U) | ((0x40U 
                                                 & ((((0xffffffc0U 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ghe_io_icctrl_out) 
                                                          << 5U)) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT___fsm_state_T_46) 
                                                         << 6U)) 
                                                     | ((0xf81U 
                                                         < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT___GEN_0)) 
                                                        << 6U)) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT___GEN_2) 
                                                       << 6U))) 
                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ghe_io_if_correct_process) 
                                                    << 5U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ghe_io_if_correct_process) 
                                                       << 4U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ghe_io_if_correct_process) 
                                                          << 3U) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ghe_io_if_correct_process) 
                                                             << 2U) 
                                                            | ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT__fsm_ini)) 
                                                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ghe_io_if_correct_process)) 
                                                                << 1U) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT___GEN_4)))))))) 
                                    >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT__fsm_state))) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ghe_io_if_correct_process))));
    bufp->fullBit(oldp+108912,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_ldst_val) 
                                  & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_dst_rtype))) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_0)) 
                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__rbk_valids_0))));
    bufp->fullBit(oldp+108913,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_ldst_val) 
                                  & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_dst_rtype))) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_1)) 
                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__rbk_valids_1))));
    bufp->fullBit(oldp+108914,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_ldst_val) 
                                  & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_dst_rtype))) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_2)) 
                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__rbk_valids_2))));
    __Vtemp_hc961d23f__3[0U] = 1U;
    __Vtemp_hc961d23f__3[1U] = 0U;
    __Vtemp_hc961d23f__3[2U] = 0U;
    __Vtemp_hc961d23f__3[3U] = 0U;
    VL_SHIFTL_WWI(128,128,7, __Vtemp_h6538aca7__0, __Vtemp_hc961d23f__3, 
                  ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_state))
                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_pdst)
                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_stale_pdst)));
    __Vtemp_hc961d23f__4[0U] = 1U;
    __Vtemp_hc961d23f__4[1U] = 0U;
    __Vtemp_hc961d23f__4[2U] = 0U;
    __Vtemp_hc961d23f__4[3U] = 0U;
    VL_SHIFTL_WWI(128,128,7, __Vtemp_h1c4b2ef6__0, __Vtemp_hc961d23f__4, 
                  ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_state))
                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_pdst)
                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_stale_pdst)));
    __Vtemp_hc961d23f__5[0U] = 1U;
    __Vtemp_hc961d23f__5[1U] = 0U;
    __Vtemp_hc961d23f__5[2U] = 0U;
    __Vtemp_hc961d23f__5[3U] = 0U;
    VL_SHIFTL_WWI(128,128,7, __Vtemp_h1d30006e__0, __Vtemp_hc961d23f__5, 
                  ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_state))
                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_pdst)
                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_stale_pdst)));
    __Vtemp_h155f73d9__0[0U] = ((((__Vtemp_h6538aca7__0[0U] 
                                   & (- (IData)(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_ldst_val) 
                                                   & (0U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_dst_rtype))) 
                                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_0)) 
                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__rbk_valids_0))))) 
                                  | (__Vtemp_h1c4b2ef6__0[0U] 
                                     & (- (IData)((
                                                   (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_ldst_val) 
                                                     & (0U 
                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_dst_rtype))) 
                                                    & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_1)) 
                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__rbk_valids_1)))))) 
                                 | (__Vtemp_h1d30006e__0[0U] 
                                    & (- (IData)(((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_ldst_val) 
                                                    & (0U 
                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_dst_rtype))) 
                                                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_2)) 
                                                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__rbk_valids_2)))))) 
                                | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__freelist__DOT__br_deallocs[0U]);
    __Vtemp_h155f73d9__0[1U] = ((((__Vtemp_h6538aca7__0[1U] 
                                   & (- (IData)(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_ldst_val) 
                                                   & (0U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_dst_rtype))) 
                                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_0)) 
                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__rbk_valids_0))))) 
                                  | (__Vtemp_h1c4b2ef6__0[1U] 
                                     & (- (IData)((
                                                   (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_ldst_val) 
                                                     & (0U 
                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_dst_rtype))) 
                                                    & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_1)) 
                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__rbk_valids_1)))))) 
                                 | (__Vtemp_h1d30006e__0[1U] 
                                    & (- (IData)(((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_ldst_val) 
                                                    & (0U 
                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_dst_rtype))) 
                                                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_2)) 
                                                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__rbk_valids_2)))))) 
                                | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__freelist__DOT__br_deallocs[1U]);
    __Vtemp_h155f73d9__0[2U] = ((((__Vtemp_h6538aca7__0[2U] 
                                   & (- (IData)(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_ldst_val) 
                                                   & (0U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_dst_rtype))) 
                                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_0)) 
                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__rbk_valids_0))))) 
                                  | (__Vtemp_h1c4b2ef6__0[2U] 
                                     & (- (IData)((
                                                   (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_ldst_val) 
                                                     & (0U 
                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_dst_rtype))) 
                                                    & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_1)) 
                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__rbk_valids_1)))))) 
                                 | (__Vtemp_h1d30006e__0[2U] 
                                    & (- (IData)(((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_ldst_val) 
                                                    & (0U 
                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_dst_rtype))) 
                                                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_2)) 
                                                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__rbk_valids_2)))))) 
                                | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__freelist__DOT__br_deallocs[2U]);
    __Vtemp_h155f73d9__0[3U] = (0xfU & ((((__Vtemp_h6538aca7__0[3U] 
                                           & (- (IData)(
                                                        ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_ldst_val) 
                                                           & (0U 
                                                              == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_0_dst_rtype))) 
                                                          & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_0)) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__rbk_valids_0))))) 
                                          | (__Vtemp_h1c4b2ef6__0[3U] 
                                             & (- (IData)(
                                                          ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_ldst_val) 
                                                             & (0U 
                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_1_dst_rtype))) 
                                                            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_1)) 
                                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__rbk_valids_1)))))) 
                                         | (__Vtemp_h1d30006e__0[3U] 
                                            & (- (IData)(
                                                         ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_ldst_val) 
                                                            & (0U 
                                                               == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_uops_2_dst_rtype))) 
                                                           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_2)) 
                                                          | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__rbk_valids_2)))))) 
                                        | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__freelist__DOT__br_deallocs[3U]));
    bufp->fullWData(oldp+108915,(__Vtemp_h155f73d9__0),100);
    bufp->fullQData(oldp+108919,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_0) 
                                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_0_uses_stq_output))
                                   ? ((0x4ffU >= (0x7ffU 
                                                  & ((IData)(0x28U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_0))))
                                       ? (0xffffffffffULL 
                                          & (((QData)((IData)(
                                                              vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_743[
                                                              (((IData)(0x27U) 
                                                                + 
                                                                (0x7ffU 
                                                                 & ((IData)(0x28U) 
                                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_0)))) 
                                                               >> 5U)])) 
                                              << ((0U 
                                                   == 
                                                   (0x1fU 
                                                    & ((IData)(0x28U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_0))))
                                                   ? 0x20U
                                                   : 
                                                  ((IData)(0x40U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x28U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_0)))))) 
                                             | (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(0x28U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_0))))
                                                  ? 0ULL
                                                  : 
                                                 ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_743[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x7ffU 
                                                                     & ((IData)(0x28U) 
                                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_0)))) 
                                                                   >> 5U)])) 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x28U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_0)))))) 
                                                | ((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_743[
                                                                   (0x3fU 
                                                                    & (((IData)(0x28U) 
                                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_0)) 
                                                                       >> 5U))])) 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(0x28U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_0)))))))
                                       : 0ULL) : 0ULL)),64);
    bufp->fullQData(oldp+108921,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_1) 
                                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_1_uses_stq_output))
                                   ? ((0x4ffU >= (0x7ffU 
                                                  & ((IData)(0x28U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_1))))
                                       ? (0xffffffffffULL 
                                          & (((QData)((IData)(
                                                              vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_743[
                                                              (((IData)(0x27U) 
                                                                + 
                                                                (0x7ffU 
                                                                 & ((IData)(0x28U) 
                                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_1)))) 
                                                               >> 5U)])) 
                                              << ((0U 
                                                   == 
                                                   (0x1fU 
                                                    & ((IData)(0x28U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_1))))
                                                   ? 0x20U
                                                   : 
                                                  ((IData)(0x40U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x28U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_1)))))) 
                                             | (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(0x28U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_1))))
                                                  ? 0ULL
                                                  : 
                                                 ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_743[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x7ffU 
                                                                     & ((IData)(0x28U) 
                                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_1)))) 
                                                                   >> 5U)])) 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x28U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_1)))))) 
                                                | ((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_743[
                                                                   (0x3fU 
                                                                    & (((IData)(0x28U) 
                                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_1)) 
                                                                       >> 5U))])) 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(0x28U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_1)))))))
                                       : 0ULL) : 0ULL)),64);
    bufp->fullQData(oldp+108923,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__will_commit_2) 
                                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_2_uses_stq_output))
                                   ? ((0x4ffU >= (0x7ffU 
                                                  & ((IData)(0x28U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_2))))
                                       ? (0xffffffffffULL 
                                          & (((QData)((IData)(
                                                              vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_743[
                                                              (((IData)(0x27U) 
                                                                + 
                                                                (0x7ffU 
                                                                 & ((IData)(0x28U) 
                                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_2)))) 
                                                               >> 5U)])) 
                                              << ((0U 
                                                   == 
                                                   (0x1fU 
                                                    & ((IData)(0x28U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_2))))
                                                   ? 0x20U
                                                   : 
                                                  ((IData)(0x40U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x28U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_2)))))) 
                                             | (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(0x28U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_2))))
                                                  ? 0ULL
                                                  : 
                                                 ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_743[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x7ffU 
                                                                     & ((IData)(0x28U) 
                                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_2)))) 
                                                                   >> 5U)])) 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x28U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_2)))))) 
                                                | ((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_743[
                                                                   (0x3fU 
                                                                    & (((IData)(0x28U) 
                                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_2)) 
                                                                       >> 5U))])) 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(0x28U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__debug_stq_cnt_2)))))))
                                       : 0ULL) : 0ULL)),64);
    bufp->fullBit(oldp+108925,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__exception_thrown)
                                 ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_xcpt_uop_edge_inst)
                                 : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__flush_commit_mask_0) 
                                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_0_edge_inst_output)) 
                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__flush_commit_mask_1) 
                                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_1_edge_inst_output))) 
                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__flush_commit_mask_2) 
                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_2_edge_inst_output))))));
    bufp->fullBit(oldp+108926,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__exception_thrown)
                                 ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_head_vals_0)
                                     ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_0_is_rvc_output)
                                     : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_head_vals_1)
                                         ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_1_is_rvc_output)
                                         : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_2_is_rvc_output)))
                                 : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__flush_commit_mask_0) 
                                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_0_is_rvc_output)) 
                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__flush_commit_mask_1) 
                                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_1_is_rvc_output))) 
                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__flush_commit_mask_2) 
                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_2_is_rvc_output))))));
    bufp->fullCData(oldp+108927,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__exception_thrown)
                                   ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_xcpt_uop_pc_lob)
                                   : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__flush_commit_mask_0)
                                         ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_0_pc_lob_output)
                                         : 0U) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__flush_commit_mask_1)
                                                   ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_1_pc_lob_output)
                                                   : 0U)) 
                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__flush_commit_mask_2)
                                          ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_2_pc_lob_output)
                                          : 0U)))),6);
    bufp->fullCData(oldp+108928,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_flush_valid_output)
                                   ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__flush_commit) 
                                       & (0x6aU == 
                                          ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__exception_thrown)
                                            ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_head_vals_0)
                                                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_0_uopc_output)
                                                : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_head_vals_1)
                                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_1_uopc_output)
                                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_2_uopc_output)))
                                            : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__flush_commit_mask_0)
                                                  ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_0_uopc_output)
                                                  : 0U) 
                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__flush_commit_mask_1)
                                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_1_uopc_output)
                                                    : 0U)) 
                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__flush_commit_mask_2)
                                                   ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___io_commit_uops_2_uopc_output)
                                                   : 0U)))))
                                       ? 3U : (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__exception_thrown) 
                                                & (0x10ULL 
                                                   != vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_exc_cause))
                                                ? 1U
                                                : (
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__exception_thrown) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_head_vals_0) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_head_vals_1)) 
                                                        | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_head_vals_2)) 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_head_vals_0)
                                                           ? 
                                                          ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_31_is_sys_pc2epc) 
                                                             << 0x1fU) 
                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_30_is_sys_pc2epc) 
                                                                << 0x1eU) 
                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_29_is_sys_pc2epc) 
                                                                   << 0x1dU) 
                                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_28_is_sys_pc2epc) 
                                                                      << 0x1cU) 
                                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_27_is_sys_pc2epc) 
                                                                         << 0x1bU) 
                                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_26_is_sys_pc2epc) 
                                                                            << 0x1aU) 
                                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_25_is_sys_pc2epc) 
                                                                               << 0x19U) 
                                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_24_is_sys_pc2epc) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_23_is_sys_pc2epc) 
                                                                                << 0x17U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_22_is_sys_pc2epc) 
                                                                                << 0x16U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_21_is_sys_pc2epc) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_20_is_sys_pc2epc) 
                                                                                << 0x14U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_19_is_sys_pc2epc) 
                                                                                << 0x13U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_18_is_sys_pc2epc) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_17_is_sys_pc2epc) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_16_is_sys_pc2epc) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_15_is_sys_pc2epc) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_14_is_sys_pc2epc) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_13_is_sys_pc2epc) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_12_is_sys_pc2epc) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_11_is_sys_pc2epc) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_10_is_sys_pc2epc) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_9_is_sys_pc2epc) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_8_is_sys_pc2epc) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_7_is_sys_pc2epc) 
                                                                                << 7U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_6_is_sys_pc2epc) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_5_is_sys_pc2epc) 
                                                                                << 5U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_4_is_sys_pc2epc) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_3_is_sys_pc2epc) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_is_sys_pc2epc) 
                                                                                << 2U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_is_sys_pc2epc) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_0_is_sys_pc2epc)))))))))))))))))))))))))))))))) 
                                                           >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))
                                                           : 
                                                          ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_head_vals_1)
                                                            ? 
                                                           ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_31_is_sys_pc2epc) 
                                                              << 0x1fU) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_30_is_sys_pc2epc) 
                                                                 << 0x1eU) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_29_is_sys_pc2epc) 
                                                                    << 0x1dU) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_28_is_sys_pc2epc) 
                                                                       << 0x1cU) 
                                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_27_is_sys_pc2epc) 
                                                                          << 0x1bU) 
                                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_26_is_sys_pc2epc) 
                                                                             << 0x1aU) 
                                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_25_is_sys_pc2epc) 
                                                                                << 0x19U) 
                                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_24_is_sys_pc2epc) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_23_is_sys_pc2epc) 
                                                                                << 0x17U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_22_is_sys_pc2epc) 
                                                                                << 0x16U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_21_is_sys_pc2epc) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_20_is_sys_pc2epc) 
                                                                                << 0x14U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_19_is_sys_pc2epc) 
                                                                                << 0x13U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_18_is_sys_pc2epc) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_17_is_sys_pc2epc) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_16_is_sys_pc2epc) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_15_is_sys_pc2epc) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_14_is_sys_pc2epc) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_13_is_sys_pc2epc) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_12_is_sys_pc2epc) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_11_is_sys_pc2epc) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_10_is_sys_pc2epc) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_9_is_sys_pc2epc) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_8_is_sys_pc2epc) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_7_is_sys_pc2epc) 
                                                                                << 7U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_6_is_sys_pc2epc) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_5_is_sys_pc2epc) 
                                                                                << 5U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_4_is_sys_pc2epc) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_3_is_sys_pc2epc) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_2_is_sys_pc2epc) 
                                                                                << 2U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_1_is_sys_pc2epc) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_0_is_sys_pc2epc)))))))))))))))))))))))))))))))) 
                                                            >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))
                                                            : 
                                                           ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_31_is_sys_pc2epc) 
                                                              << 0x1fU) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_30_is_sys_pc2epc) 
                                                                 << 0x1eU) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_29_is_sys_pc2epc) 
                                                                    << 0x1dU) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_28_is_sys_pc2epc) 
                                                                       << 0x1cU) 
                                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_27_is_sys_pc2epc) 
                                                                          << 0x1bU) 
                                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_26_is_sys_pc2epc) 
                                                                             << 0x1aU) 
                                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_25_is_sys_pc2epc) 
                                                                                << 0x19U) 
                                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_24_is_sys_pc2epc) 
                                                                                << 0x18U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_23_is_sys_pc2epc) 
                                                                                << 0x17U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_22_is_sys_pc2epc) 
                                                                                << 0x16U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_21_is_sys_pc2epc) 
                                                                                << 0x15U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_20_is_sys_pc2epc) 
                                                                                << 0x14U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_19_is_sys_pc2epc) 
                                                                                << 0x13U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_18_is_sys_pc2epc) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_17_is_sys_pc2epc) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_16_is_sys_pc2epc) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_15_is_sys_pc2epc) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_14_is_sys_pc2epc) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_13_is_sys_pc2epc) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_12_is_sys_pc2epc) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_11_is_sys_pc2epc) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_10_is_sys_pc2epc) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_9_is_sys_pc2epc) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_8_is_sys_pc2epc) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_7_is_sys_pc2epc) 
                                                                                << 7U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_6_is_sys_pc2epc) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_5_is_sys_pc2epc) 
                                                                                << 5U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_4_is_sys_pc2epc) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_3_is_sys_pc2epc) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_2_is_sys_pc2epc) 
                                                                                << 2U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_1_is_sys_pc2epc) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_0_is_sys_pc2epc)))))))))))))))))))))))))))))))) 
                                                            >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx))))))
                                                    ? 2U
                                                    : 4U)))
                                   : 0U)),3);
    bufp->fullCData(oldp+108929,((0x7fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                            ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                                ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_uopc)
                                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_uopc))
                                                : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                                    ? 
                                                   ((0x1bU 
                                                     >= 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                     ? 
                                                    ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_uopc) 
                                                       << 0x15U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_uopc) 
                                                          << 0xeU) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_uopc) 
                                                             << 7U) 
                                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_uopc)))) 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                     : 0U)
                                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_uopc)))
                                            : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_uopc)))),7);
    __Vtemp_hc9e6dfeb__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_inst;
    __Vtemp_hc9e6dfeb__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_inst;
    __Vtemp_hc9e6dfeb__0[2U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_inst)) 
                                         << 0x20U) 
                                        | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_inst))));
    __Vtemp_hc9e6dfeb__0[3U] = (IData)(((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_inst)) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_inst))) 
                                        >> 0x20U));
    bufp->fullIData(oldp+108930,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                   ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                           ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_inst
                                           : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_inst)
                                       : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                           ? (((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx) 
                                                    << 5U)))
                                                ? 0U
                                                : (
                                                   __Vtemp_hc9e6dfeb__0[
                                                   (((IData)(0x1fU) 
                                                     + 
                                                     (0x7fU 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx) 
                                                         << 5U))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx) 
                                                        << 5U))))) 
                                              | (__Vtemp_hc9e6dfeb__0[
                                                 (3U 
                                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))] 
                                                 >> 
                                                 (0x1fU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx) 
                                                     << 5U))))
                                           : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_inst))
                                   : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_inst)),32);
    __Vtemp_h0e0d11fb__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_debug_inst;
    __Vtemp_h0e0d11fb__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_debug_inst;
    __Vtemp_h0e0d11fb__0[2U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_debug_inst)) 
                                         << 0x20U) 
                                        | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_debug_inst))));
    __Vtemp_h0e0d11fb__0[3U] = (IData)(((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_debug_inst)) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_debug_inst))) 
                                        >> 0x20U));
    bufp->fullIData(oldp+108931,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                   ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                           ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_debug_inst
                                           : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_debug_inst)
                                       : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                           ? (((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx) 
                                                    << 5U)))
                                                ? 0U
                                                : (
                                                   __Vtemp_h0e0d11fb__0[
                                                   (((IData)(0x1fU) 
                                                     + 
                                                     (0x7fU 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx) 
                                                         << 5U))) 
                                                    >> 5U)] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx) 
                                                        << 5U))))) 
                                              | (__Vtemp_h0e0d11fb__0[
                                                 (3U 
                                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))] 
                                                 >> 
                                                 (0x1fU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx) 
                                                     << 5U))))
                                           : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_debug_inst))
                                   : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_debug_inst)),32);
    bufp->fullBit(oldp+108932,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_is_rvc)
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_is_rvc))
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                               ? ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_is_rvc) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_is_rvc) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_is_rvc) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_is_rvc)))) 
                                                  >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_is_rvc)))
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_is_rvc)))));
    __Vtemp_hd6f6d71f__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_debug_pc);
    __Vtemp_hd6f6d71f__0[1U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_debug_pc) 
                                 << 8U) | (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_debug_pc 
                                                   >> 0x20U)));
    __Vtemp_hd6f6d71f__0[2U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_debug_pc) 
                                 << 0x10U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_debug_pc) 
                                               >> 0x18U) 
                                              | ((IData)(
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_debug_pc 
                                                          >> 0x20U)) 
                                                 << 8U)));
    __Vtemp_hd6f6d71f__0[3U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_debug_pc) 
                                 << 0x18U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_debug_pc) 
                                               >> 0x10U) 
                                              | ((IData)(
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_debug_pc 
                                                          >> 0x20U)) 
                                                 << 0x10U)));
    __Vtemp_hd6f6d71f__0[4U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_debug_pc) 
                                 >> 8U) | ((IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_debug_pc 
                                                    >> 0x20U)) 
                                           << 0x18U));
    bufp->fullQData(oldp+108933,((0xffffffffffULL & 
                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                    ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                        ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                            ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_debug_pc
                                            : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_debug_pc)
                                        : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                            ? ((0x9fU 
                                                >= 
                                                (0xffU 
                                                 & ((IData)(0x28U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                ? (
                                                   ((QData)((IData)(
                                                                    __Vtemp_hd6f6d71f__0[
                                                                    (((IData)(0x27U) 
                                                                      + 
                                                                      (0xffU 
                                                                       & ((IData)(0x28U) 
                                                                          * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx)))) 
                                                                     >> 5U)])) 
                                                    << 
                                                    ((0U 
                                                      == 
                                                      (0x1fU 
                                                       & ((IData)(0x28U) 
                                                          * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                      ? 0x20U
                                                      : 
                                                     ((IData)(0x40U) 
                                                      - 
                                                      (0x1fU 
                                                       & ((IData)(0x28U) 
                                                          * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx)))))) 
                                                   | (((0U 
                                                        == 
                                                        (0x1fU 
                                                         & ((IData)(0x28U) 
                                                            * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                        ? 0ULL
                                                        : 
                                                       ((QData)((IData)(
                                                                        __Vtemp_hd6f6d71f__0[
                                                                        (((IData)(0x1fU) 
                                                                          + 
                                                                          (0xffU 
                                                                           & ((IData)(0x28U) 
                                                                              * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx)))) 
                                                                         >> 5U)])) 
                                                        << 
                                                        ((IData)(0x20U) 
                                                         - 
                                                         (0x1fU 
                                                          & ((IData)(0x28U) 
                                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx)))))) 
                                                      | ((QData)((IData)(
                                                                         __Vtemp_hd6f6d71f__0[
                                                                         (7U 
                                                                          & (((IData)(0x28U) 
                                                                              * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx)) 
                                                                             >> 5U))])) 
                                                         >> 
                                                         (0x1fU 
                                                          & ((IData)(0x28U) 
                                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))))
                                                : 0ULL)
                                            : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_debug_pc))
                                    : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_debug_pc))),40);
    bufp->fullCData(oldp+108935,((7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                         ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                             ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                                 ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_iq_type)
                                                 : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_iq_type))
                                             : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                                 ? 
                                                ((0xbU 
                                                  >= 
                                                  (0xfU 
                                                   & ((IData)(3U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                  ? 
                                                 ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_iq_type) 
                                                    << 9U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_iq_type) 
                                                       << 6U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_iq_type) 
                                                          << 3U) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_iq_type)))) 
                                                  >> 
                                                  (0xfU 
                                                   & ((IData)(3U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                  : 0U)
                                                 : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_iq_type)))
                                         : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_iq_type)))),3);
    bufp->fullSData(oldp+108936,((0x3ffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                             ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                                 ? 
                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                                  ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_fu_code)
                                                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_fu_code))
                                                 : 
                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                                  ? 
                                                 ((0x27U 
                                                   >= 
                                                   (0x3fU 
                                                    & ((IData)(0xaU) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                   ? (IData)(
                                                             ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_fu_code)) 
                                                                << 0x1eU) 
                                                               | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_fu_code) 
                                                                                << 0x14U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_fu_code) 
                                                                                << 0xaU) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_fu_code)))))) 
                                                              >> 
                                                              (0x3fU 
                                                               & ((IData)(0xaU) 
                                                                  * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx)))))
                                                   : 0U)
                                                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_fu_code)))
                                             : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_fu_code)))),10);
    bufp->fullCData(oldp+108937,((0xfU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                               ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                                   ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_ctrl_br_type)
                                                   : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_br_type))
                                               : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                                   ? 
                                                  ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_ctrl_br_type) 
                                                     << 0xcU) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_ctrl_br_type) 
                                                        << 8U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_ctrl_br_type) 
                                                           << 4U) 
                                                          | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_ctrl_br_type)))) 
                                                   >> 
                                                   (0xfU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx) 
                                                       << 2U)))
                                                   : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_br_type)))
                                           : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_br_type)))),4);
    bufp->fullCData(oldp+108938,((3U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                         ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                             ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                                 ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_ctrl_op1_sel)
                                                 : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_op1_sel))
                                             : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                                 ? 
                                                ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_ctrl_op1_sel) 
                                                   << 6U) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_ctrl_op1_sel) 
                                                      << 4U) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_ctrl_op1_sel) 
                                                         << 2U) 
                                                        | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_ctrl_op1_sel)))) 
                                                 >> 
                                                 (7U 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx) 
                                                     << 1U)))
                                                 : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_op1_sel)))
                                         : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_op1_sel)))),2);
    bufp->fullCData(oldp+108939,((7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                         ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                             ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                                 ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_ctrl_op2_sel)
                                                 : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_op2_sel))
                                             : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                                 ? 
                                                ((0xbU 
                                                  >= 
                                                  (0xfU 
                                                   & ((IData)(3U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                  ? 
                                                 ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_ctrl_op2_sel) 
                                                    << 9U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_ctrl_op2_sel) 
                                                       << 6U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_ctrl_op2_sel) 
                                                          << 3U) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_ctrl_op2_sel)))) 
                                                  >> 
                                                  (0xfU 
                                                   & ((IData)(3U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                  : 0U)
                                                 : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_op2_sel)))
                                         : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_op2_sel)))),3);
    bufp->fullCData(oldp+108940,((7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                         ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                             ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                                 ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_ctrl_imm_sel)
                                                 : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_imm_sel))
                                             : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                                 ? 
                                                ((0xbU 
                                                  >= 
                                                  (0xfU 
                                                   & ((IData)(3U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                  ? 
                                                 ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_ctrl_imm_sel) 
                                                    << 9U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_ctrl_imm_sel) 
                                                       << 6U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_ctrl_imm_sel) 
                                                          << 3U) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_ctrl_imm_sel)))) 
                                                  >> 
                                                  (0xfU 
                                                   & ((IData)(3U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                  : 0U)
                                                 : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_imm_sel)))
                                         : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_imm_sel)))),3);
    bufp->fullCData(oldp+108941,((0xfU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                               ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                                   ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_ctrl_op_fcn)
                                                   : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_op_fcn))
                                               : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                                   ? 
                                                  ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_ctrl_op_fcn) 
                                                     << 0xcU) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_ctrl_op_fcn) 
                                                        << 8U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_ctrl_op_fcn) 
                                                           << 4U) 
                                                          | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_ctrl_op_fcn)))) 
                                                   >> 
                                                   (0xfU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx) 
                                                       << 2U)))
                                                   : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_op_fcn)))
                                           : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_op_fcn)))),4);
    bufp->fullBit(oldp+108942,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_ctrl_fcn_dw)
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_fcn_dw))
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                               ? ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_ctrl_fcn_dw) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_ctrl_fcn_dw) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_ctrl_fcn_dw) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_ctrl_fcn_dw)))) 
                                                  >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_fcn_dw)))
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_fcn_dw)))));
    bufp->fullCData(oldp+108943,((7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                         ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                             ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                                 ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_ctrl_csr_cmd)
                                                 : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_csr_cmd))
                                             : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                                 ? 
                                                ((0xbU 
                                                  >= 
                                                  (0xfU 
                                                   & ((IData)(3U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                  ? 
                                                 ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_ctrl_csr_cmd) 
                                                    << 9U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_ctrl_csr_cmd) 
                                                       << 6U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_ctrl_csr_cmd) 
                                                          << 3U) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_ctrl_csr_cmd)))) 
                                                  >> 
                                                  (0xfU 
                                                   & ((IData)(3U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                  : 0U)
                                                 : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_csr_cmd)))
                                         : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_csr_cmd)))),3);
    bufp->fullBit(oldp+108944,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_ctrl_is_load)
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_is_load))
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                               ? ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_ctrl_is_load) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_ctrl_is_load) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_ctrl_is_load) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_ctrl_is_load)))) 
                                                  >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_is_load)))
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_is_load)))));
    bufp->fullBit(oldp+108945,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_ctrl_is_sta)
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_is_sta))
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                               ? ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_ctrl_is_sta) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_ctrl_is_sta) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_ctrl_is_sta) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_ctrl_is_sta)))) 
                                                  >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_is_sta)))
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_is_sta)))));
    bufp->fullBit(oldp+108946,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_ctrl_is_std)
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_is_std))
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                               ? ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_ctrl_is_std) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_ctrl_is_std) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_ctrl_is_std) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_ctrl_is_std)))) 
                                                  >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_is_std)))
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ctrl_is_std)))));
    bufp->fullCData(oldp+108947,((3U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                         ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                             ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                                 ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_iw_state)
                                                 : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_iw_state))
                                             : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                                 ? 
                                                ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_iw_state) 
                                                   << 6U) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_iw_state) 
                                                      << 4U) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_iw_state) 
                                                         << 2U) 
                                                        | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_iw_state)))) 
                                                 >> 
                                                 (7U 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx) 
                                                     << 1U)))
                                                 : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_iw_state)))
                                         : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_iw_state)))),2);
    bufp->fullBit(oldp+108948,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_iw_p1_poisoned)
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_iw_p1_poisoned))
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                               ? ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_iw_p1_poisoned) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_iw_p1_poisoned) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_iw_p1_poisoned) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_iw_p1_poisoned)))) 
                                                  >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_iw_p1_poisoned)))
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_iw_p1_poisoned)))));
    bufp->fullBit(oldp+108949,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_iw_p2_poisoned)
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_iw_p2_poisoned))
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                               ? ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_iw_p2_poisoned) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_iw_p2_poisoned) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_iw_p2_poisoned) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_iw_p2_poisoned)))) 
                                                  >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_iw_p2_poisoned)))
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_iw_p2_poisoned)))));
    bufp->fullBit(oldp+108950,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_is_br)
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_is_br))
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                               ? ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_is_br) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_is_br) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_is_br) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_is_br)))) 
                                                  >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_is_br)))
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_is_br)))));
    bufp->fullBit(oldp+108951,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_is_jalr)
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_is_jalr))
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                               ? ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_is_jalr) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_is_jalr) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_is_jalr) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_is_jalr)))) 
                                                  >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_is_jalr)))
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_is_jalr)))));
    bufp->fullBit(oldp+108952,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_is_jal)
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_is_jal))
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                               ? ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_is_jal) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_is_jal) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_is_jal) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_is_jal)))) 
                                                  >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_is_jal)))
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_is_jal)))));
    bufp->fullBit(oldp+108953,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_is_sfb)
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_is_sfb))
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                               ? ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_is_sfb) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_is_sfb) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_is_sfb) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_is_sfb)))) 
                                                  >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_is_sfb)))
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_is_sfb)))));
    bufp->fullCData(oldp+108954,((0xfU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                               ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                                   ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_br_tag)
                                                   : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_br_tag))
                                               : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                                   ? 
                                                  ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_br_tag) 
                                                     << 0xcU) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_br_tag) 
                                                        << 8U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_br_tag) 
                                                           << 4U) 
                                                          | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_br_tag)))) 
                                                   >> 
                                                   (0xfU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx) 
                                                       << 2U)))
                                                   : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_br_tag)))
                                           : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_br_tag)))),4);
    bufp->fullCData(oldp+108955,((0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                            ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                                ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_ftq_idx)
                                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ftq_idx))
                                                : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                                    ? 
                                                   ((0x13U 
                                                     >= 
                                                     (0x1fU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                     ? 
                                                    ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_ftq_idx) 
                                                       << 0xfU) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_ftq_idx) 
                                                          << 0xaU) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_ftq_idx) 
                                                             << 5U) 
                                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_ftq_idx)))) 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                     : 0U)
                                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ftq_idx)))
                                            : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ftq_idx)))),5);
    bufp->fullBit(oldp+108956,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_edge_inst)
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_edge_inst))
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                               ? ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_edge_inst) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_edge_inst) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_edge_inst) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_edge_inst)))) 
                                                  >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_edge_inst)))
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_edge_inst)))));
    bufp->fullCData(oldp+108957,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                   ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                           ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_pc_lob)
                                           : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_pc_lob))
                                       : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                           ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_296)
                                           : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_pc_lob)))
                                   : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_pc_lob))),6);
    bufp->fullBit(oldp+108958,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_taken)
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_taken))
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                               ? ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_taken) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_taken) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_taken) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_taken)))) 
                                                  >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_taken)))
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_taken)))));
    __Vtemp_h9e2d2b73__0[0U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_imm_packed)) 
                                         << 0x28U) 
                                        | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_imm_packed)) 
                                            << 0x14U) 
                                           | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_imm_packed)))));
    __Vtemp_h9e2d2b73__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_imm_packed 
                                 << 0x1cU) | (IData)(
                                                     ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_imm_packed)) 
                                                        << 0x28U) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_imm_packed)) 
                                                           << 0x14U) 
                                                          | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_imm_packed)))) 
                                                      >> 0x20U)));
    __Vtemp_h9e2d2b73__0[2U] = (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_imm_packed 
                                >> 4U);
    bufp->fullIData(oldp+108959,((0xfffffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                               ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                                   ? 
                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_imm_packed
                                                    : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_imm_packed)
                                                   : 
                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                                    ? 
                                                   ((0x4fU 
                                                     >= 
                                                     (0x7fU 
                                                      & ((IData)(0x14U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                     ? 
                                                    (((0U 
                                                       == 
                                                       (0x1fU 
                                                        & ((IData)(0x14U) 
                                                           * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                       ? 0U
                                                       : 
                                                      (__Vtemp_h9e2d2b73__0[
                                                       (((IData)(0x13U) 
                                                         + 
                                                         (0x7fU 
                                                          & ((IData)(0x14U) 
                                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx)))) 
                                                        >> 5U)] 
                                                       << 
                                                       ((IData)(0x20U) 
                                                        - 
                                                        (0x1fU 
                                                         & ((IData)(0x14U) 
                                                            * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx)))))) 
                                                     | (__Vtemp_h9e2d2b73__0[
                                                        (3U 
                                                         & (((IData)(0x14U) 
                                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx)) 
                                                            >> 5U))] 
                                                        >> 
                                                        (0x1fU 
                                                         & ((IData)(0x14U) 
                                                            * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx)))))
                                                     : 0U)
                                                    : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_imm_packed))
                                               : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_imm_packed))),20);
    bufp->fullSData(oldp+108960,((0xfffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                             ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                                 ? 
                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                                  ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_csr_addr)
                                                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_csr_addr))
                                                 : 
                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                                  ? 
                                                 ((0x2fU 
                                                   >= 
                                                   (0x3fU 
                                                    & ((IData)(0xcU) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                   ? (IData)(
                                                             ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_csr_addr)) 
                                                                << 0x24U) 
                                                               | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_csr_addr)) 
                                                                   << 0x18U) 
                                                                  | (QData)((IData)(
                                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_csr_addr) 
                                                                                << 0xcU) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_csr_addr)))))) 
                                                              >> 
                                                              (0x3fU 
                                                               & ((IData)(0xcU) 
                                                                  * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx)))))
                                                   : 0U)
                                                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_csr_addr)))
                                             : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_csr_addr)))),12);
    bufp->fullCData(oldp+108961,((0x7fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                            ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                                ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_rob_idx)
                                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_rob_idx))
                                                : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                                    ? 
                                                   ((0x1bU 
                                                     >= 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                     ? 
                                                    ((0x8080U 
                                                      | ((0xf800000U 
                                                          & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_tail_idx) 
                                                             << 0x15U)) 
                                                         | ((0x1f0000U 
                                                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_tail_idx) 
                                                                << 0xeU)) 
                                                            | ((0x3e00U 
                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_tail_idx) 
                                                                   << 7U)) 
                                                               | (0x7cU 
                                                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_tail_idx)))))) 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                     : 0U)
                                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_rob_idx)))
                                            : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_rob_idx)))),7);
    bufp->fullCData(oldp+108962,((0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                            ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                                ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_ldq_idx)
                                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ldq_idx))
                                                : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                                    ? 
                                                   ((0x13U 
                                                     >= 
                                                     (0x1fU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                     ? 
                                                    ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_tail) 
                                                       << 0xfU) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___T_75) 
                                                          << 0xaU) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___T_35) 
                                                             << 5U) 
                                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_tail)))) 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                     : 0U)
                                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ldq_idx)))
                                            : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ldq_idx)))),5);
    bufp->fullCData(oldp+108963,((0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                            ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                                ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_stq_idx)
                                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_stq_idx))
                                                : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                                    ? 
                                                   ((0x13U 
                                                     >= 
                                                     (0x1fU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                     ? 
                                                    ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_tail) 
                                                       << 0xfU) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___T_82) 
                                                          << 0xaU) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___T_42) 
                                                             << 5U) 
                                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_tail)))) 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                     : 0U)
                                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_stq_idx)))
                                            : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_stq_idx)))),5);
    bufp->fullCData(oldp+108964,((3U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                         ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                             ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                                 ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_rxq_idx)
                                                 : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_rxq_idx))
                                             : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                                 ? 
                                                ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rxq_tail) 
                                                   << 6U) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___csr_exe_unit_io_rocc_rxq_idx_2) 
                                                      << 4U) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___csr_exe_unit_io_rocc_rxq_idx_1) 
                                                         << 2U) 
                                                        | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rxq_tail)))) 
                                                 >> 
                                                 (7U 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx) 
                                                     << 1U)))
                                                 : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_rxq_idx)))
                                         : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_rxq_idx)))),2);
    bufp->fullCData(oldp+108965,((0x7fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                            ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                                ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_pdst)
                                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_pdst))
                                                : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                                    ? 
                                                   ((0x1bU 
                                                     >= 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                     ? 
                                                    ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_0_pdst) 
                                                       << 0x15U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_2_pdst) 
                                                          << 0xeU) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_1_pdst) 
                                                             << 7U) 
                                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_0_pdst)))) 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                     : 0U)
                                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_pdst)))
                                            : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_pdst)))),7);
    bufp->fullCData(oldp+108966,((0x7fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                            ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                                ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_prs1)
                                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_prs1))
                                                : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                                    ? 
                                                   ((0x1bU 
                                                     >= 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                     ? 
                                                    ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_0_prs1) 
                                                       << 0x15U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_2_prs1) 
                                                          << 0xeU) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_1_prs1) 
                                                             << 7U) 
                                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_0_prs1)))) 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                     : 0U)
                                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_prs1)))
                                            : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_prs1)))),7);
    bufp->fullCData(oldp+108967,((0x7fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                            ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                                ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_prs2)
                                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_prs2))
                                                : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                                    ? 
                                                   ((0x1bU 
                                                     >= 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                     ? 
                                                    ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_0_prs2) 
                                                       << 0x15U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_2_prs2) 
                                                          << 0xeU) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_1_prs2) 
                                                             << 7U) 
                                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_0_prs2)))) 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                     : 0U)
                                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_prs2)))
                                            : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_prs2)))),7);
    bufp->fullCData(oldp+108968,((0x7fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                            ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                                ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_prs3)
                                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_prs3))
                                                : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                                    ? 
                                                   ((0x1bU 
                                                     >= 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                     ? 
                                                    ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__r_uop_prs3) 
                                                       << 0x15U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_rename_stage_io_ren2_uops_2_prs3) 
                                                          << 0xeU) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_rename_stage_io_ren2_uops_1_prs3) 
                                                             << 7U) 
                                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__r_uop_prs3)))) 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                     : 0U)
                                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_prs3)))
                                            : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_prs3)))),7);
    bufp->fullCData(oldp+108969,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                   ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                           ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_ppred)
                                           : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ppred))
                                       : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                           ? 0U : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ppred)))
                                   : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ppred))),5);
    bufp->fullBit(oldp+108970,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_prs1_busy)
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_prs1_busy))
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                               ? ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_0_prs1_busy) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_2_prs1_busy) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_1_prs1_busy) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_0_prs1_busy)))) 
                                                  >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_prs1_busy)))
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_prs1_busy)))));
    bufp->fullBit(oldp+108971,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_prs2_busy)
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_prs2_busy))
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                               ? ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_0_prs2_busy) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_2_prs2_busy) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_1_prs2_busy) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_0_prs2_busy)))) 
                                                  >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_prs2_busy)))
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_prs2_busy)))));
    bufp->fullBit(oldp+108972,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_prs3_busy)
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_prs3_busy))
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                               ? ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_0_prs3_busy) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_2_prs3_busy) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_1_prs3_busy) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_0_prs3_busy)))) 
                                                  >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_prs3_busy)))
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_prs3_busy)))));
    bufp->fullBit(oldp+108973,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                 ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                     ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                         ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_ppred_busy)
                                         : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ppred_busy))
                                     : ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)) 
                                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ppred_busy)))
                                 : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_ppred_busy))));
    bufp->fullCData(oldp+108974,((0x7fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                            ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                                ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_stale_pdst)
                                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_stale_pdst))
                                                : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                                    ? 
                                                   ((0x1bU 
                                                     >= 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                     ? 
                                                    ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_0_stale_pdst) 
                                                       << 0x15U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_2_stale_pdst) 
                                                          << 0xeU) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_1_stale_pdst) 
                                                             << 7U) 
                                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dis_uops_0_stale_pdst)))) 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(7U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                     : 0U)
                                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_stale_pdst)))
                                            : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_stale_pdst)))),7);
    bufp->fullBit(oldp+108975,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_exception)
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_exception))
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                               ? ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_exception) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_exception) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_exception) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_exception)))) 
                                                  >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_exception)))
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_exception)))));
    __Vtemp_ha67e93b3__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_exc_cause);
    __Vtemp_ha67e93b3__0[1U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_exc_cause 
                                        >> 0x20U));
    __Vtemp_ha67e93b3__0[2U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_exc_cause);
    __Vtemp_ha67e93b3__0[3U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_exc_cause 
                                        >> 0x20U));
    __Vtemp_ha67e93b3__0[4U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_exc_cause);
    __Vtemp_ha67e93b3__0[5U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_exc_cause 
                                        >> 0x20U));
    __Vtemp_ha67e93b3__0[6U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_exc_cause);
    __Vtemp_ha67e93b3__0[7U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_exc_cause 
                                        >> 0x20U));
    bufp->fullQData(oldp+108976,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                   ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                           ? (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_cause))
                                           : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_exc_cause)
                                       : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                           ? (((QData)((IData)(
                                                               __Vtemp_ha67e93b3__0[
                                                               (((IData)(0x3fU) 
                                                                 + 
                                                                 (0xffU 
                                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx) 
                                                                     << 6U))) 
                                                                >> 5U)])) 
                                               << (
                                                   (0U 
                                                    == 
                                                    (0x1fU 
                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx) 
                                                        << 6U)))
                                                    ? 0x20U
                                                    : 
                                                   ((IData)(0x40U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx) 
                                                        << 6U))))) 
                                              | (((0U 
                                                   == 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx) 
                                                       << 6U)))
                                                   ? 0ULL
                                                   : 
                                                  ((QData)((IData)(
                                                                   __Vtemp_ha67e93b3__0[
                                                                   (((IData)(0x1fU) 
                                                                     + 
                                                                     (0xffU 
                                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx) 
                                                                         << 6U))) 
                                                                    >> 5U)])) 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx) 
                                                        << 6U))))) 
                                                 | ((QData)((IData)(
                                                                    __Vtemp_ha67e93b3__0[
                                                                    (6U 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx) 
                                                                        << 1U))])) 
                                                    >> 
                                                    (0x1fU 
                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx) 
                                                        << 6U)))))
                                           : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_exc_cause))
                                   : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_exc_cause)),64);
    bufp->fullBit(oldp+108978,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_bypassable)
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_bypassable))
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                               ? ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_bypassable) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_bypassable) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_bypassable) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_bypassable)))) 
                                                  >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_bypassable)))
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_bypassable)))));
    bufp->fullCData(oldp+108979,((0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                            ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                                ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_mem_cmd)
                                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_mem_cmd))
                                                : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                                    ? 
                                                   ((0x13U 
                                                     >= 
                                                     (0x1fU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                     ? 
                                                    ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_mem_cmd) 
                                                       << 0xfU) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_mem_cmd) 
                                                          << 0xaU) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_mem_cmd) 
                                                             << 5U) 
                                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_mem_cmd)))) 
                                                     >> 
                                                     (0x1fU 
                                                      & ((IData)(5U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))))
                                                     : 0U)
                                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_mem_cmd)))
                                            : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_mem_cmd)))),5);
    bufp->fullCData(oldp+108980,((3U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                         ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                             ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                                 ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_mem_size)
                                                 : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_mem_size))
                                             : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                                 ? 
                                                ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_mem_size) 
                                                   << 6U) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_mem_size) 
                                                      << 4U) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_mem_size) 
                                                         << 2U) 
                                                        | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_mem_size)))) 
                                                 >> 
                                                 (7U 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx) 
                                                     << 1U)))
                                                 : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_mem_size)))
                                         : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_mem_size)))),2);
    bufp->fullBit(oldp+108981,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1398)
                                       ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_lxcpt_valid)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1405)
                                               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__r_xcpt_uop_mem_signed)
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_mem_signed))
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_1409)
                                               ? ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_mem_signed) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_mem_signed) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_mem_signed) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_mem_signed)))) 
                                                  >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__idx))
                                               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_mem_signed)))
                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__r_xcpt_uop_mem_signed)))));
}
