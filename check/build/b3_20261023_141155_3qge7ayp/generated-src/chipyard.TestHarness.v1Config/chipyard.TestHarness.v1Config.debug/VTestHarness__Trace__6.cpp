// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "VTestHarness__Syms.h"


extern const VlWide<8>/*255:0*/ VTestHarness__ConstPool__CONST_h8692eb69_0;

void VTestHarness___024root__trace_chg_sub_6(VTestHarness___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root__trace_chg_sub_6\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 22088);
    VlWide<3>/*95:0*/ __Vtemp_h027c6960__0;
    VlWide<3>/*95:0*/ __Vtemp_h912d543e__0;
    VlWide<3>/*95:0*/ __Vtemp_h4dc51b7d__0;
    VlWide<32>/*1023:0*/ __Vtemp_h3ea52170__0;
    VlWide<32>/*1023:0*/ __Vtemp_h428b18ee__0;
    VlWide<5>/*159:0*/ __Vtemp_h1d35920d__0;
    VlWide<5>/*159:0*/ __Vtemp_h9a3b1cfe__0;
    VlWide<5>/*159:0*/ __Vtemp_hd9f6050b__0;
    VlWide<8>/*255:0*/ __Vtemp_hc3fbb1f4__0;
    VlWide<4>/*127:0*/ __Vtemp_hbb192ce2__0;
    VlWide<6>/*191:0*/ __Vtemp_hbaa1852e__0;
    VlWide<6>/*191:0*/ __Vtemp_h8d7a1f6d__0;
    VlWide<6>/*191:0*/ __Vtemp_ha339f990__0;
    VlWide<6>/*191:0*/ __Vtemp_h8571e342__0;
    VlWide<5>/*159:0*/ __Vtemp_h1084c790__0;
    VlWide<5>/*159:0*/ __Vtemp_h3ebd5f28__0;
    VlWide<32>/*1023:0*/ __Vtemp_hf5e842cb__0;
    VlWide<32>/*1023:0*/ __Vtemp_hb44432c5__0;
    VlWide<32>/*1023:0*/ __Vtemp_hae9f0cf3__0;
    VlWide<32>/*1023:0*/ __Vtemp_h5ef10458__0;
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x10U])) {
        bufp->chgBit(oldp+0,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__pmp__DOT__res_hit));
        bufp->chgBit(oldp+1,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__pmp__DOT__res_ignore));
        bufp->chgBit(oldp+2,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__pmp__DOT__res_hit_1));
        bufp->chgBit(oldp+3,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__pmp__DOT__res_ignore_1));
        bufp->chgBit(oldp+4,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__pmp__DOT__res_hit_2));
        bufp->chgBit(oldp+5,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__pmp__DOT__res_ignore_2));
        bufp->chgBit(oldp+6,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__pmp__DOT__res_hit_3));
        bufp->chgBit(oldp+7,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__pmp__DOT__res_ignore_3));
        bufp->chgBit(oldp+8,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__pmp__DOT__res_hit_4));
        bufp->chgBit(oldp+9,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__pmp__DOT__res_ignore_4));
        bufp->chgBit(oldp+10,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__pmp__DOT__res_hit_5));
        bufp->chgBit(oldp+11,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__pmp__DOT__res_ignore_5));
        bufp->chgBit(oldp+12,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__pmp__DOT__res_hit_6));
        bufp->chgBit(oldp+13,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__pmp__DOT__res_ignore_6));
        bufp->chgBit(oldp+14,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__pmp__DOT__res_hit_7));
        bufp->chgBit(oldp+15,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__pmp__DOT__res_ignore_7));
        bufp->chgBit(oldp+16,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__do_switch));
        bufp->chgBit(oldp+17,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__l2_refill));
        bufp->chgCData(oldp+18,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state),3);
        bufp->chgBit(oldp+19,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__invalidated));
        bufp->chgCData(oldp+20,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count),2);
        bufp->chgIData(oldp+21,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_req_addr),27);
        bufp->chgBit(oldp+22,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_req_vstage1));
        bufp->chgBit(oldp+23,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_req_stage2));
        bufp->chgBit(oldp+24,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_req_dest));
        bufp->chgQData(oldp+25,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_hgatp_ppn),44);
        bufp->chgCData(oldp+27,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_count),2);
        bufp->chgSData(oldp+28,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_reserved_for_future),10);
        bufp->chgQData(oldp+29,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_ppn),44);
        bufp->chgCData(oldp+31,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_reserved_for_software),2);
        bufp->chgBit(oldp+32,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_d));
        bufp->chgBit(oldp+33,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_a));
        bufp->chgBit(oldp+34,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_g));
        bufp->chgBit(oldp+35,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_u));
        bufp->chgBit(oldp+36,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_x));
        bufp->chgBit(oldp+37,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_w));
        bufp->chgBit(oldp+38,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_r));
        bufp->chgBit(oldp+39,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_v));
        bufp->chgSData(oldp+40,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__gpa_pgoff),12);
        bufp->chgBit(oldp+41,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__stage2));
        bufp->chgBit(oldp+42,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__stage2_final));
        bufp->chgBit(oldp+43,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__do_both_stages));
        bufp->chgBit(oldp+44,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__mem_resp_valid));
        bufp->chgQData(oldp+45,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__mem_resp_data),64);
        bufp->chgBit(oldp+47,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_pte_v));
        bufp->chgBit(oldp+48,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__invalid_paddr));
        bufp->chgBit(oldp+49,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__traverse));
        bufp->chgSData(oldp+50,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pte_addr_vpn_idx),9);
        bufp->chgCData(oldp+51,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state_reg),7);
        bufp->chgCData(oldp+52,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__valid),8);
        bufp->chgIData(oldp+53,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__tags_0),32);
        bufp->chgIData(oldp+54,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__tags_1),32);
        bufp->chgIData(oldp+55,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__tags_2),32);
        bufp->chgIData(oldp+56,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__tags_3),32);
        bufp->chgIData(oldp+57,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__tags_4),32);
        bufp->chgIData(oldp+58,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__tags_5),32);
        bufp->chgIData(oldp+59,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__tags_6),32);
        bufp->chgIData(oldp+60,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__tags_7),32);
        bufp->chgIData(oldp+61,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__data_0),20);
        bufp->chgIData(oldp+62,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__data_1),20);
        bufp->chgIData(oldp+63,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__data_2),20);
        bufp->chgIData(oldp+64,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__data_3),20);
        bufp->chgIData(oldp+65,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__data_4),20);
        bufp->chgIData(oldp+66,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__data_5),20);
        bufp->chgIData(oldp+67,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__data_6),20);
        bufp->chgIData(oldp+68,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__data_7),20);
        bufp->chgBit(oldp+69,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__can_hit));
        bufp->chgQData(oldp+70,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__tag),33);
        bufp->chgCData(oldp+72,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__hits),8);
        bufp->chgBit(oldp+73,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pte_cache_hit));
        bufp->chgCData(oldp+74,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__state_reg_1),7);
        bufp->chgCData(oldp+75,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__valid_1),8);
        bufp->chgIData(oldp+76,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__tags_1_0),32);
        bufp->chgIData(oldp+77,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__tags_1_1),32);
        bufp->chgIData(oldp+78,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__tags_1_2),32);
        bufp->chgIData(oldp+79,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__tags_1_3),32);
        bufp->chgIData(oldp+80,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__tags_1_4),32);
        bufp->chgIData(oldp+81,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__tags_1_5),32);
        bufp->chgIData(oldp+82,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__tags_1_6),32);
        bufp->chgIData(oldp+83,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__tags_1_7),32);
        bufp->chgIData(oldp+84,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__data_1_0),20);
        bufp->chgIData(oldp+85,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__data_1_1),20);
        bufp->chgIData(oldp+86,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__data_1_2),20);
        bufp->chgIData(oldp+87,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__data_1_3),20);
        bufp->chgIData(oldp+88,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__data_1_4),20);
        bufp->chgIData(oldp+89,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__data_1_5),20);
        bufp->chgIData(oldp+90,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__data_1_6),20);
        bufp->chgIData(oldp+91,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__data_1_7),20);
        bufp->chgIData(oldp+92,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask),32);
        bufp->chgIData(oldp+93,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_1),32);
        bufp->chgIData(oldp+94,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_2),32);
        bufp->chgIData(oldp+95,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_3),32);
        bufp->chgIData(oldp+96,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_4),32);
        bufp->chgIData(oldp+97,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_5),32);
        bufp->chgIData(oldp+98,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_6),32);
        bufp->chgIData(oldp+99,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_7),32);
        bufp->chgBit(oldp+100,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__gf));
        bufp->chgBit(oldp+101,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__ae));
        bufp->chgBit(oldp+102,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pf));
        bufp->chgBit(oldp+103,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__success));
        bufp->chgCData(oldp+104,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r),3);
        bufp->chgCData(oldp+105,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_1),3);
        bufp->chgBit(oldp+106,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___arb_io_out_valid));
        bufp->chgBit(oldp+107,((1U & ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_state)) 
                                      | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__tlb__io_kill))))));
        bufp->chgIData(oldp+108,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___arb_io_out_bits_bits_addr),27);
        bufp->chgBit(oldp+109,(((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_state))
                                 ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_need_gpa)
                                 : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__r_need_gpa))));
        bufp->chgBit(oldp+110,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___arb_io_out_bits_bits_vstage1));
        bufp->chgBit(oldp+111,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___arb_io_out_bits_bits_stage2));
        bufp->chgBit(oldp+112,((1U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_state))));
        bufp->chgSData(oldp+113,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_5)
                                   ? 0U : (0x3ffU & 
                                           ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_10)
                                             ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_reserved_for_future)
                                             : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_8)
                                                 ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_reserved_for_future)
                                                 : (IData)(
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__mem_resp_data 
                                                            >> 0x36U))))))),10);
        bufp->chgQData(oldp+114,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT____Vcellinp__r_pte_barrier__io_x_ppn),44);
        bufp->chgCData(oldp+116,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_5)
                                   ? 0U : (3U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_10)
                                                  ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_reserved_for_software)
                                                  : 
                                                 ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_8)
                                                   ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_reserved_for_software)
                                                   : (IData)(
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__mem_resp_data 
                                                              >> 8U))))))),2);
        bufp->chgBit(oldp+117,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_5)) 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_10)
                                          ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_d)
                                          : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_8)
                                              ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_d)
                                              : (IData)(
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__mem_resp_data 
                                                         >> 7U))))))));
        bufp->chgBit(oldp+118,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_5)) 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_10)
                                          ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_a)
                                          : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_8)
                                              ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_a)
                                              : (IData)(
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__mem_resp_data 
                                                         >> 6U))))))));
        bufp->chgBit(oldp+119,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_5)) 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_10)
                                          ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_g)
                                          : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_8)
                                              ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_g)
                                              : (IData)(
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__mem_resp_data 
                                                         >> 5U))))))));
        bufp->chgBit(oldp+120,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_5)) 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_10)
                                          ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_u)
                                          : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_8)
                                              ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_u)
                                              : (IData)(
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__mem_resp_data 
                                                         >> 4U))))))));
        bufp->chgBit(oldp+121,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_5)) 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_10)
                                          ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_x)
                                          : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_8)
                                              ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_x)
                                              : (IData)(
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__mem_resp_data 
                                                         >> 3U))))))));
        bufp->chgBit(oldp+122,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_5)) 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_10)
                                          ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_w)
                                          : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_8)
                                              ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_w)
                                              : (IData)(
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__mem_resp_data 
                                                         >> 2U))))))));
        bufp->chgBit(oldp+123,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_5)) 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_10)
                                          ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_r)
                                          : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_8)
                                              ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_r)
                                              : (IData)(
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__mem_resp_data 
                                                         >> 1U))))))));
        bufp->chgBit(oldp+124,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_5)) 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_10)
                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_v)
                                    : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___r_pte_T_8)
                                        ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_v)
                                        : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__aux_pte_pte_v))))));
        bufp->chgBit(oldp+125,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                   >> 0xeU))));
        bufp->chgBit(oldp+126,((1U & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__ptr_match) 
                                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__maybe_full))))));
        bufp->chgBit(oldp+127,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__enq_ptr_value));
        bufp->chgBit(oldp+128,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__deq_ptr_value));
        bufp->chgBit(oldp+129,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__maybe_full));
        bufp->chgBit(oldp+130,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__ptr_match));
        bufp->chgBit(oldp+131,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__empty));
        bufp->chgBit(oldp+132,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__ptr_match) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__maybe_full))));
        bufp->chgBit(oldp+133,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__do_enq));
        bufp->chgBit(oldp+134,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__do_deq));
        __Vtemp_h027c6960__0[0U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ghe_rd_val) 
                                     << 5U) | (0x1fU 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                  >> 7U)));
        __Vtemp_h027c6960__0[1U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ghe_rd_val) 
                                     >> 0x1bU) | ((IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ghe_rd_val 
                                                           >> 0x20U)) 
                                                  << 5U));
        __Vtemp_h027c6960__0[2U] = ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ghe_rd_val 
                                             >> 0x20U)) 
                                    >> 0x1bU);
        bufp->chgWData(oldp+135,(__Vtemp_h027c6960__0),69);
        bufp->chgWData(oldp+138,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT___ram_ext_R0_data),69);
        bufp->chgWData(oldp+141,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__ram_ext__DOT__Memory[0]),69);
        bufp->chgWData(oldp+144,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__ram_ext__DOT__Memory[1]),69);
        bufp->chgSData(oldp+147,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__beatsLeft),9);
        bufp->chgBit(oldp+148,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__beatsLeft))));
        bufp->chgCData(oldp+149,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__readys_valid),2);
        bufp->chgCData(oldp+150,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__readys_mask),2);
        bufp->chgCData(oldp+151,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__readys_readys),2);
        bufp->chgBit(oldp+152,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__readys_readys) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid))));
        bufp->chgBit(oldp+153,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__readys_readys) 
                                 >> 1U) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__tl_out_a_valid))));
        bufp->chgBit(oldp+154,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__state_0));
        bufp->chgBit(oldp+155,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__state_1));
        bufp->chgBit(oldp+156,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__muxStateEarly_0));
        bufp->chgBit(oldp+157,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__muxStateEarly_1));
        bufp->chgBit(oldp+158,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__winnerQual_0));
        bufp->chgSData(oldp+159,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__a_first_counter),9);
        bufp->chgCData(oldp+160,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__opcode),3);
        bufp->chgCData(oldp+161,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__param),3);
        bufp->chgCData(oldp+162,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__size),4);
        bufp->chgBit(oldp+163,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__source));
        bufp->chgIData(oldp+164,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__address),32);
        bufp->chgSData(oldp+165,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_first_counter),9);
        bufp->chgCData(oldp+166,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__opcode_1),3);
        bufp->chgCData(oldp+167,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__param_1),2);
        bufp->chgCData(oldp+168,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__size_1),4);
        bufp->chgBit(oldp+169,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__source_1));
        bufp->chgCData(oldp+170,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__sink),3);
        bufp->chgBit(oldp+171,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__denied));
        bufp->chgSData(oldp+172,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__c_first_counter),9);
        bufp->chgCData(oldp+173,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__opcode_3),3);
        bufp->chgCData(oldp+174,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__param_3),3);
        bufp->chgCData(oldp+175,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__size_3),4);
        bufp->chgBit(oldp+176,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__source_3));
        bufp->chgIData(oldp+177,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__address_2),32);
        bufp->chgCData(oldp+178,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__inflight),2);
        bufp->chgCData(oldp+179,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__inflight_opcodes),8);
        bufp->chgSData(oldp+180,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__inflight_sizes),16);
        bufp->chgSData(oldp+181,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__a_first_counter_1),9);
        bufp->chgBit(oldp+182,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__a_first_counter_1))));
        bufp->chgSData(oldp+183,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_first_counter_1),9);
        bufp->chgBit(oldp+184,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_first_counter_1))));
        bufp->chgIData(oldp+185,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__watchdog),32);
        bufp->chgCData(oldp+186,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__inflight_1),2);
        bufp->chgSData(oldp+187,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__inflight_sizes_1),16);
        bufp->chgSData(oldp+188,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__c_first_counter_1),9);
        bufp->chgBit(oldp+189,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__c_first_counter_1))));
        bufp->chgSData(oldp+190,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_first_counter_2),9);
        bufp->chgBit(oldp+191,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_first_counter_2))));
        bufp->chgIData(oldp+192,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__watchdog_1),32);
        bufp->chgCData(oldp+193,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__inflight_2),8);
        bufp->chgSData(oldp+194,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_first_counter_3),9);
        bufp->chgBit(oldp+195,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_first_counter_3))));
        bufp->chgBit(oldp+196,((2U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)))));
        bufp->chgBit(oldp+197,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+198,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+199,((1U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)))));
        bufp->chgBit(oldp+200,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+201,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+202,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+203,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+204,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+205,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+206,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+207,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+208,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_5) 
                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_5) 
                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                   << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_5) 
                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_5) 
                                                  & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address))) 
                                              << 6U) 
                                             | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_4) 
                                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_4) 
                                                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                                 << 5U) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_4) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_4) 
                                                        & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address))) 
                                                    << 4U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_3) 
                                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_3) 
                                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                                       << 3U) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_3) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_3) 
                                                              & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address))) 
                                                          << 2U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_2) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_2) 
                                                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address)) 
                                                             << 1U) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_2) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_2) 
                                                                  & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address))))))))))),8);
        bufp->chgBit(oldp+209,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_14));
        bufp->chgBit(oldp+210,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_15));
        bufp->chgBit(oldp+211,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_16));
        bufp->chgBit(oldp+212,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_16));
        bufp->chgBit(oldp+213,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_17));
        bufp->chgBit(oldp+214,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_17));
        bufp->chgBit(oldp+215,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_18));
        bufp->chgBit(oldp+216,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_18));
        bufp->chgBit(oldp+217,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_19));
        bufp->chgBit(oldp+218,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_19));
        bufp->chgCData(oldp+219,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_19) 
                                    << 7U) | (0x3fffff80U 
                                              & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_19) 
                                                  << 7U) 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                    >> 2U)))) 
                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_19) 
                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_19) 
                                          & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                >> 9U)))) 
                                      << 6U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_18) 
                                                  << 5U) 
                                                 | (0xfffffe0U 
                                                    & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_18) 
                                                        << 5U) 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                          >> 4U)))) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_18) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_18) 
                                                        & (~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                            >> 9U)))) 
                                                    << 4U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_17) 
                                                        << 3U) 
                                                       | (0x3fffff8U 
                                                          & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_17) 
                                                              << 3U) 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                >> 6U)))) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_17) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_17) 
                                                              & (~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                  >> 9U)))) 
                                                          << 2U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_16) 
                                                              << 1U) 
                                                             | (0xfffffeU 
                                                                & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_16) 
                                                                    << 1U) 
                                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                      >> 8U)))) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_acc_16) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT__mask_eq_16) 
                                                                  & (~ 
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                      >> 9U)))))))))))),8);
        bufp->chgCData(oldp+220,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT___same_cycle_resp_T_1)
                                   ? (3U & ((IData)(1U) 
                                            << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_source)))
                                   : 0U)),2);
        bufp->chgCData(oldp+221,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT___same_cycle_resp_T_3) 
                                   & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_opcode))))
                                   ? (3U & ((IData)(1U) 
                                            << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_source)))
                                   : 0U)),2);
        bufp->chgSData(oldp+222,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_first_counter),9);
        bufp->chgCData(oldp+223,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__opcode_1),3);
        bufp->chgCData(oldp+224,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__param_1),2);
        bufp->chgCData(oldp+225,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__size_1),4);
        bufp->chgBit(oldp+226,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__source_1));
        bufp->chgCData(oldp+227,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__sink),3);
        bufp->chgBit(oldp+228,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__denied));
        bufp->chgBit(oldp+229,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__inflight));
        bufp->chgCData(oldp+230,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__inflight_opcodes),4);
        bufp->chgCData(oldp+231,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__inflight_sizes),8);
        bufp->chgSData(oldp+232,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_first_counter_1),9);
        bufp->chgBit(oldp+233,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_first_counter_1))));
        bufp->chgIData(oldp+234,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__watchdog),32);
        bufp->chgSData(oldp+235,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_first_counter_2),9);
        bufp->chgBit(oldp+236,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_first_counter_2))));
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[0x10U] 
                     | vlSelf->__Vm_traceActivity[0x29U]))) {
        bufp->chgBit(oldp+237,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__s_or_r) 
                                 & (0x18U == (0x78U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2[4U]))) 
                                & (((7U != (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2[4U])) 
                                    & (4U != (7U & 
                                              vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2[4U]))) 
                                   & (0U != (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2[4U]))))));
        bufp->chgBit(oldp+238,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__s_or_r) 
                                 & (0x1800U == (0x7800U 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2[8U]))) 
                                & (((7U != (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2[8U] 
                                                  >> 8U))) 
                                    & (4U != (7U & 
                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2[8U] 
                                               >> 8U)))) 
                                   & (0U != (7U & (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2[8U] 
                                                   >> 8U)))))));
        bufp->chgBit(oldp+239,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__s_or_r) 
                                & (0x1cU == (0x7fU 
                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2[4U])))));
        bufp->chgBit(oldp+240,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__s_or_r) 
                                & (0x1c00U == (0x7f00U 
                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_2[8U])))));
        bufp->chgBit(oldp+241,((((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_perf_acquire_counter)) 
                                 | (0U == ((4U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))
                                            ? 0U : 
                                           (0x1ffU 
                                            & (~ (0xffffffU 
                                                  & (((IData)(0xfffU) 
                                                      << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)) 
                                                     >> 3U))))))) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_perf_acquire_T))));
        bufp->chgBit(oldp+242,((((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_perf_release_counter)) 
                                 | (0U == ((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_opcode))
                                            ? (0x1ffU 
                                               & (~ 
                                                  (((0x1aU 
                                                     >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_size))
                                                     ? 
                                                    (0x7ffffffU 
                                                     & ((IData)(0xfffU) 
                                                        << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_size)))
                                                     : 0U) 
                                                   >> 3U)))
                                            : 0U))) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___T_336))));
        bufp->chgBit(oldp+243,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_wb)) 
                                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode))))));
        bufp->chgBit(oldp+244,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_valid) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_wb)))));
        bufp->chgBit(oldp+245,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_valid) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_fence_i)) 
                                 & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                                       | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)))) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_requestor_2_s2_nack)))));
        bufp->chgBit(oldp+246,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_valid) 
                                & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_jal) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_jalr)) 
                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_branch)))));
        bufp->chgBit(oldp+247,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_valid) 
                                 & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T_29))) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_csr_stall_output)))));
        bufp->chgBit(oldp+248,((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___T_409) 
                                   & ((0x1fU >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1))
                                       ? ((0xfffffffeU 
                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___r) 
                                          >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1))
                                       : 0U)) & (~ 
                                                 ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ll_wen) 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ll_waddr) 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1))))) 
                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___T_411) 
                                     & ((0x1fU >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2))
                                         ? ((0xfffffffeU 
                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___r) 
                                            >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2))
                                         : 0U)) & (~ 
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ll_wen) 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ll_waddr) 
                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2)))))) 
                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___T_413) 
                                    & ((0x1fU >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rd))
                                        ? ((0xfffffffeU 
                                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___r) 
                                           >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rd))
                                        : 0U)) & (~ 
                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ll_wen) 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ll_waddr) 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rd))))))));
        bufp->chgBit(oldp+249,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_wen) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_set_sboard)))));
        bufp->chgBit(oldp+250,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__if_RSU_packet) 
                                & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__packet_index)))));
        bufp->chgBit(oldp+251,(((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__icsl__io_if_correct_process) 
                                    & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__io_if_check_privret_REG)) 
                                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__ic_counter_done)) 
                                  & ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__fsm_state)) 
                                     | (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__fsm_state)))) 
                                 & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__icsl__io_returned_to_special_address_valid))) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__excpt_mode)))));
        bufp->chgQData(oldp+252,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_deq_valid_0)
                                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_deq_data_0
                                    : 0ULL) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_deq_valid_1)
                                                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_deq_data_1
                                                : 0ULL))),64);
        bufp->chgBit(oldp+254,((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen)) 
                                & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))));
        bufp->chgQData(oldp+255,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : 0ULL) : ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                    & (0U 
                                                       != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                   & (0U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                   : 0ULL))),64);
        bufp->chgQData(oldp+257,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0x1eU]) : ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                    & (0U 
                                                       != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                   & (1U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                   : 
                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                  [0x1eU]))),64);
        bufp->chgQData(oldp+259,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_7)
                                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rf_sp
                                   : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                       ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                           & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                           ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                           : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                          [0x1dU]) : 
                                      ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                         & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                        & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                        ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                        : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                       [0x1dU])))),64);
        bufp->chgQData(oldp+261,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_7)
                                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rf_gp
                                   : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                       ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                           & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                           ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                           : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                          [0x1cU]) : 
                                      ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                         & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                        & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                        ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                        : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                       [0x1cU])))),64);
        bufp->chgQData(oldp+263,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0x1bU]) : ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                    & (0U 
                                                       != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                   & (4U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                   : 
                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                  [0x1bU]))),64);
        bufp->chgQData(oldp+265,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0x1aU]) : ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                    & (0U 
                                                       != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                   & (5U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                   : 
                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                  [0x1aU]))),64);
        bufp->chgQData(oldp+267,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0x19U]) : ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                    & (0U 
                                                       != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                   & (6U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                   : 
                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                  [0x19U]))),64);
        bufp->chgQData(oldp+269,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0x18U]) : ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                    & (0U 
                                                       != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                   & (7U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                   : 
                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                  [0x18U]))),64);
        bufp->chgQData(oldp+271,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0x17U]) : ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                    & (0U 
                                                       != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                   & (8U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                   : 
                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                  [0x17U]))),64);
        bufp->chgQData(oldp+273,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (9U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0x16U]) : ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                    & (0U 
                                                       != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                   & (9U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                   : 
                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                  [0x16U]))),64);
        bufp->chgQData(oldp+275,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0xaU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0x15U]) : ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                    & (0U 
                                                       != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                   & (0xaU 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                   : 
                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                  [0x15U]))),64);
        bufp->chgQData(oldp+277,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0xbU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0x14U]) : ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                    & (0U 
                                                       != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                   & (0xbU 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                   : 
                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                  [0x14U]))),64);
        bufp->chgQData(oldp+279,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0xcU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0x13U]) : ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                    & (0U 
                                                       != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                   & (0xcU 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                   : 
                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                  [0x13U]))),64);
        bufp->chgQData(oldp+281,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0xdU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0x12U]) : ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                    & (0U 
                                                       != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                   & (0xdU 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                   : 
                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                  [0x12U]))),64);
        bufp->chgQData(oldp+283,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0xeU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0x11U]) : ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                    & (0U 
                                                       != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                   & (0xeU 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                   : 
                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                  [0x11U]))),64);
        bufp->chgQData(oldp+285,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0xfU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0x10U]) : ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                    & (0U 
                                                       != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                   & (0xfU 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                   : 
                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                  [0x10U]))),64);
        bufp->chgQData(oldp+287,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0xfU]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                   & (0U 
                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                  & (0x10U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                  : 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                 [0xfU]))),64);
        bufp->chgQData(oldp+289,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x11U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0xeU]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                   & (0U 
                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                  & (0x11U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                  : 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                 [0xeU]))),64);
        bufp->chgQData(oldp+291,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0xdU]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                   & (0U 
                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                  & (0x12U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                  : 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                 [0xdU]))),64);
        bufp->chgQData(oldp+293,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x13U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0xcU]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                   & (0U 
                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                  & (0x13U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                  : 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                 [0xcU]))),64);
        bufp->chgQData(oldp+295,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0xbU]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                   & (0U 
                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                  & (0x14U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                  : 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                 [0xbU]))),64);
        bufp->chgQData(oldp+297,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x15U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0xaU]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                   & (0U 
                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                  & (0x15U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                  : 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                                 [0xaU]))),64);
        bufp->chgQData(oldp+299,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [9U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                 & (0U 
                                                    != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                & (0x16U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                               [9U]))),64);
        bufp->chgQData(oldp+301,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x17U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [8U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                 & (0U 
                                                    != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                & (0x17U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                               [8U]))),64);
        bufp->chgQData(oldp+303,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [7U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                 & (0U 
                                                    != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                & (0x18U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                               [7U]))),64);
        bufp->chgQData(oldp+305,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x19U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [6U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                 & (0U 
                                                    != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                & (0x19U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                               [6U]))),64);
        bufp->chgQData(oldp+307,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [5U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                 & (0U 
                                                    != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                & (0x1aU 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                               [5U]))),64);
        bufp->chgQData(oldp+309,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x1bU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [4U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                 & (0U 
                                                    != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                & (0x1bU 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                               [4U]))),64);
        bufp->chgQData(oldp+311,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [3U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                 & (0U 
                                                    != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                & (0x1cU 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                               [3U]))),64);
        bufp->chgQData(oldp+313,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x1dU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [2U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                 & (0U 
                                                    != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                & (0x1dU 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                               [2U]))),64);
        bufp->chgQData(oldp+315,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [1U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                 & (0U 
                                                    != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                & (0x1eU 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                               [1U]))),64);
        bufp->chgQData(oldp+317,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
                                   ? (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)) 
                                       & (0x1fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                      [0U]) : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen) 
                                                 & (0U 
                                                    != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr))) 
                                                & (0x1fU 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))
                                                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wdata
                                                : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                               [0U]))),64);
        bufp->chgQData(oldp+319,((((QData)((IData)(
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN[
                                                   (((IData)(0x3fU) 
                                                     + 
                                                     (0x7c0U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__recording_counter) 
                                                         << 6U))) 
                                                    >> 5U)])) 
                                   << 0x20U) | (QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN[
                                                               (0x3eU 
                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__recording_counter) 
                                                                   << 1U))])))),64);
        bufp->chgBit(oldp+321,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__packet_valid)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___T_17))));
        bufp->chgBit(oldp+322,((((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__packet_valid) 
                                     | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___T_17))) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___T_18)) 
                                & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))));
        bufp->chgBit(oldp+323,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__do_check) 
                                  & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter))) 
                                 & (0x1fU != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay))) 
                                & (((((QData)((IData)(
                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN[
                                                      (((IData)(0x3fU) 
                                                        + 
                                                        (0x7c0U 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay) 
                                                            << 6U))) 
                                                       >> 5U)])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN[
                                                                  (0x3eU 
                                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay) 
                                                                      << 1U))]))) 
                                    != ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ECP_ext__DOT___GEN)
                                         ? ((0x20U 
                                             >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ECP_ext__DOT___GEN_0))
                                             ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ECP_ext__DOT__Memory
                                            [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ECP_ext__DOT___GEN_0]
                                             : 0ULL)
                                         : 0ULL)) | 
                                   ((((QData)((IData)(
                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN_0[
                                                      (((IData)(0x3fU) 
                                                        + 
                                                        (0x7c0U 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay) 
                                                            << 6U))) 
                                                       >> 5U)])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN_0[
                                                                  (0x3eU 
                                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay) 
                                                                      << 1U))]))) 
                                    != ((0x20U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss_ECP__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram_R_0_addr_pipe_0))
                                         ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss_ECP__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram
                                        [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss_ECP__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram_R_0_addr_pipe_0]
                                         : 0ULL))))));
        bufp->chgBit(oldp+324,((((3U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__inflight)) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__empty)) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcIF__DOT____Vcellinp__replayq__io_nack_valid)))));
        bufp->chgBit(oldp+325,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_nack_output) 
                                & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT__s2_id)))));
        bufp->chgBit(oldp+326,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_valid) 
                                & (((0xffffffffffULL 
                                     & (~ (1ULL | (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_pc)))) 
                                    == (0xffffffffffULL 
                                        & (~ (1ULL 
                                              | (~ 
                                                 (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                   << 0x38U) 
                                                  | (((QData)((IData)(
                                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                      << 0x18U) 
                                                     | ((QData)((IData)(
                                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                                        >> 8U))))))))
                                    ? (((0xffffffffffULL 
                                         & (~ (1ULL 
                                               | (~ 
                                                  (((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                    << 0x38U) 
                                                   | (((QData)((IData)(
                                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                       << 0x18U) 
                                                      | ((QData)((IData)(
                                                                         vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                                         >> 8U))))))) 
                                        == (0xffffffffffULL 
                                            & (~ (3ULL 
                                                  | (~ 
                                                     (((QData)((IData)(
                                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                       << 0x38U) 
                                                      | (((QData)((IData)(
                                                                          vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                          << 0x18U) 
                                                         | ((QData)((IData)(
                                                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                                            >> 8U)))))))) 
                                       | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U] 
                                          >> 0x11U))
                                    : ((3ULL > (0xffffffffffULL 
                                                & ((~ 
                                                    (1ULL 
                                                     | (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_pc))) 
                                                   - 
                                                   (~ 
                                                    (1ULL 
                                                     | (~ 
                                                        (((QData)((IData)(
                                                                          vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                          << 0x38U) 
                                                         | (((QData)((IData)(
                                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                             << 0x18U) 
                                                            | ((QData)((IData)(
                                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                                               >> 8U))))))))) 
                                       | (((3ULL > 
                                            (0xffffffffffULL 
                                             & ((~ 
                                                 (1ULL 
                                                  | (~ 
                                                     (((QData)((IData)(
                                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                       << 0x38U) 
                                                      | (((QData)((IData)(
                                                                          vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                          << 0x18U) 
                                                         | ((QData)((IData)(
                                                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                                            >> 8U)))))) 
                                                - (~ 
                                                   (1ULL 
                                                    | (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_pc)))))) 
                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U] 
                                              >> 0x11U)) 
                                          & ((0xffffffffffULL 
                                              & (~ 
                                                 (1ULL 
                                                  | (~ 
                                                     (((QData)((IData)(
                                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                       << 0x38U) 
                                                      | (((QData)((IData)(
                                                                          vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                          << 0x18U) 
                                                         | ((QData)((IData)(
                                                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                                            >> 8U))))))) 
                                             != (0xffffffffffULL 
                                                 & (~ 
                                                    (3ULL 
                                                     | (~ 
                                                        (((QData)((IData)(
                                                                          vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                          << 0x38U) 
                                                         | (((QData)((IData)(
                                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U])) 
                                                             << 0x18U) 
                                                            | ((QData)((IData)(
                                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[1U])) 
                                                               >> 8U))))))))))))));
        bufp->chgQData(oldp+327,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__bjl_redirect_replay) 
                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__bjl_redirect_replay_continue))
                                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_bjl_npc
                                   : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_replay)
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_pc
                                       : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__predicted_npc))),40);
        bufp->chgBit(oldp+329,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_valid) 
                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_pc 
                                     == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__replay_pc_cfi)) 
                                 & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__bjl_use_target))) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_imem_if_check_completed)))));
        bufp->chgBit(oldp+330,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_valid) 
                                 & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_jal) 
                                     | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_jalr)) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_branch))) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_imem_checker_mode))));
        bufp->chgBit(oldp+331,((1U & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__commit_bank_ptr)
                                          ? ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__empty_spec)) 
                                             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__has_enq_1))
                                          : ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__empty_spec)) 
                                             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__has_enq)))))));
        bufp->chgBit(oldp+332,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__empty_spec)) 
                                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__has_enq)))));
        bufp->chgBit(oldp+333,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__empty_spec)) 
                                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__has_enq_1)))));
        bufp->chgBit(oldp+334,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__reserve_fire) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__spec_bank_ptr)))));
        bufp->chgBit(oldp+335,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__commit_fire) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__commit_bank_ptr)))));
        bufp->chgBit(oldp+336,(((~ ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__spec_bank_ptr)) 
                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__spec_bank_ptr) 
                                       - (IData)(1U)))) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__BJL__io_bj_s2_replay))));
        if (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__empty_spec) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__do_enq))) {
            __Vtemp_h912d543e__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT____Vcellinp__u_channel_bj_0__io_enq_bits[0U];
            __Vtemp_h912d543e__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT____Vcellinp__u_channel_bj_0__io_enq_bits[1U];
            __Vtemp_h912d543e__0[2U] = (0x3ffffU & 
                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT____Vcellinp__u_channel_bj_0__io_enq_bits[2U]);
        } else if ((0x51ffU >= (0x7fffU & ((IData)(0x52U) 
                                           * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr))))) {
            __Vtemp_h912d543e__0[0U] = (((0U == (0x1fU 
                                                 & ((IData)(0x52U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr))))
                                          ? 0U : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT___GEN[
                                                  ((IData)(1U) 
                                                   + 
                                                   (0x3ffU 
                                                    & (((IData)(0x52U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)) 
                                                       >> 5U)))] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x52U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)))))) 
                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT___GEN[
                                           (0x3ffU 
                                            & (((IData)(0x52U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)) 
                                               >> 5U))] 
                                           >> (0x1fU 
                                               & ((IData)(0x52U) 
                                                  * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)))));
            __Vtemp_h912d543e__0[1U] = (((0U == (0x1fU 
                                                 & ((IData)(0x52U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr))))
                                          ? 0U : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT___GEN[
                                                  ((IData)(2U) 
                                                   + 
                                                   (0x3ffU 
                                                    & (((IData)(0x52U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)) 
                                                       >> 5U)))] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x52U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)))))) 
                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT___GEN[
                                           ((IData)(1U) 
                                            + (0x3ffU 
                                               & (((IData)(0x52U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)) 
                                                  >> 5U)))] 
                                           >> (0x1fU 
                                               & ((IData)(0x52U) 
                                                  * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)))));
            __Vtemp_h912d543e__0[2U] = (0x3ffffU & 
                                        (((0U == (0x1fU 
                                                  & ((IData)(0x52U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr))))
                                           ? 0U : (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT___GEN[
                                                   ((IData)(3U) 
                                                    + 
                                                    (0x3ffU 
                                                     & (((IData)(0x52U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)) 
                                                        >> 5U)))] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(0x52U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)))))) 
                                         | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT___GEN[
                                            ((IData)(2U) 
                                             + (0x3ffU 
                                                & (((IData)(0x52U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)) 
                                                   >> 5U)))] 
                                            >> (0x1fU 
                                                & ((IData)(0x52U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr))))));
        } else {
            __Vtemp_h912d543e__0[0U] = 0U;
            __Vtemp_h912d543e__0[1U] = 0U;
            __Vtemp_h912d543e__0[2U] = (0x3ffffU & 0U);
        }
        bufp->chgWData(oldp+337,(__Vtemp_h912d543e__0),82);
        bufp->chgBit(oldp+340,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__reserve_fire) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__spec_bank_ptr))));
        bufp->chgBit(oldp+341,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__commit_fire) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__commit_bank_ptr))));
        bufp->chgBit(oldp+342,((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__spec_bank_ptr)) 
                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__spec_bank_ptr) 
                                    - (IData)(1U))) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__BJL__io_bj_s2_replay))));
        if (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__empty_spec) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__do_enq))) {
            __Vtemp_h4dc51b7d__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT____Vcellinp__u_channel_bj_1__io_enq_bits[0U];
            __Vtemp_h4dc51b7d__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT____Vcellinp__u_channel_bj_1__io_enq_bits[1U];
            __Vtemp_h4dc51b7d__0[2U] = (0x3ffffU & 
                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT____Vcellinp__u_channel_bj_1__io_enq_bits[2U]);
        } else if ((0x51ffU >= (0x7fffU & ((IData)(0x52U) 
                                           * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr))))) {
            __Vtemp_h4dc51b7d__0[0U] = (((0U == (0x1fU 
                                                 & ((IData)(0x52U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr))))
                                          ? 0U : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT___GEN[
                                                  ((IData)(1U) 
                                                   + 
                                                   (0x3ffU 
                                                    & (((IData)(0x52U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)) 
                                                       >> 5U)))] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x52U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)))))) 
                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT___GEN[
                                           (0x3ffU 
                                            & (((IData)(0x52U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)) 
                                               >> 5U))] 
                                           >> (0x1fU 
                                               & ((IData)(0x52U) 
                                                  * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)))));
            __Vtemp_h4dc51b7d__0[1U] = (((0U == (0x1fU 
                                                 & ((IData)(0x52U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr))))
                                          ? 0U : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT___GEN[
                                                  ((IData)(2U) 
                                                   + 
                                                   (0x3ffU 
                                                    & (((IData)(0x52U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)) 
                                                       >> 5U)))] 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(0x52U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)))))) 
                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT___GEN[
                                           ((IData)(1U) 
                                            + (0x3ffU 
                                               & (((IData)(0x52U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)) 
                                                  >> 5U)))] 
                                           >> (0x1fU 
                                               & ((IData)(0x52U) 
                                                  * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)))));
            __Vtemp_h4dc51b7d__0[2U] = (0x3ffffU & 
                                        (((0U == (0x1fU 
                                                  & ((IData)(0x52U) 
                                                     * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr))))
                                           ? 0U : (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT___GEN[
                                                   ((IData)(3U) 
                                                    + 
                                                    (0x3ffU 
                                                     & (((IData)(0x52U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)) 
                                                        >> 5U)))] 
                                                   << 
                                                   ((IData)(0x20U) 
                                                    - 
                                                    (0x1fU 
                                                     & ((IData)(0x52U) 
                                                        * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)))))) 
                                         | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT___GEN[
                                            ((IData)(2U) 
                                             + (0x3ffU 
                                                & (((IData)(0x52U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)) 
                                                   >> 5U)))] 
                                            >> (0x1fU 
                                                & ((IData)(0x52U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr))))));
        } else {
            __Vtemp_h4dc51b7d__0[0U] = 0U;
            __Vtemp_h4dc51b7d__0[1U] = 0U;
            __Vtemp_h4dc51b7d__0[2U] = (0x3ffffU & 0U);
        }
        bufp->chgWData(oldp+343,(__Vtemp_h4dc51b7d__0),82);
        bufp->chgCData(oldp+346,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_imem_btb_update_valid)
                                   ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_btb_resp_entry)
                                   : 0x1cU)),5);
        bufp->chgQData(oldp+347,((0x7fffffffffULL & 
                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_imem_btb_update_valid)
                                    ? (~ (3ULL | (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_btb_update_bits_br_pc_output)))
                                    : (~ (3ULL | (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_pc)))))),39);
        bufp->chgBit(oldp+349,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_imem_btb_update_valid)) 
                                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_cfi)))));
        bufp->chgQData(oldp+350,((0x7fffffffffULL & 
                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_imem_btb_update_valid)
                                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_btb_update_bits_br_pc_output
                                    : ((~ (3ULL | (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_pc))) 
                                       | ((QData)((IData)(
                                                          (1U 
                                                           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__taken))))) 
                                          << 1U))))),39);
        bufp->chgCData(oldp+352,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_imem_btb_update_valid)
                                   ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_btb_update_bits_cfiType_T_9) 
                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                          >> 7U)) ? 2U
                                       : (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_jalr) 
                                           & (1U == 
                                              ((0xcU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                   >> 0x10U)) 
                                               | (3U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                     >> 0xfU)))))
                                           ? 3U : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_btb_update_bits_cfiType_T_9)))
                                   : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___GEN))),2);
        bufp->chgBit(oldp+353,((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__taken)) 
                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_88) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_89)))
                                 ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_116) 
                                    & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__wrong_path)))
                                 : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_55) 
                                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_56)) 
                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_116)) 
                                    & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__wrong_path))))));
        bufp->chgSData(oldp+354,((0x1ffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT___GEN_5)
                                             ? (((~ (IData)(
                                                            (0x1fffffffffULL 
                                                             & ((~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_btb_update_bits_br_pc_output) 
                                                                >> 2U)))) 
                                                 ^ 
                                                 (3U 
                                                  & (~ (IData)(
                                                               (0xfffffffULL 
                                                                & ((~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_btb_update_bits_br_pc_output) 
                                                                   >> 0xbU)))))) 
                                                ^ (0x1c0U 
                                                   & (((IData)(0xddU) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_btb_resp_bht_history)) 
                                                      << 1U)))
                                             : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT__reset_waddr)))),9);
        bufp->chgBit(oldp+355,((1U & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__btb__io_bht_update_valid) 
                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_branch)) 
                                      | (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT__reset_waddr) 
                                            >> 9U))))));
        bufp->chgBit(oldp+356,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT___GEN_5) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_br_taken))));
        bufp->chgBit(oldp+357,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_redirect) 
                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___tlb_io_resp_miss)) 
                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_replay))));
    }
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[0x10U] 
                     | vlSelf->__Vm_traceActivity[0x40U]))) {
        bufp->chgBit(oldp+358,(((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                    >> 0xaU)) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_b_ready))));
        bufp->chgBit(oldp+359,(((~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__checker_mode_1cycle_delay)) 
                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode) 
                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__checker_priv_mode_1cycle_delay)))) 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_req_kill_T_3) 
                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__fpu_kill_mem)))));
        bufp->chgBit(oldp+360,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT___io_st_deq_T) 
                                & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl_req_cmd)))));
        bufp->chgBit(oldp+361,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT___io_st_deq_T) 
                                & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl_req_cmd)))));
        bufp->chgBit(oldp+362,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT___io_requestor_1_req_ready_output))));
        bufp->chgBit(oldp+363,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_valid) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_mem_s1_kill)))));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x11U])) {
        bufp->chgBit(oldp+364,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_tileClockGroup_tile_3_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+365,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_tileClockGroup_tile_3_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+366,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_tileClockGroup_tile_3_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_2));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x12U])) {
        bufp->chgBit(oldp+367,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+368,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+369,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+370,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+371,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+372,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+373,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+374,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+375,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+376,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+377,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+378,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+379,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+380,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_d_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+381,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+382,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+383,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_a_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+384,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+385,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+386,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_c_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+387,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+388,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+389,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__x1_e_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x13U])) {
        bufp->chgBit(oldp+390,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT___io_deq_valid_output));
        bufp->chgCData(oldp+391,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__ridx_ridx_bin),4);
        bufp->chgCData(oldp+392,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__ridx_incremented),4);
        bufp->chgBit(oldp+393,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__valid_reg));
        bufp->chgBit(oldp+394,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+395,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgCData(oldp+396,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0) 
                                   << 3U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0) 
                                              << 2U) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                 << 1U) 
                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0))))),4);
        bufp->chgBit(oldp+397,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+398,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+399,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0));
        bufp->chgBit(oldp+400,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1));
        bufp->chgBit(oldp+401,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0));
        bufp->chgBit(oldp+402,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1));
        bufp->chgBit(oldp+403,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0));
        bufp->chgBit(oldp+404,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1));
        bufp->chgBit(oldp+405,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT___io_deq_valid_output));
        bufp->chgCData(oldp+406,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__ridx_ridx_bin),7);
        bufp->chgCData(oldp+407,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__ridx_incremented),7);
        bufp->chgBit(oldp+408,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__valid_reg));
        bufp->chgBit(oldp+409,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+410,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgCData(oldp+411,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_6__DOT__sync_0) 
                                   << 6U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_5__DOT__sync_0) 
                                              << 5U) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_4__DOT__sync_0) 
                                                 << 4U) 
                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0)))))))),7);
        bufp->chgBit(oldp+412,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+413,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+414,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0));
        bufp->chgBit(oldp+415,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1));
        bufp->chgBit(oldp+416,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0));
        bufp->chgBit(oldp+417,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1));
        bufp->chgBit(oldp+418,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0));
        bufp->chgBit(oldp+419,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1));
        bufp->chgBit(oldp+420,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_4__DOT__sync_0));
        bufp->chgBit(oldp+421,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_4__DOT__sync_1));
        bufp->chgBit(oldp+422,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_5__DOT__sync_0));
        bufp->chgBit(oldp+423,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_5__DOT__sync_1));
        bufp->chgBit(oldp+424,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_6__DOT__sync_0));
        bufp->chgBit(oldp+425,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_6__DOT__sync_1));
        bufp->chgBit(oldp+426,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT___io_deq_valid_output));
        bufp->chgSData(oldp+427,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__ridx_ridx_bin),9);
        bufp->chgBit(oldp+428,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__valid_reg));
        bufp->chgBit(oldp+429,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+430,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__source_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgSData(oldp+431,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_8__DOT__sync_0) 
                                   << 8U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_7__DOT__sync_0) 
                                              << 7U) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_6__DOT__sync_0) 
                                                 << 6U) 
                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_5__DOT__sync_0) 
                                                    << 5U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_4__DOT__sync_0) 
                                                       << 4U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0) 
                                                          << 3U) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0) 
                                                             << 2U) 
                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                                << 1U) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0)))))))))),9);
        bufp->chgBit(oldp+432,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+433,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+434,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0));
        bufp->chgBit(oldp+435,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1));
        bufp->chgBit(oldp+436,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0));
        bufp->chgBit(oldp+437,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1));
        bufp->chgBit(oldp+438,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0));
        bufp->chgBit(oldp+439,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1));
        bufp->chgBit(oldp+440,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_4__DOT__sync_0));
        bufp->chgBit(oldp+441,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_4__DOT__sync_1));
        bufp->chgBit(oldp+442,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_5__DOT__sync_0));
        bufp->chgBit(oldp+443,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_5__DOT__sync_1));
        bufp->chgBit(oldp+444,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_6__DOT__sync_0));
        bufp->chgBit(oldp+445,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_6__DOT__sync_1));
        bufp->chgBit(oldp+446,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_7__DOT__sync_0));
        bufp->chgBit(oldp+447,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_7__DOT__sync_1));
        bufp->chgBit(oldp+448,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_8__DOT__sync_0));
        bufp->chgBit(oldp+449,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__widx_widx_gray__DOT__output_chain_8__DOT__sync_1));
        bufp->chgBit(oldp+450,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__ready_reg) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0))));
        bufp->chgCData(oldp+451,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__widx_widx_bin),7);
        bufp->chgBit(oldp+452,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__ready_reg));
        bufp->chgCData(oldp+453,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_6__DOT__sync_0) 
                                   << 6U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_5__DOT__sync_0) 
                                              << 5U) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_4__DOT__sync_0) 
                                                 << 4U) 
                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0) 
                                                    << 3U) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0) 
                                                       << 2U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                          << 1U) 
                                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0)))))))),7);
        bufp->chgBit(oldp+454,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+455,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+456,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0));
        bufp->chgBit(oldp+457,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1));
        bufp->chgBit(oldp+458,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0));
        bufp->chgBit(oldp+459,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1));
        bufp->chgBit(oldp+460,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0));
        bufp->chgBit(oldp+461,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1));
        bufp->chgBit(oldp+462,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_4__DOT__sync_0));
        bufp->chgBit(oldp+463,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_4__DOT__sync_1));
        bufp->chgBit(oldp+464,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_5__DOT__sync_0));
        bufp->chgBit(oldp+465,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_5__DOT__sync_1));
        bufp->chgBit(oldp+466,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_6__DOT__sync_0));
        bufp->chgBit(oldp+467,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__ridx_ridx_gray__DOT__output_chain_6__DOT__sync_1));
        bufp->chgBit(oldp+468,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+469,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__sink_valid__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+470,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsource_1__DOT__reg_0__DOT__reg_0));
        bufp->chgBit(oldp+471,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsource_2__DOT__reg_0__DOT__reg_0));
        bufp->chgBit(oldp+472,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsource_3__DOT__reg_0__DOT__reg_0));
        bufp->chgCData(oldp+473,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx_ridx_bin),4);
        bufp->chgBit(oldp+474,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__valid_reg));
        bufp->chgBit(oldp+475,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__source_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+476,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__source_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+477,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__source_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgCData(oldp+478,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0) 
                                   << 3U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0) 
                                              << 2U) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                 << 1U) 
                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0))))),4);
        bufp->chgBit(oldp+479,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+480,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+481,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+482,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0));
        bufp->chgBit(oldp+483,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1));
        bufp->chgBit(oldp+484,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2));
        bufp->chgBit(oldp+485,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0));
        bufp->chgBit(oldp+486,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1));
        bufp->chgBit(oldp+487,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2));
        bufp->chgBit(oldp+488,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0));
        bufp->chgBit(oldp+489,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1));
        bufp->chgBit(oldp+490,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2));
        bufp->chgCData(oldp+491,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__ridx_ridx_bin),4);
        bufp->chgBit(oldp+492,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__valid_reg));
        bufp->chgBit(oldp+493,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__source_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+494,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__source_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+495,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__source_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgCData(oldp+496,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0) 
                                   << 3U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0) 
                                              << 2U) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                 << 1U) 
                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0))))),4);
        bufp->chgBit(oldp+497,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+498,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+499,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+500,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0));
        bufp->chgBit(oldp+501,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_1));
        bufp->chgBit(oldp+502,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_2));
        bufp->chgBit(oldp+503,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0));
        bufp->chgBit(oldp+504,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_1));
        bufp->chgBit(oldp+505,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_2));
        bufp->chgBit(oldp+506,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0));
        bufp->chgBit(oldp+507,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_1));
        bufp->chgBit(oldp+508,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_2));
        bufp->chgCData(oldp+509,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__widx_widx_bin),4);
        bufp->chgBit(oldp+510,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__ready_reg));
        bufp->chgCData(oldp+511,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0) 
                                   << 3U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0) 
                                              << 2U) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                 << 1U) 
                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0))))),4);
        bufp->chgBit(oldp+512,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+513,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+514,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+515,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0));
        bufp->chgBit(oldp+516,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1));
        bufp->chgBit(oldp+517,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2));
        bufp->chgBit(oldp+518,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0));
        bufp->chgBit(oldp+519,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1));
        bufp->chgBit(oldp+520,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2));
        bufp->chgBit(oldp+521,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0));
        bufp->chgBit(oldp+522,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1));
        bufp->chgBit(oldp+523,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2));
        bufp->chgBit(oldp+524,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__sink_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+525,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__sink_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+526,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__sink_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgCData(oldp+527,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__widx_widx_bin),4);
        bufp->chgBit(oldp+528,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__ready_reg));
        bufp->chgCData(oldp+529,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0) 
                                   << 3U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0) 
                                              << 2U) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                 << 1U) 
                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0))))),4);
        bufp->chgBit(oldp+530,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+531,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+532,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+533,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0));
        bufp->chgBit(oldp+534,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1));
        bufp->chgBit(oldp+535,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2));
        bufp->chgBit(oldp+536,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0));
        bufp->chgBit(oldp+537,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1));
        bufp->chgBit(oldp+538,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2));
        bufp->chgBit(oldp+539,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0));
        bufp->chgBit(oldp+540,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1));
        bufp->chgBit(oldp+541,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2));
        bufp->chgBit(oldp+542,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__sink_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+543,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__sink_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+544,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__sink_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
        bufp->chgCData(oldp+545,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__widx_widx_bin),4);
        bufp->chgBit(oldp+546,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__ready_reg));
        bufp->chgCData(oldp+547,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0) 
                                   << 3U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0) 
                                              << 2U) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0) 
                                                 << 1U) 
                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0))))),4);
        bufp->chgBit(oldp+548,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+549,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+550,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__ridx_ridx_gray__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+551,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_0));
        bufp->chgBit(oldp+552,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_1));
        bufp->chgBit(oldp+553,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__ridx_ridx_gray__DOT__output_chain_1__DOT__sync_2));
        bufp->chgBit(oldp+554,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_0));
        bufp->chgBit(oldp+555,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_1));
        bufp->chgBit(oldp+556,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__ridx_ridx_gray__DOT__output_chain_2__DOT__sync_2));
        bufp->chgBit(oldp+557,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_0));
        bufp->chgBit(oldp+558,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_1));
        bufp->chgBit(oldp+559,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__ridx_ridx_gray__DOT__output_chain_3__DOT__sync_2));
        bufp->chgBit(oldp+560,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__sink_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+561,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__sink_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+562,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__sink_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0x14U])) {
        bufp->chgBit(oldp+563,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_data_cdc_ready_3));
        bufp->chgCData(oldp+564,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_l_wctrl_3),8);
        bufp->chgWData(oldp+565,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg),145);
        bufp->chgIData(oldp+570,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg),22);
        bufp->chgWData(oldp+571,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg),272);
        bufp->chgBit(oldp+580,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__io_clear_ic_status_REG) 
                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_4_auto_tile_reset_domain_tile_ghe_revent_out_sr_out)) 
                                | (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_4_auto_tile_reset_domain_tile_ghe_event_out_sr_out)))));
        bufp->chgSData(oldp+581,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_l_wctrl_3),9);
        bufp->chgSData(oldp+582,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_0),9);
        bufp->chgSData(oldp+583,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_1),9);
        bufp->chgSData(oldp+584,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_2),9);
        bufp->chgSData(oldp+585,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_3),9);
        bufp->chgSData(oldp+586,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_4),9);
        bufp->chgSData(oldp+587,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_5),9);
        bufp->chgSData(oldp+588,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_6),9);
        bufp->chgSData(oldp+589,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_7),9);
        bufp->chgSData(oldp+590,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_8),9);
        bufp->chgSData(oldp+591,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_9),9);
        bufp->chgSData(oldp+592,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_10),9);
        bufp->chgSData(oldp+593,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_11),9);
        bufp->chgSData(oldp+594,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_12),9);
        bufp->chgSData(oldp+595,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_13),9);
        bufp->chgSData(oldp+596,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_14),9);
        bufp->chgSData(oldp+597,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_15),9);
        bufp->chgSData(oldp+598,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_16),9);
        bufp->chgSData(oldp+599,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_17),9);
        bufp->chgSData(oldp+600,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_18),9);
        bufp->chgSData(oldp+601,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_19),9);
        bufp->chgSData(oldp+602,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_20),9);
        bufp->chgSData(oldp+603,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_21),9);
        bufp->chgSData(oldp+604,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_22),9);
        bufp->chgSData(oldp+605,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_23),9);
        bufp->chgSData(oldp+606,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_24),9);
        bufp->chgSData(oldp+607,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_25),9);
        bufp->chgSData(oldp+608,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_26),9);
        bufp->chgSData(oldp+609,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_27),9);
        bufp->chgSData(oldp+610,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_28),9);
        bufp->chgSData(oldp+611,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_29),9);
        bufp->chgSData(oldp+612,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_30),9);
        bufp->chgSData(oldp+613,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_31),9);
        bufp->chgSData(oldp+614,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_32),9);
        bufp->chgSData(oldp+615,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_33),9);
        bufp->chgSData(oldp+616,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_34),9);
        bufp->chgSData(oldp+617,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_35),9);
        bufp->chgSData(oldp+618,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_36),9);
        bufp->chgSData(oldp+619,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_37),9);
        bufp->chgSData(oldp+620,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_38),9);
        bufp->chgSData(oldp+621,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_39),9);
        bufp->chgSData(oldp+622,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_40),9);
        bufp->chgSData(oldp+623,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_41),9);
        bufp->chgSData(oldp+624,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_42),9);
        bufp->chgSData(oldp+625,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_43),9);
        bufp->chgSData(oldp+626,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_44),9);
        bufp->chgSData(oldp+627,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_45),9);
        bufp->chgSData(oldp+628,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_46),9);
        bufp->chgSData(oldp+629,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_47),9);
        bufp->chgSData(oldp+630,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_48),9);
        bufp->chgSData(oldp+631,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_49),9);
        bufp->chgSData(oldp+632,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_50),9);
        bufp->chgSData(oldp+633,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_51),9);
        bufp->chgSData(oldp+634,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_52),9);
        bufp->chgSData(oldp+635,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_53),9);
        bufp->chgSData(oldp+636,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_54),9);
        bufp->chgSData(oldp+637,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_55),9);
        bufp->chgSData(oldp+638,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_56),9);
        bufp->chgSData(oldp+639,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_57),9);
        bufp->chgSData(oldp+640,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_58),9);
        bufp->chgSData(oldp+641,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_59),9);
        bufp->chgSData(oldp+642,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_60),9);
        bufp->chgSData(oldp+643,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_61),9);
        bufp->chgSData(oldp+644,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_62),9);
        bufp->chgSData(oldp+645,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__mem_63),9);
        bufp->chgCData(oldp+646,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_0_opcode),3);
        bufp->chgCData(oldp+647,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_0_param),3);
        bufp->chgCData(oldp+648,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_0_size),4);
        bufp->chgCData(oldp+649,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_0_source),2);
        bufp->chgIData(oldp+650,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_0_address),32);
        bufp->chgCData(oldp+651,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_0_mask),8);
        bufp->chgQData(oldp+652,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_0_data),64);
        bufp->chgBit(oldp+654,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_0_corrupt));
        bufp->chgCData(oldp+655,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_1_opcode),3);
        bufp->chgCData(oldp+656,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_1_param),3);
        bufp->chgCData(oldp+657,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_1_size),4);
        bufp->chgCData(oldp+658,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_1_source),2);
        bufp->chgIData(oldp+659,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_1_address),32);
        bufp->chgCData(oldp+660,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_1_mask),8);
        bufp->chgQData(oldp+661,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_1_data),64);
        bufp->chgBit(oldp+663,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_1_corrupt));
        bufp->chgCData(oldp+664,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_2_opcode),3);
        bufp->chgCData(oldp+665,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_2_param),3);
        bufp->chgCData(oldp+666,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_2_size),4);
        bufp->chgCData(oldp+667,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_2_source),2);
        bufp->chgIData(oldp+668,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_2_address),32);
        bufp->chgCData(oldp+669,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_2_mask),8);
        bufp->chgQData(oldp+670,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_2_data),64);
        bufp->chgBit(oldp+672,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_2_corrupt));
        bufp->chgCData(oldp+673,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_3_opcode),3);
        bufp->chgCData(oldp+674,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_3_param),3);
        bufp->chgCData(oldp+675,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_3_size),4);
        bufp->chgCData(oldp+676,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_3_source),2);
        bufp->chgIData(oldp+677,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_3_address),32);
        bufp->chgCData(oldp+678,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_3_mask),8);
        bufp->chgQData(oldp+679,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_3_data),64);
        bufp->chgBit(oldp+681,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_3_corrupt));
        bufp->chgCData(oldp+682,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_4_opcode),3);
        bufp->chgCData(oldp+683,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_4_param),3);
        bufp->chgCData(oldp+684,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_4_size),4);
        bufp->chgCData(oldp+685,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_4_source),2);
        bufp->chgIData(oldp+686,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_4_address),32);
        bufp->chgCData(oldp+687,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_4_mask),8);
        bufp->chgQData(oldp+688,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_4_data),64);
        bufp->chgBit(oldp+690,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_4_corrupt));
        bufp->chgCData(oldp+691,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_5_opcode),3);
        bufp->chgCData(oldp+692,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_5_param),3);
        bufp->chgCData(oldp+693,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_5_size),4);
        bufp->chgCData(oldp+694,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_5_source),2);
        bufp->chgIData(oldp+695,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_5_address),32);
        bufp->chgCData(oldp+696,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_5_mask),8);
        bufp->chgQData(oldp+697,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_5_data),64);
        bufp->chgBit(oldp+699,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_5_corrupt));
        bufp->chgCData(oldp+700,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_6_opcode),3);
        bufp->chgCData(oldp+701,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_6_param),3);
        bufp->chgCData(oldp+702,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_6_size),4);
        bufp->chgCData(oldp+703,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_6_source),2);
        bufp->chgIData(oldp+704,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_6_address),32);
        bufp->chgCData(oldp+705,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_6_mask),8);
        bufp->chgQData(oldp+706,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_6_data),64);
        bufp->chgBit(oldp+708,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_6_corrupt));
        bufp->chgCData(oldp+709,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_7_opcode),3);
        bufp->chgCData(oldp+710,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_7_param),3);
        bufp->chgCData(oldp+711,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_7_size),4);
        bufp->chgCData(oldp+712,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_7_source),2);
        bufp->chgIData(oldp+713,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_7_address),32);
        bufp->chgCData(oldp+714,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_7_mask),8);
        bufp->chgQData(oldp+715,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_7_data),64);
        bufp->chgBit(oldp+717,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__mem_7_corrupt));
        bufp->chgCData(oldp+718,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_0_opcode),3);
        bufp->chgCData(oldp+719,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_0_param),3);
        bufp->chgCData(oldp+720,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_0_size),4);
        bufp->chgCData(oldp+721,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_0_source),2);
        bufp->chgIData(oldp+722,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_0_address),32);
        bufp->chgQData(oldp+723,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_0_data),64);
        bufp->chgBit(oldp+725,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_0_corrupt));
        bufp->chgCData(oldp+726,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_1_opcode),3);
        bufp->chgCData(oldp+727,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_1_param),3);
        bufp->chgCData(oldp+728,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_1_size),4);
        bufp->chgCData(oldp+729,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_1_source),2);
        bufp->chgIData(oldp+730,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_1_address),32);
        bufp->chgQData(oldp+731,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_1_data),64);
        bufp->chgBit(oldp+733,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_1_corrupt));
        bufp->chgCData(oldp+734,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_2_opcode),3);
        bufp->chgCData(oldp+735,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_2_param),3);
        bufp->chgCData(oldp+736,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_2_size),4);
        bufp->chgCData(oldp+737,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_2_source),2);
        bufp->chgIData(oldp+738,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_2_address),32);
        bufp->chgQData(oldp+739,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_2_data),64);
        bufp->chgBit(oldp+741,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_2_corrupt));
        bufp->chgCData(oldp+742,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_3_opcode),3);
        bufp->chgCData(oldp+743,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_3_param),3);
        bufp->chgCData(oldp+744,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_3_size),4);
        bufp->chgCData(oldp+745,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_3_source),2);
        bufp->chgIData(oldp+746,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_3_address),32);
        bufp->chgQData(oldp+747,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_3_data),64);
        bufp->chgBit(oldp+749,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_3_corrupt));
        bufp->chgCData(oldp+750,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_4_opcode),3);
        bufp->chgCData(oldp+751,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_4_param),3);
        bufp->chgCData(oldp+752,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_4_size),4);
        bufp->chgCData(oldp+753,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_4_source),2);
        bufp->chgIData(oldp+754,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_4_address),32);
        bufp->chgQData(oldp+755,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_4_data),64);
        bufp->chgBit(oldp+757,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_4_corrupt));
        bufp->chgCData(oldp+758,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_5_opcode),3);
        bufp->chgCData(oldp+759,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_5_param),3);
        bufp->chgCData(oldp+760,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_5_size),4);
        bufp->chgCData(oldp+761,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_5_source),2);
        bufp->chgIData(oldp+762,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_5_address),32);
        bufp->chgQData(oldp+763,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_5_data),64);
        bufp->chgBit(oldp+765,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_5_corrupt));
        bufp->chgCData(oldp+766,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_6_opcode),3);
        bufp->chgCData(oldp+767,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_6_param),3);
        bufp->chgCData(oldp+768,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_6_size),4);
        bufp->chgCData(oldp+769,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_6_source),2);
        bufp->chgIData(oldp+770,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_6_address),32);
        bufp->chgQData(oldp+771,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_6_data),64);
        bufp->chgBit(oldp+773,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_6_corrupt));
        bufp->chgCData(oldp+774,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_7_opcode),3);
        bufp->chgCData(oldp+775,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_7_param),3);
        bufp->chgCData(oldp+776,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_7_size),4);
        bufp->chgCData(oldp+777,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_7_source),2);
        bufp->chgIData(oldp+778,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_7_address),32);
        bufp->chgQData(oldp+779,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_7_data),64);
        bufp->chgBit(oldp+781,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__mem_7_corrupt));
        bufp->chgBit(oldp+782,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_4_auto_tile_reset_domain_tile_ghe_revent_out_sr_out));
        bufp->chgCData(oldp+783,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_4_auto_tile_reset_domain_tile_ghe_event_out_sr_out),6);
        bufp->chgBit(oldp+784,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__io_clear_ic_status_REG));
        bufp->chgBit(oldp+785,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__x1_out_1_valid));
        bufp->chgCData(oldp+786,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_opcode),3);
        bufp->chgCData(oldp+787,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_param),3);
        bufp->chgCData(oldp+788,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_size),4);
        bufp->chgCData(oldp+789,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_source),2);
        bufp->chgIData(oldp+790,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_address),32);
        bufp->chgCData(oldp+791,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_mask),8);
        bufp->chgQData(oldp+792,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_data),64);
        bufp->chgBit(oldp+794,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_valid));
        bufp->chgCData(oldp+795,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_opcode),3);
        bufp->chgCData(oldp+796,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_c_bits_param),3);
        bufp->chgCData(oldp+797,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_size),4);
        bufp->chgCData(oldp+798,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_source),2);
        bufp->chgIData(oldp+799,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_address),32);
        bufp->chgQData(oldp+800,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_data),64);
        bufp->chgCData(oldp+802,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                        >> 0x11U))),3);
        bufp->chgCData(oldp+803,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                        >> 0xfU))),2);
        bufp->chgCData(oldp+804,((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                          >> 0xbU))),4);
        bufp->chgCData(oldp+805,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                        >> 9U))),2);
        bufp->chgIData(oldp+806,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                   << 0x17U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                >> 9U))),32);
        bufp->chgCData(oldp+807,((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                           >> 1U))),8);
        bufp->chgBit(oldp+808,((1U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])));
        bufp->chgWData(oldp+809,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg),116);
        bufp->chgSData(oldp+813,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__a_first_counter),9);
        bufp->chgCData(oldp+814,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__opcode),3);
        bufp->chgCData(oldp+815,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__param),3);
        bufp->chgCData(oldp+816,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__size),4);
        bufp->chgCData(oldp+817,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__source),2);
        bufp->chgIData(oldp+818,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__address),32);
        bufp->chgSData(oldp+819,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__d_first_counter),9);
        bufp->chgCData(oldp+820,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__opcode_1),3);
        bufp->chgCData(oldp+821,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__param_1),2);
        bufp->chgCData(oldp+822,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__size_1),4);
        bufp->chgCData(oldp+823,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__source_1),2);
        bufp->chgCData(oldp+824,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__sink),3);
        bufp->chgBit(oldp+825,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__denied));
        bufp->chgSData(oldp+826,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__c_first_counter),9);
        bufp->chgCData(oldp+827,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__opcode_3),3);
        bufp->chgCData(oldp+828,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__param_3),3);
        bufp->chgCData(oldp+829,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__size_3),4);
        bufp->chgCData(oldp+830,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__source_3),2);
        bufp->chgIData(oldp+831,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__address_2),32);
        bufp->chgCData(oldp+832,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__inflight),3);
        bufp->chgSData(oldp+833,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__inflight_opcodes),12);
        bufp->chgIData(oldp+834,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__inflight_sizes),24);
        bufp->chgSData(oldp+835,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__a_first_counter_1),9);
        bufp->chgBit(oldp+836,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__a_first_counter_1))));
        bufp->chgSData(oldp+837,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__d_first_counter_1),9);
        bufp->chgBit(oldp+838,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__d_first_counter_1))));
        bufp->chgIData(oldp+839,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__watchdog),32);
        bufp->chgCData(oldp+840,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__inflight_1),3);
        bufp->chgIData(oldp+841,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__inflight_sizes_1),24);
        bufp->chgSData(oldp+842,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__c_first_counter_1),9);
        bufp->chgBit(oldp+843,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__c_first_counter_1))));
        bufp->chgSData(oldp+844,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__d_first_counter_2),9);
        bufp->chgBit(oldp+845,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__d_first_counter_2))));
        bufp->chgIData(oldp+846,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__watchdog_1),32);
        bufp->chgCData(oldp+847,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__inflight_2),8);
        bufp->chgSData(oldp+848,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__d_first_counter_3),9);
        bufp->chgBit(oldp+849,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__d_first_counter_3))));
        bufp->chgBit(oldp+850,((((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_source)) 
                                 | (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_source))) 
                                | (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_source)))));
        bufp->chgBit(oldp+851,((2U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_size)))));
        bufp->chgBit(oldp+852,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc));
        bufp->chgBit(oldp+853,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_1));
        bufp->chgBit(oldp+854,((1U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_size)))));
        bufp->chgBit(oldp+855,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_eq_2));
        bufp->chgBit(oldp+856,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_2));
        bufp->chgBit(oldp+857,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_eq_3));
        bufp->chgBit(oldp+858,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_3));
        bufp->chgBit(oldp+859,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_eq_4));
        bufp->chgBit(oldp+860,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_4));
        bufp->chgBit(oldp+861,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_eq_5));
        bufp->chgBit(oldp+862,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_5));
        bufp->chgCData(oldp+863,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_5) 
                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_eq_5) 
                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_address)) 
                                   << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_5) 
                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_eq_5) 
                                                  & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_address))) 
                                              << 6U) 
                                             | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_4) 
                                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_eq_4) 
                                                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_address)) 
                                                 << 5U) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_4) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_eq_4) 
                                                        & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_address))) 
                                                    << 4U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_3) 
                                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_eq_3) 
                                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_address)) 
                                                       << 3U) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_3) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_eq_3) 
                                                              & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_address))) 
                                                          << 2U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_2) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_eq_2) 
                                                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_address)) 
                                                             << 1U) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_2) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_eq_2) 
                                                                  & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_address))))))))))),8);
        bufp->chgBit(oldp+864,((((((((((((((3U == (0xfffffU 
                                                   & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                       << 0xbU) 
                                                      | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                         >> 0x15U)))) 
                                           | (0x2010U 
                                              == (0xfffffU 
                                                  & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                      << 0xbU) 
                                                     | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                        >> 0x15U))))) 
                                          | (4U == 
                                             (0xfffffU 
                                              & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                  << 0xbU) 
                                                 | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                    >> 0x15U))))) 
                                         | (0x54000U 
                                            == (0xfffffU 
                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 0xbU) 
                                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                      >> 0x15U))))) 
                                        | (3U == (0x3fU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                     >> 3U)))) 
                                       | (0x200U == 
                                          (0xffffU 
                                           & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                               << 7U) 
                                              | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                 >> 0x19U))))) 
                                      | (0U == (0xfffffU 
                                                & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                    << 0xbU) 
                                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                      >> 0x15U))))) 
                                     | (1U == (0xffffU 
                                               & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                   << 7U) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                     >> 0x19U))))) 
                                    | (0x100U == (0xfffffU 
                                                  & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                      << 0xbU) 
                                                     | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                        >> 0x15U))))) 
                                   | (0x110U == (0xfffffU 
                                                 & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                     << 0xbU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                       >> 0x15U))))) 
                                  | (8U == (0xfU & 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                             >> 5U)))) 
                                 | (0x10000U == (0xfffffU 
                                                 & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                                     << 0xbU) 
                                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                       >> 0x15U))))) 
                                | (2U == (0xffffU & 
                                          ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                            << 7U) 
                                           | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                              >> 0x19U)))))));
        bufp->chgBit(oldp+865,((2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                             >> 0xbU)))));
        bufp->chgBit(oldp+866,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_14));
        bufp->chgBit(oldp+867,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_15));
        bufp->chgBit(oldp+868,((1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                             >> 0xbU)))));
        bufp->chgBit(oldp+869,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_eq_16));
        bufp->chgBit(oldp+870,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_16));
        bufp->chgBit(oldp+871,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_eq_17));
        bufp->chgBit(oldp+872,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_17));
        bufp->chgBit(oldp+873,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_eq_18));
        bufp->chgBit(oldp+874,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_18));
        bufp->chgBit(oldp+875,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_eq_19));
        bufp->chgBit(oldp+876,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_19));
        bufp->chgCData(oldp+877,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_19) 
                                    << 7U) | (0x3fffff80U 
                                              & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_eq_19) 
                                                  << 7U) 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                    >> 2U)))) 
                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_19) 
                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_eq_19) 
                                          & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                >> 9U)))) 
                                      << 6U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_18) 
                                                  << 5U) 
                                                 | (0xfffffe0U 
                                                    & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_eq_18) 
                                                        << 5U) 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                          >> 4U)))) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_18) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_eq_18) 
                                                        & (~ 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                            >> 9U)))) 
                                                    << 4U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_17) 
                                                        << 3U) 
                                                       | (0x3fffff8U 
                                                          & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_eq_17) 
                                                              << 3U) 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                >> 6U)))) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_17) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_eq_17) 
                                                              & (~ 
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                  >> 9U)))) 
                                                          << 2U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_16) 
                                                              << 1U) 
                                                             | (0xfffffeU 
                                                                & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_eq_16) 
                                                                    << 1U) 
                                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                      >> 8U)))) 
                                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_acc_16) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT__mask_eq_16) 
                                                                  & (~ 
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                                      >> 9U)))))))))))),8);
        bufp->chgBit(oldp+878,(1U));
        bufp->chgBit(oldp+879,((((((((((((((3U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_address 
                                                   >> 0xcU)) 
                                           | (0x2010U 
                                              == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_address 
                                                  >> 0xcU))) 
                                          | (4U == 
                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_address 
                                              >> 0xcU))) 
                                         | (0x54000U 
                                            == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_address 
                                                >> 0xcU))) 
                                        | (3U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_address 
                                                  >> 0x1aU))) 
                                       | (0x200U == 
                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_address 
                                           >> 0x10U))) 
                                      | (0U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_address 
                                                >> 0xcU))) 
                                     | (1U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_address 
                                               >> 0x10U))) 
                                    | (0x100U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_address 
                                                  >> 0xcU))) 
                                   | (0x110U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_address 
                                                 >> 0xcU))) 
                                  | (8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_address 
                                            >> 0x1cU))) 
                                 | (0x10000U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_address 
                                                 >> 0xcU))) 
                                | (2U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_address 
                                          >> 0x10U)))));
        bufp->chgCData(oldp+880,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT___same_cycle_resp_T_1)
                                   ? (7U & ((IData)(1U) 
                                            << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT___tile_reset_domain_tile_auto_tl_other_masters_out_a_bits_source)))
                                   : 0U)),3);
        bufp->chgCData(oldp+881,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__monitor__DOT___same_cycle_resp_T_3) 
                                   & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_opcode))))
                                   ? (7U & ((IData)(1U) 
                                            << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_source)))
                                   : 0U)),3);
        bufp->chgBit(oldp+882,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink__DOT__chain__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+883,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink__DOT__chain__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+884,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink__DOT__chain__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+885,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink_1__DOT___chain_io_q))));
        bufp->chgBit(oldp+886,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink_1__DOT___chain_io_q) 
                                      >> 1U))));
        bufp->chgCData(oldp+887,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink_1__DOT___chain_io_q),2);
        bufp->chgBit(oldp+888,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink_1__DOT__chain__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+889,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink_1__DOT__chain__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+890,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink_1__DOT__chain__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+891,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink_1__DOT__chain__DOT__output_chain_1__DOT__sync_0));
        bufp->chgBit(oldp+892,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink_1__DOT__chain__DOT__output_chain_1__DOT__sync_1));
        bufp->chgBit(oldp+893,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink_1__DOT__chain__DOT__output_chain_1__DOT__sync_2));
        bufp->chgBit(oldp+894,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink_2__DOT__chain__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+895,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink_2__DOT__chain__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+896,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink_2__DOT__chain__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+897,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink_3__DOT__chain__DOT__output_chain__DOT__sync_0));
        bufp->chgBit(oldp+898,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink_3__DOT__chain__DOT__output_chain__DOT__sync_1));
        bufp->chgBit(oldp+899,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink_3__DOT__chain__DOT__output_chain__DOT__sync_2));
        bufp->chgBit(oldp+900,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__x1_0_REG));
        bufp->chgCData(oldp+901,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_s_or_r),2);
        bufp->chgQData(oldp+902,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_rd_val),64);
        bufp->chgBit(oldp+904,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                & ((((0x40U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                >> 0x19U)) 
                                     | (0x41U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                  >> 0x19U))) 
                                    | (0x42U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                 >> 0x19U))) 
                                   | (0x43U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                >> 0x19U))))));
        bufp->chgBit(oldp+905,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                & (7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                          >> 0x19U)))));
        bufp->chgBit(oldp+906,((6U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                       >> 0x19U))));
        bufp->chgBit(oldp+907,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                & (6U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                          >> 0x19U)))));
        bufp->chgBit(oldp+908,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_doPID_Cfg));
        bufp->chgBit(oldp+909,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                 & (6U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                           >> 0x19U))) 
                                & (((2ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_rs2) 
                                    | (3ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_rs2)) 
                                   | (4ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_rs2)))));
        bufp->chgCData(oldp+910,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_bigComp_reg),2);
        bufp->chgBit(oldp+911,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                & (0x7dU == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                             >> 0x19U)))));
        bufp->chgBit(oldp+912,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                & (0x7fU == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                             >> 0x19U)))));
        bufp->chgIData(oldp+913,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_ghe_status_reg),32);
        bufp->chgCData(oldp+914,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_ghe_event_reg),2);
        bufp->chgBit(oldp+915,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_ghe_initialised_reg));
        bufp->chgIData(oldp+916,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_ght_status_reg),32);
        bufp->chgCData(oldp+917,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_ght_critial_reg),2);
        bufp->chgQData(oldp+918,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_ght_monitor_satp_ppn),44);
        bufp->chgBit(oldp+920,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_has_monitor_target));
        bufp->chgCData(oldp+921,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_num_activated_cores),8);
        bufp->chgBit(oldp+922,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_define_monitor_target));
        bufp->chgSData(oldp+923,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_t_Value),15);
        bufp->chgCData(oldp+924,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_core_trace),2);
        bufp->chgBit(oldp+925,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_store_from_checker));
        bufp->chgCData(oldp+926,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_debug_perf_ctrl),5);
        bufp->chgBit(oldp+927,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__s_or_r));
        bufp->chgBit(oldp+928,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_undefine_monitor_target));
        bufp->chgBit(oldp+929,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe___05FT_6));
        bufp->chgBit(oldp+930,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe___05FT_9));
        bufp->chgBit(oldp+931,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                & (0x60U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                             >> 0x19U)))));
        bufp->chgBit(oldp+932,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___io_rocc_cmd_valid_output));
        bufp->chgCData(oldp+933,((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                  >> 0x19U)),7);
        bufp->chgCData(oldp+934,((0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                           >> 0x14U))),5);
        bufp->chgCData(oldp+935,((0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                           >> 0xfU))),5);
        bufp->chgBit(oldp+936,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                      >> 0xeU))));
        bufp->chgBit(oldp+937,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                      >> 0xdU))));
        bufp->chgBit(oldp+938,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                      >> 0xcU))));
        bufp->chgCData(oldp+939,((0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                           >> 7U))),5);
        bufp->chgCData(oldp+940,((0x7fU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst)),7);
        bufp->chgQData(oldp+941,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_wdata),64);
        bufp->chgQData(oldp+943,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_rs2),64);
        bufp->chgBit(oldp+945,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__io_status_cease_r));
        bufp->chgBit(oldp+946,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_wfi));
        bufp->chgIData(oldp+947,((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_misa)),32);
        bufp->chgCData(oldp+948,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mprv)
                                   ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mpp)
                                   : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_prv))),2);
        bufp->chgCData(oldp+949,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_prv),2);
        bufp->chgBit(oldp+950,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_gva));
        bufp->chgBit(oldp+951,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_tsr));
        bufp->chgBit(oldp+952,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_tw));
        bufp->chgBit(oldp+953,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_tvm));
        bufp->chgBit(oldp+954,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mxr));
        bufp->chgBit(oldp+955,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_sum));
        bufp->chgBit(oldp+956,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mprv));
        bufp->chgCData(oldp+957,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_fs),2);
        bufp->chgCData(oldp+958,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mpp),2);
        bufp->chgBit(oldp+959,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_spp));
        bufp->chgBit(oldp+960,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mpie));
        bufp->chgBit(oldp+961,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_spie));
        bufp->chgBit(oldp+962,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mie));
        bufp->chgBit(oldp+963,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_sie));
        bufp->chgIData(oldp+964,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__RAW_counter),32);
        bufp->chgCData(oldp+965,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_ghe_initialised_reg) 
                                   << 3U) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_ghe_event_reg) 
                                             << 1U))),5);
        bufp->chgBit(oldp+966,((1U & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_ght_status_reg))));
        bufp->chgIData(oldp+967,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_num_activated_cores) 
                                   << 0x17U) | (0x7fffffU 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_ght_status_reg))),32);
        bufp->chgIData(oldp+968,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                    & (6U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                              >> 0x19U))) 
                                   & (((2ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_rs2) 
                                       | (3ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_rs2)) 
                                      | (4ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_rs2)))
                                   ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_wdata)
                                   : 0U)),32);
        bufp->chgBit(oldp+969,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                & (0x2dU == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                             >> 0x19U)))));
        bufp->chgBit(oldp+970,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_define_monitor_target) 
                                | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_ght_monitor_satp_ppn 
                                    == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_satp_ppn) 
                                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_has_monitor_target)))));
        bufp->chgCData(oldp+971,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                   & (0x70U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                >> 0x19U)))
                                   ? (0xfU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_wdata))
                                   : 0U)),4);
        bufp->chgCData(oldp+972,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT____Vcellinp__cmdRouter__io_record_and_store_in),2);
        bufp->chgBit(oldp+973,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                & (0x64U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                             >> 0x19U)))));
        bufp->chgCData(oldp+974,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rsu_status),2);
        bufp->chgQData(oldp+975,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_satp_ppn),44);
        __Vtemp_h3ea52170__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT___GEN_3);
        __Vtemp_h3ea52170__0[1U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT___GEN_3 
                                            >> 0x20U));
        __Vtemp_h3ea52170__0[2U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_checking);
        __Vtemp_h3ea52170__0[3U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_checking 
                                            >> 0x20U));
        __Vtemp_h3ea52170__0[4U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_postchecking);
        __Vtemp_h3ea52170__0[5U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_postchecking 
                                            >> 0x20U));
        __Vtemp_h3ea52170__0[6U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_otherthread);
        __Vtemp_h3ea52170__0[7U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_otherthread 
                                            >> 0x20U));
        __Vtemp_h3ea52170__0[8U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_nonchecking);
        __Vtemp_h3ea52170__0[9U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_nonchecking 
                                            >> 0x20U));
        __Vtemp_h3ea52170__0[0xaU] = 0U;
        __Vtemp_h3ea52170__0[0xbU] = 0U;
        __Vtemp_h3ea52170__0[0xcU] = 0U;
        __Vtemp_h3ea52170__0[0xdU] = 0U;
        __Vtemp_h3ea52170__0[0xeU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_howmany_checkpoints);
        __Vtemp_h3ea52170__0[0xfU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_howmany_checkpoints 
                                              >> 0x20U));
        __Vtemp_h3ea52170__0[0x10U] = 0U;
        __Vtemp_h3ea52170__0[0x11U] = 0U;
        __Vtemp_h3ea52170__0[0x12U] = 0U;
        __Vtemp_h3ea52170__0[0x13U] = 0U;
        __Vtemp_h3ea52170__0[0x14U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_CPStrans);
        __Vtemp_h3ea52170__0[0x15U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_CPStrans 
                                               >> 0x20U));
        __Vtemp_h3ea52170__0[0x16U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_L_timer_worest);
        __Vtemp_h3ea52170__0[0x17U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_L_timer_worest 
                                               >> 0x20U));
        __Vtemp_h3ea52170__0[0x18U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_num_st);
        __Vtemp_h3ea52170__0[0x19U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_num_st 
                                               >> 0x20U));
        __Vtemp_h3ea52170__0[0x1aU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_num_ld);
        __Vtemp_h3ea52170__0[0x1bU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_num_ld 
                                               >> 0x20U));
        __Vtemp_h3ea52170__0[0x1cU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT___GEN_3);
        __Vtemp_h3ea52170__0[0x1dU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT___GEN_3 
                                               >> 0x20U));
        __Vtemp_h3ea52170__0[0x1eU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT___GEN_3);
        __Vtemp_h3ea52170__0[0x1fU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT___GEN_3 
                                               >> 0x20U));
        bufp->chgQData(oldp+977,((((QData)((IData)(
                                                   __Vtemp_h3ea52170__0[
                                                   (((IData)(0x3fU) 
                                                     + 
                                                     (0x3c0U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_debug_perf_ctrl) 
                                                         << 5U))) 
                                                    >> 5U)])) 
                                   << 0x20U) | (QData)((IData)(
                                                               __Vtemp_h3ea52170__0[
                                                               (0x1eU 
                                                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_debug_perf_ctrl))])))),64);
        bufp->chgBit(oldp+979,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT____Vcellinp__cmdRouter__io_elu_deq_in));
        bufp->chgCData(oldp+980,(((2U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__u_channel__DOT__emptyReg)) 
                                         << 1U)) | 
                                  (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__u_channel__DOT__emptyReg))))),2);
        bufp->chgSData(oldp+981,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                   & (0x7dU == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                >> 0x19U)))
                                   ? (0xffffU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_wdata))
                                   : 0U)),16);
        bufp->chgCData(oldp+982,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                   & (0x7fU == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                >> 0x19U)))
                                   ? (0xfU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_wdata))
                                   : 0U)),4);
        bufp->chgBit(oldp+983,((0x2bU == (0x7fU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst))));
        bufp->chgBit(oldp+984,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid));
        bufp->chgCData(oldp+985,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_cfiType),2);
        bufp->chgBit(oldp+986,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_taken));
        bufp->chgCData(oldp+987,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_mask),2);
        bufp->chgBit(oldp+988,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_bridx));
        bufp->chgQData(oldp+989,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_target),39);
        bufp->chgCData(oldp+991,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_entry),5);
        bufp->chgCData(oldp+992,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_bht_history),8);
        bufp->chgBit(oldp+993,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_bht_value));
        bufp->chgQData(oldp+994,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_pc),40);
        bufp->chgIData(oldp+996,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_data),32);
        bufp->chgCData(oldp+997,((3U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__fq__DOT__valid_0)
                                         ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__fq__DOT__elts_0_mask)
                                         : (7U & ((IData)(3U) 
                                                  << 
                                                  (1U 
                                                   & (IData)(
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_pc 
                                                              >> 1U)))))))),2);
        bufp->chgBit(oldp+998,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_xcpt_pf_inst));
        bufp->chgBit(oldp+999,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_xcpt_gf_inst));
        bufp->chgBit(oldp+1000,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_xcpt_ae_inst));
        bufp->chgBit(oldp+1001,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_replay));
        bufp->chgBit(oldp+1002,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__gpa_valid));
        bufp->chgQData(oldp+1003,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__gpa),40);
        bufp->chgBit(oldp+1005,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___io_near_full_output));
        bufp->chgBit(oldp+1006,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___io_near_full_output)))));
        bufp->chgBit(oldp+1007,(((0xfcU < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT___GEN_0)) 
                                 | (0xfcU < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT___GEN_0)))));
        bufp->chgBit(oldp+1008,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_s2_nack_cause_raw_REG) 
                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_waw_hazard))));
        bufp->chgBit(oldp+1009,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_uncached) 
                                 & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_hit)))));
        bufp->chgIData(oldp+1010,((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_addr)),32);
        bufp->chgBit(oldp+1011,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_requestor_2_resp_valid));
        bufp->chgQData(oldp+1012,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__doUncachedResp)
                                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_uncached_resp_addr
                                    : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_addr)),40);
        bufp->chgCData(oldp+1014,((0x3fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_tag) 
                                            >> 2U))),8);
        bufp->chgCData(oldp+1015,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd),5);
        bufp->chgCData(oldp+1016,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_size),2);
        bufp->chgBit(oldp+1017,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_signed));
        bufp->chgCData(oldp+1018,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_dprv),2);
        bufp->chgBit(oldp+1019,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_dv));
        bufp->chgQData(oldp+1020,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcache_io_cpu_resp_bits_data),64);
        bufp->chgCData(oldp+1022,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_mask),8);
        bufp->chgBit(oldp+1023,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__doUncachedResp));
        bufp->chgBit(oldp+1024,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_read));
        bufp->chgQData(oldp+1025,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcache_io_cpu_resp_bits_data_word_bypass),64);
        bufp->chgQData(oldp+1027,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_data),64);
        bufp->chgBit(oldp+1029,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_xcpt_ma_ld_output));
        bufp->chgBit(oldp+1030,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_xcpt_ma_st_output));
        bufp->chgBit(oldp+1031,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_xcpt_pf_ld_output));
        bufp->chgBit(oldp+1032,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_xcpt_pf_st_output));
        bufp->chgBit(oldp+1033,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_xcpt_gf_ld_output));
        bufp->chgBit(oldp+1034,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_xcpt_gf_st_output));
        bufp->chgBit(oldp+1035,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_xcpt_ae_ld_output));
        bufp->chgBit(oldp+1036,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_xcpt_ae_st_output));
        bufp->chgQData(oldp+1037,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_tlb_xcpt_gpa),40);
        bufp->chgBit(oldp+1039,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_tlb_xcpt_gpa_is_pte));
        bufp->chgBit(oldp+1040,((1U & (~ (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_valid) 
                                             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_req_no_xcpt))) 
                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid) 
                                               & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_no_xcpt)))) 
                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__cached_grant_wait)) 
                                          | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__uncachedInFlight_0))))));
        bufp->chgBit(oldp+1041,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___arb_io_out_ready_T_2) 
                                 & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_state)))));
        bufp->chgBit(oldp+1042,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__cached_grant_wait) 
                                 & (7U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_perf_blocked_near_end_of_refill_refill_count)))));
        bufp->chgBit(oldp+1043,((1U & (~ ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_perf_canAcceptLoadThenLoad_T_55) 
                                            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_rmw_r)) 
                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_perf_canAcceptStoreThenLoad_T_6)) 
                                          & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_perf_canAcceptLoadThenLoad_T))))));
        bufp->chgBit(oldp+1044,((1U & ((~ ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_perf_canAcceptLoadThenLoad_T_55) 
                                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_rmw_r)) 
                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_perf_canAcceptStoreThenLoad_T_6)) 
                                           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_perf_canAcceptLoadThenLoad_T))) 
                                       & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_valid))))));
        bufp->chgBit(oldp+1045,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcache_io_cpu_perf_canAcceptLoadThenLoad));
        bufp->chgBit(oldp+1046,((1U & (~ ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_perf_canAcceptLoadThenLoad_T) 
                                            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_perf_canAcceptLoadThenLoad_T_55) 
                                               & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_waw_hazard)))) 
                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_held)) 
                                          | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_valid))))));
        bufp->chgBit(oldp+1047,((1U & (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_perf_canAcceptLoadThenLoad_T) 
                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_perf_canAcceptLoadThenLoad_T_55) 
                                              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_rmw_r))) 
                                          | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_perf_canAcceptLoadThenLoad_T_55) 
                                               & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_waw_hazard))) 
                                              | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_held)) 
                                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_valid)))))));
        bufp->chgBit(oldp+1048,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_fcsr_flags_valid));
        bufp->chgCData(oldp+1049,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_fcsr_flags_bits),5);
        bufp->chgQData(oldp+1050,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__store),64);
        bufp->chgQData(oldp+1052,(((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_wflags)
                                           ? ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_ren2)) 
                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_typ) 
                                                 >> 1U))
                                           : ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
                                              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_fmt))))
                                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__toint
                                    : (((QData)((IData)(
                                                        (- (IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__toint 
                                                                               >> 0x1fU))))))) 
                                        << 0x20U) | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__toint))))),64);
        bufp->chgBit(oldp+1054,((1U & (~ ((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ex_reg_valid) 
                                              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ex_reg_ctrl_wflags)) 
                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_reg_valid) 
                                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_wflags))) 
                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wb_toint_valid)) 
                                           | (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wen))) 
                                          | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_inFlight))))));
        bufp->chgBit(oldp+1055,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_nack_mem_output));
        bufp->chgBit(oldp+1056,((((5U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                >> 0xcU))) 
                                  | (6U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                  >> 0xcU)))) 
                                 | (IData)(((0x7000U 
                                             == (0x7000U 
                                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits)) 
                                            & (4U < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_fpu_fcsr_rm)))))));
        bufp->chgBit(oldp+1057,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_dec_wen));
        bufp->chgBit(oldp+1058,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___fp_decoder_io_sigs_ren1));
        bufp->chgBit(oldp+1059,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___fp_decoder_io_sigs_ren2));
        bufp->chgBit(oldp+1060,((0x1fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T))));
        bufp->chgBit(oldp+1061,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wb_reg_valid) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_sboard_set_REG))));
        bufp->chgBit(oldp+1062,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_sboard_clr));
        bufp->chgCData(oldp+1063,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__waddr),5);
        bufp->chgQData(oldp+1064,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_0),64);
        bufp->chgQData(oldp+1066,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_1),64);
        bufp->chgQData(oldp+1068,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_2),64);
        bufp->chgQData(oldp+1070,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_3),64);
        bufp->chgQData(oldp+1072,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_4),64);
        bufp->chgQData(oldp+1074,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_5),64);
        bufp->chgQData(oldp+1076,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_6),64);
        bufp->chgQData(oldp+1078,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_7),64);
        bufp->chgQData(oldp+1080,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_8),64);
        bufp->chgQData(oldp+1082,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_9),64);
        bufp->chgQData(oldp+1084,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_10),64);
        bufp->chgQData(oldp+1086,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_11),64);
        bufp->chgQData(oldp+1088,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_12),64);
        bufp->chgQData(oldp+1090,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_13),64);
        bufp->chgQData(oldp+1092,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_14),64);
        bufp->chgQData(oldp+1094,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_15),64);
        bufp->chgQData(oldp+1096,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_16),64);
        bufp->chgQData(oldp+1098,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_17),64);
        bufp->chgQData(oldp+1100,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_18),64);
        bufp->chgQData(oldp+1102,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_19),64);
        bufp->chgQData(oldp+1104,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_20),64);
        bufp->chgQData(oldp+1106,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_21),64);
        bufp->chgQData(oldp+1108,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_22),64);
        bufp->chgQData(oldp+1110,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_23),64);
        bufp->chgQData(oldp+1112,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_24),64);
        bufp->chgQData(oldp+1114,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_25),64);
        bufp->chgQData(oldp+1116,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_26),64);
        bufp->chgQData(oldp+1118,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_27),64);
        bufp->chgQData(oldp+1120,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_28),64);
        bufp->chgQData(oldp+1122,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_29),64);
        bufp->chgQData(oldp+1124,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_30),64);
        bufp->chgQData(oldp+1126,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_31),64);
        bufp->chgBit(oldp+1128,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_fpu_inflight));
        bufp->chgBit(oldp+1129,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__empty)))));
        bufp->chgCData(oldp+1130,((0x1fU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT___ram_ext_R0_data[0U])),5);
        bufp->chgQData(oldp+1131,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT___ram_ext_R0_data[2U])) 
                                    << 0x3bU) | (((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT___ram_ext_R0_data[1U])) 
                                                  << 0x1bU) 
                                                 | ((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT___ram_ext_R0_data[0U])) 
                                                    >> 5U)))),64);
        bufp->chgBit(oldp+1133,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___io_rocc_cmd_valid_output) 
                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid))));
        bufp->chgBit(oldp+1134,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_core_trace))));
        bufp->chgBit(oldp+1135,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_sfence_valid_output));
        bufp->chgBit(oldp+1136,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_mem_size))));
        bufp->chgBit(oldp+1137,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_mem_size) 
                                       >> 1U))));
        bufp->chgQData(oldp+1138,((0x7fffffffffULL 
                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_wdata)),39);
        bufp->chgBit(oldp+1140,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_rs2))));
        bufp->chgBit(oldp+1141,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_hfence_v));
        bufp->chgBit(oldp+1142,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_hfence_g));
        bufp->chgCData(oldp+1143,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_btb_resp_cfiType),2);
        bufp->chgBit(oldp+1144,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_btb_resp_taken));
        bufp->chgCData(oldp+1145,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_btb_resp_mask),2);
        bufp->chgBit(oldp+1146,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_btb_resp_bridx));
        bufp->chgQData(oldp+1147,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_btb_resp_target),39);
        bufp->chgCData(oldp+1149,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_btb_resp_entry),5);
        bufp->chgCData(oldp+1150,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_btb_resp_bht_history),8);
        bufp->chgBit(oldp+1151,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_btb_resp_bht_value));
        bufp->chgQData(oldp+1152,((0x7fffffffffULL 
                                   & (~ (3ULL | (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_btb_update_bits_br_pc_output))))),39);
        bufp->chgBit(oldp+1154,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_cfi));
        bufp->chgQData(oldp+1155,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_btb_update_bits_br_pc_output),39);
        bufp->chgCData(oldp+1157,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_btb_update_bits_cfiType_T_9) 
                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                       >> 7U)) ? 2U
                                    : (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_jalr) 
                                        & (1U == ((0xcU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                      >> 0x10U)) 
                                                  | (3U 
                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                        >> 0xfU)))))
                                        ? 3U : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_btb_update_bits_cfiType_T_9)))),2);
        bufp->chgBit(oldp+1158,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_branch));
        bufp->chgBit(oldp+1159,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_br_taken));
        bufp->chgBit(oldp+1160,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_imem_checker_mode));
        bufp->chgBit(oldp+1161,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_imem_if_check_completed));
        bufp->chgBit(oldp+1162,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___icsl_io_icsl_stalld) 
                                  & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__fsm_state))) 
                                 | (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__fsm_state)))));
        bufp->chgBit(oldp+1163,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___io_dmem_req_valid_output));
        bufp->chgQData(oldp+1164,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode))
                                    ? 0ULL : (((QData)((IData)(
                                                               (1U 
                                                                & (((0U 
                                                                     == 
                                                                     (0x1ffffffU 
                                                                      & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_rs_0 
                                                                                >> 0x27U)))) 
                                                                    | (0x1ffffffU 
                                                                       == 
                                                                       (0x1ffffffU 
                                                                        & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_rs_0 
                                                                                >> 0x27U)))))
                                                                    ? (IData)(
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___io_adder_out_output 
                                                                               >> 0x27U))
                                                                    : 
                                                                   (~ (IData)(
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___io_adder_out_output 
                                                                               >> 0x26U))))))) 
                                               << 0x27U) 
                                              | (0x7fffffffffULL 
                                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___io_adder_out_output)))),40);
        bufp->chgCData(oldp+1166,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode))
                                    ? 0U : ((0x3eU 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                >> 6U)) 
                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_fp)))),8);
        bufp->chgCData(oldp+1167,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode))
                                    ? 0U : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_mem_cmd))),5);
        bufp->chgCData(oldp+1168,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode))
                                    ? 0U : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_mem_size))),2);
        bufp->chgBit(oldp+1169,((1U & ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode))) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_hls)
                                              ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                 >> 0x14U)
                                              : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                 >> 0xeU)))))));
        bufp->chgCData(oldp+1170,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode))
                                    ? 0U : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_hls)
                                             ? 0U : 
                                            ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mprv)
                                              ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mpp)
                                              : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_prv))))),2);
        bufp->chgBit(oldp+1171,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___io_dmem_req_bits_dv_output));
        bufp->chgQData(oldp+1172,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode))
                                    ? 0ULL : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_req_data_T_3)),64);
        bufp->chgCData(oldp+1174,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_satp_mode),4);
        bufp->chgBit(oldp+1175,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_hstatus_gva));
        bufp->chgBit(oldp+1176,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_cfg_l));
        bufp->chgCData(oldp+1177,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_cfg_a),2);
        bufp->chgBit(oldp+1178,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_cfg_x));
        bufp->chgBit(oldp+1179,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_cfg_w));
        bufp->chgBit(oldp+1180,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_cfg_r));
        bufp->chgIData(oldp+1181,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr),30);
        bufp->chgIData(oldp+1182,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_0_mask),32);
        bufp->chgBit(oldp+1183,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_cfg_l));
        bufp->chgCData(oldp+1184,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_cfg_a),2);
        bufp->chgBit(oldp+1185,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_cfg_x));
        bufp->chgBit(oldp+1186,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_cfg_w));
        bufp->chgBit(oldp+1187,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_cfg_r));
        bufp->chgIData(oldp+1188,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr),30);
        bufp->chgIData(oldp+1189,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_1_mask),32);
        bufp->chgBit(oldp+1190,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_cfg_l));
        bufp->chgCData(oldp+1191,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_cfg_a),2);
        bufp->chgBit(oldp+1192,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_cfg_x));
        bufp->chgBit(oldp+1193,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_cfg_w));
        bufp->chgBit(oldp+1194,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_cfg_r));
        bufp->chgIData(oldp+1195,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr),30);
        bufp->chgIData(oldp+1196,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_2_mask),32);
        bufp->chgBit(oldp+1197,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_cfg_l));
        bufp->chgCData(oldp+1198,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_cfg_a),2);
        bufp->chgBit(oldp+1199,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_cfg_x));
        bufp->chgBit(oldp+1200,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_cfg_w));
        bufp->chgBit(oldp+1201,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_cfg_r));
        bufp->chgIData(oldp+1202,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr),30);
        bufp->chgIData(oldp+1203,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_3_mask),32);
        bufp->chgBit(oldp+1204,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_cfg_l));
        bufp->chgCData(oldp+1205,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_cfg_a),2);
        bufp->chgBit(oldp+1206,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_cfg_x));
        bufp->chgBit(oldp+1207,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_cfg_w));
        bufp->chgBit(oldp+1208,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_cfg_r));
        bufp->chgIData(oldp+1209,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr),30);
        bufp->chgIData(oldp+1210,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_4_mask),32);
        bufp->chgBit(oldp+1211,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_cfg_l));
        bufp->chgCData(oldp+1212,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_cfg_a),2);
        bufp->chgBit(oldp+1213,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_cfg_x));
        bufp->chgBit(oldp+1214,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_cfg_w));
        bufp->chgBit(oldp+1215,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_cfg_r));
        bufp->chgIData(oldp+1216,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr),30);
        bufp->chgIData(oldp+1217,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_5_mask),32);
        bufp->chgBit(oldp+1218,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_cfg_l));
        bufp->chgCData(oldp+1219,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_cfg_a),2);
        bufp->chgBit(oldp+1220,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_cfg_x));
        bufp->chgBit(oldp+1221,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_cfg_w));
        bufp->chgBit(oldp+1222,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_cfg_r));
        bufp->chgIData(oldp+1223,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr),30);
        bufp->chgIData(oldp+1224,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_6_mask),32);
        bufp->chgBit(oldp+1225,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_cfg_l));
        bufp->chgCData(oldp+1226,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_cfg_a),2);
        bufp->chgBit(oldp+1227,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_cfg_x));
        bufp->chgBit(oldp+1228,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_cfg_w));
        bufp->chgBit(oldp+1229,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_cfg_r));
        bufp->chgIData(oldp+1230,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_addr),30);
        bufp->chgIData(oldp+1231,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_7_mask),32);
        bufp->chgBit(oldp+1232,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__csr_wen) 
                                 & (0x3fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_154)))));
        bufp->chgQData(oldp+1233,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__wdata),64);
        bufp->chgQData(oldp+1235,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_custom_0),64);
        bufp->chgBit(oldp+1237,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__csr_wen) 
                                 & (IData)((0xf12U 
                                            == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr))))));
        bufp->chgBit(oldp+1238,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__csr_wen) 
                                 & (IData)((0xf10U 
                                            == (0xffeU 
                                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr)))))));
        bufp->chgBit(oldp+1239,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__csr_wen) 
                                 & (IData)((0xf13U 
                                            == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr))))));
        bufp->chgIData(oldp+1240,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits),32);
        bufp->chgQData(oldp+1241,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_rs_0),64);
        bufp->chgCData(oldp+1243,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_fpu_fcsr_rm),3);
        bufp->chgBit(oldp+1244,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_fpu_dmem_resp_val));
        bufp->chgCData(oldp+1245,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode))
                                    ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__resp_valid_reg)
                                        ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__req_size_reg)
                                        : 0U) : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_size))),3);
        bufp->chgCData(oldp+1246,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__dmem_resp_waddr),5);
        bufp->chgQData(oldp+1247,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode))
                                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_io_resp_data
                                    : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcache_io_cpu_resp_bits_data_word_bypass)),64);
        bufp->chgQData(oldp+1249,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_fpu_r_farf_bits),64);
        bufp->chgCData(oldp+1251,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out),8);
        bufp->chgBit(oldp+1252,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out));
        bufp->chgBit(oldp+1253,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode));
        bufp->chgBit(oldp+1254,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode));
        bufp->chgBit(oldp+1255,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___icsl_io_if_overtaking));
        bufp->chgBit(oldp+1256,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_173)))));
        bufp->chgBit(oldp+1257,((1U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__packet_valid) 
                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__packet_valid_ECP)) 
                                        | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT___io_near_full_output))) 
                                       | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___io_near_full_output))))));
        bufp->chgBit(oldp+1258,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT___io_near_full_output) 
                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___io_near_full_output))));
        bufp->chgBit(oldp+1259,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl_req_valid));
        bufp->chgBit(oldp+1260,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl_resp_replay_rocc));
        bufp->chgBit(oldp+1261,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl_resp_replay_csr));
        bufp->chgBit(oldp+1262,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_reg_pause));
        bufp->chgBit(oldp+1263,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_legal));
        bufp->chgBit(oldp+1264,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_fp));
        bufp->chgBit(oldp+1265,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_rocc));
        bufp->chgBit(oldp+1266,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_branch));
        bufp->chgBit(oldp+1267,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_jal));
        bufp->chgBit(oldp+1268,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_jalr));
        bufp->chgBit(oldp+1269,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_rxs2));
        bufp->chgBit(oldp+1270,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_rxs1));
        bufp->chgBit(oldp+1271,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_scie));
        bufp->chgBit(oldp+1272,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_zbk));
        bufp->chgBit(oldp+1273,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_zkn));
        bufp->chgBit(oldp+1274,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_zks));
        bufp->chgCData(oldp+1275,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_alu2),2);
        bufp->chgCData(oldp+1276,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_alu1),2);
        bufp->chgCData(oldp+1277,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_sel_imm),3);
        bufp->chgBit(oldp+1278,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_dw));
        bufp->chgCData(oldp+1279,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_fn),4);
        bufp->chgBit(oldp+1280,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_mem));
        bufp->chgCData(oldp+1281,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_mem_cmd),5);
        bufp->chgBit(oldp+1282,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_rfs1));
        bufp->chgBit(oldp+1283,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_rfs2));
        bufp->chgBit(oldp+1284,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_rfs3));
        bufp->chgBit(oldp+1285,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_wfd));
        bufp->chgBit(oldp+1286,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_mul));
        bufp->chgBit(oldp+1287,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_div));
        bufp->chgBit(oldp+1288,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_wxd));
        bufp->chgCData(oldp+1289,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_csr),3);
        bufp->chgBit(oldp+1290,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_fence_i));
        bufp->chgBit(oldp+1291,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_fence));
        bufp->chgBit(oldp+1292,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_amo));
        bufp->chgBit(oldp+1293,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_dp));
        bufp->chgBit(oldp+1294,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_legal));
        bufp->chgBit(oldp+1295,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_fp));
        bufp->chgBit(oldp+1296,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_rocc));
        bufp->chgBit(oldp+1297,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_jal));
        bufp->chgBit(oldp+1298,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_jalr));
        bufp->chgBit(oldp+1299,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_rxs2));
        bufp->chgBit(oldp+1300,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_rxs1));
        bufp->chgBit(oldp+1301,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_scie));
        bufp->chgBit(oldp+1302,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_zbk));
        bufp->chgBit(oldp+1303,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_zkn));
        bufp->chgBit(oldp+1304,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_zks));
        bufp->chgCData(oldp+1305,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_sel_alu2),2);
        bufp->chgCData(oldp+1306,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_sel_alu1),2);
        bufp->chgCData(oldp+1307,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_sel_imm),3);
        bufp->chgBit(oldp+1308,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_alu_dw));
        bufp->chgCData(oldp+1309,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_alu_fn),4);
        bufp->chgBit(oldp+1310,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_mem));
        bufp->chgCData(oldp+1311,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_mem_cmd),5);
        bufp->chgBit(oldp+1312,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_rfs1));
        bufp->chgBit(oldp+1313,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_rfs2));
        bufp->chgBit(oldp+1314,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_rfs3));
        bufp->chgBit(oldp+1315,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_wfd));
        bufp->chgBit(oldp+1316,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_mul));
        bufp->chgBit(oldp+1317,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_div));
        bufp->chgBit(oldp+1318,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_wxd));
        bufp->chgCData(oldp+1319,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_csr),3);
        bufp->chgBit(oldp+1320,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_fence_i));
        bufp->chgBit(oldp+1321,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_fence));
        bufp->chgBit(oldp+1322,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_amo));
        bufp->chgBit(oldp+1323,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_dp));
        bufp->chgBit(oldp+1324,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_rocc));
        bufp->chgBit(oldp+1325,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_branch));
        bufp->chgBit(oldp+1326,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_jal));
        bufp->chgBit(oldp+1327,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_jalr));
        bufp->chgBit(oldp+1328,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_rxs2));
        bufp->chgBit(oldp+1329,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_rxs1));
        bufp->chgBit(oldp+1330,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_mem));
        bufp->chgBit(oldp+1331,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_rfs1));
        bufp->chgBit(oldp+1332,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_rfs2));
        bufp->chgBit(oldp+1333,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_wfd));
        bufp->chgBit(oldp+1334,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_div));
        bufp->chgBit(oldp+1335,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_wxd));
        bufp->chgCData(oldp+1336,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_csr),3);
        bufp->chgBit(oldp+1337,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_fence_i));
        bufp->chgBit(oldp+1338,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_xcpt_interrupt));
        bufp->chgBit(oldp+1339,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_valid));
        bufp->chgBit(oldp+1340,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rvc));
        bufp->chgCData(oldp+1341,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_btb_resp_cfiType),2);
        bufp->chgBit(oldp+1342,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_btb_resp_taken));
        bufp->chgCData(oldp+1343,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_btb_resp_mask),2);
        bufp->chgBit(oldp+1344,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_btb_resp_bridx));
        bufp->chgQData(oldp+1345,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_btb_resp_target),39);
        bufp->chgCData(oldp+1347,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_btb_resp_entry),5);
        bufp->chgCData(oldp+1348,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_btb_resp_bht_history),8);
        bufp->chgBit(oldp+1349,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_btb_resp_bht_value));
        bufp->chgBit(oldp+1350,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_xcpt));
        bufp->chgBit(oldp+1351,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_flush_pipe));
        bufp->chgBit(oldp+1352,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_load_use));
        bufp->chgQData(oldp+1353,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_cause),64);
        bufp->chgBit(oldp+1355,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_replay));
        bufp->chgQData(oldp+1356,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_pc),40);
        bufp->chgCData(oldp+1358,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_mem_size),2);
        bufp->chgBit(oldp+1359,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_hls));
        bufp->chgIData(oldp+1360,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst),32);
        bufp->chgIData(oldp+1361,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_raw_inst),32);
        bufp->chgBit(oldp+1362,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_scie_unpipelined));
        bufp->chgBit(oldp+1363,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_scie_pipelined));
        bufp->chgBit(oldp+1364,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_xcpt_interrupt));
        bufp->chgBit(oldp+1365,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_valid));
        bufp->chgBit(oldp+1366,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_rvc));
        bufp->chgBit(oldp+1367,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_xcpt));
        bufp->chgBit(oldp+1368,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_replay));
        bufp->chgBit(oldp+1369,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_flush_pipe));
        bufp->chgQData(oldp+1370,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_cause),64);
        bufp->chgBit(oldp+1372,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_slow_bypass));
        bufp->chgBit(oldp+1373,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_load));
        bufp->chgBit(oldp+1374,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_store));
        bufp->chgBit(oldp+1375,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_sfence));
        bufp->chgQData(oldp+1376,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_pc),40);
        bufp->chgIData(oldp+1378,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst),32);
        bufp->chgCData(oldp+1379,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_mem_size),2);
        bufp->chgBit(oldp+1380,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_hls_or_dv));
        bufp->chgIData(oldp+1381,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_raw_inst),32);
        bufp->chgBit(oldp+1382,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_scie_pipelined));
        bufp->chgBit(oldp+1383,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_valid));
        bufp->chgBit(oldp+1384,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_xcpt));
        bufp->chgBit(oldp+1385,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_replay));
        bufp->chgBit(oldp+1386,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_flush_pipe));
        bufp->chgQData(oldp+1387,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_cause),64);
        bufp->chgBit(oldp+1389,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_sfence));
        bufp->chgQData(oldp+1390,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_pc),40);
        bufp->chgCData(oldp+1392,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_mem_size),2);
        bufp->chgBit(oldp+1393,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_hls_or_dv));
        bufp->chgIData(oldp+1394,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst),32);
        bufp->chgIData(oldp+1395,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_raw_inst),32);
        bufp->chgQData(oldp+1396,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_wdata),64);
        bufp->chgQData(oldp+1398,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_rs2),64);
        bufp->chgBit(oldp+1400,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__check_exception));
        bufp->chgBit(oldp+1401,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__check_privret_REG));
        bufp->chgBit(oldp+1402,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__excpt_mode));
        bufp->chgCData(oldp+1403,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_ctrl_csr),3);
        bufp->chgCData(oldp+1404,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2),5);
        bufp->chgCData(oldp+1405,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1),5);
        bufp->chgBit(oldp+1406,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_reg_fence));
        bufp->chgBit(oldp+1407,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_csr_en));
        bufp->chgQData(oldp+1408,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_pc),40);
        bufp->chgBit(oldp+1410,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_mem_busy));
        bufp->chgBit(oldp+1411,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_rocc));
        bufp->chgQData(oldp+1412,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_rocc)
                                    ? (((QData)((IData)(
                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT___ram_ext_R0_data[2U])) 
                                        << 0x3bU) | 
                                       (((QData)((IData)(
                                                         vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT___ram_ext_R0_data[1U])) 
                                         << 0x1bU) 
                                        | ((QData)((IData)(
                                                           vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT___ram_ext_R0_data[0U])) 
                                           >> 5U)))
                                    : (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                                        | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode))
                                        ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_io_resp_data
                                        : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcache_io_cpu_resp_bits_data_word_bypass))),64);
        bufp->chgCData(oldp+1414,((0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                            >> 7U))),5);
        bufp->chgCData(oldp+1415,((0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                                            >> 7U))),5);
        bufp->chgBit(oldp+1416,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_bypass_0));
        bufp->chgBit(oldp+1417,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_bypass_1));
        bufp->chgCData(oldp+1418,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_lsb_0),2);
        bufp->chgCData(oldp+1419,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_lsb_1),2);
        bufp->chgQData(oldp+1420,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_msb_0),62);
        bufp->chgQData(oldp+1422,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_msb_1),62);
        bufp->chgQData(oldp+1424,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_rs_1),64);
        bufp->chgBit(oldp+1426,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_imm_sign));
        bufp->chgBit(oldp+1427,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__record_pc));
        bufp->chgQData(oldp+1428,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__pc_special),40);
        bufp->chgBit(oldp+1430,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_pc_valid));
        bufp->chgBit(oldp+1431,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_dcache_miss));
        bufp->chgQData(oldp+1432,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_br_target),40);
        bufp->chgQData(oldp+1434,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_npc),40);
        bufp->chgBit(oldp+1436,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_npc_misaligned));
        bufp->chgBit(oldp+1437,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ldst_xcpt));
        bufp->chgBit(oldp+1438,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_xcpt));
        bufp->chgBit(oldp+1439,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__fpu_kill_mem));
        bufp->chgBit(oldp+1440,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div_io_kill_REG));
        bufp->chgBit(oldp+1441,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_xcpt));
        bufp->chgBit(oldp+1442,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_wxd));
        bufp->chgBit(oldp+1443,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__replay_wb_lsl));
        bufp->chgBit(oldp+1444,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_csr));
        bufp->chgBit(oldp+1445,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_set_sboard));
        bufp->chgBit(oldp+1446,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__if_ret_special_REG));
        bufp->chgBit(oldp+1447,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__dmem_resp_xpu));
        bufp->chgBit(oldp+1448,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__dmem_resp_fpu));
        bufp->chgBit(oldp+1449,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__dmem_resp_valid));
        bufp->chgBit(oldp+1450,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__dmem_resp_replay));
        bufp->chgQData(oldp+1451,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_req_valid_rocc_T)
                                    ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                                        | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode))
                                        ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_deq_valid_0)
                                             ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_deq_data_0
                                             : 0ULL) 
                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_deq_valid_1)
                                               ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_deq_data_1
                                               : 0ULL))
                                        : (((QData)((IData)(
                                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT___ram_ext_R0_data[2U])) 
                                            << 0x3bU) 
                                           | (((QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT___ram_ext_R0_data[1U])) 
                                               << 0x1bU) 
                                              | ((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT___ram_ext_R0_data[0U])) 
                                                 >> 5U))))
                                    : (((QData)((IData)(
                                                        ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__req_dw)
                                                          ? (IData)(
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__result 
                                                                     >> 0x20U))
                                                          : 
                                                         (- (IData)(
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__loOut 
                                                                     >> 0x1fU)))))) 
                                        << 0x20U) | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__loOut))))),64);
        bufp->chgCData(oldp+1453,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ll_waddr),5);
        bufp->chgCData(oldp+1454,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__priv_status),2);
        bufp->chgCData(oldp+1455,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__check_priv),2);
        bufp->chgCData(oldp+1456,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__check_ret_priv),2);
        bufp->chgBit(oldp+1457,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__check_exception_REG));
        bufp->chgBit(oldp+1458,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__check_exception_REG_1));
        bufp->chgCData(oldp+1459,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__self_xcpt_flag),3);
        bufp->chgCData(oldp+1460,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__self_eret_flag),3);
        bufp->chgBit(oldp+1461,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__arf_paste_reg));
        bufp->chgBit(oldp+1462,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__start_check));
        bufp->chgBit(oldp+1463,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__r_exception_record));
        bufp->chgBit(oldp+1464,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl_io_if_check_privrun_REG));
        bufp->chgBit(oldp+1465,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__REG));
        bufp->chgBit(oldp+1466,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__REG_1));
        bufp->chgBit(oldp+1467,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__tval_any_addr));
        bufp->chgBit(oldp+1468,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_xcpt) 
                                 & (0x14ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_cause))));
        bufp->chgBit(oldp+1469,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__if_sysret));
        bufp->chgIData(oldp+1470,((0xfffffffeU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___r)),32);
        bufp->chgBit(oldp+1471,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_ex_hazard));
        bufp->chgBit(oldp+1472,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__data_hazard_mem));
        bufp->chgBit(oldp+1473,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_mem_hazard));
        bufp->chgBit(oldp+1474,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_wb_hazard));
        bufp->chgBit(oldp+1475,((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___fp_decoder_io_sigs_ren1) 
                                    & ((0x1fU >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1))
                                        ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_stall_fpu_r 
                                           >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1))
                                        : 0U)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___fp_decoder_io_sigs_ren2) 
                                                  & ((0x1fU 
                                                      >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2))
                                                      ? 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_stall_fpu_r 
                                                      >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2))
                                                      : 0U))) 
                                  | ((0x1fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T)) 
                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_stall_fpu_r 
                                        >> (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                            >> 0x1bU)))) 
                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_dec_wen) 
                                    & ((0x1fU >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rd))
                                        ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_stall_fpu_r 
                                           >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rd))
                                        : 0U)))));
        bufp->chgBit(oldp+1476,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__dcache_blocked_blocked));
        bufp->chgBit(oldp+1477,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rocc_blocked));
        bufp->chgBit(oldp+1478,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__load_use_RAW));
        bufp->chgIData(oldp+1479,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__c_value),27);
        bufp->chgBit(oldp+1480,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_427) 
                                 & (0x5f5e0ffU == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__c_value))));
        bufp->chgBit(oldp+1481,((0x5f5e0ffU == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__c_value)));
        bufp->chgBit(oldp+1482,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__checker_mode_1cycle_delay));
        bufp->chgBit(oldp+1483,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__checker_priv_mode_1cycle_delay));
        bufp->chgQData(oldp+1484,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu_adder_out),64);
        bufp->chgQData(oldp+1486,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_rs0),64);
        bufp->chgCData(oldp+1488,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl_req_cmd),2);
        bufp->chgCData(oldp+1489,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl_req_size),2);
        bufp->chgQData(oldp+1490,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf_notvalid_cnt),64);
        bufp->chgQData(oldp+1492,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mispred_cnt),64);
        bufp->chgQData(oldp+1494,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__imiss_cnt),64);
        bufp->chgQData(oldp+1496,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__coreMonitorBundle_rd0val_REG),64);
        bufp->chgQData(oldp+1498,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__coreMonitorBundle_rd0val_REG_1),64);
        bufp->chgQData(oldp+1500,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__coreMonitorBundle_rd1val_REG),64);
        bufp->chgQData(oldp+1502,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__coreMonitorBundle_rd1val_REG_1),64);
        bufp->chgCData(oldp+1504,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_ctrl_alu_fn),4);
        bufp->chgIData(oldp+1505,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__inst),32);
        bufp->chgCData(oldp+1506,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_ctrl_mem_cmd),5);
        bufp->chgBit(oldp+1507,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1))));
        bufp->chgBit(oldp+1508,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2))));
        bufp->chgBit(oldp+1509,((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_ctrl_csr))));
        bufp->chgBit(oldp+1510,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_csr_ren));
        bufp->chgBit(oldp+1511,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_illegal_insn));
        bufp->chgBit(oldp+1512,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_xcpt));
        bufp->chgBit(oldp+1513,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_bypass_src_1_1));
        bufp->chgBit(oldp+1514,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_bypass_src_1_2));
        bufp->chgBit(oldp+1515,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__do_bypass_1));
        bufp->chgBit(oldp+1516,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_sfence));
        bufp->chgBit(oldp+1517,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_pc_valid));
        bufp->chgBit(oldp+1518,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_bypass_src_0_1));
        bufp->chgBit(oldp+1519,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_bypass_src_0_2));
        bufp->chgBit(oldp+1520,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__do_bypass));
        bufp->chgIData(oldp+1521,((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__value_1)),32);
        bufp->chgQData(oldp+1522,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__alu__io_in2),64);
        bufp->chgQData(oldp+1524,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__alu__io_in1),64);
        bufp->chgQData(oldp+1526,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_dw)
                                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT__out
                                    : (((QData)((IData)(
                                                        (- (IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT__out 
                                                                               >> 0x1fU))))))) 
                                        << 0x20U) | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT__out))))),64);
        bufp->chgQData(oldp+1528,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___io_adder_out_output),64);
        bufp->chgBit(oldp+1530,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_fn) 
                                       ^ ((8U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_fn))
                                           ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT__slt)
                                           : (0ULL 
                                              == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT__in1_xor_in2))))));
        bufp->chgQData(oldp+1531,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT__in2_inv),64);
        bufp->chgQData(oldp+1533,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT__in1_xor_in2),64);
        bufp->chgBit(oldp+1535,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT__slt));
        bufp->chgQData(oldp+1536,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT__shin),64);
        bufp->chgQData(oldp+1538,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT__out),64);
        bufp->chgBit(oldp+1540,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_chain));
        bufp->chgCData(oldp+1541,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_tmatch),2);
        bufp->chgBit(oldp+1542,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_m));
        bufp->chgBit(oldp+1543,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_s));
        bufp->chgBit(oldp+1544,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_u));
        bufp->chgBit(oldp+1545,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_x));
        bufp->chgBit(oldp+1546,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_w));
        bufp->chgBit(oldp+1547,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_r));
        bufp->chgQData(oldp+1548,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_address),39);
        bufp->chgQData(oldp+1550,((0x7fffffffffULL 
                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_pc)),39);
        bufp->chgQData(oldp+1552,((0x7fffffffffULL 
                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_wdata)),39);
        bufp->chgBit(oldp+1554,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__bpu__DOT___T_5));
        bufp->chgBit(oldp+1555,(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_chain)) 
                                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__bpu__DOT___en_T_2)) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_r)) 
                                 & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_tmatch))
                                     ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__bpu__DOT___w_T_2) 
                                        ^ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_tmatch))
                                     : ((0x7fffffffffULL 
                                         & ((~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_wdata) 
                                            | (((QData)((IData)(
                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__bpu__DOT___r_T_10) 
                                                                 & (IData)(
                                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_address 
                                                                            >> 2U))))) 
                                                << 3U) 
                                               | (QData)((IData)(
                                                                 (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__bpu__DOT___r_T_10) 
                                                                   << 2U) 
                                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__bpu__DOT___r_T_8) 
                                                                      << 1U) 
                                                                     | (1U 
                                                                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_tmatch))))))))) 
                                        == (0x7fffffffffULL 
                                            & ((~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_address) 
                                               | (((QData)((IData)(
                                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__bpu__DOT___r_T_20) 
                                                                    & (IData)(
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_address 
                                                                               >> 2U))))) 
                                                   << 3U) 
                                                  | (QData)((IData)(
                                                                    (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__bpu__DOT___r_T_20) 
                                                                      << 2U) 
                                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__bpu__DOT___r_T_18) 
                                                                         << 1U) 
                                                                        | (1U 
                                                                           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_tmatch))))))))))))));
        bufp->chgBit(oldp+1556,(((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_chain)) 
                                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__bpu__DOT___en_T_2)) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_w)) 
                                 & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_tmatch))
                                     ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__bpu__DOT___w_T_2) 
                                        ^ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_tmatch))
                                     : ((0x7fffffffffULL 
                                         & ((~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_wdata) 
                                            | (((QData)((IData)(
                                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__bpu__DOT___w_T_10) 
                                                                 & (IData)(
                                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_address 
                                                                            >> 2U))))) 
                                                << 3U) 
                                               | (QData)((IData)(
                                                                 (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__bpu__DOT___w_T_10) 
                                                                   << 2U) 
                                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__bpu__DOT___w_T_8) 
                                                                      << 1U) 
                                                                     | (1U 
                                                                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_tmatch))))))))) 
                                        == (0x7fffffffffULL 
                                            & ((~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_address) 
                                               | (((QData)((IData)(
                                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__bpu__DOT___w_T_20) 
                                                                    & (IData)(
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_address 
                                                                               >> 2U))))) 
                                                   << 3U) 
                                                  | (QData)((IData)(
                                                                    (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__bpu__DOT___w_T_20) 
                                                                      << 2U) 
                                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__bpu__DOT___w_T_18) 
                                                                         << 1U) 
                                                                        | (1U 
                                                                           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_bp_0_control_tmatch))))))))))))));
        bufp->chgBit(oldp+1557,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__bpu__DOT___en_T_2))));
        bufp->chgSData(oldp+1558,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr),12);
        bufp->chgCData(oldp+1559,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_cmd),3);
        bufp->chgQData(oldp+1560,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_wdata),64);
        bufp->chgQData(oldp+1562,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_cause),64);
        bufp->chgQData(oldp+1564,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_tval),40);
        bufp->chgQData(oldp+1566,(((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_xcpt) 
                                       & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_xcpt))) 
                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_xcpt_gf_ld_output) 
                                         | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_xcpt_gf_st_output))) 
                                     & (0U == (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_xcpt_pf_ld_output) 
                                                << 1U) 
                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_xcpt_pf_st_output))))
                                     ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_tlb_xcpt_gpa
                                     : 0ULL) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_xcpt) 
                                                 & (0x14ULL 
                                                    == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_cause))
                                                 ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__gpa
                                                 : 0ULL))),40);
        bufp->chgBit(oldp+1568,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_gva));
        bufp->chgIData(oldp+1569,(((((3U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_raw_inst))
                                      ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                                         >> 0x10U) : 0U) 
                                    << 0x10U) | (0xffffU 
                                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_raw_inst))),32);
        bufp->chgBit(oldp+1570,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_pfarf_valid_out));
        bufp->chgCData(oldp+1571,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_fcsr_out),8);
        bufp->chgBit(oldp+1572,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__check_done) 
                                 & (~ ((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__state)) 
                                       | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_fpu_inflight))))));
        bufp->chgBit(oldp+1573,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__fsm_state))));
        bufp->chgQData(oldp+1574,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_rw_rdata_WIRE),64);
        bufp->chgBit(oldp+1576,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_decode_0_fp_illegal_output));
        bufp->chgBit(oldp+1577,((0xfU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_decode_0_fp_csr_T))));
        bufp->chgBit(oldp+1578,((1U & (~ (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_misa 
                                                  >> 0x17U))))));
        bufp->chgBit(oldp+1579,((1U & (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_decode_0_system_illegal_T) 
                                          | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__csr_exists))) 
                                         | (((0x180U 
                                              == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                  >> 0x14U)) 
                                             | (0x680U 
                                                == 
                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                 >> 0x14U))) 
                                            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__allow_sfence_vma)))) 
                                        | ((((0xbffU 
                                              < (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                 >> 0x14U)) 
                                             & (0xc20U 
                                                > (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                   >> 0x14U))) 
                                            | ((0xc7fU 
                                                < (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                   >> 0x14U)) 
                                               & (0xca0U 
                                                  > 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                   >> 0x14U)))) 
                                           & (~ ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_prv) 
                                                   >> 1U) 
                                                  | ((0x1fU 
                                                      >= 
                                                      (0x1fU 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                          >> 0x14U)))
                                                      ? 
                                                     ((7U 
                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mcounteren) 
                                                      >> 
                                                      (0x1fU 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                          >> 0x14U)))
                                                      : 0U)) 
                                                 & ((0U 
                                                     != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_prv)) 
                                                    | ((0x1fU 
                                                        >= 
                                                        (0x1fU 
                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                            >> 0x14U)))
                                                        ? 
                                                       ((7U 
                                                         & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_scounteren) 
                                                        >> 
                                                        (0x1fU 
                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                            >> 0x14U)))
                                                        : 0U)))))) 
                                       | ((0xfU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_decode_0_fp_csr_T)) 
                                          & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_decode_0_fp_illegal_output))))));
        bufp->chgBit(oldp+1580,((3U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                        >> 0x1eU))));
        bufp->chgBit(oldp+1581,((1U & (~ ((0x33fU < 
                                           (0xfffU 
                                            & (0x300U 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                  >> 0x14U)))) 
                                          & (0x344U 
                                             > (0xfffU 
                                                & (0x300U 
                                                   | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                      >> 0x14U)))))))));
        bufp->chgBit(oldp+1582,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___csr_io_decode_0_system_illegal));
        bufp->chgBit(oldp+1583,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_csr_stall_output));
        bufp->chgBit(oldp+1584,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___csr_io_eret));
        bufp->chgQData(oldp+1585,((0xffffffffffULL 
                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__check_exception)
                                       ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_pc
                                       : (((IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__notDebugTVec_base 
                                                    & (0x8000000000000000ULL 
                                                       == 
                                                       (0x80000000000000c0ULL 
                                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__cause))))
                                            ? ((0x3fffffffffffffc0ULL 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__notDebugTVec_base 
                                                   >> 2U)) 
                                               | (QData)((IData)(
                                                                 (0x3fU 
                                                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__cause)))))
                                            : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__notDebugTVec_base 
                                               >> 2U)) 
                                          << 2U)))),40);
        bufp->chgQData(oldp+1587,((0xfffffffffcULL 
                                   & (((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__notDebugTVec_base 
                                                & (0x8000000000000000ULL 
                                                   == 
                                                   (0x80000000000000c0ULL 
                                                    & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__cause))))
                                        ? ((0x3fffffffffffffc0ULL 
                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__notDebugTVec_base 
                                               >> 2U)) 
                                           | (QData)((IData)(
                                                             (0x3fU 
                                                              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__cause)))))
                                        : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__notDebugTVec_base 
                                           >> 2U)) 
                                      << 2U))),40);
        bufp->chgBit(oldp+1589,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__delegate));
        bufp->chgQData(oldp+1590,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__read_stvec),64);
        bufp->chgQData(oldp+1592,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__read_mtvec),64);
        bufp->chgQData(oldp+1594,((0xffffffffffULL 
                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__insn_ret)
                                       ? ((0x200U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr))
                                           ? (~ (1ULL 
                                                 | ((~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mepc) 
                                                    | ((QData)((IData)(
                                                                       (1U 
                                                                        & (~ (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_misa 
                                                                                >> 2U)))))) 
                                                       << 1U))))
                                           : (~ (1ULL 
                                                 | ((~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_sepc) 
                                                    | ((QData)((IData)(
                                                                       (1U 
                                                                        & (~ (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_misa 
                                                                                >> 2U)))))) 
                                                       << 1U)))))
                                       : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__check_privret_REG)
                                           ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__pc_special
                                           : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__check_exception)
                                               ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_pc
                                               : (((IData)(
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__notDebugTVec_base 
                                                            & (0x8000000000000000ULL 
                                                               == 
                                                               (0x80000000000000c0ULL 
                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__cause))))
                                                    ? 
                                                   ((0x3fffffffffffffc0ULL 
                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__notDebugTVec_base 
                                                        >> 2U)) 
                                                    | (QData)((IData)(
                                                                      (0x3fU 
                                                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__cause)))))
                                                    : 
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__notDebugTVec_base 
                                                    >> 2U)) 
                                                  << 2U)))))),40);
        bufp->chgQData(oldp+1596,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__value_1),64);
        bufp->chgBit(oldp+1598,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___csr_io_interrupt));
        bufp->chgQData(oldp+1599,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___csr_io_interrupt_cause),64);
        bufp->chgIData(oldp+1601,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__csr_wen) 
                                    & (((0xaffU < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr)) 
                                        & (0xb20U > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr))) 
                                       | ((0xb7fU < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr)) 
                                          & (0xba0U 
                                             > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr)))))
                                    ? ((IData)(1U) 
                                       << (0x1fU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr)))
                                    : 0U)),32);
        bufp->chgBit(oldp+1602,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mcountinhibit))));
        bufp->chgCData(oldp+1603,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_prv),3);
        bufp->chgBit(oldp+1604,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_trace_0_exception_output));
        bufp->chgBit(oldp+1605,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__cause 
                                               >> 0x3fU)))));
        bufp->chgQData(oldp+1606,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__cause),64);
        bufp->chgCData(oldp+1608,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_frm) 
                                    << 5U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_fflags))),8);
        bufp->chgQData(oldp+1609,((0x8000000000000000ULL 
                                   | (((QData)((IData)(
                                                       (0x14000300U 
                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_gva) 
                                                            << 0x1fU) 
                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_tsr) 
                                                               << 0xfU) 
                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_tw) 
                                                                  << 0xeU) 
                                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_tvm) 
                                                                     << 0xdU) 
                                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mxr) 
                                                                        << 0xcU) 
                                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_sum) 
                                                                           << 0xbU) 
                                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mprv) 
                                                                              << 0xaU) 
                                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_fs) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mpp) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_spp) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mpie)))))))))))))) 
                                       << 7U) | (QData)((IData)(
                                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_spie) 
                                                                  << 5U) 
                                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mie) 
                                                                     << 3U) 
                                                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_sie) 
                                                                       << 1U)))))))),64);
        bufp->chgQData(oldp+1611,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mie),64);
        bufp->chgQData(oldp+1613,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mscratch),64);
        bufp->chgQData(oldp+1615,((((QData)((IData)(
                                                    (0xffffffU 
                                                     & (- (IData)(
                                                                  (1U 
                                                                   & (~ (IData)(
                                                                                (1ULL 
                                                                                & (((~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mepc) 
                                                                                >> 0x27U) 
                                                                                | (0x1ffffffULL 
                                                                                & ((QData)((IData)(
                                                                                (1U 
                                                                                & (~ (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_misa 
                                                                                >> 2U)))))) 
                                                                                >> 0x26U)))))))))))) 
                                    << 0x28U) | (0xffffffffffULL 
                                                 & (~ 
                                                    (1ULL 
                                                     | ((~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mepc) 
                                                        | ((QData)((IData)(
                                                                           (1U 
                                                                            & (~ (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_misa 
                                                                                >> 2U)))))) 
                                                           << 1U))))))),64);
        bufp->chgQData(oldp+1617,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_3),64);
        bufp->chgQData(oldp+1619,((0x8000000200000000ULL 
                                   | (QData)((IData)(
                                                     (0x18000U 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mxr) 
                                                          << 0x13U) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_sum) 
                                                             << 0x12U) 
                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_fs) 
                                                                << 0xdU) 
                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_spp) 
                                                                   << 8U) 
                                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_spie) 
                                                                      << 5U) 
                                                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_sie) 
                                                                        << 1U))))))))))),64);
        bufp->chgQData(oldp+1621,((0x2222ULL & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mie 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mideleg))),64);
        bufp->chgQData(oldp+1623,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_sscratch),64);
        bufp->chgQData(oldp+1625,((((QData)((IData)(
                                                    (0xffffffU 
                                                     & (- (IData)(
                                                                  (1U 
                                                                   & (~ (IData)(
                                                                                (1ULL 
                                                                                & (((~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_sepc) 
                                                                                >> 0x27U) 
                                                                                | (0x1ffffffULL 
                                                                                & ((QData)((IData)(
                                                                                (1U 
                                                                                & (~ (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_misa 
                                                                                >> 2U)))))) 
                                                                                >> 0x26U)))))))))))) 
                                    << 0x28U) | (0xffffffffffULL 
                                                 & (~ 
                                                    (1ULL 
                                                     | ((~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_sepc) 
                                                        | ((QData)((IData)(
                                                                           (1U 
                                                                            & (~ (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_misa 
                                                                                >> 2U)))))) 
                                                           << 1U))))))),64);
        bufp->chgQData(oldp+1627,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_scause),64);
        bufp->chgQData(oldp+1629,((((QData)((IData)(
                                                    (0xffffffU 
                                                     & (- (IData)(
                                                                  (1U 
                                                                   & (IData)(
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_stval 
                                                                              >> 0x27U)))))))) 
                                    << 0x28U) | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_stval)),64);
        bufp->chgQData(oldp+1631,((0x2222ULL & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_3 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mideleg))),64);
        bufp->chgBit(oldp+1633,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__insn_break) 
                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_xcpt))));
        bufp->chgBit(oldp+1634,((0xcU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__checking_counter_memdelay))));
        bufp->chgCData(oldp+1635,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_fflags_shadow),5);
        bufp->chgCData(oldp+1636,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_frm_shadow),3);
        bufp->chgQData(oldp+1637,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_0),64);
        bufp->chgQData(oldp+1639,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_1),64);
        bufp->chgQData(oldp+1641,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_2),64);
        bufp->chgQData(oldp+1643,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_3),64);
        bufp->chgQData(oldp+1645,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_4),64);
        bufp->chgQData(oldp+1647,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_5),64);
        bufp->chgQData(oldp+1649,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_6),64);
        bufp->chgQData(oldp+1651,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_7),64);
        bufp->chgQData(oldp+1653,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_8),64);
        bufp->chgQData(oldp+1655,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_9),64);
        bufp->chgQData(oldp+1657,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_10),64);
        bufp->chgQData(oldp+1659,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_11),64);
        bufp->chgQData(oldp+1661,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_12),64);
        bufp->chgBit(oldp+1663,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__do_check));
        bufp->chgCData(oldp+1664,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__checking_counter),8);
        bufp->chgCData(oldp+1665,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__checking_counter_memdelay),8);
        bufp->chgCData(oldp+1666,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__shadow_status),2);
        __Vtemp_h428b18ee__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_0);
        __Vtemp_h428b18ee__0[1U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_0 
                                            >> 0x20U));
        __Vtemp_h428b18ee__0[2U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_1);
        __Vtemp_h428b18ee__0[3U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_1 
                                            >> 0x20U));
        __Vtemp_h428b18ee__0[4U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_2);
        __Vtemp_h428b18ee__0[5U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_2 
                                            >> 0x20U));
        __Vtemp_h428b18ee__0[6U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_3);
        __Vtemp_h428b18ee__0[7U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_3 
                                            >> 0x20U));
        __Vtemp_h428b18ee__0[8U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_4);
        __Vtemp_h428b18ee__0[9U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_4 
                                            >> 0x20U));
        __Vtemp_h428b18ee__0[0xaU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_5);
        __Vtemp_h428b18ee__0[0xbU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_5 
                                              >> 0x20U));
        __Vtemp_h428b18ee__0[0xcU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_6);
        __Vtemp_h428b18ee__0[0xdU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_6 
                                              >> 0x20U));
        __Vtemp_h428b18ee__0[0xeU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_7);
        __Vtemp_h428b18ee__0[0xfU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_7 
                                              >> 0x20U));
        __Vtemp_h428b18ee__0[0x10U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_8);
        __Vtemp_h428b18ee__0[0x11U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_8 
                                               >> 0x20U));
        __Vtemp_h428b18ee__0[0x12U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_9);
        __Vtemp_h428b18ee__0[0x13U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_9 
                                               >> 0x20U));
        __Vtemp_h428b18ee__0[0x14U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_10);
        __Vtemp_h428b18ee__0[0x15U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_10 
                                               >> 0x20U));
        __Vtemp_h428b18ee__0[0x16U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_11);
        __Vtemp_h428b18ee__0[0x17U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_11 
                                               >> 0x20U));
        __Vtemp_h428b18ee__0[0x18U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_12);
        __Vtemp_h428b18ee__0[0x19U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_12 
                                               >> 0x20U));
        __Vtemp_h428b18ee__0[0x1aU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_0);
        __Vtemp_h428b18ee__0[0x1bU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_0 
                                               >> 0x20U));
        __Vtemp_h428b18ee__0[0x1cU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_0);
        __Vtemp_h428b18ee__0[0x1dU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_0 
                                               >> 0x20U));
        __Vtemp_h428b18ee__0[0x1eU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_0);
        __Vtemp_h428b18ee__0[0x1fU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_0 
                                               >> 0x20U));
        bufp->chgBit(oldp+1667,((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_ECP_ext__DOT___GEN)
                                     ? ((0xcU >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_ECP_ext__DOT___GEN_0))
                                         ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_ECP_ext__DOT__Memory
                                        [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_ECP_ext__DOT___GEN_0]
                                         : 0ULL) : 0ULL) 
                                   != (((QData)((IData)(
                                                        __Vtemp_h428b18ee__0[
                                                        (((IData)(0x3fU) 
                                                          + 
                                                          (0x3c0U 
                                                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__checking_counter_memdelay) 
                                                              << 6U))) 
                                                         >> 5U)])) 
                                        << 0x20U) | (QData)((IData)(
                                                                    __Vtemp_h428b18ee__0[
                                                                    (0x1eU 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__checking_counter_memdelay) 
                                                                        << 1U))])))) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__do_check)) 
                                 & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__checking_counter)))));
        bufp->chgBit(oldp+1668,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_singleStepped));
        bufp->chgQData(oldp+1669,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mideleg),64);
        bufp->chgQData(oldp+1671,((0x2222ULL & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mideleg)),64);
        bufp->chgQData(oldp+1673,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_medeleg),64);
        bufp->chgQData(oldp+1675,((0xf0b55dULL & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_medeleg)),64);
        bufp->chgBit(oldp+1677,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mip_seip));
        bufp->chgBit(oldp+1678,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mip_stip));
        bufp->chgBit(oldp+1679,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mip_ssip));
        bufp->chgQData(oldp+1680,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mepc),40);
        bufp->chgQData(oldp+1682,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mcause),64);
        bufp->chgQData(oldp+1684,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mtval),40);
        bufp->chgIData(oldp+1686,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mtvec),32);
        bufp->chgIData(oldp+1687,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mcounteren),32);
        bufp->chgIData(oldp+1688,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_scounteren),32);
        bufp->chgQData(oldp+1689,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_sepc),40);
        bufp->chgQData(oldp+1691,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_stval),40);
        bufp->chgQData(oldp+1693,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_stvec),39);
        bufp->chgCData(oldp+1695,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_fflags),5);
        bufp->chgCData(oldp+1696,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_frm),3);
        bufp->chgCData(oldp+1697,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mcountinhibit),3);
        bufp->chgCData(oldp+1698,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__small_0),6);
        bufp->chgQData(oldp+1699,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__large_0),58);
        bufp->chgQData(oldp+1701,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__value),64);
        bufp->chgCData(oldp+1703,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__small_1),6);
        bufp->chgQData(oldp+1704,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__large_1),58);
        bufp->chgBit(oldp+1706,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mip_seip) 
                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink_3__DOT__chain__DOT__output_chain__DOT__sync_0))));
        bufp->chgQData(oldp+1707,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__pending_interrupts),64);
        bufp->chgQData(oldp+1709,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_misa),64);
        bufp->chgCData(oldp+1711,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_frm_shadow) 
                                    << 5U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_fflags_shadow))),8);
        bufp->chgSData(oldp+1712,((0xfffU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_addr)))),12);
        bufp->chgBit(oldp+1713,((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__csr__io_rw_cmd))));
        bufp->chgBit(oldp+1714,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__insn_call));
        bufp->chgBit(oldp+1715,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__insn_break));
        bufp->chgBit(oldp+1716,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__insn_ret));
        bufp->chgBit(oldp+1717,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__allow_sfence_vma));
        bufp->chgBit(oldp+1718,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__csr_exists));
        bufp->chgSData(oldp+1719,((0xfffU & (0x300U 
                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                >> 0x14U)))),12);
        bufp->chgQData(oldp+1720,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__notDebugTVec_base),64);
        bufp->chgQData(oldp+1722,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__check_exception)
                                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_pc
                                    : (((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__notDebugTVec_base 
                                                 & (0x8000000000000000ULL 
                                                    == 
                                                    (0x80000000000000c0ULL 
                                                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__cause))))
                                         ? ((0x3fffffffffffffc0ULL 
                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__notDebugTVec_base 
                                                >> 2U)) 
                                            | (QData)((IData)(
                                                              (0x3fU 
                                                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__cause)))))
                                         : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__notDebugTVec_base 
                                            >> 2U)) 
                                       << 2U))),64);
        bufp->chgCData(oldp+1724,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__pre_ret_prv),2);
        bufp->chgCData(oldp+1725,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__ret_prv),2);
        bufp->chgBit(oldp+1726,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__csr_wen) 
                                  & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1874) 
                                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1869)) 
                                     | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1864))) 
                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_1833))));
        bufp->chgBit(oldp+1727,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__set_fs_dirty_shadow));
        bufp->chgBit(oldp+1728,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__csr_wen));
        bufp->chgCData(oldp+1729,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__nextSmall_1),7);
        bufp->chgCData(oldp+1730,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__do_check)
                                    ? (0xfU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__checking_counter))
                                    : 0U)),4);
        bufp->chgQData(oldp+1731,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_ECP_ext__DOT___GEN)
                                    ? ((0xcU >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_ECP_ext__DOT___GEN_0))
                                        ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_ECP_ext__DOT__Memory
                                       [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_ECP_ext__DOT___GEN_0]
                                        : 0ULL) : 0ULL)),64);
        bufp->chgQData(oldp+1733,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_ECP_ext__DOT__Memory[0]),64);
        bufp->chgQData(oldp+1735,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_ECP_ext__DOT__Memory[1]),64);
        bufp->chgQData(oldp+1737,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_ECP_ext__DOT__Memory[2]),64);
        bufp->chgQData(oldp+1739,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_ECP_ext__DOT__Memory[3]),64);
        bufp->chgQData(oldp+1741,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_ECP_ext__DOT__Memory[4]),64);
        bufp->chgQData(oldp+1743,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_ECP_ext__DOT__Memory[5]),64);
        bufp->chgQData(oldp+1745,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_ECP_ext__DOT__Memory[6]),64);
        bufp->chgQData(oldp+1747,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_ECP_ext__DOT__Memory[7]),64);
        bufp->chgQData(oldp+1749,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_ECP_ext__DOT__Memory[8]),64);
        bufp->chgQData(oldp+1751,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_ECP_ext__DOT__Memory[9]),64);
        bufp->chgQData(oldp+1753,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_ECP_ext__DOT__Memory[10]),64);
        bufp->chgQData(oldp+1755,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_ECP_ext__DOT__Memory[11]),64);
        bufp->chgQData(oldp+1757,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_shadow_ECP_ext__DOT__Memory[12]),64);
        bufp->chgBit(oldp+1759,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___div_io_req_valid_T));
        bufp->chgBit(oldp+1760,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN));
        bufp->chgBit(oldp+1761,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__state))));
        bufp->chgBit(oldp+1762,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___io_resp_valid_output));
        bufp->chgQData(oldp+1763,((((QData)((IData)(
                                                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__req_dw)
                                                      ? (IData)(
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__result 
                                                                 >> 0x20U))
                                                      : 
                                                     (- (IData)(
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__loOut 
                                                                 >> 0x1fU)))))) 
                                    << 0x20U) | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__loOut)))),64);
        bufp->chgCData(oldp+1765,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__req_tag),5);
        bufp->chgCData(oldp+1766,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__state),3);
        bufp->chgBit(oldp+1767,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__req_dw));
        bufp->chgCData(oldp+1768,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__count),4);
        bufp->chgBit(oldp+1769,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__neg_out));
        bufp->chgBit(oldp+1770,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__isHi));
        bufp->chgBit(oldp+1771,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__resHi));
        bufp->chgWData(oldp+1772,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__divisor),65);
        bufp->chgWData(oldp+1775,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder),130);
        bufp->chgQData(oldp+1780,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__result),64);
        bufp->chgIData(oldp+1782,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__loOut),32);
        bufp->chgCData(oldp+1783,((0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___eOutPos_T_1)))),6);
        bufp->chgWData(oldp+1784,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__subtractor),65);
        bufp->chgBit(oldp+1787,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__divby0));
        bufp->chgCData(oldp+1788,((7U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_fn)))),3);
        bufp->chgBit(oldp+1789,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__lhs_sign));
        bufp->chgBit(oldp+1790,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__rhs_sign));
        bufp->chgBit(oldp+1791,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__eOut));
        __Vtemp_h1d35920d__0[0U] = (IData)((((QData)((IData)(
                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U])) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[0U]))));
        __Vtemp_h1d35920d__0[1U] = (IData)(((((QData)((IData)(
                                                              vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U])) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[0U]))) 
                                            >> 0x20U));
        __Vtemp_h1d35920d__0[2U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[3U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[2U] 
                                                  >> 1U));
        __Vtemp_h1d35920d__0[3U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[4U] 
                                     << 0x1fU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[3U] 
                                                  >> 1U));
        __Vtemp_h1d35920d__0[4U] = (1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[4U] 
                                          >> 1U));
        VL_SHIFTR_WWI(129,129,6, __Vtemp_h9a3b1cfe__0, __Vtemp_h1d35920d__0, 
                      (0x3fU & (- (0x38U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__count) 
                                            << 3U)))));
        __Vtemp_hd9f6050b__0[0U] = __Vtemp_h9a3b1cfe__0[0U];
        __Vtemp_hd9f6050b__0[1U] = __Vtemp_h9a3b1cfe__0[1U];
        __Vtemp_hd9f6050b__0[2U] = __Vtemp_h9a3b1cfe__0[2U];
        __Vtemp_hd9f6050b__0[3U] = __Vtemp_h9a3b1cfe__0[3U];
        __Vtemp_hd9f6050b__0[4U] = (1U & __Vtemp_h9a3b1cfe__0[4U]);
        bufp->chgWData(oldp+1792,(__Vtemp_hd9f6050b__0),129);
        bufp->chgQData(oldp+1797,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode))
                                    ? (((QData)((IData)(
                                                        (1U 
                                                         & (((0U 
                                                              == 
                                                              (0x1ffffffU 
                                                               & (IData)(
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_rs0 
                                                                          >> 0x27U)))) 
                                                             | (0x1ffffffU 
                                                                == 
                                                                (0x1ffffffU 
                                                                 & (IData)(
                                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_rs0 
                                                                            >> 0x27U)))))
                                                             ? (IData)(
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu_adder_out 
                                                                        >> 0x27U))
                                                             : 
                                                            (~ (IData)(
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu_adder_out 
                                                                        >> 0x26U))))))) 
                                        << 0x27U) | 
                                       (0x7fffffffffULL 
                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu_adder_out))
                                    : 0ULL)),40);
        bufp->chgQData(oldp+1799,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode))
                                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_req_data_T_3
                                    : 0ULL)),64);
        bufp->chgBit(oldp+1801,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT___GEN_0)))));
        bufp->chgQData(oldp+1802,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_io_resp_addr),40);
        bufp->chgQData(oldp+1804,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_io_resp_data),64);
        bufp->chgQData(oldp+1806,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__elu__io_wb_pc),40);
        bufp->chgBit(oldp+1808,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__u_channel__DOT__emptyReg)))));
        bufp->chgBit(oldp+1809,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__ld_valid_reg));
        bufp->chgBit(oldp+1810,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__st_valid));
        bufp->chgQData(oldp+1811,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__req_addr_reg),40);
        bufp->chgQData(oldp+1813,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__req_data_reg),64);
        bufp->chgCData(oldp+1815,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__size),2);
        bufp->chgQData(oldp+1816,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__req_data_wire),64);
        bufp->chgQData(oldp+1818,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__resp_data_wire),64);
        bufp->chgBit(oldp+1820,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__err_ld));
        bufp->chgBit(oldp+1821,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__err_st));
        if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__err_ld) {
            __Vtemp_hc3fbb1f4__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__req_addr_reg);
            __Vtemp_hc3fbb1f4__0[1U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_io_resp_addr) 
                                         << 8U) | (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__req_addr_reg 
                                                           >> 0x20U)));
            __Vtemp_hc3fbb1f4__0[2U] = (0x77770000U 
                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_io_resp_addr) 
                                            >> 0x18U) 
                                           | ((IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_io_resp_addr 
                                                       >> 0x20U)) 
                                              << 8U)));
            __Vtemp_hc3fbb1f4__0[3U] = 0x7777U;
            __Vtemp_hc3fbb1f4__0[4U] = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__resp_data_wire) 
                                        << 0x10U);
            __Vtemp_hc3fbb1f4__0[5U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__resp_data_wire) 
                                         >> 0x10U) 
                                        | ((IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__resp_data_wire 
                                                    >> 0x20U)) 
                                           << 0x10U));
            __Vtemp_hc3fbb1f4__0[6U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__elu__io_wb_pc) 
                                         << 0x10U) 
                                        | ((IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__resp_data_wire 
                                                    >> 0x20U)) 
                                           >> 0x10U));
            __Vtemp_hc3fbb1f4__0[7U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__elu__io_wb_pc) 
                                         >> 0x10U) 
                                        | ((IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__elu__io_wb_pc 
                                                    >> 0x20U)) 
                                           << 0x10U));
        } else if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__err_st) {
            __Vtemp_hc3fbb1f4__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__req_addr_reg);
            __Vtemp_hc3fbb1f4__0[1U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_io_resp_addr) 
                                         << 8U) | (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__req_addr_reg 
                                                           >> 0x20U)));
            __Vtemp_hc3fbb1f4__0[2U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__req_data_wire) 
                                         << 0x10U) 
                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_io_resp_addr) 
                                            >> 0x18U) 
                                           | ((IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_io_resp_addr 
                                                       >> 0x20U)) 
                                              << 8U)));
            __Vtemp_hc3fbb1f4__0[3U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__req_data_wire) 
                                         >> 0x10U) 
                                        | ((IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__req_data_wire 
                                                    >> 0x20U)) 
                                           << 0x10U));
            __Vtemp_hc3fbb1f4__0[4U] = (((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__req_data_wire 
                                                  >> 0x20U)) 
                                         >> 0x10U) 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__resp_data_wire) 
                                           << 0x10U));
            __Vtemp_hc3fbb1f4__0[5U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__resp_data_wire) 
                                         >> 0x10U) 
                                        | ((IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__resp_data_wire 
                                                    >> 0x20U)) 
                                           << 0x10U));
            __Vtemp_hc3fbb1f4__0[6U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__elu__io_wb_pc) 
                                         << 0x10U) 
                                        | ((IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__resp_data_wire 
                                                    >> 0x20U)) 
                                           >> 0x10U));
            __Vtemp_hc3fbb1f4__0[7U] = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__elu__io_wb_pc) 
                                         >> 0x10U) 
                                        | ((IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__elu__io_wb_pc 
                                                    >> 0x20U)) 
                                           << 0x10U));
        } else {
            __Vtemp_hc3fbb1f4__0[0U] = VTestHarness__ConstPool__CONST_h8692eb69_0[0U];
            __Vtemp_hc3fbb1f4__0[1U] = VTestHarness__ConstPool__CONST_h8692eb69_0[1U];
            __Vtemp_hc3fbb1f4__0[2U] = VTestHarness__ConstPool__CONST_h8692eb69_0[2U];
            __Vtemp_hc3fbb1f4__0[3U] = VTestHarness__ConstPool__CONST_h8692eb69_0[3U];
            __Vtemp_hc3fbb1f4__0[4U] = VTestHarness__ConstPool__CONST_h8692eb69_0[4U];
            __Vtemp_hc3fbb1f4__0[5U] = VTestHarness__ConstPool__CONST_h8692eb69_0[5U];
            __Vtemp_hc3fbb1f4__0[6U] = VTestHarness__ConstPool__CONST_h8692eb69_0[6U];
            __Vtemp_hc3fbb1f4__0[7U] = VTestHarness__ConstPool__CONST_h8692eb69_0[7U];
        }
        bufp->chgWData(oldp+1822,(__Vtemp_hc3fbb1f4__0),248);
        bufp->chgBit(oldp+1830,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT____Vcellinp__u_channel__io_enq_valid));
        bufp->chgBit(oldp+1831,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__u_channel__DOT__emptyReg));
        bufp->chgCData(oldp+1832,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__u_channel__DOT__readPtr),2);
        bufp->chgCData(oldp+1833,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__u_channel__DOT__writePtr),2);
        bufp->chgBit(oldp+1834,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__elu__DOT__u_channel__DOT__fullReg));
        bufp->chgQData(oldp+1835,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_pc),40);
        bufp->chgCData(oldp+1837,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT___T_23)
                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ibufBTBResp_cfiType)
                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_cfiType))),2);
        bufp->chgBit(oldp+1838,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT___T_23)
                                  ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ibufBTBResp_taken)
                                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_taken))));
        bufp->chgCData(oldp+1839,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT___T_23)
                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ibufBTBResp_mask)
                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_mask))),2);
        bufp->chgBit(oldp+1840,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT___T_23)
                                  ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ibufBTBResp_bridx)
                                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_bridx))));
        bufp->chgQData(oldp+1841,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT___T_23)
                                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ibufBTBResp_target
                                    : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_target)),39);
        bufp->chgCData(oldp+1843,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT___T_23)
                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ibufBTBResp_entry)
                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_entry))),5);
        bufp->chgCData(oldp+1844,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT___T_23)
                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ibufBTBResp_bht_history)
                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_bht_history))),8);
        bufp->chgBit(oldp+1845,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT___T_23)
                                  ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ibufBTBResp_bht_value)
                                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_bht_value))));
        bufp->chgBit(oldp+1846,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_xcpt0_pf_inst));
        bufp->chgBit(oldp+1847,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_xcpt0_gf_inst));
        bufp->chgBit(oldp+1848,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_xcpt0_ae_inst));
        bufp->chgBit(oldp+1849,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT___io_inst_0_bits_xcpt1_WIRE_1) 
                                       >> 2U))));
        bufp->chgBit(oldp+1850,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT___io_inst_0_bits_xcpt1_WIRE_1) 
                                       >> 1U))));
        bufp->chgBit(oldp+1851,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT___io_inst_0_bits_xcpt1_WIRE_1))));
        bufp->chgBit(oldp+1852,((3U != (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst))));
        bufp->chgCData(oldp+1853,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rd),5);
        bufp->chgCData(oldp+1854,((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                   >> 0x1bU)),5);
        bufp->chgIData(oldp+1855,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst),32);
        bufp->chgBit(oldp+1856,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__nBufValid));
        bufp->chgQData(oldp+1857,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__buf_pc),40);
        bufp->chgIData(oldp+1859,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__buf_data),32);
        bufp->chgBit(oldp+1860,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__buf_xcpt_pf_inst));
        bufp->chgBit(oldp+1861,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__buf_xcpt_gf_inst));
        bufp->chgBit(oldp+1862,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__buf_xcpt_ae_inst));
        bufp->chgBit(oldp+1863,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__buf_replay));
        bufp->chgCData(oldp+1864,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ibufBTBResp_cfiType),2);
        bufp->chgBit(oldp+1865,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ibufBTBResp_taken));
        bufp->chgCData(oldp+1866,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ibufBTBResp_mask),2);
        bufp->chgBit(oldp+1867,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ibufBTBResp_bridx));
        bufp->chgQData(oldp+1868,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ibufBTBResp_target),39);
        bufp->chgCData(oldp+1870,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ibufBTBResp_entry),5);
        bufp->chgCData(oldp+1871,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ibufBTBResp_bht_history),8);
        bufp->chgBit(oldp+1872,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ibufBTBResp_bht_value));
        bufp->chgBit(oldp+1873,((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_pc 
                                               >> 1U)))));
        bufp->chgCData(oldp+1874,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__nIC),2);
        bufp->chgCData(oldp+1875,((3U & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__nBufValid) 
                                          - (IData)(2U)) 
                                         - (1U & (IData)(
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_pc 
                                                          >> 1U)))))),2);
        VL_EXTEND_WQ(127,64, __Vtemp_hbb192ce2__0, 
                     (((QData)((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_data 
                                        >> 0x10U))) 
                       << 0x30U) | (((QData)((IData)(
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_data 
                                                      >> 0x10U))) 
                                     << 0x20U) | (((QData)((IData)(
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_data 
                                                                    >> 0x10U))) 
                                                   << 0x10U) 
                                                  | (QData)((IData)(
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_data 
                                                                     >> 0x10U)))))));
        __Vtemp_hbaa1852e__0[0U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_data)) 
                                             << 0x20U) 
                                            | (QData)((IData)(
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_data 
                                                                << 0x10U) 
                                                               | (0xffffU 
                                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_data))))));
        __Vtemp_hbaa1852e__0[1U] = (IData)(((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_data)) 
                                              << 0x20U) 
                                             | (QData)((IData)(
                                                               ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_data 
                                                                 << 0x10U) 
                                                                | (0xffffU 
                                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_data))))) 
                                            >> 0x20U));
        __Vtemp_hbaa1852e__0[2U] = __Vtemp_hbb192ce2__0[0U];
        __Vtemp_hbaa1852e__0[3U] = __Vtemp_hbb192ce2__0[1U];
        __Vtemp_hbaa1852e__0[4U] = __Vtemp_hbb192ce2__0[2U];
        __Vtemp_hbaa1852e__0[5U] = __Vtemp_hbb192ce2__0[3U];
        VL_EXTEND_WI(187,2, __Vtemp_h8d7a1f6d__0, (3U 
                                                   & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__nBufValid) 
                                                       - (IData)(2U)) 
                                                      - 
                                                      (1U 
                                                       & (IData)(
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_pc 
                                                                  >> 1U))))));
        __Vtemp_ha339f990__0[0U] = (__Vtemp_h8d7a1f6d__0[0U] 
                                    << 4U);
        __Vtemp_ha339f990__0[1U] = ((__Vtemp_h8d7a1f6d__0[0U] 
                                     >> 0x1cU) | (__Vtemp_h8d7a1f6d__0[1U] 
                                                  << 4U));
        __Vtemp_ha339f990__0[2U] = ((__Vtemp_h8d7a1f6d__0[1U] 
                                     >> 0x1cU) | (__Vtemp_h8d7a1f6d__0[2U] 
                                                  << 4U));
        __Vtemp_ha339f990__0[3U] = ((__Vtemp_h8d7a1f6d__0[2U] 
                                     >> 0x1cU) | (__Vtemp_h8d7a1f6d__0[3U] 
                                                  << 4U));
        __Vtemp_ha339f990__0[4U] = ((__Vtemp_h8d7a1f6d__0[3U] 
                                     >> 0x1cU) | (__Vtemp_h8d7a1f6d__0[4U] 
                                                  << 4U));
        __Vtemp_ha339f990__0[5U] = ((__Vtemp_h8d7a1f6d__0[4U] 
                                     >> 0x1cU) | (__Vtemp_h8d7a1f6d__0[5U] 
                                                  << 4U));
        VL_SHIFTL_WWW(191,191,191, __Vtemp_h8571e342__0, __Vtemp_hbaa1852e__0, __Vtemp_ha339f990__0);
        bufp->chgIData(oldp+1876,(__Vtemp_h8571e342__0[2U]),32);
        bufp->chgIData(oldp+1877,((IData)((0x7fffffffffffffffULL 
                                           & VL_SHIFTL_QQQ(63,63,63, 0xffffffffULL, 
                                                           ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__nBufValid)) 
                                                            << 4U))))),32);
        bufp->chgIData(oldp+1878,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst_checker),32);
        bufp->chgCData(oldp+1879,((3U & (((IData)(1U) 
                                          << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__nBufValid)) 
                                         - (IData)(1U)))),2);
        bufp->chgCData(oldp+1880,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__buf_replay_0),2);
        bufp->chgCData(oldp+1881,((8U | (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                               >> 2U)))),5);
        bufp->chgCData(oldp+1882,(((0U != (0x1fU & 
                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                                            >> 7U)))
                                    ? 3U : 0x1fU)),7);
        bufp->chgBit(oldp+1883,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__arf_paste_reg) 
                                 & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT____Vcellinp__cmdRouter__io_record_and_store_in)))));
        bufp->chgBit(oldp+1884,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__icsl__io_if_correct_process));
        bufp->chgBit(oldp+1885,((0x1fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay))));
        bufp->chgBit(oldp+1886,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__icsl__io_something_inflight));
        bufp->chgBit(oldp+1887,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_debug_perf_ctrl))));
        bufp->chgCData(oldp+1888,((0xfU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_debug_perf_ctrl) 
                                           >> 1U))),4);
        bufp->chgBit(oldp+1889,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__check_done));
        bufp->chgBit(oldp+1890,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__if_ret_special_pc));
        bufp->chgBit(oldp+1891,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___icsl_io_icsl_stalld));
        bufp->chgCData(oldp+1892,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__fsm_state),3);
        bufp->chgSData(oldp+1893,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__ic_counter_shadow),15);
        bufp->chgBit(oldp+1894,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__ic_counter_done));
        bufp->chgBit(oldp+1895,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__if_overtaking));
        bufp->chgBit(oldp+1896,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__if_overtaking_priv));
        bufp->chgCData(oldp+1897,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__self_xcpt_flag),3);
        bufp->chgCData(oldp+1898,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__self_eret_flag),3);
        bufp->chgSData(oldp+1899,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__sl_counter),16);
        bufp->chgCData(oldp+1900,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__fsm_state_delay),3);
        bufp->chgBit(oldp+1901,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__io_if_check_privret_REG));
        bufp->chgBit(oldp+1902,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__stall_checking));
        bufp->chgBit(oldp+1903,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__stall_postchecking));
        bufp->chgBit(oldp+1904,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__stall_checking_priv));
        bufp->chgBit(oldp+1905,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__stall_postchecking_priv));
        bufp->chgQData(oldp+1906,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_howmany_checkpoints),64);
        bufp->chgQData(oldp+1908,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_checking),64);
        bufp->chgQData(oldp+1910,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_postchecking),64);
        bufp->chgQData(oldp+1912,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_otherthread),64);
        bufp->chgQData(oldp+1914,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_nonchecking),64);
        bufp->chgQData(oldp+1916,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_CPStrans),64);
        bufp->chgBit(oldp+1918,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_CPStrans_ifGo));
        bufp->chgQData(oldp+1919,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_num_st),64);
        bufp->chgQData(oldp+1921,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_num_ld),64);
        bufp->chgQData(oldp+1923,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_L_timer_worest),64);
        bufp->chgQData(oldp+1925,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_L_timer),64);
        bufp->chgCData(oldp+1927,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_sel_delay),4);
        bufp->chgBit(oldp+1928,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT____Vcellinp__u_channel__io_enq_valid));
        bufp->chgIData(oldp+1929,((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_L_timer)),32);
        bufp->chgBit(oldp+1930,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT____Vcellinp__u_channel__io_deq_ready));
        bufp->chgIData(oldp+1931,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__u_channel__DOT__mem_ext__DOT___GEN)
                                    ? ((0x31U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__u_channel__DOT__mem_ext__DOT___GEN_0))
                                        ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__u_channel__DOT__mem_ext__DOT__Memory
                                       [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__u_channel__DOT__mem_ext__DOT___GEN_0]
                                        : 0U) : 0U)),32);
        bufp->chgCData(oldp+1932,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__u_channel__DOT__readPtr),6);
        bufp->chgCData(oldp+1933,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__u_channel__DOT__writePtr),6);
        bufp->chgBit(oldp+1934,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__u_channel__DOT__emptyReg));
        bufp->chgBit(oldp+1935,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__u_channel__DOT__fullReg));
        bufp->chgBit(oldp+1936,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__u_channel__DOT___T_4));
        bufp->chgBit(oldp+1937,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__u_channel__DOT___T_10));
        bufp->chgCData(oldp+1938,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode))
                                    ? ((0x3eU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                 >> 6U)) 
                                       | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_fp))
                                    : 0U)),8);
        bufp->chgBit(oldp+1939,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__lsl__io_req_valid_rocc));
        bufp->chgBit(oldp+1940,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT___io_near_full_output)))));
        bufp->chgBit(oldp+1941,((1U & (~ ((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_deq_ptr))
                                           ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__emptyReg)
                                           : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__emptyReg))))));
        bufp->chgBit(oldp+1942,((1U & (~ ((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_deq_ptr))
                                           ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__emptyReg)
                                           : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__emptyReg))))));
        bufp->chgBit(oldp+1943,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__resp_valid_reg));
        bufp->chgCData(oldp+1944,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__resp_tag),8);
        bufp->chgCData(oldp+1945,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__resp_valid_reg)
                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__req_size_reg)
                                    : 0U)),2);
        bufp->chgBit(oldp+1946,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__resp_valid_reg) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__cmd))));
        bufp->chgBit(oldp+1947,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_io_resp_replay));
        bufp->chgBit(oldp+1948,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT___io_near_full_output));
        bufp->chgQData(oldp+1949,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_deq_valid_0)
                                     ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_deq_data_0
                                     : 0ULL) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_deq_valid_1)
                                                 ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_deq_data_1
                                                 : 0ULL))),64);
        bufp->chgBit(oldp+1951,((IData)(((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__num_contentReg) 
                                             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__num_contentReg)) 
                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__num_contentReg)) 
                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__num_contentReg)) 
                                          >> 3U) | 
                                         ((0xeaU < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT__num_contentReg)) 
                                          | (0xeaU 
                                             < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT__num_contentReg)))))));
        bufp->chgBit(oldp+1952,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_deq_valid_1));
        bufp->chgBit(oldp+1953,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_deq_valid_0));
        bufp->chgCData(oldp+1954,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__lsl_enq_ptr),2);
        bufp->chgCData(oldp+1955,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__lsl_deq_ptr),2);
        bufp->chgWData(oldp+1956,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__enq_data_0),130);
        bufp->chgWData(oldp+1961,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__enq_data_1),130);
        bufp->chgBit(oldp+1966,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__enq_valid_0));
        bufp->chgBit(oldp+1967,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__enq_valid_1));
        bufp->chgCData(oldp+1968,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__enq_offset_0),2);
        bufp->chgCData(oldp+1969,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__enq_offset_1),2);
        bufp->chgBit(oldp+1970,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__enq_OH_0));
        bufp->chgBit(oldp+1971,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__enq_OH_1));
        bufp->chgBit(oldp+1972,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__enq_OH_0_1));
        bufp->chgBit(oldp+1973,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__enq_OH_1_1));
        if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT__mem_ext__DOT___GEN) {
            if ((0xfeU >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT__mem_ext__DOT___GEN_0))) {
                __Vtemp_h1084c790__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT__mem_ext__DOT__Memory
                    [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT__mem_ext__DOT___GEN_0][0U];
                __Vtemp_h1084c790__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT__mem_ext__DOT__Memory
                    [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT__mem_ext__DOT___GEN_0][1U];
                __Vtemp_h1084c790__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT__mem_ext__DOT__Memory
                    [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT__mem_ext__DOT___GEN_0][2U];
                __Vtemp_h1084c790__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT__mem_ext__DOT__Memory
                    [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT__mem_ext__DOT___GEN_0][3U];
                __Vtemp_h1084c790__0[4U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT__mem_ext__DOT__Memory
                    [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT__mem_ext__DOT___GEN_0][4U];
            } else {
                __Vtemp_h1084c790__0[0U] = 0U;
                __Vtemp_h1084c790__0[1U] = 0U;
                __Vtemp_h1084c790__0[2U] = 0U;
                __Vtemp_h1084c790__0[3U] = 0U;
                __Vtemp_h1084c790__0[4U] = 0U;
            }
        } else {
            __Vtemp_h1084c790__0[0U] = 0U;
            __Vtemp_h1084c790__0[1U] = 0U;
            __Vtemp_h1084c790__0[2U] = 0U;
            __Vtemp_h1084c790__0[3U] = 0U;
            __Vtemp_h1084c790__0[4U] = 0U;
        }
        bufp->chgWData(oldp+1974,(__Vtemp_h1084c790__0),130);
        if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT__mem_ext__DOT___GEN) {
            if ((0xfeU >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT__mem_ext__DOT___GEN_0))) {
                __Vtemp_h3ebd5f28__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT__mem_ext__DOT__Memory
                    [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT__mem_ext__DOT___GEN_0][0U];
                __Vtemp_h3ebd5f28__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT__mem_ext__DOT__Memory
                    [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT__mem_ext__DOT___GEN_0][1U];
                __Vtemp_h3ebd5f28__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT__mem_ext__DOT__Memory
                    [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT__mem_ext__DOT___GEN_0][2U];
                __Vtemp_h3ebd5f28__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT__mem_ext__DOT__Memory
                    [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT__mem_ext__DOT___GEN_0][3U];
                __Vtemp_h3ebd5f28__0[4U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT__mem_ext__DOT__Memory
                    [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT__mem_ext__DOT___GEN_0][4U];
            } else {
                __Vtemp_h3ebd5f28__0[0U] = 0U;
                __Vtemp_h3ebd5f28__0[1U] = 0U;
                __Vtemp_h3ebd5f28__0[2U] = 0U;
                __Vtemp_h3ebd5f28__0[3U] = 0U;
                __Vtemp_h3ebd5f28__0[4U] = 0U;
            }
        } else {
            __Vtemp_h3ebd5f28__0[0U] = 0U;
            __Vtemp_h3ebd5f28__0[1U] = 0U;
            __Vtemp_h3ebd5f28__0[2U] = 0U;
            __Vtemp_h3ebd5f28__0[3U] = 0U;
            __Vtemp_h3ebd5f28__0[4U] = 0U;
        }
        bufp->chgWData(oldp+1979,(__Vtemp_h3ebd5f28__0),130);
        bufp->chgBit(oldp+1984,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__req_valid_reg));
        bufp->chgBit(oldp+1985,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__resp_kill_reg));
        bufp->chgCData(oldp+1986,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__cmd),2);
        bufp->chgCData(oldp+1987,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__req_size_reg),2);
        bufp->chgBit(oldp+1988,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__out_packet_REG_0));
        bufp->chgBit(oldp+1989,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__out_packet_REG_1));
        bufp->chgWData(oldp+1990,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__out_packet),130);
        bufp->chgCData(oldp+1995,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_enq_ptr),2);
        bufp->chgCData(oldp+1996,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_deq_ptr),2);
        bufp->chgQData(oldp+1997,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_enq_data_0),64);
        bufp->chgQData(oldp+1999,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_enq_data_1),64);
        bufp->chgBit(oldp+2001,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_enq_valid_0));
        bufp->chgBit(oldp+2002,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_enq_valid_1));
        bufp->chgCData(oldp+2003,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_enq_offset_0),2);
        bufp->chgCData(oldp+2004,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_enq_offset_1),2);
        bufp->chgBit(oldp+2005,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_enq_OH_0));
        bufp->chgBit(oldp+2006,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_enq_OH_1));
        bufp->chgBit(oldp+2007,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_enq_OH_0_1));
        bufp->chgBit(oldp+2008,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_enq_OH_1_1));
        bufp->chgQData(oldp+2009,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_deq_data_0),64);
        bufp->chgQData(oldp+2011,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_deq_data_1),64);
        bufp->chgCData(oldp+2013,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_enq_ptr),2);
        bufp->chgCData(oldp+2014,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_deq_ptr),2);
        bufp->chgQData(oldp+2015,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_enq_data_0),64);
        bufp->chgQData(oldp+2017,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_enq_data_1),64);
        bufp->chgBit(oldp+2019,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_enq_valid_0));
        bufp->chgBit(oldp+2020,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_enq_valid_1));
        bufp->chgCData(oldp+2021,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_enq_offset_0),2);
        bufp->chgCData(oldp+2022,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_enq_offset_1),2);
        bufp->chgBit(oldp+2023,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_enq_OH_0));
        bufp->chgBit(oldp+2024,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_enq_OH_1));
        bufp->chgBit(oldp+2025,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_enq_OH_0_1));
        bufp->chgBit(oldp+2026,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_enq_OH_1_1));
        bufp->chgQData(oldp+2027,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_deq_data_0),64);
        bufp->chgQData(oldp+2029,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_deq_data_1),64);
        bufp->chgBit(oldp+2031,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT____Vcellinp__u_channel_0__io_enq_valid));
        bufp->chgWData(oldp+2032,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT____Vcellinp__u_channel_0__io_enq_bits),130);
        bufp->chgBit(oldp+2037,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT__emptyReg));
        bufp->chgBit(oldp+2038,((0xfcU < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT__num_contentReg))));
        bufp->chgBit(oldp+2039,((0xeaU < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT__num_contentReg))));
        bufp->chgCData(oldp+2040,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT__readPtr),8);
        bufp->chgCData(oldp+2041,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT__writePtr),8);
        bufp->chgBit(oldp+2042,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT__fullReg));
        bufp->chgCData(oldp+2043,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT__num_contentReg),8);
        bufp->chgBit(oldp+2044,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT____Vcellinp__u_channel_1__io_enq_valid));
        bufp->chgWData(oldp+2045,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT____Vcellinp__u_channel_1__io_enq_bits),130);
        bufp->chgBit(oldp+2050,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT__emptyReg));
        bufp->chgBit(oldp+2051,((0xfcU < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT__num_contentReg))));
        bufp->chgBit(oldp+2052,((0xeaU < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT__num_contentReg))));
        bufp->chgCData(oldp+2053,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT__readPtr),8);
        bufp->chgCData(oldp+2054,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT__writePtr),8);
        bufp->chgBit(oldp+2055,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT__fullReg));
        bufp->chgCData(oldp+2056,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT__num_contentReg),8);
        bufp->chgBit(oldp+2057,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT____Vcellinp__u_channel_csr_0__io_enq_valid));
        bufp->chgQData(oldp+2058,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT____Vcellinp__u_channel_csr_0__io_enq_bits),64);
        bufp->chgBit(oldp+2060,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__emptyReg));
        __Vtemp_hf5e842cb__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_0);
        __Vtemp_hf5e842cb__0[1U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_0 
                                            >> 0x20U));
        __Vtemp_hf5e842cb__0[2U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_1);
        __Vtemp_hf5e842cb__0[3U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_1 
                                            >> 0x20U));
        __Vtemp_hf5e842cb__0[4U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_2);
        __Vtemp_hf5e842cb__0[5U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_2 
                                            >> 0x20U));
        __Vtemp_hf5e842cb__0[6U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_3);
        __Vtemp_hf5e842cb__0[7U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_3 
                                            >> 0x20U));
        __Vtemp_hf5e842cb__0[8U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_4);
        __Vtemp_hf5e842cb__0[9U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_4 
                                            >> 0x20U));
        __Vtemp_hf5e842cb__0[0xaU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_5);
        __Vtemp_hf5e842cb__0[0xbU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_5 
                                              >> 0x20U));
        __Vtemp_hf5e842cb__0[0xcU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_6);
        __Vtemp_hf5e842cb__0[0xdU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_6 
                                              >> 0x20U));
        __Vtemp_hf5e842cb__0[0xeU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_7);
        __Vtemp_hf5e842cb__0[0xfU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_7 
                                              >> 0x20U));
        __Vtemp_hf5e842cb__0[0x10U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_8);
        __Vtemp_hf5e842cb__0[0x11U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_8 
                                               >> 0x20U));
        __Vtemp_hf5e842cb__0[0x12U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_9);
        __Vtemp_hf5e842cb__0[0x13U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_9 
                                               >> 0x20U));
        __Vtemp_hf5e842cb__0[0x14U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_10);
        __Vtemp_hf5e842cb__0[0x15U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_10 
                                               >> 0x20U));
        __Vtemp_hf5e842cb__0[0x16U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_0);
        __Vtemp_hf5e842cb__0[0x17U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_0 
                                               >> 0x20U));
        __Vtemp_hf5e842cb__0[0x18U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_0);
        __Vtemp_hf5e842cb__0[0x19U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_0 
                                               >> 0x20U));
        __Vtemp_hf5e842cb__0[0x1aU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_0);
        __Vtemp_hf5e842cb__0[0x1bU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_0 
                                               >> 0x20U));
        __Vtemp_hf5e842cb__0[0x1cU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_0);
        __Vtemp_hf5e842cb__0[0x1dU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_0 
                                               >> 0x20U));
        __Vtemp_hf5e842cb__0[0x1eU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_0);
        __Vtemp_hf5e842cb__0[0x1fU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_0 
                                               >> 0x20U));
        bufp->chgQData(oldp+2061,((((QData)((IData)(
                                                    __Vtemp_hf5e842cb__0[
                                                    (((IData)(0x3fU) 
                                                      + 
                                                      (0x3ffU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__readPtr) 
                                                          << 6U))) 
                                                     >> 5U)])) 
                                    << ((0U == (0x1fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__readPtr) 
                                                   << 6U)))
                                         ? 0x20U : 
                                        ((IData)(0x40U) 
                                         - (0x1fU & 
                                            ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__readPtr) 
                                             << 6U))))) 
                                   | (((0U == (0x1fU 
                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__readPtr) 
                                                  << 6U)))
                                        ? 0ULL : ((QData)((IData)(
                                                                  __Vtemp_hf5e842cb__0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x3ffU 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__readPtr) 
                                                                        << 6U))) 
                                                                   >> 5U)])) 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__readPtr) 
                                                       << 6U))))) 
                                      | ((QData)((IData)(
                                                         __Vtemp_hf5e842cb__0[
                                                         (0x1eU 
                                                          & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__readPtr) 
                                                             << 1U))])) 
                                         >> (0x1fU 
                                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__readPtr) 
                                                << 6U)))))),64);
        bufp->chgBit(oldp+2063,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__num_contentReg) 
                                       >> 3U))));
        bufp->chgBit(oldp+2064,((8U < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__num_contentReg))));
        bufp->chgQData(oldp+2065,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_0),64);
        bufp->chgQData(oldp+2067,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_1),64);
        bufp->chgQData(oldp+2069,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_2),64);
        bufp->chgQData(oldp+2071,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_3),64);
        bufp->chgQData(oldp+2073,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_4),64);
        bufp->chgQData(oldp+2075,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_5),64);
        bufp->chgQData(oldp+2077,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_6),64);
        bufp->chgQData(oldp+2079,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_7),64);
        bufp->chgQData(oldp+2081,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_8),64);
        bufp->chgQData(oldp+2083,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_9),64);
        bufp->chgQData(oldp+2085,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__memReg_10),64);
        bufp->chgCData(oldp+2087,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__readPtr),4);
        bufp->chgCData(oldp+2088,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__writePtr),4);
        bufp->chgBit(oldp+2089,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__fullReg));
        bufp->chgCData(oldp+2090,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__num_contentReg),4);
        bufp->chgBit(oldp+2091,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT____Vcellinp__u_channel_csr_1__io_enq_valid));
        bufp->chgQData(oldp+2092,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT____Vcellinp__u_channel_csr_1__io_enq_bits),64);
        bufp->chgBit(oldp+2094,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__emptyReg));
        __Vtemp_hb44432c5__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_0);
        __Vtemp_hb44432c5__0[1U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_0 
                                            >> 0x20U));
        __Vtemp_hb44432c5__0[2U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_1);
        __Vtemp_hb44432c5__0[3U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_1 
                                            >> 0x20U));
        __Vtemp_hb44432c5__0[4U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_2);
        __Vtemp_hb44432c5__0[5U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_2 
                                            >> 0x20U));
        __Vtemp_hb44432c5__0[6U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_3);
        __Vtemp_hb44432c5__0[7U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_3 
                                            >> 0x20U));
        __Vtemp_hb44432c5__0[8U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_4);
        __Vtemp_hb44432c5__0[9U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_4 
                                            >> 0x20U));
        __Vtemp_hb44432c5__0[0xaU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_5);
        __Vtemp_hb44432c5__0[0xbU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_5 
                                              >> 0x20U));
        __Vtemp_hb44432c5__0[0xcU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_6);
        __Vtemp_hb44432c5__0[0xdU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_6 
                                              >> 0x20U));
        __Vtemp_hb44432c5__0[0xeU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_7);
        __Vtemp_hb44432c5__0[0xfU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_7 
                                              >> 0x20U));
        __Vtemp_hb44432c5__0[0x10U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_8);
        __Vtemp_hb44432c5__0[0x11U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_8 
                                               >> 0x20U));
        __Vtemp_hb44432c5__0[0x12U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_9);
        __Vtemp_hb44432c5__0[0x13U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_9 
                                               >> 0x20U));
        __Vtemp_hb44432c5__0[0x14U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_10);
        __Vtemp_hb44432c5__0[0x15U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_10 
                                               >> 0x20U));
        __Vtemp_hb44432c5__0[0x16U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_0);
        __Vtemp_hb44432c5__0[0x17U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_0 
                                               >> 0x20U));
        __Vtemp_hb44432c5__0[0x18U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_0);
        __Vtemp_hb44432c5__0[0x19U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_0 
                                               >> 0x20U));
        __Vtemp_hb44432c5__0[0x1aU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_0);
        __Vtemp_hb44432c5__0[0x1bU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_0 
                                               >> 0x20U));
        __Vtemp_hb44432c5__0[0x1cU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_0);
        __Vtemp_hb44432c5__0[0x1dU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_0 
                                               >> 0x20U));
        __Vtemp_hb44432c5__0[0x1eU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_0);
        __Vtemp_hb44432c5__0[0x1fU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_0 
                                               >> 0x20U));
        bufp->chgQData(oldp+2095,((((QData)((IData)(
                                                    __Vtemp_hb44432c5__0[
                                                    (((IData)(0x3fU) 
                                                      + 
                                                      (0x3ffU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__readPtr) 
                                                          << 6U))) 
                                                     >> 5U)])) 
                                    << ((0U == (0x1fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__readPtr) 
                                                   << 6U)))
                                         ? 0x20U : 
                                        ((IData)(0x40U) 
                                         - (0x1fU & 
                                            ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__readPtr) 
                                             << 6U))))) 
                                   | (((0U == (0x1fU 
                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__readPtr) 
                                                  << 6U)))
                                        ? 0ULL : ((QData)((IData)(
                                                                  __Vtemp_hb44432c5__0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x3ffU 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__readPtr) 
                                                                        << 6U))) 
                                                                   >> 5U)])) 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__readPtr) 
                                                       << 6U))))) 
                                      | ((QData)((IData)(
                                                         __Vtemp_hb44432c5__0[
                                                         (0x1eU 
                                                          & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__readPtr) 
                                                             << 1U))])) 
                                         >> (0x1fU 
                                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__readPtr) 
                                                << 6U)))))),64);
        bufp->chgBit(oldp+2097,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__num_contentReg) 
                                       >> 3U))));
        bufp->chgBit(oldp+2098,((8U < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__num_contentReg))));
        bufp->chgQData(oldp+2099,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_0),64);
        bufp->chgQData(oldp+2101,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_1),64);
        bufp->chgQData(oldp+2103,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_2),64);
        bufp->chgQData(oldp+2105,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_3),64);
        bufp->chgQData(oldp+2107,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_4),64);
        bufp->chgQData(oldp+2109,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_5),64);
        bufp->chgQData(oldp+2111,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_6),64);
        bufp->chgQData(oldp+2113,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_7),64);
        bufp->chgQData(oldp+2115,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_8),64);
        bufp->chgQData(oldp+2117,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_9),64);
        bufp->chgQData(oldp+2119,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__memReg_10),64);
        bufp->chgCData(oldp+2121,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__readPtr),4);
        bufp->chgCData(oldp+2122,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__writePtr),4);
        bufp->chgBit(oldp+2123,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__fullReg));
        bufp->chgCData(oldp+2124,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__num_contentReg),4);
        bufp->chgBit(oldp+2125,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT____Vcellinp__u_channel_rocc_0__io_enq_valid));
        bufp->chgQData(oldp+2126,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT____Vcellinp__u_channel_rocc_0__io_enq_bits),64);
        bufp->chgBit(oldp+2128,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__emptyReg));
        __Vtemp_hae9f0cf3__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_0);
        __Vtemp_hae9f0cf3__0[1U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_0 
                                            >> 0x20U));
        __Vtemp_hae9f0cf3__0[2U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_1);
        __Vtemp_hae9f0cf3__0[3U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_1 
                                            >> 0x20U));
        __Vtemp_hae9f0cf3__0[4U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_2);
        __Vtemp_hae9f0cf3__0[5U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_2 
                                            >> 0x20U));
        __Vtemp_hae9f0cf3__0[6U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_3);
        __Vtemp_hae9f0cf3__0[7U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_3 
                                            >> 0x20U));
        __Vtemp_hae9f0cf3__0[8U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_4);
        __Vtemp_hae9f0cf3__0[9U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_4 
                                            >> 0x20U));
        __Vtemp_hae9f0cf3__0[0xaU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_5);
        __Vtemp_hae9f0cf3__0[0xbU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_5 
                                              >> 0x20U));
        __Vtemp_hae9f0cf3__0[0xcU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_6);
        __Vtemp_hae9f0cf3__0[0xdU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_6 
                                              >> 0x20U));
        __Vtemp_hae9f0cf3__0[0xeU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_7);
        __Vtemp_hae9f0cf3__0[0xfU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_7 
                                              >> 0x20U));
        __Vtemp_hae9f0cf3__0[0x10U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_8);
        __Vtemp_hae9f0cf3__0[0x11U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_8 
                                               >> 0x20U));
        __Vtemp_hae9f0cf3__0[0x12U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_9);
        __Vtemp_hae9f0cf3__0[0x13U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_9 
                                               >> 0x20U));
        __Vtemp_hae9f0cf3__0[0x14U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_10);
        __Vtemp_hae9f0cf3__0[0x15U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_10 
                                               >> 0x20U));
        __Vtemp_hae9f0cf3__0[0x16U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_0);
        __Vtemp_hae9f0cf3__0[0x17U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_0 
                                               >> 0x20U));
        __Vtemp_hae9f0cf3__0[0x18U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_0);
        __Vtemp_hae9f0cf3__0[0x19U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_0 
                                               >> 0x20U));
        __Vtemp_hae9f0cf3__0[0x1aU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_0);
        __Vtemp_hae9f0cf3__0[0x1bU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_0 
                                               >> 0x20U));
        __Vtemp_hae9f0cf3__0[0x1cU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_0);
        __Vtemp_hae9f0cf3__0[0x1dU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_0 
                                               >> 0x20U));
        __Vtemp_hae9f0cf3__0[0x1eU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_0);
        __Vtemp_hae9f0cf3__0[0x1fU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_0 
                                               >> 0x20U));
        bufp->chgQData(oldp+2129,((((QData)((IData)(
                                                    __Vtemp_hae9f0cf3__0[
                                                    (((IData)(0x3fU) 
                                                      + 
                                                      (0x3ffU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__readPtr) 
                                                          << 6U))) 
                                                     >> 5U)])) 
                                    << ((0U == (0x1fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__readPtr) 
                                                   << 6U)))
                                         ? 0x20U : 
                                        ((IData)(0x40U) 
                                         - (0x1fU & 
                                            ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__readPtr) 
                                             << 6U))))) 
                                   | (((0U == (0x1fU 
                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__readPtr) 
                                                  << 6U)))
                                        ? 0ULL : ((QData)((IData)(
                                                                  __Vtemp_hae9f0cf3__0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x3ffU 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__readPtr) 
                                                                        << 6U))) 
                                                                   >> 5U)])) 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__readPtr) 
                                                       << 6U))))) 
                                      | ((QData)((IData)(
                                                         __Vtemp_hae9f0cf3__0[
                                                         (0x1eU 
                                                          & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__readPtr) 
                                                             << 1U))])) 
                                         >> (0x1fU 
                                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__readPtr) 
                                                << 6U)))))),64);
        bufp->chgBit(oldp+2131,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__num_contentReg) 
                                       >> 3U))));
        bufp->chgBit(oldp+2132,((8U < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__num_contentReg))));
        bufp->chgQData(oldp+2133,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_0),64);
        bufp->chgQData(oldp+2135,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_1),64);
        bufp->chgQData(oldp+2137,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_2),64);
        bufp->chgQData(oldp+2139,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_3),64);
        bufp->chgQData(oldp+2141,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_4),64);
        bufp->chgQData(oldp+2143,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_5),64);
        bufp->chgQData(oldp+2145,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_6),64);
        bufp->chgQData(oldp+2147,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_7),64);
        bufp->chgQData(oldp+2149,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_8),64);
        bufp->chgQData(oldp+2151,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_9),64);
        bufp->chgQData(oldp+2153,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__memReg_10),64);
        bufp->chgCData(oldp+2155,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__readPtr),4);
        bufp->chgCData(oldp+2156,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__writePtr),4);
        bufp->chgBit(oldp+2157,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__fullReg));
        bufp->chgCData(oldp+2158,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__num_contentReg),4);
        bufp->chgBit(oldp+2159,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT____Vcellinp__u_channel_rocc_1__io_enq_valid));
        bufp->chgQData(oldp+2160,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT____Vcellinp__u_channel_rocc_1__io_enq_bits),64);
        bufp->chgBit(oldp+2162,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__emptyReg));
        __Vtemp_h5ef10458__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_0);
        __Vtemp_h5ef10458__0[1U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_0 
                                            >> 0x20U));
        __Vtemp_h5ef10458__0[2U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_1);
        __Vtemp_h5ef10458__0[3U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_1 
                                            >> 0x20U));
        __Vtemp_h5ef10458__0[4U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_2);
        __Vtemp_h5ef10458__0[5U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_2 
                                            >> 0x20U));
        __Vtemp_h5ef10458__0[6U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_3);
        __Vtemp_h5ef10458__0[7U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_3 
                                            >> 0x20U));
        __Vtemp_h5ef10458__0[8U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_4);
        __Vtemp_h5ef10458__0[9U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_4 
                                            >> 0x20U));
        __Vtemp_h5ef10458__0[0xaU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_5);
        __Vtemp_h5ef10458__0[0xbU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_5 
                                              >> 0x20U));
        __Vtemp_h5ef10458__0[0xcU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_6);
        __Vtemp_h5ef10458__0[0xdU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_6 
                                              >> 0x20U));
        __Vtemp_h5ef10458__0[0xeU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_7);
        __Vtemp_h5ef10458__0[0xfU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_7 
                                              >> 0x20U));
        __Vtemp_h5ef10458__0[0x10U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_8);
        __Vtemp_h5ef10458__0[0x11U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_8 
                                               >> 0x20U));
        __Vtemp_h5ef10458__0[0x12U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_9);
        __Vtemp_h5ef10458__0[0x13U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_9 
                                               >> 0x20U));
        __Vtemp_h5ef10458__0[0x14U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_10);
        __Vtemp_h5ef10458__0[0x15U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_10 
                                               >> 0x20U));
        __Vtemp_h5ef10458__0[0x16U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_0);
        __Vtemp_h5ef10458__0[0x17U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_0 
                                               >> 0x20U));
        __Vtemp_h5ef10458__0[0x18U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_0);
        __Vtemp_h5ef10458__0[0x19U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_0 
                                               >> 0x20U));
        __Vtemp_h5ef10458__0[0x1aU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_0);
        __Vtemp_h5ef10458__0[0x1bU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_0 
                                               >> 0x20U));
        __Vtemp_h5ef10458__0[0x1cU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_0);
        __Vtemp_h5ef10458__0[0x1dU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_0 
                                               >> 0x20U));
        __Vtemp_h5ef10458__0[0x1eU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_0);
        __Vtemp_h5ef10458__0[0x1fU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_0 
                                               >> 0x20U));
        bufp->chgQData(oldp+2163,((((QData)((IData)(
                                                    __Vtemp_h5ef10458__0[
                                                    (((IData)(0x3fU) 
                                                      + 
                                                      (0x3ffU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__readPtr) 
                                                          << 6U))) 
                                                     >> 5U)])) 
                                    << ((0U == (0x1fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__readPtr) 
                                                   << 6U)))
                                         ? 0x20U : 
                                        ((IData)(0x40U) 
                                         - (0x1fU & 
                                            ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__readPtr) 
                                             << 6U))))) 
                                   | (((0U == (0x1fU 
                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__readPtr) 
                                                  << 6U)))
                                        ? 0ULL : ((QData)((IData)(
                                                                  __Vtemp_h5ef10458__0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x3ffU 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__readPtr) 
                                                                        << 6U))) 
                                                                   >> 5U)])) 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__readPtr) 
                                                       << 6U))))) 
                                      | ((QData)((IData)(
                                                         __Vtemp_h5ef10458__0[
                                                         (0x1eU 
                                                          & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__readPtr) 
                                                             << 1U))])) 
                                         >> (0x1fU 
                                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__readPtr) 
                                                << 6U)))))),64);
        bufp->chgBit(oldp+2165,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__num_contentReg) 
                                       >> 3U))));
        bufp->chgBit(oldp+2166,((8U < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__num_contentReg))));
        bufp->chgQData(oldp+2167,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_0),64);
        bufp->chgQData(oldp+2169,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_1),64);
        bufp->chgQData(oldp+2171,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_2),64);
        bufp->chgQData(oldp+2173,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_3),64);
        bufp->chgQData(oldp+2175,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_4),64);
        bufp->chgQData(oldp+2177,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_5),64);
        bufp->chgQData(oldp+2179,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_6),64);
        bufp->chgQData(oldp+2181,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_7),64);
        bufp->chgQData(oldp+2183,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_8),64);
        bufp->chgQData(oldp+2185,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_9),64);
        bufp->chgQData(oldp+2187,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__memReg_10),64);
        bufp->chgCData(oldp+2189,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__readPtr),4);
        bufp->chgCData(oldp+2190,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__writePtr),4);
        bufp->chgBit(oldp+2191,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__fullReg));
        bufp->chgCData(oldp+2192,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__num_contentReg),4);
        bufp->chgCData(oldp+2193,((0x1fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1)))),5);
        bufp->chgCData(oldp+2194,((0x1fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2)))),5);
        bufp->chgCData(oldp+2195,((0x1fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))),5);
        bufp->chgBit(oldp+2196,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out) 
                                 & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_idx_out)))));
        bufp->chgQData(oldp+2197,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_out),64);
        bufp->chgBit(oldp+2199,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_258));
        bufp->chgQData(oldp+2200,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rf_sp),64);
        bufp->chgQData(oldp+2202,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rf_gp),64);
        bufp->chgBit(oldp+2204,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_6));
        bufp->chgQData(oldp+2205,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rf_ext_R0_data),64);
        bufp->chgQData(oldp+2207,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rf_ext_R1_data),64);
        bufp->chgQData(oldp+2209,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [0x15U]),64);
        bufp->chgQData(oldp+2211,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [0x14U]),64);
        bufp->chgQData(oldp+2213,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [0x13U]),64);
        bufp->chgQData(oldp+2215,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [0x12U]),64);
        bufp->chgQData(oldp+2217,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [0x11U]),64);
        bufp->chgQData(oldp+2219,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [0x10U]),64);
        bufp->chgQData(oldp+2221,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [0xfU]),64);
        bufp->chgQData(oldp+2223,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [0xeU]),64);
        bufp->chgQData(oldp+2225,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [0xdU]),64);
        bufp->chgQData(oldp+2227,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [0xcU]),64);
        bufp->chgQData(oldp+2229,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [0x1eU]),64);
        bufp->chgQData(oldp+2231,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [0xbU]),64);
        bufp->chgQData(oldp+2233,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [0xaU]),64);
        bufp->chgQData(oldp+2235,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [9U]),64);
        bufp->chgQData(oldp+2237,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [8U]),64);
        bufp->chgQData(oldp+2239,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [7U]),64);
        bufp->chgQData(oldp+2241,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [6U]),64);
        bufp->chgQData(oldp+2243,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [5U]),64);
        bufp->chgQData(oldp+2245,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [4U]),64);
        bufp->chgQData(oldp+2247,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [3U]),64);
        bufp->chgQData(oldp+2249,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [2U]),64);
        bufp->chgQData(oldp+2251,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [0x1dU]),64);
        bufp->chgQData(oldp+2253,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [1U]),64);
        bufp->chgQData(oldp+2255,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [0U]),64);
        bufp->chgQData(oldp+2257,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [0x1cU]),64);
        bufp->chgQData(oldp+2259,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [0x1bU]),64);
        bufp->chgQData(oldp+2261,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [0x1aU]),64);
        bufp->chgQData(oldp+2263,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [0x19U]),64);
        bufp->chgQData(oldp+2265,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [0x18U]),64);
        bufp->chgQData(oldp+2267,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [0x17U]),64);
        bufp->chgQData(oldp+2269,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory
                                  [0x16U]),64);
        bufp->chgQData(oldp+2271,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[0]),64);
        bufp->chgQData(oldp+2273,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[1]),64);
        bufp->chgQData(oldp+2275,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[2]),64);
        bufp->chgQData(oldp+2277,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[3]),64);
        bufp->chgQData(oldp+2279,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[4]),64);
        bufp->chgQData(oldp+2281,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[5]),64);
        bufp->chgQData(oldp+2283,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[6]),64);
        bufp->chgQData(oldp+2285,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[7]),64);
        bufp->chgQData(oldp+2287,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[8]),64);
        bufp->chgQData(oldp+2289,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[9]),64);
        bufp->chgQData(oldp+2291,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[10]),64);
        bufp->chgQData(oldp+2293,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[11]),64);
        bufp->chgQData(oldp+2295,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[12]),64);
        bufp->chgQData(oldp+2297,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[13]),64);
        bufp->chgQData(oldp+2299,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[14]),64);
        bufp->chgQData(oldp+2301,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[15]),64);
        bufp->chgQData(oldp+2303,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[16]),64);
        bufp->chgQData(oldp+2305,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[17]),64);
        bufp->chgQData(oldp+2307,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[18]),64);
        bufp->chgQData(oldp+2309,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[19]),64);
        bufp->chgQData(oldp+2311,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[20]),64);
        bufp->chgQData(oldp+2313,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[21]),64);
        bufp->chgQData(oldp+2315,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[22]),64);
        bufp->chgQData(oldp+2317,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[23]),64);
        bufp->chgQData(oldp+2319,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[24]),64);
        bufp->chgQData(oldp+2321,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[25]),64);
        bufp->chgQData(oldp+2323,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[26]),64);
        bufp->chgQData(oldp+2325,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[27]),64);
        bufp->chgQData(oldp+2327,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[28]),64);
        bufp->chgQData(oldp+2329,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[29]),64);
        bufp->chgQData(oldp+2331,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_ext__DOT__Memory[30]),64);
        bufp->chgBit(oldp+2333,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode))));
        bufp->chgBit(oldp+2334,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__arf_paste_reg) 
                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__check_exception))));
        bufp->chgBit(oldp+2335,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__check_done) 
                                  & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rsu_status))) 
                                 & (~ ((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__state)) 
                                       | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_fpu_inflight))))));
        bufp->chgBit(oldp+2336,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT____Vcellinp__cmdRouter__io_record_and_store_in) 
                                       >> 1U))));
        bufp->chgBit(oldp+2337,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT____Vcellinp__cmdRouter__io_record_and_store_in))));
        bufp->chgQData(oldp+2338,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__pcarfs_ss),40);
        bufp->chgBit(oldp+2340,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_core_hang_up));
        bufp->chgBit(oldp+2341,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__packet_valid) 
                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__packet_valid_ECP))));
        bufp->chgBit(oldp+2342,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__u_channel__DOT__emptyReg)))));
        bufp->chgCData(oldp+2343,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__rsu_status),2);
        bufp->chgBit(oldp+2344,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__packet_valid));
        bufp->chgCData(oldp+2345,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__packet_index),8);
        bufp->chgQData(oldp+2346,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__packet_arfs),64);
        bufp->chgQData(oldp+2348,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__packet_farfs),64);
        bufp->chgBit(oldp+2350,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__recording_context));
        bufp->chgCData(oldp+2351,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__recording_counter),7);
        bufp->chgBit(oldp+2352,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__packet_valid_ECP));
        bufp->chgCData(oldp+2353,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__packet_index_ECP),8);
        bufp->chgQData(oldp+2354,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__packet_arfs_ECP),64);
        bufp->chgQData(oldp+2356,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__packet_farfs_ECP),64);
        bufp->chgBit(oldp+2358,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__has_ECP));
        bufp->chgBit(oldp+2359,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__det_fall_REG));
        bufp->chgBit(oldp+2360,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__apply_snapshot));
        bufp->chgBit(oldp+2361,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__apply_snapshot_memdelay));
        bufp->chgCData(oldp+2362,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__apply_counter),8);
        bufp->chgCData(oldp+2363,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__apply_counter_memdelay),8);
        bufp->chgBit(oldp+2364,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__do_check));
        bufp->chgCData(oldp+2365,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter),8);
        bufp->chgQData(oldp+2366,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farf_data),64);
        bufp->chgBit(oldp+2368,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__excpt));
        bufp->chgBit(oldp+2369,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__eret));
        bufp->chgCData(oldp+2370,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay),8);
        bufp->chgCData(oldp+2371,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__do_check)
                                    ? (0x3fU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter))
                                    : 0U)),6);
        bufp->chgCData(oldp+2372,((0x3fU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__packet_index_ECP))),6);
        bufp->chgBit(oldp+2373,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___T_25) 
                                 & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__packet_index_ECP)))));
        bufp->chgQData(oldp+2374,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ECP_ext__DOT___GEN)
                                    ? ((0x20U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ECP_ext__DOT___GEN_0))
                                        ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ECP_ext__DOT__Memory
                                       [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ECP_ext__DOT___GEN_0]
                                        : 0ULL) : 0ULL)),64);
        bufp->chgCData(oldp+2376,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___arf_data_T_3),6);
        bufp->chgCData(oldp+2377,((0x3fU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__recording_counter))),6);
        bufp->chgQData(oldp+2378,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_GMode_ext__DOT___GEN)
                                    ? ((0x20U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_GMode_ext__DOT___GEN_0))
                                        ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_GMode_ext__DOT__Memory
                                       [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_GMode_ext__DOT___GEN_0]
                                        : 0ULL) : 0ULL)),64);
        bufp->chgQData(oldp+2380,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_GMode_ext__DOT___GEN_1)
                                    ? ((0x20U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_GMode_ext__DOT___GEN_2))
                                        ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_GMode_ext__DOT__Memory
                                       [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_GMode_ext__DOT___GEN_2]
                                        : 0ULL) : 0ULL)),64);
        bufp->chgQData(oldp+2382,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_GMode_ext__DOT___GEN_3)
                                    ? ((0x20U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_GMode_ext__DOT___GEN_4))
                                        ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_GMode_ext__DOT__Memory
                                       [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_GMode_ext__DOT___GEN_4]
                                        : 0ULL) : 0ULL)),64);
        bufp->chgCData(oldp+2384,((0x3fU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__packet_index))),6);
        bufp->chgQData(oldp+2385,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ext__DOT___GEN)
                                    ? ((0x20U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ext__DOT___GEN_0))
                                        ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ext__DOT__Memory
                                       [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ext__DOT___GEN_0]
                                        : 0ULL) : 0ULL)),64);
        bufp->chgQData(oldp+2387,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ext__DOT___GEN_1)
                                    ? ((0x20U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ext__DOT___GEN_2))
                                        ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ext__DOT__Memory
                                       [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ext__DOT___GEN_2]
                                        : 0ULL) : 0ULL)),64);
        bufp->chgQData(oldp+2389,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ext__DOT___GEN_3)
                                    ? ((0x20U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ext__DOT___GEN_4))
                                        ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ext__DOT__Memory
                                       [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ext__DOT___GEN_4]
                                        : 0ULL) : 0ULL)),64);
        bufp->chgCData(oldp+2391,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__apply_snapshot)
                                    ? (0x3fU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__apply_counter))
                                    : 0U)),6);
        bufp->chgQData(oldp+2392,(((0x20U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram_R_0_addr_pipe_0))
                                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram
                                   [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram_R_0_addr_pipe_0]
                                    : 0ULL)),64);
        bufp->chgBit(oldp+2394,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram_R_0_en_pipe_0));
        bufp->chgCData(oldp+2395,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram_R_0_addr_pipe_0),6);
        bufp->chgBit(oldp+2396,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___T_25));
        bufp->chgQData(oldp+2397,(((0x20U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss_ECP__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram_R_0_addr_pipe_0))
                                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss_ECP__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram
                                   [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss_ECP__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram_R_0_addr_pipe_0]
                                    : 0ULL)),64);
        bufp->chgBit(oldp+2399,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss_ECP__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram_R_0_en_pipe_0));
        bufp->chgCData(oldp+2400,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss_ECP__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram_R_0_addr_pipe_0),6);
        bufp->chgQData(oldp+2401,((((QData)((IData)(
                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN_0[
                                                    (((IData)(0x3fU) 
                                                      + 
                                                      (0x7c0U 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__recording_counter) 
                                                          << 6U))) 
                                                     >> 5U)])) 
                                    << 0x20U) | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN_0[
                                                                (0x3eU 
                                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__recording_counter) 
                                                                    << 1U))])))),64);
        bufp->chgQData(oldp+2403,(((0x20U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss_GMode__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram_R_0_addr_pipe_0))
                                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss_GMode__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram
                                   [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss_GMode__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram_R_0_addr_pipe_0]
                                    : 0ULL)),64);
        bufp->chgBit(oldp+2405,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss_GMode__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram_R_0_en_pipe_0));
        bufp->chgCData(oldp+2406,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss_GMode__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram_R_0_addr_pipe_0),6);
        bufp->chgBit(oldp+2407,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__u_channel__DOT__emptyReg));
        bufp->chgBit(oldp+2408,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__u_channel__DOT__readPtr));
        bufp->chgBit(oldp+2409,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__u_channel__DOT__writePtr));
        bufp->chgBit(oldp+2410,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__u_channel__DOT__fullReg));
        bufp->chgBit(oldp+2411,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__u_channel__DOT__readPtr)) 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__u_channel__DOT__readPtr) 
                                          - (IData)(1U))))));
        bufp->chgBit(oldp+2412,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__u_channel__DOT__nextWrite));
        bufp->chgBit(oldp+2413,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_requestor_1_resp_valid));
        bufp->chgBit(oldp+2414,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output));
        bufp->chgQData(oldp+2415,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output)
                                    ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                        ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_addr
                                        : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_addr)
                                    : 0ULL)),40);
        bufp->chgCData(oldp+2417,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT___req_arb_io_out_bits_tag),8);
        bufp->chgCData(oldp+2418,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output)
                                    ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                        ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_cmd)
                                        : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_cmd))
                                    : 0U)),5);
        bufp->chgCData(oldp+2419,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output)
                                    ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                        ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_size)
                                        : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_size))
                                    : 0U)),2);
        bufp->chgBit(oldp+2420,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output) 
                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                     ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_signed)
                                     : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_signed)))));
        bufp->chgCData(oldp+2421,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output)
                                    ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                        ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_dprv)
                                        : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_dprv))
                                    : 0U)),2);
        bufp->chgBit(oldp+2422,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output) 
                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                     ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_dv)
                                     : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_dv)))));
        bufp->chgBit(oldp+2423,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output) 
                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                     ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_phys)
                                     : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_phys)))));
        bufp->chgBit(oldp+2424,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output) 
                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                     ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_no_alloc)
                                     : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_no_alloc)))));
        bufp->chgBit(oldp+2425,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output) 
                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                     ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_no_xcpt)
                                     : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_no_xcpt)))));
        bufp->chgCData(oldp+2426,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output)
                                    ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                        ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_mask)
                                        : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_mask))
                                    : 0U)),8);
        bufp->chgQData(oldp+2427,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__io_cache_s1_data_data_r),64);
        bufp->chgBit(oldp+2429,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__s1_req_fire));
        bufp->chgBit(oldp+2430,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__s2_req_fire));
        bufp->chgCData(oldp+2431,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__s1_req_tag),8);
        bufp->chgCData(oldp+2432,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__s2_req_tag),8);
        bufp->chgBit(oldp+2433,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__REG));
        bufp->chgCData(oldp+2434,((0x3fU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__s2_req_tag))),6);
        bufp->chgQData(oldp+2435,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_addr
                                    : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_addr)),40);
        bufp->chgCData(oldp+2437,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___GEN),8);
        bufp->chgCData(oldp+2438,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_cmd)
                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_cmd))),5);
        bufp->chgCData(oldp+2439,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_size)
                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_size))),2);
        bufp->chgBit(oldp+2440,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                  ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_signed)
                                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_signed))));
        bufp->chgCData(oldp+2441,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_dprv)
                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_dprv))),2);
        bufp->chgBit(oldp+2442,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                  ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_dv)
                                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_dv))));
        bufp->chgBit(oldp+2443,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                  ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_phys)
                                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_phys))));
        bufp->chgBit(oldp+2444,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                  ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_no_alloc)
                                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_no_alloc))));
        bufp->chgBit(oldp+2445,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                  ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_no_xcpt)
                                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_no_xcpt))));
        bufp->chgQData(oldp+2446,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_data
                                    : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_data)),64);
        bufp->chgCData(oldp+2448,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_mask)
                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_mask))),8);
        bufp->chgCData(oldp+2449,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__inflight),2);
        bufp->chgBit(oldp+2450,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__replaying));
        bufp->chgBit(oldp+2451,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__replay_complete));
        bufp->chgCData(oldp+2452,(((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__inflight))
                                    ? (2U & ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__inflight) 
                                                 >> 1U)) 
                                             << 1U))
                                    : 1U)),2);
        bufp->chgBit(oldp+2453,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_tag) 
                                  == (0x3fU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__s2_req_tag))) 
                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__inflight) 
                                    >> 1U))));
        bufp->chgBit(oldp+2454,((1U & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__ptr_match) 
                                          & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__maybe_full))))));
        bufp->chgBit(oldp+2455,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__empty)))));
        bufp->chgBit(oldp+2456,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits));
        bufp->chgBit(oldp+2457,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__enq_ptr_value));
        bufp->chgBit(oldp+2458,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__deq_ptr_value));
        bufp->chgBit(oldp+2459,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__maybe_full));
        bufp->chgBit(oldp+2460,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__ptr_match));
        bufp->chgBit(oldp+2461,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__empty));
        bufp->chgBit(oldp+2462,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__ptr_match) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__maybe_full))));
        bufp->chgBit(oldp+2463,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__do_deq));
        bufp->chgBit(oldp+2464,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__ram_ext__DOT__Memory[0]));
        bufp->chgBit(oldp+2465,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__ram_ext__DOT__Memory[1]));
        bufp->chgQData(oldp+2466,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output)
                                    ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                        ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_data
                                        : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_data)
                                    : 0ULL)),64);
        bufp->chgBit(oldp+2468,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                       >> 9U))));
        bufp->chgBit(oldp+2469,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_mem_req_valid));
        bufp->chgQData(oldp+2470,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_mem_req_bits_addr),40);
        bufp->chgCData(oldp+2472,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___ptw_io_mem_req_valid)
                                    ? 0U : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output)
                                             ? (1U 
                                                | (0xfcU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT___req_arb_io_out_bits_tag) 
                                                      << 2U)))
                                             : (2U 
                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                                                     | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode))
                                                     ? 0U
                                                     : 
                                                    ((0x3eU 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                         >> 6U)) 
                                                     | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_fp))) 
                                                   << 2U))))),8);
        bufp->chgCData(oldp+2473,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_mem_req_bits_cmd),5);
        bufp->chgCData(oldp+2474,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_mem_req_bits_size),2);
        bufp->chgBit(oldp+2475,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___ptw_io_mem_req_valid)) 
                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output)
                                           ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output) 
                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                                  ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_signed)
                                                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_signed)))
                                           : ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                                                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode))) 
                                              & (~ 
                                                 ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_hls)
                                                   ? 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                   >> 0x14U)
                                                   : 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                   >> 0xeU)))))))));
        bufp->chgCData(oldp+2476,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_mem_req_bits_dprv),2);
        bufp->chgBit(oldp+2477,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___ptw_io_mem_req_valid)
                                  ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__do_both_stages) 
                                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__stage2)))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output)
                                      ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output) 
                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                             ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_dv)
                                             : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_dv)))
                                      : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___io_dmem_req_bits_dv_output)))));
        bufp->chgBit(oldp+2478,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_mem_req_bits_phys));
        bufp->chgBit(oldp+2479,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___ptw_io_mem_req_valid)) 
                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output) 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                        ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_no_alloc)
                                        : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_no_alloc))))));
        bufp->chgBit(oldp+2480,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___ptw_io_mem_req_valid)) 
                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output) 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                        ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_no_xcpt)
                                        : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_no_xcpt))))));
        bufp->chgCData(oldp+2481,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___ptw_io_mem_req_valid)
                                    ? 0U : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output)
                                             ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output)
                                                 ? 
                                                ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                                                  ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_mask)
                                                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_mask))
                                                 : 0U)
                                             : 0U))),8);
        bufp->chgQData(oldp+2482,(((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT__s1_id))
                                    ? 0ULL : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT__s1_id))
                                               ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__io_cache_s1_data_data_r
                                               : (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode))
                                                   ? 0ULL
                                                   : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_req_data_T_3)))),64);
        bufp->chgBit(oldp+2484,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___arb_io_out_ready_T_2));
        bufp->chgBit(oldp+2485,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_valid_0));
        bufp->chgBit(oldp+2486,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_ae_ptw));
        bufp->chgBit(oldp+2487,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_ae_final));
        bufp->chgBit(oldp+2488,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_pf));
        bufp->chgBit(oldp+2489,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_gf));
        bufp->chgBit(oldp+2490,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hr));
        bufp->chgBit(oldp+2491,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hw));
        bufp->chgBit(oldp+2492,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__resp_hx));
        bufp->chgQData(oldp+2493,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn),44);
        bufp->chgBit(oldp+2495,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_d));
        bufp->chgBit(oldp+2496,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_a));
        bufp->chgBit(oldp+2497,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_g));
        bufp->chgBit(oldp+2498,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_u));
        bufp->chgBit(oldp+2499,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_x));
        bufp->chgBit(oldp+2500,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_w));
        bufp->chgBit(oldp+2501,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_r));
        bufp->chgBit(oldp+2502,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_v));
        bufp->chgCData(oldp+2503,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__max_count),2);
        bufp->chgBit(oldp+2504,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__homogeneous));
        bufp->chgBit(oldp+2505,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_valid));
        bufp->chgCData(oldp+2506,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode),3);
        bufp->chgCData(oldp+2507,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_param),3);
        bufp->chgCData(oldp+2508,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size),4);
        bufp->chgBit(oldp+2509,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_source));
        bufp->chgIData(oldp+2510,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_address),32);
        bufp->chgCData(oldp+2511,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_mask),8);
        bufp->chgQData(oldp+2512,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_uncached) 
                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_write)) 
                                    & (((((((((((0x11U 
                                                 == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd)) 
                                                | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_read))) 
                                               | (0xfU 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                                              | (0xeU 
                                                 == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                                             | (0xdU 
                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                                            | (0xcU 
                                               == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                                           | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                                          | (0xbU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                                         | (0xaU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                                        | (9U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                                       | (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))))
                                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_data
                                    : 0ULL)),64);
        bufp->chgBit(oldp+2514,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_source));
        bufp->chgBit(oldp+2515,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcache_io_cpu_resp_valid));
        bufp->chgCData(oldp+2516,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_tag),8);
        bufp->chgBit(oldp+2517,((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_state))));
        bufp->chgIData(oldp+2518,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag),27);
        bufp->chgBit(oldp+2519,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_need_gpa));
        bufp->chgBit(oldp+2520,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_vstage1_en));
        bufp->chgBit(oldp+2521,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_stage2_en));
        bufp->chgCData(oldp+2522,((0x1fU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__flushCounter))),5);
        bufp->chgIData(oldp+2523,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___T_320)
                                      ? 0U : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_12)
                                               ? 2U
                                               : ((1U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___T_125))
                                                   ? 1U
                                                   : 
                                                  ((0U 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___T_125))
                                                    ? 0U
                                                    : 
                                                   (((7U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___T_125)) 
                                                     | (6U 
                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___T_125))) 
                                                    | (5U 
                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___T_125))))))) 
                                    << 0x15U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_address 
                                                 >> 0xbU))),23);
        bufp->chgBit(oldp+2524,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_in_4_valid));
        bufp->chgCData(oldp+2525,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__releaseWay),2);
        bufp->chgCData(oldp+2526,((0x1fU & ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__release_state))
                                             ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_address 
                                                >> 6U)
                                             : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                 << 0x11U) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                                                   >> 0xfU))))),5);
        bufp->chgCData(oldp+2527,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_valid)
                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_mask)
                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_mask))),8);
        bufp->chgQData(oldp+2528,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_valid)
                                    ? (((QData)((IData)(
                                                        (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_7) 
                                                          << 0x18U) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_6) 
                                                             << 0x10U) 
                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_5) 
                                                                << 8U) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_4)))))) 
                                        << 0x20U) | (QData)((IData)(
                                                                    (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_3) 
                                                                      << 0x18U) 
                                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_2) 
                                                                         << 0x10U) 
                                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_1) 
                                                                            << 8U) 
                                                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r)))))))
                                    : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_data)),64);
        bufp->chgCData(oldp+2530,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_valid)
                                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_way)
                                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_way))),2);
        bufp->chgSData(oldp+2531,((0x7ffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_valid)
                                              ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_addr)
                                              : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_addr)))),11);
        bufp->chgBit(oldp+2532,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_in_0_valid));
        bufp->chgBit(oldp+2533,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__dataArb_io_in_0_bits_write));
        bufp->chgIData(oldp+2534,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_in_2_bits_data_meta_coh_state) 
                                    << 0x15U) | (0x1fffffU 
                                                 & (IData)(
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_addr 
                                                            >> 0xbU))))),23);
        bufp->chgIData(oldp+2535,(((((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_meta_uncorrectable_errors))
                                      ? 0U : (3U & 
                                              ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_meta_correctable_errors_r)
                                                ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_meta_corrected_r 
                                                   >> 0x15U)
                                                : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_meta_corrected_r_1 
                                                   >> 0x15U)))) 
                                    << 0x15U) | (0x1fffffU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_meta_correctable_errors_r)
                                                     ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_meta_corrected_r
                                                     : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_meta_corrected_r_1)))),23);
        bufp->chgCData(oldp+2536,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_in_1_bits_idx),5);
        bufp->chgCData(oldp+2537,((0x1fU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_addr 
                                                    >> 6U)))),5);
        bufp->chgCData(oldp+2538,((0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_address 
                                            >> 6U))),5);
        bufp->chgCData(oldp+2539,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_meta_uncorrectable_errors) 
                                   | ((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_meta_uncorrectable_errors))
                                       ? 0U : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_meta_correctable_errors_r)
                                                ? 1U
                                                : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_meta_correctable_errors_r_1) 
                                                   << 1U))))),2);
        bufp->chgBit(oldp+2540,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_in_1_valid));
        bufp->chgBit(oldp+2541,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_in_2_valid));
        bufp->chgCData(oldp+2542,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_in_2_bits_way_en),2);
        bufp->chgQData(oldp+2543,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_addr),40);
        bufp->chgCData(oldp+2545,((0x1fU & (IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_mem_req_bits_addr 
                                                    >> 6U)))),5);
        bufp->chgSData(oldp+2546,((0x7ffU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_mem_req_bits_addr))),11);
        bufp->chgBit(oldp+2547,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_mem_req_valid) 
                                 & (~ ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_mem_req_bits_cmd)) 
                                       | (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_mem_req_bits_cmd)))))));
        bufp->chgCData(oldp+2548,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__refill_way),2);
        bufp->chgBit(oldp+2549,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__resetting));
        bufp->chgCData(oldp+2550,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_prv),2);
        bufp->chgBit(oldp+2551,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_passthrough));
        bufp->chgQData(oldp+2552,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_vaddr),40);
        bufp->chgQData(oldp+2554,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_req_addr),40);
        bufp->chgIData(oldp+2556,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_tag_vpn),27);
        bufp->chgBit(oldp+2557,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_tag_v));
        bufp->chgQData(oldp+2558,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_data_0),41);
        bufp->chgQData(oldp+2560,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_data_1),41);
        bufp->chgQData(oldp+2562,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_data_2),41);
        bufp->chgQData(oldp+2564,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_data_3),41);
        bufp->chgBit(oldp+2566,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_0));
        bufp->chgBit(oldp+2567,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_1));
        bufp->chgBit(oldp+2568,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_2));
        bufp->chgBit(oldp+2569,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_3));
        bufp->chgCData(oldp+2570,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_0_level),2);
        bufp->chgIData(oldp+2571,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_0_tag_vpn),27);
        bufp->chgBit(oldp+2572,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_0_tag_v));
        bufp->chgQData(oldp+2573,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_0_data_0),41);
        bufp->chgBit(oldp+2575,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_0_valid_0));
        bufp->chgCData(oldp+2576,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_1_level),2);
        bufp->chgIData(oldp+2577,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_1_tag_vpn),27);
        bufp->chgBit(oldp+2578,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_1_tag_v));
        bufp->chgQData(oldp+2579,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_1_data_0),41);
        bufp->chgBit(oldp+2581,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_1_valid_0));
        bufp->chgCData(oldp+2582,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_2_level),2);
        bufp->chgIData(oldp+2583,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_2_tag_vpn),27);
        bufp->chgBit(oldp+2584,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_2_tag_v));
        bufp->chgQData(oldp+2585,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_2_data_0),41);
        bufp->chgBit(oldp+2587,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_2_valid_0));
        bufp->chgCData(oldp+2588,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_3_level),2);
        bufp->chgIData(oldp+2589,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_3_tag_vpn),27);
        bufp->chgBit(oldp+2590,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_3_tag_v));
        bufp->chgQData(oldp+2591,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_3_data_0),41);
        bufp->chgBit(oldp+2593,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_3_valid_0));
        bufp->chgCData(oldp+2594,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_special_entry_level),2);
        bufp->chgIData(oldp+2595,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_special_entry_tag_vpn),27);
        bufp->chgBit(oldp+2596,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_special_entry_tag_v));
        bufp->chgQData(oldp+2597,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_special_entry_data_0),41);
        bufp->chgBit(oldp+2599,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_special_entry_valid_0));
        bufp->chgCData(oldp+2600,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_state),2);
        bufp->chgCData(oldp+2601,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_superpage_repl_addr),2);
        bufp->chgBit(oldp+2602,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_sectored_hit_valid));
        bufp->chgBit(oldp+2603,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_vm_enabled));
        bufp->chgBit(oldp+2604,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_special_entry_level))));
        bufp->chgIData(oldp+2605,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_mpu_ppn),28);
        bufp->chgCData(oldp+2606,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_mpu_priv),3);
        bufp->chgIData(oldp+2607,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb___05Fsector_hits_T_4),25);
        bufp->chgBit(oldp+2608,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_0_level))));
        bufp->chgBit(oldp+2609,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_1_level))));
        bufp->chgBit(oldp+2610,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_2_level))));
        bufp->chgBit(oldp+2611,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_3_level))));
        bufp->chgBit(oldp+2612,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_hitsVec_0));
        bufp->chgBit(oldp+2613,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_hitsVec_1));
        bufp->chgBit(oldp+2614,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_hitsVec_2));
        bufp->chgBit(oldp+2615,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_hitsVec_3));
        bufp->chgBit(oldp+2616,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_hitsVec_4));
        bufp->chgIData(oldp+2617,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb___05FhitsVec_T_66),27);
        bufp->chgBit(oldp+2618,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_hitsVec_5));
        bufp->chgCData(oldp+2619,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_real_hits),6);
        bufp->chgQData(oldp+2620,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb___05Fentries_WIRE_1),41);
        bufp->chgIData(oldp+2622,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_ppn),20);
        bufp->chgBit(oldp+2623,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_bad_va));
        bufp->chgBit(oldp+2624,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_tlb_miss));
        bufp->chgCData(oldp+2625,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_state_reg_1),3);
        bufp->chgBit(oldp+2626,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_multipleHits_rightOne_1));
        bufp->chgBit(oldp+2627,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_multipleHits_rightOne_3));
        bufp->chgBit(oldp+2628,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_multipleHits));
        bufp->chgBit(oldp+2629,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_state))));
        bufp->chgBit(oldp+2630,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_valid));
        bufp->chgBit(oldp+2631,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_probe));
        bufp->chgCData(oldp+2632,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_param),2);
        bufp->chgCData(oldp+2633,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_size),4);
        bufp->chgCData(oldp+2634,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_req_tag),8);
        bufp->chgCData(oldp+2635,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_req_cmd),5);
        bufp->chgCData(oldp+2636,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_req_size),2);
        bufp->chgBit(oldp+2637,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_req_signed));
        bufp->chgCData(oldp+2638,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_req_dprv),2);
        bufp->chgBit(oldp+2639,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_req_dv));
        bufp->chgBit(oldp+2640,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_req_no_alloc));
        bufp->chgBit(oldp+2641,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_req_no_xcpt));
        bufp->chgCData(oldp+2642,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_req_mask),8);
        bufp->chgCData(oldp+2643,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_size),2);
        bufp->chgCData(oldp+2644,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd),5);
        bufp->chgBit(oldp+2645,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_read));
        bufp->chgBit(oldp+2646,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_write));
        bufp->chgBit(oldp+2647,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_sfence));
        bufp->chgBit(oldp+2648,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__cached_grant_wait));
        bufp->chgCData(oldp+2649,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__flushCounter),6);
        bufp->chgBit(oldp+2650,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__release_ack_wait));
        bufp->chgIData(oldp+2651,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__release_ack_addr),32);
        bufp->chgCData(oldp+2652,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__release_state),4);
        bufp->chgBit(oldp+2653,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__inWriteback));
        bufp->chgBit(oldp+2654,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__uncachedInFlight_0));
        bufp->chgQData(oldp+2655,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__uncachedReqs_0_addr),40);
        bufp->chgCData(oldp+2657,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__uncachedReqs_0_tag),8);
        bufp->chgCData(oldp+2658,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__uncachedReqs_0_size),2);
        bufp->chgBit(oldp+2659,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__uncachedReqs_0_signed));
        bufp->chgBit(oldp+2660,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_did_read));
        bufp->chgBit(oldp+2661,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_read_mask));
        bufp->chgBit(oldp+2662,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_cmd_uses_tlb));
        bufp->chgCData(oldp+2663,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_hit_way),2);
        bufp->chgCData(oldp+2664,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_mask_xwr),8);
        bufp->chgBit(oldp+2665,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid));
        bufp->chgBit(oldp+2666,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_no_xcpt));
        bufp->chgBit(oldp+2667,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_probe));
        bufp->chgBit(oldp+2668,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__releaseInFlight));
        bufp->chgBit(oldp+2669,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_not_nacked_in_s1));
        bufp->chgBit(oldp+2670,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_masked));
        bufp->chgBit(oldp+2671,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_no_alloc));
        bufp->chgBit(oldp+2672,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_no_xcpt));
        bufp->chgBit(oldp+2673,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_tlb_xcpt_pf_ld));
        bufp->chgBit(oldp+2674,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_tlb_xcpt_pf_st));
        bufp->chgBit(oldp+2675,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_tlb_xcpt_gf_ld));
        bufp->chgBit(oldp+2676,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_tlb_xcpt_gf_st));
        bufp->chgBit(oldp+2677,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_tlb_xcpt_ae_ld));
        bufp->chgBit(oldp+2678,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_tlb_xcpt_ae_st));
        bufp->chgBit(oldp+2679,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_tlb_xcpt_ma_ld));
        bufp->chgBit(oldp+2680,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_tlb_xcpt_ma_st));
        bufp->chgBit(oldp+2681,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_pma_cacheable));
        bufp->chgBit(oldp+2682,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_pma_must_alloc));
        bufp->chgQData(oldp+2683,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_uncached_resp_addr),40);
        bufp->chgQData(oldp+2685,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_vaddr_r),40);
        bufp->chgBit(oldp+2687,((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))));
        bufp->chgBit(oldp+2688,((7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))));
        bufp->chgBit(oldp+2689,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_write));
        bufp->chgBit(oldp+2690,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_readwrite));
        bufp->chgBit(oldp+2691,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_meta_correctable_errors_r));
        bufp->chgBit(oldp+2692,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_meta_correctable_errors_r_1));
        bufp->chgBit(oldp+2693,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_meta_uncorrectable_errors_r));
        bufp->chgBit(oldp+2694,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_meta_uncorrectable_errors_r_1));
        bufp->chgCData(oldp+2695,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_meta_uncorrectable_errors),2);
        bufp->chgIData(oldp+2696,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_meta_corrected_r),23);
        bufp->chgIData(oldp+2697,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_meta_corrected_r_1),23);
        bufp->chgCData(oldp+2698,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_probe_way),2);
        bufp->chgCData(oldp+2699,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_probe_state_state),2);
        bufp->chgCData(oldp+2700,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_hit_way),2);
        bufp->chgCData(oldp+2701,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_hit_state_state),2);
        bufp->chgBit(oldp+2702,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_waw_hazard));
        bufp->chgBit(oldp+2703,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_hit));
        bufp->chgCData(oldp+2704,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_in_2_bits_data_meta_coh_state),2);
        bufp->chgBit(oldp+2705,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_hit_maybe_flush_pre_data_ecc_and_waw));
        bufp->chgBit(oldp+2706,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_hit_pre_data_ecc_and_waw));
        bufp->chgBit(oldp+2707,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_flush_line));
        bufp->chgBit(oldp+2708,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_hit_pre_data_ecc));
        bufp->chgBit(oldp+2709,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_miss));
        bufp->chgBit(oldp+2710,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_uncached));
        bufp->chgBit(oldp+2711,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_cached_miss));
        bufp->chgBit(oldp+2712,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_victimize));
        bufp->chgBit(oldp+2713,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_uncached_pending));
        bufp->chgBit(oldp+2714,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_victim_way_r));
        bufp->chgCData(oldp+2715,((3U & ((IData)(1U) 
                                         << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_victim_way_r)))),2);
        bufp->chgCData(oldp+2716,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_victim_state_state),2);
        bufp->chgBit(oldp+2717,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_prb_ack_data));
        bufp->chgBit(oldp+2718,((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_victim_state_state))));
        bufp->chgCData(oldp+2719,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__lrscCount),7);
        bufp->chgQData(oldp+2720,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__lrscAddr),34);
        bufp->chgBit(oldp+2722,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_sc_fail));
        bufp->chgCData(oldp+2723,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_cmd),5);
        bufp->chgQData(oldp+2724,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_addr),40);
        bufp->chgCData(oldp+2726,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_way),2);
        bufp->chgCData(oldp+2727,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_mask),8);
        bufp->chgBit(oldp+2728,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_rmw_r));
        bufp->chgBit(oldp+2729,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_valid));
        bufp->chgBit(oldp+2730,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore_drain_on_miss_REG));
        bufp->chgBit(oldp+2731,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_held));
        bufp->chgBit(oldp+2732,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_valid_likely));
        bufp->chgBit(oldp+2733,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___pstore1_held_T) 
                                  & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_sc_fail))) 
                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_held))));
        bufp->chgBit(oldp+2734,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore_drain_structural));
        bufp->chgQData(oldp+2735,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_addr),40);
        bufp->chgCData(oldp+2737,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_way),2);
        bufp->chgCData(oldp+2738,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r),8);
        bufp->chgCData(oldp+2739,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_1),8);
        bufp->chgCData(oldp+2740,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_2),8);
        bufp->chgCData(oldp+2741,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_3),8);
        bufp->chgCData(oldp+2742,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_4),8);
        bufp->chgCData(oldp+2743,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_5),8);
        bufp->chgCData(oldp+2744,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_6),8);
        bufp->chgCData(oldp+2745,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_data_r_7),8);
        bufp->chgCData(oldp+2746,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_mask),8);
        bufp->chgBit(oldp+2747,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_raw_hazard));
        bufp->chgBit(oldp+2748,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_s2_nack_cause_raw_REG));
        bufp->chgBit(oldp+2749,((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_size))));
        bufp->chgBit(oldp+2750,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__get_a_mask_acc));
        bufp->chgBit(oldp+2751,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__get_a_mask_acc_1));
        bufp->chgBit(oldp+2752,((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_size))));
        bufp->chgBit(oldp+2753,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__get_a_mask_eq_2));
        bufp->chgBit(oldp+2754,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__get_a_mask_acc_2));
        bufp->chgBit(oldp+2755,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__get_a_mask_eq_3));
        bufp->chgBit(oldp+2756,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__get_a_mask_acc_3));
        bufp->chgBit(oldp+2757,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__get_a_mask_eq_4));
        bufp->chgBit(oldp+2758,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__get_a_mask_acc_4));
        bufp->chgBit(oldp+2759,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__get_a_mask_eq_5));
        bufp->chgBit(oldp+2760,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__get_a_mask_acc_5));
        bufp->chgBit(oldp+2761,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__put_a_mask_acc));
        bufp->chgBit(oldp+2762,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__put_a_mask_acc_1));
        bufp->chgBit(oldp+2763,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__put_a_mask_eq_2));
        bufp->chgBit(oldp+2764,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__put_a_mask_acc_2));
        bufp->chgBit(oldp+2765,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__put_a_mask_eq_3));
        bufp->chgBit(oldp+2766,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__put_a_mask_acc_3));
        bufp->chgBit(oldp+2767,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__put_a_mask_eq_4));
        bufp->chgBit(oldp+2768,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__put_a_mask_acc_4));
        bufp->chgBit(oldp+2769,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__put_a_mask_eq_5));
        bufp->chgBit(oldp+2770,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__put_a_mask_acc_5));
        bufp->chgBit(oldp+2771,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc));
        bufp->chgBit(oldp+2772,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_1));
        bufp->chgBit(oldp+2773,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_2));
        bufp->chgBit(oldp+2774,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_2));
        bufp->chgBit(oldp+2775,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_3));
        bufp->chgBit(oldp+2776,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_3));
        bufp->chgBit(oldp+2777,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_4));
        bufp->chgBit(oldp+2778,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_4));
        bufp->chgBit(oldp+2779,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_5));
        bufp->chgBit(oldp+2780,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_5));
        bufp->chgBit(oldp+2781,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_14));
        bufp->chgBit(oldp+2782,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_15));
        bufp->chgBit(oldp+2783,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_16));
        bufp->chgBit(oldp+2784,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_16));
        bufp->chgBit(oldp+2785,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_17));
        bufp->chgBit(oldp+2786,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_17));
        bufp->chgBit(oldp+2787,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_18));
        bufp->chgBit(oldp+2788,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_18));
        bufp->chgBit(oldp+2789,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_19));
        bufp->chgBit(oldp+2790,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_19));
        bufp->chgBit(oldp+2791,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_28));
        bufp->chgBit(oldp+2792,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_29));
        bufp->chgBit(oldp+2793,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_30));
        bufp->chgBit(oldp+2794,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_30));
        bufp->chgBit(oldp+2795,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_31));
        bufp->chgBit(oldp+2796,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_31));
        bufp->chgBit(oldp+2797,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_32));
        bufp->chgBit(oldp+2798,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_32));
        bufp->chgBit(oldp+2799,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_33));
        bufp->chgBit(oldp+2800,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_33));
        bufp->chgBit(oldp+2801,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_42));
        bufp->chgBit(oldp+2802,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_43));
        bufp->chgBit(oldp+2803,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_44));
        bufp->chgBit(oldp+2804,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_44));
        bufp->chgBit(oldp+2805,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_45));
        bufp->chgBit(oldp+2806,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_45));
        bufp->chgBit(oldp+2807,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_46));
        bufp->chgBit(oldp+2808,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_46));
        bufp->chgBit(oldp+2809,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_47));
        bufp->chgBit(oldp+2810,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_47));
        bufp->chgBit(oldp+2811,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_56));
        bufp->chgBit(oldp+2812,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_57));
        bufp->chgBit(oldp+2813,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_58));
        bufp->chgBit(oldp+2814,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_58));
        bufp->chgBit(oldp+2815,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_59));
        bufp->chgBit(oldp+2816,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_59));
        bufp->chgBit(oldp+2817,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_60));
        bufp->chgBit(oldp+2818,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_60));
        bufp->chgBit(oldp+2819,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_61));
        bufp->chgBit(oldp+2820,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_61));
        bufp->chgBit(oldp+2821,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_70));
        bufp->chgBit(oldp+2822,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_71));
        bufp->chgBit(oldp+2823,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_72));
        bufp->chgBit(oldp+2824,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_72));
        bufp->chgBit(oldp+2825,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_73));
        bufp->chgBit(oldp+2826,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_73));
        bufp->chgBit(oldp+2827,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_74));
        bufp->chgBit(oldp+2828,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_74));
        bufp->chgBit(oldp+2829,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_75));
        bufp->chgBit(oldp+2830,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_75));
        bufp->chgBit(oldp+2831,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_84));
        bufp->chgBit(oldp+2832,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_85));
        bufp->chgBit(oldp+2833,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_86));
        bufp->chgBit(oldp+2834,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_86));
        bufp->chgBit(oldp+2835,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_87));
        bufp->chgBit(oldp+2836,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_87));
        bufp->chgBit(oldp+2837,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_88));
        bufp->chgBit(oldp+2838,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_88));
        bufp->chgBit(oldp+2839,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_89));
        bufp->chgBit(oldp+2840,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_89));
        bufp->chgBit(oldp+2841,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_98));
        bufp->chgBit(oldp+2842,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_99));
        bufp->chgBit(oldp+2843,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_100));
        bufp->chgBit(oldp+2844,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_100));
        bufp->chgBit(oldp+2845,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_101));
        bufp->chgBit(oldp+2846,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_101));
        bufp->chgBit(oldp+2847,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_102));
        bufp->chgBit(oldp+2848,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_102));
        bufp->chgBit(oldp+2849,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_103));
        bufp->chgBit(oldp+2850,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_103));
        bufp->chgBit(oldp+2851,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_112));
        bufp->chgBit(oldp+2852,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_113));
        bufp->chgBit(oldp+2853,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_114));
        bufp->chgBit(oldp+2854,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_114));
        bufp->chgBit(oldp+2855,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_115));
        bufp->chgBit(oldp+2856,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_115));
        bufp->chgBit(oldp+2857,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_116));
        bufp->chgBit(oldp+2858,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_116));
        bufp->chgBit(oldp+2859,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_eq_117));
        bufp->chgBit(oldp+2860,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_a_mask_acc_117));
        bufp->chgCData(oldp+2861,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__atomics_mask),8);
        bufp->chgSData(oldp+2862,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__counter),9);
        bufp->chgSData(oldp+2863,((0x1ffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__counter) 
                                             - (IData)(1U)))),9);
        bufp->chgBit(oldp+2864,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__grantInProgress));
        bufp->chgCData(oldp+2865,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__blockProbeAfterGrantCount),3);
        bufp->chgBit(oldp+2866,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__blockUncachedGrant));
        bufp->chgBit(oldp+2867,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__block_probe_for_core_progress));
        bufp->chgSData(oldp+2868,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__beats1_1),9);
        bufp->chgSData(oldp+2869,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__counter_1),9);
        bufp->chgSData(oldp+2870,((0x1ffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__counter_1) 
                                             - (IData)(1U)))),9);
        bufp->chgBit(oldp+2871,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__counter_1))));
        bufp->chgBit(oldp+2872,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_release_data_valid));
        bufp->chgBit(oldp+2873,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_release_data_valid));
        bufp->chgBit(oldp+2874,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_s2_xcpt_REG));
        bufp->chgIData(oldp+2875,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_resp_bits_data_shifted),32);
        bufp->chgSData(oldp+2876,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_resp_bits_data_shifted_1),16);
        bufp->chgCData(oldp+2877,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_resp_bits_data_zeroed_2),8);
        bufp->chgIData(oldp+2878,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_resp_bits_data_word_bypass_shifted),32);
        bufp->chgBit(oldp+2879,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__REG));
        bufp->chgSData(oldp+2880,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_perf_acquire_counter),9);
        bufp->chgSData(oldp+2881,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_perf_release_counter),9);
        bufp->chgCData(oldp+2882,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_perf_blocked_near_end_of_refill_refill_count),3);
        bufp->chgCData(oldp+2883,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_hits),7);
        bufp->chgCData(oldp+2884,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_ptw_pf_array),7);
        bufp->chgCData(oldp+2885,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_priv_rw_ok),6);
        bufp->chgBit(oldp+2886,((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))));
        bufp->chgBit(oldp+2887,((7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))));
        bufp->chgBit(oldp+2888,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb___05Fcmd_lrsc_T_2));
        bufp->chgBit(oldp+2889,((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))));
        bufp->chgBit(oldp+2890,((9U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))));
        bufp->chgBit(oldp+2891,((0xaU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))));
        bufp->chgBit(oldp+2892,((0xbU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))));
        bufp->chgBit(oldp+2893,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb___05Fcmd_amo_logical_T_6));
        bufp->chgBit(oldp+2894,((8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))));
        bufp->chgBit(oldp+2895,((0xcU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))));
        bufp->chgBit(oldp+2896,((0xdU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))));
        bufp->chgBit(oldp+2897,((0xeU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))));
        bufp->chgBit(oldp+2898,((0xfU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))));
        bufp->chgBit(oldp+2899,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb___05Fcmd_amo_arithmetic_T_8));
        bufp->chgBit(oldp+2900,((0x11U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_cmd))));
        bufp->chgBit(oldp+2901,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_cmd_read));
        bufp->chgBit(oldp+2902,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_cmd_write));
        bufp->chgBit(oldp+2903,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_cmd_write_perms));
        bufp->chgCData(oldp+2904,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb___05Fpf_ld_array_T_2),7);
        bufp->chgCData(oldp+2905,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb___05Fpf_ld_array_T_5),7);
        bufp->chgBit(oldp+2906,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb___05Fsuperpage_hits_T_23));
        bufp->chgBit(oldp+2907,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb___05Fsuperpage_hits_T_37));
        bufp->chgBit(oldp+2908,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb___05Fsuperpage_hits_T_51));
    }
}
