// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_fst_c.h"
#include "VTestHarness__Syms.h"


extern const VlWide<8>/*255:0*/ VTestHarness__ConstPool__CONST_h4e4f723a_0;

VL_ATTR_COLD void VTestHarness___024root__trace_full_sub_8(VTestHarness___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root__trace_full_sub_8\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
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
    bufp->fullCData(oldp+29381,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT___same_cycle_resp_T_1)
                                  ? (3U & ((IData)(1U) 
                                           << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcache_auto_out_a_bits_source)))
                                  : 0U)),2);
    bufp->fullCData(oldp+29382,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor__DOT___same_cycle_resp_T_3) 
                                  & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_opcode))))
                                  ? (3U & ((IData)(1U) 
                                           << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_source)))
                                  : 0U)),2);
    bufp->fullSData(oldp+29383,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_first_counter),9);
    bufp->fullCData(oldp+29384,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__opcode_1),3);
    bufp->fullCData(oldp+29385,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__param_1),2);
    bufp->fullCData(oldp+29386,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__size_1),4);
    bufp->fullBit(oldp+29387,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__source_1));
    bufp->fullCData(oldp+29388,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__sink),3);
    bufp->fullBit(oldp+29389,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__denied));
    bufp->fullBit(oldp+29390,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__inflight));
    bufp->fullCData(oldp+29391,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__inflight_opcodes),4);
    bufp->fullCData(oldp+29392,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__inflight_sizes),8);
    bufp->fullSData(oldp+29393,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_first_counter_1),9);
    bufp->fullBit(oldp+29394,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_first_counter_1))));
    bufp->fullIData(oldp+29395,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__watchdog),32);
    bufp->fullSData(oldp+29396,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_first_counter_2),9);
    bufp->fullBit(oldp+29397,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_first_counter_2))));
    bufp->fullBit(oldp+29398,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__s_or_r) 
                                & (0x20U == (0x78U 
                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[4U]))) 
                               & (((7U != (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[4U])) 
                                   & (4U != (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[4U]))) 
                                  & (0U != (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[4U]))))));
    bufp->fullBit(oldp+29399,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__s_or_r) 
                                & (0x2000U == (0x7800U 
                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[8U]))) 
                               & (((7U != (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[8U] 
                                                 >> 8U))) 
                                   & (4U != (7U & (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[8U] 
                                                   >> 8U)))) 
                                  & (0U != (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[8U] 
                                                  >> 8U)))))));
    bufp->fullBit(oldp+29400,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__s_or_r) 
                               & (0x24U == (0x7fU & 
                                            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[4U])))));
    bufp->fullBit(oldp+29401,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__s_or_r) 
                               & (0x2400U == (0x7f00U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_io_ghm_packet_outs_3[8U])))));
    bufp->fullBit(oldp+29402,((((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_perf_acquire_counter)) 
                                | (0U == ((4U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_opcode))
                                           ? 0U : (0x1ffU 
                                                   & (~ 
                                                      (0xffffffU 
                                                       & (((IData)(0xfffU) 
                                                           << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__x1_a_deq_bits_size)) 
                                                          >> 3U))))))) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_perf_acquire_T))));
    bufp->fullBit(oldp+29403,((((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_perf_release_counter)) 
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
    bufp->fullBit(oldp+29404,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_wb)) 
                                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode))))));
    bufp->fullBit(oldp+29405,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_valid) 
                               & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_wb)))));
    bufp->fullBit(oldp+29406,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_valid) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_fence_i)) 
                                & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)))) 
                               & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_requestor_2_s2_nack)))));
    bufp->fullBit(oldp+29407,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_valid) 
                               & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_jal) 
                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_jalr)) 
                                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_branch)))));
    bufp->fullBit(oldp+29408,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_valid) 
                                & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T_29))) 
                               & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_csr_stall_output)))));
    bufp->fullBit(oldp+29409,((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_409) 
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
    bufp->fullBit(oldp+29410,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_wen) 
                               & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_set_sboard)))));
    bufp->fullBit(oldp+29411,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__if_RSU_packet) 
                               & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__packet_index)))));
    bufp->fullBit(oldp+29412,(((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__icsl__io_if_correct_process) 
                                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__io_if_check_privret_REG)) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__ic_counter_done)) 
                                 & ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__fsm_state)) 
                                    | (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__fsm_state)))) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__icsl__io_returned_to_special_address_valid))) 
                               & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__excpt_mode)))));
    bufp->fullQData(oldp+29413,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_deq_valid_0)
                                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_deq_data_0
                                   : 0ULL) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_deq_valid_1)
                                               ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_deq_data_1
                                               : 0ULL))),64);
    bufp->fullBit(oldp+29415,((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_wen)) 
                               & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))));
    bufp->fullQData(oldp+29416,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29418,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29420,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_7)
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
    bufp->fullQData(oldp+29422,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_7)
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
    bufp->fullQData(oldp+29424,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29426,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29428,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29430,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29432,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29434,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29436,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29438,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29440,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29442,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29444,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29446,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29448,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29450,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29452,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29454,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29456,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29458,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29460,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29462,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29464,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29466,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29468,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29470,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29472,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29474,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29476,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29478,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_arfs_valid_out)
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
    bufp->fullQData(oldp+29480,((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN[
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
    bufp->fullBit(oldp+29482,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__packet_valid)) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___T_17))));
    bufp->fullBit(oldp+29483,((((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__packet_valid) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___T_17))) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___T_18)) 
                               & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rf_waddr)))));
    bufp->fullBit(oldp+29484,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__do_check) 
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
                                        ? ((0x20U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ECP_ext__DOT___GEN_0))
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
    bufp->fullBit(oldp+29485,((((3U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__inflight)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__empty)) 
                               & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT____Vcellinp__replayq__io_nack_valid)))));
    bufp->fullBit(oldp+29486,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_s2_nack_output) 
                               & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT__s2_id)))));
    bufp->fullBit(oldp+29487,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_valid) 
                               & (((0xffffffffffULL 
                                    & (~ (1ULL | (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_pc)))) 
                                   == (0xffffffffffULL 
                                       & (~ (1ULL | 
                                             (~ (((QData)((IData)(
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
                                      | (((3ULL > (0xffffffffffULL 
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
                                                      - 
                                                      (~ 
                                                       (1ULL 
                                                        | (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_pc)))))) 
                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___GEN_0[2U] 
                                             >> 0x11U)) 
                                         & ((0xffffffffffULL 
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
    bufp->fullQData(oldp+29488,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__bjl_redirect_replay) 
                                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__bjl_redirect_replay_continue))
                                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_bjl_npc
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_replay)
                                      ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_pc
                                      : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__predicted_npc))),40);
    bufp->fullBit(oldp+29490,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_valid) 
                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_pc 
                                    == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__replay_pc_cfi)) 
                                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__bjl_use_target))) 
                               & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_imem_if_check_completed)))));
    bufp->fullBit(oldp+29491,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_valid) 
                                & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_jal) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_jalr)) 
                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_branch))) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_imem_checker_mode))));
    bufp->fullBit(oldp+29492,((1U & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__commit_bank_ptr)
                                         ? ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__empty_spec)) 
                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__has_enq_1))
                                         : ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__empty_spec)) 
                                            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__has_enq)))))));
    bufp->fullBit(oldp+29493,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__empty_spec)) 
                                     | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__has_enq)))));
    bufp->fullBit(oldp+29494,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__empty_spec)) 
                                     | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__has_enq_1)))));
    bufp->fullBit(oldp+29495,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__reserve_fire) 
                               & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__spec_bank_ptr)))));
    bufp->fullBit(oldp+29496,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__commit_fire) 
                               & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__commit_bank_ptr)))));
    bufp->fullBit(oldp+29497,(((~ ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__spec_bank_ptr)) 
                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__spec_bank_ptr) 
                                      - (IData)(1U)))) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__BJL__io_bj_s2_replay))));
    if (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__empty_spec) 
         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__do_enq))) {
        __Vtemp_h0abd8d3f__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT____Vcellinp__u_channel_bj_0__io_enq_bits[0U];
        __Vtemp_h0abd8d3f__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT____Vcellinp__u_channel_bj_0__io_enq_bits[1U];
        __Vtemp_h0abd8d3f__0[2U] = (0x3ffffU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT____Vcellinp__u_channel_bj_0__io_enq_bits[2U]);
    } else if ((0x51ffU >= (0x7fffU & ((IData)(0x52U) 
                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr))))) {
        __Vtemp_h0abd8d3f__0[0U] = (((0U == (0x1fU 
                                             & ((IData)(0x52U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr))))
                                      ? 0U : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT___GEN[
                                              ((IData)(1U) 
                                               + (0x3ffU 
                                                  & (((IData)(0x52U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)) 
                                                     >> 5U)))] 
                                              << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(0x52U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)))))) 
                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT___GEN[
                                       (0x3ffU & (((IData)(0x52U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)) 
                                                  >> 5U))] 
                                       >> (0x1fU & 
                                           ((IData)(0x52U) 
                                            * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)))));
        __Vtemp_h0abd8d3f__0[1U] = (((0U == (0x1fU 
                                             & ((IData)(0x52U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr))))
                                      ? 0U : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT___GEN[
                                              ((IData)(2U) 
                                               + (0x3ffU 
                                                  & (((IData)(0x52U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)) 
                                                     >> 5U)))] 
                                              << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(0x52U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)))))) 
                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT___GEN[
                                       ((IData)(1U) 
                                        + (0x3ffU & 
                                           (((IData)(0x52U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)) 
                                            >> 5U)))] 
                                       >> (0x1fU & 
                                           ((IData)(0x52U) 
                                            * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)))));
        __Vtemp_h0abd8d3f__0[2U] = (0x3ffffU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(0x52U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr))))
                                                  ? 0U
                                                  : 
                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT___GEN[
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
                                                    + 
                                                    (0x3ffU 
                                                     & (((IData)(0x52U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr)) 
                                                        >> 5U)))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(0x52U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT__sptr))))));
    } else {
        __Vtemp_h0abd8d3f__0[0U] = 0U;
        __Vtemp_h0abd8d3f__0[1U] = 0U;
        __Vtemp_h0abd8d3f__0[2U] = (0x3ffffU & 0U);
    }
    bufp->fullWData(oldp+29498,(__Vtemp_h0abd8d3f__0),82);
    bufp->fullBit(oldp+29501,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__reserve_fire) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__spec_bank_ptr))));
    bufp->fullBit(oldp+29502,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__commit_fire) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__commit_bank_ptr))));
    bufp->fullBit(oldp+29503,((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__spec_bank_ptr)) 
                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__spec_bank_ptr) 
                                   - (IData)(1U))) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__BJL__io_bj_s2_replay))));
    if (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__empty_spec) 
         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__do_enq))) {
        __Vtemp_h1e2890c5__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT____Vcellinp__u_channel_bj_1__io_enq_bits[0U];
        __Vtemp_h1e2890c5__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT____Vcellinp__u_channel_bj_1__io_enq_bits[1U];
        __Vtemp_h1e2890c5__0[2U] = (0x3ffffU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT____Vcellinp__u_channel_bj_1__io_enq_bits[2U]);
    } else if ((0x51ffU >= (0x7fffU & ((IData)(0x52U) 
                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr))))) {
        __Vtemp_h1e2890c5__0[0U] = (((0U == (0x1fU 
                                             & ((IData)(0x52U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr))))
                                      ? 0U : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT___GEN[
                                              ((IData)(1U) 
                                               + (0x3ffU 
                                                  & (((IData)(0x52U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)) 
                                                     >> 5U)))] 
                                              << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(0x52U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)))))) 
                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT___GEN[
                                       (0x3ffU & (((IData)(0x52U) 
                                                   * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)) 
                                                  >> 5U))] 
                                       >> (0x1fU & 
                                           ((IData)(0x52U) 
                                            * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)))));
        __Vtemp_h1e2890c5__0[1U] = (((0U == (0x1fU 
                                             & ((IData)(0x52U) 
                                                * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr))))
                                      ? 0U : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT___GEN[
                                              ((IData)(2U) 
                                               + (0x3ffU 
                                                  & (((IData)(0x52U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)) 
                                                     >> 5U)))] 
                                              << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(0x52U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)))))) 
                                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT___GEN[
                                       ((IData)(1U) 
                                        + (0x3ffU & 
                                           (((IData)(0x52U) 
                                             * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)) 
                                            >> 5U)))] 
                                       >> (0x1fU & 
                                           ((IData)(0x52U) 
                                            * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)))));
        __Vtemp_h1e2890c5__0[2U] = (0x3ffffU & (((0U 
                                                  == 
                                                  (0x1fU 
                                                   & ((IData)(0x52U) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr))))
                                                  ? 0U
                                                  : 
                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT___GEN[
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
                                                    + 
                                                    (0x3ffU 
                                                     & (((IData)(0x52U) 
                                                         * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr)) 
                                                        >> 5U)))] 
                                                   >> 
                                                   (0x1fU 
                                                    & ((IData)(0x52U) 
                                                       * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT__sptr))))));
    } else {
        __Vtemp_h1e2890c5__0[0U] = 0U;
        __Vtemp_h1e2890c5__0[1U] = 0U;
        __Vtemp_h1e2890c5__0[2U] = (0x3ffffU & 0U);
    }
    bufp->fullWData(oldp+29504,(__Vtemp_h1e2890c5__0),82);
    bufp->fullCData(oldp+29507,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_imem_btb_update_valid)
                                  ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_btb_resp_entry)
                                  : 0x1cU)),5);
    bufp->fullQData(oldp+29508,((0x7fffffffffULL & 
                                 ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_imem_btb_update_valid)
                                   ? (~ (3ULL | (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_btb_update_bits_br_pc_output)))
                                   : (~ (3ULL | (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_pc)))))),39);
    bufp->fullBit(oldp+29510,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_imem_btb_update_valid)) 
                                     | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_cfi)))));
    bufp->fullQData(oldp+29511,((0x7fffffffffULL & 
                                 ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_imem_btb_update_valid)
                                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_btb_update_bits_br_pc_output
                                   : ((~ (3ULL | (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_pc))) 
                                      | ((QData)((IData)(
                                                         (1U 
                                                          & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__taken))))) 
                                         << 1U))))),39);
    bufp->fullCData(oldp+29513,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_imem_btb_update_valid)
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
    bufp->fullBit(oldp+29514,((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__taken)) 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_88) 
                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_89)))
                                ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_116) 
                                   & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__wrong_path)))
                                : ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_55) 
                                     | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_56)) 
                                    & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_116)) 
                                   & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__wrong_path))))));
    bufp->fullSData(oldp+29515,((0x1ffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT___GEN_5)
                                            ? (((~ (IData)(
                                                           (0x1fffffffffULL 
                                                            & ((~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_btb_update_bits_br_pc_output) 
                                                               >> 2U)))) 
                                                ^ (3U 
                                                   & (~ (IData)(
                                                                (0xfffffffULL 
                                                                 & ((~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___io_imem_btb_update_bits_br_pc_output) 
                                                                    >> 0xbU)))))) 
                                               ^ (0x1c0U 
                                                  & (((IData)(0xddU) 
                                                      * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_btb_resp_bht_history)) 
                                                     << 1U)))
                                            : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT__reset_waddr)))),9);
    bufp->fullBit(oldp+29516,((1U & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__btb__io_bht_update_valid) 
                                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_branch)) 
                                     | (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT__reset_waddr) 
                                           >> 9U))))));
    bufp->fullBit(oldp+29517,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT___GEN_5) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_br_taken))));
    bufp->fullBit(oldp+29518,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_redirect) 
                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___tlb_io_resp_miss)) 
                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_replay))));
    bufp->fullBit(oldp+29519,(((~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                                   >> 0xaU)) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_b_ready))));
    bufp->fullBit(oldp+29520,(((~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                                    & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__checker_mode_1cycle_delay)) 
                                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode) 
                                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__checker_priv_mode_1cycle_delay)))) 
                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___lsl_req_kill_T_3) 
                                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__fpu_kill_mem)))));
    bufp->fullBit(oldp+29521,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT___io_st_deq_T) 
                               & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl_req_cmd)))));
    bufp->fullBit(oldp+29522,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT___io_st_deq_T) 
                               & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl_req_cmd)))));
    bufp->fullBit(oldp+29523,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output)) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT___io_requestor_1_req_ready_output))));
    bufp->fullBit(oldp+29524,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_valid) 
                               & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_mem_s1_kill)))));
    bufp->fullBit(oldp+29525,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_tileClockGroup_tile_4_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0));
    bufp->fullBit(oldp+29526,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_tileClockGroup_tile_4_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_1));
    bufp->fullBit(oldp+29527,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_tileClockGroup_tile_4_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_2));
    bufp->fullBit(oldp+29528,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    bufp->fullBit(oldp+29529,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    bufp->fullBit(oldp+29530,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    bufp->fullBit(oldp+29531,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    bufp->fullBit(oldp+29532,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    bufp->fullBit(oldp+29533,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    bufp->fullBit(oldp+29534,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    bufp->fullBit(oldp+29535,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    bufp->fullBit(oldp+29536,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
    bufp->fullBit(oldp+29537,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
    bufp->fullBit(oldp+29538,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    bufp->fullBit(oldp+29539,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
    bufp->fullBit(oldp+29540,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
    bufp->fullBit(oldp+29541,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    bufp->fullBit(oldp+29542,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
    bufp->fullBit(oldp+29543,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
    bufp->fullBit(oldp+29544,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    bufp->fullBit(oldp+29545,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
    bufp->fullBit(oldp+29546,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
    bufp->fullBit(oldp+29547,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    bufp->fullBit(oldp+29548,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
    bufp->fullBit(oldp+29549,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
    bufp->fullBit(oldp+29550,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    bufp->fullBit(oldp+29551,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__receiving));
    bufp->fullIData(oldp+29552,(vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg),32);
    bufp->fullBit(oldp+29553,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__sending));
    bufp->fullIData(oldp+29554,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U]),32);
    bufp->fullIData(oldp+29555,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_0),32);
    bufp->fullIData(oldp+29556,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_1),32);
    bufp->fullIData(oldp+29557,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_2),32);
    bufp->fullIData(oldp+29558,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_3),32);
    bufp->fullIData(oldp+29559,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_4),32);
    bufp->fullIData(oldp+29560,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_5),32);
    bufp->fullIData(oldp+29561,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_6),32);
    bufp->fullIData(oldp+29562,(vlSelf->TestHarness__DOT__bits_out_queue__DOT__source__DOT__mem_7),32);
    bufp->fullBit(oldp+29563,(vlSelf->TestHarness__DOT__simdram__DOT_____05Faw_ready_reg));
    bufp->fullBit(oldp+29564,(vlSelf->TestHarness__DOT__simdram__DOT_____05Fw_ready_reg));
    bufp->fullBit(oldp+29565,(vlSelf->TestHarness__DOT__simdram__DOT_____05Fb_valid_reg));
    bufp->fullCData(oldp+29566,(vlSelf->TestHarness__DOT__simdram__DOT_____05Fb_id_reg),4);
    bufp->fullCData(oldp+29567,(vlSelf->TestHarness__DOT__simdram__DOT_____05Fb_resp_reg),2);
    bufp->fullBit(oldp+29568,(vlSelf->TestHarness__DOT__simdram__DOT_____05Far_ready_reg));
    bufp->fullBit(oldp+29569,(vlSelf->TestHarness__DOT__simdram__DOT_____05Fr_valid_reg));
    bufp->fullCData(oldp+29570,(vlSelf->TestHarness__DOT__simdram__DOT_____05Fr_id_reg),4);
    bufp->fullQData(oldp+29571,(vlSelf->TestHarness__DOT__simdram__DOT_____05Fr_data_reg),64);
    bufp->fullCData(oldp+29573,(vlSelf->TestHarness__DOT__simdram__DOT_____05Fr_resp_reg),2);
    bufp->fullBit(oldp+29574,(vlSelf->TestHarness__DOT__simdram__DOT_____05Fr_last_reg));
    bufp->fullBit(oldp+29575,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT___tl2axi4_auto_out_aw_valid) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__axi4yank__DOT___GEN_4))));
    bufp->fullCData(oldp+29576,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___queue_arw_deq_io_deq_bits_id),4);
    bufp->fullIData(oldp+29577,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___queue_arw_deq_io_deq_bits_addr),32);
    bufp->fullCData(oldp+29578,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___queue_arw_deq_io_deq_bits_len),8);
    bufp->fullCData(oldp+29579,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT___queue_arw_deq_io_deq_bits_size),3);
    bufp->fullCData(oldp+29580,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__queue_arw_deq__DOT__maybe_full)
                                  ? (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__queue_arw_deq__DOT__ram_ext__DOT__Memory
                                           [0U][1U] 
                                           >> 0xfU))
                                  : 1U)),2);
    bufp->fullBit(oldp+29581,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__queue_arw_deq__DOT__maybe_full) 
                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__queue_arw_deq__DOT__ram_ext__DOT__Memory
                                  [0U][1U] >> 0x11U))));
    bufp->fullCData(oldp+29582,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__queue_arw_deq__DOT__maybe_full)
                                  ? (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__queue_arw_deq__DOT__ram_ext__DOT__Memory
                                             [0U][1U] 
                                             >> 0x12U))
                                  : 0U)),4);
    bufp->fullCData(oldp+29583,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__queue_arw_deq__DOT__maybe_full)
                                  ? (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__queue_arw_deq__DOT__ram_ext__DOT__Memory
                                           [0U][1U] 
                                           >> 0x16U))
                                  : 1U)),3);
    bufp->fullCData(oldp+29584,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__queue_arw_deq__DOT__maybe_full)
                                  ? (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__queue_arw_deq__DOT__ram_ext__DOT__Memory
                                             [0U][1U] 
                                             >> 0x19U))
                                  : 0U)),4);
    bufp->fullBit(oldp+29585,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__deq__DOT___io_deq_valid_output));
    bufp->fullQData(oldp+29586,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__deq__DOT__maybe_full)
                                  ? (((QData)((IData)(
                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__deq__DOT__ram_ext__DOT__Memory
                                                      [0U][1U])) 
                                      << 0x20U) | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__deq__DOT__ram_ext__DOT__Memory
                                                                  [0U][0U])))
                                  : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_data)),64);
    bufp->fullCData(oldp+29588,((0xffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__deq__DOT__maybe_full)
                                           ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__deq__DOT__ram_ext__DOT__Memory
                                          [0U][2U] : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_mask)))),8);
    bufp->fullBit(oldp+29589,((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__deq__DOT__maybe_full)
                                      ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__deq__DOT__ram_ext__DOT__Memory
                                         [0U][2U] >> 8U)
                                      : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__out_w_bits_last)))));
    bufp->fullBit(oldp+29590,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__x1_b_ready));
    bufp->fullBit(oldp+29591,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT___tl2axi4_auto_out_ar_valid) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__axi4yank__DOT___GEN_0))));
    bufp->fullBit(oldp+29592,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__x1_r_ready));
    bufp->fullBit(oldp+29593,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txm__DOT__out));
    bufp->fullBit(oldp+29594,((1U & vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg)));
    bufp->fullBit(oldp+29595,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 1U))));
    bufp->fullBit(oldp+29596,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 0xaU))));
    bufp->fullBit(oldp+29597,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 0xbU))));
    bufp->fullBit(oldp+29598,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 0xcU))));
    bufp->fullBit(oldp+29599,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 0xdU))));
    bufp->fullBit(oldp+29600,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 0xeU))));
    bufp->fullBit(oldp+29601,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 0xfU))));
    bufp->fullBit(oldp+29602,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 0x10U))));
    bufp->fullBit(oldp+29603,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 0x11U))));
    bufp->fullBit(oldp+29604,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 0x12U))));
    bufp->fullBit(oldp+29605,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 0x13U))));
    bufp->fullBit(oldp+29606,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 2U))));
    bufp->fullBit(oldp+29607,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 0x14U))));
    bufp->fullBit(oldp+29608,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 0x15U))));
    bufp->fullBit(oldp+29609,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 0x16U))));
    bufp->fullBit(oldp+29610,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 0x17U))));
    bufp->fullBit(oldp+29611,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 0x18U))));
    bufp->fullBit(oldp+29612,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 0x19U))));
    bufp->fullBit(oldp+29613,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 0x1aU))));
    bufp->fullBit(oldp+29614,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 0x1bU))));
    bufp->fullBit(oldp+29615,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 0x1cU))));
    bufp->fullBit(oldp+29616,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 0x1dU))));
    bufp->fullBit(oldp+29617,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 3U))));
    bufp->fullBit(oldp+29618,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 0x1eU))));
    bufp->fullBit(oldp+29619,((vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                               >> 0x1fU)));
    bufp->fullBit(oldp+29620,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 4U))));
    bufp->fullBit(oldp+29621,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 5U))));
    bufp->fullBit(oldp+29622,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 6U))));
    bufp->fullBit(oldp+29623,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 7U))));
    bufp->fullBit(oldp+29624,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 8U))));
    bufp->fullBit(oldp+29625,((1U & (vlSelf->TestHarness__DOT__bits_in_queue__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg 
                                     >> 9U))));
    bufp->fullBit(oldp+29626,((1U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U])));
    bufp->fullBit(oldp+29627,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 1U))));
    bufp->fullBit(oldp+29628,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 0xaU))));
    bufp->fullBit(oldp+29629,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 0xbU))));
    bufp->fullBit(oldp+29630,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 0xcU))));
    bufp->fullBit(oldp+29631,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 0xdU))));
    bufp->fullBit(oldp+29632,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 0xeU))));
    bufp->fullBit(oldp+29633,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 0xfU))));
    bufp->fullBit(oldp+29634,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 0x10U))));
    bufp->fullBit(oldp+29635,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 0x11U))));
    bufp->fullBit(oldp+29636,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 0x12U))));
    bufp->fullBit(oldp+29637,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 0x13U))));
    bufp->fullBit(oldp+29638,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 2U))));
    bufp->fullBit(oldp+29639,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 0x14U))));
    bufp->fullBit(oldp+29640,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 0x15U))));
    bufp->fullBit(oldp+29641,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 0x16U))));
    bufp->fullBit(oldp+29642,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 0x17U))));
    bufp->fullBit(oldp+29643,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 0x18U))));
    bufp->fullBit(oldp+29644,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 0x19U))));
    bufp->fullBit(oldp+29645,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 0x1aU))));
    bufp->fullBit(oldp+29646,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 0x1bU))));
    bufp->fullBit(oldp+29647,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 0x1cU))));
    bufp->fullBit(oldp+29648,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 0x1dU))));
    bufp->fullBit(oldp+29649,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 3U))));
    bufp->fullBit(oldp+29650,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 0x1eU))));
    bufp->fullBit(oldp+29651,((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                               >> 0x1fU)));
    bufp->fullBit(oldp+29652,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 4U))));
    bufp->fullBit(oldp+29653,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 5U))));
    bufp->fullBit(oldp+29654,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 6U))));
    bufp->fullBit(oldp+29655,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 7U))));
    bufp->fullBit(oldp+29656,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 8U))));
    bufp->fullBit(oldp+29657,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U] 
                                     >> 9U))));
    bufp->fullIData(oldp+29658,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__outSer__DOT__data[0U]),32);
    bufp->fullBit(oldp+29659,((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_ght_status_out_sr_out 
                               >> 0x1fU)));
    bufp->fullCData(oldp+29660,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[4U] 
                                       >> 0xcU))),3);
    bufp->fullCData(oldp+29661,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[4U] 
                                       >> 0x14U))),3);
    bufp->fullIData(oldp+29662,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_b_wctrl_0),22);
    bufp->fullIData(oldp+29663,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_b_wctrl_1),22);
    bufp->fullIData(oldp+29664,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_b_wctrl_2),22);
    bufp->fullIData(oldp+29665,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_b_wctrl_3),22);
    bufp->fullCData(oldp+29666,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_routed_status),5);
    bufp->fullCData(oldp+29667,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_routed_status_1),5);
    bufp->fullCData(oldp+29668,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_routed_status_2),5);
    bufp->fullCData(oldp+29669,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_routed_status_3),5);
    bufp->fullQData(oldp+29670,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_debug_gcounter),64);
    bufp->fullCData(oldp+29672,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__int_rtc_tick_c_value),8);
    bufp->fullBit(oldp+29673,((0xc7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__int_rtc_tick_c_value))));
    bufp->fullWData(oldp+29674,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__inflight),1040);
    bufp->fullWData(oldp+29707,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__inflight_opcodes),4160);
    bufp->fullWData(oldp+29837,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__inflight_sizes),4160);
    bufp->fullIData(oldp+29967,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__bootROMDomainWrapper__DOT__bootrom__DOT__monitor__DOT__watchdog),32);
    bufp->fullWData(oldp+29968,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__inflight),1040);
    bufp->fullWData(oldp+30001,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__inflight_opcodes),4160);
    bufp->fullWData(oldp+30131,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__inflight_sizes),4160);
    bufp->fullIData(oldp+30261,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__monitor__DOT__watchdog),32);
    bufp->fullBit(oldp+30262,(((1U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[4U] 
                                             >> 0xcU))) 
                               | (1U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[4U] 
                                               >> 0x14U))))));
    __Vtemp_h10336803__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[0U];
    __Vtemp_h10336803__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[1U];
    __Vtemp_h10336803__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[2U];
    __Vtemp_h10336803__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[3U];
    __Vtemp_h10336803__0[4U] = (0x1ffffU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[4U]);
    bufp->fullWData(oldp+30263,(__Vtemp_h10336803__0),145);
    bufp->fullWData(oldp+30268,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__source__DOT__mem_0),145);
    bufp->fullWData(oldp+30273,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__source__DOT__mem_1),145);
    bufp->fullWData(oldp+30278,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__source__DOT__mem_2),145);
    bufp->fullWData(oldp+30283,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__source__DOT__mem_3),145);
    bufp->fullWData(oldp+30288,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__source__DOT__mem_4),145);
    bufp->fullWData(oldp+30293,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__source__DOT__mem_5),145);
    bufp->fullWData(oldp+30298,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__source__DOT__mem_6),145);
    bufp->fullWData(oldp+30303,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_0__DOT__source__DOT__mem_7),145);
    bufp->fullBit(oldp+30308,(((2U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[4U] 
                                             >> 0xcU))) 
                               | (2U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[4U] 
                                               >> 0x14U))))));
    bufp->fullWData(oldp+30309,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__source__DOT__mem_0),145);
    bufp->fullWData(oldp+30314,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__source__DOT__mem_1),145);
    bufp->fullWData(oldp+30319,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__source__DOT__mem_2),145);
    bufp->fullWData(oldp+30324,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__source__DOT__mem_3),145);
    bufp->fullWData(oldp+30329,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__source__DOT__mem_4),145);
    bufp->fullWData(oldp+30334,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__source__DOT__mem_5),145);
    bufp->fullWData(oldp+30339,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__source__DOT__mem_6),145);
    bufp->fullWData(oldp+30344,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_1__DOT__source__DOT__mem_7),145);
    bufp->fullBit(oldp+30349,(((3U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[4U] 
                                             >> 0xcU))) 
                               | (3U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[4U] 
                                               >> 0x14U))))));
    bufp->fullWData(oldp+30350,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__source__DOT__mem_0),145);
    bufp->fullWData(oldp+30355,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__source__DOT__mem_1),145);
    bufp->fullWData(oldp+30360,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__source__DOT__mem_2),145);
    bufp->fullWData(oldp+30365,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__source__DOT__mem_3),145);
    bufp->fullWData(oldp+30370,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__source__DOT__mem_4),145);
    bufp->fullWData(oldp+30375,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__source__DOT__mem_5),145);
    bufp->fullWData(oldp+30380,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__source__DOT__mem_6),145);
    bufp->fullWData(oldp+30385,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_2__DOT__source__DOT__mem_7),145);
    bufp->fullBit(oldp+30390,(((4U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[4U] 
                                             >> 0xcU))) 
                               | (4U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_core_r_arfs_sr_out[4U] 
                                               >> 0x14U))))));
    bufp->fullWData(oldp+30391,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__source__DOT__mem_0),145);
    bufp->fullWData(oldp+30396,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__source__DOT__mem_1),145);
    bufp->fullWData(oldp+30401,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__source__DOT__mem_2),145);
    bufp->fullWData(oldp+30406,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__source__DOT__mem_3),145);
    bufp->fullWData(oldp+30411,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__source__DOT__mem_4),145);
    bufp->fullWData(oldp+30416,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__source__DOT__mem_5),145);
    bufp->fullWData(oldp+30421,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__source__DOT__mem_6),145);
    bufp->fullWData(oldp+30426,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__source__DOT__mem_7),145);
    bufp->fullBit(oldp+30431,((((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_ght_status_out_sr_out 
                                 >> 0x1fU) | (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_routed_status))) 
                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_ic_counter_sr_out[0U] 
                                  >> 0x1fU))));
    bufp->fullIData(oldp+30432,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_0),22);
    bufp->fullIData(oldp+30433,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_1),22);
    bufp->fullIData(oldp+30434,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_2),22);
    bufp->fullIData(oldp+30435,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_3),22);
    bufp->fullIData(oldp+30436,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_4),22);
    bufp->fullIData(oldp+30437,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_5),22);
    bufp->fullIData(oldp+30438,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_6),22);
    bufp->fullIData(oldp+30439,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_7),22);
    bufp->fullIData(oldp+30440,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_8),22);
    bufp->fullIData(oldp+30441,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_9),22);
    bufp->fullIData(oldp+30442,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_10),22);
    bufp->fullIData(oldp+30443,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_11),22);
    bufp->fullIData(oldp+30444,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_12),22);
    bufp->fullIData(oldp+30445,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_13),22);
    bufp->fullIData(oldp+30446,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_14),22);
    bufp->fullIData(oldp+30447,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_15),22);
    bufp->fullIData(oldp+30448,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_16),22);
    bufp->fullIData(oldp+30449,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_17),22);
    bufp->fullIData(oldp+30450,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_18),22);
    bufp->fullIData(oldp+30451,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_19),22);
    bufp->fullIData(oldp+30452,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_20),22);
    bufp->fullIData(oldp+30453,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_21),22);
    bufp->fullIData(oldp+30454,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_22),22);
    bufp->fullIData(oldp+30455,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_23),22);
    bufp->fullIData(oldp+30456,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_24),22);
    bufp->fullIData(oldp+30457,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_25),22);
    bufp->fullIData(oldp+30458,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_26),22);
    bufp->fullIData(oldp+30459,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_27),22);
    bufp->fullIData(oldp+30460,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_28),22);
    bufp->fullIData(oldp+30461,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_29),22);
    bufp->fullIData(oldp+30462,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_30),22);
    bufp->fullIData(oldp+30463,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_31),22);
    bufp->fullIData(oldp+30464,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_32),22);
    bufp->fullIData(oldp+30465,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_33),22);
    bufp->fullIData(oldp+30466,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_34),22);
    bufp->fullIData(oldp+30467,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_35),22);
    bufp->fullIData(oldp+30468,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_36),22);
    bufp->fullIData(oldp+30469,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_37),22);
    bufp->fullIData(oldp+30470,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_38),22);
    bufp->fullIData(oldp+30471,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_39),22);
    bufp->fullIData(oldp+30472,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_40),22);
    bufp->fullIData(oldp+30473,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_41),22);
    bufp->fullIData(oldp+30474,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_42),22);
    bufp->fullIData(oldp+30475,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_43),22);
    bufp->fullIData(oldp+30476,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_44),22);
    bufp->fullIData(oldp+30477,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_45),22);
    bufp->fullIData(oldp+30478,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_46),22);
    bufp->fullIData(oldp+30479,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_47),22);
    bufp->fullIData(oldp+30480,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_48),22);
    bufp->fullIData(oldp+30481,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_49),22);
    bufp->fullIData(oldp+30482,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_50),22);
    bufp->fullIData(oldp+30483,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_51),22);
    bufp->fullIData(oldp+30484,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_52),22);
    bufp->fullIData(oldp+30485,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_53),22);
    bufp->fullIData(oldp+30486,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_54),22);
    bufp->fullIData(oldp+30487,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_55),22);
    bufp->fullIData(oldp+30488,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_56),22);
    bufp->fullIData(oldp+30489,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_57),22);
    bufp->fullIData(oldp+30490,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_58),22);
    bufp->fullIData(oldp+30491,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_59),22);
    bufp->fullIData(oldp+30492,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_60),22);
    bufp->fullIData(oldp+30493,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_61),22);
    bufp->fullIData(oldp+30494,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_62),22);
    bufp->fullIData(oldp+30495,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_0__DOT__source__DOT__mem_63),22);
    bufp->fullBit(oldp+30496,((1U & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_ght_status_out_sr_out 
                                       >> 0x1fU) | 
                                      (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_routed_status_1))) 
                                     | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_ic_counter_sr_out[1U] 
                                        >> 0xfU)))));
    bufp->fullIData(oldp+30497,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_0),22);
    bufp->fullIData(oldp+30498,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_1),22);
    bufp->fullIData(oldp+30499,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_2),22);
    bufp->fullIData(oldp+30500,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_3),22);
    bufp->fullIData(oldp+30501,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_4),22);
    bufp->fullIData(oldp+30502,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_5),22);
    bufp->fullIData(oldp+30503,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_6),22);
    bufp->fullIData(oldp+30504,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_7),22);
    bufp->fullIData(oldp+30505,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_8),22);
    bufp->fullIData(oldp+30506,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_9),22);
    bufp->fullIData(oldp+30507,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_10),22);
    bufp->fullIData(oldp+30508,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_11),22);
    bufp->fullIData(oldp+30509,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_12),22);
    bufp->fullIData(oldp+30510,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_13),22);
    bufp->fullIData(oldp+30511,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_14),22);
    bufp->fullIData(oldp+30512,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_15),22);
    bufp->fullIData(oldp+30513,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_16),22);
    bufp->fullIData(oldp+30514,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_17),22);
    bufp->fullIData(oldp+30515,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_18),22);
    bufp->fullIData(oldp+30516,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_19),22);
    bufp->fullIData(oldp+30517,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_20),22);
    bufp->fullIData(oldp+30518,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_21),22);
    bufp->fullIData(oldp+30519,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_22),22);
    bufp->fullIData(oldp+30520,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_23),22);
    bufp->fullIData(oldp+30521,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_24),22);
    bufp->fullIData(oldp+30522,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_25),22);
    bufp->fullIData(oldp+30523,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_26),22);
    bufp->fullIData(oldp+30524,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_27),22);
    bufp->fullIData(oldp+30525,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_28),22);
    bufp->fullIData(oldp+30526,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_29),22);
    bufp->fullIData(oldp+30527,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_30),22);
    bufp->fullIData(oldp+30528,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_31),22);
    bufp->fullIData(oldp+30529,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_32),22);
    bufp->fullIData(oldp+30530,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_33),22);
    bufp->fullIData(oldp+30531,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_34),22);
    bufp->fullIData(oldp+30532,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_35),22);
    bufp->fullIData(oldp+30533,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_36),22);
    bufp->fullIData(oldp+30534,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_37),22);
    bufp->fullIData(oldp+30535,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_38),22);
    bufp->fullIData(oldp+30536,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_39),22);
    bufp->fullIData(oldp+30537,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_40),22);
    bufp->fullIData(oldp+30538,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_41),22);
    bufp->fullIData(oldp+30539,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_42),22);
    bufp->fullIData(oldp+30540,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_43),22);
    bufp->fullIData(oldp+30541,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_44),22);
    bufp->fullIData(oldp+30542,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_45),22);
    bufp->fullIData(oldp+30543,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_46),22);
    bufp->fullIData(oldp+30544,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_47),22);
    bufp->fullIData(oldp+30545,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_48),22);
    bufp->fullIData(oldp+30546,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_49),22);
    bufp->fullIData(oldp+30547,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_50),22);
    bufp->fullIData(oldp+30548,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_51),22);
    bufp->fullIData(oldp+30549,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_52),22);
    bufp->fullIData(oldp+30550,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_53),22);
    bufp->fullIData(oldp+30551,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_54),22);
    bufp->fullIData(oldp+30552,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_55),22);
    bufp->fullIData(oldp+30553,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_56),22);
    bufp->fullIData(oldp+30554,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_57),22);
    bufp->fullIData(oldp+30555,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_58),22);
    bufp->fullIData(oldp+30556,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_59),22);
    bufp->fullIData(oldp+30557,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_60),22);
    bufp->fullIData(oldp+30558,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_61),22);
    bufp->fullIData(oldp+30559,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_62),22);
    bufp->fullIData(oldp+30560,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_1__DOT__source__DOT__mem_63),22);
    bufp->fullBit(oldp+30561,((((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_ght_status_out_sr_out 
                                 >> 0x1fU) | (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_routed_status_2))) 
                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_ic_counter_sr_out[1U] 
                                  >> 0x1fU))));
    bufp->fullIData(oldp+30562,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_0),22);
    bufp->fullIData(oldp+30563,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_1),22);
    bufp->fullIData(oldp+30564,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_2),22);
    bufp->fullIData(oldp+30565,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_3),22);
    bufp->fullIData(oldp+30566,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_4),22);
    bufp->fullIData(oldp+30567,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_5),22);
    bufp->fullIData(oldp+30568,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_6),22);
    bufp->fullIData(oldp+30569,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_7),22);
    bufp->fullIData(oldp+30570,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_8),22);
    bufp->fullIData(oldp+30571,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_9),22);
    bufp->fullIData(oldp+30572,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_10),22);
    bufp->fullIData(oldp+30573,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_11),22);
    bufp->fullIData(oldp+30574,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_12),22);
    bufp->fullIData(oldp+30575,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_13),22);
    bufp->fullIData(oldp+30576,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_14),22);
    bufp->fullIData(oldp+30577,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_15),22);
    bufp->fullIData(oldp+30578,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_16),22);
    bufp->fullIData(oldp+30579,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_17),22);
    bufp->fullIData(oldp+30580,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_18),22);
    bufp->fullIData(oldp+30581,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_19),22);
    bufp->fullIData(oldp+30582,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_20),22);
    bufp->fullIData(oldp+30583,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_21),22);
    bufp->fullIData(oldp+30584,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_22),22);
    bufp->fullIData(oldp+30585,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_23),22);
    bufp->fullIData(oldp+30586,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_24),22);
    bufp->fullIData(oldp+30587,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_25),22);
    bufp->fullIData(oldp+30588,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_26),22);
    bufp->fullIData(oldp+30589,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_27),22);
    bufp->fullIData(oldp+30590,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_28),22);
    bufp->fullIData(oldp+30591,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_29),22);
    bufp->fullIData(oldp+30592,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_30),22);
    bufp->fullIData(oldp+30593,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_31),22);
    bufp->fullIData(oldp+30594,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_32),22);
    bufp->fullIData(oldp+30595,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_33),22);
    bufp->fullIData(oldp+30596,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_34),22);
    bufp->fullIData(oldp+30597,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_35),22);
    bufp->fullIData(oldp+30598,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_36),22);
    bufp->fullIData(oldp+30599,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_37),22);
    bufp->fullIData(oldp+30600,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_38),22);
    bufp->fullIData(oldp+30601,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_39),22);
    bufp->fullIData(oldp+30602,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_40),22);
    bufp->fullIData(oldp+30603,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_41),22);
    bufp->fullIData(oldp+30604,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_42),22);
    bufp->fullIData(oldp+30605,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_43),22);
    bufp->fullIData(oldp+30606,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_44),22);
    bufp->fullIData(oldp+30607,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_45),22);
    bufp->fullIData(oldp+30608,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_46),22);
    bufp->fullIData(oldp+30609,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_47),22);
    bufp->fullIData(oldp+30610,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_48),22);
    bufp->fullIData(oldp+30611,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_49),22);
    bufp->fullIData(oldp+30612,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_50),22);
    bufp->fullIData(oldp+30613,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_51),22);
    bufp->fullIData(oldp+30614,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_52),22);
    bufp->fullIData(oldp+30615,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_53),22);
    bufp->fullIData(oldp+30616,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_54),22);
    bufp->fullIData(oldp+30617,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_55),22);
    bufp->fullIData(oldp+30618,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_56),22);
    bufp->fullIData(oldp+30619,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_57),22);
    bufp->fullIData(oldp+30620,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_58),22);
    bufp->fullIData(oldp+30621,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_59),22);
    bufp->fullIData(oldp+30622,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_60),22);
    bufp->fullIData(oldp+30623,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_61),22);
    bufp->fullIData(oldp+30624,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_62),22);
    bufp->fullIData(oldp+30625,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_2__DOT__source__DOT__mem_63),22);
    bufp->fullBit(oldp+30626,((((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_ght_status_out_sr_out 
                                 >> 0x1fU) | (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_routed_status_3))) 
                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_auto_tile_reset_domain_boom_tile_ic_counter_sr_out[2U] 
                                  >> 0xfU))));
    bufp->fullIData(oldp+30627,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_0),22);
    bufp->fullIData(oldp+30628,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_1),22);
    bufp->fullIData(oldp+30629,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_2),22);
    bufp->fullIData(oldp+30630,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_3),22);
    bufp->fullIData(oldp+30631,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_4),22);
    bufp->fullIData(oldp+30632,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_5),22);
    bufp->fullIData(oldp+30633,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_6),22);
    bufp->fullIData(oldp+30634,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_7),22);
    bufp->fullIData(oldp+30635,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_8),22);
    bufp->fullIData(oldp+30636,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_9),22);
    bufp->fullIData(oldp+30637,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_10),22);
    bufp->fullIData(oldp+30638,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_11),22);
    bufp->fullIData(oldp+30639,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_12),22);
    bufp->fullIData(oldp+30640,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_13),22);
    bufp->fullIData(oldp+30641,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_14),22);
    bufp->fullIData(oldp+30642,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_15),22);
    bufp->fullIData(oldp+30643,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_16),22);
    bufp->fullIData(oldp+30644,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_17),22);
    bufp->fullIData(oldp+30645,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_18),22);
    bufp->fullIData(oldp+30646,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_19),22);
    bufp->fullIData(oldp+30647,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_20),22);
    bufp->fullIData(oldp+30648,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_21),22);
    bufp->fullIData(oldp+30649,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_22),22);
    bufp->fullIData(oldp+30650,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_23),22);
    bufp->fullIData(oldp+30651,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_24),22);
    bufp->fullIData(oldp+30652,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_25),22);
    bufp->fullIData(oldp+30653,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_26),22);
    bufp->fullIData(oldp+30654,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_27),22);
    bufp->fullIData(oldp+30655,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_28),22);
    bufp->fullIData(oldp+30656,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_29),22);
    bufp->fullIData(oldp+30657,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_30),22);
    bufp->fullIData(oldp+30658,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_31),22);
    bufp->fullIData(oldp+30659,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_32),22);
    bufp->fullIData(oldp+30660,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_33),22);
    bufp->fullIData(oldp+30661,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_34),22);
    bufp->fullIData(oldp+30662,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_35),22);
    bufp->fullIData(oldp+30663,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_36),22);
    bufp->fullIData(oldp+30664,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_37),22);
    bufp->fullIData(oldp+30665,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_38),22);
    bufp->fullIData(oldp+30666,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_39),22);
    bufp->fullIData(oldp+30667,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_40),22);
    bufp->fullIData(oldp+30668,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_41),22);
    bufp->fullIData(oldp+30669,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_42),22);
    bufp->fullIData(oldp+30670,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_43),22);
    bufp->fullIData(oldp+30671,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_44),22);
    bufp->fullIData(oldp+30672,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_45),22);
    bufp->fullIData(oldp+30673,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_46),22);
    bufp->fullIData(oldp+30674,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_47),22);
    bufp->fullIData(oldp+30675,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_48),22);
    bufp->fullIData(oldp+30676,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_49),22);
    bufp->fullIData(oldp+30677,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_50),22);
    bufp->fullIData(oldp+30678,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_51),22);
    bufp->fullIData(oldp+30679,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_52),22);
    bufp->fullIData(oldp+30680,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_53),22);
    bufp->fullIData(oldp+30681,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_54),22);
    bufp->fullIData(oldp+30682,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_55),22);
    bufp->fullIData(oldp+30683,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_56),22);
    bufp->fullIData(oldp+30684,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_57),22);
    bufp->fullIData(oldp+30685,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_58),22);
    bufp->fullIData(oldp+30686,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_59),22);
    bufp->fullIData(oldp+30687,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_60),22);
    bufp->fullIData(oldp+30688,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_61),22);
    bufp->fullIData(oldp+30689,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_62),22);
    bufp->fullIData(oldp+30690,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__mem_63),22);
    bufp->fullWData(oldp+30691,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_0),272);
    bufp->fullWData(oldp+30700,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_1),272);
    bufp->fullWData(oldp+30709,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_2),272);
    bufp->fullWData(oldp+30718,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_3),272);
    bufp->fullWData(oldp+30727,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_4),272);
    bufp->fullWData(oldp+30736,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_5),272);
    bufp->fullWData(oldp+30745,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_6),272);
    bufp->fullWData(oldp+30754,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_7),272);
    bufp->fullWData(oldp+30763,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_8),272);
    bufp->fullWData(oldp+30772,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_9),272);
    bufp->fullWData(oldp+30781,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_10),272);
    bufp->fullWData(oldp+30790,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_11),272);
    bufp->fullWData(oldp+30799,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_12),272);
    bufp->fullWData(oldp+30808,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_13),272);
    bufp->fullWData(oldp+30817,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_14),272);
    bufp->fullWData(oldp+30826,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_15),272);
    bufp->fullWData(oldp+30835,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_16),272);
    bufp->fullWData(oldp+30844,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_17),272);
    bufp->fullWData(oldp+30853,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_18),272);
    bufp->fullWData(oldp+30862,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_19),272);
    bufp->fullWData(oldp+30871,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_20),272);
    bufp->fullWData(oldp+30880,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_21),272);
    bufp->fullWData(oldp+30889,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_22),272);
    bufp->fullWData(oldp+30898,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_23),272);
    bufp->fullWData(oldp+30907,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_24),272);
    bufp->fullWData(oldp+30916,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_25),272);
    bufp->fullWData(oldp+30925,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_26),272);
    bufp->fullWData(oldp+30934,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_27),272);
    bufp->fullWData(oldp+30943,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_28),272);
    bufp->fullWData(oldp+30952,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_29),272);
    bufp->fullWData(oldp+30961,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_30),272);
    bufp->fullWData(oldp+30970,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_31),272);
    bufp->fullWData(oldp+30979,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_32),272);
    bufp->fullWData(oldp+30988,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_33),272);
    bufp->fullWData(oldp+30997,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_34),272);
    bufp->fullWData(oldp+31006,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_35),272);
    bufp->fullWData(oldp+31015,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_36),272);
    bufp->fullWData(oldp+31024,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_37),272);
    bufp->fullWData(oldp+31033,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_38),272);
    bufp->fullWData(oldp+31042,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_39),272);
    bufp->fullWData(oldp+31051,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_40),272);
    bufp->fullWData(oldp+31060,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_41),272);
    bufp->fullWData(oldp+31069,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_42),272);
    bufp->fullWData(oldp+31078,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_43),272);
    bufp->fullWData(oldp+31087,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_44),272);
    bufp->fullWData(oldp+31096,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_45),272);
    bufp->fullWData(oldp+31105,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_46),272);
    bufp->fullWData(oldp+31114,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_47),272);
    bufp->fullWData(oldp+31123,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_48),272);
    bufp->fullWData(oldp+31132,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_49),272);
    bufp->fullWData(oldp+31141,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_50),272);
    bufp->fullWData(oldp+31150,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_51),272);
    bufp->fullWData(oldp+31159,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_52),272);
    bufp->fullWData(oldp+31168,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_53),272);
    bufp->fullWData(oldp+31177,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_54),272);
    bufp->fullWData(oldp+31186,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_55),272);
    bufp->fullWData(oldp+31195,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_56),272);
    bufp->fullWData(oldp+31204,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_57),272);
    bufp->fullWData(oldp+31213,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_58),272);
    bufp->fullWData(oldp+31222,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_59),272);
    bufp->fullWData(oldp+31231,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_60),272);
    bufp->fullWData(oldp+31240,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_61),272);
    bufp->fullWData(oldp+31249,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_62),272);
    bufp->fullWData(oldp+31258,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_63),272);
    bufp->fullWData(oldp+31267,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_64),272);
    bufp->fullWData(oldp+31276,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_65),272);
    bufp->fullWData(oldp+31285,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_66),272);
    bufp->fullWData(oldp+31294,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_67),272);
    bufp->fullWData(oldp+31303,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_68),272);
    bufp->fullWData(oldp+31312,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_69),272);
    bufp->fullWData(oldp+31321,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_70),272);
    bufp->fullWData(oldp+31330,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_71),272);
    bufp->fullWData(oldp+31339,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_72),272);
    bufp->fullWData(oldp+31348,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_73),272);
    bufp->fullWData(oldp+31357,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_74),272);
    bufp->fullWData(oldp+31366,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_75),272);
    bufp->fullWData(oldp+31375,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_76),272);
    bufp->fullWData(oldp+31384,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_77),272);
    bufp->fullWData(oldp+31393,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_78),272);
    bufp->fullWData(oldp+31402,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_79),272);
    bufp->fullWData(oldp+31411,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_80),272);
    bufp->fullWData(oldp+31420,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_81),272);
    bufp->fullWData(oldp+31429,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_82),272);
    bufp->fullWData(oldp+31438,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_83),272);
    bufp->fullWData(oldp+31447,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_84),272);
    bufp->fullWData(oldp+31456,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_85),272);
    bufp->fullWData(oldp+31465,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_86),272);
    bufp->fullWData(oldp+31474,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_87),272);
    bufp->fullWData(oldp+31483,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_88),272);
    bufp->fullWData(oldp+31492,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_89),272);
    bufp->fullWData(oldp+31501,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_90),272);
    bufp->fullWData(oldp+31510,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_91),272);
    bufp->fullWData(oldp+31519,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_92),272);
    bufp->fullWData(oldp+31528,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_93),272);
    bufp->fullWData(oldp+31537,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_94),272);
    bufp->fullWData(oldp+31546,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_95),272);
    bufp->fullWData(oldp+31555,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_96),272);
    bufp->fullWData(oldp+31564,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_97),272);
    bufp->fullWData(oldp+31573,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_98),272);
    bufp->fullWData(oldp+31582,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_99),272);
    bufp->fullWData(oldp+31591,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_100),272);
    bufp->fullWData(oldp+31600,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_101),272);
    bufp->fullWData(oldp+31609,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_102),272);
    bufp->fullWData(oldp+31618,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_103),272);
    bufp->fullWData(oldp+31627,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_104),272);
    bufp->fullWData(oldp+31636,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_105),272);
    bufp->fullWData(oldp+31645,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_106),272);
    bufp->fullWData(oldp+31654,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_107),272);
    bufp->fullWData(oldp+31663,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_108),272);
    bufp->fullWData(oldp+31672,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_109),272);
    bufp->fullWData(oldp+31681,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_110),272);
    bufp->fullWData(oldp+31690,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_111),272);
    bufp->fullWData(oldp+31699,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_112),272);
    bufp->fullWData(oldp+31708,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_113),272);
    bufp->fullWData(oldp+31717,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_114),272);
    bufp->fullWData(oldp+31726,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_115),272);
    bufp->fullWData(oldp+31735,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_116),272);
    bufp->fullWData(oldp+31744,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_117),272);
    bufp->fullWData(oldp+31753,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_118),272);
    bufp->fullWData(oldp+31762,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_119),272);
    bufp->fullWData(oldp+31771,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_120),272);
    bufp->fullWData(oldp+31780,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_121),272);
    bufp->fullWData(oldp+31789,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_122),272);
    bufp->fullWData(oldp+31798,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_123),272);
    bufp->fullWData(oldp+31807,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_124),272);
    bufp->fullWData(oldp+31816,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_125),272);
    bufp->fullWData(oldp+31825,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_126),272);
    bufp->fullWData(oldp+31834,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_127),272);
    bufp->fullWData(oldp+31843,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_128),272);
    bufp->fullWData(oldp+31852,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_129),272);
    bufp->fullWData(oldp+31861,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_130),272);
    bufp->fullWData(oldp+31870,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_131),272);
    bufp->fullWData(oldp+31879,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_132),272);
    bufp->fullWData(oldp+31888,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_133),272);
    bufp->fullWData(oldp+31897,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_134),272);
    bufp->fullWData(oldp+31906,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_135),272);
    bufp->fullWData(oldp+31915,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_136),272);
    bufp->fullWData(oldp+31924,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_137),272);
    bufp->fullWData(oldp+31933,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_138),272);
    bufp->fullWData(oldp+31942,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_139),272);
    bufp->fullWData(oldp+31951,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_140),272);
    bufp->fullWData(oldp+31960,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_141),272);
    bufp->fullWData(oldp+31969,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_142),272);
    bufp->fullWData(oldp+31978,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_143),272);
    bufp->fullWData(oldp+31987,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_144),272);
    bufp->fullWData(oldp+31996,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_145),272);
    bufp->fullWData(oldp+32005,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_146),272);
    bufp->fullWData(oldp+32014,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_147),272);
    bufp->fullWData(oldp+32023,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_148),272);
    bufp->fullWData(oldp+32032,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_149),272);
    bufp->fullWData(oldp+32041,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_150),272);
    bufp->fullWData(oldp+32050,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_151),272);
    bufp->fullWData(oldp+32059,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_152),272);
    bufp->fullWData(oldp+32068,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_153),272);
    bufp->fullWData(oldp+32077,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_154),272);
    bufp->fullWData(oldp+32086,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_155),272);
    bufp->fullWData(oldp+32095,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_156),272);
    bufp->fullWData(oldp+32104,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_157),272);
    bufp->fullWData(oldp+32113,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_158),272);
    bufp->fullWData(oldp+32122,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_159),272);
    bufp->fullWData(oldp+32131,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_160),272);
    bufp->fullWData(oldp+32140,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_161),272);
    bufp->fullWData(oldp+32149,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_162),272);
    bufp->fullWData(oldp+32158,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_163),272);
    bufp->fullWData(oldp+32167,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_164),272);
    bufp->fullWData(oldp+32176,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_165),272);
    bufp->fullWData(oldp+32185,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_166),272);
    bufp->fullWData(oldp+32194,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_167),272);
    bufp->fullWData(oldp+32203,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_168),272);
    bufp->fullWData(oldp+32212,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_169),272);
    bufp->fullWData(oldp+32221,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_170),272);
    bufp->fullWData(oldp+32230,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_171),272);
    bufp->fullWData(oldp+32239,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_172),272);
    bufp->fullWData(oldp+32248,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_173),272);
    bufp->fullWData(oldp+32257,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_174),272);
    bufp->fullWData(oldp+32266,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_175),272);
    bufp->fullWData(oldp+32275,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_176),272);
    bufp->fullWData(oldp+32284,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_177),272);
    bufp->fullWData(oldp+32293,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_178),272);
    bufp->fullWData(oldp+32302,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_179),272);
    bufp->fullWData(oldp+32311,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_180),272);
    bufp->fullWData(oldp+32320,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_181),272);
    bufp->fullWData(oldp+32329,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_182),272);
    bufp->fullWData(oldp+32338,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_183),272);
    bufp->fullWData(oldp+32347,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_184),272);
    bufp->fullWData(oldp+32356,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_185),272);
    bufp->fullWData(oldp+32365,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_186),272);
    bufp->fullWData(oldp+32374,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_187),272);
    bufp->fullWData(oldp+32383,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_188),272);
    bufp->fullWData(oldp+32392,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_189),272);
    bufp->fullWData(oldp+32401,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_190),272);
    bufp->fullWData(oldp+32410,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_191),272);
    bufp->fullWData(oldp+32419,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_192),272);
    bufp->fullWData(oldp+32428,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_193),272);
    bufp->fullWData(oldp+32437,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_194),272);
    bufp->fullWData(oldp+32446,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_195),272);
    bufp->fullWData(oldp+32455,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_196),272);
    bufp->fullWData(oldp+32464,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_197),272);
    bufp->fullWData(oldp+32473,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_198),272);
    bufp->fullWData(oldp+32482,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_199),272);
    bufp->fullWData(oldp+32491,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_200),272);
    bufp->fullWData(oldp+32500,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_201),272);
    bufp->fullWData(oldp+32509,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_202),272);
    bufp->fullWData(oldp+32518,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_203),272);
    bufp->fullWData(oldp+32527,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_204),272);
    bufp->fullWData(oldp+32536,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_205),272);
    bufp->fullWData(oldp+32545,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_206),272);
    bufp->fullWData(oldp+32554,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_207),272);
    bufp->fullWData(oldp+32563,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_208),272);
    bufp->fullWData(oldp+32572,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_209),272);
    bufp->fullWData(oldp+32581,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_210),272);
    bufp->fullWData(oldp+32590,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_211),272);
    bufp->fullWData(oldp+32599,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_212),272);
    bufp->fullWData(oldp+32608,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_213),272);
    bufp->fullWData(oldp+32617,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_214),272);
    bufp->fullWData(oldp+32626,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_215),272);
    bufp->fullWData(oldp+32635,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_216),272);
    bufp->fullWData(oldp+32644,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_217),272);
    bufp->fullWData(oldp+32653,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_218),272);
    bufp->fullWData(oldp+32662,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_219),272);
    bufp->fullWData(oldp+32671,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_220),272);
    bufp->fullWData(oldp+32680,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_221),272);
    bufp->fullWData(oldp+32689,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_222),272);
    bufp->fullWData(oldp+32698,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_223),272);
    bufp->fullWData(oldp+32707,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_224),272);
    bufp->fullWData(oldp+32716,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_225),272);
    bufp->fullWData(oldp+32725,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_226),272);
    bufp->fullWData(oldp+32734,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_227),272);
    bufp->fullWData(oldp+32743,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_228),272);
    bufp->fullWData(oldp+32752,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_229),272);
    bufp->fullWData(oldp+32761,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_230),272);
    bufp->fullWData(oldp+32770,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_231),272);
    bufp->fullWData(oldp+32779,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_232),272);
    bufp->fullWData(oldp+32788,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_233),272);
    bufp->fullWData(oldp+32797,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_234),272);
    bufp->fullWData(oldp+32806,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_235),272);
    bufp->fullWData(oldp+32815,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_236),272);
    bufp->fullWData(oldp+32824,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_237),272);
    bufp->fullWData(oldp+32833,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_238),272);
    bufp->fullWData(oldp+32842,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_239),272);
    bufp->fullWData(oldp+32851,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_240),272);
    bufp->fullWData(oldp+32860,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_241),272);
    bufp->fullWData(oldp+32869,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_242),272);
    bufp->fullWData(oldp+32878,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_243),272);
    bufp->fullWData(oldp+32887,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_244),272);
    bufp->fullWData(oldp+32896,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_245),272);
    bufp->fullWData(oldp+32905,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_246),272);
    bufp->fullWData(oldp+32914,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_247),272);
    bufp->fullWData(oldp+32923,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_248),272);
    bufp->fullWData(oldp+32932,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_249),272);
    bufp->fullWData(oldp+32941,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_250),272);
    bufp->fullWData(oldp+32950,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_251),272);
    bufp->fullWData(oldp+32959,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_252),272);
    bufp->fullWData(oldp+32968,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_253),272);
    bufp->fullWData(oldp+32977,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_254),272);
    bufp->fullWData(oldp+32986,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_0__DOT__source__DOT__mem_255),272);
    bufp->fullWData(oldp+32995,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_0),272);
    bufp->fullWData(oldp+33004,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_1),272);
    bufp->fullWData(oldp+33013,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_2),272);
    bufp->fullWData(oldp+33022,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_3),272);
    bufp->fullWData(oldp+33031,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_4),272);
    bufp->fullWData(oldp+33040,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_5),272);
    bufp->fullWData(oldp+33049,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_6),272);
    bufp->fullWData(oldp+33058,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_7),272);
    bufp->fullWData(oldp+33067,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_8),272);
    bufp->fullWData(oldp+33076,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_9),272);
    bufp->fullWData(oldp+33085,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_10),272);
    bufp->fullWData(oldp+33094,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_11),272);
    bufp->fullWData(oldp+33103,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_12),272);
    bufp->fullWData(oldp+33112,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_13),272);
    bufp->fullWData(oldp+33121,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_14),272);
    bufp->fullWData(oldp+33130,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_15),272);
    bufp->fullWData(oldp+33139,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_16),272);
    bufp->fullWData(oldp+33148,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_17),272);
    bufp->fullWData(oldp+33157,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_18),272);
    bufp->fullWData(oldp+33166,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_19),272);
    bufp->fullWData(oldp+33175,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_20),272);
    bufp->fullWData(oldp+33184,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_21),272);
    bufp->fullWData(oldp+33193,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_22),272);
    bufp->fullWData(oldp+33202,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_23),272);
    bufp->fullWData(oldp+33211,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_24),272);
    bufp->fullWData(oldp+33220,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_25),272);
    bufp->fullWData(oldp+33229,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_26),272);
    bufp->fullWData(oldp+33238,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_27),272);
    bufp->fullWData(oldp+33247,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_28),272);
    bufp->fullWData(oldp+33256,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_29),272);
    bufp->fullWData(oldp+33265,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_30),272);
    bufp->fullWData(oldp+33274,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_31),272);
    bufp->fullWData(oldp+33283,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_32),272);
    bufp->fullWData(oldp+33292,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_33),272);
    bufp->fullWData(oldp+33301,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_34),272);
    bufp->fullWData(oldp+33310,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_35),272);
    bufp->fullWData(oldp+33319,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_36),272);
    bufp->fullWData(oldp+33328,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_37),272);
    bufp->fullWData(oldp+33337,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_38),272);
    bufp->fullWData(oldp+33346,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_39),272);
    bufp->fullWData(oldp+33355,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_40),272);
    bufp->fullWData(oldp+33364,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_41),272);
    bufp->fullWData(oldp+33373,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_42),272);
    bufp->fullWData(oldp+33382,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_43),272);
    bufp->fullWData(oldp+33391,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_44),272);
    bufp->fullWData(oldp+33400,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_45),272);
    bufp->fullWData(oldp+33409,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_46),272);
    bufp->fullWData(oldp+33418,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_47),272);
    bufp->fullWData(oldp+33427,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_48),272);
    bufp->fullWData(oldp+33436,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_49),272);
    bufp->fullWData(oldp+33445,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_50),272);
    bufp->fullWData(oldp+33454,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_51),272);
    bufp->fullWData(oldp+33463,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_52),272);
    bufp->fullWData(oldp+33472,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_53),272);
    bufp->fullWData(oldp+33481,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_54),272);
    bufp->fullWData(oldp+33490,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_55),272);
    bufp->fullWData(oldp+33499,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_56),272);
    bufp->fullWData(oldp+33508,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_57),272);
    bufp->fullWData(oldp+33517,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_58),272);
    bufp->fullWData(oldp+33526,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_59),272);
    bufp->fullWData(oldp+33535,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_60),272);
    bufp->fullWData(oldp+33544,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_61),272);
    bufp->fullWData(oldp+33553,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_62),272);
    bufp->fullWData(oldp+33562,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_63),272);
    bufp->fullWData(oldp+33571,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_64),272);
    bufp->fullWData(oldp+33580,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_65),272);
    bufp->fullWData(oldp+33589,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_66),272);
    bufp->fullWData(oldp+33598,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_67),272);
    bufp->fullWData(oldp+33607,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_68),272);
    bufp->fullWData(oldp+33616,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_69),272);
    bufp->fullWData(oldp+33625,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_70),272);
    bufp->fullWData(oldp+33634,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_71),272);
    bufp->fullWData(oldp+33643,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_72),272);
    bufp->fullWData(oldp+33652,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_73),272);
    bufp->fullWData(oldp+33661,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_74),272);
    bufp->fullWData(oldp+33670,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_75),272);
    bufp->fullWData(oldp+33679,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_76),272);
    bufp->fullWData(oldp+33688,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_77),272);
    bufp->fullWData(oldp+33697,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_78),272);
    bufp->fullWData(oldp+33706,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_79),272);
    bufp->fullWData(oldp+33715,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_80),272);
    bufp->fullWData(oldp+33724,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_81),272);
    bufp->fullWData(oldp+33733,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_82),272);
    bufp->fullWData(oldp+33742,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_83),272);
    bufp->fullWData(oldp+33751,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_84),272);
    bufp->fullWData(oldp+33760,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_85),272);
    bufp->fullWData(oldp+33769,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_86),272);
    bufp->fullWData(oldp+33778,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_87),272);
    bufp->fullWData(oldp+33787,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_88),272);
    bufp->fullWData(oldp+33796,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_89),272);
    bufp->fullWData(oldp+33805,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_90),272);
    bufp->fullWData(oldp+33814,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_91),272);
    bufp->fullWData(oldp+33823,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_92),272);
    bufp->fullWData(oldp+33832,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_93),272);
    bufp->fullWData(oldp+33841,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_94),272);
    bufp->fullWData(oldp+33850,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_95),272);
    bufp->fullWData(oldp+33859,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_96),272);
    bufp->fullWData(oldp+33868,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_97),272);
    bufp->fullWData(oldp+33877,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_98),272);
    bufp->fullWData(oldp+33886,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_99),272);
    bufp->fullWData(oldp+33895,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_100),272);
    bufp->fullWData(oldp+33904,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_101),272);
    bufp->fullWData(oldp+33913,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_102),272);
    bufp->fullWData(oldp+33922,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_103),272);
    bufp->fullWData(oldp+33931,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_104),272);
    bufp->fullWData(oldp+33940,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_105),272);
    bufp->fullWData(oldp+33949,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_106),272);
    bufp->fullWData(oldp+33958,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_107),272);
    bufp->fullWData(oldp+33967,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_108),272);
    bufp->fullWData(oldp+33976,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_109),272);
    bufp->fullWData(oldp+33985,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_110),272);
    bufp->fullWData(oldp+33994,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_111),272);
    bufp->fullWData(oldp+34003,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_112),272);
    bufp->fullWData(oldp+34012,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_113),272);
    bufp->fullWData(oldp+34021,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_114),272);
    bufp->fullWData(oldp+34030,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_115),272);
    bufp->fullWData(oldp+34039,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_116),272);
    bufp->fullWData(oldp+34048,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_117),272);
    bufp->fullWData(oldp+34057,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_118),272);
    bufp->fullWData(oldp+34066,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_119),272);
    bufp->fullWData(oldp+34075,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_120),272);
    bufp->fullWData(oldp+34084,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_121),272);
    bufp->fullWData(oldp+34093,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_122),272);
    bufp->fullWData(oldp+34102,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_123),272);
    bufp->fullWData(oldp+34111,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_124),272);
    bufp->fullWData(oldp+34120,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_125),272);
    bufp->fullWData(oldp+34129,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_126),272);
    bufp->fullWData(oldp+34138,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_127),272);
    bufp->fullWData(oldp+34147,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_128),272);
    bufp->fullWData(oldp+34156,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_129),272);
    bufp->fullWData(oldp+34165,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_130),272);
    bufp->fullWData(oldp+34174,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_131),272);
    bufp->fullWData(oldp+34183,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_132),272);
    bufp->fullWData(oldp+34192,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_133),272);
    bufp->fullWData(oldp+34201,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_134),272);
    bufp->fullWData(oldp+34210,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_135),272);
    bufp->fullWData(oldp+34219,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_136),272);
    bufp->fullWData(oldp+34228,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_137),272);
    bufp->fullWData(oldp+34237,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_138),272);
    bufp->fullWData(oldp+34246,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_139),272);
    bufp->fullWData(oldp+34255,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_140),272);
    bufp->fullWData(oldp+34264,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_141),272);
    bufp->fullWData(oldp+34273,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_142),272);
    bufp->fullWData(oldp+34282,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_143),272);
    bufp->fullWData(oldp+34291,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_144),272);
    bufp->fullWData(oldp+34300,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_145),272);
    bufp->fullWData(oldp+34309,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_146),272);
    bufp->fullWData(oldp+34318,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_147),272);
    bufp->fullWData(oldp+34327,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_148),272);
    bufp->fullWData(oldp+34336,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_149),272);
    bufp->fullWData(oldp+34345,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_150),272);
    bufp->fullWData(oldp+34354,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_151),272);
    bufp->fullWData(oldp+34363,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_152),272);
    bufp->fullWData(oldp+34372,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_153),272);
    bufp->fullWData(oldp+34381,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_154),272);
    bufp->fullWData(oldp+34390,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_155),272);
    bufp->fullWData(oldp+34399,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_156),272);
    bufp->fullWData(oldp+34408,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_157),272);
    bufp->fullWData(oldp+34417,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_158),272);
    bufp->fullWData(oldp+34426,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_159),272);
    bufp->fullWData(oldp+34435,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_160),272);
    bufp->fullWData(oldp+34444,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_161),272);
    bufp->fullWData(oldp+34453,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_162),272);
    bufp->fullWData(oldp+34462,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_163),272);
    bufp->fullWData(oldp+34471,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_164),272);
    bufp->fullWData(oldp+34480,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_165),272);
    bufp->fullWData(oldp+34489,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_166),272);
    bufp->fullWData(oldp+34498,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_167),272);
    bufp->fullWData(oldp+34507,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_168),272);
    bufp->fullWData(oldp+34516,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_169),272);
    bufp->fullWData(oldp+34525,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_170),272);
    bufp->fullWData(oldp+34534,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_171),272);
    bufp->fullWData(oldp+34543,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_172),272);
    bufp->fullWData(oldp+34552,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_173),272);
    bufp->fullWData(oldp+34561,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_174),272);
    bufp->fullWData(oldp+34570,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_175),272);
    bufp->fullWData(oldp+34579,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_176),272);
    bufp->fullWData(oldp+34588,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_177),272);
    bufp->fullWData(oldp+34597,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_178),272);
    bufp->fullWData(oldp+34606,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_179),272);
    bufp->fullWData(oldp+34615,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_180),272);
    bufp->fullWData(oldp+34624,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_181),272);
    bufp->fullWData(oldp+34633,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_182),272);
    bufp->fullWData(oldp+34642,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_183),272);
    bufp->fullWData(oldp+34651,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_184),272);
    bufp->fullWData(oldp+34660,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_185),272);
    bufp->fullWData(oldp+34669,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_186),272);
    bufp->fullWData(oldp+34678,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_187),272);
    bufp->fullWData(oldp+34687,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_188),272);
    bufp->fullWData(oldp+34696,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_189),272);
    bufp->fullWData(oldp+34705,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_190),272);
    bufp->fullWData(oldp+34714,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_191),272);
    bufp->fullWData(oldp+34723,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_192),272);
    bufp->fullWData(oldp+34732,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_193),272);
    bufp->fullWData(oldp+34741,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_194),272);
    bufp->fullWData(oldp+34750,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_195),272);
    bufp->fullWData(oldp+34759,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_196),272);
    bufp->fullWData(oldp+34768,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_197),272);
    bufp->fullWData(oldp+34777,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_198),272);
    bufp->fullWData(oldp+34786,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_199),272);
    bufp->fullWData(oldp+34795,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_200),272);
    bufp->fullWData(oldp+34804,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_201),272);
    bufp->fullWData(oldp+34813,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_202),272);
    bufp->fullWData(oldp+34822,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_203),272);
    bufp->fullWData(oldp+34831,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_204),272);
    bufp->fullWData(oldp+34840,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_205),272);
    bufp->fullWData(oldp+34849,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_206),272);
    bufp->fullWData(oldp+34858,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_207),272);
    bufp->fullWData(oldp+34867,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_208),272);
    bufp->fullWData(oldp+34876,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_209),272);
    bufp->fullWData(oldp+34885,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_210),272);
    bufp->fullWData(oldp+34894,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_211),272);
    bufp->fullWData(oldp+34903,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_212),272);
    bufp->fullWData(oldp+34912,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_213),272);
    bufp->fullWData(oldp+34921,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_214),272);
    bufp->fullWData(oldp+34930,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_215),272);
    bufp->fullWData(oldp+34939,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_216),272);
    bufp->fullWData(oldp+34948,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_217),272);
    bufp->fullWData(oldp+34957,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_218),272);
    bufp->fullWData(oldp+34966,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_219),272);
    bufp->fullWData(oldp+34975,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_220),272);
    bufp->fullWData(oldp+34984,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_221),272);
    bufp->fullWData(oldp+34993,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_222),272);
    bufp->fullWData(oldp+35002,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_223),272);
    bufp->fullWData(oldp+35011,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_224),272);
    bufp->fullWData(oldp+35020,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_225),272);
    bufp->fullWData(oldp+35029,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_226),272);
    bufp->fullWData(oldp+35038,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_227),272);
    bufp->fullWData(oldp+35047,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_228),272);
    bufp->fullWData(oldp+35056,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_229),272);
    bufp->fullWData(oldp+35065,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_230),272);
    bufp->fullWData(oldp+35074,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_231),272);
    bufp->fullWData(oldp+35083,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_232),272);
    bufp->fullWData(oldp+35092,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_233),272);
    bufp->fullWData(oldp+35101,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_234),272);
    bufp->fullWData(oldp+35110,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_235),272);
    bufp->fullWData(oldp+35119,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_236),272);
    bufp->fullWData(oldp+35128,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_237),272);
    bufp->fullWData(oldp+35137,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_238),272);
    bufp->fullWData(oldp+35146,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_239),272);
    bufp->fullWData(oldp+35155,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_240),272);
    bufp->fullWData(oldp+35164,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_241),272);
    bufp->fullWData(oldp+35173,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_242),272);
    bufp->fullWData(oldp+35182,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_243),272);
    bufp->fullWData(oldp+35191,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_244),272);
    bufp->fullWData(oldp+35200,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_245),272);
    bufp->fullWData(oldp+35209,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_246),272);
    bufp->fullWData(oldp+35218,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_247),272);
    bufp->fullWData(oldp+35227,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_248),272);
    bufp->fullWData(oldp+35236,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_249),272);
    bufp->fullWData(oldp+35245,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_250),272);
    bufp->fullWData(oldp+35254,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_251),272);
    bufp->fullWData(oldp+35263,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_252),272);
    bufp->fullWData(oldp+35272,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_253),272);
    bufp->fullWData(oldp+35281,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_254),272);
    bufp->fullWData(oldp+35290,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_1__DOT__source__DOT__mem_255),272);
    bufp->fullWData(oldp+35299,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_0),272);
    bufp->fullWData(oldp+35308,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_1),272);
    bufp->fullWData(oldp+35317,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_2),272);
    bufp->fullWData(oldp+35326,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_3),272);
    bufp->fullWData(oldp+35335,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_4),272);
    bufp->fullWData(oldp+35344,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_5),272);
    bufp->fullWData(oldp+35353,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_6),272);
    bufp->fullWData(oldp+35362,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_7),272);
    bufp->fullWData(oldp+35371,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_8),272);
    bufp->fullWData(oldp+35380,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_9),272);
    bufp->fullWData(oldp+35389,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_10),272);
    bufp->fullWData(oldp+35398,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_11),272);
    bufp->fullWData(oldp+35407,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_12),272);
    bufp->fullWData(oldp+35416,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_13),272);
    bufp->fullWData(oldp+35425,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_14),272);
    bufp->fullWData(oldp+35434,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_15),272);
    bufp->fullWData(oldp+35443,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_16),272);
    bufp->fullWData(oldp+35452,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_17),272);
    bufp->fullWData(oldp+35461,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_18),272);
    bufp->fullWData(oldp+35470,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_19),272);
    bufp->fullWData(oldp+35479,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_20),272);
    bufp->fullWData(oldp+35488,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_21),272);
    bufp->fullWData(oldp+35497,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_22),272);
    bufp->fullWData(oldp+35506,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_23),272);
    bufp->fullWData(oldp+35515,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_24),272);
    bufp->fullWData(oldp+35524,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_25),272);
    bufp->fullWData(oldp+35533,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_26),272);
    bufp->fullWData(oldp+35542,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_27),272);
    bufp->fullWData(oldp+35551,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_28),272);
    bufp->fullWData(oldp+35560,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_29),272);
    bufp->fullWData(oldp+35569,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_30),272);
    bufp->fullWData(oldp+35578,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_31),272);
    bufp->fullWData(oldp+35587,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_32),272);
    bufp->fullWData(oldp+35596,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_33),272);
    bufp->fullWData(oldp+35605,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_34),272);
    bufp->fullWData(oldp+35614,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_35),272);
    bufp->fullWData(oldp+35623,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_36),272);
    bufp->fullWData(oldp+35632,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_37),272);
    bufp->fullWData(oldp+35641,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_38),272);
    bufp->fullWData(oldp+35650,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_39),272);
    bufp->fullWData(oldp+35659,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_40),272);
    bufp->fullWData(oldp+35668,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_41),272);
    bufp->fullWData(oldp+35677,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_42),272);
    bufp->fullWData(oldp+35686,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_43),272);
    bufp->fullWData(oldp+35695,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_44),272);
    bufp->fullWData(oldp+35704,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_45),272);
    bufp->fullWData(oldp+35713,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_46),272);
    bufp->fullWData(oldp+35722,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_47),272);
    bufp->fullWData(oldp+35731,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_48),272);
    bufp->fullWData(oldp+35740,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_49),272);
    bufp->fullWData(oldp+35749,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_50),272);
    bufp->fullWData(oldp+35758,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_51),272);
    bufp->fullWData(oldp+35767,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_52),272);
    bufp->fullWData(oldp+35776,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_53),272);
    bufp->fullWData(oldp+35785,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_54),272);
    bufp->fullWData(oldp+35794,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_55),272);
    bufp->fullWData(oldp+35803,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_56),272);
    bufp->fullWData(oldp+35812,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_57),272);
    bufp->fullWData(oldp+35821,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_58),272);
    bufp->fullWData(oldp+35830,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_59),272);
    bufp->fullWData(oldp+35839,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_60),272);
    bufp->fullWData(oldp+35848,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_61),272);
    bufp->fullWData(oldp+35857,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_62),272);
    bufp->fullWData(oldp+35866,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_63),272);
    bufp->fullWData(oldp+35875,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_64),272);
    bufp->fullWData(oldp+35884,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_65),272);
    bufp->fullWData(oldp+35893,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_66),272);
    bufp->fullWData(oldp+35902,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_67),272);
    bufp->fullWData(oldp+35911,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_68),272);
    bufp->fullWData(oldp+35920,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_69),272);
    bufp->fullWData(oldp+35929,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_70),272);
    bufp->fullWData(oldp+35938,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_71),272);
    bufp->fullWData(oldp+35947,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_72),272);
    bufp->fullWData(oldp+35956,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_73),272);
    bufp->fullWData(oldp+35965,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_74),272);
    bufp->fullWData(oldp+35974,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_75),272);
    bufp->fullWData(oldp+35983,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_76),272);
    bufp->fullWData(oldp+35992,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_77),272);
    bufp->fullWData(oldp+36001,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_78),272);
    bufp->fullWData(oldp+36010,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_79),272);
    bufp->fullWData(oldp+36019,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_80),272);
    bufp->fullWData(oldp+36028,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_81),272);
    bufp->fullWData(oldp+36037,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_82),272);
    bufp->fullWData(oldp+36046,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_83),272);
    bufp->fullWData(oldp+36055,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_84),272);
    bufp->fullWData(oldp+36064,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_85),272);
    bufp->fullWData(oldp+36073,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_86),272);
    bufp->fullWData(oldp+36082,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_87),272);
    bufp->fullWData(oldp+36091,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_88),272);
    bufp->fullWData(oldp+36100,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_89),272);
    bufp->fullWData(oldp+36109,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_90),272);
    bufp->fullWData(oldp+36118,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_91),272);
    bufp->fullWData(oldp+36127,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_92),272);
    bufp->fullWData(oldp+36136,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_93),272);
    bufp->fullWData(oldp+36145,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_94),272);
    bufp->fullWData(oldp+36154,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_95),272);
    bufp->fullWData(oldp+36163,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_96),272);
    bufp->fullWData(oldp+36172,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_97),272);
    bufp->fullWData(oldp+36181,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_98),272);
    bufp->fullWData(oldp+36190,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_99),272);
    bufp->fullWData(oldp+36199,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_100),272);
    bufp->fullWData(oldp+36208,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_101),272);
    bufp->fullWData(oldp+36217,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_102),272);
    bufp->fullWData(oldp+36226,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_103),272);
    bufp->fullWData(oldp+36235,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_104),272);
    bufp->fullWData(oldp+36244,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_105),272);
    bufp->fullWData(oldp+36253,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_106),272);
    bufp->fullWData(oldp+36262,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_107),272);
    bufp->fullWData(oldp+36271,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_108),272);
    bufp->fullWData(oldp+36280,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_109),272);
    bufp->fullWData(oldp+36289,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_110),272);
    bufp->fullWData(oldp+36298,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_111),272);
    bufp->fullWData(oldp+36307,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_112),272);
    bufp->fullWData(oldp+36316,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_113),272);
    bufp->fullWData(oldp+36325,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_114),272);
    bufp->fullWData(oldp+36334,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_115),272);
    bufp->fullWData(oldp+36343,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_116),272);
    bufp->fullWData(oldp+36352,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_117),272);
    bufp->fullWData(oldp+36361,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_118),272);
    bufp->fullWData(oldp+36370,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_119),272);
    bufp->fullWData(oldp+36379,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_120),272);
    bufp->fullWData(oldp+36388,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_121),272);
    bufp->fullWData(oldp+36397,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_122),272);
    bufp->fullWData(oldp+36406,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_123),272);
    bufp->fullWData(oldp+36415,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_124),272);
    bufp->fullWData(oldp+36424,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_125),272);
    bufp->fullWData(oldp+36433,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_126),272);
    bufp->fullWData(oldp+36442,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_127),272);
    bufp->fullWData(oldp+36451,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_128),272);
    bufp->fullWData(oldp+36460,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_129),272);
    bufp->fullWData(oldp+36469,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_130),272);
    bufp->fullWData(oldp+36478,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_131),272);
    bufp->fullWData(oldp+36487,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_132),272);
    bufp->fullWData(oldp+36496,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_133),272);
    bufp->fullWData(oldp+36505,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_134),272);
    bufp->fullWData(oldp+36514,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_135),272);
    bufp->fullWData(oldp+36523,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_136),272);
    bufp->fullWData(oldp+36532,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_137),272);
    bufp->fullWData(oldp+36541,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_138),272);
    bufp->fullWData(oldp+36550,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_139),272);
    bufp->fullWData(oldp+36559,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_140),272);
    bufp->fullWData(oldp+36568,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_141),272);
    bufp->fullWData(oldp+36577,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_142),272);
    bufp->fullWData(oldp+36586,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_143),272);
    bufp->fullWData(oldp+36595,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_144),272);
    bufp->fullWData(oldp+36604,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_145),272);
    bufp->fullWData(oldp+36613,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_146),272);
    bufp->fullWData(oldp+36622,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_147),272);
    bufp->fullWData(oldp+36631,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_148),272);
    bufp->fullWData(oldp+36640,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_149),272);
    bufp->fullWData(oldp+36649,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_150),272);
    bufp->fullWData(oldp+36658,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_151),272);
    bufp->fullWData(oldp+36667,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_152),272);
    bufp->fullWData(oldp+36676,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_153),272);
    bufp->fullWData(oldp+36685,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_154),272);
    bufp->fullWData(oldp+36694,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_155),272);
    bufp->fullWData(oldp+36703,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_156),272);
    bufp->fullWData(oldp+36712,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_157),272);
    bufp->fullWData(oldp+36721,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_158),272);
    bufp->fullWData(oldp+36730,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_159),272);
    bufp->fullWData(oldp+36739,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_160),272);
    bufp->fullWData(oldp+36748,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_161),272);
    bufp->fullWData(oldp+36757,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_162),272);
    bufp->fullWData(oldp+36766,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_163),272);
    bufp->fullWData(oldp+36775,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_164),272);
    bufp->fullWData(oldp+36784,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_165),272);
    bufp->fullWData(oldp+36793,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_166),272);
    bufp->fullWData(oldp+36802,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_167),272);
    bufp->fullWData(oldp+36811,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_168),272);
    bufp->fullWData(oldp+36820,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_169),272);
    bufp->fullWData(oldp+36829,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_170),272);
    bufp->fullWData(oldp+36838,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_171),272);
    bufp->fullWData(oldp+36847,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_172),272);
    bufp->fullWData(oldp+36856,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_173),272);
    bufp->fullWData(oldp+36865,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_174),272);
    bufp->fullWData(oldp+36874,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_175),272);
    bufp->fullWData(oldp+36883,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_176),272);
    bufp->fullWData(oldp+36892,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_177),272);
    bufp->fullWData(oldp+36901,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_178),272);
    bufp->fullWData(oldp+36910,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_179),272);
    bufp->fullWData(oldp+36919,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_180),272);
    bufp->fullWData(oldp+36928,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_181),272);
    bufp->fullWData(oldp+36937,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_182),272);
    bufp->fullWData(oldp+36946,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_183),272);
    bufp->fullWData(oldp+36955,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_184),272);
    bufp->fullWData(oldp+36964,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_185),272);
    bufp->fullWData(oldp+36973,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_186),272);
    bufp->fullWData(oldp+36982,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_187),272);
    bufp->fullWData(oldp+36991,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_188),272);
    bufp->fullWData(oldp+37000,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_189),272);
    bufp->fullWData(oldp+37009,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_190),272);
    bufp->fullWData(oldp+37018,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_191),272);
    bufp->fullWData(oldp+37027,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_192),272);
    bufp->fullWData(oldp+37036,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_193),272);
    bufp->fullWData(oldp+37045,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_194),272);
    bufp->fullWData(oldp+37054,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_195),272);
    bufp->fullWData(oldp+37063,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_196),272);
    bufp->fullWData(oldp+37072,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_197),272);
    bufp->fullWData(oldp+37081,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_198),272);
    bufp->fullWData(oldp+37090,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_199),272);
    bufp->fullWData(oldp+37099,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_200),272);
    bufp->fullWData(oldp+37108,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_201),272);
    bufp->fullWData(oldp+37117,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_202),272);
    bufp->fullWData(oldp+37126,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_203),272);
    bufp->fullWData(oldp+37135,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_204),272);
    bufp->fullWData(oldp+37144,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_205),272);
    bufp->fullWData(oldp+37153,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_206),272);
    bufp->fullWData(oldp+37162,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_207),272);
    bufp->fullWData(oldp+37171,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_208),272);
    bufp->fullWData(oldp+37180,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_209),272);
    bufp->fullWData(oldp+37189,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_210),272);
    bufp->fullWData(oldp+37198,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_211),272);
    bufp->fullWData(oldp+37207,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_212),272);
    bufp->fullWData(oldp+37216,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_213),272);
    bufp->fullWData(oldp+37225,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_214),272);
    bufp->fullWData(oldp+37234,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_215),272);
    bufp->fullWData(oldp+37243,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_216),272);
    bufp->fullWData(oldp+37252,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_217),272);
    bufp->fullWData(oldp+37261,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_218),272);
    bufp->fullWData(oldp+37270,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_219),272);
    bufp->fullWData(oldp+37279,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_220),272);
    bufp->fullWData(oldp+37288,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_221),272);
    bufp->fullWData(oldp+37297,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_222),272);
    bufp->fullWData(oldp+37306,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_223),272);
    bufp->fullWData(oldp+37315,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_224),272);
    bufp->fullWData(oldp+37324,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_225),272);
    bufp->fullWData(oldp+37333,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_226),272);
    bufp->fullWData(oldp+37342,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_227),272);
    bufp->fullWData(oldp+37351,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_228),272);
    bufp->fullWData(oldp+37360,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_229),272);
    bufp->fullWData(oldp+37369,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_230),272);
    bufp->fullWData(oldp+37378,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_231),272);
    bufp->fullWData(oldp+37387,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_232),272);
    bufp->fullWData(oldp+37396,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_233),272);
    bufp->fullWData(oldp+37405,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_234),272);
    bufp->fullWData(oldp+37414,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_235),272);
    bufp->fullWData(oldp+37423,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_236),272);
    bufp->fullWData(oldp+37432,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_237),272);
    bufp->fullWData(oldp+37441,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_238),272);
    bufp->fullWData(oldp+37450,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_239),272);
    bufp->fullWData(oldp+37459,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_240),272);
    bufp->fullWData(oldp+37468,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_241),272);
    bufp->fullWData(oldp+37477,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_242),272);
    bufp->fullWData(oldp+37486,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_243),272);
    bufp->fullWData(oldp+37495,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_244),272);
    bufp->fullWData(oldp+37504,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_245),272);
    bufp->fullWData(oldp+37513,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_246),272);
    bufp->fullWData(oldp+37522,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_247),272);
    bufp->fullWData(oldp+37531,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_248),272);
    bufp->fullWData(oldp+37540,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_249),272);
    bufp->fullWData(oldp+37549,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_250),272);
    bufp->fullWData(oldp+37558,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_251),272);
    bufp->fullWData(oldp+37567,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_252),272);
    bufp->fullWData(oldp+37576,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_253),272);
    bufp->fullWData(oldp+37585,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_254),272);
    bufp->fullWData(oldp+37594,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_2__DOT__source__DOT__mem_255),272);
    bufp->fullWData(oldp+37603,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_0),272);
    bufp->fullWData(oldp+37612,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_1),272);
    bufp->fullWData(oldp+37621,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_2),272);
    bufp->fullWData(oldp+37630,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_3),272);
    bufp->fullWData(oldp+37639,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_4),272);
    bufp->fullWData(oldp+37648,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_5),272);
    bufp->fullWData(oldp+37657,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_6),272);
    bufp->fullWData(oldp+37666,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_7),272);
    bufp->fullWData(oldp+37675,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_8),272);
    bufp->fullWData(oldp+37684,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_9),272);
    bufp->fullWData(oldp+37693,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_10),272);
    bufp->fullWData(oldp+37702,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_11),272);
    bufp->fullWData(oldp+37711,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_12),272);
    bufp->fullWData(oldp+37720,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_13),272);
    bufp->fullWData(oldp+37729,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_14),272);
    bufp->fullWData(oldp+37738,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_15),272);
    bufp->fullWData(oldp+37747,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_16),272);
    bufp->fullWData(oldp+37756,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_17),272);
    bufp->fullWData(oldp+37765,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_18),272);
    bufp->fullWData(oldp+37774,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_19),272);
    bufp->fullWData(oldp+37783,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_20),272);
    bufp->fullWData(oldp+37792,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_21),272);
    bufp->fullWData(oldp+37801,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_22),272);
    bufp->fullWData(oldp+37810,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_23),272);
    bufp->fullWData(oldp+37819,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_24),272);
    bufp->fullWData(oldp+37828,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_25),272);
    bufp->fullWData(oldp+37837,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_26),272);
    bufp->fullWData(oldp+37846,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_27),272);
    bufp->fullWData(oldp+37855,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_28),272);
    bufp->fullWData(oldp+37864,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_29),272);
    bufp->fullWData(oldp+37873,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_30),272);
    bufp->fullWData(oldp+37882,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_31),272);
    bufp->fullWData(oldp+37891,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_32),272);
    bufp->fullWData(oldp+37900,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_33),272);
    bufp->fullWData(oldp+37909,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_34),272);
    bufp->fullWData(oldp+37918,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_35),272);
    bufp->fullWData(oldp+37927,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_36),272);
    bufp->fullWData(oldp+37936,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_37),272);
    bufp->fullWData(oldp+37945,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_38),272);
    bufp->fullWData(oldp+37954,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_39),272);
    bufp->fullWData(oldp+37963,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_40),272);
    bufp->fullWData(oldp+37972,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_41),272);
    bufp->fullWData(oldp+37981,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_42),272);
    bufp->fullWData(oldp+37990,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_43),272);
    bufp->fullWData(oldp+37999,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_44),272);
    bufp->fullWData(oldp+38008,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_45),272);
    bufp->fullWData(oldp+38017,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_46),272);
    bufp->fullWData(oldp+38026,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_47),272);
    bufp->fullWData(oldp+38035,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_48),272);
    bufp->fullWData(oldp+38044,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_49),272);
    bufp->fullWData(oldp+38053,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_50),272);
    bufp->fullWData(oldp+38062,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_51),272);
    bufp->fullWData(oldp+38071,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_52),272);
    bufp->fullWData(oldp+38080,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_53),272);
    bufp->fullWData(oldp+38089,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_54),272);
    bufp->fullWData(oldp+38098,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_55),272);
    bufp->fullWData(oldp+38107,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_56),272);
    bufp->fullWData(oldp+38116,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_57),272);
    bufp->fullWData(oldp+38125,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_58),272);
    bufp->fullWData(oldp+38134,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_59),272);
    bufp->fullWData(oldp+38143,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_60),272);
    bufp->fullWData(oldp+38152,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_61),272);
    bufp->fullWData(oldp+38161,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_62),272);
    bufp->fullWData(oldp+38170,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_63),272);
    bufp->fullWData(oldp+38179,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_64),272);
    bufp->fullWData(oldp+38188,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_65),272);
    bufp->fullWData(oldp+38197,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_66),272);
    bufp->fullWData(oldp+38206,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_67),272);
    bufp->fullWData(oldp+38215,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_68),272);
    bufp->fullWData(oldp+38224,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_69),272);
    bufp->fullWData(oldp+38233,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_70),272);
    bufp->fullWData(oldp+38242,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_71),272);
    bufp->fullWData(oldp+38251,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_72),272);
    bufp->fullWData(oldp+38260,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_73),272);
    bufp->fullWData(oldp+38269,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_74),272);
    bufp->fullWData(oldp+38278,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_75),272);
    bufp->fullWData(oldp+38287,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_76),272);
    bufp->fullWData(oldp+38296,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_77),272);
    bufp->fullWData(oldp+38305,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_78),272);
    bufp->fullWData(oldp+38314,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_79),272);
    bufp->fullWData(oldp+38323,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_80),272);
    bufp->fullWData(oldp+38332,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_81),272);
    bufp->fullWData(oldp+38341,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_82),272);
    bufp->fullWData(oldp+38350,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_83),272);
    bufp->fullWData(oldp+38359,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_84),272);
    bufp->fullWData(oldp+38368,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_85),272);
    bufp->fullWData(oldp+38377,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_86),272);
    bufp->fullWData(oldp+38386,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_87),272);
    bufp->fullWData(oldp+38395,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_88),272);
    bufp->fullWData(oldp+38404,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_89),272);
    bufp->fullWData(oldp+38413,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_90),272);
    bufp->fullWData(oldp+38422,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_91),272);
    bufp->fullWData(oldp+38431,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_92),272);
    bufp->fullWData(oldp+38440,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_93),272);
    bufp->fullWData(oldp+38449,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_94),272);
    bufp->fullWData(oldp+38458,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_95),272);
    bufp->fullWData(oldp+38467,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_96),272);
    bufp->fullWData(oldp+38476,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_97),272);
    bufp->fullWData(oldp+38485,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_98),272);
    bufp->fullWData(oldp+38494,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_99),272);
    bufp->fullWData(oldp+38503,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_100),272);
    bufp->fullWData(oldp+38512,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_101),272);
    bufp->fullWData(oldp+38521,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_102),272);
    bufp->fullWData(oldp+38530,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_103),272);
    bufp->fullWData(oldp+38539,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_104),272);
    bufp->fullWData(oldp+38548,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_105),272);
    bufp->fullWData(oldp+38557,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_106),272);
    bufp->fullWData(oldp+38566,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_107),272);
    bufp->fullWData(oldp+38575,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_108),272);
    bufp->fullWData(oldp+38584,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_109),272);
    bufp->fullWData(oldp+38593,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_110),272);
    bufp->fullWData(oldp+38602,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_111),272);
    bufp->fullWData(oldp+38611,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_112),272);
    bufp->fullWData(oldp+38620,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_113),272);
    bufp->fullWData(oldp+38629,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_114),272);
    bufp->fullWData(oldp+38638,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_115),272);
    bufp->fullWData(oldp+38647,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_116),272);
    bufp->fullWData(oldp+38656,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_117),272);
    bufp->fullWData(oldp+38665,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_118),272);
    bufp->fullWData(oldp+38674,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_119),272);
    bufp->fullWData(oldp+38683,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_120),272);
    bufp->fullWData(oldp+38692,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_121),272);
    bufp->fullWData(oldp+38701,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_122),272);
    bufp->fullWData(oldp+38710,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_123),272);
    bufp->fullWData(oldp+38719,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_124),272);
    bufp->fullWData(oldp+38728,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_125),272);
    bufp->fullWData(oldp+38737,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_126),272);
    bufp->fullWData(oldp+38746,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_127),272);
    bufp->fullWData(oldp+38755,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_128),272);
    bufp->fullWData(oldp+38764,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_129),272);
    bufp->fullWData(oldp+38773,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_130),272);
    bufp->fullWData(oldp+38782,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_131),272);
    bufp->fullWData(oldp+38791,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_132),272);
    bufp->fullWData(oldp+38800,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_133),272);
    bufp->fullWData(oldp+38809,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_134),272);
    bufp->fullWData(oldp+38818,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_135),272);
    bufp->fullWData(oldp+38827,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_136),272);
    bufp->fullWData(oldp+38836,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_137),272);
    bufp->fullWData(oldp+38845,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_138),272);
    bufp->fullWData(oldp+38854,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_139),272);
    bufp->fullWData(oldp+38863,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_140),272);
    bufp->fullWData(oldp+38872,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_141),272);
    bufp->fullWData(oldp+38881,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_142),272);
    bufp->fullWData(oldp+38890,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_143),272);
    bufp->fullWData(oldp+38899,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_144),272);
    bufp->fullWData(oldp+38908,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_145),272);
    bufp->fullWData(oldp+38917,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_146),272);
    bufp->fullWData(oldp+38926,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_147),272);
    bufp->fullWData(oldp+38935,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_148),272);
    bufp->fullWData(oldp+38944,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_149),272);
    bufp->fullWData(oldp+38953,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_150),272);
    bufp->fullWData(oldp+38962,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_151),272);
    bufp->fullWData(oldp+38971,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_152),272);
    bufp->fullWData(oldp+38980,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_153),272);
    bufp->fullWData(oldp+38989,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_154),272);
    bufp->fullWData(oldp+38998,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_155),272);
    bufp->fullWData(oldp+39007,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_156),272);
    bufp->fullWData(oldp+39016,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_157),272);
    bufp->fullWData(oldp+39025,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_158),272);
    bufp->fullWData(oldp+39034,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_159),272);
    bufp->fullWData(oldp+39043,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_160),272);
    bufp->fullWData(oldp+39052,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_161),272);
    bufp->fullWData(oldp+39061,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_162),272);
    bufp->fullWData(oldp+39070,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_163),272);
    bufp->fullWData(oldp+39079,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_164),272);
    bufp->fullWData(oldp+39088,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_165),272);
    bufp->fullWData(oldp+39097,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_166),272);
    bufp->fullWData(oldp+39106,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_167),272);
    bufp->fullWData(oldp+39115,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_168),272);
    bufp->fullWData(oldp+39124,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_169),272);
    bufp->fullWData(oldp+39133,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_170),272);
    bufp->fullWData(oldp+39142,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_171),272);
    bufp->fullWData(oldp+39151,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_172),272);
    bufp->fullWData(oldp+39160,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_173),272);
    bufp->fullWData(oldp+39169,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_174),272);
    bufp->fullWData(oldp+39178,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_175),272);
    bufp->fullWData(oldp+39187,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_176),272);
    bufp->fullWData(oldp+39196,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_177),272);
    bufp->fullWData(oldp+39205,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_178),272);
    bufp->fullWData(oldp+39214,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_179),272);
    bufp->fullWData(oldp+39223,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_180),272);
    bufp->fullWData(oldp+39232,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_181),272);
    bufp->fullWData(oldp+39241,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_182),272);
    bufp->fullWData(oldp+39250,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_183),272);
    bufp->fullWData(oldp+39259,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_184),272);
    bufp->fullWData(oldp+39268,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_185),272);
    bufp->fullWData(oldp+39277,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_186),272);
    bufp->fullWData(oldp+39286,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_187),272);
    bufp->fullWData(oldp+39295,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_188),272);
    bufp->fullWData(oldp+39304,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_189),272);
    bufp->fullWData(oldp+39313,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_190),272);
    bufp->fullWData(oldp+39322,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_191),272);
    bufp->fullWData(oldp+39331,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_192),272);
    bufp->fullWData(oldp+39340,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_193),272);
    bufp->fullWData(oldp+39349,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_194),272);
    bufp->fullWData(oldp+39358,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_195),272);
    bufp->fullWData(oldp+39367,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_196),272);
    bufp->fullWData(oldp+39376,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_197),272);
    bufp->fullWData(oldp+39385,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_198),272);
    bufp->fullWData(oldp+39394,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_199),272);
    bufp->fullWData(oldp+39403,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_200),272);
    bufp->fullWData(oldp+39412,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_201),272);
    bufp->fullWData(oldp+39421,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_202),272);
    bufp->fullWData(oldp+39430,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_203),272);
    bufp->fullWData(oldp+39439,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_204),272);
    bufp->fullWData(oldp+39448,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_205),272);
    bufp->fullWData(oldp+39457,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_206),272);
    bufp->fullWData(oldp+39466,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_207),272);
    bufp->fullWData(oldp+39475,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_208),272);
    bufp->fullWData(oldp+39484,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_209),272);
    bufp->fullWData(oldp+39493,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_210),272);
    bufp->fullWData(oldp+39502,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_211),272);
    bufp->fullWData(oldp+39511,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_212),272);
    bufp->fullWData(oldp+39520,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_213),272);
    bufp->fullWData(oldp+39529,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_214),272);
    bufp->fullWData(oldp+39538,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_215),272);
    bufp->fullWData(oldp+39547,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_216),272);
    bufp->fullWData(oldp+39556,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_217),272);
    bufp->fullWData(oldp+39565,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_218),272);
    bufp->fullWData(oldp+39574,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_219),272);
    bufp->fullWData(oldp+39583,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_220),272);
    bufp->fullWData(oldp+39592,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_221),272);
    bufp->fullWData(oldp+39601,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_222),272);
    bufp->fullWData(oldp+39610,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_223),272);
    bufp->fullWData(oldp+39619,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_224),272);
    bufp->fullWData(oldp+39628,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_225),272);
    bufp->fullWData(oldp+39637,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_226),272);
    bufp->fullWData(oldp+39646,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_227),272);
    bufp->fullWData(oldp+39655,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_228),272);
    bufp->fullWData(oldp+39664,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_229),272);
    bufp->fullWData(oldp+39673,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_230),272);
    bufp->fullWData(oldp+39682,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_231),272);
    bufp->fullWData(oldp+39691,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_232),272);
    bufp->fullWData(oldp+39700,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_233),272);
    bufp->fullWData(oldp+39709,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_234),272);
    bufp->fullWData(oldp+39718,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_235),272);
    bufp->fullWData(oldp+39727,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_236),272);
    bufp->fullWData(oldp+39736,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_237),272);
    bufp->fullWData(oldp+39745,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_238),272);
    bufp->fullWData(oldp+39754,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_239),272);
    bufp->fullWData(oldp+39763,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_240),272);
    bufp->fullWData(oldp+39772,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_241),272);
    bufp->fullWData(oldp+39781,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_242),272);
    bufp->fullWData(oldp+39790,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_243),272);
    bufp->fullWData(oldp+39799,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_244),272);
    bufp->fullWData(oldp+39808,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_245),272);
    bufp->fullWData(oldp+39817,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_246),272);
    bufp->fullWData(oldp+39826,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_247),272);
    bufp->fullWData(oldp+39835,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_248),272);
    bufp->fullWData(oldp+39844,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_249),272);
    bufp->fullWData(oldp+39853,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_250),272);
    bufp->fullWData(oldp+39862,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_251),272);
    bufp->fullWData(oldp+39871,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_252),272);
    bufp->fullWData(oldp+39880,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_253),272);
    bufp->fullWData(oldp+39889,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_254),272);
    bufp->fullWData(oldp+39898,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__mem_255),272);
    bufp->fullSData(oldp+39907,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_0__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg),9);
    bufp->fullSData(oldp+39908,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_1__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg),9);
    bufp->fullSData(oldp+39909,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_2__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg),9);
    bufp->fullSData(oldp+39910,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg),9);
    bufp->fullBit(oldp+39911,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_back__DOT__maybe_full)))));
    bufp->fullBit(oldp+39912,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_back__DOT__maybe_full));
    bufp->fullBit(oldp+39913,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__pending_0));
    bufp->fullBit(oldp+39914,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_0_0));
    bufp->fullBit(oldp+39915,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_1_0));
    bufp->fullBit(oldp+39916,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_2_0));
    bufp->fullBit(oldp+39917,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_3_0));
    bufp->fullBit(oldp+39918,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_4_0));
    bufp->fullBit(oldp+39919,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_5_0));
    bufp->fullBit(oldp+39920,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_6_0));
    bufp->fullBit(oldp+39921,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_7_0));
    bufp->fullBit(oldp+39922,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_8_0));
    bufp->fullBit(oldp+39923,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_9_0));
    bufp->fullBit(oldp+39924,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__maxDevs_0));
    bufp->fullBit(oldp+39925,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__maxDevs_1));
    bufp->fullBit(oldp+39926,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__maxDevs_2));
    bufp->fullBit(oldp+39927,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__maxDevs_3));
    bufp->fullBit(oldp+39928,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__maxDevs_4));
    bufp->fullBit(oldp+39929,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__maxDevs_5));
    bufp->fullBit(oldp+39930,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__maxDevs_6));
    bufp->fullBit(oldp+39931,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__maxDevs_7));
    bufp->fullBit(oldp+39932,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__maxDevs_8));
    bufp->fullBit(oldp+39933,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__maxDevs_9));
    bufp->fullBit(oldp+39934,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_0_0) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__pending_0))));
    bufp->fullBit(oldp+39935,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_1_0) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__pending_0))));
    bufp->fullBit(oldp+39936,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_2_0) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__pending_0))));
    bufp->fullBit(oldp+39937,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_3_0) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__pending_0))));
    bufp->fullBit(oldp+39938,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_4_0) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__pending_0))));
    bufp->fullBit(oldp+39939,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_5_0) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__pending_0))));
    bufp->fullBit(oldp+39940,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_6_0) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__pending_0))));
    bufp->fullBit(oldp+39941,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_7_0) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__pending_0))));
    bufp->fullBit(oldp+39942,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_8_0) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__pending_0))));
    bufp->fullBit(oldp+39943,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__enables_9_0) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__pending_0))));
    bufp->fullBit(oldp+39944,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__pending_0)))));
    bufp->fullBit(oldp+39945,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__gateways_gateway__DOT__inFlight));
    bufp->fullWData(oldp+39946,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__inflight),1040);
    bufp->fullWData(oldp+39979,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__inflight_opcodes),4160);
    bufp->fullWData(oldp+40109,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__inflight_sizes),4160);
    bufp->fullIData(oldp+40239,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__monitor__DOT__watchdog),32);
    bufp->fullBit(oldp+40240,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT__empty)))));
    bufp->fullBit(oldp+40241,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full)))));
    bufp->fullBit(oldp+40242,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT__empty)))));
    bufp->fullBit(oldp+40243,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full)))));
    bufp->fullBit(oldp+40244,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__a_first_done));
    bufp->fullWData(oldp+40245,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__inflight),1040);
    bufp->fullWData(oldp+40278,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__inflight_opcodes),4160);
    bufp->fullWData(oldp+40408,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__inflight_sizes),4160);
    bufp->fullIData(oldp+40538,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__watchdog),32);
    bufp->fullBit(oldp+40539,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileClockGater__DOT__monitor__DOT__d_first_done));
    bufp->fullBit(oldp+40540,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__a_first_done));
    bufp->fullWData(oldp+40541,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__inflight),1040);
    bufp->fullWData(oldp+40574,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__inflight_opcodes),4160);
    bufp->fullWData(oldp+40704,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__inflight_sizes),4160);
    bufp->fullIData(oldp+40834,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__watchdog),32);
    bufp->fullBit(oldp+40835,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__monitor__DOT__d_first_done));
    bufp->fullBit(oldp+40836,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT__tileResetSetter__DOT__r_tile_resets_0__DOT__reg_0));
    bufp->fullBit(oldp+40837,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__x1_a_q__DOT__full)))));
    bufp->fullBit(oldp+40838,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__empty)))));
    bufp->fullCData(oldp+40839,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])),3);
    bufp->fullCData(oldp+40840,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                       >> 3U))),2);
    bufp->fullCData(oldp+40841,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                       >> 5U))),3);
    bufp->fullCData(oldp+40842,((0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                          >> 8U))),7);
    bufp->fullBit(oldp+40843,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 0xfU))));
    bufp->fullBit(oldp+40844,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 0x10U))));
    bufp->fullQData(oldp+40845,((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                  << 0x2fU) | (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                                << 0xfU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                                  >> 0x11U)))),64);
    bufp->fullBit(oldp+40847,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                     >> 0x11U))));
    bufp->fullBit(oldp+40848,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__in_ready));
    bufp->fullBit(oldp+40849,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_valid));
    bufp->fullCData(oldp+40850,((1U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_back__DOT__ram_ext__DOT__Memory
                                 [0U][0U])),3);
    bufp->fullCData(oldp+40851,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_back__DOT__ram_ext__DOT__Memory
                                       [0U][2U] >> 0x1dU))),2);
    bufp->fullSData(oldp+40852,((0x7ffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_back__DOT__ram_ext__DOT__Memory
                                           [0U][2U] 
                                           >> 0x12U))),11);
    bufp->fullQData(oldp+40853,(((1U & ((2U | ((8U 
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
                                      << ((0U == (0x1fU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_oindex) 
                                                     << 6U)))
                                           ? 0x20U : 
                                          ((IData)(0x40U) 
                                           - (0x1fU 
                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_oindex) 
                                                 << 6U))))) 
                                     | (((0U == (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_oindex) 
                                                    << 6U)))
                                          ? 0ULL : 
                                         ((QData)((IData)(
                                                          VTestHarness__ConstPool__CONST_h4e4f723a_0[
                                                          (((IData)(0x1fU) 
                                                            + 
                                                            (0xffU 
                                                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_oindex) 
                                                                << 6U))) 
                                                           >> 5U)])) 
                                          << ((IData)(0x20U) 
                                              - (0x1fU 
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
    bufp->fullBit(oldp+40855,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__maybe_full));
    bufp->fullCData(oldp+40856,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                 [0U][0U])),3);
    bufp->fullCData(oldp+40857,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                       [0U][0U] >> 3U))),3);
    bufp->fullCData(oldp+40858,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                       [0U][0U] >> 6U))),2);
    bufp->fullSData(oldp+40859,((0x7ffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                           [0U][0U] 
                                           >> 8U))),11);
    bufp->fullIData(oldp+40860,((0x3ffffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                                [0U][1U] 
                                                << 0xdU) 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                                  [0U][0U] 
                                                  >> 0x13U)))),26);
    bufp->fullCData(oldp+40861,((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                          [0U][1U] 
                                          >> 0xdU))),8);
    bufp->fullQData(oldp+40862,((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                                  [0U][3U])) 
                                  << 0x2bU) | (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                                                [0U][2U])) 
                                                << 0xbU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                                                  [0U][1U])) 
                                                  >> 0x15U)))),64);
    bufp->fullBit(oldp+40864,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                     [0U][3U] >> 0x15U))));
    bufp->fullBit(oldp+40865,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__maybe_full)))));
    bufp->fullBit(oldp+40866,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__out_7_valid));
    bufp->fullCData(oldp+40867,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__bundleIn_0_d_bits_opcode),3);
    bufp->fullCData(oldp+40868,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                       >> 3U))),2);
    bufp->fullCData(oldp+40869,((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                         >> 5U))),4);
    bufp->fullCData(oldp+40870,((0x3fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                          >> 9U))),6);
    bufp->fullBit(oldp+40871,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 0x10U))));
    bufp->fullBit(oldp+40872,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__bundleIn_0_d_bits_denied));
    bufp->fullQData(oldp+40873,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_in_d_bits_data),64);
    bufp->fullBit(oldp+40875,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__bundleIn_0_d_bits_corrupt));
    bufp->fullCData(oldp+40876,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__state),3);
    bufp->fullBit(oldp+40877,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__x1_2_a_valid));
    bufp->fullBit(oldp+40878,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__full)))));
    bufp->fullBit(oldp+40879,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)))));
    bufp->fullCData(oldp+40880,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])),3);
    bufp->fullCData(oldp+40881,((0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                          >> 9U))),7);
    bufp->fullBit(oldp+40882,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 0x11U))));
    bufp->fullQData(oldp+40883,((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                  << 0x2eU) | (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                                << 0xeU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                                  >> 0x12U)))),64);
    bufp->fullBit(oldp+40885,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                     >> 0x12U))));
    bufp->fullBit(oldp+40886,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__bundleIn_0_d_valid));
    bufp->fullBit(oldp+40887,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__out_1_ready));
    bufp->fullCData(oldp+40888,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_s_0_state),2);
    bufp->fullCData(oldp+40889,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_a_0_bits_opcode),3);
    bufp->fullCData(oldp+40890,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_a_0_bits_param),3);
    bufp->fullCData(oldp+40891,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_a_0_bits_size),4);
    bufp->fullCData(oldp+40892,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_a_0_bits_source),7);
    bufp->fullIData(oldp+40893,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_a_0_bits_address),31);
    bufp->fullCData(oldp+40894,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_a_0_bits_mask),8);
    bufp->fullQData(oldp+40895,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_a_0_bits_data),64);
    bufp->fullBit(oldp+40897,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_a_0_bits_corrupt));
    bufp->fullBit(oldp+40898,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_a_0_fifoId));
    bufp->fullCData(oldp+40899,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_a_0_lut),4);
    bufp->fullQData(oldp+40900,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_d_0_data),64);
    bufp->fullBit(oldp+40902,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_d_0_denied));
    bufp->fullBit(oldp+40903,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_d_0_corrupt));
    bufp->fullBit(oldp+40904,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_s_0_state))));
    bufp->fullBit(oldp+40905,((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_s_0_state))));
    bufp->fullQData(oldp+40906,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__wide_mask),64);
    bufp->fullQData(oldp+40908,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__a_a_ext),64);
    bufp->fullQData(oldp+40910,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__a_d_ext),64);
    bufp->fullQData(oldp+40912,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__adder_out),64);
    bufp->fullBit(oldp+40914,((2U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_a_0_bits_size)))));
    bufp->fullBit(oldp+40915,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__source_c_bits_a_mask_acc));
    bufp->fullBit(oldp+40916,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__source_c_bits_a_mask_acc_1));
    bufp->fullBit(oldp+40917,((1U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_a_0_bits_size)))));
    bufp->fullBit(oldp+40918,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__source_c_bits_a_mask_eq_2));
    bufp->fullBit(oldp+40919,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__source_c_bits_a_mask_acc_2));
    bufp->fullBit(oldp+40920,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__source_c_bits_a_mask_eq_3));
    bufp->fullBit(oldp+40921,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__source_c_bits_a_mask_acc_3));
    bufp->fullBit(oldp+40922,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__source_c_bits_a_mask_eq_4));
    bufp->fullBit(oldp+40923,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__source_c_bits_a_mask_acc_4));
    bufp->fullBit(oldp+40924,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__source_c_bits_a_mask_eq_5));
    bufp->fullBit(oldp+40925,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__source_c_bits_a_mask_acc_5));
    bufp->fullSData(oldp+40926,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__beatsLeft),9);
    bufp->fullBit(oldp+40927,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__beatsLeft))));
    bufp->fullBit(oldp+40928,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__state_0));
    bufp->fullBit(oldp+40929,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__state_1));
    bufp->fullBit(oldp+40930,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__muxStateEarly_0));
    bufp->fullSData(oldp+40931,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__d_first_counter),9);
    bufp->fullBit(oldp+40932,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__d_first_counter))));
    bufp->fullBit(oldp+40933,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__d_cam_sel_match_0));
    bufp->fullBit(oldp+40934,((1U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))));
    bufp->fullBit(oldp+40935,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__d_drop));
    bufp->fullBit(oldp+40936,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__d_replace));
    bufp->fullSData(oldp+40937,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__a_first_counter),9);
    bufp->fullCData(oldp+40938,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__opcode),3);
    bufp->fullCData(oldp+40939,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__param),3);
    bufp->fullCData(oldp+40940,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__size),4);
    bufp->fullCData(oldp+40941,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__source),7);
    bufp->fullIData(oldp+40942,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__address),31);
    bufp->fullSData(oldp+40943,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__d_first_counter),9);
    bufp->fullCData(oldp+40944,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__opcode_1),3);
    bufp->fullCData(oldp+40945,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__param_1),2);
    bufp->fullCData(oldp+40946,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__size_1),4);
    bufp->fullCData(oldp+40947,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__source_1),7);
    bufp->fullBit(oldp+40948,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__sink));
    bufp->fullBit(oldp+40949,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__denied));
    bufp->fullWData(oldp+40950,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__inflight),65);
    bufp->fullWData(oldp+40953,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__inflight_opcodes),260);
    bufp->fullWData(oldp+40962,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__inflight_sizes),520);
    bufp->fullSData(oldp+40979,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__a_first_counter_1),9);
    bufp->fullBit(oldp+40980,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__a_first_counter_1))));
    bufp->fullSData(oldp+40981,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__d_first_counter_1),9);
    bufp->fullBit(oldp+40982,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__d_first_counter_1))));
    bufp->fullBit(oldp+40983,((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__bundleIn_0_d_bits_opcode))));
    bufp->fullIData(oldp+40984,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__watchdog),32);
    bufp->fullSData(oldp+40985,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__d_first_counter_2),9);
    bufp->fullBit(oldp+40986,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__d_first_counter_2))));
    bufp->fullBit(oldp+40987,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__source_ok_1));
    bufp->fullBit(oldp+40988,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty)))));
    bufp->fullBit(oldp+40989,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full)))));
    bufp->fullBit(oldp+40990,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value));
    bufp->fullBit(oldp+40991,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value));
    bufp->fullBit(oldp+40992,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__maybe_full));
    bufp->fullBit(oldp+40993,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ptr_match));
    bufp->fullBit(oldp+40994,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty));
    bufp->fullBit(oldp+40995,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full));
    bufp->fullWData(oldp+40996,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data),83);
    bufp->fullWData(oldp+40999,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[0]),83);
    bufp->fullWData(oldp+41002,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[1]),83);
    bufp->fullSData(oldp+41005,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__a_first_counter),9);
    bufp->fullCData(oldp+41006,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__opcode),3);
    bufp->fullCData(oldp+41007,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__param),3);
    bufp->fullCData(oldp+41008,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__size),4);
    bufp->fullCData(oldp+41009,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__source),7);
    bufp->fullIData(oldp+41010,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__address),31);
    bufp->fullSData(oldp+41011,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__d_first_counter),9);
    bufp->fullCData(oldp+41012,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__opcode_1),3);
    bufp->fullCData(oldp+41013,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__param_1),2);
    bufp->fullCData(oldp+41014,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__size_1),4);
    bufp->fullCData(oldp+41015,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__source_1),7);
    bufp->fullBit(oldp+41016,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__sink));
    bufp->fullBit(oldp+41017,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__denied));
    bufp->fullWData(oldp+41018,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight),65);
    bufp->fullWData(oldp+41021,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_opcodes),260);
    bufp->fullWData(oldp+41030,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes),520);
    bufp->fullSData(oldp+41047,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__a_first_counter_1),9);
    bufp->fullBit(oldp+41048,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__a_first_counter_1))));
    bufp->fullSData(oldp+41049,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__d_first_counter_1),9);
    bufp->fullBit(oldp+41050,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__d_first_counter_1))));
    bufp->fullBit(oldp+41051,((6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))));
    bufp->fullIData(oldp+41052,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__watchdog),32);
    bufp->fullSData(oldp+41053,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__d_first_counter_2),9);
    bufp->fullBit(oldp+41054,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__d_first_counter_2))));
    bufp->fullBit(oldp+41055,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__source_ok_1));
    bufp->fullBit(oldp+41056,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value));
    bufp->fullBit(oldp+41057,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__deq_ptr_value));
    bufp->fullBit(oldp+41058,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__maybe_full));
    bufp->fullBit(oldp+41059,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__ptr_match));
    bufp->fullBit(oldp+41060,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__empty));
    bufp->fullBit(oldp+41061,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__full));
    bufp->fullWData(oldp+41062,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[0]),121);
    bufp->fullWData(oldp+41066,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[1]),121);
    bufp->fullCData(oldp+41070,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__acknum),3);
    bufp->fullCData(oldp+41071,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__dOrig),3);
    bufp->fullBit(oldp+41072,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__dToggle));
    bufp->fullBit(oldp+41073,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__acknum))));
    bufp->fullCData(oldp+41074,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__gennum),3);
    bufp->fullBit(oldp+41075,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__gennum))));
    bufp->fullBit(oldp+41076,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__aToggle_r));
    bufp->fullCData(oldp+41077,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__d_first_counter),3);
    bufp->fullCData(oldp+41078,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__opcode_1),3);
    bufp->fullCData(oldp+41079,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__param_1),2);
    bufp->fullCData(oldp+41080,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__size_1),3);
    bufp->fullCData(oldp+41081,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__source_1),7);
    bufp->fullBit(oldp+41082,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__sink));
    bufp->fullBit(oldp+41083,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__denied));
    bufp->fullWData(oldp+41084,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__inflight),65);
    bufp->fullWData(oldp+41087,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes),260);
    bufp->fullWData(oldp+41096,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes),260);
    bufp->fullCData(oldp+41105,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1),3);
    bufp->fullBit(oldp+41106,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1))));
    bufp->fullIData(oldp+41107,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__watchdog),32);
    bufp->fullBit(oldp+41108,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__repeater__DOT__full));
    bufp->fullCData(oldp+41109,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__repeater__DOT__saved_opcode),3);
    bufp->fullCData(oldp+41110,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__repeater__DOT__saved_param),3);
    bufp->fullCData(oldp+41111,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__repeater__DOT__saved_size),3);
    bufp->fullCData(oldp+41112,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__repeater__DOT__saved_source),7);
    bufp->fullIData(oldp+41113,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__repeater__DOT__saved_address),17);
    bufp->fullCData(oldp+41114,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__repeater__DOT__saved_mask),8);
    bufp->fullBit(oldp+41115,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__repeater__DOT__saved_corrupt));
    bufp->fullCData(oldp+41116,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__acknum),3);
    bufp->fullCData(oldp+41117,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__dOrig),3);
    bufp->fullBit(oldp+41118,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__dToggle));
    bufp->fullBit(oldp+41119,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__acknum))));
    bufp->fullCData(oldp+41120,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__gennum),3);
    bufp->fullBit(oldp+41121,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__gennum))));
    bufp->fullBit(oldp+41122,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__aToggle_r));
    bufp->fullCData(oldp+41123,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__a_first_counter),3);
    bufp->fullCData(oldp+41124,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__opcode),3);
    bufp->fullCData(oldp+41125,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__param),3);
    bufp->fullCData(oldp+41126,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__size),3);
    bufp->fullCData(oldp+41127,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__source),7);
    bufp->fullIData(oldp+41128,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__address),26);
    bufp->fullCData(oldp+41129,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__d_first_counter),3);
    bufp->fullCData(oldp+41130,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__opcode_1),3);
    bufp->fullCData(oldp+41131,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__param_1),2);
    bufp->fullCData(oldp+41132,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__size_1),3);
    bufp->fullCData(oldp+41133,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__source_1),7);
    bufp->fullBit(oldp+41134,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__sink));
    bufp->fullBit(oldp+41135,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__denied));
    bufp->fullWData(oldp+41136,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight),65);
    bufp->fullWData(oldp+41139,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes),260);
    bufp->fullWData(oldp+41148,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes),260);
    bufp->fullCData(oldp+41157,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1),3);
    bufp->fullBit(oldp+41158,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1))));
    bufp->fullCData(oldp+41159,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1),3);
    bufp->fullBit(oldp+41160,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1))));
    bufp->fullIData(oldp+41161,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__watchdog),32);
    bufp->fullCData(oldp+41162,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2),3);
    bufp->fullBit(oldp+41163,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2))));
    bufp->fullBit(oldp+41164,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__repeater__DOT__full));
    bufp->fullCData(oldp+41165,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__repeater__DOT__saved_opcode),3);
    bufp->fullCData(oldp+41166,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__repeater__DOT__saved_param),3);
    bufp->fullCData(oldp+41167,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__repeater__DOT__saved_size),3);
    bufp->fullCData(oldp+41168,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__repeater__DOT__saved_source),7);
    bufp->fullIData(oldp+41169,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__repeater__DOT__saved_address),26);
    bufp->fullCData(oldp+41170,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__repeater__DOT__saved_mask),8);
    bufp->fullBit(oldp+41171,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__repeater__DOT__saved_corrupt));
    bufp->fullCData(oldp+41172,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__acknum),3);
    bufp->fullCData(oldp+41173,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__dOrig),3);
    bufp->fullBit(oldp+41174,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__dToggle));
    bufp->fullBit(oldp+41175,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__acknum))));
    bufp->fullCData(oldp+41176,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__gennum),3);
    bufp->fullBit(oldp+41177,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__gennum))));
    bufp->fullBit(oldp+41178,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__aToggle_r));
    bufp->fullCData(oldp+41179,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__a_first_counter),3);
    bufp->fullCData(oldp+41180,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__opcode),3);
    bufp->fullCData(oldp+41181,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__param),3);
    bufp->fullCData(oldp+41182,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__size),3);
    bufp->fullCData(oldp+41183,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__source),7);
    bufp->fullSData(oldp+41184,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__address),12);
    bufp->fullCData(oldp+41185,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__d_first_counter),3);
    bufp->fullCData(oldp+41186,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__opcode_1),3);
    bufp->fullCData(oldp+41187,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__param_1),2);
    bufp->fullCData(oldp+41188,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__size_1),3);
    bufp->fullCData(oldp+41189,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__source_1),7);
    bufp->fullBit(oldp+41190,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__sink));
    bufp->fullBit(oldp+41191,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__denied));
    bufp->fullWData(oldp+41192,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight),65);
    bufp->fullWData(oldp+41195,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes),260);
    bufp->fullWData(oldp+41204,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes),260);
    bufp->fullCData(oldp+41213,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1),3);
    bufp->fullBit(oldp+41214,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1))));
    bufp->fullCData(oldp+41215,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1),3);
    bufp->fullBit(oldp+41216,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1))));
    bufp->fullIData(oldp+41217,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__watchdog),32);
    bufp->fullCData(oldp+41218,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2),3);
    bufp->fullBit(oldp+41219,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2))));
    bufp->fullCData(oldp+41220,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__repeater__DOT__saved_opcode),3);
    bufp->fullCData(oldp+41221,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__repeater__DOT__saved_size),3);
    bufp->fullCData(oldp+41222,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__repeater__DOT__saved_source),7);
    bufp->fullSData(oldp+41223,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__repeater__DOT__saved_address),12);
    bufp->fullCData(oldp+41224,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__repeater__DOT__saved_mask),8);
    bufp->fullBit(oldp+41225,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_enq_ready_output));
    bufp->fullBit(oldp+41226,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__bundleIn_0_d_valid));
    bufp->fullCData(oldp+41227,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                 [0U][0U])),3);
    bufp->fullCData(oldp+41228,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                       [0U][0U] >> 3U))),2);
    bufp->fullCData(oldp+41229,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__bundleIn_0_d_bits_size),3);
    bufp->fullCData(oldp+41230,((0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                          [0U][0U] 
                                          >> 0xbU))),7);
    bufp->fullBit(oldp+41231,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                     [0U][0U] >> 0x12U))));
    bufp->fullBit(oldp+41232,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                     [0U][0U] >> 0x13U))));
    bufp->fullQData(oldp+41233,((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                                  [0U][2U])) 
                                  << 0x2cU) | (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                                                [0U][1U])) 
                                                << 0xcU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                                                  [0U][0U])) 
                                                  >> 0x14U)))),64);
    bufp->fullBit(oldp+41235,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                     [0U][2U] >> 0x14U))));
    bufp->fullBit(oldp+41236,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__maybe_full)))));
    bufp->fullBit(oldp+41237,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__maybe_full));
    bufp->fullCData(oldp+41238,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                       [0U][0U] >> 5U))),2);
    bufp->fullSData(oldp+41239,((0x7ffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                           [0U][0U] 
                                           >> 7U))),11);
    bufp->fullBit(oldp+41240,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_enq));
    VL_EXTEND_WQ(65,64, __Vtemp_h56c6a7bd__0, ((1U 
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
                                                ? (
                                                   ((QData)((IData)(
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
    bufp->fullWData(oldp+41241,(__Vtemp_hc92888ee__0),85);
    __Vtemp_hb2c720f9__9[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
        [0U][0U];
    __Vtemp_hb2c720f9__9[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
        [0U][1U];
    __Vtemp_hb2c720f9__9[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
        [0U][2U];
    bufp->fullWData(oldp+41244,(__Vtemp_hb2c720f9__9),85);
    bufp->fullWData(oldp+41247,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[0]),85);
    bufp->fullWData(oldp+41250,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__inflight),1040);
    bufp->fullWData(oldp+41283,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__inflight_opcodes),4160);
    bufp->fullWData(oldp+41413,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__inflight_sizes),4160);
    bufp->fullBit(oldp+41543,((6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
                                      [0U][0U]))));
    bufp->fullIData(oldp+41544,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__monitor__DOT__watchdog),32);
    __Vtemp_h14e110c9__8[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
        [0U][0U];
    __Vtemp_h14e110c9__8[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
        [0U][1U];
    __Vtemp_h14e110c9__8[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
        [0U][2U];
    __Vtemp_h14e110c9__8[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
        [0U][3U];
    bufp->fullWData(oldp+41545,(__Vtemp_h14e110c9__8),118);
    bufp->fullWData(oldp+41549,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[0]),118);
    bufp->fullCData(oldp+41553,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__acknum),3);
    bufp->fullCData(oldp+41554,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__dOrig),3);
    bufp->fullBit(oldp+41555,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__dToggle));
    bufp->fullBit(oldp+41556,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__acknum))));
    bufp->fullCData(oldp+41557,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__dFirst_size),3);
    bufp->fullBit(oldp+41558,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__drop));
    bufp->fullCData(oldp+41559,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__gennum),3);
    bufp->fullBit(oldp+41560,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__gennum))));
    bufp->fullBit(oldp+41561,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__aToggle_r));
    bufp->fullCData(oldp+41562,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__a_first_counter),3);
    bufp->fullCData(oldp+41563,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__opcode),3);
    bufp->fullCData(oldp+41564,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__param),3);
    bufp->fullCData(oldp+41565,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__size),3);
    bufp->fullCData(oldp+41566,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__source),7);
    bufp->fullIData(oldp+41567,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__address),26);
    bufp->fullCData(oldp+41568,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__d_first_counter),3);
    bufp->fullCData(oldp+41569,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__opcode_1),3);
    bufp->fullCData(oldp+41570,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__param_1),2);
    bufp->fullCData(oldp+41571,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__size_1),3);
    bufp->fullCData(oldp+41572,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__source_1),7);
    bufp->fullBit(oldp+41573,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__sink));
    bufp->fullBit(oldp+41574,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__denied));
    bufp->fullWData(oldp+41575,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__inflight),65);
    bufp->fullWData(oldp+41578,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes),260);
    bufp->fullWData(oldp+41587,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes),260);
    bufp->fullCData(oldp+41596,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1),3);
    bufp->fullBit(oldp+41597,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1))));
    bufp->fullCData(oldp+41598,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1),3);
    bufp->fullBit(oldp+41599,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1))));
    bufp->fullIData(oldp+41600,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__watchdog),32);
    bufp->fullCData(oldp+41601,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2),3);
    bufp->fullBit(oldp+41602,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2))));
    bufp->fullBit(oldp+41603,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__source_ok_1));
    bufp->fullBit(oldp+41604,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT__full));
    bufp->fullCData(oldp+41605,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT__saved_opcode),3);
    bufp->fullCData(oldp+41606,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT__saved_param),3);
    bufp->fullCData(oldp+41607,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT__saved_size),3);
    bufp->fullCData(oldp+41608,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT__saved_source),7);
    bufp->fullIData(oldp+41609,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT__saved_address),26);
    bufp->fullCData(oldp+41610,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT__saved_mask),8);
    bufp->fullBit(oldp+41611,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT__saved_corrupt));
    bufp->fullBit(oldp+41612,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_enq_ready_output));
    bufp->fullCData(oldp+41613,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__acknum),3);
    bufp->fullCData(oldp+41614,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__dOrig),3);
    bufp->fullBit(oldp+41615,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__dToggle));
    bufp->fullBit(oldp+41616,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__acknum))));
    bufp->fullCData(oldp+41617,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__gennum),3);
    bufp->fullBit(oldp+41618,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__gennum))));
    bufp->fullBit(oldp+41619,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__aToggle_r));
    bufp->fullCData(oldp+41620,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__a_first_counter),3);
    bufp->fullCData(oldp+41621,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__opcode),3);
    bufp->fullCData(oldp+41622,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__param),3);
    bufp->fullCData(oldp+41623,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__size),3);
    bufp->fullCData(oldp+41624,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__source),7);
    bufp->fullIData(oldp+41625,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__address),28);
    bufp->fullCData(oldp+41626,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__d_first_counter),3);
    bufp->fullCData(oldp+41627,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__opcode_1),3);
    bufp->fullCData(oldp+41628,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__param_1),2);
    bufp->fullCData(oldp+41629,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__size_1),3);
    bufp->fullCData(oldp+41630,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__source_1),7);
    bufp->fullBit(oldp+41631,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__sink));
    bufp->fullBit(oldp+41632,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__denied));
    bufp->fullWData(oldp+41633,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__inflight),65);
    bufp->fullWData(oldp+41636,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes),260);
    bufp->fullWData(oldp+41645,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes),260);
    bufp->fullCData(oldp+41654,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1),3);
    bufp->fullBit(oldp+41655,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1))));
    bufp->fullCData(oldp+41656,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1),3);
    bufp->fullBit(oldp+41657,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1))));
    bufp->fullIData(oldp+41658,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__watchdog),32);
    bufp->fullCData(oldp+41659,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2),3);
    bufp->fullBit(oldp+41660,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2))));
    bufp->fullBit(oldp+41661,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT__full));
    bufp->fullCData(oldp+41662,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT__saved_opcode),3);
    bufp->fullCData(oldp+41663,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT__saved_param),3);
    bufp->fullCData(oldp+41664,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT__saved_size),3);
    bufp->fullCData(oldp+41665,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT__saved_source),7);
    bufp->fullIData(oldp+41666,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT__saved_address),28);
    bufp->fullCData(oldp+41667,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT__saved_mask),8);
    bufp->fullBit(oldp+41668,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT__saved_corrupt));
    bufp->fullBit(oldp+41669,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_enq_ready_output));
    bufp->fullBit(oldp+41670,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__bundleIn_0_d_valid));
    bufp->fullCData(oldp+41671,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])),3);
    bufp->fullCData(oldp+41672,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                       >> 3U))),2);
    bufp->fullCData(oldp+41673,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__bundleIn_0_d_bits_size),3);
    bufp->fullCData(oldp+41674,((0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                          >> 0xbU))),7);
    bufp->fullBit(oldp+41675,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 0x12U))));
    bufp->fullBit(oldp+41676,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 0x13U))));
    bufp->fullQData(oldp+41677,((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                  << 0x2cU) | (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                                << 0xcU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                                  >> 0x14U)))),64);
    bufp->fullBit(oldp+41679,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                     >> 0x14U))));
    bufp->fullBit(oldp+41680,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT__full)))));
    bufp->fullBit(oldp+41681,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)))));
    bufp->fullCData(oldp+41682,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                       >> 5U))),2);
    bufp->fullSData(oldp+41683,((0x7ffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                           >> 7U))),11);
    bufp->fullBit(oldp+41684,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value));
    bufp->fullBit(oldp+41685,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value));
    bufp->fullBit(oldp+41686,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__maybe_full));
    bufp->fullBit(oldp+41687,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ptr_match));
    bufp->fullBit(oldp+41688,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty));
    bufp->fullBit(oldp+41689,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full));
    bufp->fullBit(oldp+41690,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_enq));
    bufp->fullWData(oldp+41691,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data),85);
    bufp->fullWData(oldp+41694,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[0]),85);
    bufp->fullWData(oldp+41697,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[1]),85);
    bufp->fullWData(oldp+41700,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__inflight),1040);
    bufp->fullWData(oldp+41733,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__inflight_opcodes),4160);
    bufp->fullWData(oldp+41863,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__inflight_sizes),4160);
    bufp->fullBit(oldp+41993,((6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))));
    bufp->fullIData(oldp+41994,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__monitor__DOT__watchdog),32);
    bufp->fullBit(oldp+41995,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value));
    bufp->fullBit(oldp+41996,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT__deq_ptr_value));
    bufp->fullBit(oldp+41997,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT__maybe_full));
    bufp->fullBit(oldp+41998,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT__ptr_match));
    bufp->fullBit(oldp+41999,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT__empty));
    bufp->fullBit(oldp+42000,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT__full));
    bufp->fullWData(oldp+42001,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[0]),113);
    bufp->fullWData(oldp+42005,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[1]),113);
    bufp->fullCData(oldp+42009,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__acknum),3);
    bufp->fullCData(oldp+42010,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__dOrig),3);
    bufp->fullBit(oldp+42011,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__dToggle));
    bufp->fullBit(oldp+42012,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__acknum))));
    bufp->fullCData(oldp+42013,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__dFirst_size),3);
    bufp->fullBit(oldp+42014,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__drop));
    bufp->fullCData(oldp+42015,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__gennum),3);
    bufp->fullBit(oldp+42016,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__gennum))));
    bufp->fullBit(oldp+42017,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__aToggle_r));
    bufp->fullCData(oldp+42018,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__a_first_counter),3);
    bufp->fullCData(oldp+42019,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__opcode),3);
    bufp->fullCData(oldp+42020,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__param),3);
    bufp->fullCData(oldp+42021,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__size),3);
    bufp->fullCData(oldp+42022,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__source),7);
    bufp->fullIData(oldp+42023,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__address),21);
    bufp->fullCData(oldp+42024,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__d_first_counter),3);
    bufp->fullCData(oldp+42025,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__opcode_1),3);
    bufp->fullCData(oldp+42026,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__param_1),2);
    bufp->fullCData(oldp+42027,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__size_1),3);
    bufp->fullCData(oldp+42028,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__source_1),7);
    bufp->fullBit(oldp+42029,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__sink));
    bufp->fullBit(oldp+42030,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__denied));
    bufp->fullWData(oldp+42031,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight),65);
    bufp->fullWData(oldp+42034,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes),260);
    bufp->fullWData(oldp+42043,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes),260);
    bufp->fullCData(oldp+42052,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1),3);
    bufp->fullBit(oldp+42053,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1))));
    bufp->fullCData(oldp+42054,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1),3);
    bufp->fullBit(oldp+42055,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1))));
    bufp->fullIData(oldp+42056,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__watchdog),32);
    bufp->fullCData(oldp+42057,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2),3);
    bufp->fullBit(oldp+42058,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2))));
    bufp->fullBit(oldp+42059,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__source_ok_1));
    bufp->fullBit(oldp+42060,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT__full));
    bufp->fullCData(oldp+42061,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT__saved_opcode),3);
    bufp->fullCData(oldp+42062,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT__saved_param),3);
    bufp->fullCData(oldp+42063,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT__saved_size),3);
    bufp->fullCData(oldp+42064,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT__saved_source),7);
    bufp->fullIData(oldp+42065,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT__saved_address),21);
    bufp->fullCData(oldp+42066,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT__saved_mask),8);
    bufp->fullBit(oldp+42067,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT__saved_corrupt));
    bufp->fullBit(oldp+42068,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_enq_ready_output));
    bufp->fullBit(oldp+42069,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__bundleIn_0_d_valid));
    bufp->fullCData(oldp+42070,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])),3);
    bufp->fullCData(oldp+42071,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                       >> 3U))),2);
    bufp->fullCData(oldp+42072,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__bundleIn_0_d_bits_size),3);
    bufp->fullCData(oldp+42073,((0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                          >> 0xbU))),7);
    bufp->fullBit(oldp+42074,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 0x12U))));
    bufp->fullBit(oldp+42075,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 0x13U))));
    bufp->fullQData(oldp+42076,((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                  << 0x2cU) | (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                                << 0xcU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                                  >> 0x14U)))),64);
    bufp->fullBit(oldp+42078,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                     >> 0x14U))));
    bufp->fullBit(oldp+42079,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT__full)))));
    bufp->fullBit(oldp+42080,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)))));
    bufp->fullCData(oldp+42081,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                       >> 5U))),2);
    bufp->fullSData(oldp+42082,((0x7ffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                           >> 7U))),11);
    bufp->fullBit(oldp+42083,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value));
    bufp->fullBit(oldp+42084,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value));
    bufp->fullBit(oldp+42085,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__maybe_full));
    bufp->fullBit(oldp+42086,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ptr_match));
    bufp->fullBit(oldp+42087,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty));
    bufp->fullBit(oldp+42088,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full));
    bufp->fullBit(oldp+42089,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_enq));
    bufp->fullWData(oldp+42090,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data),85);
    bufp->fullWData(oldp+42093,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[0]),85);
    bufp->fullWData(oldp+42096,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[1]),85);
    bufp->fullWData(oldp+42099,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__inflight),1040);
    bufp->fullWData(oldp+42132,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__inflight_opcodes),4160);
    bufp->fullWData(oldp+42262,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__inflight_sizes),4160);
    bufp->fullBit(oldp+42392,((6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))));
    bufp->fullIData(oldp+42393,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__monitor__DOT__watchdog),32);
    bufp->fullBit(oldp+42394,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value));
    bufp->fullBit(oldp+42395,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT__deq_ptr_value));
    bufp->fullBit(oldp+42396,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT__maybe_full));
    bufp->fullBit(oldp+42397,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT__ptr_match));
    bufp->fullBit(oldp+42398,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT__empty));
    bufp->fullBit(oldp+42399,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT__full));
    bufp->fullWData(oldp+42400,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[0]),113);
    bufp->fullWData(oldp+42404,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[1]),113);
    bufp->fullCData(oldp+42408,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__acknum),3);
    bufp->fullCData(oldp+42409,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__dOrig),3);
    bufp->fullBit(oldp+42410,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__dToggle));
    bufp->fullBit(oldp+42411,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__acknum))));
    bufp->fullCData(oldp+42412,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__dFirst_size),3);
    bufp->fullBit(oldp+42413,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__drop));
    bufp->fullCData(oldp+42414,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__gennum),3);
    bufp->fullBit(oldp+42415,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__gennum))));
    bufp->fullBit(oldp+42416,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__aToggle_r));
    bufp->fullCData(oldp+42417,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__a_first_counter),3);
    bufp->fullCData(oldp+42418,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__opcode),3);
    bufp->fullCData(oldp+42419,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__param),3);
    bufp->fullCData(oldp+42420,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__size),3);
    bufp->fullCData(oldp+42421,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__source),7);
    bufp->fullIData(oldp+42422,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__address),21);
    bufp->fullCData(oldp+42423,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__d_first_counter),3);
    bufp->fullCData(oldp+42424,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__opcode_1),3);
    bufp->fullCData(oldp+42425,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__param_1),2);
    bufp->fullCData(oldp+42426,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__size_1),3);
    bufp->fullCData(oldp+42427,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__source_1),7);
    bufp->fullBit(oldp+42428,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__sink));
    bufp->fullBit(oldp+42429,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__denied));
    bufp->fullWData(oldp+42430,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__inflight),65);
    bufp->fullWData(oldp+42433,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes),260);
    bufp->fullWData(oldp+42442,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes),260);
    bufp->fullCData(oldp+42451,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1),3);
    bufp->fullBit(oldp+42452,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1))));
    bufp->fullCData(oldp+42453,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1),3);
    bufp->fullBit(oldp+42454,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1))));
    bufp->fullIData(oldp+42455,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__watchdog),32);
    bufp->fullCData(oldp+42456,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2),3);
    bufp->fullBit(oldp+42457,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2))));
    bufp->fullBit(oldp+42458,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__source_ok_1));
    bufp->fullBit(oldp+42459,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT__full));
    bufp->fullCData(oldp+42460,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT__saved_opcode),3);
    bufp->fullCData(oldp+42461,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT__saved_param),3);
    bufp->fullCData(oldp+42462,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT__saved_size),3);
    bufp->fullCData(oldp+42463,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT__saved_source),7);
    bufp->fullIData(oldp+42464,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT__saved_address),21);
    bufp->fullCData(oldp+42465,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT__saved_mask),8);
    bufp->fullBit(oldp+42466,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT__saved_corrupt));
    bufp->fullSData(oldp+42467,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__a_first_counter),9);
    bufp->fullCData(oldp+42468,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__opcode),3);
    bufp->fullCData(oldp+42469,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__param),3);
    bufp->fullCData(oldp+42470,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__size),4);
    bufp->fullCData(oldp+42471,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__source),7);
    bufp->fullIData(oldp+42472,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__address),31);
    bufp->fullSData(oldp+42473,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__d_first_counter),9);
    bufp->fullCData(oldp+42474,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__opcode_1),3);
    bufp->fullCData(oldp+42475,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__param_1),2);
    bufp->fullCData(oldp+42476,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__size_1),4);
    bufp->fullCData(oldp+42477,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__source_1),7);
    bufp->fullBit(oldp+42478,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__sink));
    bufp->fullBit(oldp+42479,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__denied));
    bufp->fullWData(oldp+42480,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight),65);
    bufp->fullWData(oldp+42483,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_opcodes),260);
    bufp->fullWData(oldp+42492,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__inflight_sizes),520);
    bufp->fullSData(oldp+42509,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__a_first_counter_1),9);
    bufp->fullBit(oldp+42510,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__a_first_counter_1))));
    bufp->fullSData(oldp+42511,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__d_first_counter_1),9);
    bufp->fullBit(oldp+42512,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__d_first_counter_1))));
    bufp->fullIData(oldp+42513,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__watchdog),32);
    bufp->fullSData(oldp+42514,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__d_first_counter_2),9);
    bufp->fullBit(oldp+42515,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__d_first_counter_2))));
    bufp->fullIData(oldp+42516,(((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__state))
                                  ? 0x4000U : 0x2000000U)),31);
    bufp->fullQData(oldp+42517,(((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__state))
                                  ? 0x80000000ULL : 1ULL)),64);
    bufp->fullBit(oldp+42519,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__out_10_valid));
    bufp->fullBit(oldp+42520,((0x40U == (0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 9U)))));
    bufp->fullSData(oldp+42521,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__beatsLeft),9);
    bufp->fullBit(oldp+42522,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__beatsLeft))));
    bufp->fullCData(oldp+42523,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__readys_mask),2);
    bufp->fullBit(oldp+42524,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__state_0));
    bufp->fullBit(oldp+42525,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__state_1));
    bufp->fullSData(oldp+42526,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__a_first_counter),9);
    bufp->fullCData(oldp+42527,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__opcode),3);
    bufp->fullCData(oldp+42528,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__param),3);
    bufp->fullCData(oldp+42529,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__size),4);
    bufp->fullCData(oldp+42530,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__source),6);
    bufp->fullIData(oldp+42531,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__address),31);
    bufp->fullSData(oldp+42532,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__d_first_counter),9);
    bufp->fullCData(oldp+42533,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__opcode_1),3);
    bufp->fullCData(oldp+42534,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__param_1),2);
    bufp->fullCData(oldp+42535,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__size_1),4);
    bufp->fullCData(oldp+42536,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__source_1),6);
    bufp->fullBit(oldp+42537,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__sink));
    bufp->fullBit(oldp+42538,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__denied));
    bufp->fullQData(oldp+42539,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__inflight),33);
    bufp->fullWData(oldp+42541,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__inflight_opcodes),132);
    bufp->fullWData(oldp+42546,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__inflight_sizes),264);
    bufp->fullSData(oldp+42555,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__a_first_counter_1),9);
    bufp->fullBit(oldp+42556,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__a_first_counter_1))));
    bufp->fullSData(oldp+42557,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__d_first_counter_1),9);
    bufp->fullBit(oldp+42558,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__d_first_counter_1))));
    bufp->fullIData(oldp+42559,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__watchdog),32);
    bufp->fullSData(oldp+42560,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__d_first_counter_2),9);
    bufp->fullBit(oldp+42561,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__d_first_counter_2))));
    bufp->fullBit(oldp+42562,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__source_ok_1));
    bufp->fullSData(oldp+42563,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__d_first_counter),9);
    bufp->fullCData(oldp+42564,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__opcode_1),3);
    bufp->fullCData(oldp+42565,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__param_1),2);
    bufp->fullCData(oldp+42566,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__size_1),4);
    bufp->fullBit(oldp+42567,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__source_1));
    bufp->fullBit(oldp+42568,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__sink));
    bufp->fullBit(oldp+42569,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__denied));
    bufp->fullBit(oldp+42570,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__inflight));
    bufp->fullCData(oldp+42571,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__inflight_opcodes),4);
    bufp->fullCData(oldp+42572,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__inflight_sizes),8);
    bufp->fullSData(oldp+42573,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__d_first_counter_1),9);
    bufp->fullBit(oldp+42574,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__d_first_counter_1))));
    bufp->fullIData(oldp+42575,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__watchdog),32);
    bufp->fullSData(oldp+42576,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__d_first_counter_2),9);
    bufp->fullBit(oldp+42577,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__d_first_counter_2))));
    bufp->fullBit(oldp+42578,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__d_clr));
    bufp->fullBit(oldp+42579,((1U & ((~ (((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__state))
                                           ? 0x4000U
                                           : 0x2000000U) 
                                         >> 2U)) & 
                                     (~ (((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__state))
                                           ? 0x4000U
                                           : 0x2000000U) 
                                         >> 1U))))));
    bufp->fullBit(oldp+42580,((1U & ((~ (((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__state))
                                           ? 0x4000U
                                           : 0x2000000U) 
                                         >> 2U)) & 
                                     (((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__state))
                                        ? 0x4000U : 0x2000000U) 
                                      >> 1U)))));
    bufp->fullBit(oldp+42581,((1U & ((((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__state))
                                        ? 0x4000U : 0x2000000U) 
                                      >> 2U) & (~ (
                                                   ((1U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__state))
                                                     ? 0x4000U
                                                     : 0x2000000U) 
                                                   >> 1U))))));
    bufp->fullBit(oldp+42582,((1U & ((((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__state))
                                        ? 0x4000U : 0x2000000U) 
                                      >> 2U) & (((1U 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__state))
                                                  ? 0x4000U
                                                  : 0x2000000U) 
                                                >> 1U)))));
    bufp->fullBit(oldp+42583,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__full)))));
    bufp->fullBit(oldp+42584,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)))));
    bufp->fullCData(oldp+42585,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])),3);
    bufp->fullCData(oldp+42586,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                       >> 3U))),2);
    bufp->fullCData(oldp+42587,((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                         >> 5U))),4);
    bufp->fullCData(oldp+42588,((0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                          >> 9U))),7);
    bufp->fullBit(oldp+42589,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 0x10U))));
    bufp->fullBit(oldp+42590,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 0x11U))));
    bufp->fullQData(oldp+42591,((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                  << 0x2eU) | (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                                << 0xeU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                                  >> 0x12U)))),64);
    bufp->fullBit(oldp+42593,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                     >> 0x12U))));
    bufp->fullSData(oldp+42594,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__beatsLeft),9);
    bufp->fullBit(oldp+42595,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__beatsLeft))));
    bufp->fullSData(oldp+42596,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__readys_mask),9);
    bufp->fullBit(oldp+42597,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__state_0));
    bufp->fullBit(oldp+42598,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__state_1));
    bufp->fullBit(oldp+42599,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__state_2));
    bufp->fullBit(oldp+42600,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__state_3));
    bufp->fullBit(oldp+42601,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__state_4));
    bufp->fullBit(oldp+42602,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__state_5));
    bufp->fullBit(oldp+42603,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__state_6));
    bufp->fullBit(oldp+42604,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__state_7));
    bufp->fullBit(oldp+42605,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__state_8));
    bufp->fullBit(oldp+42606,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__latch));
    bufp->fullSData(oldp+42607,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__a_first_counter),9);
    bufp->fullCData(oldp+42608,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__opcode),3);
    bufp->fullCData(oldp+42609,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__param),3);
    bufp->fullCData(oldp+42610,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__size),4);
    bufp->fullCData(oldp+42611,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__source),7);
    bufp->fullIData(oldp+42612,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__address),31);
    bufp->fullSData(oldp+42613,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__d_first_counter),9);
    bufp->fullCData(oldp+42614,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__opcode_1),3);
    bufp->fullCData(oldp+42615,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__param_1),2);
    bufp->fullCData(oldp+42616,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__size_1),4);
    bufp->fullCData(oldp+42617,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__source_1),7);
    bufp->fullBit(oldp+42618,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__sink));
    bufp->fullBit(oldp+42619,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__denied));
    bufp->fullWData(oldp+42620,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight),65);
    bufp->fullWData(oldp+42623,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight_opcodes),260);
    bufp->fullWData(oldp+42632,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__inflight_sizes),520);
    bufp->fullSData(oldp+42649,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__a_first_counter_1),9);
    bufp->fullBit(oldp+42650,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__a_first_counter_1))));
    bufp->fullSData(oldp+42651,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__d_first_counter_1),9);
    bufp->fullBit(oldp+42652,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__d_first_counter_1))));
    bufp->fullIData(oldp+42653,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__watchdog),32);
    bufp->fullSData(oldp+42654,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__d_first_counter_2),9);
    bufp->fullBit(oldp+42655,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__d_first_counter_2))));
    bufp->fullBit(oldp+42656,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__maybe_full)))));
    bufp->fullBit(oldp+42657,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__da_valid));
    bufp->fullCData(oldp+42658,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__da_bits_opcode),3);
    bufp->fullCData(oldp+42659,((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__ram_ext__DOT__Memory
                                         [0U][0U] >> 6U))),4);
    bufp->fullCData(oldp+42660,((0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__ram_ext__DOT__Memory
                                          [0U][0U] 
                                          >> 0xaU))),7);
    bufp->fullBit(oldp+42661,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__da_bits_opcode))));
    bufp->fullBit(oldp+42662,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__empty)))));
    bufp->fullCData(oldp+42663,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])),3);
    bufp->fullCData(oldp+42664,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                       >> 3U))),3);
    bufp->fullCData(oldp+42665,((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                         >> 6U))),4);
    bufp->fullCData(oldp+42666,((0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                          >> 0xaU))),7);
    bufp->fullSData(oldp+42667,((0x3fffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                            >> 0x11U))),14);
    bufp->fullCData(oldp+42668,((0xffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                           << 1U) | 
                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                           >> 0x1fU)))),8);
    bufp->fullQData(oldp+42669,((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                                  << 0x39U) | (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                                                << 0x19U) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                                  >> 7U)))),64);
    bufp->fullBit(oldp+42671,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                                     >> 7U))));
    bufp->fullBit(oldp+42672,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full)))));
    bufp->fullBit(oldp+42673,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value));
    bufp->fullBit(oldp+42674,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value));
    bufp->fullBit(oldp+42675,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__maybe_full));
    bufp->fullBit(oldp+42676,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ptr_match));
    bufp->fullBit(oldp+42677,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty));
    bufp->fullBit(oldp+42678,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full));
    bufp->fullBit(oldp+42679,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_enq));
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
    bufp->fullWData(oldp+42680,(__Vtemp_h95b49b13__0),83);
    bufp->fullWData(oldp+42683,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data),83);
    bufp->fullWData(oldp+42686,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[0]),83);
    bufp->fullWData(oldp+42689,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[1]),83);
    bufp->fullSData(oldp+42692,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__a_first_counter),9);
    bufp->fullCData(oldp+42693,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__opcode),3);
    bufp->fullCData(oldp+42694,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__param),3);
    bufp->fullCData(oldp+42695,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__size),4);
    bufp->fullCData(oldp+42696,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__source),7);
    bufp->fullSData(oldp+42697,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__address),14);
    bufp->fullSData(oldp+42698,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__d_first_counter),9);
    bufp->fullCData(oldp+42699,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__opcode_1),3);
    bufp->fullCData(oldp+42700,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__param_1),2);
    bufp->fullCData(oldp+42701,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__size_1),4);
    bufp->fullCData(oldp+42702,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__source_1),7);
    bufp->fullBit(oldp+42703,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__sink));
    bufp->fullBit(oldp+42704,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__denied));
    bufp->fullWData(oldp+42705,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight),65);
    bufp->fullWData(oldp+42708,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_opcodes),260);
    bufp->fullWData(oldp+42717,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__inflight_sizes),520);
    bufp->fullSData(oldp+42734,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__a_first_counter_1),9);
    bufp->fullBit(oldp+42735,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__a_first_counter_1))));
    bufp->fullSData(oldp+42736,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__d_first_counter_1),9);
    bufp->fullBit(oldp+42737,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__d_first_counter_1))));
    bufp->fullBit(oldp+42738,((6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))));
    bufp->fullIData(oldp+42739,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__watchdog),32);
    bufp->fullSData(oldp+42740,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__d_first_counter_2),9);
    bufp->fullBit(oldp+42741,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__d_first_counter_2))));
    bufp->fullBit(oldp+42742,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__source_ok_1));
    bufp->fullBit(oldp+42743,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value));
    bufp->fullBit(oldp+42744,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__deq_ptr_value));
    bufp->fullBit(oldp+42745,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__maybe_full));
    bufp->fullBit(oldp+42746,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__ptr_match));
    bufp->fullBit(oldp+42747,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__empty));
    bufp->fullBit(oldp+42748,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__full));
    bufp->fullBit(oldp+42749,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__do_deq));
    bufp->fullWData(oldp+42750,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data),104);
    bufp->fullWData(oldp+42754,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[0]),104);
    bufp->fullWData(oldp+42758,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[1]),104);
    bufp->fullSData(oldp+42762,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a_last_counter),9);
    bufp->fullBit(oldp+42763,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a_last));
    bufp->fullSData(oldp+42764,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__counter),9);
    bufp->fullBit(oldp+42765,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT___a_io_deq_ready_T_3));
    bufp->fullBit(oldp+42766,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__maybe_full));
    bufp->fullCData(oldp+42767,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__ram_ext__DOT__Memory
                                 [0U][0U])),3);
    bufp->fullBit(oldp+42768,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__do_enq));
    __Vtemp_h353c8118__5[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__ram_ext__DOT__Memory
        [0U][0U];
    __Vtemp_h353c8118__5[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__ram_ext__DOT__Memory
        [0U][1U];
    __Vtemp_h353c8118__5[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__ram_ext__DOT__Memory
        [0U][2U];
    __Vtemp_h353c8118__5[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__ram_ext__DOT__Memory
        [0U][3U];
    bufp->fullWData(oldp+42769,(__Vtemp_h353c8118__5),104);
    bufp->fullWData(oldp+42773,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__ram_ext__DOT__Memory[0]),104);
    bufp->fullSData(oldp+42777,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__a_first_counter),9);
    bufp->fullCData(oldp+42778,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__opcode),3);
    bufp->fullCData(oldp+42779,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__param),3);
    bufp->fullCData(oldp+42780,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__size),4);
    bufp->fullCData(oldp+42781,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__source),7);
    bufp->fullSData(oldp+42782,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__address),14);
    bufp->fullSData(oldp+42783,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__d_first_counter),9);
    bufp->fullCData(oldp+42784,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__opcode_1),3);
    bufp->fullCData(oldp+42785,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__param_1),2);
    bufp->fullCData(oldp+42786,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__size_1),4);
    bufp->fullCData(oldp+42787,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__source_1),7);
    bufp->fullBit(oldp+42788,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__sink));
    bufp->fullBit(oldp+42789,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__denied));
    bufp->fullWData(oldp+42790,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__inflight),65);
    bufp->fullWData(oldp+42793,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__inflight_opcodes),260);
    bufp->fullWData(oldp+42802,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__inflight_sizes),520);
    bufp->fullSData(oldp+42819,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__a_first_counter_1),9);
    bufp->fullBit(oldp+42820,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__a_first_counter_1))));
    bufp->fullSData(oldp+42821,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__d_first_counter_1),9);
    bufp->fullBit(oldp+42822,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__d_first_counter_1))));
    bufp->fullBit(oldp+42823,((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__da_bits_opcode))));
    bufp->fullIData(oldp+42824,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__watchdog),32);
    bufp->fullSData(oldp+42825,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__d_first_counter_2),9);
    bufp->fullBit(oldp+42826,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__d_first_counter_2))));
    bufp->fullBit(oldp+42827,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__source_ok));
    bufp->fullBit(oldp+42828,((2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                            >> 6U)))));
    bufp->fullBit(oldp+42829,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_acc));
    bufp->fullBit(oldp+42830,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_acc_1));
    bufp->fullBit(oldp+42831,((1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                            >> 6U)))));
    bufp->fullBit(oldp+42832,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_eq_2));
    bufp->fullBit(oldp+42833,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_acc_2));
    bufp->fullBit(oldp+42834,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_eq_3));
    bufp->fullBit(oldp+42835,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_acc_3));
    bufp->fullBit(oldp+42836,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_eq_4));
    bufp->fullBit(oldp+42837,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_acc_4));
    bufp->fullBit(oldp+42838,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_eq_5));
    bufp->fullBit(oldp+42839,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_acc_5));
    bufp->fullCData(oldp+42840,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_acc_5) 
                                   << 7U) | (0x3fff80U 
                                             & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_eq_5) 
                                                 << 7U) 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)))) 
                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_acc_5) 
                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_eq_5) 
                                         & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                               >> 0x11U)))) 
                                     << 6U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__mask_acc_4) 
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
    bufp->fullBit(oldp+42841,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__source_ok_1));
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
    bufp->fullWData(oldp+42842,(__Vtemp_he55d0783__0),65);
    bufp->fullBit(oldp+42845,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__same_cycle_resp));
    bufp->fullBit(oldp+42846,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__empty)))));
    bufp->fullCData(oldp+42847,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])),3);
    bufp->fullCData(oldp+42848,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                       >> 3U))),3);
    bufp->fullCData(oldp+42849,((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                         >> 6U))),4);
    bufp->fullBit(oldp+42850,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                     >> 0xaU))));
    bufp->fullIData(oldp+42851,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                  << 0x15U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                               >> 0xbU))),32);
    bufp->fullCData(oldp+42852,((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                          >> 0xbU))),8);
    bufp->fullQData(oldp+42853,((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                                  << 0x2dU) | (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                                                << 0xdU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                                  >> 0x13U)))),64);
    bufp->fullBit(oldp+42855,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                                     >> 0x13U))));
    bufp->fullBit(oldp+42856,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full)))));
    bufp->fullBit(oldp+42857,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_24_valid));
    bufp->fullCData(oldp+42858,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_24_bits_opcode),3);
    bufp->fullCData(oldp+42859,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_24_bits_param),2);
    bufp->fullCData(oldp+42860,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_24_bits_size),4);
    bufp->fullCData(oldp+42861,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_24_bits_sink),3);
    bufp->fullBit(oldp+42862,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__out_24_bits_denied));
    bufp->fullQData(oldp+42863,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_4_0)
                                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_in_d_bits_data
                                   : 0ULL) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_4_1)
                                               ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_l2_wrapper_auto_coherent_jbar_in_d_bits_data
                                               : 0ULL))),64);
    bufp->fullBit(oldp+42865,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_4_0) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__bundleIn_0_d_bits_corrupt)) 
                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_4_1) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_corrupt)))));
    bufp->fullBit(oldp+42866,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT__full)))));
    bufp->fullBit(oldp+42867,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT__empty)))));
    bufp->fullCData(oldp+42868,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])),3);
    bufp->fullCData(oldp+42869,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                       >> 3U))),2);
    bufp->fullCData(oldp+42870,((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                         >> 5U))),4);
    bufp->fullCData(oldp+42871,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                       >> 0xaU))),3);
    bufp->fullBit(oldp+42872,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 0xdU))));
    bufp->fullQData(oldp+42873,((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                  << 0x32U) | (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                                << 0x12U) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                                  >> 0xeU)))),64);
    bufp->fullBit(oldp+42875,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                     >> 0xeU))));
    bufp->fullBit(oldp+42876,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT__empty)))));
    bufp->fullCData(oldp+42877,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])),3);
    bufp->fullCData(oldp+42878,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                       >> 3U))),3);
    bufp->fullCData(oldp+42879,((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                         >> 6U))),4);
    bufp->fullBit(oldp+42880,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                     >> 0xaU))));
    bufp->fullIData(oldp+42881,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                  << 0x15U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                               >> 0xbU))),32);
    bufp->fullCData(oldp+42882,((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                                          >> 0xbU))),8);
    bufp->fullQData(oldp+42883,((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U])) 
                                  << 0x2dU) | (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[2U])) 
                                                << 0xdU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U])) 
                                                  >> 0x13U)))),64);
    bufp->fullBit(oldp+42885,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[3U] 
                                     >> 0x13U))));
    bufp->fullBit(oldp+42886,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT__full)))));
    bufp->fullBit(oldp+42887,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 9U))));
    bufp->fullBit(oldp+42888,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value));
    bufp->fullBit(oldp+42889,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value));
    bufp->fullBit(oldp+42890,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT__maybe_full));
    bufp->fullBit(oldp+42891,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT__ptr_match));
    bufp->fullBit(oldp+42892,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT__empty));
    bufp->fullBit(oldp+42893,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT__full));
    bufp->fullBit(oldp+42894,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT__do_enq));
    bufp->fullBit(oldp+42895,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT__do_deq));
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
    bufp->fullWData(oldp+42896,(__Vtemp_h50fe2c8b__0),79);
    bufp->fullWData(oldp+42899,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data),79);
    bufp->fullWData(oldp+42902,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[0]),79);
    bufp->fullWData(oldp+42905,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[1]),79);
    bufp->fullSData(oldp+42908,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__a_first_counter),9);
    bufp->fullCData(oldp+42909,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__opcode),3);
    bufp->fullCData(oldp+42910,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__param),3);
    bufp->fullCData(oldp+42911,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__size),4);
    bufp->fullBit(oldp+42912,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__source));
    bufp->fullIData(oldp+42913,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__address),32);
    bufp->fullSData(oldp+42914,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__d_first_counter),9);
    bufp->fullCData(oldp+42915,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__opcode_1),3);
    bufp->fullCData(oldp+42916,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__param_1),2);
    bufp->fullCData(oldp+42917,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__size_1),4);
    bufp->fullBit(oldp+42918,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__source_1));
    bufp->fullCData(oldp+42919,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__sink),3);
    bufp->fullBit(oldp+42920,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__denied));
    bufp->fullBit(oldp+42921,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__inflight));
    bufp->fullCData(oldp+42922,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__inflight_opcodes),4);
    bufp->fullCData(oldp+42923,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__inflight_sizes),8);
    bufp->fullSData(oldp+42924,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__a_first_counter_1),9);
    bufp->fullBit(oldp+42925,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__a_first_counter_1))));
    bufp->fullSData(oldp+42926,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__d_first_counter_1),9);
    bufp->fullBit(oldp+42927,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__d_first_counter_1))));
    bufp->fullBit(oldp+42928,((6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))));
    bufp->fullIData(oldp+42929,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__watchdog),32);
    bufp->fullSData(oldp+42930,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__d_first_counter_2),9);
    bufp->fullBit(oldp+42931,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__d_first_counter_2))));
    bufp->fullBit(oldp+42932,((2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                            >> 6U)))));
    bufp->fullBit(oldp+42933,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_acc));
    bufp->fullBit(oldp+42934,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_acc_1));
    bufp->fullBit(oldp+42935,((1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                            >> 6U)))));
    bufp->fullBit(oldp+42936,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_eq_2));
    bufp->fullBit(oldp+42937,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_acc_2));
    bufp->fullBit(oldp+42938,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_eq_3));
    bufp->fullBit(oldp+42939,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_acc_3));
    bufp->fullBit(oldp+42940,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_eq_4));
    bufp->fullBit(oldp+42941,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_acc_4));
    bufp->fullBit(oldp+42942,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_eq_5));
    bufp->fullBit(oldp+42943,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_acc_5));
    bufp->fullCData(oldp+42944,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_acc_5) 
                                   << 7U) | (0xfffff80U 
                                             & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_eq_5) 
                                                 << 7U) 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 4U)))) 
                                 | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_acc_5) 
                                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_eq_5) 
                                         & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                               >> 0xbU)))) 
                                     << 6U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__mask_acc_4) 
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
    bufp->fullBit(oldp+42945,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT___same_cycle_resp_T_1) 
                               & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                     >> 0xaU)))));
    bufp->fullBit(oldp+42946,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__same_cycle_resp));
    bufp->fullBit(oldp+42947,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT__enq_ptr_value));
    bufp->fullBit(oldp+42948,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT__deq_ptr_value));
    bufp->fullBit(oldp+42949,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT__maybe_full));
    bufp->fullBit(oldp+42950,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT__ptr_match));
    bufp->fullBit(oldp+42951,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT__empty));
    bufp->fullBit(oldp+42952,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT__full));
    bufp->fullBit(oldp+42953,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT__do_enq));
    bufp->fullWData(oldp+42954,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data),116);
    bufp->fullWData(oldp+42958,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT___ram_ext_R0_data),116);
    bufp->fullWData(oldp+42962,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[0]),116);
    bufp->fullWData(oldp+42966,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[1]),116);
    bufp->fullBit(oldp+42970,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tsi_domain_auto_serdesser_client_out_a_valid));
    bufp->fullCData(oldp+42971,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                       >> 0x15U))),3);
    bufp->fullCData(oldp+42972,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                       >> 0x12U))),3);
    bufp->fullCData(oldp+42973,((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                         >> 0xeU))),4);
    bufp->fullBit(oldp+42974,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                     >> 0xaU))));
    bufp->fullIData(oldp+42975,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tsi_domain_auto_serdesser_client_out_a_bits_address),32);
    bufp->fullCData(oldp+42976,((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_0 
                                          >> 1U))),8);
    bufp->fullQData(oldp+42977,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT___inDes_io_out_bits_data),64);
    bufp->fullBit(oldp+42979,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_0 
                                     >> 9U))));
    bufp->fullBit(oldp+42980,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT___outArb_io_in_1_ready));
    bufp->fullBit(oldp+42981,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__full)))));
    bufp->fullBit(oldp+42982,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty)))));
    bufp->fullCData(oldp+42983,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])),3);
    bufp->fullCData(oldp+42984,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                       >> 3U))),2);
    bufp->fullCData(oldp+42985,((0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                         >> 5U))),4);
    bufp->fullBit(oldp+42986,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 9U))));
    bufp->fullCData(oldp+42987,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                       >> 0xaU))),3);
    bufp->fullBit(oldp+42988,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                     >> 0xdU))));
    bufp->fullQData(oldp+42989,((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                  << 0x32U) | (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                                << 0x12U) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                                  >> 0xeU)))),64);
    bufp->fullBit(oldp+42991,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                     >> 0xeU))));
    bufp->fullBit(oldp+42992,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value));
    bufp->fullBit(oldp+42993,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value));
    bufp->fullBit(oldp+42994,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__maybe_full));
    bufp->fullBit(oldp+42995,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ptr_match));
    bufp->fullBit(oldp+42996,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__empty));
    bufp->fullBit(oldp+42997,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__full));
    bufp->fullBit(oldp+42998,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_enq));
    bufp->fullBit(oldp+42999,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__do_deq));
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
    bufp->fullWData(oldp+43000,(__Vtemp_hfbbb1fa2__0),79);
    bufp->fullWData(oldp+43003,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data),79);
    bufp->fullWData(oldp+43006,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[0]),79);
    bufp->fullWData(oldp+43009,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[1]),79);
    bufp->fullSData(oldp+43012,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__a_first_counter),9);
    bufp->fullCData(oldp+43013,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__opcode),3);
    bufp->fullCData(oldp+43014,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__param),3);
    bufp->fullCData(oldp+43015,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__size),4);
    bufp->fullBit(oldp+43016,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__source));
    bufp->fullIData(oldp+43017,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__address),32);
    bufp->fullSData(oldp+43018,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__d_first_counter),9);
    bufp->fullCData(oldp+43019,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__opcode_1),3);
    bufp->fullCData(oldp+43020,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__param_1),2);
    bufp->fullCData(oldp+43021,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__size_1),4);
    bufp->fullBit(oldp+43022,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__source_1));
    bufp->fullCData(oldp+43023,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__sink),3);
    bufp->fullBit(oldp+43024,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__denied));
    bufp->fullBit(oldp+43025,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__inflight));
    bufp->fullCData(oldp+43026,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__inflight_opcodes),4);
    bufp->fullCData(oldp+43027,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__inflight_sizes),8);
    bufp->fullSData(oldp+43028,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__a_first_counter_1),9);
    bufp->fullBit(oldp+43029,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__a_first_counter_1))));
    bufp->fullSData(oldp+43030,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__d_first_counter_1),9);
    bufp->fullBit(oldp+43031,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__d_first_counter_1))));
    bufp->fullBit(oldp+43032,((6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U]))));
    bufp->fullIData(oldp+43033,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__watchdog),32);
    bufp->fullSData(oldp+43034,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__d_first_counter_2),9);
    bufp->fullBit(oldp+43035,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__d_first_counter_2))));
    bufp->fullBit(oldp+43036,((2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                            >> 0xeU)))));
    bufp->fullBit(oldp+43037,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc));
    bufp->fullBit(oldp+43038,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_1));
    bufp->fullBit(oldp+43039,((1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                            >> 0xeU)))));
    bufp->fullBit(oldp+43040,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_2));
    bufp->fullBit(oldp+43041,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_2));
    bufp->fullBit(oldp+43042,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_3));
    bufp->fullBit(oldp+43043,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_3));
    bufp->fullBit(oldp+43044,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_4));
    bufp->fullBit(oldp+43045,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_4));
    bufp->fullBit(oldp+43046,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_eq_5));
    bufp->fullBit(oldp+43047,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_5));
    bufp->fullCData(oldp+43048,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__mask_acc_5) 
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
    bufp->fullBit(oldp+43049,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT___same_cycle_resp_T_1) 
                               & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__inDes__DOT__data_3 
                                     >> 0xaU)))));
    bufp->fullBit(oldp+43050,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__same_cycle_resp));
    bufp->fullBit(oldp+43051,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value));
    bufp->fullBit(oldp+43052,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__deq_ptr_value));
    bufp->fullBit(oldp+43053,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__maybe_full));
    bufp->fullBit(oldp+43054,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ptr_match));
    bufp->fullBit(oldp+43055,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__empty));
    bufp->fullBit(oldp+43056,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__full));
    bufp->fullBit(oldp+43057,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__do_enq));
    bufp->fullBit(oldp+43058,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__do_deq));
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
    bufp->fullWData(oldp+43059,(__Vtemp_hcffc7c87__0),116);
    bufp->fullWData(oldp+43063,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[0]),116);
    bufp->fullWData(oldp+43067,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[1]),116);
    bufp->fullBit(oldp+43071,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT___portsAOI_in_0_a_ready_WIRE));
    bufp->fullBit(oldp+43072,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__out_9_valid));
    bufp->fullCData(oldp+43073,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__out_9_bits_opcode),3);
    bufp->fullCData(oldp+43074,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__out_9_bits_param),2);
    bufp->fullCData(oldp+43075,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__out_9_bits_size),3);
    bufp->fullCData(oldp+43076,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__out_9_bits_source),4);
    bufp->fullBit(oldp+43077,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__out_9_bits_sink));
    bufp->fullBit(oldp+43078,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__out_9_bits_denied));
    bufp->fullQData(oldp+43079,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__muxStateEarly_0)
                                   ? vlSelf->TestHarness__DOT__simdram__DOT_____05Fr_data_reg
                                   : 0ULL) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__muxStateEarly_1)
                                               ? (((QData)((IData)(
                                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                                   << 0x32U) 
                                                  | (((QData)((IData)(
                                                                      vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                                      << 0x12U) 
                                                     | ((QData)((IData)(
                                                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                                        >> 0xeU)))
                                               : 0ULL))),64);
    bufp->fullBit(oldp+43081,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__muxStateEarly_0) 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__r_wins) 
                                   & ((0U != (IData)(vlSelf->TestHarness__DOT__simdram__DOT_____05Fr_resp_reg)) 
                                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__r_d_denied)))) 
                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__muxStateEarly_1) 
                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                     >> 0xeU)))));
    bufp->fullBit(oldp+43082,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_2_valid));
    bufp->fullCData(oldp+43083,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_opcode),3);
    bufp->fullCData(oldp+43084,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_param),3);
    bufp->fullCData(oldp+43085,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size),3);
    bufp->fullCData(oldp+43086,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source),4);
    bufp->fullIData(oldp+43087,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_address),32);
    bufp->fullCData(oldp+43088,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_mask),8);
    bufp->fullQData(oldp+43089,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_data),64);
    bufp->fullBit(oldp+43091,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_0) 
                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[3U] 
                                   >> 0xcU)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1) 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[3U] 
                                                   >> 0x14U)))));
    bufp->fullBit(oldp+43092,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_d_ready));
    bufp->fullBit(oldp+43093,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__maybe_full)))));
    bufp->fullBit(oldp+43094,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceB__DOT__b_valid));
    bufp->fullCData(oldp+43095,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_param),2);
    bufp->fullCData(oldp+43096,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source),6);
    bufp->fullIData(oldp+43097,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address),32);
    bufp->fullBit(oldp+43098,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__c__DOT__full)))));
    bufp->fullBit(oldp+43099,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output));
    bufp->fullCData(oldp+43100,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode),3);
    bufp->fullCData(oldp+43101,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_param),2);
    bufp->fullCData(oldp+43102,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_size),3);
    bufp->fullCData(oldp+43103,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source),6);
    bufp->fullCData(oldp+43104,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_sink),3);
    bufp->fullBit(oldp+43105,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_denied));
    bufp->fullQData(oldp+43106,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_l2_wrapper_auto_coherent_jbar_in_d_bits_data),64);
    bufp->fullBit(oldp+43108,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_corrupt));
    bufp->fullBit(oldp+43109,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s3_valid_d));
    bufp->fullCData(oldp+43110,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__d_bits_opcode),3);
    bufp->fullCData(oldp+43111,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_d_bits_param),2);
    bufp->fullCData(oldp+43112,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s3_req_size),3);
    bufp->fullCData(oldp+43113,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s3_req_source),6);
    bufp->fullCData(oldp+43114,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s3_req_sink),3);
    bufp->fullBit(oldp+43115,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s3_req_bad));
    bufp->fullQData(oldp+43116,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___l2_auto_in_d_bits_data),64);
    bufp->fullBit(oldp+43118,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_d_bits_corrupt));
    bufp->fullBit(oldp+43119,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT__maybe_full)))));
    bufp->fullBit(oldp+43120,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT__maybe_full));
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
    bufp->fullWData(oldp+43121,(__Vtemp_h07fba5f3__0),83);
    __Vtemp_haf83fa31__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
        [0U][0U];
    __Vtemp_haf83fa31__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
        [0U][1U];
    __Vtemp_haf83fa31__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory
        [0U][2U];
    bufp->fullWData(oldp+43124,(__Vtemp_haf83fa31__0),83);
    bufp->fullWData(oldp+43127,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory[0]),83);
    bufp->fullCData(oldp+43130,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__a_first_counter),3);
    bufp->fullCData(oldp+43131,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__opcode),3);
    bufp->fullCData(oldp+43132,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__param),3);
    bufp->fullCData(oldp+43133,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__size),3);
    bufp->fullCData(oldp+43134,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__source),6);
    bufp->fullIData(oldp+43135,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__address),32);
    bufp->fullCData(oldp+43136,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__d_first_counter),3);
    bufp->fullCData(oldp+43137,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__opcode_1),3);
    bufp->fullCData(oldp+43138,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__param_1),2);
    bufp->fullCData(oldp+43139,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__size_1),3);
    bufp->fullCData(oldp+43140,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__source_1),6);
    bufp->fullCData(oldp+43141,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__sink),3);
    bufp->fullBit(oldp+43142,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__denied));
    bufp->fullCData(oldp+43143,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__c_first_counter),3);
    bufp->fullCData(oldp+43144,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__opcode_3),3);
    bufp->fullCData(oldp+43145,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__param_3),3);
    bufp->fullCData(oldp+43146,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__size_3),3);
    bufp->fullCData(oldp+43147,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__source_3),6);
    bufp->fullIData(oldp+43148,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__address_2),32);
    bufp->fullQData(oldp+43149,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__inflight),33);
    bufp->fullWData(oldp+43151,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__inflight_opcodes),132);
    bufp->fullWData(oldp+43156,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__inflight_sizes),132);
    bufp->fullCData(oldp+43161,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__a_first_counter_1),3);
    bufp->fullBit(oldp+43162,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__a_first_counter_1))));
    bufp->fullCData(oldp+43163,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__d_first_counter_1),3);
    bufp->fullBit(oldp+43164,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__d_first_counter_1))));
    bufp->fullBit(oldp+43165,((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))));
    bufp->fullIData(oldp+43166,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__watchdog),32);
    bufp->fullQData(oldp+43167,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__inflight_1),33);
    bufp->fullWData(oldp+43169,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__inflight_sizes_1),132);
    bufp->fullCData(oldp+43174,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__c_first_counter_1),3);
    bufp->fullBit(oldp+43175,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__c_first_counter_1))));
    bufp->fullCData(oldp+43176,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__d_first_counter_2),3);
    bufp->fullBit(oldp+43177,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__d_first_counter_2))));
    bufp->fullIData(oldp+43178,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__watchdog_1),32);
    bufp->fullCData(oldp+43179,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__inflight_2),7);
    bufp->fullCData(oldp+43180,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__d_first_counter_3),3);
    bufp->fullBit(oldp+43181,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__d_first_counter_3))));
    bufp->fullBit(oldp+43182,((((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source)) 
                                        | (IData)((
                                                   (0U 
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
    bufp->fullBit(oldp+43183,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__maybe_full));
    __Vtemp_h6b530f7d__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
        [0U][0U];
    __Vtemp_h6b530f7d__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
        [0U][1U];
    __Vtemp_h6b530f7d__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
        [0U][2U];
    __Vtemp_h6b530f7d__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
        [0U][3U];
    bufp->fullWData(oldp+43184,(__Vtemp_h6b530f7d__0),120);
    bufp->fullWData(oldp+43188,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory[0]),120);
    bufp->fullCData(oldp+43192,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__a_first_counter),3);
    bufp->fullCData(oldp+43193,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__opcode),3);
    bufp->fullCData(oldp+43194,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__param),3);
    bufp->fullCData(oldp+43195,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__size),3);
    bufp->fullCData(oldp+43196,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__source),4);
    bufp->fullIData(oldp+43197,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__address),32);
    bufp->fullCData(oldp+43198,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__d_first_counter),3);
    bufp->fullCData(oldp+43199,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__opcode_1),3);
    bufp->fullCData(oldp+43200,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__param_1),2);
    bufp->fullCData(oldp+43201,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__size_1),3);
    bufp->fullCData(oldp+43202,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__source_1),4);
    bufp->fullBit(oldp+43203,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__sink));
    bufp->fullBit(oldp+43204,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__denied));
    bufp->fullSData(oldp+43205,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__inflight),10);
    bufp->fullQData(oldp+43206,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__inflight_opcodes),40);
    bufp->fullQData(oldp+43208,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__inflight_sizes),40);
    bufp->fullCData(oldp+43210,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__a_first_counter_1),3);
    bufp->fullBit(oldp+43211,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__a_first_counter_1))));
    bufp->fullCData(oldp+43212,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__d_first_counter_1),3);
    bufp->fullBit(oldp+43213,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__d_first_counter_1))));
    bufp->fullBit(oldp+43214,((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__out_9_bits_opcode))));
    bufp->fullIData(oldp+43215,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__watchdog),32);
    bufp->fullCData(oldp+43216,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__d_first_counter_2),3);
    bufp->fullBit(oldp+43217,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__d_first_counter_2))));
    bufp->fullBit(oldp+43218,((2U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size)))));
    bufp->fullBit(oldp+43219,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_acc));
    bufp->fullBit(oldp+43220,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_acc_1));
    bufp->fullBit(oldp+43221,((1U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_size)))));
    bufp->fullBit(oldp+43222,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_eq_2));
    bufp->fullBit(oldp+43223,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_acc_2));
    bufp->fullBit(oldp+43224,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_eq_3));
    bufp->fullBit(oldp+43225,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_acc_3));
    bufp->fullBit(oldp+43226,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_eq_4));
    bufp->fullBit(oldp+43227,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_acc_4));
    bufp->fullBit(oldp+43228,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_eq_5));
    bufp->fullBit(oldp+43229,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_acc_5));
    bufp->fullCData(oldp+43230,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__mask_acc_5) 
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
    bufp->fullSData(oldp+43231,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT___same_cycle_resp_T_1)
                                  ? ((0xfU >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source))
                                      ? (0x3ffU & ((IData)(1U) 
                                                   << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___cork_auto_out_a_bits_source)))
                                      : 0U) : 0U)),10);
    bufp->fullBit(oldp+43232,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__same_cycle_resp));
    bufp->fullBit(oldp+43233,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT__empty)))));
    bufp->fullCData(oldp+43234,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[0U])),3);
    bufp->fullCData(oldp+43235,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[0U] 
                                       >> 3U))),3);
    bufp->fullCData(oldp+43236,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[0U] 
                                       >> 6U))),3);
    bufp->fullCData(oldp+43237,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[0U] 
                                       >> 9U))),3);
    bufp->fullIData(oldp+43238,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___l2_auto_out_a_bits_address),32);
    bufp->fullCData(oldp+43239,((0xffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[1U] 
                                          >> 0xcU))),8);
    bufp->fullQData(oldp+43240,((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[3U])) 
                                  << 0x2cU) | (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[2U])) 
                                                << 0xcU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[1U])) 
                                                  >> 0x14U)))),64);
    bufp->fullBit(oldp+43242,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[3U] 
                                     >> 0x14U))));
    bufp->fullBit(oldp+43243,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT__empty)))));
    bufp->fullCData(oldp+43244,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U])),3);
    bufp->fullCData(oldp+43245,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U] 
                                       >> 3U))),3);
    bufp->fullCData(oldp+43246,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U] 
                                       >> 6U))),3);
    bufp->fullCData(oldp+43247,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U] 
                                       >> 9U))),3);
    bufp->fullIData(oldp+43248,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___l2_auto_out_c_bits_address),32);
    bufp->fullQData(oldp+43249,((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[3U])) 
                                  << 0x34U) | (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[2U])) 
                                                << 0x14U) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[1U])) 
                                                  >> 0xcU)))),64);
    bufp->fullBit(oldp+43251,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[3U] 
                                     >> 0xcU))));
    bufp->fullBit(oldp+43252,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkD__DOT__d__DOT__full)))));
    bufp->fullBit(oldp+43253,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceE__DOT__io_e_q__DOT__empty)))));
    bufp->fullCData(oldp+43254,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___l2_auto_out_e_bits_sink),3);
    bufp->fullBit(oldp+43255,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__bundleIn_0_a_ready));
    bufp->fullBit(oldp+43256,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__bundleIn_0_c_ready));
    bufp->fullBit(oldp+43257,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__bundleIn_0_d_valid));
    bufp->fullCData(oldp+43258,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_6_bits_opcode),3);
    bufp->fullCData(oldp+43259,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_6_bits_param),2);
    bufp->fullCData(oldp+43260,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_6_bits_size),3);
    bufp->fullCData(oldp+43261,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_6_bits_source),3);
    bufp->fullCData(oldp+43262,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__bundleIn_0_d_bits_sink),3);
    bufp->fullBit(oldp+43263,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_6_bits_denied));
    bufp->fullQData(oldp+43264,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1_0)
                                    ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__muxStateEarly_0)
                                         ? vlSelf->TestHarness__DOT__simdram__DOT_____05Fr_data_reg
                                         : 0ULL) | 
                                       ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__muxStateEarly_1)
                                         ? (((QData)((IData)(
                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U])) 
                                             << 0x32U) 
                                            | (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[1U])) 
                                                << 0x12U) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])) 
                                                  >> 0xeU)))
                                         : 0ULL)) : 0ULL) 
                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1_1)
                                      ? (((QData)((IData)(
                                                          vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[2U])) 
                                          << 0x31U) 
                                         | (((QData)((IData)(
                                                             vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[1U])) 
                                             << 0x11U) 
                                            | ((QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[0U])) 
                                               >> 0xfU)))
                                      : 0ULL)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1_2)
                                                   ? 
                                                  (((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[2U])) 
                                                    << 0x31U) 
                                                   | (((QData)((IData)(
                                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[1U])) 
                                                       << 0x11U) 
                                                      | ((QData)((IData)(
                                                                         vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[0U])) 
                                                         >> 0xfU)))
                                                   : 0ULL))),64);
    bufp->fullBit(oldp+43266,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1_0) 
                                 & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__muxStateEarly_0) 
                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__r_wins) 
                                        & ((0U != (IData)(vlSelf->TestHarness__DOT__simdram__DOT_____05Fr_resp_reg)) 
                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__r_d_denied)))) 
                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__muxStateEarly_1) 
                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[2U] 
                                          >> 0xeU)))) 
                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1_1) 
                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[2U] 
                                      >> 0xfU))) | 
                               ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1_2) 
                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[2U] 
                                   >> 0xfU)))));
    bufp->fullBit(oldp+43267,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_6_valid));
    bufp->fullBit(oldp+43268,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT___portsAOI_in_0_a_ready_WIRE) 
                               & ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__beatsLeft))
                                   ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__winnerQual_0))
                                   : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__state_1)))));
    bufp->fullBit(oldp+43269,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT___portsAOI_in_0_a_ready_WIRE) 
                               & ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__beatsLeft)) 
                                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__state_0)))));
    bufp->fullBit(oldp+43270,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__toD));
    bufp->fullBit(oldp+43271,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_1_earlyValid));
    bufp->fullCData(oldp+43272,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_1_bits_opcode),3);
    bufp->fullBit(oldp+43273,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__winnerQual_0));
    bufp->fullBit(oldp+43274,((2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U] 
                                            >> 6U)))));
    bufp->fullBit(oldp+43275,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__c_a_bits_a_mask_acc));
    bufp->fullBit(oldp+43276,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__c_a_bits_a_mask_acc_1));
    bufp->fullBit(oldp+43277,((1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U] 
                                            >> 6U)))));
    bufp->fullBit(oldp+43278,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__c_a_bits_a_mask_eq_2));
    bufp->fullBit(oldp+43279,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__c_a_bits_a_mask_acc_2));
    bufp->fullBit(oldp+43280,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__c_a_bits_a_mask_eq_3));
    bufp->fullBit(oldp+43281,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__c_a_bits_a_mask_acc_3));
    bufp->fullBit(oldp+43282,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__c_a_bits_a_mask_eq_4));
    bufp->fullBit(oldp+43283,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__c_a_bits_a_mask_acc_4));
    bufp->fullBit(oldp+43284,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__c_a_bits_a_mask_eq_5));
    bufp->fullBit(oldp+43285,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__c_a_bits_a_mask_acc_5));
    bufp->fullCData(oldp+43286,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__d_first_counter),3);
    bufp->fullBit(oldp+43287,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__d_grant));
    bufp->fullBit(oldp+43288,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_6_ready));
    bufp->fullCData(oldp+43289,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__bundleIn_0_d_bits_sink_r),3);
    bufp->fullBit(oldp+43290,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__wSourceVec_0));
    bufp->fullBit(oldp+43291,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__wSourceVec_1));
    bufp->fullBit(oldp+43292,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__wSourceVec_2));
    bufp->fullBit(oldp+43293,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__wSourceVec_3));
    bufp->fullBit(oldp+43294,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__wSourceVec_4));
    bufp->fullBit(oldp+43295,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__dWHeld_r));
    bufp->fullCData(oldp+43296,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_3_bits_opcode),3);
    bufp->fullCData(oldp+43297,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__beatsLeft),3);
    bufp->fullBit(oldp+43298,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__beatsLeft))));
    bufp->fullBit(oldp+43299,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__winnerQual_0)) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_1_earlyValid))));
    bufp->fullBit(oldp+43300,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__state_0));
    bufp->fullBit(oldp+43301,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__state_1));
    bufp->fullBit(oldp+43302,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_0));
    bufp->fullBit(oldp+43303,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1));
    bufp->fullCData(oldp+43304,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__beatsLeft_1),3);
    bufp->fullBit(oldp+43305,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__beatsLeft_1))));
    bufp->fullBit(oldp+43306,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__out_9_valid)) 
                                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__empty))))));
    bufp->fullBit(oldp+43307,((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT___GEN_1)) 
                                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__empty))))));
    bufp->fullBit(oldp+43308,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__state_1_0));
    bufp->fullBit(oldp+43309,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__state_1_1));
    bufp->fullBit(oldp+43310,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__state_1_2));
    bufp->fullBit(oldp+43311,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1_0));
    bufp->fullBit(oldp+43312,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1_1));
    bufp->fullBit(oldp+43313,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__muxStateEarly_1_2));
    bufp->fullBit(oldp+43314,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__winnerQual_1));
    bufp->fullBit(oldp+43315,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__aWOk));
    bufp->fullCData(oldp+43316,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__a_first_counter),3);
    bufp->fullCData(oldp+43317,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__opcode),3);
    bufp->fullCData(oldp+43318,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__param),3);
    bufp->fullCData(oldp+43319,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__size),3);
    bufp->fullCData(oldp+43320,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__source),3);
    bufp->fullIData(oldp+43321,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__address),32);
    bufp->fullCData(oldp+43322,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__d_first_counter),3);
    bufp->fullCData(oldp+43323,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__opcode_1),3);
    bufp->fullCData(oldp+43324,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__param_1),2);
    bufp->fullCData(oldp+43325,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__size_1),3);
    bufp->fullCData(oldp+43326,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__source_1),3);
    bufp->fullCData(oldp+43327,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__sink),3);
    bufp->fullBit(oldp+43328,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__denied));
    bufp->fullCData(oldp+43329,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__c_first_counter),3);
    bufp->fullCData(oldp+43330,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__opcode_3),3);
    bufp->fullCData(oldp+43331,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__param_3),3);
    bufp->fullCData(oldp+43332,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__size_3),3);
    bufp->fullCData(oldp+43333,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__source_3),3);
    bufp->fullIData(oldp+43334,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__address_2),32);
    bufp->fullCData(oldp+43335,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__inflight),5);
    bufp->fullIData(oldp+43336,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__inflight_opcodes),20);
    bufp->fullIData(oldp+43337,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__inflight_sizes),20);
    bufp->fullCData(oldp+43338,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__a_first_counter_1),3);
    bufp->fullBit(oldp+43339,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__a_first_counter_1))));
    bufp->fullCData(oldp+43340,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__d_first_counter_1),3);
    bufp->fullBit(oldp+43341,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__d_first_counter_1))));
    bufp->fullBit(oldp+43342,((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_6_bits_opcode))));
    bufp->fullIData(oldp+43343,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__watchdog),32);
    bufp->fullCData(oldp+43344,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__inflight_1),5);
    bufp->fullIData(oldp+43345,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__inflight_sizes_1),20);
    bufp->fullCData(oldp+43346,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__c_first_counter_1),3);
    bufp->fullBit(oldp+43347,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__c_first_counter_1))));
    bufp->fullCData(oldp+43348,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__d_first_counter_2),3);
    bufp->fullBit(oldp+43349,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__d_first_counter_2))));
    bufp->fullIData(oldp+43350,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__watchdog_1),32);
    bufp->fullCData(oldp+43351,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__inflight_2),8);
    bufp->fullCData(oldp+43352,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__d_first_counter_3),3);
    bufp->fullBit(oldp+43353,((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__d_first_counter_3))));
    bufp->fullCData(oldp+43354,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__d_set),8);
    bufp->fullBit(oldp+43355,((2U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[0U] 
                                            >> 6U)))));
    bufp->fullBit(oldp+43356,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_acc));
    bufp->fullBit(oldp+43357,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_acc_1));
    bufp->fullBit(oldp+43358,((1U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[0U] 
                                            >> 6U)))));
    bufp->fullBit(oldp+43359,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_eq_2));
    bufp->fullBit(oldp+43360,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_acc_2));
    bufp->fullBit(oldp+43361,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_eq_3));
    bufp->fullBit(oldp+43362,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_acc_3));
    bufp->fullBit(oldp+43363,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_eq_4));
    bufp->fullBit(oldp+43364,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_acc_4));
    bufp->fullBit(oldp+43365,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_eq_5));
    bufp->fullBit(oldp+43366,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_acc_5));
    bufp->fullCData(oldp+43367,(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__mask_acc_5) 
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
    bufp->fullBit(oldp+43368,((((8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___l2_auto_out_c_bits_address 
                                        >> 0x1cU)) 
                                | (0x10000U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___l2_auto_out_c_bits_address 
                                                >> 0xcU))) 
                               | (2U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___l2_auto_out_c_bits_address 
                                         >> 0x10U)))));
    bufp->fullCData(oldp+43369,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT___same_cycle_resp_T_1)
                                  ? ((7U >= (7U & (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 9U)))
                                      ? (0x1fU & ((IData)(1U) 
                                                  << 
                                                  (7U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 9U))))
                                      : 0U) : 0U)),5);
    bufp->fullBit(oldp+43370,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__same_cycle_resp));
    bufp->fullCData(oldp+43371,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT___same_cycle_resp_T_3) 
                                  & (6U == (6U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U])))
                                  ? ((7U >= (7U & (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U] 
                                                   >> 9U)))
                                      ? (0x1fU & ((IData)(1U) 
                                                  << 
                                                  (7U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U] 
                                                      >> 9U))))
                                      : 0U) : 0U)),5);
    bufp->fullBit(oldp+43372,((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT___same_cycle_resp_T_3) 
                                & (6U == (6U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U]))) 
                               & ((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U] 
                                         >> 9U)) == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_6_bits_source)))));
    bufp->fullBit(oldp+43373,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT____Vcellinp__pool__io_alloc_ready));
    bufp->fullBit(oldp+43374,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__pool__DOT__valid));
    bufp->fullCData(oldp+43375,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__pool__DOT__select),3);
    bufp->fullCData(oldp+43376,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__pool__DOT__bitmap),8);
    bufp->fullCData(oldp+43377,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__pool__DOT__taken),8);
    bufp->fullBit(oldp+43378,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__pool__DOT__REG));
    bufp->fullCData(oldp+43379,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__pool__DOT__bitmap1),8);
    bufp->fullBit(oldp+43380,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT__empty)) 
                               & (6U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U])))));
    bufp->fullBit(oldp+43381,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_6_ready) 
                               & ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__beatsLeft_1))
                                   ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__out_9_valid))
                                   : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__state_1_1)))));
    bufp->fullBit(oldp+43382,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__full)))));
    bufp->fullBit(oldp+43383,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__empty)))));
    bufp->fullCData(oldp+43384,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[0U])),3);
    bufp->fullCData(oldp+43385,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[0U] 
                                       >> 3U))),2);
    bufp->fullCData(oldp+43386,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[0U] 
                                       >> 5U))),3);
    bufp->fullCData(oldp+43387,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[0U] 
                                       >> 8U))),3);
    bufp->fullCData(oldp+43388,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[0U] 
                                       >> 0xbU))),3);
    bufp->fullBit(oldp+43389,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[0U] 
                                     >> 0xeU))));
    bufp->fullQData(oldp+43390,((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[2U])) 
                                  << 0x31U) | (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[1U])) 
                                                << 0x11U) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[0U])) 
                                                  >> 0xfU)))),64);
    bufp->fullBit(oldp+43392,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data[2U] 
                                     >> 0xfU))));
    bufp->fullBit(oldp+43393,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__enq_ptr_value));
    bufp->fullBit(oldp+43394,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__deq_ptr_value));
    bufp->fullBit(oldp+43395,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__maybe_full));
    bufp->fullBit(oldp+43396,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__ptr_match));
    bufp->fullBit(oldp+43397,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__empty));
    bufp->fullBit(oldp+43398,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__full));
    bufp->fullBit(oldp+43399,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__do_enq));
    bufp->fullBit(oldp+43400,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__do_deq));
    VL_EXTEND_WI(80,11, __Vtemp_h6d4f267c__0, (6U | 
                                               ((0x700U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U] 
                                                    >> 1U)) 
                                                | (0xe0U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U] 
                                                      >> 1U)))));
    bufp->fullWData(oldp+43401,(__Vtemp_h6d4f267c__0),80);
    bufp->fullWData(oldp+43404,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT___ram_ext_R0_data),80);
    bufp->fullWData(oldp+43407,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__ram_ext__DOT__Memory[0]),80);
    bufp->fullWData(oldp+43410,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__ram_ext__DOT__Memory[1]),80);
    bufp->fullBit(oldp+43413,(((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT__empty)) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__toD))));
    bufp->fullBit(oldp+43414,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__out_6_ready) 
                               & ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__beatsLeft_1))
                                   ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT___GEN_1))
                                   : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__state_1_2)))));
    bufp->fullBit(oldp+43415,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__full)))));
    bufp->fullBit(oldp+43416,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__empty)))));
    bufp->fullCData(oldp+43417,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[0U])),3);
    bufp->fullCData(oldp+43418,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[0U] 
                                       >> 3U))),2);
    bufp->fullCData(oldp+43419,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[0U] 
                                       >> 5U))),3);
    bufp->fullCData(oldp+43420,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[0U] 
                                       >> 8U))),3);
    bufp->fullCData(oldp+43421,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[0U] 
                                       >> 0xbU))),3);
    bufp->fullBit(oldp+43422,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[0U] 
                                     >> 0xeU))));
    bufp->fullQData(oldp+43423,((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[2U])) 
                                  << 0x31U) | (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[1U])) 
                                                << 0x11U) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[0U])) 
                                                  >> 0xfU)))),64);
    bufp->fullBit(oldp+43425,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data[2U] 
                                     >> 0xfU))));
    bufp->fullBit(oldp+43426,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__enq_ptr_value));
    bufp->fullBit(oldp+43427,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__deq_ptr_value));
    bufp->fullBit(oldp+43428,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__maybe_full));
    bufp->fullBit(oldp+43429,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__ptr_match));
    bufp->fullBit(oldp+43430,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__empty));
    bufp->fullBit(oldp+43431,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__full));
    bufp->fullBit(oldp+43432,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__do_enq));
    bufp->fullBit(oldp+43433,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__do_deq));
    VL_EXTEND_WI(80,11, __Vtemp_h5462a164__0, (4U | 
                                               ((0x700U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 1U)) 
                                                | (0xe0U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[0U] 
                                                      >> 1U)))));
    bufp->fullWData(oldp+43434,(__Vtemp_h5462a164__0),80);
    bufp->fullWData(oldp+43437,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT___ram_ext_R0_data),80);
    bufp->fullWData(oldp+43440,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__ram_ext__DOT__Memory[0]),80);
    bufp->fullWData(oldp+43443,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__ram_ext__DOT__Memory[1]),80);
    bufp->fullBit(oldp+43446,((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___GEN_4))));
    bufp->fullBit(oldp+43447,((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___GEN_4))));
    bufp->fullBit(oldp+43448,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__flushInValid));
    bufp->fullQData(oldp+43449,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__flushInAddress),64);
    bufp->fullBit(oldp+43451,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__flushOutValid));
    bufp->fullBit(oldp+43452,((4U == (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory
                                      [0U][0U]))));
    bufp->fullQData(oldp+43453,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_frontMask),64);
    bufp->fullQData(oldp+43455,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_backMask),64);
    bufp->fullCData(oldp+43457,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_oindex),2);
    bufp->fullBit(oldp+43458,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_iready));
    bufp->fullBit(oldp+43459,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_oready));
    bufp->fullBit(oldp+43460,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__flushSelect));
    bufp->fullBit(oldp+43461,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_f_wivalid_4));
    bufp->fullBit(oldp+43462,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_f_wivalid_5));
    bufp->fullBit(oldp+43463,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__flushInValid) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__flushSelect))));
    bufp->fullIData(oldp+43464,((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__flushInAddress)),32);
    bufp->fullBit(oldp+43465,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__flushOutValid)))));
    bufp->fullIData(oldp+43466,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_address),32);
    bufp->fullIData(oldp+43467,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[1U] 
                                  << 0x14U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT___ram_ext_R0_data[0U] 
                                               >> 0xcU))),32);
    bufp->fullIData(oldp+43468,(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[1U] 
                                  << 0x14U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT___ram_ext_R0_data[0U] 
                                               >> 0xcU))),32);
    bufp->fullBit(oldp+43469,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkX__DOT__x__DOT__maybe_full)))));
    bufp->fullBit(oldp+43470,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceX__DOT__io_x_q__DOT__maybe_full));
    bufp->fullCData(oldp+43471,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_request),7);
    bufp->fullCData(oldp+43472,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__robin_filter),7);
    bufp->fullCData(oldp+43473,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH),7);
    bufp->fullCData(oldp+43474,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__schedule_d_bits_sink),3);
    bufp->fullSData(oldp+43475,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__scheduleTag),13);
    bufp->fullSData(oldp+43476,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__nestedwb_set),10);
    bufp->fullSData(oldp+43477,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__nestedwb_tag),13);
    bufp->fullBit(oldp+43478,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__nestedwb_b_clr_dirty));
    bufp->fullBit(oldp+43479,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__nestedwb_b_toN));
    bufp->fullBit(oldp+43480,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__nestedwb_b_toB));
    bufp->fullBit(oldp+43481,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__nestedwb_c_set_dirty));
    bufp->fullCData(oldp+43482,((3U & (- (IData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___sinkC_io_req_valid))))),2);
    bufp->fullCData(oldp+43483,((0x1fU | (0x60U & (
                                                   (- (IData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___sinkC_io_req_valid))) 
                                                   << 5U)))),7);
    bufp->fullIData(oldp+43484,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__selected_requests),21);
    bufp->fullBit(oldp+43485,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__may_pop));
    bufp->fullBit(oldp+43486,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__lb_tag_mismatch));
    bufp->fullBit(oldp+43487,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_uses_directory_assuming_no_bypass));
    bufp->fullCData(oldp+43488,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_insertOH),8);
    bufp->fullCData(oldp+43489,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directoryFanout),8);
    bufp->fullBit(oldp+43490,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directoryFanout))));
    bufp->fullBit(oldp+43491,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___directory_io_result_bits_dirty));
    bufp->fullCData(oldp+43492,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___directory_io_result_bits_state),2);
    bufp->fullCData(oldp+43493,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___directory_io_result_bits_clients),5);
    bufp->fullSData(oldp+43494,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___directory_io_result_bits_tag),13);
    bufp->fullBit(oldp+43495,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___directory_io_result_bits_hit));
    bufp->fullCData(oldp+43496,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___directory_io_result_bits_way),3);
    bufp->fullBit(oldp+43497,((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH))));
    bufp->fullBit(oldp+43498,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_0__io_sinkc_valid));
    bufp->fullBit(oldp+43499,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__last));
    bufp->fullSData(oldp+43500,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__tag),13);
    bufp->fullCData(oldp+43501,((0x3fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__c__DOT___ram_ext_R0_data[0U] 
                                          >> 9U))),6);
    bufp->fullCData(oldp+43502,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__c__DOT___ram_ext_R0_data[0U] 
                                       >> 3U))),3);
    bufp->fullBit(oldp+43503,((1U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__c__DOT___ram_ext_R0_data[0U])));
    bufp->fullBit(oldp+43504,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_0__io_sinkd_valid));
    bufp->fullBit(oldp+43505,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkD__DOT__last));
    bufp->fullCData(oldp+43506,((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkD__DOT__d__DOT___ram_ext_R0_data[0U])),3);
    bufp->fullCData(oldp+43507,((3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkD__DOT__d__DOT___ram_ext_R0_data[0U] 
                                       >> 3U))),3);
    bufp->fullCData(oldp+43508,((7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkD__DOT__d__DOT___ram_ext_R0_data[0U] 
                                       >> 0xbU))),3);
    bufp->fullBit(oldp+43509,((1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkD__DOT__d__DOT___ram_ext_R0_data[0U] 
                                     >> 0xeU))));
    bufp->fullBit(oldp+43510,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_valid));
    bufp->fullSData(oldp+43511,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_set),10);
    bufp->fullSData(oldp+43512,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_tag),13);
    bufp->fullCData(oldp+43513,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_way),3);
    bufp->fullBit(oldp+43514,((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_valid)))));
    bufp->fullBit(oldp+43515,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_valid) 
                               & (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_rprobeackfirst)) 
                                   | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_pprobeackfirst))) 
                                  | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_grantfirst))))));
    bufp->fullBit(oldp+43516,((((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_a_valid_output) 
                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_b_valid_output)) 
                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_c_valid_output)) 
                                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_d_valid_output)) 
                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_e_valid_output)) 
                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_x_valid_output)) 
                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_valid_output))));
    bufp->fullBit(oldp+43517,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_a_valid_output));
    bufp->fullCData(oldp+43518,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__req_needT)
                                  ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
                                      ? 2U : 1U) : 0U)),3);
    bufp->fullBit(oldp+43519,((1U & ((6U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_size)) 
                                     | (~ ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_opcode)) 
                                           | (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_opcode))))))));
    bufp->fullBit(oldp+43520,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_b_valid_output));
    bufp->fullCData(oldp+43521,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_rprobe)
                                  ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_prio_1)
                                      ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_param)
                                      : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__req_needT)
                                          ? 2U : 1U))
                                  : 2U)),3);
    bufp->fullSData(oldp+43522,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_rprobe)
                                  ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_tag)
                                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_tag))),13);
    bufp->fullCData(oldp+43523,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_clients) 
                                 & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__excluded_client)))),5);
    bufp->fullBit(oldp+43524,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_c_valid_output));
    bufp->fullCData(oldp+43525,((6U | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_dirty))),3);
    bufp->fullCData(oldp+43526,(((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_state))
                                  ? 2U : 1U)),3);
    bufp->fullSData(oldp+43527,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_tag),13);
    bufp->fullBit(oldp+43528,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_dirty));
    bufp->fullBit(oldp+43529,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_d_valid_output));
    bufp->fullBit(oldp+43530,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_prio_0));
    bufp->fullBit(oldp+43531,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_prio_2));
    bufp->fullCData(oldp+43532,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_opcode),3);
    bufp->fullCData(oldp+43533,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__req_acquire)
                                  ? ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_param))
                                      ? 1U : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_param))
                                               ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit) 
                                                   & (0U 
                                                      != 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_clients) 
                                                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__req_clientBit))))
                                                   ? 2U
                                                   : 1U)
                                               : ((0U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_param))
                                                   ? 
                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__req_acquire) 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
                                                       ? 
                                                      ((~ (IData)(
                                                                  (0U 
                                                                   != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_clients)))) 
                                                       & (3U 
                                                          == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_state)))
                                                       : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__gotT)))
                                                   : 0U)))
                                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_param))),3);
    bufp->fullCData(oldp+43534,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_size),3);
    bufp->fullCData(oldp+43535,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_source),6);
    bufp->fullCData(oldp+43536,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_offset),6);
    bufp->fullCData(oldp+43537,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_put),6);
    bufp->fullBit(oldp+43538,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__bad_grant));
    bufp->fullBit(oldp+43539,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_e_valid_output));
    bufp->fullCData(oldp+43540,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__sink),3);
    bufp->fullBit(oldp+43541,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_x_valid_output));
    bufp->fullBit(oldp+43542,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_valid_output));
    bufp->fullBit(oldp+43543,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_release) 
                               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty))));
    bufp->fullCData(oldp+43544,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_release)
                                  ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state)
                                  : 0U)),2);
    bufp->fullCData(oldp+43545,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_release)
                                  ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)
                                  : 0U)),5);
    bufp->fullSData(oldp+43546,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_release)
                                  ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___GEN_0)
                                      ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_tag)
                                      : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_tag))
                                  : 0U)),13);
    bufp->fullBit(oldp+43547,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait));
    bufp->fullBit(oldp+43548,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_prio_1));
    bufp->fullBit(oldp+43549,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_control));
    bufp->fullCData(oldp+43550,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_param),3);
    bufp->fullBit(oldp+43551,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_valid));
    bufp->fullCData(oldp+43552,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_state),2);
    bufp->fullCData(oldp+43553,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_clients),5);
    bufp->fullBit(oldp+43554,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit));
    bufp->fullBit(oldp+43555,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_rprobe));
    bufp->fullBit(oldp+43556,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_rprobeackfirst));
    bufp->fullBit(oldp+43557,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_rprobeacklast));
    bufp->fullBit(oldp+43558,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_release));
    bufp->fullBit(oldp+43559,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_releaseack));
    bufp->fullBit(oldp+43560,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_pprobe));
    bufp->fullBit(oldp+43561,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_acquire));
    bufp->fullBit(oldp+43562,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_flush));
    bufp->fullBit(oldp+43563,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_grantfirst));
    bufp->fullBit(oldp+43564,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_grantlast));
    bufp->fullBit(oldp+43565,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_grant));
    bufp->fullBit(oldp+43566,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_pprobeackfirst));
    bufp->fullBit(oldp+43567,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_pprobeacklast));
    bufp->fullBit(oldp+43568,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_pprobeack));
    bufp->fullBit(oldp+43569,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_grantack));
    bufp->fullBit(oldp+43570,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_execute));
    bufp->fullBit(oldp+43571,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_grantack));
    bufp->fullBit(oldp+43572,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback));
    bufp->fullBit(oldp+43573,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__gotT));
    bufp->fullCData(oldp+43574,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__probes_done),5);
    bufp->fullCData(oldp+43575,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__probes_toN),5);
    bufp->fullCData(oldp+43576,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__req_clientBit),5);
    bufp->fullBit(oldp+43577,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__req_needT));
    bufp->fullBit(oldp+43578,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__req_acquire));
    bufp->fullCData(oldp+43579,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__excluded_client),5);
    bufp->fullCData(oldp+43580,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__probe_bit),5);
    bufp->fullBit(oldp+43581,(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__last_probe));
    bufp->fullCData(oldp+43582,(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
                                  ? (0xfU & ((0x4208U 
                                              | (((0x2000U 
                                                   & ((~ (IData)(
                                                                 (0U 
                                                                  != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_clients)))) 
                                                      << 0xdU)) 
                                                  | (0x1000U 
                                                     & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_dirty)) 
                                                        << 0xcU))) 
                                                 | ((0x100U 
                                                     & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_dirty)) 
                                                        << 8U)) 
                                                    | (0x10U 
                                                       & ((~ (IData)(
                                                                     (0U 
                                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_clients)))) 
                                                          << 4U))))) 
                                             >> (0xfU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_state) 
                                                    << 2U))))
                                  : 8U)),4);
    bufp->fullCData(oldp+43583,((0xfU & ((0x4208U | 
                                          (((0x2000U 
                                             & ((~ (IData)(
                                                           (0U 
                                                            != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                << 0xdU)) 
                                            | (0x1000U 
                                               & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                  << 0xcU))) 
                                           | ((0x100U 
                                               & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                  << 8U)) 
                                              | (0x10U 
                                                 & ((~ (IData)(
                                                               (0U 
                                                                != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                    << 4U))))) 
                                         >> (0xfU & 
                                             ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                              << 2U))))),4);
}
