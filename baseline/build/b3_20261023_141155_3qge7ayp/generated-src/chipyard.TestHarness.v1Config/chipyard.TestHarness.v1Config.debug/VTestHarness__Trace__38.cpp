// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "VTestHarness__Syms.h"


extern const VlWide<2048>/*65535:0*/ VTestHarness__ConstPool__CONST_h5f0e7fd6_0;
extern const VlWide<64>/*2047:0*/ VTestHarness__ConstPool__CONST_ha056d847_0;
extern const VlWide<33>/*1055:0*/ VTestHarness__ConstPool__CONST_hf1d89c7e_0;
extern const VlWide<33>/*1055:0*/ VTestHarness__ConstPool__CONST_hd0572db1_0;

void VTestHarness___024root__trace_chg_sub_38(VTestHarness___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root__trace_chg_sub_38\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 111212);
    VlWide<5>/*159:0*/ __Vtemp_hbc54b0fd__0;
    VlWide<5>/*159:0*/ __Vtemp_hf1427b78__0;
    VlWide<5>/*159:0*/ __Vtemp_hc0d9b241__0;
    VlWide<5>/*159:0*/ __Vtemp_h0807dc75__0;
    VlWide<5>/*159:0*/ __Vtemp_hca3a2207__0;
    VlWide<5>/*159:0*/ __Vtemp_h5b39d182__0;
    VlWide<5>/*159:0*/ __Vtemp_h266ce27f__0;
    VlWide<5>/*159:0*/ __Vtemp_h864f979f__0;
    VlWide<4>/*127:0*/ __Vtemp_h017094c4__0;
    VlWide<8>/*255:0*/ __Vtemp_h9b14575f__0;
    VlWide<8>/*255:0*/ __Vtemp_h9b93cb5f__0;
    VlWide<4>/*127:0*/ __Vtemp_hed165ee8__0;
    VlWide<8>/*255:0*/ __Vtemp_hf77b9dbc__0;
    VlWide<8>/*255:0*/ __Vtemp_h4da38fe0__0;
    VlWide<4>/*127:0*/ __Vtemp_hfcec72af__0;
    VlWide<8>/*255:0*/ __Vtemp_heaf20e4b__0;
    VlWide<8>/*255:0*/ __Vtemp_h1071e998__0;
    VlWide<4>/*127:0*/ __Vtemp_hdbb986da__0;
    VlWide<8>/*255:0*/ __Vtemp_h18615b55__0;
    VlWide<8>/*255:0*/ __Vtemp_h18ad1821__0;
    VlWide<8>/*255:0*/ __Vtemp_h33641d2a__0;
    VlWide<32>/*1023:0*/ __Vtemp_h8236c4c9__0;
    VlWide<64>/*2047:0*/ __Vtemp_hdfc08149__0;
    VlWide<64>/*2047:0*/ __Vtemp_h0b048a1a__0;
    VlWide<33>/*1055:0*/ __Vtemp_h05224570__0;
    VlWide<4>/*127:0*/ __Vtemp_h73565780__0;
    VlWide<4>/*127:0*/ __Vtemp_hb42910ab__8;
    VlWide<64>/*2047:0*/ __Vtemp_h885446e2__0;
    VlWide<64>/*2047:0*/ __Vtemp_h3cdc4348__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9bf1e077__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__0;
    VlWide<4>/*127:0*/ __Vtemp_h9a9a6856__0;
    VlWide<4>/*127:0*/ __Vtemp_hca162495__0;
    VlWide<3>/*95:0*/ __Vtemp_h819c6816__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__1;
    VlWide<4>/*127:0*/ __Vtemp_h9a9a6856__1;
    VlWide<4>/*127:0*/ __Vtemp_h0ada6192__0;
    VlWide<3>/*95:0*/ __Vtemp_hd7b582ad__0;
    VlWide<64>/*2047:0*/ __Vtemp_h182e915d__0;
    VlWide<64>/*2047:0*/ __Vtemp_h93bb4e5e__0;
    VlWide<33>/*1055:0*/ __Vtemp_ha3ff2fea__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__2;
    VlWide<4>/*127:0*/ __Vtemp_h9a9a6856__2;
    VlWide<4>/*127:0*/ __Vtemp_h996bff05__0;
    VlWide<3>/*95:0*/ __Vtemp_hfb7966ea__0;
    VlWide<64>/*2047:0*/ __Vtemp_h760111ce__0;
    VlWide<64>/*2047:0*/ __Vtemp_h47380d22__0;
    VlWide<33>/*1055:0*/ __Vtemp_h99228d75__0;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x18U])) {
        bufp->chgBit(oldp+0,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT____Vcellinp__tile_prci_domain__auto_tile_reset_domain_boom_tile_icsl_na_sk_in) 
                                    >> 4U))));
        bufp->chgCData(oldp+1,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT____Vcellinp__ic_master__io_ic_incr),3);
        bufp->chgBit(oldp+2,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT____Vcellinp__tile_prci_domain__auto_tile_reset_domain_boom_tile_clear_ic_status_tomain_sk_in))));
        bufp->chgBit(oldp+3,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT____Vcellinp__tile_prci_domain__auto_tile_reset_domain_boom_tile_clear_ic_status_tomain_sk_in) 
                                    >> 1U))));
        bufp->chgBit(oldp+4,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT____Vcellinp__tile_prci_domain__auto_tile_reset_domain_boom_tile_clear_ic_status_tomain_sk_in) 
                                    >> 2U))));
        bufp->chgBit(oldp+5,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT____Vcellinp__tile_prci_domain__auto_tile_reset_domain_boom_tile_clear_ic_status_tomain_sk_in) 
                                    >> 3U))));
        bufp->chgBit(oldp+6,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT____Vcellinp__tile_prci_domain__auto_tile_reset_domain_boom_tile_clear_ic_status_tomain_sk_in) 
                                    >> 4U))));
        bufp->chgBit(oldp+7,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT__if_t_and_na));
        bufp->chgBit(oldp+8,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT__if_t_and_a));
        bufp->chgBit(oldp+9,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT____Vcellinp__rob__io_gh_stall));
        bufp->chgQData(oldp+10,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_debug_rs2_0),64);
        bufp->chgQData(oldp+12,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_debug_rs2_1),64);
        bufp->chgQData(oldp+14,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_commit_debug_rs2_2),64);
        bufp->chgBit(oldp+16,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___rob_io_com_xcpt_valid));
        bufp->chgBit(oldp+17,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__can_commit_0));
        bufp->chgBit(oldp+18,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__can_commit_1));
        bufp->chgBit(oldp+19,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__exception_thrown));
        bufp->chgBit(oldp+20,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__flush_commit_mask_0));
        bufp->chgBit(oldp+21,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__flush_commit_mask_1));
        bufp->chgBit(oldp+22,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__flush_commit_mask_2));
        bufp->chgBit(oldp+23,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__flush_commit));
        bufp->chgBit(oldp+24,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__fflags_val_0));
        bufp->chgBit(oldp+25,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__fflags_val_1));
        bufp->chgBit(oldp+26,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__fflags_val_2));
        bufp->chgSData(oldp+27,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__next_xcpt_uop_br_mask),16);
        bufp->chgBit(oldp+28,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__finished_committing_row));
        bufp->chgBit(oldp+29,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_deq));
        bufp->chgCData(oldp+30,((0x1fU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___core_io_ifu_commit_bits)),5);
        bufp->chgBit(oldp+31,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT____Vcellinp__gh_buf__io_cdc_not_ready));
        bufp->chgCData(oldp+32,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___gh_buf_io_gh_packet_dest),4);
        bufp->chgBit(oldp+33,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__deq_valid_2));
        bufp->chgBit(oldp+34,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__deq_valid_1));
        bufp->chgBit(oldp+35,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__deq_valid_0));
        bufp->chgCData(oldp+36,((3U & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__deq_valid_0) 
                                        + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__deq_valid_1)) 
                                       + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__deq_valid_2)))),2);
        bufp->chgWData(oldp+37,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__buffer_deq_data_0),136);
        bufp->chgWData(oldp+42,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__buffer_deq_data_1),136);
        bufp->chgWData(oldp+47,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__buffer_deq_data_2),136);
        bufp->chgCData(oldp+52,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__out_inst_type_0),8);
        bufp->chgCData(oldp+53,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__out_inst_type_1),8);
        bufp->chgBit(oldp+54,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__commit_store));
        bufp->chgBit(oldp+55,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__commit_load));
        bufp->chgCData(oldp+56,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__idx),5);
        bufp->chgBit(oldp+57,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__commit_store_1));
        bufp->chgBit(oldp+58,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__commit_load_1));
        bufp->chgCData(oldp+59,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__idx_1),5);
        bufp->chgBit(oldp+60,((0x17U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___T_1981))));
        bufp->chgBit(oldp+61,((0x17U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___T_1985))));
        bufp->chgBit(oldp+62,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__commit_store_2));
        bufp->chgBit(oldp+63,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__commit_load_2));
        bufp->chgCData(oldp+64,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__idx_2),5);
        bufp->chgBit(oldp+65,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__widx_gray))));
        bufp->chgBit(oldp+66,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__widx_gray) 
                                     >> 1U))));
        bufp->chgBit(oldp+67,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__widx_gray) 
                                     >> 2U))));
        bufp->chgBit(oldp+68,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__widx_gray) 
                                     >> 3U))));
        bufp->chgBit(oldp+69,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_d_source__DOT__widx_gray))));
        bufp->chgBit(oldp+70,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_d_source__DOT__widx_gray) 
                                     >> 1U))));
        bufp->chgBit(oldp+71,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_d_source__DOT__widx_gray) 
                                     >> 2U))));
        bufp->chgBit(oldp+72,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_d_source__DOT__widx_gray) 
                                     >> 3U))));
        bufp->chgBit(oldp+73,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+74,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__ridx_gray) 
                                     >> 1U))));
        bufp->chgBit(oldp+75,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__ridx_gray) 
                                     >> 2U))));
        bufp->chgBit(oldp+76,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__ridx_gray) 
                                     >> 3U))));
        bufp->chgBit(oldp+77,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+78,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__ridx_gray) 
                                     >> 1U))));
        bufp->chgBit(oldp+79,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__ridx_gray) 
                                     >> 2U))));
        bufp->chgBit(oldp+80,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__ridx_gray) 
                                     >> 3U))));
        bufp->chgBit(oldp+81,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_e_sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+82,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_e_sink__DOT__ridx_gray) 
                                     >> 1U))));
        bufp->chgBit(oldp+83,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_e_sink__DOT__ridx_gray) 
                                     >> 2U))));
        bufp->chgBit(oldp+84,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_e_sink__DOT__ridx_gray) 
                                     >> 3U))));
        bufp->chgBit(oldp+85,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_b_source__DOT__widx_gray))));
        bufp->chgBit(oldp+86,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_b_source__DOT__widx_gray) 
                                     >> 1U))));
        bufp->chgBit(oldp+87,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_b_source__DOT__widx_gray) 
                                     >> 2U))));
        bufp->chgBit(oldp+88,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_b_source__DOT__widx_gray) 
                                     >> 3U))));
        bufp->chgBit(oldp+89,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_d_source__DOT__widx_gray))));
        bufp->chgBit(oldp+90,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_d_source__DOT__widx_gray) 
                                     >> 1U))));
        bufp->chgBit(oldp+91,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_d_source__DOT__widx_gray) 
                                     >> 2U))));
        bufp->chgBit(oldp+92,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_d_source__DOT__widx_gray) 
                                     >> 3U))));
        bufp->chgBit(oldp+93,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+94,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__ridx_gray) 
                                     >> 1U))));
        bufp->chgBit(oldp+95,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__ridx_gray) 
                                     >> 2U))));
        bufp->chgBit(oldp+96,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__ridx_gray) 
                                     >> 3U))));
        bufp->chgBit(oldp+97,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+98,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__ridx_gray) 
                                     >> 1U))));
        bufp->chgBit(oldp+99,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__ridx_gray) 
                                     >> 2U))));
        bufp->chgBit(oldp+100,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__ridx_gray) 
                                      >> 3U))));
        bufp->chgBit(oldp+101,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_e_sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+102,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_e_sink__DOT__ridx_gray) 
                                      >> 1U))));
        bufp->chgBit(oldp+103,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_e_sink__DOT__ridx_gray) 
                                      >> 2U))));
        bufp->chgBit(oldp+104,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_e_sink__DOT__ridx_gray) 
                                      >> 3U))));
        bufp->chgBit(oldp+105,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_b_source__DOT__widx_gray))));
        bufp->chgBit(oldp+106,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_b_source__DOT__widx_gray) 
                                      >> 1U))));
        bufp->chgBit(oldp+107,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_b_source__DOT__widx_gray) 
                                      >> 2U))));
        bufp->chgBit(oldp+108,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_b_source__DOT__widx_gray) 
                                      >> 3U))));
        bufp->chgBit(oldp+109,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_d_source__DOT__widx_gray))));
        bufp->chgBit(oldp+110,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_d_source__DOT__widx_gray) 
                                      >> 1U))));
        bufp->chgBit(oldp+111,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_d_source__DOT__widx_gray) 
                                      >> 2U))));
        bufp->chgBit(oldp+112,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_d_source__DOT__widx_gray) 
                                      >> 3U))));
        bufp->chgBit(oldp+113,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+114,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__ridx_gray) 
                                      >> 1U))));
        bufp->chgBit(oldp+115,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__ridx_gray) 
                                      >> 2U))));
        bufp->chgBit(oldp+116,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__ridx_gray) 
                                      >> 3U))));
        bufp->chgBit(oldp+117,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+118,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__ridx_gray) 
                                      >> 1U))));
        bufp->chgBit(oldp+119,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__ridx_gray) 
                                      >> 2U))));
        bufp->chgBit(oldp+120,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__ridx_gray) 
                                      >> 3U))));
        bufp->chgBit(oldp+121,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_e_sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+122,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_e_sink__DOT__ridx_gray) 
                                      >> 1U))));
        bufp->chgBit(oldp+123,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_e_sink__DOT__ridx_gray) 
                                      >> 2U))));
        bufp->chgBit(oldp+124,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_e_sink__DOT__ridx_gray) 
                                      >> 3U))));
        bufp->chgBit(oldp+125,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_b_source__DOT__widx_gray))));
        bufp->chgBit(oldp+126,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_b_source__DOT__widx_gray) 
                                      >> 1U))));
        bufp->chgBit(oldp+127,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_b_source__DOT__widx_gray) 
                                      >> 2U))));
        bufp->chgBit(oldp+128,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_b_source__DOT__widx_gray) 
                                      >> 3U))));
        bufp->chgBit(oldp+129,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_d_source__DOT__widx_gray))));
        bufp->chgBit(oldp+130,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_d_source__DOT__widx_gray) 
                                      >> 1U))));
        bufp->chgBit(oldp+131,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_d_source__DOT__widx_gray) 
                                      >> 2U))));
        bufp->chgBit(oldp+132,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_d_source__DOT__widx_gray) 
                                      >> 3U))));
        bufp->chgBit(oldp+133,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+134,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__ridx_gray) 
                                      >> 1U))));
        bufp->chgBit(oldp+135,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__ridx_gray) 
                                      >> 2U))));
        bufp->chgBit(oldp+136,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__ridx_gray) 
                                      >> 3U))));
        bufp->chgBit(oldp+137,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+138,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__ridx_gray) 
                                      >> 1U))));
        bufp->chgBit(oldp+139,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__ridx_gray) 
                                      >> 2U))));
        bufp->chgBit(oldp+140,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__ridx_gray) 
                                      >> 3U))));
        bufp->chgBit(oldp+141,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_e_sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+142,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_e_sink__DOT__ridx_gray) 
                                      >> 1U))));
        bufp->chgBit(oldp+143,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_e_sink__DOT__ridx_gray) 
                                      >> 2U))));
        bufp->chgBit(oldp+144,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_e_sink__DOT__ridx_gray) 
                                      >> 3U))));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x19U])) {
        bufp->chgBit(oldp+145,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+146,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+147,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+148,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+149,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+150,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+151,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+152,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+153,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+154,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+155,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+156,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+157,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+158,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+159,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+160,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+161,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+162,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+163,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+164,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+165,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+166,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+167,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+168,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+169,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+170,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+171,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+172,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_d_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+173,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_e_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+174,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+175,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+176,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+177,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+178,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+179,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+180,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+181,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+182,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_d_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+183,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_d_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+184,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_d_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+185,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_d_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+186,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_d_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+187,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_d_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+188,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_d_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+189,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_d_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+190,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+191,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+192,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+193,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+194,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+195,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+196,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+197,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+198,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+199,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+200,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+201,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+202,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+203,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+204,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+205,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+206,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_e_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+207,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_e_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+208,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_e_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+209,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_e_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+210,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_e_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+211,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_e_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+212,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_e_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+213,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_e_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x1aU])) {
        bufp->chgBit(oldp+214,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+215,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+216,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+217,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+218,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+219,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+220,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+221,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+222,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+223,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+224,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+225,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+226,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+227,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+228,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+229,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+230,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+231,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+232,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+233,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+234,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+235,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+236,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+237,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+238,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+239,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_b_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+240,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+241,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_d_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+242,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_e_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+243,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_b_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+244,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_b_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+245,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_b_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+246,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_b_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+247,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_b_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+248,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_b_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+249,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_b_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+250,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_b_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+251,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_d_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+252,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_d_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+253,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_d_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+254,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_d_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+255,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_d_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+256,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_d_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+257,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_d_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+258,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__bundleIn_0_d_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+259,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+260,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+261,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+262,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+263,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+264,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+265,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+266,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+267,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+268,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+269,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+270,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+271,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+272,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+273,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+274,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+275,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_e_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+276,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_e_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+277,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_e_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+278,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_e_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+279,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_e_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+280,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_e_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+281,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_e_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+282,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_e_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x1bU])) {
        bufp->chgBit(oldp+283,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+284,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+285,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+286,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+287,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+288,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+289,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+290,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+291,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+292,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+293,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+294,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+295,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+296,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+297,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+298,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+299,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+300,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+301,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+302,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+303,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+304,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+305,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+306,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+307,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+308,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_b_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+309,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+310,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_d_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+311,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_e_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+312,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_b_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+313,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_b_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+314,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_b_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+315,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_b_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+316,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_b_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+317,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_b_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+318,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_b_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+319,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_b_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+320,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_d_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+321,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_d_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+322,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_d_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+323,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_d_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+324,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_d_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+325,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_d_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+326,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_d_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+327,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__bundleIn_0_d_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+328,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+329,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+330,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+331,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+332,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+333,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+334,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+335,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+336,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+337,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+338,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+339,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+340,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+341,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+342,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+343,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+344,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_e_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+345,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_e_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+346,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_e_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+347,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_e_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+348,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_e_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+349,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_e_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+350,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_e_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+351,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_e_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x1cU])) {
        bufp->chgBit(oldp+352,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+353,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+354,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+355,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+356,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+357,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+358,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+359,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+360,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+361,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+362,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+363,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+364,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+365,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+366,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+367,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+368,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+369,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+370,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+371,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+372,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+373,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+374,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+375,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+376,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+377,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_b_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+378,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+379,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_d_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+380,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_e_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+381,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_b_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+382,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_b_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+383,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_b_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+384,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_b_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+385,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_b_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+386,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_b_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+387,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_b_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+388,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_b_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+389,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_d_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+390,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_d_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+391,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_d_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+392,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_d_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+393,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_d_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+394,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_d_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+395,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_d_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+396,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_d_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+397,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+398,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+399,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+400,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+401,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+402,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+403,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+404,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+405,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+406,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+407,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+408,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+409,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+410,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+411,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+412,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+413,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_e_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+414,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_e_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+415,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_e_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+416,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_e_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+417,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_e_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+418,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_e_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+419,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_e_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+420,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_e_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x1dU])) {
        bufp->chgBit(oldp+421,(vlSelf->TestHarness__DOT__chiptop__DOT__debug_reset_syncd_debug_reset_sync__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+422,(vlSelf->TestHarness__DOT__chiptop__DOT__debug_reset_syncd_debug_reset_sync__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+423,(vlSelf->TestHarness__DOT__chiptop__DOT__debug_reset_syncd_debug_reset_sync__DOT__output_chain__DOT__sync_2));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x1eU])) {
        bufp->chgBit(oldp+424,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT___io_deq_valid_output));
        bufp->chgCData(oldp+425,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__ridx_gray),4);
        bufp->chgBit(oldp+426,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgCData(oldp+427,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__ridx_ridx_bin),4);
        bufp->chgCData(oldp+428,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__ridx_incremented),4);
        bufp->chgCData(oldp+429,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__ridx),4);
        bufp->chgBit(oldp+430,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__valid));
        bufp->chgBit(oldp+431,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__valid_reg));
        bufp->chgBit(oldp+432,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+433,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+434,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+435,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+436,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+437,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+438,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+439,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+440,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__source_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+441,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__source_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+442,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__source_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgCData(oldp+443,((((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0) 
                                   << 3U) | (((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0) 
                                              << 2U) 
                                             | (((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                 << 1U) 
                                                | (IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0))))),4);
        bufp->chgBit(oldp+444,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+445,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+446,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+447,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0));
        bufp->chgBit(oldp+448,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1));
        bufp->chgBit(oldp+449,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2));
        bufp->chgBit(oldp+450,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0));
        bufp->chgBit(oldp+451,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1));
        bufp->chgBit(oldp+452,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2));
        bufp->chgBit(oldp+453,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0));
        bufp->chgBit(oldp+454,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1));
        bufp->chgBit(oldp+455,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2));
        bufp->chgBit(oldp+456,((1U & (IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+457,((1U & ((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__ridx_gray) 
                                      >> 1U))));
        bufp->chgBit(oldp+458,((1U & ((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__ridx_gray) 
                                      >> 2U))));
        bufp->chgBit(oldp+459,((1U & ((IData)(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__ridx_gray) 
                                      >> 3U))));
        bufp->chgBit(oldp+460,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT___io_enq_ready_output));
        bufp->chgCData(oldp+461,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__widx_gray),4);
        bufp->chgBit(oldp+462,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+463,((1U & (IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__widx_gray))));
        bufp->chgBit(oldp+464,((1U & ((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__widx_gray) 
                                      >> 1U))));
        bufp->chgBit(oldp+465,((1U & ((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__widx_gray) 
                                      >> 2U))));
        bufp->chgBit(oldp+466,((1U & ((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__widx_gray) 
                                      >> 3U))));
        bufp->chgCData(oldp+467,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__widx_widx_bin),4);
        bufp->chgBit(oldp+468,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__ready_reg));
        bufp->chgCData(oldp+469,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__index),3);
        bufp->chgCData(oldp+470,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__widx_incremented),4);
        bufp->chgCData(oldp+471,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__widx),4);
        bufp->chgCData(oldp+472,((((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0) 
                                   << 3U) | (((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0) 
                                              << 2U) 
                                             | (((IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                 << 1U) 
                                                | (IData)(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0))))),4);
        bufp->chgBit(oldp+473,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+474,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+475,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+476,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0));
        bufp->chgBit(oldp+477,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1));
        bufp->chgBit(oldp+478,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2));
        bufp->chgBit(oldp+479,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0));
        bufp->chgBit(oldp+480,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1));
        bufp->chgBit(oldp+481,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2));
        bufp->chgBit(oldp+482,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0));
        bufp->chgBit(oldp+483,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1));
        bufp->chgBit(oldp+484,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2));
        bufp->chgBit(oldp+485,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+486,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+487,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+488,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__sink_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+489,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__sink_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+490,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__sink_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+491,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+492,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+493,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+494,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+495,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+496,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)))));
        bufp->chgBit(oldp+497,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)))));
        bufp->chgBit(oldp+498,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)))));
        bufp->chgBit(oldp+499,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset));
        bufp->chgBit(oldp+500,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset)))));
        bufp->chgBit(oldp+501,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_0__DOT__reg_0));
        bufp->chgBit(oldp+502,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_1__DOT__reg_0));
        bufp->chgBit(oldp+503,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_10__DOT__reg_0));
        bufp->chgBit(oldp+504,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_11__DOT__reg_0));
        bufp->chgBit(oldp+505,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_6__DOT__reg_0));
        bufp->chgBit(oldp+506,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_7__DOT__reg_0));
        bufp->chgBit(oldp+507,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_8__DOT__reg_0));
        bufp->chgBit(oldp+508,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__regs_9__DOT__reg_0));
        bufp->chgBit(oldp+509,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_1__DOT__reg_0));
        bufp->chgBit(oldp+510,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_2__DOT__reg_0));
        bufp->chgBit(oldp+511,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_3__DOT__reg_0));
        bufp->chgBit(oldp+512,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_4__DOT__reg_0));
        bufp->chgBit(oldp+513,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_implicit_clock_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+514,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_implicit_clock_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+515,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_implicit_clock_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+516,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_cbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+517,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_cbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+518,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_cbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+519,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+520,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+521,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_fbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+522,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+523,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+524,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_mbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+525,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_pbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+526,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_pbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+527,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_pbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+528,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+529,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+530,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_0_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+531,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+532,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+533,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_2));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x1fU])) {
        bufp->chgBit(oldp+534,(vlSelf->TestHarness__DOT__chiptop__DOT__clock_en));
        bufp->chgBit(oldp+535,(vlSelf->TestHarness__DOT__chiptop__DOT__dmactiveAck_dmactiveAck__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+536,(vlSelf->TestHarness__DOT__chiptop__DOT__dmactiveAck_dmactiveAck__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+537,(vlSelf->TestHarness__DOT__chiptop__DOT__dmactiveAck_dmactiveAck__DOT__output_chain__DOT__sync_2));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x20U])) {
        bufp->chgBit(oldp+538,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource__DOT__reg_0__DOT__reg_0))));
        bufp->chgBit(oldp+539,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource__DOT__reg_0__DOT__reg_0) 
                                      >> 1U))));
        bufp->chgCData(oldp+540,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource__DOT__reg_0__DOT__reg_0),2);
        bufp->chgBit(oldp+541,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource_1__DOT__reg_0__DOT__reg_0));
        bufp->chgBit(oldp+542,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource_10__DOT__reg_0__DOT__reg_0));
        bufp->chgBit(oldp+543,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource_11__DOT__reg_0__DOT__reg_0));
        bufp->chgBit(oldp+544,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource_12__DOT__reg_0__DOT__reg_0))));
        bufp->chgBit(oldp+545,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource_12__DOT__reg_0__DOT__reg_0) 
                                      >> 1U))));
        bufp->chgCData(oldp+546,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource_12__DOT__reg_0__DOT__reg_0),2);
        bufp->chgBit(oldp+547,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource_13__DOT__reg_0__DOT__reg_0));
        bufp->chgBit(oldp+548,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource_14__DOT__reg_0__DOT__reg_0));
        bufp->chgBit(oldp+549,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource_2__DOT__reg_0__DOT__reg_0));
        bufp->chgBit(oldp+550,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource_3__DOT__reg_0__DOT__reg_0))));
        bufp->chgBit(oldp+551,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource_3__DOT__reg_0__DOT__reg_0) 
                                      >> 1U))));
        bufp->chgCData(oldp+552,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource_3__DOT__reg_0__DOT__reg_0),2);
        bufp->chgBit(oldp+553,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource_4__DOT__reg_0__DOT__reg_0));
        bufp->chgBit(oldp+554,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource_5__DOT__reg_0__DOT__reg_0));
        bufp->chgBit(oldp+555,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource_6__DOT__reg_0__DOT__reg_0))));
        bufp->chgBit(oldp+556,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource_6__DOT__reg_0__DOT__reg_0) 
                                      >> 1U))));
        bufp->chgCData(oldp+557,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource_6__DOT__reg_0__DOT__reg_0),2);
        bufp->chgBit(oldp+558,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource_7__DOT__reg_0__DOT__reg_0));
        bufp->chgBit(oldp+559,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource_8__DOT__reg_0__DOT__reg_0));
        bufp->chgBit(oldp+560,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource_9__DOT__reg_0__DOT__reg_0))));
        bufp->chgBit(oldp+561,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource_9__DOT__reg_0__DOT__reg_0) 
                                      >> 1U))));
        bufp->chgCData(oldp+562,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource_9__DOT__reg_0__DOT__reg_0),2);
        bufp->chgQData(oldp+563,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_WIRE),64);
        bufp->chgBit(oldp+565,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___csr_io_interrupt));
        bufp->chgQData(oldp+566,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___csr_io_interrupt_cause),64);
        bufp->chgQData(oldp+568,((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__read_mip))),64);
        bufp->chgQData(oldp+570,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT___io_shadow_read_12_T),64);
        bufp->chgSData(oldp+572,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__read_mip),16);
        bufp->chgQData(oldp+573,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__pending_interrupts),64);
        bufp->chgQData(oldp+575,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__wdata),64);
        bufp->chgBit(oldp+577,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___decode_units_0_io_deq_uop_exception));
        bufp->chgBit(oldp+578,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___decode_units_1_io_deq_uop_exception));
        bufp->chgBit(oldp+579,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___decode_units_2_io_deq_uop_exception));
        bufp->chgQData(oldp+580,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___GEN_34),64);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x21U])) {
        bufp->chgCData(oldp+582,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__mem_0_opcode),3);
        bufp->chgCData(oldp+583,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__mem_0_param),2);
        bufp->chgCData(oldp+584,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__mem_0_size),2);
        bufp->chgBit(oldp+585,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__mem_0_source));
        bufp->chgBit(oldp+586,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__mem_0_sink));
        bufp->chgBit(oldp+587,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__mem_0_denied));
        bufp->chgIData(oldp+588,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__mem_0_data),32);
        bufp->chgBit(oldp+589,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__mem_0_corrupt));
        bufp->chgBit(oldp+590,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 0x16U))));
        bufp->chgSData(oldp+591,((0x3ffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                            >> 0xcU))),10);
        bufp->chgBit(oldp+592,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 0xbU))));
        bufp->chgBit(oldp+593,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 0xaU))));
        bufp->chgBit(oldp+594,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 5U))));
        bufp->chgBit(oldp+595,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 6U))));
        bufp->chgBit(oldp+596,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 7U))));
        bufp->chgBit(oldp+597,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 8U))));
        bufp->chgBit(oldp+598,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 9U))));
        bufp->chgBit(oldp+599,((1U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg)));
        bufp->chgBit(oldp+600,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 1U))));
        bufp->chgBit(oldp+601,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 2U))));
        bufp->chgBit(oldp+602,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 3U))));
        bufp->chgBit(oldp+603,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                      >> 4U))));
        bufp->chgBit(oldp+604,((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__ctrlStateReg))));
        bufp->chgCData(oldp+605,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__resumeReqRegs),5);
        bufp->chgCData(oldp+606,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__haveResetBitRegs),5);
        bufp->chgCData(oldp+607,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__selectedHartReg),3);
        bufp->chgBit(oldp+608,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hamaskReg_0));
        bufp->chgBit(oldp+609,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hamaskReg_1));
        bufp->chgBit(oldp+610,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hamaskReg_2));
        bufp->chgBit(oldp+611,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hamaskReg_3));
        bufp->chgBit(oldp+612,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hamaskReg_4));
        bufp->chgBit(oldp+613,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hamaskWrSel_0));
        bufp->chgBit(oldp+614,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hamaskWrSel_1));
        bufp->chgBit(oldp+615,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hamaskWrSel_2));
        bufp->chgBit(oldp+616,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hamaskWrSel_3));
        bufp->chgBit(oldp+617,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hamaskWrSel_4));
        bufp->chgBit(oldp+618,((4U < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__selectedHartReg))));
        bufp->chgCData(oldp+619,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__ABSTRACTCSReg_cmderr),3);
        bufp->chgSData(oldp+620,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__ABSTRACTAUTOReg_autoexecprogbuf),16);
        bufp->chgSData(oldp+621,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__ABSTRACTAUTOReg_autoexecdata),12);
        bufp->chgCData(oldp+622,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__COMMANDRdData_cmdtype),8);
        bufp->chgIData(oldp+623,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__COMMANDRdData_control),24);
        bufp->chgCData(oldp+624,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_0),8);
        bufp->chgCData(oldp+625,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_1),8);
        bufp->chgCData(oldp+626,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_2),8);
        bufp->chgCData(oldp+627,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_3),8);
        bufp->chgCData(oldp+628,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_4),8);
        bufp->chgCData(oldp+629,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_5),8);
        bufp->chgCData(oldp+630,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_6),8);
        bufp->chgCData(oldp+631,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractDataMem_7),8);
        bufp->chgCData(oldp+632,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_0),8);
        bufp->chgCData(oldp+633,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_1),8);
        bufp->chgCData(oldp+634,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_2),8);
        bufp->chgCData(oldp+635,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_3),8);
        bufp->chgCData(oldp+636,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_4),8);
        bufp->chgCData(oldp+637,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_5),8);
        bufp->chgCData(oldp+638,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_6),8);
        bufp->chgCData(oldp+639,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_7),8);
        bufp->chgCData(oldp+640,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_8),8);
        bufp->chgCData(oldp+641,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_9),8);
        bufp->chgCData(oldp+642,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_10),8);
        bufp->chgCData(oldp+643,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_11),8);
        bufp->chgCData(oldp+644,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_12),8);
        bufp->chgCData(oldp+645,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_13),8);
        bufp->chgCData(oldp+646,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_14),8);
        bufp->chgCData(oldp+647,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_15),8);
        bufp->chgCData(oldp+648,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_16),8);
        bufp->chgCData(oldp+649,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_17),8);
        bufp->chgCData(oldp+650,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_18),8);
        bufp->chgCData(oldp+651,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_19),8);
        bufp->chgCData(oldp+652,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_20),8);
        bufp->chgCData(oldp+653,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_21),8);
        bufp->chgCData(oldp+654,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_22),8);
        bufp->chgCData(oldp+655,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_23),8);
        bufp->chgCData(oldp+656,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_24),8);
        bufp->chgCData(oldp+657,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_25),8);
        bufp->chgCData(oldp+658,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_26),8);
        bufp->chgCData(oldp+659,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_27),8);
        bufp->chgCData(oldp+660,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_28),8);
        bufp->chgCData(oldp+661,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_29),8);
        bufp->chgCData(oldp+662,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_30),8);
        bufp->chgCData(oldp+663,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_31),8);
        bufp->chgCData(oldp+664,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_32),8);
        bufp->chgCData(oldp+665,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_33),8);
        bufp->chgCData(oldp+666,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_34),8);
        bufp->chgCData(oldp+667,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_35),8);
        bufp->chgCData(oldp+668,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_36),8);
        bufp->chgCData(oldp+669,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_37),8);
        bufp->chgCData(oldp+670,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_38),8);
        bufp->chgCData(oldp+671,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_39),8);
        bufp->chgCData(oldp+672,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_40),8);
        bufp->chgCData(oldp+673,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_41),8);
        bufp->chgCData(oldp+674,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_42),8);
        bufp->chgCData(oldp+675,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_43),8);
        bufp->chgCData(oldp+676,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_44),8);
        bufp->chgCData(oldp+677,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_45),8);
        bufp->chgCData(oldp+678,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_46),8);
        bufp->chgCData(oldp+679,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_47),8);
        bufp->chgCData(oldp+680,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_48),8);
        bufp->chgCData(oldp+681,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_49),8);
        bufp->chgCData(oldp+682,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_50),8);
        bufp->chgCData(oldp+683,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_51),8);
        bufp->chgCData(oldp+684,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_52),8);
        bufp->chgCData(oldp+685,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_53),8);
        bufp->chgCData(oldp+686,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_54),8);
        bufp->chgCData(oldp+687,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_55),8);
        bufp->chgCData(oldp+688,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_56),8);
        bufp->chgCData(oldp+689,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_57),8);
        bufp->chgCData(oldp+690,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_58),8);
        bufp->chgCData(oldp+691,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_59),8);
        bufp->chgCData(oldp+692,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_60),8);
        bufp->chgCData(oldp+693,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_61),8);
        bufp->chgCData(oldp+694,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_62),8);
        bufp->chgCData(oldp+695,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__programBufferMem_63),8);
        bufp->chgBit(oldp+696,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__goReg));
        bufp->chgIData(oldp+697,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractGeneratedMem_0),32);
        bufp->chgIData(oldp+698,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__abstractGeneratedMem_1),32);
        bufp->chgCData(oldp+699,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__ctrlStateReg),2);
        bufp->chgBit(oldp+700,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__COMMANDRdData_cmdtype))));
        bufp->chgBit(oldp+701,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor__DOT__inflight));
        bufp->chgCData(oldp+702,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor__DOT__inflight_opcodes),4);
        bufp->chgCData(oldp+703,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor__DOT__inflight_sizes),4);
        bufp->chgIData(oldp+704,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor__DOT__watchdog),32);
        bufp->chgWData(oldp+705,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__inflight),1040);
        bufp->chgWData(oldp+738,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__inflight_opcodes),4160);
        bufp->chgWData(oldp+868,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__inflight_sizes),4160);
        bufp->chgIData(oldp+998,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor_1__DOT__watchdog),32);
        bufp->chgIData(oldp+999,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg),23);
        bufp->chgQData(oldp+1000,((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__mem_0_opcode)) 
                                    << 0x28U) | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__mem_0_param)) 
                                                  << 0x26U) 
                                                 | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__mem_0_size)) 
                                                     << 0x24U) 
                                                    | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__mem_0_source)) 
                                                        << 0x23U) 
                                                       | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__mem_0_sink)) 
                                                           << 0x22U) 
                                                          | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__mem_0_denied)) 
                                                              << 0x21U) 
                                                             | (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__mem_0_data)) 
                                                                 << 1U) 
                                                                | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__mem_0_corrupt)))))))))),43);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x22U])) {
        bufp->chgBit(oldp+1002,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__ridx_gray));
        bufp->chgBit(oldp+1003,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__widx_gray));
        bufp->chgBit(oldp+1004,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__ridx_gray));
        bufp->chgBit(oldp+1005,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hgParticipateHart_0) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hgFired_1)) 
                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hrDebugIntReg_0))));
        bufp->chgBit(oldp+1006,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hgParticipateHart_1) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hgFired_1)) 
                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hrDebugIntReg_1))));
        bufp->chgBit(oldp+1007,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hgParticipateHart_2) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hgFired_1)) 
                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hrDebugIntReg_2))));
        bufp->chgBit(oldp+1008,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hgParticipateHart_3) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hgFired_1)) 
                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hrDebugIntReg_3))));
        bufp->chgBit(oldp+1009,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hgParticipateHart_4) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hgFired_1)) 
                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hrDebugIntReg_4))));
        bufp->chgBit(oldp+1010,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT___io_deq_valid_output));
        bufp->chgBit(oldp+1011,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT___io_enq_ready_output));
        bufp->chgBit(oldp+1012,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmactive_synced_dmactiveSync__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+1013,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT___io_deq_valid_output));
        bufp->chgCData(oldp+1014,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__resumeAcks),5);
        bufp->chgBit(oldp+1015,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hrDebugIntReg_0));
        bufp->chgBit(oldp+1016,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hrDebugIntReg_1));
        bufp->chgBit(oldp+1017,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hrDebugIntReg_2));
        bufp->chgBit(oldp+1018,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hrDebugIntReg_3));
        bufp->chgBit(oldp+1019,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hrDebugIntReg_4));
        bufp->chgBit(oldp+1020,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__resumereq));
        bufp->chgBit(oldp+1021,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hgParticipateHart_0));
        bufp->chgBit(oldp+1022,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hgParticipateHart_1));
        bufp->chgBit(oldp+1023,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hgParticipateHart_2));
        bufp->chgBit(oldp+1024,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hgParticipateHart_3));
        bufp->chgBit(oldp+1025,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hgParticipateHart_4));
        bufp->chgBit(oldp+1026,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hgFired_1));
        bufp->chgBit(oldp+1027,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hartIsInResetSync_0_debug_hartReset_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+1028,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hartIsInResetSync_0_debug_hartReset_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+1029,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hartIsInResetSync_0_debug_hartReset_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+1030,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hartIsInResetSync_1_debug_hartReset_1__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+1031,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hartIsInResetSync_1_debug_hartReset_1__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+1032,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hartIsInResetSync_1_debug_hartReset_1__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+1033,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hartIsInResetSync_2_debug_hartReset_2__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+1034,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hartIsInResetSync_2_debug_hartReset_2__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+1035,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hartIsInResetSync_2_debug_hartReset_2__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+1036,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hartIsInResetSync_3_debug_hartReset_3__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+1037,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hartIsInResetSync_3_debug_hartReset_3__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+1038,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hartIsInResetSync_3_debug_hartReset_3__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+1039,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hartIsInResetSync_4_debug_hartReset_4__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+1040,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hartIsInResetSync_4_debug_hartReset_4__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+1041,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hartIsInResetSync_4_debug_hartReset_4__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+1042,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor__DOT__a_first_done));
        bufp->chgBit(oldp+1043,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__monitor__DOT__d_first_done));
        bufp->chgBit(oldp+1044,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__ridx_ridx_bin));
        bufp->chgBit(oldp+1045,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__ridx_incremented));
        bufp->chgBit(oldp+1046,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__valid));
        bufp->chgBit(oldp+1047,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__valid_reg));
        bufp->chgBit(oldp+1048,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__source_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+1049,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__source_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+1050,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__source_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+1051,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+1052,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+1053,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmInner_io_innerCtrl_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+1054,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmactive_synced_dmactiveSync__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+1055,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmactive_synced_dmactive_synced_dmactiveSync__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+1056,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__widx_widx_bin));
        bufp->chgBit(oldp+1057,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__ready_reg));
        bufp->chgBit(oldp+1058,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__widx_incremented));
        bufp->chgBit(oldp+1059,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+1060,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+1061,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+1062,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__sink_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+1063,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__sink_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+1064,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__bundleIn_0_d_source__DOT__sink_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+1065,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__ridx_ridx_bin));
        bufp->chgBit(oldp+1066,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__ridx_incremented));
        bufp->chgBit(oldp+1067,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__valid_reg));
        bufp->chgBit(oldp+1068,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__source_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+1069,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__source_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+1070,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__source_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+1071,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+1072,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+1073,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmiXing__DOT__x1_a_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_2));
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[0x22U] 
                     | vlSelf->__Vm_traceActivity[0x26U]))) {
        bufp->chgBit(oldp+1074,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__debugIntRegs_0) 
                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hgParticipateHart_0) 
                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hgFired_1)) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hrDebugIntReg_0)))));
        bufp->chgBit(oldp+1075,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__debugIntRegs_1) 
                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hgParticipateHart_1) 
                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hgFired_1)) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hrDebugIntReg_1)))));
        bufp->chgBit(oldp+1076,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__debugIntRegs_2) 
                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hgParticipateHart_2) 
                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hgFired_1)) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hrDebugIntReg_2)))));
        bufp->chgBit(oldp+1077,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__debugIntRegs_3) 
                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hgParticipateHart_3) 
                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hgFired_1)) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hrDebugIntReg_3)))));
        bufp->chgBit(oldp+1078,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__debugIntRegs_4) 
                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hgParticipateHart_4) 
                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hgFired_1)) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmInner__DOT__dmInner__DOT__hrDebugIntReg_4)))));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x23U])) {
        bufp->chgBit(oldp+1079,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__bundleIn_0_d_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+1080,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__bundleIn_0_d_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+1081,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__bundleIn_0_d_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+1082,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+1083,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+1084,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+1085,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+1086,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+1087,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x24U])) {
        bufp->chgBit(oldp+1088,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_0));
        bufp->chgCData(oldp+1089,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_40) 
                                    << 6U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_39) 
                                               << 5U) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_38) 
                                                  << 4U) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_37) 
                                                     << 3U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_36) 
                                                        << 2U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_35) 
                                                           << 1U) 
                                                          | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_34)))))))),7);
        bufp->chgIData(oldp+1090,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_33) 
                                    << 0x1fU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_32) 
                                                  << 0x1eU) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_31) 
                                                     << 0x1dU) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_30) 
                                                        << 0x1cU) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_29) 
                                                           << 0x1bU) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_28) 
                                                              << 0x1aU) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_27) 
                                                                 << 0x19U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_26) 
                                                                    << 0x18U) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_25) 
                                                                       << 0x17U) 
                                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_24) 
                                                                          << 0x16U) 
                                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_23) 
                                                                             << 0x15U) 
                                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_22) 
                                                                                << 0x14U) 
                                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_21) 
                                                                                << 0x13U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_20) 
                                                                                << 0x12U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_19) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_18) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_17) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_16) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_15) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_14) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_13) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_12) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_11) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_10) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_9) 
                                                                                << 7U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_8) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_7) 
                                                                                << 5U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_6) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_5) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_4) 
                                                                                << 2U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_3) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_2))))))))))))))))))))))))))))))))),32);
        bufp->chgCData(oldp+1091,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT___dmiAccessChain_io_update_bits_op),2);
        bufp->chgBit(oldp+1092,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_1));
        bufp->chgBit(oldp+1093,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_2));
        bufp->chgBit(oldp+1094,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_3));
        bufp->chgBit(oldp+1095,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_4));
        bufp->chgBit(oldp+1096,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_5));
        bufp->chgBit(oldp+1097,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_6));
        bufp->chgBit(oldp+1098,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_7));
        bufp->chgBit(oldp+1099,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_8));
        bufp->chgBit(oldp+1100,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_9));
        bufp->chgBit(oldp+1101,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_10));
        bufp->chgBit(oldp+1102,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_11));
        bufp->chgBit(oldp+1103,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_12));
        bufp->chgBit(oldp+1104,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_13));
        bufp->chgBit(oldp+1105,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_14));
        bufp->chgBit(oldp+1106,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_15));
        bufp->chgBit(oldp+1107,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_16));
        bufp->chgBit(oldp+1108,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_17));
        bufp->chgBit(oldp+1109,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_18));
        bufp->chgBit(oldp+1110,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_19));
        bufp->chgBit(oldp+1111,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_20));
        bufp->chgBit(oldp+1112,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_21));
        bufp->chgBit(oldp+1113,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_22));
        bufp->chgBit(oldp+1114,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_23));
        bufp->chgBit(oldp+1115,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_24));
        bufp->chgBit(oldp+1116,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_25));
        bufp->chgBit(oldp+1117,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_26));
        bufp->chgBit(oldp+1118,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_27));
        bufp->chgBit(oldp+1119,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_28));
        bufp->chgBit(oldp+1120,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_29));
        bufp->chgBit(oldp+1121,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_30));
        bufp->chgBit(oldp+1122,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_31));
        bufp->chgBit(oldp+1123,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_32));
        bufp->chgBit(oldp+1124,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_33));
        bufp->chgBit(oldp+1125,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_34));
        bufp->chgBit(oldp+1126,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_35));
        bufp->chgBit(oldp+1127,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_36));
        bufp->chgBit(oldp+1128,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_37));
        bufp->chgBit(oldp+1129,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_38));
        bufp->chgBit(oldp+1130,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_39));
        bufp->chgBit(oldp+1131,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dmiAccessChain__DOT__regs_40));
        bufp->chgBit(oldp+1132,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__dtmInfoChain__DOT__regs_0));
        bufp->chgBit(oldp+1133,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_bypassChain__DOT__reg_0));
        bufp->chgBit(oldp+1134,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_0));
        bufp->chgBit(oldp+1135,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_1));
        bufp->chgBit(oldp+1136,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_2));
        bufp->chgBit(oldp+1137,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_3));
        bufp->chgBit(oldp+1138,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_4));
        bufp->chgBit(oldp+1139,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_5));
        bufp->chgBit(oldp+1140,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_6));
        bufp->chgBit(oldp+1141,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_7));
        bufp->chgBit(oldp+1142,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_8));
        bufp->chgBit(oldp+1143,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_9));
        bufp->chgBit(oldp+1144,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_10));
        bufp->chgBit(oldp+1145,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_11));
        bufp->chgBit(oldp+1146,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_12));
        bufp->chgBit(oldp+1147,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_13));
        bufp->chgBit(oldp+1148,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_14));
        bufp->chgBit(oldp+1149,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_15));
        bufp->chgBit(oldp+1150,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_16));
        bufp->chgBit(oldp+1151,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_17));
        bufp->chgBit(oldp+1152,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_18));
        bufp->chgBit(oldp+1153,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_19));
        bufp->chgBit(oldp+1154,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_20));
        bufp->chgBit(oldp+1155,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_21));
        bufp->chgBit(oldp+1156,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_22));
        bufp->chgBit(oldp+1157,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_23));
        bufp->chgBit(oldp+1158,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_24));
        bufp->chgBit(oldp+1159,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_25));
        bufp->chgBit(oldp+1160,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_26));
        bufp->chgBit(oldp+1161,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_27));
        bufp->chgBit(oldp+1162,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_28));
        bufp->chgBit(oldp+1163,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_29));
        bufp->chgBit(oldp+1164,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_30));
        bufp->chgBit(oldp+1165,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__dtm__DOT__tapIO_idcodeChain__DOT__regs_31));
        bufp->chgBit(oldp+1166,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_resumereq));
        bufp->chgSData(oldp+1167,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_hartsel),10);
        bufp->chgBit(oldp+1168,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_ackhavereset));
        bufp->chgBit(oldp+1169,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_hasel));
        bufp->chgBit(oldp+1170,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_hamask_0));
        bufp->chgBit(oldp+1171,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_hamask_1));
        bufp->chgBit(oldp+1172,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_hamask_2));
        bufp->chgBit(oldp+1173,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_hamask_3));
        bufp->chgBit(oldp+1174,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_hamask_4));
        bufp->chgBit(oldp+1175,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_hrmask_0));
        bufp->chgBit(oldp+1176,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_hrmask_1));
        bufp->chgBit(oldp+1177,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_hrmask_2));
        bufp->chgBit(oldp+1178,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_hrmask_3));
        bufp->chgBit(oldp+1179,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_hrmask_4));
        bufp->chgIData(oldp+1180,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_resumereq) 
                                    << 0x16U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_hartsel) 
                                                  << 0xcU) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_ackhavereset) 
                                                     << 0xbU) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_hasel) 
                                                        << 0xaU) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_hamask_4) 
                                                           << 9U) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_hamask_3) 
                                                              << 8U) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_hamask_2) 
                                                                 << 7U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_hamask_1) 
                                                                    << 6U) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_hamask_0) 
                                                                       << 5U) 
                                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_hrmask_4) 
                                                                          << 4U) 
                                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_hrmask_3) 
                                                                             << 3U) 
                                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_hrmask_2) 
                                                                                << 2U) 
                                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_hrmask_1) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__mem_0_hrmask_0))))))))))))))),23);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x25U])) {
        bufp->chgWData(oldp+1181,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_0),273);
        bufp->chgIData(oldp+1190,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_status_outs_0),32);
        bufp->chgIData(oldp+1191,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_l_rctrl_0),22);
        bufp->chgCData(oldp+1192,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__sink__DOT__ridx_gray),4);
        bufp->chgCData(oldp+1193,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__sink__DOT__ridx),4);
        bufp->chgBit(oldp+1194,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__sink__DOT__valid));
        bufp->chgBit(oldp+1195,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+1196,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__sink__DOT__ridx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+1197,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__sink__DOT__ridx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+1198,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__sink__DOT__ridx_gray) 
                                       >> 3U))));
        bufp->chgCData(oldp+1199,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__sink__DOT__ridx_gray),7);
        bufp->chgCData(oldp+1200,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__sink__DOT__ridx),7);
        bufp->chgBit(oldp+1201,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__sink__DOT__valid));
        bufp->chgBit(oldp+1202,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+1203,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__sink__DOT__ridx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+1204,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__sink__DOT__ridx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+1205,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__sink__DOT__ridx_gray) 
                                       >> 3U))));
        bufp->chgBit(oldp+1206,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__sink__DOT__ridx_gray) 
                                       >> 4U))));
        bufp->chgBit(oldp+1207,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__sink__DOT__ridx_gray) 
                                       >> 5U))));
        bufp->chgBit(oldp+1208,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__sink__DOT__ridx_gray) 
                                       >> 6U))));
        bufp->chgSData(oldp+1209,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__sink__DOT__ridx_gray),9);
        bufp->chgSData(oldp+1210,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__sink__DOT__ridx_incremented),9);
        bufp->chgSData(oldp+1211,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__sink__DOT__ridx),9);
        bufp->chgBit(oldp+1212,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__sink__DOT__valid));
        bufp->chgBit(oldp+1213,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+1214,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__sink__DOT__ridx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+1215,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__sink__DOT__ridx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+1216,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__sink__DOT__ridx_gray) 
                                       >> 3U))));
        bufp->chgBit(oldp+1217,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__sink__DOT__ridx_gray) 
                                       >> 4U))));
        bufp->chgBit(oldp+1218,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__sink__DOT__ridx_gray) 
                                       >> 5U))));
        bufp->chgBit(oldp+1219,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__sink__DOT__ridx_gray) 
                                       >> 6U))));
        bufp->chgBit(oldp+1220,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__sink__DOT__ridx_gray) 
                                       >> 7U))));
        bufp->chgBit(oldp+1221,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__sink__DOT__ridx_gray) 
                                       >> 8U))));
        bufp->chgCData(oldp+1222,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__widx_gray),7);
        bufp->chgBit(oldp+1223,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__widx_gray))));
        bufp->chgBit(oldp+1224,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__widx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+1225,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__widx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+1226,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__widx_gray) 
                                       >> 3U))));
        bufp->chgBit(oldp+1227,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__widx_gray) 
                                       >> 4U))));
        bufp->chgBit(oldp+1228,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__widx_gray) 
                                       >> 5U))));
        bufp->chgBit(oldp+1229,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__widx_gray) 
                                       >> 6U))));
        bufp->chgCData(oldp+1230,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__index),6);
        bufp->chgCData(oldp+1231,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__widx_incremented),7);
        bufp->chgCData(oldp+1232,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__widx),7);
        bufp->chgCData(oldp+1233,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__widx_gray),4);
        bufp->chgCData(oldp+1234,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx_gray),4);
        bufp->chgCData(oldp+1235,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__widx_gray),4);
        bufp->chgCData(oldp+1236,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_gray),4);
        bufp->chgBit(oldp+1237,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+1238,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+1239,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+1240,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx_gray) 
                                       >> 3U))));
        bufp->chgBit(oldp+1241,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+1242,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+1243,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+1244,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_gray) 
                                       >> 3U))));
        bufp->chgBit(oldp+1245,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__widx_gray))));
        bufp->chgBit(oldp+1246,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__widx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+1247,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__widx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+1248,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__widx_gray) 
                                       >> 3U))));
        bufp->chgBit(oldp+1249,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__widx_gray))));
        bufp->chgBit(oldp+1250,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__widx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+1251,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__widx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+1252,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__widx_gray) 
                                       >> 3U))));
        bufp->chgWData(oldp+1253,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT____Vcellinp__tile_prci_domain_1__auto_tile_reset_domain_tile_core_r_arfs_c_sk_in),145);
        bufp->chgIData(oldp+1258,((0xffffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_l_rctrl_0 
                                              >> 6U))),20);
        bufp->chgBit(oldp+1259,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT___io_enq_ready_output));
        bufp->chgBit(oldp+1260,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT___io_deq_valid_output));
        bufp->chgBit(oldp+1261,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT___io_enq_ready_output));
        bufp->chgBit(oldp+1262,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT___io_deq_valid_output));
        bufp->chgBit(oldp+1263,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT___io_enq_ready_output));
        bufp->chgCData(oldp+1264,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__index),3);
        bufp->chgCData(oldp+1265,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__widx_incremented),4);
        bufp->chgCData(oldp+1266,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__widx),4);
        bufp->chgCData(oldp+1267,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__index),3);
        bufp->chgCData(oldp+1268,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__widx_incremented),4);
        bufp->chgCData(oldp+1269,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__widx),4);
        bufp->chgBit(oldp+1270,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptype_rcu));
        __Vtemp_hbc54b0fd__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_0[0U];
        __Vtemp_hbc54b0fd__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_0[1U];
        __Vtemp_hbc54b0fd__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_0[2U];
        __Vtemp_hbc54b0fd__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_0[3U];
        __Vtemp_hbc54b0fd__0[4U] = (0xffU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_0[4U]);
        bufp->chgWData(oldp+1271,(__Vtemp_hbc54b0fd__0),136);
        __Vtemp_hf1427b78__0[0U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_0[5U] 
                                     << 0x18U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_0[4U] 
                                                  >> 8U));
        __Vtemp_hf1427b78__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_0[6U] 
                                     << 0x18U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_0[5U] 
                                                  >> 8U));
        __Vtemp_hf1427b78__0[2U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_0[7U] 
                                     << 0x18U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_0[6U] 
                                                  >> 8U));
        __Vtemp_hf1427b78__0[3U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_0[8U] 
                                     << 0x18U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_0[7U] 
                                                  >> 8U));
        __Vtemp_hf1427b78__0[4U] = (0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_0[8U] 
                                             >> 8U));
        bufp->chgWData(oldp+1276,(__Vtemp_hf1427b78__0),136);
        bufp->chgCData(oldp+1281,((0xffU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_0[4U])),8);
        bufp->chgCData(oldp+1282,((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_0[8U] 
                                            >> 8U))),8);
        bufp->chgWData(oldp+1283,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0),136);
        bufp->chgWData(oldp+1288,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1),136);
        bufp->chgWData(oldp+1293,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_0),128);
        bufp->chgWData(oldp+1297,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_1),128);
        bufp->chgBit(oldp+1301,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_valid));
        bufp->chgBit(oldp+1302,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___refill_fire_T));
        bufp->chgBit(oldp+1303,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_requestor_2_s2_nack));
        bufp->chgBit(oldp+1304,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT____Vcellinp__core__io_arfs_if_CPS));
        bufp->chgWData(oldp+1305,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT____Vcellinp__core__io_packet_arfs),144);
        bufp->chgBit(oldp+1310,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem_wb));
        bufp->chgQData(oldp+1311,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_req_bits_pc_output),40);
        bufp->chgBit(oldp+1313,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_imem_btb_update_valid));
        bufp->chgQData(oldp+1314,((0x7fffffffffULL 
                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_req_bits_pc_output)),39);
        bufp->chgBit(oldp+1316,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_wrong_npc));
        bufp->chgBit(oldp+1317,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_imem_if_check_already_done));
        bufp->chgBit(oldp+1318,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___io_fpu_retire_T));
        bufp->chgBit(oldp+1319,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___icsl_io_if_overtaking_next_cycle));
        bufp->chgBit(oldp+1320,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_wb));
        bufp->chgBit(oldp+1321,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem));
        bufp->chgBit(oldp+1322,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl_req_valid_csr));
        bufp->chgBit(oldp+1323,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl_req_valid_csr_test));
        bufp->chgBit(oldp+1324,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__replay_wb_common));
        bufp->chgBit(oldp+1325,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__replay_wb));
        bufp->chgBit(oldp+1326,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_valid));
        bufp->chgBit(oldp+1327,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ll_wen));
        bufp->chgBit(oldp+1328,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_wen));
        bufp->chgBit(oldp+1329,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen));
        bufp->chgCData(oldp+1330,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr),5);
        bufp->chgQData(oldp+1331,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata),64);
        bufp->chgBit(oldp+1333,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__arfs_is_CSR));
        bufp->chgBit(oldp+1334,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__arfs_is_ARFS));
        bufp->chgQData(oldp+1335,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__id_rs_0),64);
        bufp->chgQData(oldp+1337,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__id_rs_1),64);
        bufp->chgBit(oldp+1339,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__priv_cps_done));
        bufp->chgWData(oldp+1340,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_csr_shadows),128);
        bufp->chgCData(oldp+1344,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_shadow_idx),7);
        bufp->chgBit(oldp+1345,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___csr_io_trace_0_valid));
        bufp->chgCData(oldp+1346,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__nextSmall),7);
        bufp->chgCData(oldp+1347,((0xeU & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_shadow_idx) 
                                            - (IData)(1U)) 
                                           << 1U))),4);
        bufp->chgBit(oldp+1348,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_1));
        bufp->chgQData(oldp+1349,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_csr_shadows[1U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_csr_shadows[0U])))),64);
        bufp->chgCData(oldp+1351,((0xfU & ((IData)(1U) 
                                           + (0xeU 
                                              & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_shadow_idx) 
                                                  - (IData)(1U)) 
                                                 << 1U))))),4);
        bufp->chgQData(oldp+1352,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_csr_shadows[3U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_csr_shadows[2U])))),64);
        bufp->chgBit(oldp+1354,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_valid));
        bufp->chgBit(oldp+1355,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_replay));
        bufp->chgCData(oldp+1356,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__nReady),2);
        bufp->chgCData(oldp+1357,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__nICReady),2);
        bufp->chgCData(oldp+1358,((3U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT___valid_T) 
                                         - (IData)(1U)))),2);
        bufp->chgCData(oldp+1359,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ic_replay),2);
        bufp->chgBit(oldp+1360,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__full_insn));
        bufp->chgSData(oldp+1361,((0xffffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_l_rctrl_0 
                                              >> 6U))),16);
        bufp->chgBit(oldp+1362,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__icsl__io_new_commit));
        bufp->chgBit(oldp+1363,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__icsl__io_returned_to_special_address_valid));
        bufp->chgBit(oldp+1364,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__if_completion));
        bufp->chgBit(oldp+1365,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__if_completion_priv));
        bufp->chgBit(oldp+1366,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__if_just_overtaking));
        bufp->chgBit(oldp+1367,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__if_just_overtaking_priv));
        bufp->chgBit(oldp+1368,((1U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[4U]))));
        bufp->chgBit(oldp+1369,((1U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[4U]))));
        bufp->chgBit(oldp+1370,((2U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[4U]))));
        bufp->chgBit(oldp+1371,((2U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[4U]))));
        bufp->chgQData(oldp+1372,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[3U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[2U])))),64);
        bufp->chgQData(oldp+1374,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[3U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[2U])))),64);
        bufp->chgQData(oldp+1376,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[1U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[0U])))),64);
        bufp->chgQData(oldp+1378,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[1U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[0U])))),64);
        bufp->chgBit(oldp+1380,((3U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[4U]))));
        bufp->chgBit(oldp+1381,((3U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[4U]))));
        bufp->chgBit(oldp+1382,((5U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[4U]))));
        bufp->chgBit(oldp+1383,((5U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[4U]))));
        bufp->chgBit(oldp+1384,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_deq_valid_0));
        bufp->chgBit(oldp+1385,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_deq_valid_1));
        bufp->chgCData(oldp+1386,((0x1fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))),5);
        bufp->chgCData(oldp+1387,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__arfs_is_CSR)
                                    ? (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT____Vcellinp__core__io_packet_arfs[4U] 
                                             >> 6U))
                                    : 0U)),2);
        bufp->chgWData(oldp+1388,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__rsu_slave__io_arfs_merge),128);
        bufp->chgCData(oldp+1392,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__rsu_slave__io_arfs_index),7);
        bufp->chgBit(oldp+1393,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__if_RSU_packet));
        bufp->chgBit(oldp+1394,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__if_RSU_packet_ECP));
        bufp->chgCData(oldp+1395,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr),6);
        bufp->chgBit(oldp+1396,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_requestor_1_s2_nack));
        bufp->chgBit(oldp+1397,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcIF__DOT____Vcellinp__replayq__io_nack_valid));
        bufp->chgBit(oldp+1398,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nack_head));
        bufp->chgBit(oldp+1399,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcIF__DOT____Vcellinp__replayq__io_nack_valid) 
                                 & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nack_head)))));
        bufp->chgBit(oldp+1400,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__do_enq));
        bufp->chgBit(oldp+1401,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__portsAOI_filtered_0_ready));
        bufp->chgBit(oldp+1402,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid));
        bufp->chgBit(oldp+1403,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_nack_output));
        bufp->chgBit(oldp+1404,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_in_2_valid));
        bufp->chgBit(oldp+1405,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_in_6_valid));
        bufp->chgBit(oldp+1406,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_nack));
        bufp->chgBit(oldp+1407,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__releaseDone));
        bufp->chgBit(oldp+1408,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__releaseRejected));
        bufp->chgSData(oldp+1409,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__releaseDataBeat),10);
        bufp->chgBit(oldp+1410,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_valid_not_nacked));
        bufp->chgBit(oldp+1411,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_meta_clk_en));
        bufp->chgBit(oldp+1412,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__portsAOI_filtered_1_0_ready));
        bufp->chgQData(oldp+1413,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___io_cpu_npc_output),40);
        bufp->chgQData(oldp+1415,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__predicted_npc),40);
        bufp->chgBit(oldp+1417,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__bjl_use_target));
        bufp->chgBit(oldp+1418,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_redirect));
        bufp->chgBit(oldp+1419,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s0_valid));
        bufp->chgQData(oldp+1420,((0xffffffffffULL 
                                   & (~ (3ULL | (~ 
                                                 (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[0U])))))))),40);
        bufp->chgQData(oldp+1422,((0xffffffffffULL 
                                   & (~ (3ULL | (~ 
                                                 (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                   << 0x38U) 
                                                  | (((QData)((IData)(
                                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                      << 0x18U) 
                                                     | ((QData)((IData)(
                                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                                        >> 8U)))))))),40);
        bufp->chgQData(oldp+1424,((0xffffffffffULL 
                                   & (~ (1ULL | (~ 
                                                 (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                   << 0x38U) 
                                                  | (((QData)((IData)(
                                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                      << 0x18U) 
                                                     | ((QData)((IData)(
                                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                                        >> 8U)))))))),40);
        bufp->chgBit(oldp+1426,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__bjl_need_replay));
        bufp->chgBit(oldp+1427,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__bjl_redirect_replay));
        bufp->chgBit(oldp+1428,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_replay));
        bufp->chgBit(oldp+1429,((0U != (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_0[0U] 
                                          | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_0[1U]) 
                                         | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_0[2U]) 
                                        | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_0[3U]))));
        bufp->chgBit(oldp+1430,((0U != (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_1[0U] 
                                          | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_1[1U]) 
                                         | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_1[2U]) 
                                        | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_1[3U]))));
        bufp->chgBit(oldp+1431,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___BJL_io_bj_rollback_T_2));
        bufp->chgBit(oldp+1432,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__BJL__io_bj_s2_replay));
        bufp->chgBit(oldp+1433,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___io_bj_req_ready_output));
        bufp->chgQData(oldp+1434,((0xffffffffffULL 
                                   & (((QData)((IData)(
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[0U]))))),40);
        bufp->chgQData(oldp+1436,((0xffffffffffULL 
                                   & (((QData)((IData)(
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                       << 0x18U) | 
                                      ((QData)((IData)(
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                       >> 8U)))),40);
        bufp->chgBit(oldp+1438,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U] 
                                       >> 0x10U))));
        bufp->chgBit(oldp+1439,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U] 
                                       >> 0x11U))));
        bufp->chgWData(oldp+1440,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_data_0),82);
        bufp->chgWData(oldp+1443,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_data_1),82);
        bufp->chgCData(oldp+1446,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_offset_sum_1),2);
        bufp->chgCData(oldp+1447,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_offset_1),2);
        bufp->chgBit(oldp+1448,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_OH_0));
        bufp->chgBit(oldp+1449,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_OH_1));
        bufp->chgBit(oldp+1450,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__has_enq));
        bufp->chgBit(oldp+1451,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_OH_0_1));
        bufp->chgBit(oldp+1452,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_OH_1_1));
        bufp->chgBit(oldp+1453,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__has_enq_1));
        bufp->chgBit(oldp+1454,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__reserve_fire));
        bufp->chgBit(oldp+1455,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__commit_fire));
        bufp->chgCData(oldp+1456,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__sum),2);
        bufp->chgWData(oldp+1457,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT____Vcellinp__u_channel_bj_0__io_enq_bits),82);
        bufp->chgBit(oldp+1460,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__do_enq));
        bufp->chgWData(oldp+1461,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT____Vcellinp__u_channel_bj_1__io_enq_bits),82);
        bufp->chgBit(oldp+1464,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__do_enq));
        bufp->chgBit(oldp+1465,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__btb__io_btb_update_valid));
        bufp->chgBit(oldp+1466,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__btb__io_bht_update_valid));
        bufp->chgBit(oldp+1467,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__btb__io_ras_update_valid));
        bufp->chgBit(oldp+1468,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___fq_io_enq_valid_T_8));
        bufp->chgQData(oldp+1469,((0x7fffffffffULL 
                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___io_cpu_npc_output)),39);
        bufp->chgBit(oldp+1471,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__invalidate));
        bufp->chgBit(oldp+1472,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__tlb__io_req_valid));
        bufp->chgBit(oldp+1473,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__latch));
        bufp->chgBit(oldp+1474,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__a_set));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x26U])) {
        bufp->chgBit(oldp+1475,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__DMCONTROLReg_dmactive));
        bufp->chgBit(oldp+1476,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__x1_a_source__DOT__widx_gray));
        bufp->chgBit(oldp+1477,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_gray));
        bufp->chgBit(oldp+1478,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__io_innerCtrl_source__DOT__widx_gray));
        bufp->chgBit(oldp+1479,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__debugIntRegs_0));
        bufp->chgBit(oldp+1480,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__debugIntRegs_1));
        bufp->chgBit(oldp+1481,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__debugIntRegs_2));
        bufp->chgBit(oldp+1482,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__debugIntRegs_3));
        bufp->chgBit(oldp+1483,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmOuter__DOT__debugIntRegs_4));
        bufp->chgBit(oldp+1484,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT____Vcellinp__dmiBypass__io_bypass));
        bufp->chgBit(oldp+1485,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT__bypass));
        bufp->chgBit(oldp+1486,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tlDM__DOT__dmOuter__DOT__dmiBypass__DOT__bar__DOT____Vcellinp__monitor__io_in_d_bits_source));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x27U])) {
        bufp->chgBit(oldp+1487,(vlSelf->TestHarness__DOT__chiptop__DOT__gated_clock_debug_clock_gate__DOT__en_latched));
        bufp->chgBit(oldp+1488,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT____Vcellinp__sink_valid_0__reset));
        bufp->chgBit(oldp+1489,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT____Vcellinp__sink_valid_0__reset));
        bufp->chgBit(oldp+1490,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT____Vcellinp__sink_valid_0__reset));
        bufp->chgBit(oldp+1491,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT____Vcellinp__sink_valid_0__reset));
        bufp->chgBit(oldp+1492,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT___tileResetSetter_auto_clock_out_member_allClocks_tileClockGroup_tile_4_reset));
        bufp->chgBit(oldp+1493,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT___tileResetSetter_auto_clock_out_member_allClocks_tileClockGroup_tile_3_reset));
        bufp->chgBit(oldp+1494,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT___tileResetSetter_auto_clock_out_member_allClocks_tileClockGroup_tile_2_reset));
        bufp->chgBit(oldp+1495,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT___tileResetSetter_auto_clock_out_member_allClocks_tileClockGroup_tile_1_reset));
        bufp->chgBit(oldp+1496,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dec_ready));
        bufp->chgCData(oldp+1497,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___core_io_ifu_get_pc_0_ftq_idx),5);
        bufp->chgBit(oldp+1498,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dec_xcpts_1));
        bufp->chgBit(oldp+1499,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dec_xcpts_0));
        bufp->chgBit(oldp+1500,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dec_valids_0));
        bufp->chgBit(oldp+1501,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dec_valids_1));
        bufp->chgBit(oldp+1502,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dec_valids_2));
        bufp->chgBit(oldp+1503,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dec_xcpt_stall));
        bufp->chgBit(oldp+1504,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dec_hazards_0));
        bufp->chgBit(oldp+1505,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dec_stalls_1));
        bufp->chgBit(oldp+1506,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dec_fire_0));
        bufp->chgBit(oldp+1507,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__dec_fire_1));
        bufp->chgQData(oldp+1508,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s0_vpc),40);
        bufp->chgBit(oldp+1510,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s0_valid));
        bufp->chgBit(oldp+1511,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT___GEN));
        bufp->chgQData(oldp+1512,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT____Vcellinp__banked_predictors_0__io_f0_pc),40);
        bufp->chgCData(oldp+1514,(((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s0_vpc 
                                                  >> 3U)))
                                    ? 0xfU : (0xfU 
                                              & ((IData)(0xffU) 
                                                 << 
                                                 (3U 
                                                  & (IData)(
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s0_vpc 
                                                             >> 1U))))))),4);
        bufp->chgCData(oldp+1515,((0x7fU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT____Vcellinp__banked_predictors_0__io_f0_pc 
                                                    >> 4U)))),7);
        bufp->chgSData(oldp+1516,((0x7ffU & (IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT____Vcellinp__banked_predictors_0__io_f0_pc 
                                                     >> 4U)))),11);
        bufp->chgQData(oldp+1517,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT____Vcellinp__banked_predictors_1__io_f0_pc),40);
        bufp->chgCData(oldp+1519,(((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s0_vpc 
                                                  >> 3U)))
                                    ? (0xfU & ((IData)(0xffU) 
                                               << (3U 
                                                   & (IData)(
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s0_vpc 
                                                              >> 1U)))))
                                    : 0xfU)),4);
        bufp->chgCData(oldp+1520,((0x7fU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT____Vcellinp__banked_predictors_1__io_f0_pc 
                                                    >> 4U)))),7);
        bufp->chgSData(oldp+1521,((0x7ffU & (IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT____Vcellinp__banked_predictors_1__io_f0_pc 
                                                     >> 4U)))),11);
        bufp->chgBit(oldp+1522,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__do_deq));
        bufp->chgCData(oldp+1523,((0x1fU & ((IData)(1U) 
                                            + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___core_io_ifu_get_pc_0_ftq_idx)))),5);
        bufp->chgBit(oldp+1524,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__next_is_enq));
        bufp->chgQData(oldp+1525,((0x7fffffffffULL 
                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s0_vpc)),39);
        bufp->chgBit(oldp+1527,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__s0_valid));
        bufp->chgCData(oldp+1528,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB0Way_0__RW0_addr),8);
        bufp->chgBit(oldp+1529,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB0Way_0__RW0_en));
        bufp->chgCData(oldp+1530,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB0Way_1__RW0_addr),8);
        bufp->chgBit(oldp+1531,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB0Way_1__RW0_en));
        bufp->chgCData(oldp+1532,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB0Way_2__RW0_addr),8);
        bufp->chgBit(oldp+1533,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB0Way_2__RW0_en));
        bufp->chgCData(oldp+1534,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB0Way_3__RW0_addr),8);
        bufp->chgBit(oldp+1535,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB0Way_3__RW0_en));
        bufp->chgCData(oldp+1536,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB0Way_4__RW0_addr),8);
        bufp->chgBit(oldp+1537,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB0Way_4__RW0_en));
        bufp->chgCData(oldp+1538,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB0Way_5__RW0_addr),8);
        bufp->chgBit(oldp+1539,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB0Way_5__RW0_en));
        bufp->chgCData(oldp+1540,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB0Way_6__RW0_addr),8);
        bufp->chgBit(oldp+1541,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB0Way_6__RW0_en));
        bufp->chgCData(oldp+1542,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB0Way_7__RW0_addr),8);
        bufp->chgBit(oldp+1543,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB0Way_7__RW0_en));
        bufp->chgCData(oldp+1544,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB1Way_0__RW0_addr),8);
        bufp->chgBit(oldp+1545,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB1Way_0__RW0_en));
        bufp->chgCData(oldp+1546,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB1Way_1__RW0_addr),8);
        bufp->chgBit(oldp+1547,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB1Way_1__RW0_en));
        bufp->chgCData(oldp+1548,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB1Way_2__RW0_addr),8);
        bufp->chgBit(oldp+1549,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB1Way_2__RW0_en));
        bufp->chgCData(oldp+1550,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB1Way_3__RW0_addr),8);
        bufp->chgBit(oldp+1551,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB1Way_3__RW0_en));
        bufp->chgCData(oldp+1552,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB1Way_4__RW0_addr),8);
        bufp->chgBit(oldp+1553,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB1Way_4__RW0_en));
        bufp->chgCData(oldp+1554,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB1Way_5__RW0_addr),8);
        bufp->chgBit(oldp+1555,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB1Way_5__RW0_en));
        bufp->chgCData(oldp+1556,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB1Way_6__RW0_addr),8);
        bufp->chgBit(oldp+1557,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB1Way_6__RW0_en));
        bufp->chgCData(oldp+1558,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB1Way_7__RW0_addr),8);
        bufp->chgBit(oldp+1559,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__dataArrayB1Way_7__RW0_en));
        bufp->chgCData(oldp+1560,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_addr),6);
        bufp->chgBit(oldp+1561,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_en));
        bufp->chgBit(oldp+1562,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb___05FT_1122));
        bufp->chgBit(oldp+1563,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__BJL__reset));
        bufp->chgBit(oldp+1564,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb___05FT_1122));
        bufp->chgBit(oldp+1565,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb___05FT_1122));
        bufp->chgBit(oldp+1566,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb___05FT_1122));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x28U])) {
        bufp->chgWData(oldp+1567,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_1),273);
        bufp->chgIData(oldp+1576,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_status_outs_1),32);
        bufp->chgIData(oldp+1577,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_l_rctrl_1),22);
        bufp->chgCData(oldp+1578,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__sink__DOT__ridx_gray),4);
        bufp->chgCData(oldp+1579,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__sink__DOT__ridx),4);
        bufp->chgBit(oldp+1580,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__sink__DOT__valid));
        bufp->chgBit(oldp+1581,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+1582,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__sink__DOT__ridx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+1583,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__sink__DOT__ridx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+1584,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__sink__DOT__ridx_gray) 
                                       >> 3U))));
        bufp->chgCData(oldp+1585,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__sink__DOT__ridx_gray),7);
        bufp->chgCData(oldp+1586,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__sink__DOT__ridx),7);
        bufp->chgBit(oldp+1587,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__sink__DOT__valid));
        bufp->chgBit(oldp+1588,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+1589,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__sink__DOT__ridx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+1590,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__sink__DOT__ridx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+1591,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__sink__DOT__ridx_gray) 
                                       >> 3U))));
        bufp->chgBit(oldp+1592,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__sink__DOT__ridx_gray) 
                                       >> 4U))));
        bufp->chgBit(oldp+1593,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__sink__DOT__ridx_gray) 
                                       >> 5U))));
        bufp->chgBit(oldp+1594,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__sink__DOT__ridx_gray) 
                                       >> 6U))));
        bufp->chgSData(oldp+1595,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__sink__DOT__ridx_gray),9);
        bufp->chgSData(oldp+1596,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__sink__DOT__ridx_incremented),9);
        bufp->chgSData(oldp+1597,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__sink__DOT__ridx),9);
        bufp->chgBit(oldp+1598,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__sink__DOT__valid));
        bufp->chgBit(oldp+1599,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+1600,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__sink__DOT__ridx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+1601,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__sink__DOT__ridx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+1602,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__sink__DOT__ridx_gray) 
                                       >> 3U))));
        bufp->chgBit(oldp+1603,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__sink__DOT__ridx_gray) 
                                       >> 4U))));
        bufp->chgBit(oldp+1604,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__sink__DOT__ridx_gray) 
                                       >> 5U))));
        bufp->chgBit(oldp+1605,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__sink__DOT__ridx_gray) 
                                       >> 6U))));
        bufp->chgBit(oldp+1606,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__sink__DOT__ridx_gray) 
                                       >> 7U))));
        bufp->chgBit(oldp+1607,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__sink__DOT__ridx_gray) 
                                       >> 8U))));
        bufp->chgCData(oldp+1608,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__source__DOT__widx_gray),7);
        bufp->chgBit(oldp+1609,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__source__DOT__widx_gray))));
        bufp->chgBit(oldp+1610,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__source__DOT__widx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+1611,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__source__DOT__widx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+1612,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__source__DOT__widx_gray) 
                                       >> 3U))));
        bufp->chgBit(oldp+1613,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__source__DOT__widx_gray) 
                                       >> 4U))));
        bufp->chgBit(oldp+1614,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__source__DOT__widx_gray) 
                                       >> 5U))));
        bufp->chgBit(oldp+1615,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__source__DOT__widx_gray) 
                                       >> 6U))));
        bufp->chgCData(oldp+1616,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__source__DOT__index),6);
        bufp->chgCData(oldp+1617,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__source__DOT__widx_incremented),7);
        bufp->chgCData(oldp+1618,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__source__DOT__widx),7);
        bufp->chgCData(oldp+1619,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__widx_gray),4);
        bufp->chgCData(oldp+1620,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx_gray),4);
        bufp->chgCData(oldp+1621,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__widx_gray),4);
        bufp->chgCData(oldp+1622,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_gray),4);
        bufp->chgBit(oldp+1623,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+1624,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+1625,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+1626,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx_gray) 
                                       >> 3U))));
        bufp->chgBit(oldp+1627,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+1628,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+1629,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+1630,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_gray) 
                                       >> 3U))));
        bufp->chgBit(oldp+1631,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__widx_gray))));
        bufp->chgBit(oldp+1632,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__widx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+1633,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__widx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+1634,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__widx_gray) 
                                       >> 3U))));
        bufp->chgBit(oldp+1635,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__widx_gray))));
        bufp->chgBit(oldp+1636,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__widx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+1637,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__widx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+1638,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__widx_gray) 
                                       >> 3U))));
        bufp->chgWData(oldp+1639,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT____Vcellinp__tile_prci_domain_2__auto_tile_reset_domain_tile_core_r_arfs_c_sk_in),145);
        bufp->chgIData(oldp+1644,((0xffffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_l_rctrl_1 
                                              >> 6U))),20);
        bufp->chgBit(oldp+1645,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT___io_enq_ready_output));
        bufp->chgBit(oldp+1646,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT___io_deq_valid_output));
        bufp->chgBit(oldp+1647,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT___io_enq_ready_output));
        bufp->chgBit(oldp+1648,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT___io_deq_valid_output));
        bufp->chgBit(oldp+1649,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT___io_enq_ready_output));
        bufp->chgCData(oldp+1650,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__index),3);
        bufp->chgCData(oldp+1651,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__widx_incremented),4);
        bufp->chgCData(oldp+1652,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__widx),4);
        bufp->chgCData(oldp+1653,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__index),3);
        bufp->chgCData(oldp+1654,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__widx_incremented),4);
        bufp->chgCData(oldp+1655,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__widx),4);
        bufp->chgBit(oldp+1656,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptype_rcu));
        __Vtemp_hc0d9b241__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_1[0U];
        __Vtemp_hc0d9b241__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_1[1U];
        __Vtemp_hc0d9b241__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_1[2U];
        __Vtemp_hc0d9b241__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_1[3U];
        __Vtemp_hc0d9b241__0[4U] = (0xffU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_1[4U]);
        bufp->chgWData(oldp+1657,(__Vtemp_hc0d9b241__0),136);
        __Vtemp_h0807dc75__0[0U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_1[5U] 
                                     << 0x18U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_1[4U] 
                                                  >> 8U));
        __Vtemp_h0807dc75__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_1[6U] 
                                     << 0x18U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_1[5U] 
                                                  >> 8U));
        __Vtemp_h0807dc75__0[2U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_1[7U] 
                                     << 0x18U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_1[6U] 
                                                  >> 8U));
        __Vtemp_h0807dc75__0[3U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_1[8U] 
                                     << 0x18U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_1[7U] 
                                                  >> 8U));
        __Vtemp_h0807dc75__0[4U] = (0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_1[8U] 
                                             >> 8U));
        bufp->chgWData(oldp+1662,(__Vtemp_h0807dc75__0),136);
        bufp->chgCData(oldp+1667,((0xffU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_1[4U])),8);
        bufp->chgCData(oldp+1668,((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_1[8U] 
                                            >> 8U))),8);
        bufp->chgWData(oldp+1669,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0),136);
        bufp->chgWData(oldp+1674,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1),136);
        bufp->chgWData(oldp+1679,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_0),128);
        bufp->chgWData(oldp+1683,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_1),128);
        bufp->chgBit(oldp+1687,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_valid));
        bufp->chgBit(oldp+1688,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___refill_fire_T));
        bufp->chgBit(oldp+1689,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_requestor_2_s2_nack));
        bufp->chgBit(oldp+1690,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT____Vcellinp__core__io_arfs_if_CPS));
        bufp->chgWData(oldp+1691,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT____Vcellinp__core__io_packet_arfs),144);
        bufp->chgBit(oldp+1696,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem_wb));
        bufp->chgQData(oldp+1697,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_req_bits_pc_output),40);
        bufp->chgBit(oldp+1699,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_imem_btb_update_valid));
        bufp->chgQData(oldp+1700,((0x7fffffffffULL 
                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_req_bits_pc_output)),39);
        bufp->chgBit(oldp+1702,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_wrong_npc));
        bufp->chgBit(oldp+1703,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_imem_if_check_already_done));
        bufp->chgBit(oldp+1704,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT___io_fpu_retire_T));
        bufp->chgBit(oldp+1705,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT___icsl_io_if_overtaking_next_cycle));
        bufp->chgBit(oldp+1706,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_wb));
        bufp->chgBit(oldp+1707,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem));
        bufp->chgBit(oldp+1708,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl_req_valid_csr));
        bufp->chgBit(oldp+1709,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl_req_valid_csr_test));
        bufp->chgBit(oldp+1710,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__replay_wb_common));
        bufp->chgBit(oldp+1711,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__replay_wb));
        bufp->chgBit(oldp+1712,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_valid));
        bufp->chgBit(oldp+1713,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__ll_wen));
        bufp->chgBit(oldp+1714,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_wen));
        bufp->chgBit(oldp+1715,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen));
        bufp->chgCData(oldp+1716,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr),5);
        bufp->chgQData(oldp+1717,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata),64);
        bufp->chgBit(oldp+1719,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__arfs_is_CSR));
        bufp->chgBit(oldp+1720,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__arfs_is_ARFS));
        bufp->chgQData(oldp+1721,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__id_rs_0),64);
        bufp->chgQData(oldp+1723,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__id_rs_1),64);
        bufp->chgBit(oldp+1725,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__priv_cps_done));
        bufp->chgWData(oldp+1726,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_csr_shadows),128);
        bufp->chgCData(oldp+1730,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_shadow_idx),7);
        bufp->chgBit(oldp+1731,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT___csr_io_trace_0_valid));
        bufp->chgCData(oldp+1732,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__nextSmall),7);
        bufp->chgCData(oldp+1733,((0xeU & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_shadow_idx) 
                                            - (IData)(1U)) 
                                           << 1U))),4);
        bufp->chgBit(oldp+1734,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_1));
        bufp->chgQData(oldp+1735,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_csr_shadows[1U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_csr_shadows[0U])))),64);
        bufp->chgCData(oldp+1737,((0xfU & ((IData)(1U) 
                                           + (0xeU 
                                              & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_shadow_idx) 
                                                  - (IData)(1U)) 
                                                 << 1U))))),4);
        bufp->chgQData(oldp+1738,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_csr_shadows[3U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_csr_shadows[2U])))),64);
        bufp->chgBit(oldp+1740,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_valid));
        bufp->chgBit(oldp+1741,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_replay));
        bufp->chgCData(oldp+1742,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__nReady),2);
        bufp->chgCData(oldp+1743,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__nICReady),2);
        bufp->chgCData(oldp+1744,((3U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT___valid_T) 
                                         - (IData)(1U)))),2);
        bufp->chgCData(oldp+1745,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ic_replay),2);
        bufp->chgBit(oldp+1746,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__full_insn));
        bufp->chgSData(oldp+1747,((0xffffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_l_rctrl_1 
                                              >> 6U))),16);
        bufp->chgBit(oldp+1748,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__icsl__io_new_commit));
        bufp->chgBit(oldp+1749,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__icsl__io_returned_to_special_address_valid));
        bufp->chgBit(oldp+1750,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__if_completion));
        bufp->chgBit(oldp+1751,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__if_completion_priv));
        bufp->chgBit(oldp+1752,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__if_just_overtaking));
        bufp->chgBit(oldp+1753,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__if_just_overtaking_priv));
        bufp->chgBit(oldp+1754,((1U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[4U]))));
        bufp->chgBit(oldp+1755,((1U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[4U]))));
        bufp->chgBit(oldp+1756,((2U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[4U]))));
        bufp->chgBit(oldp+1757,((2U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[4U]))));
        bufp->chgQData(oldp+1758,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[3U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[2U])))),64);
        bufp->chgQData(oldp+1760,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[3U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[2U])))),64);
        bufp->chgQData(oldp+1762,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[1U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[0U])))),64);
        bufp->chgQData(oldp+1764,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[1U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[0U])))),64);
        bufp->chgBit(oldp+1766,((3U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[4U]))));
        bufp->chgBit(oldp+1767,((3U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[4U]))));
        bufp->chgBit(oldp+1768,((5U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[4U]))));
        bufp->chgBit(oldp+1769,((5U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[4U]))));
        bufp->chgBit(oldp+1770,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_deq_valid_0));
        bufp->chgBit(oldp+1771,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_deq_valid_1));
        bufp->chgCData(oldp+1772,((0x1fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))),5);
        bufp->chgCData(oldp+1773,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__arfs_is_CSR)
                                    ? (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT____Vcellinp__core__io_packet_arfs[4U] 
                                             >> 6U))
                                    : 0U)),2);
        bufp->chgWData(oldp+1774,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__rsu_slave__io_arfs_merge),128);
        bufp->chgCData(oldp+1778,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__rsu_slave__io_arfs_index),7);
        bufp->chgBit(oldp+1779,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__if_RSU_packet));
        bufp->chgBit(oldp+1780,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__if_RSU_packet_ECP));
        bufp->chgCData(oldp+1781,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr),6);
        bufp->chgBit(oldp+1782,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_requestor_1_s2_nack));
        bufp->chgBit(oldp+1783,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcIF__DOT____Vcellinp__replayq__io_nack_valid));
        bufp->chgBit(oldp+1784,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nack_head));
        bufp->chgBit(oldp+1785,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcIF__DOT____Vcellinp__replayq__io_nack_valid) 
                                 & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nack_head)))));
        bufp->chgBit(oldp+1786,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__do_enq));
        bufp->chgBit(oldp+1787,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__portsAOI_filtered_0_ready));
        bufp->chgBit(oldp+1788,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid));
        bufp->chgBit(oldp+1789,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_nack_output));
        bufp->chgBit(oldp+1790,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_in_2_valid));
        bufp->chgBit(oldp+1791,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_in_6_valid));
        bufp->chgBit(oldp+1792,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_nack));
        bufp->chgBit(oldp+1793,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__releaseDone));
        bufp->chgBit(oldp+1794,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__releaseRejected));
        bufp->chgSData(oldp+1795,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__releaseDataBeat),10);
        bufp->chgBit(oldp+1796,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_valid_not_nacked));
        bufp->chgBit(oldp+1797,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_meta_clk_en));
        bufp->chgBit(oldp+1798,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__portsAOI_filtered_1_0_ready));
        bufp->chgQData(oldp+1799,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT___io_cpu_npc_output),40);
        bufp->chgQData(oldp+1801,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__predicted_npc),40);
        bufp->chgBit(oldp+1803,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__bjl_use_target));
        bufp->chgBit(oldp+1804,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_redirect));
        bufp->chgBit(oldp+1805,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s0_valid));
        bufp->chgQData(oldp+1806,((0xffffffffffULL 
                                   & (~ (3ULL | (~ 
                                                 (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[0U])))))))),40);
        bufp->chgQData(oldp+1808,((0xffffffffffULL 
                                   & (~ (3ULL | (~ 
                                                 (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                   << 0x38U) 
                                                  | (((QData)((IData)(
                                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                      << 0x18U) 
                                                     | ((QData)((IData)(
                                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                                        >> 8U)))))))),40);
        bufp->chgQData(oldp+1810,((0xffffffffffULL 
                                   & (~ (1ULL | (~ 
                                                 (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                   << 0x38U) 
                                                  | (((QData)((IData)(
                                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                      << 0x18U) 
                                                     | ((QData)((IData)(
                                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                                        >> 8U)))))))),40);
        bufp->chgBit(oldp+1812,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__bjl_need_replay));
        bufp->chgBit(oldp+1813,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__bjl_redirect_replay));
        bufp->chgBit(oldp+1814,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_replay));
        bufp->chgBit(oldp+1815,((0U != (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_0[0U] 
                                          | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_0[1U]) 
                                         | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_0[2U]) 
                                        | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_0[3U]))));
        bufp->chgBit(oldp+1816,((0U != (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_1[0U] 
                                          | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_1[1U]) 
                                         | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_1[2U]) 
                                        | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_1[3U]))));
        bufp->chgBit(oldp+1817,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT___BJL_io_bj_rollback_T_2));
        bufp->chgBit(oldp+1818,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__BJL__io_bj_s2_replay));
        bufp->chgBit(oldp+1819,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___io_bj_req_ready_output));
        bufp->chgQData(oldp+1820,((0xffffffffffULL 
                                   & (((QData)((IData)(
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[0U]))))),40);
        bufp->chgQData(oldp+1822,((0xffffffffffULL 
                                   & (((QData)((IData)(
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                       << 0x18U) | 
                                      ((QData)((IData)(
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                       >> 8U)))),40);
        bufp->chgBit(oldp+1824,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U] 
                                       >> 0x10U))));
        bufp->chgBit(oldp+1825,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U] 
                                       >> 0x11U))));
        bufp->chgWData(oldp+1826,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_data_0),82);
        bufp->chgWData(oldp+1829,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_data_1),82);
        bufp->chgCData(oldp+1832,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_offset_sum_1),2);
        bufp->chgCData(oldp+1833,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_offset_1),2);
        bufp->chgBit(oldp+1834,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_OH_0));
        bufp->chgBit(oldp+1835,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_OH_1));
        bufp->chgBit(oldp+1836,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__has_enq));
        bufp->chgBit(oldp+1837,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_OH_0_1));
        bufp->chgBit(oldp+1838,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_OH_1_1));
        bufp->chgBit(oldp+1839,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__has_enq_1));
        bufp->chgBit(oldp+1840,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__reserve_fire));
        bufp->chgBit(oldp+1841,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__commit_fire));
        bufp->chgCData(oldp+1842,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__sum),2);
        bufp->chgWData(oldp+1843,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT____Vcellinp__u_channel_bj_0__io_enq_bits),82);
        bufp->chgBit(oldp+1846,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__do_enq));
        bufp->chgWData(oldp+1847,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT____Vcellinp__u_channel_bj_1__io_enq_bits),82);
        bufp->chgBit(oldp+1850,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__do_enq));
        bufp->chgBit(oldp+1851,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__btb__io_btb_update_valid));
        bufp->chgBit(oldp+1852,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__btb__io_bht_update_valid));
        bufp->chgBit(oldp+1853,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__btb__io_ras_update_valid));
        bufp->chgBit(oldp+1854,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT___fq_io_enq_valid_T_8));
        bufp->chgQData(oldp+1855,((0x7fffffffffULL 
                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT___io_cpu_npc_output)),39);
        bufp->chgBit(oldp+1857,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__invalidate));
        bufp->chgBit(oldp+1858,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__tlb__io_req_valid));
        bufp->chgBit(oldp+1859,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__latch));
        bufp->chgBit(oldp+1860,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__a_set));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x29U])) {
        bufp->chgWData(oldp+1861,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2),273);
        bufp->chgIData(oldp+1870,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_status_outs_2),32);
        bufp->chgIData(oldp+1871,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_l_rctrl_2),22);
        bufp->chgCData(oldp+1872,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__sink__DOT__ridx_gray),4);
        bufp->chgCData(oldp+1873,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__sink__DOT__ridx),4);
        bufp->chgBit(oldp+1874,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__sink__DOT__valid));
        bufp->chgBit(oldp+1875,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+1876,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__sink__DOT__ridx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+1877,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__sink__DOT__ridx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+1878,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__sink__DOT__ridx_gray) 
                                       >> 3U))));
        bufp->chgCData(oldp+1879,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__sink__DOT__ridx_gray),7);
        bufp->chgCData(oldp+1880,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__sink__DOT__ridx),7);
        bufp->chgBit(oldp+1881,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__sink__DOT__valid));
        bufp->chgBit(oldp+1882,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+1883,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__sink__DOT__ridx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+1884,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__sink__DOT__ridx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+1885,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__sink__DOT__ridx_gray) 
                                       >> 3U))));
        bufp->chgBit(oldp+1886,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__sink__DOT__ridx_gray) 
                                       >> 4U))));
        bufp->chgBit(oldp+1887,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__sink__DOT__ridx_gray) 
                                       >> 5U))));
        bufp->chgBit(oldp+1888,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__sink__DOT__ridx_gray) 
                                       >> 6U))));
        bufp->chgSData(oldp+1889,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__sink__DOT__ridx_gray),9);
        bufp->chgSData(oldp+1890,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__sink__DOT__ridx_incremented),9);
        bufp->chgSData(oldp+1891,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__sink__DOT__ridx),9);
        bufp->chgBit(oldp+1892,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__sink__DOT__valid));
        bufp->chgBit(oldp+1893,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+1894,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__sink__DOT__ridx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+1895,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__sink__DOT__ridx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+1896,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__sink__DOT__ridx_gray) 
                                       >> 3U))));
        bufp->chgBit(oldp+1897,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__sink__DOT__ridx_gray) 
                                       >> 4U))));
        bufp->chgBit(oldp+1898,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__sink__DOT__ridx_gray) 
                                       >> 5U))));
        bufp->chgBit(oldp+1899,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__sink__DOT__ridx_gray) 
                                       >> 6U))));
        bufp->chgBit(oldp+1900,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__sink__DOT__ridx_gray) 
                                       >> 7U))));
        bufp->chgBit(oldp+1901,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__sink__DOT__ridx_gray) 
                                       >> 8U))));
        bufp->chgCData(oldp+1902,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__source__DOT__widx_gray),7);
        bufp->chgBit(oldp+1903,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__source__DOT__widx_gray))));
        bufp->chgBit(oldp+1904,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__source__DOT__widx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+1905,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__source__DOT__widx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+1906,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__source__DOT__widx_gray) 
                                       >> 3U))));
        bufp->chgBit(oldp+1907,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__source__DOT__widx_gray) 
                                       >> 4U))));
        bufp->chgBit(oldp+1908,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__source__DOT__widx_gray) 
                                       >> 5U))));
        bufp->chgBit(oldp+1909,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__source__DOT__widx_gray) 
                                       >> 6U))));
        bufp->chgCData(oldp+1910,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__source__DOT__index),6);
        bufp->chgCData(oldp+1911,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__source__DOT__widx_incremented),7);
        bufp->chgCData(oldp+1912,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__source__DOT__widx),7);
        bufp->chgCData(oldp+1913,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__widx_gray),4);
        bufp->chgCData(oldp+1914,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx_gray),4);
        bufp->chgCData(oldp+1915,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__widx_gray),4);
        bufp->chgCData(oldp+1916,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_gray),4);
        bufp->chgBit(oldp+1917,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+1918,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+1919,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+1920,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx_gray) 
                                       >> 3U))));
        bufp->chgBit(oldp+1921,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+1922,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+1923,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+1924,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_gray) 
                                       >> 3U))));
        bufp->chgBit(oldp+1925,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__widx_gray))));
        bufp->chgBit(oldp+1926,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__widx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+1927,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__widx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+1928,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__widx_gray) 
                                       >> 3U))));
        bufp->chgBit(oldp+1929,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__widx_gray))));
        bufp->chgBit(oldp+1930,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__widx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+1931,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__widx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+1932,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__widx_gray) 
                                       >> 3U))));
        bufp->chgWData(oldp+1933,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT____Vcellinp__tile_prci_domain_3__auto_tile_reset_domain_tile_core_r_arfs_c_sk_in),145);
        bufp->chgIData(oldp+1938,((0xffffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_l_rctrl_2 
                                              >> 6U))),20);
        bufp->chgBit(oldp+1939,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT___io_enq_ready_output));
        bufp->chgBit(oldp+1940,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT___io_deq_valid_output));
        bufp->chgBit(oldp+1941,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT___io_enq_ready_output));
        bufp->chgBit(oldp+1942,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT___io_deq_valid_output));
        bufp->chgBit(oldp+1943,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT___io_enq_ready_output));
        bufp->chgCData(oldp+1944,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__index),3);
        bufp->chgCData(oldp+1945,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__widx_incremented),4);
        bufp->chgCData(oldp+1946,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__widx),4);
        bufp->chgCData(oldp+1947,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__index),3);
        bufp->chgCData(oldp+1948,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__widx_incremented),4);
        bufp->chgCData(oldp+1949,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__widx),4);
        bufp->chgBit(oldp+1950,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptype_rcu));
        __Vtemp_hca3a2207__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2[0U];
        __Vtemp_hca3a2207__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2[1U];
        __Vtemp_hca3a2207__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2[2U];
        __Vtemp_hca3a2207__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2[3U];
        __Vtemp_hca3a2207__0[4U] = (0xffU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2[4U]);
        bufp->chgWData(oldp+1951,(__Vtemp_hca3a2207__0),136);
        __Vtemp_h5b39d182__0[0U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2[5U] 
                                     << 0x18U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2[4U] 
                                                  >> 8U));
        __Vtemp_h5b39d182__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2[6U] 
                                     << 0x18U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2[5U] 
                                                  >> 8U));
        __Vtemp_h5b39d182__0[2U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2[7U] 
                                     << 0x18U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2[6U] 
                                                  >> 8U));
        __Vtemp_h5b39d182__0[3U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2[8U] 
                                     << 0x18U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2[7U] 
                                                  >> 8U));
        __Vtemp_h5b39d182__0[4U] = (0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2[8U] 
                                             >> 8U));
        bufp->chgWData(oldp+1956,(__Vtemp_h5b39d182__0),136);
        bufp->chgCData(oldp+1961,((0xffU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2[4U])),8);
        bufp->chgCData(oldp+1962,((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2[8U] 
                                            >> 8U))),8);
        bufp->chgWData(oldp+1963,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0),136);
        bufp->chgWData(oldp+1968,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1),136);
        bufp->chgWData(oldp+1973,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_0),128);
        bufp->chgWData(oldp+1977,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_1),128);
        bufp->chgBit(oldp+1981,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_valid));
        bufp->chgBit(oldp+1982,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___refill_fire_T));
        bufp->chgBit(oldp+1983,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_requestor_2_s2_nack));
        bufp->chgBit(oldp+1984,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT____Vcellinp__core__io_arfs_if_CPS));
        bufp->chgWData(oldp+1985,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT____Vcellinp__core__io_packet_arfs),144);
        bufp->chgBit(oldp+1990,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem_wb));
        bufp->chgQData(oldp+1991,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_req_bits_pc_output),40);
        bufp->chgBit(oldp+1993,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_imem_btb_update_valid));
        bufp->chgQData(oldp+1994,((0x7fffffffffULL 
                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_req_bits_pc_output)),39);
        bufp->chgBit(oldp+1996,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_wrong_npc));
        bufp->chgBit(oldp+1997,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_imem_if_check_already_done));
        bufp->chgBit(oldp+1998,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___io_fpu_retire_T));
        bufp->chgBit(oldp+1999,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___icsl_io_if_overtaking_next_cycle));
        bufp->chgBit(oldp+2000,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_wb));
        bufp->chgBit(oldp+2001,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem));
        bufp->chgBit(oldp+2002,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl_req_valid_csr));
        bufp->chgBit(oldp+2003,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl_req_valid_csr_test));
        bufp->chgBit(oldp+2004,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__replay_wb_common));
        bufp->chgBit(oldp+2005,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__replay_wb));
        bufp->chgBit(oldp+2006,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_valid));
        bufp->chgBit(oldp+2007,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ll_wen));
        bufp->chgBit(oldp+2008,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_wen));
        bufp->chgBit(oldp+2009,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen));
        bufp->chgCData(oldp+2010,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr),5);
        bufp->chgQData(oldp+2011,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata),64);
        bufp->chgBit(oldp+2013,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__arfs_is_CSR));
        bufp->chgBit(oldp+2014,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__arfs_is_ARFS));
        bufp->chgQData(oldp+2015,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__id_rs_0),64);
        bufp->chgQData(oldp+2017,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__id_rs_1),64);
        bufp->chgBit(oldp+2019,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__priv_cps_done));
        bufp->chgWData(oldp+2020,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_csr_shadows),128);
        bufp->chgCData(oldp+2024,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_shadow_idx),7);
        bufp->chgBit(oldp+2025,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___csr_io_trace_0_valid));
        bufp->chgCData(oldp+2026,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__nextSmall),7);
        bufp->chgCData(oldp+2027,((0xeU & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_shadow_idx) 
                                            - (IData)(1U)) 
                                           << 1U))),4);
        bufp->chgBit(oldp+2028,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_1));
        bufp->chgQData(oldp+2029,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_csr_shadows[1U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_csr_shadows[0U])))),64);
        bufp->chgCData(oldp+2031,((0xfU & ((IData)(1U) 
                                           + (0xeU 
                                              & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_shadow_idx) 
                                                  - (IData)(1U)) 
                                                 << 1U))))),4);
        bufp->chgQData(oldp+2032,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_csr_shadows[3U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_csr_shadows[2U])))),64);
        bufp->chgBit(oldp+2034,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_valid));
        bufp->chgBit(oldp+2035,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_replay));
        bufp->chgCData(oldp+2036,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__nReady),2);
        bufp->chgCData(oldp+2037,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__nICReady),2);
        bufp->chgCData(oldp+2038,((3U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT___valid_T) 
                                         - (IData)(1U)))),2);
        bufp->chgCData(oldp+2039,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ic_replay),2);
        bufp->chgBit(oldp+2040,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__full_insn));
        bufp->chgSData(oldp+2041,((0xffffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_l_rctrl_2 
                                              >> 6U))),16);
        bufp->chgBit(oldp+2042,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__icsl__io_new_commit));
        bufp->chgBit(oldp+2043,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__icsl__io_returned_to_special_address_valid));
        bufp->chgBit(oldp+2044,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__if_completion));
        bufp->chgBit(oldp+2045,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__if_completion_priv));
        bufp->chgBit(oldp+2046,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__if_just_overtaking));
        bufp->chgBit(oldp+2047,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__if_just_overtaking_priv));
        bufp->chgBit(oldp+2048,((1U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[4U]))));
        bufp->chgBit(oldp+2049,((1U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[4U]))));
        bufp->chgBit(oldp+2050,((2U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[4U]))));
        bufp->chgBit(oldp+2051,((2U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[4U]))));
        bufp->chgQData(oldp+2052,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[3U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[2U])))),64);
        bufp->chgQData(oldp+2054,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[3U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[2U])))),64);
        bufp->chgQData(oldp+2056,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[1U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[0U])))),64);
        bufp->chgQData(oldp+2058,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[1U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[0U])))),64);
        bufp->chgBit(oldp+2060,((3U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[4U]))));
        bufp->chgBit(oldp+2061,((3U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[4U]))));
        bufp->chgBit(oldp+2062,((5U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[4U]))));
        bufp->chgBit(oldp+2063,((5U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[4U]))));
        bufp->chgBit(oldp+2064,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_deq_valid_0));
        bufp->chgBit(oldp+2065,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_deq_valid_1));
        bufp->chgCData(oldp+2066,((0x1fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))),5);
        bufp->chgCData(oldp+2067,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__arfs_is_CSR)
                                    ? (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT____Vcellinp__core__io_packet_arfs[4U] 
                                             >> 6U))
                                    : 0U)),2);
        bufp->chgWData(oldp+2068,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__rsu_slave__io_arfs_merge),128);
        bufp->chgCData(oldp+2072,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__rsu_slave__io_arfs_index),7);
        bufp->chgBit(oldp+2073,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__if_RSU_packet));
        bufp->chgBit(oldp+2074,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__if_RSU_packet_ECP));
        bufp->chgCData(oldp+2075,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr),6);
        bufp->chgBit(oldp+2076,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_requestor_1_s2_nack));
        bufp->chgBit(oldp+2077,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcIF__DOT____Vcellinp__replayq__io_nack_valid));
        bufp->chgBit(oldp+2078,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nack_head));
        bufp->chgBit(oldp+2079,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcIF__DOT____Vcellinp__replayq__io_nack_valid) 
                                 & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nack_head)))));
        bufp->chgBit(oldp+2080,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__do_enq));
        bufp->chgBit(oldp+2081,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__portsAOI_filtered_0_ready));
        bufp->chgBit(oldp+2082,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid));
        bufp->chgBit(oldp+2083,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_nack_output));
        bufp->chgBit(oldp+2084,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_in_2_valid));
        bufp->chgBit(oldp+2085,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_in_6_valid));
        bufp->chgBit(oldp+2086,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_nack));
        bufp->chgBit(oldp+2087,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__releaseDone));
        bufp->chgBit(oldp+2088,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__releaseRejected));
        bufp->chgSData(oldp+2089,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__releaseDataBeat),10);
        bufp->chgBit(oldp+2090,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_valid_not_nacked));
        bufp->chgBit(oldp+2091,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_meta_clk_en));
        bufp->chgBit(oldp+2092,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__portsAOI_filtered_1_0_ready));
        bufp->chgQData(oldp+2093,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___io_cpu_npc_output),40);
        bufp->chgQData(oldp+2095,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__predicted_npc),40);
        bufp->chgBit(oldp+2097,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__bjl_use_target));
        bufp->chgBit(oldp+2098,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_redirect));
        bufp->chgBit(oldp+2099,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s0_valid));
        bufp->chgQData(oldp+2100,((0xffffffffffULL 
                                   & (~ (3ULL | (~ 
                                                 (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[0U])))))))),40);
        bufp->chgQData(oldp+2102,((0xffffffffffULL 
                                   & (~ (3ULL | (~ 
                                                 (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                   << 0x38U) 
                                                  | (((QData)((IData)(
                                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                      << 0x18U) 
                                                     | ((QData)((IData)(
                                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                                        >> 8U)))))))),40);
        bufp->chgQData(oldp+2104,((0xffffffffffULL 
                                   & (~ (1ULL | (~ 
                                                 (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                   << 0x38U) 
                                                  | (((QData)((IData)(
                                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                      << 0x18U) 
                                                     | ((QData)((IData)(
                                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                                        >> 8U)))))))),40);
        bufp->chgBit(oldp+2106,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__bjl_need_replay));
        bufp->chgBit(oldp+2107,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__bjl_redirect_replay));
        bufp->chgBit(oldp+2108,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_replay));
        bufp->chgBit(oldp+2109,((0U != (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_0[0U] 
                                          | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_0[1U]) 
                                         | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_0[2U]) 
                                        | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_0[3U]))));
        bufp->chgBit(oldp+2110,((0U != (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_1[0U] 
                                          | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_1[1U]) 
                                         | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_1[2U]) 
                                        | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_1[3U]))));
        bufp->chgBit(oldp+2111,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___BJL_io_bj_rollback_T_2));
        bufp->chgBit(oldp+2112,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__BJL__io_bj_s2_replay));
        bufp->chgBit(oldp+2113,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___io_bj_req_ready_output));
        bufp->chgQData(oldp+2114,((0xffffffffffULL 
                                   & (((QData)((IData)(
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[0U]))))),40);
        bufp->chgQData(oldp+2116,((0xffffffffffULL 
                                   & (((QData)((IData)(
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                       << 0x18U) | 
                                      ((QData)((IData)(
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                       >> 8U)))),40);
        bufp->chgBit(oldp+2118,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U] 
                                       >> 0x10U))));
        bufp->chgBit(oldp+2119,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U] 
                                       >> 0x11U))));
        bufp->chgWData(oldp+2120,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_data_0),82);
        bufp->chgWData(oldp+2123,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_data_1),82);
        bufp->chgCData(oldp+2126,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_offset_sum_1),2);
        bufp->chgCData(oldp+2127,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_offset_1),2);
        bufp->chgBit(oldp+2128,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_OH_0));
        bufp->chgBit(oldp+2129,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_OH_1));
        bufp->chgBit(oldp+2130,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__has_enq));
        bufp->chgBit(oldp+2131,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_OH_0_1));
        bufp->chgBit(oldp+2132,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_OH_1_1));
        bufp->chgBit(oldp+2133,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__has_enq_1));
        bufp->chgBit(oldp+2134,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__reserve_fire));
        bufp->chgBit(oldp+2135,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__commit_fire));
        bufp->chgCData(oldp+2136,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__sum),2);
        bufp->chgWData(oldp+2137,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT____Vcellinp__u_channel_bj_0__io_enq_bits),82);
        bufp->chgBit(oldp+2140,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__do_enq));
        bufp->chgWData(oldp+2141,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT____Vcellinp__u_channel_bj_1__io_enq_bits),82);
        bufp->chgBit(oldp+2144,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__do_enq));
        bufp->chgBit(oldp+2145,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__btb__io_btb_update_valid));
        bufp->chgBit(oldp+2146,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__btb__io_bht_update_valid));
        bufp->chgBit(oldp+2147,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__btb__io_ras_update_valid));
        bufp->chgBit(oldp+2148,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___fq_io_enq_valid_T_8));
        bufp->chgQData(oldp+2149,((0x7fffffffffULL 
                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___io_cpu_npc_output)),39);
        bufp->chgBit(oldp+2151,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__invalidate));
        bufp->chgBit(oldp+2152,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__tlb__io_req_valid));
        bufp->chgBit(oldp+2153,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__latch));
        bufp->chgBit(oldp+2154,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__a_set));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x2aU])) {
        bufp->chgWData(oldp+2155,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3),273);
        bufp->chgIData(oldp+2164,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_status_outs_3),32);
        bufp->chgIData(oldp+2165,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_l_rctrl_3),22);
        bufp->chgCData(oldp+2166,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__ridx_gray),4);
        bufp->chgCData(oldp+2167,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__ridx),4);
        bufp->chgBit(oldp+2168,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__valid));
        bufp->chgBit(oldp+2169,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+2170,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__ridx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+2171,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__ridx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+2172,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__ridx_gray) 
                                       >> 3U))));
        bufp->chgCData(oldp+2173,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__ridx_gray),7);
        bufp->chgCData(oldp+2174,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__ridx),7);
        bufp->chgBit(oldp+2175,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__valid));
        bufp->chgBit(oldp+2176,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+2177,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__ridx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+2178,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__ridx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+2179,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__ridx_gray) 
                                       >> 3U))));
        bufp->chgBit(oldp+2180,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__ridx_gray) 
                                       >> 4U))));
        bufp->chgBit(oldp+2181,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__ridx_gray) 
                                       >> 5U))));
        bufp->chgBit(oldp+2182,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__ridx_gray) 
                                       >> 6U))));
        bufp->chgSData(oldp+2183,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__ridx_gray),9);
        bufp->chgSData(oldp+2184,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__ridx_incremented),9);
        bufp->chgSData(oldp+2185,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__ridx),9);
        bufp->chgBit(oldp+2186,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__valid));
        bufp->chgBit(oldp+2187,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+2188,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__ridx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+2189,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__ridx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+2190,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__ridx_gray) 
                                       >> 3U))));
        bufp->chgBit(oldp+2191,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__ridx_gray) 
                                       >> 4U))));
        bufp->chgBit(oldp+2192,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__ridx_gray) 
                                       >> 5U))));
        bufp->chgBit(oldp+2193,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__ridx_gray) 
                                       >> 6U))));
        bufp->chgBit(oldp+2194,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__ridx_gray) 
                                       >> 7U))));
        bufp->chgBit(oldp+2195,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__ridx_gray) 
                                       >> 8U))));
        bufp->chgCData(oldp+2196,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__widx_gray),7);
        bufp->chgBit(oldp+2197,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__widx_gray))));
        bufp->chgBit(oldp+2198,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__widx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+2199,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__widx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+2200,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__widx_gray) 
                                       >> 3U))));
        bufp->chgBit(oldp+2201,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__widx_gray) 
                                       >> 4U))));
        bufp->chgBit(oldp+2202,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__widx_gray) 
                                       >> 5U))));
        bufp->chgBit(oldp+2203,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__widx_gray) 
                                       >> 6U))));
        bufp->chgCData(oldp+2204,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__index),6);
        bufp->chgCData(oldp+2205,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__widx_incremented),7);
        bufp->chgCData(oldp+2206,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__widx),7);
        bufp->chgCData(oldp+2207,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__widx_gray),4);
        bufp->chgCData(oldp+2208,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx_gray),4);
        bufp->chgCData(oldp+2209,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__widx_gray),4);
        bufp->chgCData(oldp+2210,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_gray),4);
        bufp->chgBit(oldp+2211,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+2212,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+2213,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+2214,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx_gray) 
                                       >> 3U))));
        bufp->chgBit(oldp+2215,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_gray))));
        bufp->chgBit(oldp+2216,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+2217,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+2218,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_gray) 
                                       >> 3U))));
        bufp->chgBit(oldp+2219,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__widx_gray))));
        bufp->chgBit(oldp+2220,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__widx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+2221,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__widx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+2222,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__widx_gray) 
                                       >> 3U))));
        bufp->chgBit(oldp+2223,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__widx_gray))));
        bufp->chgBit(oldp+2224,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__widx_gray) 
                                       >> 1U))));
        bufp->chgBit(oldp+2225,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__widx_gray) 
                                       >> 2U))));
        bufp->chgBit(oldp+2226,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__widx_gray) 
                                       >> 3U))));
        bufp->chgWData(oldp+2227,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT____Vcellinp__tile_prci_domain_4__auto_tile_reset_domain_tile_core_r_arfs_c_sk_in),145);
        bufp->chgIData(oldp+2232,((0xffffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_l_rctrl_3 
                                              >> 6U))),20);
        bufp->chgBit(oldp+2233,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT___io_enq_ready_output));
        bufp->chgBit(oldp+2234,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT___io_deq_valid_output));
        bufp->chgBit(oldp+2235,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT___io_enq_ready_output));
        bufp->chgBit(oldp+2236,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT___io_deq_valid_output));
        bufp->chgBit(oldp+2237,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT___io_enq_ready_output));
        bufp->chgCData(oldp+2238,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__index),3);
        bufp->chgCData(oldp+2239,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__widx_incremented),4);
        bufp->chgCData(oldp+2240,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__widx),4);
        bufp->chgCData(oldp+2241,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__index),3);
        bufp->chgCData(oldp+2242,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__widx_incremented),4);
        bufp->chgCData(oldp+2243,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__widx),4);
        bufp->chgBit(oldp+2244,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptype_rcu));
        __Vtemp_h266ce27f__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[0U];
        __Vtemp_h266ce27f__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[1U];
        __Vtemp_h266ce27f__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[2U];
        __Vtemp_h266ce27f__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[3U];
        __Vtemp_h266ce27f__0[4U] = (0xffU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[4U]);
        bufp->chgWData(oldp+2245,(__Vtemp_h266ce27f__0),136);
        __Vtemp_h864f979f__0[0U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[5U] 
                                     << 0x18U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[4U] 
                                                  >> 8U));
        __Vtemp_h864f979f__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[6U] 
                                     << 0x18U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[5U] 
                                                  >> 8U));
        __Vtemp_h864f979f__0[2U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[7U] 
                                     << 0x18U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[6U] 
                                                  >> 8U));
        __Vtemp_h864f979f__0[3U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[8U] 
                                     << 0x18U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[7U] 
                                                  >> 8U));
        __Vtemp_h864f979f__0[4U] = (0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[8U] 
                                             >> 8U));
        bufp->chgWData(oldp+2250,(__Vtemp_h864f979f__0),136);
        bufp->chgCData(oldp+2255,((0xffU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[4U])),8);
        bufp->chgCData(oldp+2256,((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[8U] 
                                            >> 8U))),8);
        bufp->chgWData(oldp+2257,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0),136);
        bufp->chgWData(oldp+2262,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1),136);
        bufp->chgWData(oldp+2267,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_0),128);
        bufp->chgWData(oldp+2271,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_1),128);
        bufp->chgBit(oldp+2275,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_valid));
        bufp->chgBit(oldp+2276,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___refill_fire_T));
        bufp->chgBit(oldp+2277,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_requestor_2_s2_nack));
        bufp->chgBit(oldp+2278,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT____Vcellinp__core__io_arfs_if_CPS));
        bufp->chgWData(oldp+2279,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT____Vcellinp__core__io_packet_arfs),144);
        bufp->chgBit(oldp+2284,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem_wb));
        bufp->chgQData(oldp+2285,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_req_bits_pc_output),40);
        bufp->chgBit(oldp+2287,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_imem_btb_update_valid));
        bufp->chgQData(oldp+2288,((0x7fffffffffULL 
                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_req_bits_pc_output)),39);
        bufp->chgBit(oldp+2290,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_wrong_npc));
        bufp->chgBit(oldp+2291,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_imem_if_check_already_done));
        bufp->chgBit(oldp+2292,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___io_fpu_retire_T));
        bufp->chgBit(oldp+2293,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___icsl_io_if_overtaking_next_cycle));
        bufp->chgBit(oldp+2294,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_wb));
        bufp->chgBit(oldp+2295,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem));
        bufp->chgBit(oldp+2296,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl_req_valid_csr));
        bufp->chgBit(oldp+2297,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl_req_valid_csr_test));
        bufp->chgBit(oldp+2298,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__replay_wb_common));
        bufp->chgBit(oldp+2299,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__replay_wb));
        bufp->chgBit(oldp+2300,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_valid));
        bufp->chgBit(oldp+2301,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ll_wen));
        bufp->chgBit(oldp+2302,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_wen));
        bufp->chgBit(oldp+2303,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen));
        bufp->chgCData(oldp+2304,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr),5);
        bufp->chgQData(oldp+2305,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata),64);
        bufp->chgBit(oldp+2307,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__arfs_is_CSR));
        bufp->chgBit(oldp+2308,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__arfs_is_ARFS));
        bufp->chgQData(oldp+2309,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_rs_0),64);
        bufp->chgQData(oldp+2311,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_rs_1),64);
        bufp->chgBit(oldp+2313,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__priv_cps_done));
        bufp->chgWData(oldp+2314,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_csr_shadows),128);
        bufp->chgCData(oldp+2318,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_shadow_idx),7);
        bufp->chgBit(oldp+2319,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___csr_io_trace_0_valid));
        bufp->chgCData(oldp+2320,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__nextSmall),7);
        bufp->chgCData(oldp+2321,((0xeU & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_shadow_idx) 
                                            - (IData)(1U)) 
                                           << 1U))),4);
        bufp->chgBit(oldp+2322,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_1));
        bufp->chgQData(oldp+2323,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_csr_shadows[1U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_csr_shadows[0U])))),64);
        bufp->chgCData(oldp+2325,((0xfU & ((IData)(1U) 
                                           + (0xeU 
                                              & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_shadow_idx) 
                                                  - (IData)(1U)) 
                                                 << 1U))))),4);
        bufp->chgQData(oldp+2326,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_csr_shadows[3U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_csr_shadows[2U])))),64);
        bufp->chgBit(oldp+2328,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_valid));
        bufp->chgBit(oldp+2329,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_replay));
        bufp->chgCData(oldp+2330,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__nReady),2);
        bufp->chgCData(oldp+2331,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__nICReady),2);
        bufp->chgCData(oldp+2332,((3U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT___valid_T) 
                                         - (IData)(1U)))),2);
        bufp->chgCData(oldp+2333,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ic_replay),2);
        bufp->chgBit(oldp+2334,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__full_insn));
        bufp->chgSData(oldp+2335,((0xffffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_l_rctrl_3 
                                              >> 6U))),16);
        bufp->chgBit(oldp+2336,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__icsl__io_new_commit));
        bufp->chgBit(oldp+2337,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__icsl__io_returned_to_special_address_valid));
        bufp->chgBit(oldp+2338,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__if_completion));
        bufp->chgBit(oldp+2339,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__if_completion_priv));
        bufp->chgBit(oldp+2340,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__if_just_overtaking));
        bufp->chgBit(oldp+2341,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__if_just_overtaking_priv));
        bufp->chgBit(oldp+2342,((1U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[4U]))));
        bufp->chgBit(oldp+2343,((1U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[4U]))));
        bufp->chgBit(oldp+2344,((2U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[4U]))));
        bufp->chgBit(oldp+2345,((2U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[4U]))));
        bufp->chgQData(oldp+2346,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[3U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[2U])))),64);
        bufp->chgQData(oldp+2348,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[3U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[2U])))),64);
        bufp->chgQData(oldp+2350,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[1U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[0U])))),64);
        bufp->chgQData(oldp+2352,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[1U])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[0U])))),64);
        bufp->chgBit(oldp+2354,((3U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[4U]))));
        bufp->chgBit(oldp+2355,((3U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[4U]))));
        bufp->chgBit(oldp+2356,((5U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_vec_in_0[4U]))));
        bufp->chgBit(oldp+2357,((5U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_vec_in_1[4U]))));
        bufp->chgBit(oldp+2358,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_deq_valid_0));
        bufp->chgBit(oldp+2359,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_deq_valid_1));
        bufp->chgCData(oldp+2360,((0x1fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))),5);
        bufp->chgCData(oldp+2361,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__arfs_is_CSR)
                                    ? (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT____Vcellinp__core__io_packet_arfs[4U] 
                                             >> 6U))
                                    : 0U)),2);
        bufp->chgWData(oldp+2362,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__rsu_slave__io_arfs_merge),128);
        bufp->chgCData(oldp+2366,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__rsu_slave__io_arfs_index),7);
        bufp->chgBit(oldp+2367,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__if_RSU_packet));
        bufp->chgBit(oldp+2368,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__if_RSU_packet_ECP));
        bufp->chgCData(oldp+2369,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr),6);
        bufp->chgBit(oldp+2370,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_requestor_1_s2_nack));
        bufp->chgBit(oldp+2371,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT____Vcellinp__replayq__io_nack_valid));
        bufp->chgBit(oldp+2372,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nack_head));
        bufp->chgBit(oldp+2373,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT____Vcellinp__replayq__io_nack_valid) 
                                 & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nack_head)))));
        bufp->chgBit(oldp+2374,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__do_enq));
        bufp->chgBit(oldp+2375,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__portsAOI_filtered_0_ready));
        bufp->chgBit(oldp+2376,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__out_8_valid));
        bufp->chgBit(oldp+2377,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_nack_output));
        bufp->chgBit(oldp+2378,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_in_2_valid));
        bufp->chgBit(oldp+2379,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_in_6_valid));
        bufp->chgBit(oldp+2380,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_nack));
        bufp->chgBit(oldp+2381,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__releaseDone));
        bufp->chgBit(oldp+2382,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__releaseRejected));
        bufp->chgSData(oldp+2383,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__releaseDataBeat),10);
        bufp->chgBit(oldp+2384,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_valid_not_nacked));
        bufp->chgBit(oldp+2385,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_meta_clk_en));
        bufp->chgBit(oldp+2386,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__portsAOI_filtered_1_0_ready));
        bufp->chgQData(oldp+2387,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___io_cpu_npc_output),40);
        bufp->chgQData(oldp+2389,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__predicted_npc),40);
        bufp->chgBit(oldp+2391,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__bjl_use_target));
        bufp->chgBit(oldp+2392,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_redirect));
        bufp->chgBit(oldp+2393,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s0_valid));
        bufp->chgQData(oldp+2394,((0xffffffffffULL 
                                   & (~ (3ULL | (~ 
                                                 (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                                   << 0x20U) 
                                                  | (QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[0U])))))))),40);
        bufp->chgQData(oldp+2396,((0xffffffffffULL 
                                   & (~ (3ULL | (~ 
                                                 (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                   << 0x38U) 
                                                  | (((QData)((IData)(
                                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                      << 0x18U) 
                                                     | ((QData)((IData)(
                                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                                        >> 8U)))))))),40);
        bufp->chgQData(oldp+2398,((0xffffffffffULL 
                                   & (~ (1ULL | (~ 
                                                 (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                   << 0x38U) 
                                                  | (((QData)((IData)(
                                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                      << 0x18U) 
                                                     | ((QData)((IData)(
                                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                                        >> 8U)))))))),40);
        bufp->chgBit(oldp+2400,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__bjl_need_replay));
        bufp->chgBit(oldp+2401,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__bjl_redirect_replay));
        bufp->chgBit(oldp+2402,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_replay));
        bufp->chgBit(oldp+2403,((0U != (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_0[0U] 
                                          | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_0[1U]) 
                                         | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_0[2U]) 
                                        | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_0[3U]))));
        bufp->chgBit(oldp+2404,((0U != (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_1[0U] 
                                          | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_1[1U]) 
                                         | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_1[2U]) 
                                        | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__packet_bjvec_in_1[3U]))));
        bufp->chgBit(oldp+2405,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___BJL_io_bj_rollback_T_2));
        bufp->chgBit(oldp+2406,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__BJL__io_bj_s2_replay));
        bufp->chgBit(oldp+2407,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___io_bj_req_ready_output));
        bufp->chgQData(oldp+2408,((0xffffffffffULL 
                                   & (((QData)((IData)(
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                       << 0x20U) | (QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[0U]))))),40);
        bufp->chgQData(oldp+2410,((0xffffffffffULL 
                                   & (((QData)((IData)(
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                       << 0x18U) | 
                                      ((QData)((IData)(
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                       >> 8U)))),40);
        bufp->chgBit(oldp+2412,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U] 
                                       >> 0x10U))));
        bufp->chgBit(oldp+2413,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U] 
                                       >> 0x11U))));
        bufp->chgWData(oldp+2414,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_data_0),82);
        bufp->chgWData(oldp+2417,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_data_1),82);
        bufp->chgCData(oldp+2420,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_offset_sum_1),2);
        bufp->chgCData(oldp+2421,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_offset_1),2);
        bufp->chgBit(oldp+2422,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_OH_0));
        bufp->chgBit(oldp+2423,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_OH_1));
        bufp->chgBit(oldp+2424,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__has_enq));
        bufp->chgBit(oldp+2425,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_OH_0_1));
        bufp->chgBit(oldp+2426,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__bj_enq_OH_1_1));
        bufp->chgBit(oldp+2427,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__has_enq_1));
        bufp->chgBit(oldp+2428,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__reserve_fire));
        bufp->chgBit(oldp+2429,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__commit_fire));
        bufp->chgCData(oldp+2430,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__sum),2);
        bufp->chgWData(oldp+2431,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT____Vcellinp__u_channel_bj_0__io_enq_bits),82);
        bufp->chgBit(oldp+2434,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__do_enq));
        bufp->chgWData(oldp+2435,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT____Vcellinp__u_channel_bj_1__io_enq_bits),82);
        bufp->chgBit(oldp+2438,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__do_enq));
        bufp->chgBit(oldp+2439,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__btb__io_btb_update_valid));
        bufp->chgBit(oldp+2440,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__btb__io_bht_update_valid));
        bufp->chgBit(oldp+2441,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__btb__io_ras_update_valid));
        bufp->chgBit(oldp+2442,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___fq_io_enq_valid_T_8));
        bufp->chgQData(oldp+2443,((0x7fffffffffULL 
                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___io_cpu_npc_output)),39);
        bufp->chgBit(oldp+2445,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__invalidate));
        bufp->chgBit(oldp+2446,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__tlb__io_req_valid));
        bufp->chgBit(oldp+2447,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__latch));
        bufp->chgBit(oldp+2448,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__a_set));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x2bU])) {
        bufp->chgCData(oldp+2449,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__mem_0_sink),3);
        bufp->chgCData(oldp+2450,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__mem_1_sink),3);
        bufp->chgCData(oldp+2451,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__mem_2_sink),3);
        bufp->chgCData(oldp+2452,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__mem_3_sink),3);
        bufp->chgCData(oldp+2453,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__mem_4_sink),3);
        bufp->chgCData(oldp+2454,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__mem_5_sink),3);
        bufp->chgCData(oldp+2455,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__mem_6_sink),3);
        bufp->chgCData(oldp+2456,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__mem_7_sink),3);
        bufp->chgCData(oldp+2457,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                         >> 2U))),3);
        bufp->chgCData(oldp+2458,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                         >> 0xdU))),3);
        bufp->chgCData(oldp+2459,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                         >> 0xbU))),2);
        bufp->chgCData(oldp+2460,((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                           >> 7U))),4);
        bufp->chgCData(oldp+2461,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                         >> 5U))),2);
        bufp->chgBit(oldp+2462,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                       >> 1U))));
        bufp->chgQData(oldp+2463,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) 
                                    << 0x3fU) | (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U])) 
                                                  << 0x1fU) 
                                                 | ((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                                    >> 1U)))),64);
        bufp->chgBit(oldp+2465,((1U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])));
        bufp->chgWData(oldp+2466,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg),80);
        bufp->chgBit(oldp+2469,((6U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 0xdU)))));
        bufp->chgBit(oldp+2470,((((0U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                >> 5U))) 
                                  | (1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 5U)))) 
                                 | (2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                 >> 5U))))));
        bufp->chgBit(oldp+2471,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+2472,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                       >> 5U))));
        bufp->chgSData(oldp+2473,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__beats1),9);
        bufp->chgBit(oldp+2474,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__d_last));
        bufp->chgBit(oldp+2475,((1U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 0xdU)))));
        bufp->chgBit(oldp+2476,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__grantIsUncached));
        bufp->chgBit(oldp+2477,((5U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 0xdU)))));
        bufp->chgBit(oldp+2478,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__grantIsCached));
        bufp->chgQData(oldp+2479,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata),64);
        __Vtemp_h017094c4__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata);
        __Vtemp_h017094c4__0[1U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                            >> 0x20U));
        __Vtemp_h017094c4__0[2U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata);
        __Vtemp_h017094c4__0[3U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                            >> 0x20U));
        bufp->chgWData(oldp+2481,(__Vtemp_h017094c4__0),128);
        bufp->chgCData(oldp+2485,((0xffU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata))),8);
        bufp->chgCData(oldp+2486,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 8U)))),8);
        bufp->chgCData(oldp+2487,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 0x10U)))),8);
        bufp->chgCData(oldp+2488,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 0x18U)))),8);
        bufp->chgCData(oldp+2489,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 0x20U)))),8);
        bufp->chgCData(oldp+2490,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 0x28U)))),8);
        bufp->chgCData(oldp+2491,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 0x30U)))),8);
        bufp->chgCData(oldp+2492,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 0x38U)))),8);
        bufp->chgBit(oldp+2493,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError));
        bufp->chgSData(oldp+2494,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__beats1),9);
        bufp->chgSData(oldp+2495,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_cnt),9);
        __Vtemp_h9b14575f__0[0U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_h9b14575f__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_h9b14575f__0[2U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_h9b14575f__0[3U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_h9b14575f__0[4U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_h9b14575f__0[5U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_h9b14575f__0[6U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_h9b14575f__0[7U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        bufp->chgWData(oldp+2496,(__Vtemp_h9b14575f__0),256);
        bufp->chgIData(oldp+2504,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                    << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                 >> 1U))),32);
        __Vtemp_h9b93cb5f__0[0U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h9b93cb5f__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h9b93cb5f__0[2U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h9b93cb5f__0[3U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h9b93cb5f__0[4U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h9b93cb5f__0[5U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h9b93cb5f__0[6U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h9b93cb5f__0[7U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        bufp->chgWData(oldp+2505,(__Vtemp_h9b93cb5f__0),256);
        bufp->chgIData(oldp+2513,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                    << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                 >> 1U))),32);
        bufp->chgWData(oldp+2514,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata),168);
        bufp->chgIData(oldp+2520,((0x1fffffU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[0U])),21);
        bufp->chgIData(oldp+2521,((0x1fffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[1U] 
                                                 << 0xbU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[0U] 
                                                   >> 0x15U)))),21);
        bufp->chgIData(oldp+2522,((0x1fffffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[1U] 
                                                >> 0xaU))),21);
        bufp->chgIData(oldp+2523,((0x1fffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[2U] 
                                                 << 1U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[1U] 
                                                   >> 0x1fU)))),21);
        bufp->chgIData(oldp+2524,((0x1fffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[3U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[2U] 
                                                   >> 0x14U)))),21);
        bufp->chgIData(oldp+2525,((0x1fffffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[3U] 
                                                >> 9U))),21);
        bufp->chgIData(oldp+2526,((0x1fffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[4U] 
                                                 << 2U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[3U] 
                                                   >> 0x1eU)))),21);
        bufp->chgIData(oldp+2527,((0x1fffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[5U] 
                                                 << 0xdU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[4U] 
                                                   >> 0x13U)))),21);
        bufp->chgBit(oldp+2528,((2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 5U)))));
        bufp->chgBit(oldp+2529,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__same_cycle_resp));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x2cU])) {
        bufp->chgCData(oldp+2530,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__mem_0_sink),3);
        bufp->chgCData(oldp+2531,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__mem_1_sink),3);
        bufp->chgCData(oldp+2532,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__mem_2_sink),3);
        bufp->chgCData(oldp+2533,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__mem_3_sink),3);
        bufp->chgCData(oldp+2534,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__mem_4_sink),3);
        bufp->chgCData(oldp+2535,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__mem_5_sink),3);
        bufp->chgCData(oldp+2536,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__mem_6_sink),3);
        bufp->chgCData(oldp+2537,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__mem_7_sink),3);
        bufp->chgCData(oldp+2538,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                         >> 2U))),3);
        bufp->chgCData(oldp+2539,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                         >> 0xdU))),3);
        bufp->chgCData(oldp+2540,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                         >> 0xbU))),2);
        bufp->chgCData(oldp+2541,((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                           >> 7U))),4);
        bufp->chgCData(oldp+2542,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                         >> 5U))),2);
        bufp->chgBit(oldp+2543,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                       >> 1U))));
        bufp->chgQData(oldp+2544,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) 
                                    << 0x3fU) | (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U])) 
                                                  << 0x1fU) 
                                                 | ((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                                    >> 1U)))),64);
        bufp->chgBit(oldp+2546,((1U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])));
        bufp->chgWData(oldp+2547,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg),80);
        bufp->chgBit(oldp+2550,((6U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 0xdU)))));
        bufp->chgBit(oldp+2551,((((0U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                >> 5U))) 
                                  | (1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 5U)))) 
                                 | (2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                 >> 5U))))));
        bufp->chgBit(oldp+2552,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+2553,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                       >> 5U))));
        bufp->chgSData(oldp+2554,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__beats1),9);
        bufp->chgBit(oldp+2555,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__d_last));
        bufp->chgBit(oldp+2556,((1U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 0xdU)))));
        bufp->chgBit(oldp+2557,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__grantIsUncached));
        bufp->chgBit(oldp+2558,((5U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 0xdU)))));
        bufp->chgBit(oldp+2559,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__grantIsCached));
        bufp->chgQData(oldp+2560,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata),64);
        __Vtemp_hed165ee8__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata);
        __Vtemp_hed165ee8__0[1U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                            >> 0x20U));
        __Vtemp_hed165ee8__0[2U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata);
        __Vtemp_hed165ee8__0[3U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                            >> 0x20U));
        bufp->chgWData(oldp+2562,(__Vtemp_hed165ee8__0),128);
        bufp->chgCData(oldp+2566,((0xffU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata))),8);
        bufp->chgCData(oldp+2567,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 8U)))),8);
        bufp->chgCData(oldp+2568,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 0x10U)))),8);
        bufp->chgCData(oldp+2569,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 0x18U)))),8);
        bufp->chgCData(oldp+2570,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 0x20U)))),8);
        bufp->chgCData(oldp+2571,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 0x28U)))),8);
        bufp->chgCData(oldp+2572,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 0x30U)))),8);
        bufp->chgCData(oldp+2573,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 0x38U)))),8);
        bufp->chgBit(oldp+2574,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError));
        bufp->chgSData(oldp+2575,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__beats1),9);
        bufp->chgSData(oldp+2576,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_cnt),9);
        __Vtemp_hf77b9dbc__0[0U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_hf77b9dbc__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_hf77b9dbc__0[2U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_hf77b9dbc__0[3U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_hf77b9dbc__0[4U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_hf77b9dbc__0[5U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_hf77b9dbc__0[6U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_hf77b9dbc__0[7U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        bufp->chgWData(oldp+2577,(__Vtemp_hf77b9dbc__0),256);
        bufp->chgIData(oldp+2585,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                    << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                 >> 1U))),32);
        __Vtemp_h4da38fe0__0[0U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h4da38fe0__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h4da38fe0__0[2U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h4da38fe0__0[3U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h4da38fe0__0[4U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h4da38fe0__0[5U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h4da38fe0__0[6U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h4da38fe0__0[7U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        bufp->chgWData(oldp+2586,(__Vtemp_h4da38fe0__0),256);
        bufp->chgIData(oldp+2594,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                    << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                 >> 1U))),32);
        bufp->chgWData(oldp+2595,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata),168);
        bufp->chgIData(oldp+2601,((0x1fffffU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[0U])),21);
        bufp->chgIData(oldp+2602,((0x1fffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[1U] 
                                                 << 0xbU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[0U] 
                                                   >> 0x15U)))),21);
        bufp->chgIData(oldp+2603,((0x1fffffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[1U] 
                                                >> 0xaU))),21);
        bufp->chgIData(oldp+2604,((0x1fffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[2U] 
                                                 << 1U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[1U] 
                                                   >> 0x1fU)))),21);
        bufp->chgIData(oldp+2605,((0x1fffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[3U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[2U] 
                                                   >> 0x14U)))),21);
        bufp->chgIData(oldp+2606,((0x1fffffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[3U] 
                                                >> 9U))),21);
        bufp->chgIData(oldp+2607,((0x1fffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[4U] 
                                                 << 2U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[3U] 
                                                   >> 0x1eU)))),21);
        bufp->chgIData(oldp+2608,((0x1fffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[5U] 
                                                 << 0xdU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[4U] 
                                                   >> 0x13U)))),21);
        bufp->chgBit(oldp+2609,((2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 5U)))));
        bufp->chgBit(oldp+2610,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__same_cycle_resp));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x2dU])) {
        bufp->chgCData(oldp+2611,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__mem_0_sink),3);
        bufp->chgCData(oldp+2612,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__mem_1_sink),3);
        bufp->chgCData(oldp+2613,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__mem_2_sink),3);
        bufp->chgCData(oldp+2614,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__mem_3_sink),3);
        bufp->chgCData(oldp+2615,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__mem_4_sink),3);
        bufp->chgCData(oldp+2616,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__mem_5_sink),3);
        bufp->chgCData(oldp+2617,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__mem_6_sink),3);
        bufp->chgCData(oldp+2618,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__mem_7_sink),3);
        bufp->chgCData(oldp+2619,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                         >> 2U))),3);
        bufp->chgCData(oldp+2620,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                         >> 0xdU))),3);
        bufp->chgCData(oldp+2621,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                         >> 0xbU))),2);
        bufp->chgCData(oldp+2622,((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                           >> 7U))),4);
        bufp->chgCData(oldp+2623,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                         >> 5U))),2);
        bufp->chgBit(oldp+2624,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                       >> 1U))));
        bufp->chgQData(oldp+2625,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) 
                                    << 0x3fU) | (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U])) 
                                                  << 0x1fU) 
                                                 | ((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                                    >> 1U)))),64);
        bufp->chgBit(oldp+2627,((1U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])));
        bufp->chgWData(oldp+2628,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg),80);
        bufp->chgBit(oldp+2631,((6U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 0xdU)))));
        bufp->chgBit(oldp+2632,((((0U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                >> 5U))) 
                                  | (1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 5U)))) 
                                 | (2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                 >> 5U))))));
        bufp->chgBit(oldp+2633,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+2634,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                       >> 5U))));
        bufp->chgSData(oldp+2635,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__beats1),9);
        bufp->chgBit(oldp+2636,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__d_last));
        bufp->chgBit(oldp+2637,((1U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 0xdU)))));
        bufp->chgBit(oldp+2638,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__grantIsUncached));
        bufp->chgBit(oldp+2639,((5U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 0xdU)))));
        bufp->chgBit(oldp+2640,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__grantIsCached));
        bufp->chgQData(oldp+2641,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata),64);
        __Vtemp_hfcec72af__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata);
        __Vtemp_hfcec72af__0[1U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                            >> 0x20U));
        __Vtemp_hfcec72af__0[2U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata);
        __Vtemp_hfcec72af__0[3U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                            >> 0x20U));
        bufp->chgWData(oldp+2643,(__Vtemp_hfcec72af__0),128);
        bufp->chgCData(oldp+2647,((0xffU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata))),8);
        bufp->chgCData(oldp+2648,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 8U)))),8);
        bufp->chgCData(oldp+2649,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 0x10U)))),8);
        bufp->chgCData(oldp+2650,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 0x18U)))),8);
        bufp->chgCData(oldp+2651,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 0x20U)))),8);
        bufp->chgCData(oldp+2652,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 0x28U)))),8);
        bufp->chgCData(oldp+2653,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 0x30U)))),8);
        bufp->chgCData(oldp+2654,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 0x38U)))),8);
        bufp->chgBit(oldp+2655,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError));
        bufp->chgSData(oldp+2656,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__beats1),9);
        bufp->chgSData(oldp+2657,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_cnt),9);
        __Vtemp_heaf20e4b__0[0U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_heaf20e4b__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_heaf20e4b__0[2U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_heaf20e4b__0[3U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_heaf20e4b__0[4U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_heaf20e4b__0[5U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_heaf20e4b__0[6U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_heaf20e4b__0[7U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        bufp->chgWData(oldp+2658,(__Vtemp_heaf20e4b__0),256);
        bufp->chgIData(oldp+2666,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                    << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                 >> 1U))),32);
        __Vtemp_h1071e998__0[0U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h1071e998__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h1071e998__0[2U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h1071e998__0[3U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h1071e998__0[4U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h1071e998__0[5U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h1071e998__0[6U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h1071e998__0[7U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        bufp->chgWData(oldp+2667,(__Vtemp_h1071e998__0),256);
        bufp->chgIData(oldp+2675,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                    << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                 >> 1U))),32);
        bufp->chgWData(oldp+2676,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata),168);
        bufp->chgIData(oldp+2682,((0x1fffffU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[0U])),21);
        bufp->chgIData(oldp+2683,((0x1fffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[1U] 
                                                 << 0xbU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[0U] 
                                                   >> 0x15U)))),21);
        bufp->chgIData(oldp+2684,((0x1fffffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[1U] 
                                                >> 0xaU))),21);
        bufp->chgIData(oldp+2685,((0x1fffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[2U] 
                                                 << 1U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[1U] 
                                                   >> 0x1fU)))),21);
        bufp->chgIData(oldp+2686,((0x1fffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[3U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[2U] 
                                                   >> 0x14U)))),21);
        bufp->chgIData(oldp+2687,((0x1fffffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[3U] 
                                                >> 9U))),21);
        bufp->chgIData(oldp+2688,((0x1fffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[4U] 
                                                 << 2U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[3U] 
                                                   >> 0x1eU)))),21);
        bufp->chgIData(oldp+2689,((0x1fffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[5U] 
                                                 << 0xdU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[4U] 
                                                   >> 0x13U)))),21);
        bufp->chgBit(oldp+2690,((2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 5U)))));
        bufp->chgBit(oldp+2691,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__same_cycle_resp));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x2eU])) {
        bufp->chgCData(oldp+2692,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__mem_0_sink),3);
        bufp->chgCData(oldp+2693,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__mem_1_sink),3);
        bufp->chgCData(oldp+2694,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__mem_2_sink),3);
        bufp->chgCData(oldp+2695,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__mem_3_sink),3);
        bufp->chgCData(oldp+2696,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__mem_4_sink),3);
        bufp->chgCData(oldp+2697,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__mem_5_sink),3);
        bufp->chgCData(oldp+2698,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__mem_6_sink),3);
        bufp->chgCData(oldp+2699,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__mem_7_sink),3);
        bufp->chgCData(oldp+2700,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                         >> 2U))),3);
        bufp->chgCData(oldp+2701,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                         >> 0xdU))),3);
        bufp->chgCData(oldp+2702,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                         >> 0xbU))),2);
        bufp->chgCData(oldp+2703,((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                           >> 7U))),4);
        bufp->chgCData(oldp+2704,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                         >> 5U))),2);
        bufp->chgBit(oldp+2705,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                       >> 1U))));
        bufp->chgQData(oldp+2706,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U])) 
                                    << 0x3fU) | (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U])) 
                                                  << 0x1fU) 
                                                 | ((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                                                    >> 1U)))),64);
        bufp->chgBit(oldp+2708,((1U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])));
        bufp->chgWData(oldp+2709,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg),80);
        bufp->chgBit(oldp+2712,((6U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 0xdU)))));
        bufp->chgBit(oldp+2713,((((0U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                >> 5U))) 
                                  | (1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                  >> 5U)))) 
                                 | (2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                 >> 5U))))));
        bufp->chgBit(oldp+2714,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+2715,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                       >> 5U))));
        bufp->chgSData(oldp+2716,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__beats1),9);
        bufp->chgBit(oldp+2717,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__d_last));
        bufp->chgBit(oldp+2718,((1U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 0xdU)))));
        bufp->chgBit(oldp+2719,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__grantIsUncached));
        bufp->chgBit(oldp+2720,((5U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 0xdU)))));
        bufp->chgBit(oldp+2721,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__grantIsCached));
        bufp->chgQData(oldp+2722,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata),64);
        __Vtemp_hdbb986da__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata);
        __Vtemp_hdbb986da__0[1U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                            >> 0x20U));
        __Vtemp_hdbb986da__0[2U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata);
        __Vtemp_hdbb986da__0[3U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                            >> 0x20U));
        bufp->chgWData(oldp+2724,(__Vtemp_hdbb986da__0),128);
        bufp->chgCData(oldp+2728,((0xffU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata))),8);
        bufp->chgCData(oldp+2729,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 8U)))),8);
        bufp->chgCData(oldp+2730,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 0x10U)))),8);
        bufp->chgCData(oldp+2731,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 0x18U)))),8);
        bufp->chgCData(oldp+2732,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 0x20U)))),8);
        bufp->chgCData(oldp+2733,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 0x28U)))),8);
        bufp->chgCData(oldp+2734,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 0x30U)))),8);
        bufp->chgCData(oldp+2735,((0xffU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__data__io_req_bits_wdata 
                                                    >> 0x38U)))),8);
        bufp->chgBit(oldp+2736,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refillError));
        bufp->chgSData(oldp+2737,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__beats1),9);
        bufp->chgSData(oldp+2738,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_cnt),9);
        __Vtemp_h18615b55__0[0U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_h18615b55__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_h18615b55__0[2U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_h18615b55__0[3U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_h18615b55__0[4U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_h18615b55__0[5U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_h18615b55__0[6U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        __Vtemp_h18615b55__0[7U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                  >> 1U));
        bufp->chgWData(oldp+2739,(__Vtemp_h18615b55__0),256);
        bufp->chgIData(oldp+2747,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                    << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U] 
                                                 >> 1U))),32);
        __Vtemp_h18ad1821__0[0U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h18ad1821__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h18ad1821__0[2U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h18ad1821__0[3U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h18ad1821__0[4U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h18ad1821__0[5U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h18ad1821__0[6U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        __Vtemp_h18ad1821__0[7U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                  >> 1U));
        bufp->chgWData(oldp+2748,(__Vtemp_h18ad1821__0),256);
        bufp->chgIData(oldp+2756,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                    << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[1U] 
                                                 >> 1U))),32);
        bufp->chgWData(oldp+2757,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata),168);
        bufp->chgIData(oldp+2763,((0x1fffffU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[0U])),21);
        bufp->chgIData(oldp+2764,((0x1fffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[1U] 
                                                 << 0xbU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[0U] 
                                                   >> 0x15U)))),21);
        bufp->chgIData(oldp+2765,((0x1fffffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[1U] 
                                                >> 0xaU))),21);
        bufp->chgIData(oldp+2766,((0x1fffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[2U] 
                                                 << 1U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[1U] 
                                                   >> 0x1fU)))),21);
        bufp->chgIData(oldp+2767,((0x1fffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[3U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[2U] 
                                                   >> 0x14U)))),21);
        bufp->chgIData(oldp+2768,((0x1fffffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[3U] 
                                                >> 9U))),21);
        bufp->chgIData(oldp+2769,((0x1fffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[4U] 
                                                 << 2U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[3U] 
                                                   >> 0x1eU)))),21);
        bufp->chgIData(oldp+2770,((0x1fffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[5U] 
                                                 << 0xdU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wdata[4U] 
                                                   >> 0x13U)))),21);
        bufp->chgBit(oldp+2771,((2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 5U)))));
        bufp->chgBit(oldp+2772,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__same_cycle_resp));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x2fU])) {
        bufp->chgIData(oldp+2773,(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT__data[0U]),32);
        bufp->chgIData(oldp+2774,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__mem_0),32);
        bufp->chgIData(oldp+2775,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__mem_1),32);
        bufp->chgIData(oldp+2776,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__mem_2),32);
        bufp->chgIData(oldp+2777,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__mem_3),32);
        bufp->chgIData(oldp+2778,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__mem_4),32);
        bufp->chgIData(oldp+2779,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__mem_5),32);
        bufp->chgIData(oldp+2780,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__mem_6),32);
        bufp->chgIData(oldp+2781,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__source__DOT__mem_7),32);
        bufp->chgBit(oldp+2782,(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxm__DOT__out));
        bufp->chgWData(oldp+2783,(vlSelf->TestHarness__DOT__ram__DOT__serdesser__DOT__outSer__DOT__data),123);
        bufp->chgBit(oldp+2787,((1U & (~ (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__empty)))));
        bufp->chgCData(oldp+2788,(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__ram_ext__DOT__Memory
                                  [vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__deq_ptr_value]),8);
        bufp->chgSData(oldp+2789,(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxm__DOT__shifter),9);
        bufp->chgBit(oldp+2790,((1U & (~ (IData)(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__full)))));
        bufp->chgCData(oldp+2791,(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__deq_ptr_value),3);
        bufp->chgBit(oldp+2792,(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__ptr_match));
        bufp->chgBit(oldp+2793,(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__empty));
        bufp->chgBit(oldp+2794,(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__full));
        bufp->chgBit(oldp+2795,(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__do_enq));
        bufp->chgBit(oldp+2796,(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__do_deq));
        bufp->chgCData(oldp+2797,(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__ram_ext__DOT__Memory[0]),8);
        bufp->chgCData(oldp+2798,(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__ram_ext__DOT__Memory[1]),8);
        bufp->chgCData(oldp+2799,(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__ram_ext__DOT__Memory[2]),8);
        bufp->chgCData(oldp+2800,(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__ram_ext__DOT__Memory[3]),8);
        bufp->chgCData(oldp+2801,(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__ram_ext__DOT__Memory[4]),8);
        bufp->chgCData(oldp+2802,(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__ram_ext__DOT__Memory[5]),8);
        bufp->chgCData(oldp+2803,(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__ram_ext__DOT__Memory[6]),8);
        bufp->chgCData(oldp+2804,(vlSelf->TestHarness__DOT__uart_sim_0__DOT__rxq__DOT__ram_ext__DOT__Memory[7]),8);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x30U])) {
        bufp->chgWData(oldp+2805,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_a_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d),117);
        bufp->chgWData(oldp+2809,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d),109);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x31U])) {
        bufp->chgWData(oldp+2813,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_a_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d),117);
        bufp->chgWData(oldp+2817,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d),109);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x32U])) {
        bufp->chgWData(oldp+2821,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_a_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d),117);
        bufp->chgWData(oldp+2825,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d),109);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x33U])) {
        bufp->chgWData(oldp+2829,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d),117);
        bufp->chgWData(oldp+2833,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d),109);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x34U])) {
        bufp->chgBit(oldp+2837,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2838,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2839,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2840,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2841,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2842,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2843,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2844,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2845,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2846,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2847,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2848,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2849,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2850,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2851,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2852,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2853,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2854,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2855,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2856,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2857,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2858,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2859,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2860,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2861,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2862,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2863,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2864,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2865,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2866,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2867,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2868,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2869,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2870,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2871,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2872,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_a_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2873,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2874,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2875,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2876,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2877,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_c_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2878,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2879,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2880,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2881,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2882,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__x1_e_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x35U])) {
        bufp->chgBit(oldp+2883,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2884,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2885,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2886,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2887,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2888,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2889,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2890,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2891,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2892,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2893,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2894,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2895,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2896,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2897,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2898,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2899,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2900,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2901,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2902,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2903,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2904,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2905,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2906,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2907,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2908,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2909,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2910,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2911,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2912,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2913,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2914,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2915,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2916,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2917,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2918,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_a_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2919,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2920,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2921,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2922,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2923,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_c_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2924,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2925,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2926,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2927,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2928,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__x1_e_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x36U])) {
        bufp->chgBit(oldp+2929,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2930,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2931,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2932,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2933,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2934,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2935,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2936,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2937,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2938,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2939,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2940,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2941,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2942,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2943,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2944,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2945,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2946,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2947,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2948,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2949,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2950,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2951,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2952,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2953,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2954,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2955,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2956,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2957,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2958,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2959,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2960,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2961,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2962,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2963,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2964,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2965,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2966,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2967,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2968,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2969,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2970,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2971,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2972,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2973,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2974,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x37U])) {
        bufp->chgBit(oldp+2975,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2976,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2977,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2978,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2979,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2980,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2981,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2982,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2983,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2984,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2985,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__sink_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2986,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2987,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2988,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2989,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__source_valid_0__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2990,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2991,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2992,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2993,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2994,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2995,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2996,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+2997,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+2998,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+2999,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+3000,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+3001,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+3002,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+3003,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+3004,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+3005,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+3006,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+3007,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+3008,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+3009,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+3010,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+3011,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+3012,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+3013,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+3014,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+3015,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+3016,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+3017,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+3018,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__source_valid_0__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+3019,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+3020,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x38U])) {
        bufp->chgBit(oldp+3021,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output));
        bufp->chgCData(oldp+3022,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_bootrom_fragmenter_out_a_bits_opcode),3);
        bufp->chgCData(oldp+3023,((3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__aFrag))),2);
        bufp->chgSData(oldp+3024,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_bootrom_fragmenter_out_a_bits_source),11);
        bufp->chgIData(oldp+3025,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_bootrom_fragmenter_out_a_bits_address),17);
        bufp->chgBit(oldp+3026,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_6_d_ready));
        bufp->chgQData(oldp+3027,(((0U != (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_bootrom_fragmenter_out_a_bits_address 
                                                 >> 0xdU)))
                                    ? 0ULL : (((QData)((IData)(
                                                               VTestHarness__ConstPool__CONST_h5f0e7fd6_0[
                                                               (((IData)(0x3fU) 
                                                                 + 
                                                                 (0xffc0U 
                                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_bootrom_fragmenter_out_a_bits_address 
                                                                     << 3U))) 
                                                                >> 5U)])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                VTestHarness__ConstPool__CONST_h5f0e7fd6_0[
                                                                (0x7feU 
                                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_bootrom_fragmenter_out_a_bits_address 
                                                                    >> 2U))]))))),64);
        bufp->chgBit(oldp+3029,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__a_first_done));
        bufp->chgBit(oldp+3030,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__d_first_done));
        bufp->chgBit(oldp+3031,((2U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__aFrag)))));
        bufp->chgBit(oldp+3032,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+3033,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+3034,((1U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__aFrag)))));
        bufp->chgBit(oldp+3035,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+3036,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+3037,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+3038,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+3039,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+3040,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+3041,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+3042,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+3043,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__mask_acc_5) 
                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__mask_eq_5) 
                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_bootrom_fragmenter_out_a_bits_address)) 
                                    << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__mask_acc_5) 
                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__mask_eq_5) 
                                                   & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_bootrom_fragmenter_out_a_bits_address))) 
                                               << 6U) 
                                              | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__mask_acc_4) 
                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__mask_eq_4) 
                                                      & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_bootrom_fragmenter_out_a_bits_address)) 
                                                  << 5U) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__mask_acc_4) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__mask_eq_4) 
                                                         & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_bootrom_fragmenter_out_a_bits_address))) 
                                                     << 4U) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__mask_acc_3) 
                                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__mask_eq_3) 
                                                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_bootrom_fragmenter_out_a_bits_address)) 
                                                        << 3U) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__mask_acc_3) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__mask_eq_3) 
                                                               & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_bootrom_fragmenter_out_a_bits_address))) 
                                                           << 2U) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__mask_acc_2) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__mask_eq_2) 
                                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_bootrom_fragmenter_out_a_bits_address)) 
                                                              << 1U) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__mask_eq_2) 
                                                                   & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_bootrom_fragmenter_out_a_bits_address))))))))))),8);
        bufp->chgBit(oldp+3044,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output));
        bufp->chgCData(oldp+3045,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode),3);
        bufp->chgCData(oldp+3046,((3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__aFrag))),2);
        bufp->chgSData(oldp+3047,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_clint_fragmenter_out_a_bits_source),11);
        bufp->chgIData(oldp+3048,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_clint_fragmenter_out_a_bits_address),26);
        bufp->chgCData(oldp+3049,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_clint_fragmenter_out_a_bits_mask),8);
        bufp->chgQData(oldp+3050,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                                    << 0x28U) | (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                                                  << 8U) 
                                                 | ((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                                    >> 0x18U)))),64);
        bufp->chgBit(oldp+3052,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__x1_d_ready));
        bufp->chgBit(oldp+3053,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__ipi_4));
        bufp->chgBit(oldp+3054,((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0 
                                 >= vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_4)));
        bufp->chgBit(oldp+3055,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__ipi_3));
        bufp->chgBit(oldp+3056,((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0 
                                 >= vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_3)));
        bufp->chgBit(oldp+3057,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__ipi_2));
        bufp->chgBit(oldp+3058,((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0 
                                 >= vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_2)));
        bufp->chgBit(oldp+3059,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__ipi_1));
        bufp->chgBit(oldp+3060,((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0 
                                 >= vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_1)));
        bufp->chgBit(oldp+3061,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__ipi_0));
        bufp->chgBit(oldp+3062,((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0 
                                 >= vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_0)));
        bufp->chgCData(oldp+3063,((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))),3);
        VL_EXTEND_WQ(256,64, __Vtemp_h33641d2a__0, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_4);
        __Vtemp_h8236c4c9__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__ipi_0;
        __Vtemp_h8236c4c9__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__ipi_1;
        __Vtemp_h8236c4c9__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__ipi_2;
        __Vtemp_h8236c4c9__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__ipi_3;
        __Vtemp_h8236c4c9__0[4U] = (IData)((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__ipi_4)));
        __Vtemp_h8236c4c9__0[5U] = (IData)(((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__ipi_4)) 
                                            >> 0x20U));
        __Vtemp_h8236c4c9__0[6U] = 0U;
        __Vtemp_h8236c4c9__0[7U] = 0U;
        __Vtemp_h8236c4c9__0[8U] = 0U;
        __Vtemp_h8236c4c9__0[9U] = 0U;
        __Vtemp_h8236c4c9__0[0xaU] = 0U;
        __Vtemp_h8236c4c9__0[0xbU] = 0U;
        __Vtemp_h8236c4c9__0[0xcU] = 0U;
        __Vtemp_h8236c4c9__0[0xdU] = 0U;
        __Vtemp_h8236c4c9__0[0xeU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0);
        __Vtemp_h8236c4c9__0[0xfU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0 
                                              >> 0x20U));
        __Vtemp_h8236c4c9__0[0x10U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_0);
        __Vtemp_h8236c4c9__0[0x11U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_0 
                                               >> 0x20U));
        __Vtemp_h8236c4c9__0[0x12U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_1);
        __Vtemp_h8236c4c9__0[0x13U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_1 
                                               >> 0x20U));
        __Vtemp_h8236c4c9__0[0x14U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_2);
        __Vtemp_h8236c4c9__0[0x15U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_2 
                                               >> 0x20U));
        __Vtemp_h8236c4c9__0[0x16U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_3);
        __Vtemp_h8236c4c9__0[0x17U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_3 
                                               >> 0x20U));
        __Vtemp_h8236c4c9__0[0x18U] = __Vtemp_h33641d2a__0[0U];
        __Vtemp_h8236c4c9__0[0x19U] = __Vtemp_h33641d2a__0[1U];
        __Vtemp_h8236c4c9__0[0x1aU] = __Vtemp_h33641d2a__0[2U];
        __Vtemp_h8236c4c9__0[0x1bU] = __Vtemp_h33641d2a__0[3U];
        __Vtemp_h8236c4c9__0[0x1cU] = __Vtemp_h33641d2a__0[4U];
        __Vtemp_h8236c4c9__0[0x1dU] = __Vtemp_h33641d2a__0[5U];
        __Vtemp_h8236c4c9__0[0x1eU] = __Vtemp_h33641d2a__0[6U];
        __Vtemp_h8236c4c9__0[0x1fU] = __Vtemp_h33641d2a__0[7U];
        bufp->chgQData(oldp+3064,(((1U & ((0xe078U 
                                           | (((0U 
                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT___GEN)) 
                                               << 0xcU) 
                                              | (((0U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT___GEN)) 
                                                  << 0xbU) 
                                                 | (((0U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT___GEN)) 
                                                     << 0xaU) 
                                                    | (((0U 
                                                         == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT___GEN)) 
                                                        << 9U) 
                                                       | (((0U 
                                                            == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT___GEN)) 
                                                           << 8U) 
                                                          | (((IData)(
                                                                      (0x1ffU 
                                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT___GEN))) 
                                                              << 7U) 
                                                             | (7U 
                                                                & (- (IData)(
                                                                             (0U 
                                                                              == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT___GEN)))))))))))) 
                                          >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_oindex)))
                                    ? (((QData)((IData)(
                                                        __Vtemp_h8236c4c9__0[
                                                        (((IData)(0x3fU) 
                                                          + 
                                                          (0x3ffU 
                                                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_oindex) 
                                                              << 6U))) 
                                                         >> 5U)])) 
                                        << ((0U == 
                                             (0x1fU 
                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_oindex) 
                                                 << 6U)))
                                             ? 0x20U
                                             : ((IData)(0x40U) 
                                                - (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_oindex) 
                                                      << 6U))))) 
                                       | (((0U == (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_oindex) 
                                                      << 6U)))
                                            ? 0ULL : 
                                           ((QData)((IData)(
                                                            __Vtemp_h8236c4c9__0[
                                                            (((IData)(0x1fU) 
                                                              + 
                                                              (0x3ffU 
                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_oindex) 
                                                                  << 6U))) 
                                                             >> 5U)])) 
                                            << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_oindex) 
                                                      << 6U))))) 
                                          | ((QData)((IData)(
                                                             __Vtemp_h8236c4c9__0[
                                                             (0x1eU 
                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_oindex) 
                                                                 << 1U))])) 
                                             >> (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_oindex) 
                                                    << 6U)))))
                                    : 0ULL)),64);
        bufp->chgBit(oldp+3066,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_woready_31));
        bufp->chgBit(oldp+3067,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_woready_49));
        bufp->chgBit(oldp+3068,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_woready_57));
        bufp->chgBit(oldp+3069,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_woready_11));
        bufp->chgBit(oldp+3070,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_woready_41));
        bufp->chgBit(oldp+3071,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_woready_23));
        bufp->chgQData(oldp+3072,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0),64);
        bufp->chgQData(oldp+3074,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_0),64);
        bufp->chgQData(oldp+3076,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_1),64);
        bufp->chgQData(oldp+3078,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_2),64);
        bufp->chgQData(oldp+3080,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_3),64);
        bufp->chgQData(oldp+3082,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_4),64);
        bufp->chgBit(oldp+3084,((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))));
        bufp->chgBit(oldp+3085,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_1_0));
        bufp->chgBit(oldp+3086,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_1_1));
        bufp->chgBit(oldp+3087,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_1_2));
        bufp->chgBit(oldp+3088,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_1_3));
        bufp->chgBit(oldp+3089,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_1_4));
        bufp->chgBit(oldp+3090,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_1_5));
        bufp->chgBit(oldp+3091,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_1_6));
        bufp->chgBit(oldp+3092,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_1_7));
        bufp->chgBit(oldp+3093,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_5_0));
        bufp->chgBit(oldp+3094,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_5_1));
        bufp->chgBit(oldp+3095,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_5_2));
        bufp->chgBit(oldp+3096,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_5_3));
        bufp->chgBit(oldp+3097,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_5_4));
        bufp->chgBit(oldp+3098,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_5_5));
        bufp->chgBit(oldp+3099,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_5_6));
        bufp->chgBit(oldp+3100,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_5_7));
        bufp->chgBit(oldp+3101,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_4_0));
        bufp->chgBit(oldp+3102,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_4_1));
        bufp->chgBit(oldp+3103,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_4_2));
        bufp->chgBit(oldp+3104,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_4_3));
        bufp->chgBit(oldp+3105,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_4_4));
        bufp->chgBit(oldp+3106,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_4_5));
        bufp->chgBit(oldp+3107,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_4_6));
        bufp->chgBit(oldp+3108,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_4_7));
        bufp->chgBit(oldp+3109,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_0));
        bufp->chgBit(oldp+3110,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_1));
        bufp->chgBit(oldp+3111,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_2));
        bufp->chgBit(oldp+3112,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_3));
        bufp->chgBit(oldp+3113,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_4));
        bufp->chgBit(oldp+3114,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_5));
        bufp->chgBit(oldp+3115,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_6));
        bufp->chgBit(oldp+3116,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_7));
        bufp->chgBit(oldp+3117,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_3_0));
        bufp->chgBit(oldp+3118,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_3_1));
        bufp->chgBit(oldp+3119,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_3_2));
        bufp->chgBit(oldp+3120,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_3_3));
        bufp->chgBit(oldp+3121,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_3_4));
        bufp->chgBit(oldp+3122,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_3_5));
        bufp->chgBit(oldp+3123,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_3_6));
        bufp->chgBit(oldp+3124,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_3_7));
        bufp->chgBit(oldp+3125,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_2_0));
        bufp->chgBit(oldp+3126,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_2_1));
        bufp->chgBit(oldp+3127,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_2_2));
        bufp->chgBit(oldp+3128,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_2_3));
        bufp->chgBit(oldp+3129,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_2_4));
        bufp->chgBit(oldp+3130,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_2_5));
        bufp->chgBit(oldp+3131,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_2_6));
        bufp->chgBit(oldp+3132,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__valids_2_7));
        bufp->chgCData(oldp+3133,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_oindex),4);
        bufp->chgBit(oldp+3134,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_woready_2));
        bufp->chgBit(oldp+3135,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__out_woready_14));
        bufp->chgBit(oldp+3136,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__a_first_done));
        bufp->chgBit(oldp+3137,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__d_first_done));
        bufp->chgBit(oldp+3138,((2U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__aFrag)))));
        bufp->chgBit(oldp+3139,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+3140,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+3141,((1U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__aFrag)))));
        bufp->chgBit(oldp+3142,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+3143,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+3144,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+3145,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+3146,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+3147,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+3148,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+3149,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+3150,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__mask_acc_5) 
                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__mask_eq_5) 
                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_clint_fragmenter_out_a_bits_address)) 
                                    << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__mask_acc_5) 
                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__mask_eq_5) 
                                                   & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_clint_fragmenter_out_a_bits_address))) 
                                               << 6U) 
                                              | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__mask_acc_4) 
                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__mask_eq_4) 
                                                      & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_clint_fragmenter_out_a_bits_address)) 
                                                  << 5U) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__mask_acc_4) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__mask_eq_4) 
                                                         & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_clint_fragmenter_out_a_bits_address))) 
                                                     << 4U) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__mask_acc_3) 
                                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__mask_eq_3) 
                                                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_clint_fragmenter_out_a_bits_address)) 
                                                        << 3U) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__mask_acc_3) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__mask_eq_3) 
                                                               & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_clint_fragmenter_out_a_bits_address))) 
                                                           << 2U) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__mask_acc_2) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__mask_eq_2) 
                                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_clint_fragmenter_out_a_bits_address)) 
                                                              << 1U) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__mask_eq_2) 
                                                                   & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_clint_fragmenter_out_a_bits_address))))))))))),8);
        bufp->chgCData(oldp+3151,((((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0 
                                     >= vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_0) 
                                    << 1U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__ipi_0))),2);
        bufp->chgBit(oldp+3152,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__x1_0_REG) 
                                 > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__threshold_0))));
        bufp->chgBit(oldp+3153,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__bundleOut_6_0_REG) 
                                 > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__threshold_6))));
        bufp->chgBit(oldp+3154,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__bundleOut_7_0_REG) 
                                 > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__threshold_7))));
        bufp->chgCData(oldp+3155,((((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0 
                                     >= vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_4) 
                                    << 1U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__ipi_4))),2);
        bufp->chgBit(oldp+3156,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__bundleOut_8_0_REG) 
                                 > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__threshold_8))));
        bufp->chgBit(oldp+3157,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__bundleOut_9_0_REG) 
                                 > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__threshold_9))));
        bufp->chgBit(oldp+3158,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__bundleOut_1_0_REG) 
                                 > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__threshold_1))));
        bufp->chgCData(oldp+3159,((((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0 
                                     >= vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_1) 
                                    << 1U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__ipi_1))),2);
        bufp->chgBit(oldp+3160,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__bundleOut_2_0_REG) 
                                 > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__threshold_2))));
        bufp->chgBit(oldp+3161,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__bundleOut_3_0_REG) 
                                 > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__threshold_3))));
        bufp->chgCData(oldp+3162,((((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0 
                                     >= vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_2) 
                                    << 1U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__ipi_2))),2);
        bufp->chgBit(oldp+3163,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__bundleOut_4_0_REG) 
                                 > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__threshold_4))));
        bufp->chgBit(oldp+3164,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__bundleOut_5_0_REG) 
                                 > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__threshold_5))));
        bufp->chgCData(oldp+3165,((((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0 
                                     >= vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_3) 
                                    << 1U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__ipi_3))),2);
        bufp->chgBit(oldp+3166,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output));
        bufp->chgCData(oldp+3167,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode),3);
        bufp->chgCData(oldp+3168,((3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__aFrag))),2);
        bufp->chgSData(oldp+3169,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_plic_fragmenter_out_a_bits_source),11);
        bufp->chgIData(oldp+3170,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_plic_fragmenter_out_a_bits_address),28);
        bufp->chgCData(oldp+3171,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_plic_fragmenter_out_a_bits_mask),8);
        bufp->chgBit(oldp+3172,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__x1_d_ready));
        bufp->chgCData(oldp+3173,((1U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_back__DOT__ram_ext__DOT__Memory
                                   [0U][0U])),3);
        bufp->chgCData(oldp+3174,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_back__DOT__ram_ext__DOT__Memory
                                         [0U][3U] >> 0xbU))),2);
        bufp->chgSData(oldp+3175,((0x7ffU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_back__DOT__ram_ext__DOT__Memory
                                   [0U][3U])),11);
        bufp->chgQData(oldp+3176,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___plicDomainWrapper_auto_plic_in_d_bits_data),64);
        bufp->chgBit(oldp+3178,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_woready_5));
        bufp->chgBit(oldp+3179,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_woready_13));
        bufp->chgBit(oldp+3180,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_woready_22));
        bufp->chgBit(oldp+3181,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_woready_31));
        bufp->chgBit(oldp+3182,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_woready_2));
        bufp->chgBit(oldp+3183,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_woready_10));
        bufp->chgBit(oldp+3184,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_woready_19));
        bufp->chgBit(oldp+3185,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_woready_28));
        bufp->chgBit(oldp+3186,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_woready_16));
        bufp->chgBit(oldp+3187,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_woready_25));
        bufp->chgBit(oldp+3188,((0x190U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___GEN_0))));
        bufp->chgBit(oldp+3189,((0x180U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___GEN_0))));
        bufp->chgBit(oldp+3190,((0x170U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___GEN_0))));
        bufp->chgBit(oldp+3191,((0x160U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___GEN_0))));
        bufp->chgBit(oldp+3192,((0x150U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___GEN_0))));
        bufp->chgBit(oldp+3193,((0x140U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___GEN_0))));
        bufp->chgBit(oldp+3194,((0x130U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___GEN_0))));
        bufp->chgBit(oldp+3195,((0x120U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___GEN_0))));
        bufp->chgBit(oldp+3196,((0x110U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___GEN_0))));
        bufp->chgBit(oldp+3197,((0x100U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___GEN_0))));
        bufp->chgBit(oldp+3198,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_back__DOT__ram_ext__DOT__Memory
                                       [0U][1U] >> 0x18U))));
        bufp->chgBit(oldp+3199,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__priority_0));
        bufp->chgBit(oldp+3200,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__threshold_0));
        bufp->chgBit(oldp+3201,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__threshold_1));
        bufp->chgBit(oldp+3202,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__threshold_2));
        bufp->chgBit(oldp+3203,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__threshold_3));
        bufp->chgBit(oldp+3204,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__threshold_4));
        bufp->chgBit(oldp+3205,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__threshold_5));
        bufp->chgBit(oldp+3206,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__threshold_6));
        bufp->chgBit(oldp+3207,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__threshold_7));
        bufp->chgBit(oldp+3208,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__threshold_8));
        bufp->chgBit(oldp+3209,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__threshold_9));
        bufp->chgBit(oldp+3210,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__x1_0_REG));
        bufp->chgBit(oldp+3211,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__bundleOut_1_0_REG));
        bufp->chgBit(oldp+3212,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__bundleOut_2_0_REG));
        bufp->chgBit(oldp+3213,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__bundleOut_3_0_REG));
        bufp->chgBit(oldp+3214,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__bundleOut_4_0_REG));
        bufp->chgBit(oldp+3215,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__bundleOut_5_0_REG));
        bufp->chgBit(oldp+3216,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__bundleOut_6_0_REG));
        bufp->chgBit(oldp+3217,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__bundleOut_7_0_REG));
        bufp->chgBit(oldp+3218,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__bundleOut_8_0_REG));
        bufp->chgBit(oldp+3219,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__bundleOut_9_0_REG));
        bufp->chgBit(oldp+3220,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_rofireMux_T_1) 
                                   & (0x150U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___GEN_0))) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_T_43)) 
                                 & (0U != vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_womask_T_31))));
        bufp->chgBit(oldp+3221,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_rofireMux_T_1) 
                                   & (0x190U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___GEN_0))) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_T_43)) 
                                 & (0U != vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_womask_T_31))));
        bufp->chgBit(oldp+3222,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_rofireMux_T_1) 
                                   & (0x140U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___GEN_0))) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_T_43)) 
                                 & (0U != vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_womask_T_31))));
        bufp->chgBit(oldp+3223,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_rofireMux_T_1) 
                                   & (0x180U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___GEN_0))) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_T_43)) 
                                 & (0U != vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_womask_T_31))));
        bufp->chgBit(oldp+3224,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_rofireMux_T_1) 
                                   & (0x110U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___GEN_0))) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_T_43)) 
                                 & (0U != vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_womask_T_31))));
        bufp->chgBit(oldp+3225,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_rofireMux_T_1) 
                                   & (0x130U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___GEN_0))) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_T_43)) 
                                 & (0U != vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_womask_T_31))));
        bufp->chgBit(oldp+3226,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_rofireMux_T_1) 
                                   & (0x170U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___GEN_0))) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_T_43)) 
                                 & (0U != vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_womask_T_31))));
        bufp->chgBit(oldp+3227,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_rofireMux_T_1) 
                                   & (0x100U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___GEN_0))) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_T_43)) 
                                 & (0U != vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_womask_T_31))));
        bufp->chgBit(oldp+3228,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_rofireMux_T_1) 
                                   & (0x120U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___GEN_0))) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_T_43)) 
                                 & (0U != vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_womask_T_31))));
        bufp->chgBit(oldp+3229,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_rofireMux_T_1) 
                                   & (0x160U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___GEN_0))) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_T_43)) 
                                 & (0U != vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT___out_womask_T_31))));
        bufp->chgSData(oldp+3230,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_oindex),9);
        bufp->chgBit(oldp+3231,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__claimedDevs_1));
        bufp->chgBit(oldp+3232,((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin__DOT__effectivePriority_1))));
        bufp->chgBit(oldp+3233,(((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin__DOT__effectivePriority_1)) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__priority_0))));
        bufp->chgCData(oldp+3234,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin__DOT__effectivePriority_1),2);
        bufp->chgBit(oldp+3235,((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_1__DOT__effectivePriority_1))));
        bufp->chgBit(oldp+3236,(((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_1__DOT__effectivePriority_1)) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__priority_0))));
        bufp->chgCData(oldp+3237,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_1__DOT__effectivePriority_1),2);
        bufp->chgBit(oldp+3238,((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_2__DOT__effectivePriority_1))));
        bufp->chgBit(oldp+3239,(((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_2__DOT__effectivePriority_1)) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__priority_0))));
        bufp->chgCData(oldp+3240,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_2__DOT__effectivePriority_1),2);
        bufp->chgBit(oldp+3241,((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_3__DOT__effectivePriority_1))));
        bufp->chgBit(oldp+3242,(((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_3__DOT__effectivePriority_1)) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__priority_0))));
        bufp->chgCData(oldp+3243,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_3__DOT__effectivePriority_1),2);
        bufp->chgBit(oldp+3244,((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_4__DOT__effectivePriority_1))));
        bufp->chgBit(oldp+3245,(((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_4__DOT__effectivePriority_1)) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__priority_0))));
        bufp->chgCData(oldp+3246,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_4__DOT__effectivePriority_1),2);
        bufp->chgBit(oldp+3247,((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_5__DOT__effectivePriority_1))));
        bufp->chgBit(oldp+3248,(((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_5__DOT__effectivePriority_1)) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__priority_0))));
        bufp->chgCData(oldp+3249,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_5__DOT__effectivePriority_1),2);
        bufp->chgBit(oldp+3250,((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_6__DOT__effectivePriority_1))));
        bufp->chgBit(oldp+3251,(((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_6__DOT__effectivePriority_1)) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__priority_0))));
        bufp->chgCData(oldp+3252,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_6__DOT__effectivePriority_1),2);
        bufp->chgBit(oldp+3253,((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_7__DOT__effectivePriority_1))));
        bufp->chgBit(oldp+3254,(((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_7__DOT__effectivePriority_1)) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__priority_0))));
        bufp->chgCData(oldp+3255,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_7__DOT__effectivePriority_1),2);
        bufp->chgBit(oldp+3256,((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_8__DOT__effectivePriority_1))));
        bufp->chgBit(oldp+3257,(((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_8__DOT__effectivePriority_1)) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__priority_0))));
        bufp->chgCData(oldp+3258,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_8__DOT__effectivePriority_1),2);
        bufp->chgBit(oldp+3259,((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_9__DOT__effectivePriority_1))));
        bufp->chgBit(oldp+3260,(((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_9__DOT__effectivePriority_1)) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__priority_0))));
        bufp->chgCData(oldp+3261,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__fanin_9__DOT__effectivePriority_1),2);
        bufp->chgBit(oldp+3262,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT____Vcellinp__gateways_gateway__io_plic_complete));
        bufp->chgBit(oldp+3263,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__a_first_done));
        bufp->chgBit(oldp+3264,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__d_first_done));
        bufp->chgBit(oldp+3265,((2U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__aFrag)))));
        bufp->chgBit(oldp+3266,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+3267,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+3268,((1U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__aFrag)))));
        bufp->chgBit(oldp+3269,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+3270,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+3271,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+3272,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+3273,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+3274,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+3275,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+3276,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+3277,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__mask_acc_5) 
                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__mask_eq_5) 
                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_plic_fragmenter_out_a_bits_address)) 
                                    << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__mask_acc_5) 
                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__mask_eq_5) 
                                                   & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_plic_fragmenter_out_a_bits_address))) 
                                               << 6U) 
                                              | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__mask_acc_4) 
                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__mask_eq_4) 
                                                      & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_plic_fragmenter_out_a_bits_address)) 
                                                  << 5U) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__mask_acc_4) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__mask_eq_4) 
                                                         & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_plic_fragmenter_out_a_bits_address))) 
                                                     << 4U) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__mask_acc_3) 
                                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__mask_eq_3) 
                                                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_plic_fragmenter_out_a_bits_address)) 
                                                        << 3U) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__mask_acc_3) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__mask_eq_3) 
                                                               & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_plic_fragmenter_out_a_bits_address))) 
                                                           << 2U) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__mask_acc_2) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__mask_eq_2) 
                                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_plic_fragmenter_out_a_bits_address)) 
                                                              << 1U) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__mask_eq_2) 
                                                                   & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_plic_fragmenter_out_a_bits_address))))))))))),8);
        VL_EXTEND_WI(2048,11, __Vtemp_hdfc08149__0, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_plic_fragmenter_out_a_bits_source));
        VL_SHIFTL_WWW(2048,2048,2048, __Vtemp_h0b048a1a__0, VTestHarness__ConstPool__CONST_ha056d847_0, __Vtemp_hdfc08149__0);
        __Vtemp_h05224570__0[0U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h0b048a1a__0[0U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[0U]));
        __Vtemp_h05224570__0[1U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[1U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h0b048a1a__0[1U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[1U]));
        __Vtemp_h05224570__0[2U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[2U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h0b048a1a__0[2U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[2U]));
        __Vtemp_h05224570__0[3U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[3U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h0b048a1a__0[3U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[3U]));
        __Vtemp_h05224570__0[4U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[4U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h0b048a1a__0[4U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[4U]));
        __Vtemp_h05224570__0[5U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[5U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h0b048a1a__0[5U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[5U]));
        __Vtemp_h05224570__0[6U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[6U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h0b048a1a__0[6U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[6U]));
        __Vtemp_h05224570__0[7U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[7U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h0b048a1a__0[7U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[7U]));
        __Vtemp_h05224570__0[8U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[8U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h0b048a1a__0[8U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[8U]));
        __Vtemp_h05224570__0[9U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[9U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h0b048a1a__0[9U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[9U]));
        __Vtemp_h05224570__0[0xaU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0xaU] 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                          ? __Vtemp_h0b048a1a__0[0xaU]
                                          : VTestHarness__ConstPool__CONST_hd0572db1_0[0xaU]));
        __Vtemp_h05224570__0[0xbU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0xbU] 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                          ? __Vtemp_h0b048a1a__0[0xbU]
                                          : VTestHarness__ConstPool__CONST_hd0572db1_0[0xbU]));
        __Vtemp_h05224570__0[0xcU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0xcU] 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                          ? __Vtemp_h0b048a1a__0[0xcU]
                                          : VTestHarness__ConstPool__CONST_hd0572db1_0[0xcU]));
        __Vtemp_h05224570__0[0xdU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0xdU] 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                          ? __Vtemp_h0b048a1a__0[0xdU]
                                          : VTestHarness__ConstPool__CONST_hd0572db1_0[0xdU]));
        __Vtemp_h05224570__0[0xeU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0xeU] 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                          ? __Vtemp_h0b048a1a__0[0xeU]
                                          : VTestHarness__ConstPool__CONST_hd0572db1_0[0xeU]));
        __Vtemp_h05224570__0[0xfU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0xfU] 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                          ? __Vtemp_h0b048a1a__0[0xfU]
                                          : VTestHarness__ConstPool__CONST_hd0572db1_0[0xfU]));
        __Vtemp_h05224570__0[0x10U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x10U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h0b048a1a__0[0x10U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x10U]));
        __Vtemp_h05224570__0[0x11U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x11U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h0b048a1a__0[0x11U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x11U]));
        __Vtemp_h05224570__0[0x12U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x12U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h0b048a1a__0[0x12U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x12U]));
        __Vtemp_h05224570__0[0x13U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x13U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h0b048a1a__0[0x13U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x13U]));
        __Vtemp_h05224570__0[0x14U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x14U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h0b048a1a__0[0x14U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x14U]));
        __Vtemp_h05224570__0[0x15U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x15U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h0b048a1a__0[0x15U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x15U]));
        __Vtemp_h05224570__0[0x16U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x16U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h0b048a1a__0[0x16U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x16U]));
        __Vtemp_h05224570__0[0x17U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x17U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h0b048a1a__0[0x17U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x17U]));
        __Vtemp_h05224570__0[0x18U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x18U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h0b048a1a__0[0x18U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x18U]));
        __Vtemp_h05224570__0[0x19U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x19U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h0b048a1a__0[0x19U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x19U]));
        __Vtemp_h05224570__0[0x1aU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x1aU] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h0b048a1a__0[0x1aU]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x1aU]));
        __Vtemp_h05224570__0[0x1bU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x1bU] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h0b048a1a__0[0x1bU]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x1bU]));
        __Vtemp_h05224570__0[0x1cU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x1cU] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h0b048a1a__0[0x1cU]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x1cU]));
        __Vtemp_h05224570__0[0x1dU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x1dU] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h0b048a1a__0[0x1dU]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x1dU]));
        __Vtemp_h05224570__0[0x1eU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x1eU] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h0b048a1a__0[0x1eU]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x1eU]));
        __Vtemp_h05224570__0[0x1fU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x1fU] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h0b048a1a__0[0x1fU]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x1fU]));
        __Vtemp_h05224570__0[0x20U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x20U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h0b048a1a__0[0x20U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x20U]));
        bufp->chgWData(oldp+3278,(__Vtemp_h05224570__0),1040);
        bufp->chgBit(oldp+3311,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+3312,((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))));
        bufp->chgIData(oldp+3313,((0x7fffffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_plic_fragmenter_out_a_bits_address 
                                                >> 3U))),23);
        bufp->chgBit(oldp+3314,((1U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_back__DOT__ram_ext__DOT__Memory
                                 [0U][0U])));
        bufp->chgIData(oldp+3315,((0x7fffffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_back__DOT__ram_ext__DOT__Memory
                                                [0U][0U] 
                                                >> 1U))),23);
        bufp->chgQData(oldp+3316,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_back__DOT__ram_ext__DOT__Memory
                                                    [0U][2U])) 
                                    << 0x28U) | (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_back__DOT__ram_ext__DOT__Memory
                                                                  [0U][1U])) 
                                                  << 8U) 
                                                 | ((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_back__DOT__ram_ext__DOT__Memory
                                                                    [0U][0U])) 
                                                    >> 0x18U)))),64);
        bufp->chgCData(oldp+3318,((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_back__DOT__ram_ext__DOT__Memory
                                   [0U][2U] >> 0x18U)),8);
        bufp->chgBit(oldp+3319,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_back__DOT__do_enq));
        __Vtemp_h73565780__0[0U] = (((IData)((((QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                                               << 0x28U) 
                                              | (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                                                  << 8U) 
                                                 | ((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                                    >> 0x18U)))) 
                                     << 0x18U) | ((0xfffffeU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_plic_fragmenter_out_a_bits_address 
                                                      >> 2U)) 
                                                  | (4U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))));
        __Vtemp_h73565780__0[1U] = (((IData)((((QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                                               << 0x28U) 
                                              | (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                                                  << 8U) 
                                                 | ((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                                    >> 0x18U)))) 
                                     >> 8U) | ((IData)(
                                                       ((((QData)((IData)(
                                                                          vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                                                          << 0x28U) 
                                                         | (((QData)((IData)(
                                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                                                             << 8U) 
                                                            | ((QData)((IData)(
                                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                                               >> 0x18U))) 
                                                        >> 0x20U)) 
                                               << 0x18U));
        __Vtemp_h73565780__0[2U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_plic_fragmenter_out_a_bits_mask) 
                                     << 0x18U) | ((IData)(
                                                          ((((QData)((IData)(
                                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                                                             << 0x28U) 
                                                            | (((QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                                                                << 8U) 
                                                               | ((QData)((IData)(
                                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                                                  >> 0x18U))) 
                                                           >> 0x20U)) 
                                                  >> 8U));
        __Vtemp_h73565780__0[3U] = ((0x1800U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__aFrag) 
                                                << 0xbU)) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_plic_fragmenter_out_a_bits_source));
        bufp->chgWData(oldp+3320,(__Vtemp_h73565780__0),109);
        __Vtemp_hb42910ab__8[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_back__DOT__ram_ext__DOT__Memory
            [0U][0U];
        __Vtemp_hb42910ab__8[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_back__DOT__ram_ext__DOT__Memory
            [0U][1U];
        __Vtemp_hb42910ab__8[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_back__DOT__ram_ext__DOT__Memory
            [0U][2U];
        __Vtemp_hb42910ab__8[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_back__DOT__ram_ext__DOT__Memory
            [0U][3U];
        bufp->chgWData(oldp+3324,(__Vtemp_hb42910ab__8),109);
        bufp->chgWData(oldp+3328,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_back__DOT__ram_ext__DOT__Memory[0]),109);
        bufp->chgCData(oldp+3332,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])),3);
        bufp->chgCData(oldp+3333,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                         >> 3U))),3);
        bufp->chgCData(oldp+3334,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                         >> 6U))),2);
        bufp->chgSData(oldp+3335,((0x7ffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 8U))),11);
        bufp->chgIData(oldp+3336,((0x1fffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                 << 0xdU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0x13U)))),21);
        bufp->chgCData(oldp+3337,((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                            >> 8U))),8);
        bufp->chgQData(oldp+3338,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                                    << 0x30U) | (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                                                  << 0x10U) 
                                                 | ((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                                    >> 0x10U)))),64);
        bufp->chgBit(oldp+3340,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                                       >> 0x10U))));
        bufp->chgCData(oldp+3341,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])),3);
        bufp->chgCData(oldp+3342,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                         >> 3U))),3);
        bufp->chgCData(oldp+3343,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                         >> 6U))),2);
        bufp->chgSData(oldp+3344,((0x7ffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 8U))),11);
        bufp->chgIData(oldp+3345,((0x1fffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                 << 0xdU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0x13U)))),21);
        bufp->chgCData(oldp+3346,((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                            >> 8U))),8);
        bufp->chgQData(oldp+3347,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                                    << 0x30U) | (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                                                  << 0x10U) 
                                                 | ((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                                    >> 0x10U)))),64);
        bufp->chgBit(oldp+3349,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                                       >> 0x10U))));
        bufp->chgCData(oldp+3350,((4U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))),3);
        bufp->chgCData(oldp+3351,((4U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))),3);
        bufp->chgBit(oldp+3352,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__out_woready_3));
        bufp->chgBit(oldp+3353,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__out_woready_11));
        bufp->chgBit(oldp+3354,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__out_woready_9));
        bufp->chgBit(oldp+3355,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__out_woready_7));
        bufp->chgBit(oldp+3356,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__out_woready_5));
        bufp->chgBit(oldp+3357,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__out_woready_1));
        bufp->chgBit(oldp+3358,((4U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))));
        bufp->chgBit(oldp+3359,((2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                              >> 6U)))));
        bufp->chgBit(oldp+3360,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+3361,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+3362,((1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                              >> 6U)))));
        bufp->chgBit(oldp+3363,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+3364,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+3365,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+3366,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+3367,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+3368,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+3369,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+3370,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+3371,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__mask_acc_5) 
                                     << 7U) | (0xfff80U 
                                               & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__mask_eq_5) 
                                                   << 7U) 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0xcU)))) 
                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__mask_acc_5) 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__mask_eq_5) 
                                           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                 >> 0x13U)))) 
                                       << 6U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__mask_acc_4) 
                                                   << 5U) 
                                                  | (0x3ffe0U 
                                                     & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__mask_eq_4) 
                                                         << 5U) 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                           >> 0xeU)))) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__mask_acc_4) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__mask_eq_4) 
                                                         & (~ 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                             >> 0x13U)))) 
                                                     << 4U) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__mask_acc_3) 
                                                         << 3U) 
                                                        | (0xfff8U 
                                                           & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__mask_eq_3) 
                                                               << 3U) 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                 >> 0x10U)))) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__mask_acc_3) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__mask_eq_3) 
                                                               & (~ 
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                   >> 0x13U)))) 
                                                           << 2U) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__mask_acc_2) 
                                                               << 1U) 
                                                              | (0x3ffeU 
                                                                 & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__mask_eq_2) 
                                                                     << 1U) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                       >> 0x12U)))) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__mask_eq_2) 
                                                                   & (~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                       >> 0x13U)))))))))))),8);
        bufp->chgBit(oldp+3372,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                       >> 0x10U))));
        bufp->chgBit(oldp+3373,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__out_woready_1) 
                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                    >> 8U))));
        bufp->chgBit(oldp+3374,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U] 
                                       >> 0x10U))));
        bufp->chgBit(oldp+3375,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__out_woready_1) 
                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                    >> 0xcU))));
        bufp->chgBit(oldp+3376,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__out_woready_3) 
                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                    >> 8U))));
        bufp->chgBit(oldp+3377,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__out_woready_3) 
                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                    >> 0xcU))));
        bufp->chgBit(oldp+3378,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__out_woready_5) 
                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                    >> 8U))));
        bufp->chgBit(oldp+3379,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__out_woready_5) 
                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                    >> 0xcU))));
        bufp->chgBit(oldp+3380,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__out_woready_7) 
                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                    >> 8U))));
        bufp->chgBit(oldp+3381,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__out_woready_7) 
                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                    >> 0xcU))));
        bufp->chgBit(oldp+3382,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__out_woready_9) 
                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                    >> 8U))));
        bufp->chgBit(oldp+3383,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__out_woready_9) 
                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                    >> 0xcU))));
        bufp->chgBit(oldp+3384,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__out_woready_11) 
                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                    >> 8U))));
        bufp->chgBit(oldp+3385,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__out_woready_11) 
                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                    >> 0xcU))));
        bufp->chgBit(oldp+3386,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__out_woready_3));
        bufp->chgBit(oldp+3387,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__out_woready_1));
        bufp->chgBit(oldp+3388,((2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                              >> 0x16U)))));
        bufp->chgBit(oldp+3389,((4U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))));
        bufp->chgBit(oldp+3390,((2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                              >> 6U)))));
        bufp->chgBit(oldp+3391,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+3392,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+3393,((1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                              >> 6U)))));
        bufp->chgBit(oldp+3394,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+3395,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+3396,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+3397,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+3398,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+3399,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+3400,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+3401,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+3402,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__mask_acc_5) 
                                     << 7U) | (0xfff80U 
                                               & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__mask_eq_5) 
                                                   << 7U) 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0xcU)))) 
                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__mask_acc_5) 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__mask_eq_5) 
                                           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                 >> 0x13U)))) 
                                       << 6U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__mask_acc_4) 
                                                   << 5U) 
                                                  | (0x3ffe0U 
                                                     & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__mask_eq_4) 
                                                         << 5U) 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                           >> 0xeU)))) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__mask_acc_4) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__mask_eq_4) 
                                                         & (~ 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                             >> 0x13U)))) 
                                                     << 4U) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__mask_acc_3) 
                                                         << 3U) 
                                                        | (0xfff8U 
                                                           & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__mask_eq_3) 
                                                               << 3U) 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                 >> 0x10U)))) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__mask_acc_3) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__mask_eq_3) 
                                                               & (~ 
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                   >> 0x13U)))) 
                                                           << 2U) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__mask_acc_2) 
                                                               << 1U) 
                                                              | (0x3ffeU 
                                                                 & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__mask_eq_2) 
                                                                     << 1U) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                       >> 0x12U)))) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__mask_eq_2) 
                                                                   & (~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                       >> 0x13U)))))))))))),8);
        bufp->chgBit(oldp+3403,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                       >> 0x10U))));
        bufp->chgBit(oldp+3404,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__out_woready_1) 
                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                    >> 8U))));
        bufp->chgBit(oldp+3405,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U] 
                                       >> 0x10U))));
        bufp->chgBit(oldp+3406,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__out_woready_1) 
                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                    >> 0xcU))));
        bufp->chgBit(oldp+3407,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__out_woready_3) 
                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                    >> 8U))));
        bufp->chgBit(oldp+3408,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__out_woready_3) 
                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                    >> 0xcU))));
        bufp->chgBit(oldp+3409,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT___out_wofireMux_T_2) 
                                  & (0x800000U == (0x7fc00000U 
                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]))) 
                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                    >> 8U))));
        bufp->chgBit(oldp+3410,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__x1_d_ready));
        bufp->chgBit(oldp+3411,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output));
        bufp->chgCData(oldp+3412,((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode))),3);
        bufp->chgCData(oldp+3413,((3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__aFrag))),2);
        bufp->chgSData(oldp+3414,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_debug_fragmenter_out_a_bits_source),11);
        bufp->chgCData(oldp+3415,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode),3);
        bufp->chgCData(oldp+3416,((7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__repeater__DOT__full)
                                          ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__repeater__DOT__saved_param)
                                          : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                              << 0x1dU) 
                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                >> 3U))))),3);
        bufp->chgSData(oldp+3417,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_debug_fragmenter_out_a_bits_address),12);
        bufp->chgCData(oldp+3418,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_debug_fragmenter_out_a_bits_mask),8);
        bufp->chgBit(oldp+3419,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__repeater__DOT__full)
                                        ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__repeater__DOT__saved_corrupt)
                                        : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                                           >> 0x18U)))));
        bufp->chgBit(oldp+3420,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_bus_named_subsystem_pbus_bus_xing_out_a_valid));
        bufp->chgCData(oldp+3421,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])),3);
        bufp->chgCData(oldp+3422,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                         >> 3U))),3);
        bufp->chgCData(oldp+3423,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                         >> 6U))),3);
        bufp->chgCData(oldp+3424,((0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                            >> 0xaU))),7);
        bufp->chgIData(oldp+3425,((0x7fffffffU & ((
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                   << 0xfU) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0x11U)))),31);
        bufp->chgCData(oldp+3426,((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                            >> 0x10U))),8);
        bufp->chgBit(oldp+3427,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                                       >> 0x18U))));
        bufp->chgBit(oldp+3428,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_bus_named_subsystem_pbus_bus_xing_out_d_ready));
        bufp->chgBit(oldp+3429,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT___portsAOI_in_0_a_ready_WIRE));
        bufp->chgBit(oldp+3430,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_valid));
        bufp->chgCData(oldp+3431,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_opcode),3);
        bufp->chgCData(oldp+3432,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_param),2);
        bufp->chgCData(oldp+3433,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_size),4);
        bufp->chgCData(oldp+3434,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_source),7);
        bufp->chgBit(oldp+3435,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_sink));
        bufp->chgBit(oldp+3436,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__out_30_bits_denied));
        bufp->chgCData(oldp+3437,((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                           >> 6U))),4);
        bufp->chgBit(oldp+3438,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_enq));
        bufp->chgBit(oldp+3439,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__do_deq));
        bufp->chgWData(oldp+3440,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data),121);
        bufp->chgBit(oldp+3444,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_6_a_valid));
        bufp->chgIData(oldp+3445,((0x1ffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                << 0xfU) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 0x11U)))),17);
        bufp->chgBit(oldp+3446,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__repeater__DOT___io_enq_ready_output));
        bufp->chgCData(oldp+3447,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__bundleIn_0_d_bits_size),3);
        bufp->chgCData(oldp+3448,((0x7fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_bootrom_fragmenter_out_a_bits_source) 
                                            >> 4U))),7);
        bufp->chgCData(oldp+3449,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__dFirst_size),3);
        bufp->chgCData(oldp+3450,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__aFrag),3);
        bufp->chgCData(oldp+3451,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__old_gennum1),3);
        bufp->chgBit(oldp+3452,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__a_first_done));
        bufp->chgBit(oldp+3453,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__source_ok));
        bufp->chgBit(oldp+3454,((2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                              >> 6U)))));
        bufp->chgBit(oldp+3455,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+3456,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+3457,((1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                              >> 6U)))));
        bufp->chgBit(oldp+3458,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+3459,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+3460,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+3461,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+3462,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+3463,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+3464,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+3465,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+3466,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5) 
                                     << 7U) | (0x3fff80U 
                                               & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5) 
                                                   << 7U) 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0xaU)))) 
                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5) 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5) 
                                           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                 >> 0x11U)))) 
                                       << 6U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4) 
                                                   << 5U) 
                                                  | (0xfffe0U 
                                                     & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4) 
                                                         << 5U) 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                           >> 0xcU)))) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4) 
                                                         & (~ 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                             >> 0x11U)))) 
                                                     << 4U) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3) 
                                                         << 3U) 
                                                        | (0x3fff8U 
                                                           & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3) 
                                                               << 3U) 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                 >> 0xeU)))) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3) 
                                                               & (~ 
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                   >> 0x11U)))) 
                                                           << 2U) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2) 
                                                               << 1U) 
                                                              | (0xfffeU 
                                                                 & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2) 
                                                                     << 1U) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                       >> 0x10U)))) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2) 
                                                                   & (~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                       >> 0x11U)))))))))))),8);
        bufp->chgBit(oldp+3467,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+3468,((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__old_gennum1))));
        bufp->chgCData(oldp+3469,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT___repeater_io_deq_bits_size),3);
        bufp->chgBit(oldp+3470,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_4_a_valid));
        bufp->chgIData(oldp+3471,((0x3ffffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                  << 0xfU) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0x11U)))),26);
        bufp->chgBit(oldp+3472,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_4_d_ready));
        bufp->chgBit(oldp+3473,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__repeater__DOT___io_enq_ready_output));
        bufp->chgBit(oldp+3474,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__bundleIn_0_d_valid));
        bufp->chgCData(oldp+3475,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__bundleIn_0_d_bits_size),3);
        bufp->chgCData(oldp+3476,((0x7fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_clint_fragmenter_out_a_bits_source) 
                                            >> 4U))),7);
        bufp->chgCData(oldp+3477,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__dFirst_size),3);
        bufp->chgBit(oldp+3478,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__drop));
        bufp->chgCData(oldp+3479,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__aFrag),3);
        bufp->chgCData(oldp+3480,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__old_gennum1),3);
        bufp->chgBit(oldp+3481,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__source_ok));
        bufp->chgBit(oldp+3482,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+3483,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+3484,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+3485,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+3486,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+3487,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+3488,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+3489,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+3490,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+3491,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+3492,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5) 
                                     << 7U) | (0x3fff80U 
                                               & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5) 
                                                   << 7U) 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0xaU)))) 
                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5) 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5) 
                                           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                 >> 0x11U)))) 
                                       << 6U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4) 
                                                   << 5U) 
                                                  | (0xfffe0U 
                                                     & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4) 
                                                         << 5U) 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                           >> 0xcU)))) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4) 
                                                         & (~ 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                             >> 0x11U)))) 
                                                     << 4U) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3) 
                                                         << 3U) 
                                                        | (0x3fff8U 
                                                           & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3) 
                                                               << 3U) 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                 >> 0xeU)))) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3) 
                                                               & (~ 
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                   >> 0x11U)))) 
                                                           << 2U) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2) 
                                                               << 1U) 
                                                              | (0xfffeU 
                                                                 & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2) 
                                                                     << 1U) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                       >> 0x10U)))) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2) 
                                                                   & (~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                       >> 0x11U)))))))))))),8);
        bufp->chgBit(oldp+3493,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__source_ok_1));
        bufp->chgBit(oldp+3494,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+3495,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT____Vcellinp__repeater__io_repeat));
        bufp->chgCData(oldp+3496,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT___repeater_io_deq_bits_size),3);
        bufp->chgBit(oldp+3497,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_5_a_valid));
        bufp->chgSData(oldp+3498,((0xfffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                             >> 0x11U))),12);
        bufp->chgBit(oldp+3499,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_5_d_ready));
        bufp->chgBit(oldp+3500,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__repeater__DOT___io_enq_ready_output));
        bufp->chgBit(oldp+3501,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__bundleIn_0_d_valid));
        bufp->chgCData(oldp+3502,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__bundleIn_0_d_bits_size),3);
        bufp->chgCData(oldp+3503,((0x7fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_debug_fragmenter_out_a_bits_source) 
                                            >> 4U))),7);
        bufp->chgCData(oldp+3504,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__dFirst_size),3);
        bufp->chgBit(oldp+3505,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__drop));
        bufp->chgCData(oldp+3506,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__aFrag),3);
        bufp->chgCData(oldp+3507,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__old_gennum1),3);
        bufp->chgBit(oldp+3508,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__source_ok));
        bufp->chgBit(oldp+3509,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+3510,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+3511,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+3512,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+3513,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+3514,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+3515,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+3516,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+3517,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+3518,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+3519,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5) 
                                     << 7U) | (0x3fff80U 
                                               & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5) 
                                                   << 7U) 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0xaU)))) 
                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5) 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5) 
                                           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                 >> 0x11U)))) 
                                       << 6U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4) 
                                                   << 5U) 
                                                  | (0xfffe0U 
                                                     & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4) 
                                                         << 5U) 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                           >> 0xcU)))) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4) 
                                                         & (~ 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                             >> 0x11U)))) 
                                                     << 4U) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3) 
                                                         << 3U) 
                                                        | (0x3fff8U 
                                                           & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3) 
                                                               << 3U) 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                 >> 0xeU)))) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3) 
                                                               & (~ 
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                   >> 0x11U)))) 
                                                           << 2U) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2) 
                                                               << 1U) 
                                                              | (0xfffeU 
                                                                 & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2) 
                                                                     << 1U) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                       >> 0x10U)))) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2) 
                                                                   & (~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                       >> 0x11U)))))))))))),8);
        bufp->chgBit(oldp+3520,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__source_ok_1));
        bufp->chgBit(oldp+3521,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+3522,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT____Vcellinp__repeater__io_repeat));
        bufp->chgBit(oldp+3523,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__repeater__DOT__full));
        bufp->chgCData(oldp+3524,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT___repeater_io_deq_bits_size),3);
        bufp->chgCData(oldp+3525,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__repeater__DOT__saved_param),3);
        bufp->chgBit(oldp+3526,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__repeater__DOT__saved_corrupt));
        bufp->chgBit(oldp+3527,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_1_a_valid));
        bufp->chgBit(oldp+3528,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_1_d_ready));
        bufp->chgBit(oldp+3529,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output));
        bufp->chgCData(oldp+3530,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode),3);
        bufp->chgCData(oldp+3531,((3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__aFrag))),2);
        bufp->chgSData(oldp+3532,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT___fragmenter_auto_out_a_bits_source),11);
        bufp->chgIData(oldp+3533,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT___fragmenter_auto_out_a_bits_address),26);
        bufp->chgCData(oldp+3534,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT___fragmenter_auto_out_a_bits_mask),8);
        bufp->chgBit(oldp+3535,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__x1_d_ready));
        bufp->chgBit(oldp+3536,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__a_first_done));
        bufp->chgBit(oldp+3537,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__d_first_done));
        bufp->chgBit(oldp+3538,((2U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__aFrag)))));
        bufp->chgBit(oldp+3539,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+3540,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+3541,((1U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__aFrag)))));
        bufp->chgBit(oldp+3542,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+3543,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+3544,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+3545,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+3546,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+3547,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+3548,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+3549,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+3550,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_5) 
                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_5) 
                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT___fragmenter_auto_out_a_bits_address)) 
                                    << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_5) 
                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_5) 
                                                   & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT___fragmenter_auto_out_a_bits_address))) 
                                               << 6U) 
                                              | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_4) 
                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_4) 
                                                      & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT___fragmenter_auto_out_a_bits_address)) 
                                                  << 5U) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_4) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_4) 
                                                         & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT___fragmenter_auto_out_a_bits_address))) 
                                                     << 4U) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_3) 
                                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_3) 
                                                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT___fragmenter_auto_out_a_bits_address)) 
                                                        << 3U) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_3) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_3) 
                                                               & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT___fragmenter_auto_out_a_bits_address))) 
                                                           << 2U) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_2) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_2) 
                                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT___fragmenter_auto_out_a_bits_address)) 
                                                              << 1U) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_2) 
                                                                   & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT___fragmenter_auto_out_a_bits_address))))))))))),8);
        VL_EXTEND_WI(2048,11, __Vtemp_h885446e2__0, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT___fragmenter_auto_out_a_bits_source));
        VL_SHIFTL_WWW(2048,2048,2048, __Vtemp_h3cdc4348__0, VTestHarness__ConstPool__CONST_ha056d847_0, __Vtemp_h885446e2__0);
        __Vtemp_h9bf1e077__0[0U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h3cdc4348__0[0U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[0U]));
        __Vtemp_h9bf1e077__0[1U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[1U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h3cdc4348__0[1U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[1U]));
        __Vtemp_h9bf1e077__0[2U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[2U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h3cdc4348__0[2U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[2U]));
        __Vtemp_h9bf1e077__0[3U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[3U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h3cdc4348__0[3U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[3U]));
        __Vtemp_h9bf1e077__0[4U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[4U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h3cdc4348__0[4U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[4U]));
        __Vtemp_h9bf1e077__0[5U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[5U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h3cdc4348__0[5U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[5U]));
        __Vtemp_h9bf1e077__0[6U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[6U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h3cdc4348__0[6U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[6U]));
        __Vtemp_h9bf1e077__0[7U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[7U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h3cdc4348__0[7U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[7U]));
        __Vtemp_h9bf1e077__0[8U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[8U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h3cdc4348__0[8U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[8U]));
        __Vtemp_h9bf1e077__0[9U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[9U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h3cdc4348__0[9U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[9U]));
        __Vtemp_h9bf1e077__0[0xaU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0xaU] 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                          ? __Vtemp_h3cdc4348__0[0xaU]
                                          : VTestHarness__ConstPool__CONST_hd0572db1_0[0xaU]));
        __Vtemp_h9bf1e077__0[0xbU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0xbU] 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                          ? __Vtemp_h3cdc4348__0[0xbU]
                                          : VTestHarness__ConstPool__CONST_hd0572db1_0[0xbU]));
        __Vtemp_h9bf1e077__0[0xcU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0xcU] 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                          ? __Vtemp_h3cdc4348__0[0xcU]
                                          : VTestHarness__ConstPool__CONST_hd0572db1_0[0xcU]));
        __Vtemp_h9bf1e077__0[0xdU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0xdU] 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                          ? __Vtemp_h3cdc4348__0[0xdU]
                                          : VTestHarness__ConstPool__CONST_hd0572db1_0[0xdU]));
        __Vtemp_h9bf1e077__0[0xeU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0xeU] 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                          ? __Vtemp_h3cdc4348__0[0xeU]
                                          : VTestHarness__ConstPool__CONST_hd0572db1_0[0xeU]));
        __Vtemp_h9bf1e077__0[0xfU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0xfU] 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                          ? __Vtemp_h3cdc4348__0[0xfU]
                                          : VTestHarness__ConstPool__CONST_hd0572db1_0[0xfU]));
        __Vtemp_h9bf1e077__0[0x10U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x10U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h3cdc4348__0[0x10U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x10U]));
        __Vtemp_h9bf1e077__0[0x11U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x11U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h3cdc4348__0[0x11U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x11U]));
        __Vtemp_h9bf1e077__0[0x12U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x12U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h3cdc4348__0[0x12U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x12U]));
        __Vtemp_h9bf1e077__0[0x13U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x13U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h3cdc4348__0[0x13U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x13U]));
        __Vtemp_h9bf1e077__0[0x14U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x14U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h3cdc4348__0[0x14U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x14U]));
        __Vtemp_h9bf1e077__0[0x15U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x15U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h3cdc4348__0[0x15U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x15U]));
        __Vtemp_h9bf1e077__0[0x16U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x16U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h3cdc4348__0[0x16U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x16U]));
        __Vtemp_h9bf1e077__0[0x17U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x17U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h3cdc4348__0[0x17U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x17U]));
        __Vtemp_h9bf1e077__0[0x18U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x18U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h3cdc4348__0[0x18U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x18U]));
        __Vtemp_h9bf1e077__0[0x19U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x19U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h3cdc4348__0[0x19U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x19U]));
        __Vtemp_h9bf1e077__0[0x1aU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x1aU] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h3cdc4348__0[0x1aU]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x1aU]));
        __Vtemp_h9bf1e077__0[0x1bU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x1bU] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h3cdc4348__0[0x1bU]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x1bU]));
        __Vtemp_h9bf1e077__0[0x1cU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x1cU] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h3cdc4348__0[0x1cU]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x1cU]));
        __Vtemp_h9bf1e077__0[0x1dU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x1dU] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h3cdc4348__0[0x1dU]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x1dU]));
        __Vtemp_h9bf1e077__0[0x1eU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x1eU] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h3cdc4348__0[0x1eU]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x1eU]));
        __Vtemp_h9bf1e077__0[0x1fU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x1fU] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h3cdc4348__0[0x1fU]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x1fU]));
        __Vtemp_h9bf1e077__0[0x20U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x20U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h3cdc4348__0[0x20U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x20U]));
        bufp->chgWData(oldp+3551,(__Vtemp_h9bf1e077__0),1040);
        bufp->chgBit(oldp+3584,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+3585,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__do_enq));
        bufp->chgCData(oldp+3586,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__aFrag),3);
        bufp->chgCData(oldp+3587,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__old_gennum1),3);
        bufp->chgBit(oldp+3588,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__source_ok));
        bufp->chgBit(oldp+3589,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+3590,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+3591,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+3592,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+3593,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+3594,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+3595,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+3596,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+3597,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+3598,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+3599,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5) 
                                     << 7U) | (0x3fff80U 
                                               & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5) 
                                                   << 7U) 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0xaU)))) 
                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5) 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5) 
                                           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                 >> 0x11U)))) 
                                       << 6U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4) 
                                                   << 5U) 
                                                  | (0xfffe0U 
                                                     & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4) 
                                                         << 5U) 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                           >> 0xcU)))) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4) 
                                                         & (~ 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                             >> 0x11U)))) 
                                                     << 4U) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3) 
                                                         << 3U) 
                                                        | (0x3fff8U 
                                                           & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3) 
                                                               << 3U) 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                 >> 0xeU)))) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3) 
                                                               & (~ 
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                   >> 0x11U)))) 
                                                           << 2U) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2) 
                                                               << 1U) 
                                                              | (0xfffeU 
                                                                 & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2) 
                                                                     << 1U) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                       >> 0x10U)))) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2) 
                                                                   & (~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                       >> 0x11U)))))))))))),8);
        __Vtemp_hc961d23f__0[0U] = 1U;
        __Vtemp_hc961d23f__0[1U] = 0U;
        __Vtemp_hc961d23f__0[2U] = 0U;
        __Vtemp_hc961d23f__0[3U] = 0U;
        VL_EXTEND_WI(128,7, __Vtemp_h9a9a6856__0, (0x7fU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 0xaU)));
        VL_SHIFTL_WWW(128,128,128, __Vtemp_hca162495__0, __Vtemp_hc961d23f__0, __Vtemp_h9a9a6856__0);
        if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT___same_cycle_resp_T_1) {
            __Vtemp_h819c6816__0[0U] = __Vtemp_hca162495__0[0U];
            __Vtemp_h819c6816__0[1U] = __Vtemp_hca162495__0[1U];
            __Vtemp_h819c6816__0[2U] = (1U & __Vtemp_hca162495__0[2U]);
        } else {
            __Vtemp_h819c6816__0[0U] = 0U;
            __Vtemp_h819c6816__0[1U] = 0U;
            __Vtemp_h819c6816__0[2U] = 0U;
        }
        bufp->chgWData(oldp+3600,(__Vtemp_h819c6816__0),65);
        bufp->chgBit(oldp+3603,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+3604,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT____Vcellinp__repeater__io_repeat));
        bufp->chgCData(oldp+3605,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT___repeater_io_deq_bits_size),3);
        bufp->chgBit(oldp+3606,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_3_a_valid));
        bufp->chgIData(oldp+3607,((0xfffffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                  << 0xfU) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 0x11U)))),28);
        bufp->chgBit(oldp+3608,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_3_d_ready));
        bufp->chgBit(oldp+3609,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__bundleIn_0_d_valid));
        bufp->chgCData(oldp+3610,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__bundleIn_0_d_bits_size),3);
        bufp->chgCData(oldp+3611,((0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_back__DOT__ram_ext__DOT__Memory
                                            [0U][3U] 
                                            >> 4U))),7);
        bufp->chgCData(oldp+3612,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__dFirst_size),3);
        bufp->chgBit(oldp+3613,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__drop));
        bufp->chgCData(oldp+3614,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__aFrag),3);
        bufp->chgCData(oldp+3615,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__old_gennum1),3);
        bufp->chgBit(oldp+3616,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__source_ok));
        bufp->chgBit(oldp+3617,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+3618,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+3619,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+3620,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+3621,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+3622,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+3623,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+3624,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+3625,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+3626,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+3627,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5) 
                                     << 7U) | (0x3fff80U 
                                               & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5) 
                                                   << 7U) 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0xaU)))) 
                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5) 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5) 
                                           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                 >> 0x11U)))) 
                                       << 6U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4) 
                                                   << 5U) 
                                                  | (0xfffe0U 
                                                     & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4) 
                                                         << 5U) 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                           >> 0xcU)))) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4) 
                                                         & (~ 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                             >> 0x11U)))) 
                                                     << 4U) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3) 
                                                         << 3U) 
                                                        | (0x3fff8U 
                                                           & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3) 
                                                               << 3U) 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                 >> 0xeU)))) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3) 
                                                               & (~ 
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                   >> 0x11U)))) 
                                                           << 2U) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2) 
                                                               << 1U) 
                                                              | (0xfffeU 
                                                                 & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2) 
                                                                     << 1U) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                       >> 0x10U)))) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2) 
                                                                   & (~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                       >> 0x11U)))))))))))),8);
        bufp->chgBit(oldp+3628,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__source_ok_1));
        __Vtemp_hc961d23f__1[0U] = 1U;
        __Vtemp_hc961d23f__1[1U] = 0U;
        __Vtemp_hc961d23f__1[2U] = 0U;
        __Vtemp_hc961d23f__1[3U] = 0U;
        VL_EXTEND_WI(128,7, __Vtemp_h9a9a6856__1, (0x7fU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 0xaU)));
        VL_SHIFTL_WWW(128,128,128, __Vtemp_h0ada6192__0, __Vtemp_hc961d23f__1, __Vtemp_h9a9a6856__1);
        if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT___same_cycle_resp_T_1) {
            __Vtemp_hd7b582ad__0[0U] = __Vtemp_h0ada6192__0[0U];
            __Vtemp_hd7b582ad__0[1U] = __Vtemp_h0ada6192__0[1U];
            __Vtemp_hd7b582ad__0[2U] = (1U & __Vtemp_h0ada6192__0[2U]);
        } else {
            __Vtemp_hd7b582ad__0[0U] = 0U;
            __Vtemp_hd7b582ad__0[1U] = 0U;
            __Vtemp_hd7b582ad__0[2U] = 0U;
        }
        bufp->chgWData(oldp+3629,(__Vtemp_hd7b582ad__0),65);
        bufp->chgBit(oldp+3632,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+3633,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT____Vcellinp__repeater__io_repeat));
        bufp->chgCData(oldp+3634,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT___repeater_io_deq_bits_size),3);
        bufp->chgBit(oldp+3635,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_7_a_valid));
        bufp->chgIData(oldp+3636,((0x1fffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                                 << 0xfU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0x11U)))),21);
        bufp->chgBit(oldp+3637,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_7_d_ready));
        bufp->chgBit(oldp+3638,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output));
        bufp->chgCData(oldp+3639,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode),3);
        bufp->chgCData(oldp+3640,((3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__aFrag))),2);
        bufp->chgSData(oldp+3641,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT___fragmenter_auto_out_a_bits_source),11);
        bufp->chgIData(oldp+3642,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT___fragmenter_auto_out_a_bits_address),21);
        bufp->chgCData(oldp+3643,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT___fragmenter_auto_out_a_bits_mask),8);
        bufp->chgBit(oldp+3644,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__x1_d_ready));
        bufp->chgBit(oldp+3645,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_deq));
        bufp->chgBit(oldp+3646,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__a_first_done));
        bufp->chgBit(oldp+3647,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__d_first_done));
        bufp->chgBit(oldp+3648,((2U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__aFrag)))));
        bufp->chgBit(oldp+3649,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+3650,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+3651,((1U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__aFrag)))));
        bufp->chgBit(oldp+3652,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+3653,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+3654,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+3655,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+3656,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+3657,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+3658,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+3659,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+3660,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__mask_acc_5) 
                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__mask_eq_5) 
                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT___fragmenter_auto_out_a_bits_address)) 
                                    << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__mask_acc_5) 
                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__mask_eq_5) 
                                                   & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT___fragmenter_auto_out_a_bits_address))) 
                                               << 6U) 
                                              | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__mask_acc_4) 
                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__mask_eq_4) 
                                                      & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT___fragmenter_auto_out_a_bits_address)) 
                                                  << 5U) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__mask_acc_4) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__mask_eq_4) 
                                                         & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT___fragmenter_auto_out_a_bits_address))) 
                                                     << 4U) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__mask_acc_3) 
                                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__mask_eq_3) 
                                                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT___fragmenter_auto_out_a_bits_address)) 
                                                        << 3U) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__mask_acc_3) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__mask_eq_3) 
                                                               & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT___fragmenter_auto_out_a_bits_address))) 
                                                           << 2U) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__mask_acc_2) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__mask_eq_2) 
                                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT___fragmenter_auto_out_a_bits_address)) 
                                                              << 1U) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__mask_eq_2) 
                                                                   & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT___fragmenter_auto_out_a_bits_address))))))))))),8);
        VL_EXTEND_WI(2048,11, __Vtemp_h182e915d__0, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT___fragmenter_auto_out_a_bits_source));
        VL_SHIFTL_WWW(2048,2048,2048, __Vtemp_h93bb4e5e__0, VTestHarness__ConstPool__CONST_ha056d847_0, __Vtemp_h182e915d__0);
        __Vtemp_ha3ff2fea__0[0U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h93bb4e5e__0[0U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[0U]));
        __Vtemp_ha3ff2fea__0[1U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[1U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h93bb4e5e__0[1U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[1U]));
        __Vtemp_ha3ff2fea__0[2U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[2U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h93bb4e5e__0[2U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[2U]));
        __Vtemp_ha3ff2fea__0[3U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[3U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h93bb4e5e__0[3U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[3U]));
        __Vtemp_ha3ff2fea__0[4U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[4U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h93bb4e5e__0[4U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[4U]));
        __Vtemp_ha3ff2fea__0[5U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[5U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h93bb4e5e__0[5U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[5U]));
        __Vtemp_ha3ff2fea__0[6U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[6U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h93bb4e5e__0[6U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[6U]));
        __Vtemp_ha3ff2fea__0[7U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[7U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h93bb4e5e__0[7U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[7U]));
        __Vtemp_ha3ff2fea__0[8U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[8U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h93bb4e5e__0[8U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[8U]));
        __Vtemp_ha3ff2fea__0[9U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[9U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h93bb4e5e__0[9U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[9U]));
        __Vtemp_ha3ff2fea__0[0xaU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0xaU] 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                          ? __Vtemp_h93bb4e5e__0[0xaU]
                                          : VTestHarness__ConstPool__CONST_hd0572db1_0[0xaU]));
        __Vtemp_ha3ff2fea__0[0xbU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0xbU] 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                          ? __Vtemp_h93bb4e5e__0[0xbU]
                                          : VTestHarness__ConstPool__CONST_hd0572db1_0[0xbU]));
        __Vtemp_ha3ff2fea__0[0xcU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0xcU] 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                          ? __Vtemp_h93bb4e5e__0[0xcU]
                                          : VTestHarness__ConstPool__CONST_hd0572db1_0[0xcU]));
        __Vtemp_ha3ff2fea__0[0xdU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0xdU] 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                          ? __Vtemp_h93bb4e5e__0[0xdU]
                                          : VTestHarness__ConstPool__CONST_hd0572db1_0[0xdU]));
        __Vtemp_ha3ff2fea__0[0xeU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0xeU] 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                          ? __Vtemp_h93bb4e5e__0[0xeU]
                                          : VTestHarness__ConstPool__CONST_hd0572db1_0[0xeU]));
        __Vtemp_ha3ff2fea__0[0xfU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0xfU] 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                          ? __Vtemp_h93bb4e5e__0[0xfU]
                                          : VTestHarness__ConstPool__CONST_hd0572db1_0[0xfU]));
        __Vtemp_ha3ff2fea__0[0x10U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x10U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h93bb4e5e__0[0x10U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x10U]));
        __Vtemp_ha3ff2fea__0[0x11U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x11U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h93bb4e5e__0[0x11U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x11U]));
        __Vtemp_ha3ff2fea__0[0x12U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x12U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h93bb4e5e__0[0x12U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x12U]));
        __Vtemp_ha3ff2fea__0[0x13U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x13U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h93bb4e5e__0[0x13U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x13U]));
        __Vtemp_ha3ff2fea__0[0x14U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x14U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h93bb4e5e__0[0x14U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x14U]));
        __Vtemp_ha3ff2fea__0[0x15U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x15U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h93bb4e5e__0[0x15U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x15U]));
        __Vtemp_ha3ff2fea__0[0x16U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x16U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h93bb4e5e__0[0x16U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x16U]));
        __Vtemp_ha3ff2fea__0[0x17U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x17U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h93bb4e5e__0[0x17U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x17U]));
        __Vtemp_ha3ff2fea__0[0x18U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x18U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h93bb4e5e__0[0x18U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x18U]));
        __Vtemp_ha3ff2fea__0[0x19U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x19U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h93bb4e5e__0[0x19U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x19U]));
        __Vtemp_ha3ff2fea__0[0x1aU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x1aU] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h93bb4e5e__0[0x1aU]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x1aU]));
        __Vtemp_ha3ff2fea__0[0x1bU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x1bU] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h93bb4e5e__0[0x1bU]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x1bU]));
        __Vtemp_ha3ff2fea__0[0x1cU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x1cU] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h93bb4e5e__0[0x1cU]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x1cU]));
        __Vtemp_ha3ff2fea__0[0x1dU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x1dU] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h93bb4e5e__0[0x1dU]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x1dU]));
        __Vtemp_ha3ff2fea__0[0x1eU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x1eU] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h93bb4e5e__0[0x1eU]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x1eU]));
        __Vtemp_ha3ff2fea__0[0x1fU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x1fU] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h93bb4e5e__0[0x1fU]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x1fU]));
        __Vtemp_ha3ff2fea__0[0x20U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x20U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h93bb4e5e__0[0x20U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x20U]));
        bufp->chgWData(oldp+3661,(__Vtemp_ha3ff2fea__0),1040);
        bufp->chgBit(oldp+3694,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+3695,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT__do_enq));
        bufp->chgWData(oldp+3696,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data),113);
        bufp->chgCData(oldp+3700,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__aFrag),3);
        bufp->chgCData(oldp+3701,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__old_gennum1),3);
        bufp->chgBit(oldp+3702,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__source_ok));
        bufp->chgBit(oldp+3703,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+3704,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+3705,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+3706,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+3707,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+3708,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+3709,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+3710,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+3711,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+3712,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+3713,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5) 
                                     << 7U) | (0x3fff80U 
                                               & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5) 
                                                   << 7U) 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 0xaU)))) 
                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__mask_acc_5) 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__mask_eq_5) 
                                           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                 >> 0x11U)))) 
                                       << 6U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4) 
                                                   << 5U) 
                                                  | (0xfffe0U 
                                                     & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4) 
                                                         << 5U) 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                           >> 0xcU)))) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__mask_acc_4) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__mask_eq_4) 
                                                         & (~ 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                             >> 0x11U)))) 
                                                     << 4U) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3) 
                                                         << 3U) 
                                                        | (0x3fff8U 
                                                           & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3) 
                                                               << 3U) 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                 >> 0xeU)))) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__mask_acc_3) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__mask_eq_3) 
                                                               & (~ 
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                   >> 0x11U)))) 
                                                           << 2U) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2) 
                                                               << 1U) 
                                                              | (0xfffeU 
                                                                 & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2) 
                                                                     << 1U) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                       >> 0x10U)))) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__mask_eq_2) 
                                                                   & (~ 
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                                       >> 0x11U)))))))))))),8);
        __Vtemp_hc961d23f__2[0U] = 1U;
        __Vtemp_hc961d23f__2[1U] = 0U;
        __Vtemp_hc961d23f__2[2U] = 0U;
        __Vtemp_hc961d23f__2[3U] = 0U;
        VL_EXTEND_WI(128,7, __Vtemp_h9a9a6856__2, (0x7fU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 0xaU)));
        VL_SHIFTL_WWW(128,128,128, __Vtemp_h996bff05__0, __Vtemp_hc961d23f__2, __Vtemp_h9a9a6856__2);
        if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___same_cycle_resp_T_1) {
            __Vtemp_hfb7966ea__0[0U] = __Vtemp_h996bff05__0[0U];
            __Vtemp_hfb7966ea__0[1U] = __Vtemp_h996bff05__0[1U];
            __Vtemp_hfb7966ea__0[2U] = (1U & __Vtemp_h996bff05__0[2U]);
        } else {
            __Vtemp_hfb7966ea__0[0U] = 0U;
            __Vtemp_hfb7966ea__0[1U] = 0U;
            __Vtemp_hfb7966ea__0[2U] = 0U;
        }
        bufp->chgWData(oldp+3714,(__Vtemp_hfb7966ea__0),65);
        bufp->chgBit(oldp+3717,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__same_cycle_resp));
        bufp->chgBit(oldp+3718,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT____Vcellinp__repeater__io_repeat));
        bufp->chgCData(oldp+3719,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT___repeater_io_deq_bits_size),3);
        bufp->chgBit(oldp+3720,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_8_a_valid));
        bufp->chgBit(oldp+3721,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_8_d_ready));
        bufp->chgBit(oldp+3722,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output));
        bufp->chgCData(oldp+3723,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode),3);
        bufp->chgCData(oldp+3724,((3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__aFrag))),2);
        bufp->chgSData(oldp+3725,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT___fragmenter_auto_out_a_bits_source),11);
        bufp->chgIData(oldp+3726,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT___fragmenter_auto_out_a_bits_address),21);
        bufp->chgCData(oldp+3727,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT___fragmenter_auto_out_a_bits_mask),8);
        bufp->chgBit(oldp+3728,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__x1_d_ready));
        bufp->chgBit(oldp+3729,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_deq));
        bufp->chgBit(oldp+3730,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__a_first_done));
        bufp->chgBit(oldp+3731,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__d_first_done));
        bufp->chgBit(oldp+3732,((2U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__aFrag)))));
        bufp->chgBit(oldp+3733,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+3734,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+3735,((1U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__aFrag)))));
        bufp->chgBit(oldp+3736,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+3737,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+3738,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+3739,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+3740,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+3741,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+3742,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+3743,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+3744,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__mask_acc_5) 
                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__mask_eq_5) 
                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT___fragmenter_auto_out_a_bits_address)) 
                                    << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__mask_acc_5) 
                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__mask_eq_5) 
                                                   & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT___fragmenter_auto_out_a_bits_address))) 
                                               << 6U) 
                                              | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__mask_acc_4) 
                                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__mask_eq_4) 
                                                      & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT___fragmenter_auto_out_a_bits_address)) 
                                                  << 5U) 
                                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__mask_acc_4) 
                                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__mask_eq_4) 
                                                         & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT___fragmenter_auto_out_a_bits_address))) 
                                                     << 4U) 
                                                    | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__mask_acc_3) 
                                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__mask_eq_3) 
                                                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT___fragmenter_auto_out_a_bits_address)) 
                                                        << 3U) 
                                                       | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__mask_acc_3) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__mask_eq_3) 
                                                               & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT___fragmenter_auto_out_a_bits_address))) 
                                                           << 2U) 
                                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__mask_acc_2) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__mask_eq_2) 
                                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT___fragmenter_auto_out_a_bits_address)) 
                                                              << 1U) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__mask_eq_2) 
                                                                   & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT___fragmenter_auto_out_a_bits_address))))))))))),8);
        VL_EXTEND_WI(2048,11, __Vtemp_h760111ce__0, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT___fragmenter_auto_out_a_bits_source));
        VL_SHIFTL_WWW(2048,2048,2048, __Vtemp_h47380d22__0, VTestHarness__ConstPool__CONST_ha056d847_0, __Vtemp_h760111ce__0);
        __Vtemp_h99228d75__0[0U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h47380d22__0[0U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[0U]));
        __Vtemp_h99228d75__0[1U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[1U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h47380d22__0[1U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[1U]));
        __Vtemp_h99228d75__0[2U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[2U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h47380d22__0[2U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[2U]));
        __Vtemp_h99228d75__0[3U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[3U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h47380d22__0[3U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[3U]));
        __Vtemp_h99228d75__0[4U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[4U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h47380d22__0[4U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[4U]));
        __Vtemp_h99228d75__0[5U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[5U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h47380d22__0[5U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[5U]));
        __Vtemp_h99228d75__0[6U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[6U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h47380d22__0[6U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[6U]));
        __Vtemp_h99228d75__0[7U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[7U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h47380d22__0[7U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[7U]));
        __Vtemp_h99228d75__0[8U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[8U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h47380d22__0[8U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[8U]));
        __Vtemp_h99228d75__0[9U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[9U] 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                        ? __Vtemp_h47380d22__0[9U]
                                        : VTestHarness__ConstPool__CONST_hd0572db1_0[9U]));
        __Vtemp_h99228d75__0[0xaU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0xaU] 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                          ? __Vtemp_h47380d22__0[0xaU]
                                          : VTestHarness__ConstPool__CONST_hd0572db1_0[0xaU]));
        __Vtemp_h99228d75__0[0xbU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0xbU] 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                          ? __Vtemp_h47380d22__0[0xbU]
                                          : VTestHarness__ConstPool__CONST_hd0572db1_0[0xbU]));
        __Vtemp_h99228d75__0[0xcU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0xcU] 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                          ? __Vtemp_h47380d22__0[0xcU]
                                          : VTestHarness__ConstPool__CONST_hd0572db1_0[0xcU]));
        __Vtemp_h99228d75__0[0xdU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0xdU] 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                          ? __Vtemp_h47380d22__0[0xdU]
                                          : VTestHarness__ConstPool__CONST_hd0572db1_0[0xdU]));
        __Vtemp_h99228d75__0[0xeU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0xeU] 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                          ? __Vtemp_h47380d22__0[0xeU]
                                          : VTestHarness__ConstPool__CONST_hd0572db1_0[0xeU]));
        __Vtemp_h99228d75__0[0xfU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0xfU] 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                          ? __Vtemp_h47380d22__0[0xfU]
                                          : VTestHarness__ConstPool__CONST_hd0572db1_0[0xfU]));
        __Vtemp_h99228d75__0[0x10U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x10U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h47380d22__0[0x10U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x10U]));
        __Vtemp_h99228d75__0[0x11U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x11U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h47380d22__0[0x11U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x11U]));
        __Vtemp_h99228d75__0[0x12U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x12U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h47380d22__0[0x12U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x12U]));
        __Vtemp_h99228d75__0[0x13U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x13U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h47380d22__0[0x13U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x13U]));
        __Vtemp_h99228d75__0[0x14U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x14U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h47380d22__0[0x14U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x14U]));
        __Vtemp_h99228d75__0[0x15U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x15U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h47380d22__0[0x15U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x15U]));
        __Vtemp_h99228d75__0[0x16U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x16U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h47380d22__0[0x16U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x16U]));
        __Vtemp_h99228d75__0[0x17U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x17U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h47380d22__0[0x17U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x17U]));
        __Vtemp_h99228d75__0[0x18U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x18U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h47380d22__0[0x18U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x18U]));
        __Vtemp_h99228d75__0[0x19U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x19U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h47380d22__0[0x19U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x19U]));
        __Vtemp_h99228d75__0[0x1aU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x1aU] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h47380d22__0[0x1aU]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x1aU]));
        __Vtemp_h99228d75__0[0x1bU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x1bU] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h47380d22__0[0x1bU]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x1bU]));
        __Vtemp_h99228d75__0[0x1cU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x1cU] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h47380d22__0[0x1cU]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x1cU]));
        __Vtemp_h99228d75__0[0x1dU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x1dU] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h47380d22__0[0x1dU]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x1dU]));
        __Vtemp_h99228d75__0[0x1eU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x1eU] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h47380d22__0[0x1eU]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x1eU]));
        __Vtemp_h99228d75__0[0x1fU] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x1fU] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h47380d22__0[0x1fU]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x1fU]));
        __Vtemp_h99228d75__0[0x20U] = (VTestHarness__ConstPool__CONST_hf1d89c7e_0[0x20U] 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)
                                           ? __Vtemp_h47380d22__0[0x20U]
                                           : VTestHarness__ConstPool__CONST_hd0572db1_0[0x20U]));
        bufp->chgWData(oldp+3745,(__Vtemp_h99228d75__0),1040);
        bufp->chgBit(oldp+3778,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__same_cycle_resp));
    }
}
