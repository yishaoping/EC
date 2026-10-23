// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTestHarness.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTestHarness___024root.h"

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5541(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5541\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT__in2_inv 
        = ((- (QData)((IData)((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_fn) 
                                     >> 3U))))) ^ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__alu__io_in2);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_deq_valid_0 
        = (((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_deq_ptr)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__lsl__io_req_valid_rocc)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__emptyReg)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_deq_valid_1 
        = (((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_deq_ptr)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__lsl__io_req_valid_rocc)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__emptyReg)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_49 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_31)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_sie));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_50 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_24) 
           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_31)
               ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_sie)
               : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_spie)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_51 
        = (1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_24)) 
                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_31)
                     ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_prv)
                     : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_spp))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__do_bypass 
        = ((((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1)) 
             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_bypass_src_0_1)) 
            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_bypass_src_0_2)) 
           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___dcache_kill_mem_T_3) 
              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_mem_T_1)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_bypass_src_1_1 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_29) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_ex_T_3));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_bypass_src_1_2 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_34) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_mem_T_3));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___csr_io_decode_0_system_illegal 
        = (1U & (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_decode_0_system_illegal_T) 
                    | ((IData)((0x10400000U == (0xffc00000U 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                       & (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_prv) 
                              >> 1U) | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_tw)))))) 
                   | ((0x3ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_T_16)) 
                      & (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_prv) 
                             >> 1U) | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_tsr)))))) 
                  | (IData)(((0x3ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_T_16)) 
                             & (0x48000000U == (0x48000000U 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))))) 
                 | ((IData)((0x12000073U == (0xfe0003ffU 
                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                    & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__allow_sfence_vma)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5542(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5542\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___fp_decoder_io_sigs_typeTagIn 
        = (1U & ((0x1ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_12)) 
                 | ((0x7fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_16)) 
                    | ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_18)) 
                       | ((0x7fffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_30)) 
                          | ((0x7fffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_32)) 
                             | ((0x7fffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_34)) 
                                | ((0x7ffffU == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_40) 
                                   | ((0x7ffffU == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_48) 
                                      | ((IData)((0xc2000053U 
                                                  == 
                                                  (0xefc0007fU 
                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                         | ((IData)(
                                                    (0xe0000053U 
                                                     == 
                                                     (0xfdf0707fU 
                                                      & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                            | ((IData)(
                                                       (0xe2000053U 
                                                        == 
                                                        (0xeff0707fU 
                                                         & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                               | (0x1fffffU 
                                                  == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_70)))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5543(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5543\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___fp_decoder_io_sigs_typeTagOut 
        = (1U & ((IData)((0x3027U == (0x707fU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                 | ((0x7fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_16)) 
                    | ((0xfffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_18)) 
                       | ((0x7fffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_30)) 
                          | ((0x7fffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_32)) 
                             | ((0x7fffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_34)) 
                                | ((0x7ffffU == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_44) 
                                   | ((0x7ffffU == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_48) 
                                      | ((IData)((0xd2000053U 
                                                  == 
                                                  (0xffc0007fU 
                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                         | ((0x1fffffU 
                                             == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_70) 
                                            | (0x1fffffU 
                                               == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_72))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5544(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5544\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T 
        = (((IData)((0x3007U == (0x705fU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
            << 0xbU) | (((IData)((0x2000043U == (0x6000073U 
                                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                         << 0xaU) | (((IData)((0x2000053U 
                                               == (0xe600007fU 
                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                      << 9U) | (((IData)(
                                                         (0x22000053U 
                                                          == 
                                                          (0x7e00507fU 
                                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                 << 8U) 
                                                | (((IData)(
                                                            (0x22000053U 
                                                             == 
                                                             (0x7e00607fU 
                                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                    << 7U) 
                                                   | (((IData)(
                                                               (0x22000053U 
                                                                == 
                                                                (0xf600607fU 
                                                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                       << 6U) 
                                                      | (((IData)(
                                                                  (0x7ffffU 
                                                                   == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_236)) 
                                                          << 5U) 
                                                         | (((IData)(
                                                                     (0x3ffffU 
                                                                      == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_238)) 
                                                             << 4U) 
                                                            | (((IData)(
                                                                        (0x5a000053U 
                                                                         == 
                                                                         (0xfff0007fU 
                                                                          & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                                << 3U) 
                                                               | (((IData)(
                                                                           (0xc2000053U 
                                                                            == 
                                                                            (0xefc0007fU 
                                                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                                   << 2U) 
                                                                  | (((IData)(
                                                                              (0xe2000053U 
                                                                               == 
                                                                               (0xeff0707fU 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                                      << 1U) 
                                                                     | (IData)(
                                                                               (0xe2000053U 
                                                                                == 
                                                                                (0xfff0607fU 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5545(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5545\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T_65 
        = (((IData)((0x1fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_36))) 
            << 0xaU) | (((IData)((0x7ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_40))) 
                         << 9U) | (((IData)((0x2007U 
                                             == (0x605fU 
                                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                    << 8U) | (((IData)(
                                                       (0x3fffU 
                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_208))) 
                                               << 7U) 
                                              | (((IData)(
                                                          (0x3fffU 
                                                           == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_210))) 
                                                  << 6U) 
                                                 | (((IData)(
                                                             (0x3fffU 
                                                              == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_212))) 
                                                     << 5U) 
                                                    | (((IData)(
                                                                (0x3ffffU 
                                                                 == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_234)) 
                                                        << 4U) 
                                                       | (((IData)(
                                                                   (0x3ffffU 
                                                                    == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_238)) 
                                                           << 3U) 
                                                          | (((IData)(
                                                                      (0x3ffffU 
                                                                       == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_242)) 
                                                              << 2U) 
                                                             | (((IData)(
                                                                         (0xc0000053U 
                                                                          == 
                                                                          (0xcdf0007fU 
                                                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                                 << 1U) 
                                                                | (0x7fffU 
                                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_254))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5546(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5546\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T_63 
        = (((IData)((0x7fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_12))) 
            << 3U) | (((IData)((0x7fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_42))) 
                       << 2U) | (((IData)((0x7fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_84))) 
                                  << 1U) | (0x7fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_100)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_ctrl_csr 
        = ((4U & (((IData)((0x71U == (0xffeffff9U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                   | ((0xffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_74)) 
                      | ((0xffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_104)) 
                         | ((IData)((0x10200071U == 
                                     (0xdffffff9U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                            | ((IData)((0x10500071U 
                                        == (0xdffffff9U 
                                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                               | (0x1ffffU == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_198)))))) 
                  << 2U)) | (((IData)((0xffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_104))) 
                              << 1U) | (0xffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_74))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5547(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5547\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___fp_decoder_io_sigs_wflags 
        = (1U & ((0x1fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T)) 
                 | ((0x7ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_2)) 
                    | ((IData)((0x28000053U == (0xfc00607fU 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                       | ((0x3ffffU == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_38) 
                          | ((0x3ffffU == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_42) 
                             | ((0x3ffffU == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_46) 
                                | ((0x7fffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_50)) 
                                   | ((0x7fffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_52)) 
                                      | (IData)((0xc0000053U 
                                                 == 
                                                 (0xedc0007fU 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5548(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5548\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___fp_decoder_io_sigs_ren2 
        = ((0x1fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T)) 
           | ((0x7ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_2)) 
              | ((0x1ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_12)) 
                 | ((0x3fffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_22)) 
                    | ((0x3fffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_24)) 
                       | (0x3fffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_26)))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_dec_wen 
        = (1U & ((0x1fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T)) 
                 | ((0x7ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_2)) 
                    | ((IData)((0x2007U == (0x607fU 
                                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                       | ((0x3fffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_26)) 
                          | ((0x7fffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_28)) 
                             | ((0x7ffffU == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_40) 
                                | ((0x7ffffU == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_44) 
                                   | ((0x3ffffU == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_46) 
                                      | ((0xffffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_60)) 
                                         | (0x1fffffU 
                                            == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_72)))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___fp_decoder_io_sigs_ren1 
        = ((0x1fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T)) 
           | ((0x7ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_2)) 
              | ((0x3fffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_22)) 
                 | ((0x3fffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_24)) 
                    | ((0x3fffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_26)) 
                       | ((0x3ffffU == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_38) 
                          | ((0x3ffffU == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_42) 
                             | ((0x3ffffU == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_46) 
                                | ((0xffffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_56)) 
                                   | (0xfffffU == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T_64))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5549(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5549\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_ctrl_alu_fn 
        = ((8U & (((IData)((0x2013U == (0x607fU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                   | ((IData)((0x2033U == (0xfe00607fU 
                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                      | ((0xffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_126)) 
                         | ((0xffffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_224)) 
                            | ((0xffffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_228)) 
                               | ((0xffffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_230)) 
                                  | (0xffffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_232)))))))) 
                  << 3U)) | ((4U & (((0xffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_86)) 
                                     | ((IData)((0x2033U 
                                                 == 
                                                 (0xfe00207fU 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                        | ((IData)(
                                                   (0x4013U 
                                                    == 
                                                    (0x507fU 
                                                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                           | ((IData)(
                                                      (0x4033U 
                                                       == 
                                                       (0xfc00407fU 
                                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                              | ((0xffU 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_126)) 
                                                 | ((IData)(
                                                            (0x5013U 
                                                             == 
                                                             (0xfc00705fU 
                                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                    | ((IData)(
                                                               (0x501bU 
                                                                == 
                                                                (0xfe00705fU 
                                                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                       | (0x3fffU 
                                                          == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_178))))))))) 
                                    << 2U)) | ((2U 
                                                & (((IData)(
                                                            (0x63U 
                                                             == 
                                                             (0x607fU 
                                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                    | ((IData)(
                                                               (0x3013U 
                                                                == 
                                                                (0x307fU 
                                                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                       | ((IData)(
                                                                  (0x3033U 
                                                                   == 
                                                                   (0xfc00307fU 
                                                                    & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                          | ((IData)(
                                                                     (0x6013U 
                                                                      == 
                                                                      (0x607fU 
                                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                             | ((IData)(
                                                                        (0x6033U 
                                                                         == 
                                                                         (0xfc00607fU 
                                                                          & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                                | ((IData)(
                                                                           (0x6063U 
                                                                            == 
                                                                            (0x607fU 
                                                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                                   | ((IData)(
                                                                              (0x2002033U 
                                                                               == 
                                                                               (0xfe00207fU 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                                      | ((IData)(
                                                                                (0x2006033U 
                                                                                == 
                                                                                (0xfe006077U 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                                         | ((0xffffU 
                                                                             == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_224)) 
                                                                            | ((0xffffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_228)) 
                                                                               | ((0xffffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_230)) 
                                                                                | (0xffffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_232))))))))))))) 
                                                   << 1U)) 
                                               | (1U 
                                                  & ((0x3fffU 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_60)) 
                                                     | ((0x7fffU 
                                                         == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_64)) 
                                                        | ((IData)(
                                                                   (0x1063U 
                                                                    == 
                                                                    (0x307fU 
                                                                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                           | ((0x7fffU 
                                                               == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_128)) 
                                                              | ((0x7fffU 
                                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_132)) 
                                                                 | ((0x7fffU 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_138)) 
                                                                    | ((IData)(
                                                                               (0x5033U 
                                                                                == 
                                                                                (0xfc00507fU 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                                       | ((IData)(
                                                                                (0x5063U 
                                                                                == 
                                                                                (0x507fU 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                                          | ((IData)(
                                                                                (0x7013U 
                                                                                == 
                                                                                (0x707fU 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                                             | ((IData)(
                                                                                (0x2001033U 
                                                                                == 
                                                                                (0xfe00107fU 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                                                | (IData)(
                                                                                (0x2005033U 
                                                                                == 
                                                                                (0xfe005077U 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits)))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5550(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5550\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T_12 
        = (((IData)((0x2000033U == (0xfe00007fU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
            << 2U) | (((IData)((0x2000033U == (0xfe003077U 
                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                       << 1U) | (0x3fffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_178))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5551(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5551\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_ctrl_mem_cmd 
        = (((IData)((0x1ffffU == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_198)) 
            << 4U) | (((IData)((0x7ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_94))) 
                       << 3U) | ((4U & (((0x1fffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_184)) 
                                         | ((0x1ffffU 
                                             == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_186) 
                                            | ((0x1ffffU 
                                                == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_198) 
                                               | (IData)(
                                                         (0x8000202fU 
                                                          == 
                                                          (0x9800607fU 
                                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits)))))) 
                                        << 2U)) | (
                                                   (2U 
                                                    & (((0x1ffffU 
                                                         == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_186) 
                                                        | ((0x3fffU 
                                                            == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_206)) 
                                                           | (IData)(
                                                                     (0x4000202fU 
                                                                      == 
                                                                      (0x5800607fU 
                                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))))) 
                                                       << 1U)) 
                                                   | (1U 
                                                      & ((0xffU 
                                                          == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_22)) 
                                                         | ((IData)(
                                                                    (0x2023U 
                                                                     == 
                                                                     (0x607bU 
                                                                      & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                            | ((0x3fffU 
                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_206)) 
                                                               | (IData)(
                                                                         (0x2000202fU 
                                                                          == 
                                                                          (0x3800607fU 
                                                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits)))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5552(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5552\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T_67 
        = (((QData)((IData)((((IData)((0x7fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T))) 
                              << 0x1fU) | (((IData)(
                                                    (0xffU 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_4))) 
                                            << 0x1eU) 
                                           | (((IData)(
                                                       (0x7fU 
                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_6))) 
                                               << 0x1dU) 
                                              | (((IData)(
                                                          (0xffU 
                                                           == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_10))) 
                                                  << 0x1cU) 
                                                 | (((IData)(
                                                             (0x7fU 
                                                              == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_12))) 
                                                     << 0x1bU) 
                                                    | (((IData)(
                                                                (0x1ffU 
                                                                 == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_14))) 
                                                        << 0x1aU) 
                                                       | (((IData)(
                                                                   (0x3fU 
                                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_18))) 
                                                           << 0x19U) 
                                                          | (((IData)(
                                                                      (0x7fffU 
                                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_26))) 
                                                              << 0x18U) 
                                                             | (((IData)(
                                                                         (0x1fffU 
                                                                          == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_30))) 
                                                                 << 0x17U) 
                                                                | (((IData)(
                                                                            (0x7fffU 
                                                                             == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_32))) 
                                                                    << 0x16U) 
                                                                   | (((IData)(
                                                                               (0x43U 
                                                                                == 
                                                                                (0x4000073U 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                                       << 0x15U) 
                                                                      | (((IData)(
                                                                                (0x7ffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_40))) 
                                                                          << 0x14U) 
                                                                         | (((IData)(
                                                                                (0x7fU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_42))) 
                                                                             << 0x13U) 
                                                                            | (((IData)(
                                                                                (0xffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_46))) 
                                                                                << 0x12U) 
                                                                               | (((IData)(
                                                                                (0x7fU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_52))) 
                                                                                << 0x11U) 
                                                                                | (((IData)(
                                                                                (0x73U 
                                                                                == 
                                                                                (0xffefffffU 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                                                << 0x10U) 
                                                                                | (((IData)(
                                                                                (0x3fffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_60))) 
                                                                                << 0xfU) 
                                                                                | (((IData)(
                                                                                (0x7fffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_64))) 
                                                                                << 0xeU) 
                                                                                | (((IData)(
                                                                                (0xffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_68))) 
                                                                                << 0xdU) 
                                                                                | (((IData)(
                                                                                (0x7fU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_76))) 
                                                                                << 0xcU) 
                                                                                | (((IData)(
                                                                                (0x7fU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_84))) 
                                                                                << 0xbU) 
                                                                                | (((IData)(
                                                                                (0xffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_86))) 
                                                                                << 0xaU) 
                                                                                | (((IData)(
                                                                                (0x7ffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_94))) 
                                                                                << 9U) 
                                                                                | (((IData)(
                                                                                (0x7fU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_100))) 
                                                                                << 8U) 
                                                                                | (((IData)(
                                                                                (0x7fU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_102))) 
                                                                                << 7U) 
                                                                                | (((IData)(
                                                                                (0xffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_126))) 
                                                                                << 6U) 
                                                                                | (((IData)(
                                                                                (0x7fffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_128))) 
                                                                                << 5U) 
                                                                                | (((IData)(
                                                                                (0x7fffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_132))) 
                                                                                << 4U) 
                                                                                | (((IData)(
                                                                                (0x7fffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_138))) 
                                                                                << 3U) 
                                                                                | (((IData)(
                                                                                (0x3fffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_178))) 
                                                                                << 2U) 
                                                                                | (((IData)(
                                                                                (0x1fffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_184))) 
                                                                                << 1U) 
                                                                                | (0x7ffffU 
                                                                                == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_188)))))))))))))))))))))))))))))))))) 
            << 0xcU) | (QData)((IData)((((IData)((0x10200073U 
                                                  == 
                                                  (0xdfffffffU 
                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                         << 0xbU) | 
                                        (((IData)((0x10500073U 
                                                   == 
                                                   (0xdfffffffU 
                                                    & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                          << 0xaU) 
                                         | (((IData)(
                                                     (0x3fffffU 
                                                      == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_204)) 
                                             << 9U) 
                                            | (((IData)(
                                                        (0x3fffU 
                                                         == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_208))) 
                                                << 8U) 
                                               | (((IData)(
                                                           (0x3fffU 
                                                            == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_210))) 
                                                   << 7U) 
                                                  | (((IData)(
                                                              (0x3fffU 
                                                               == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_212))) 
                                                      << 6U) 
                                                     | (((IData)(
                                                                 (0x3ffffU 
                                                                  == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_234)) 
                                                         << 5U) 
                                                        | (((IData)(
                                                                    (0x3ffffU 
                                                                     == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_238)) 
                                                            << 4U) 
                                                           | (((IData)(
                                                                       (0x3ffffU 
                                                                        == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_242)) 
                                                               << 3U) 
                                                              | (((IData)(
                                                                          (0x7fffU 
                                                                           == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_254))) 
                                                                  << 2U) 
                                                                 | (((IData)(
                                                                             (0xe0000053U 
                                                                              == 
                                                                              (0xedf0707fU 
                                                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                                     << 1U) 
                                                                    | (0xfffffU 
                                                                       == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_264)))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5553(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5553\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T_29 
        = (((IData)((3U == (0x107fU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
            << 7U) | (((IData)((0xffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_4))) 
                       << 6U) | (((IData)((0x7fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_6))) 
                                  << 5U) | (((IData)(
                                                     (0x7fU 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_76))) 
                                             << 4U) 
                                            | (((IData)(
                                                        (0x7ffU 
                                                         == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_94))) 
                                                << 3U) 
                                               | (((IData)(
                                                           (0x1fffU 
                                                            == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_184))) 
                                                   << 2U) 
                                                  | (((IData)(
                                                              (0x7ffffU 
                                                               == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_188)) 
                                                      << 1U) 
                                                     | (0x3fffffU 
                                                        == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_204))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T_2 
        = (((IData)((0x7ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_94))) 
            << 2U) | (((IData)((0x1fffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_184))) 
                       << 1U) | (0x1ffffU == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_186)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T_57 
        = (((IData)((0xffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_22))) 
            << 0xeU) | (((IData)((0x23U == (0x603fU 
                                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                         << 0xdU) | (((IData)((0x7fffU 
                                               == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_26))) 
                                      << 0xcU) | (((IData)(
                                                           (0x1fffU 
                                                            == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_30))) 
                                                   << 0xbU) 
                                                  | (((IData)(
                                                              (0x7fffU 
                                                               == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_32))) 
                                                      << 0xaU) 
                                                     | (((IData)(
                                                                 (0x33U 
                                                                  == 
                                                                  (0xfe006077U 
                                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                         << 9U) 
                                                        | (((IData)(
                                                                    (0x7ffU 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_94))) 
                                                            << 8U) 
                                                           | (((IData)(
                                                                       (0x300bU 
                                                                        == 
                                                                        (0x305fU 
                                                                         & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                               << 7U) 
                                                              | (((IData)(
                                                                          (0x305bU 
                                                                           == 
                                                                           (0x305fU 
                                                                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                                  << 6U) 
                                                                 | (((IData)(
                                                                             (0xffU 
                                                                              == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_126))) 
                                                                     << 5U) 
                                                                    | (((IData)(
                                                                                (0x7fffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_138))) 
                                                                        << 4U) 
                                                                       | (((IData)(
                                                                                (0x3fffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_178))) 
                                                                           << 3U) 
                                                                          | (((IData)(
                                                                                (0x1fffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_184))) 
                                                                              << 2U) 
                                                                             | (((IData)(
                                                                                (0x1ffffU 
                                                                                == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_186)) 
                                                                                << 1U) 
                                                                                | (IData)(
                                                                                (0x12000073U 
                                                                                == 
                                                                                (0xfe0073ffU 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits)))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5554(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5554\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T_10 
        = (((IData)((0x7fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T))) 
            << 0x1dU) | (((IData)((0xffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_4))) 
                          << 0x1cU) | (((IData)((3U 
                                                 == 
                                                 (0x407fU 
                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                        << 0x1bU) | 
                                       (((IData)((0x1ffU 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_16))) 
                                         << 0x1aU) 
                                        | (((IData)(
                                                    (0x3fU 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_18))) 
                                            << 0x19U) 
                                           | (((IData)(
                                                       (0x7fffU 
                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_26))) 
                                               << 0x18U) 
                                              | (((IData)(
                                                          (0x1fffU 
                                                           == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_30))) 
                                                  << 0x17U) 
                                                 | (((IData)(
                                                             (0x7fffU 
                                                              == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_32))) 
                                                     << 0x16U) 
                                                    | (((IData)(
                                                                (0x1ffU 
                                                                 == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_50))) 
                                                        << 0x15U) 
                                                       | (((IData)(
                                                                   (0x7fU 
                                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_52))) 
                                                           << 0x14U) 
                                                          | (((IData)(
                                                                      (0x3fffU 
                                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_60))) 
                                                              << 0x13U) 
                                                             | (((IData)(
                                                                         (0x7fffU 
                                                                          == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_64))) 
                                                                 << 0x12U) 
                                                                | (((IData)(
                                                                            (0xffU 
                                                                             == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_74))) 
                                                                    << 0x11U) 
                                                                   | (((IData)(
                                                                               (0xffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_86))) 
                                                                       << 0x10U) 
                                                                      | (((IData)(
                                                                                (0x7ffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_94))) 
                                                                          << 0xfU) 
                                                                         | (((IData)(
                                                                                (0xffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_104))) 
                                                                             << 0xeU) 
                                                                            | (((IData)(
                                                                                (0x400bU 
                                                                                == 
                                                                                (0x505fU 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                                                << 0xdU) 
                                                                               | (((IData)(
                                                                                (0x405bU 
                                                                                == 
                                                                                (0x505fU 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                                                << 0xcU) 
                                                                                | (((IData)(
                                                                                (0x7fffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_128))) 
                                                                                << 0xbU) 
                                                                                | (((IData)(
                                                                                (0x7fffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_132))) 
                                                                                << 0xaU) 
                                                                                | (((IData)(
                                                                                (0x7fffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_138))) 
                                                                                << 9U) 
                                                                                | (((IData)(
                                                                                (0x600bU 
                                                                                == 
                                                                                (0x605fU 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                                                << 8U) 
                                                                                | (((IData)(
                                                                                (0x605bU 
                                                                                == 
                                                                                (0x605fU 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                                                << 7U) 
                                                                                | (((IData)(
                                                                                (0x3fffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_178))) 
                                                                                << 6U) 
                                                                                | (((IData)(
                                                                                (0x1fffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_184))) 
                                                                                << 5U) 
                                                                                | (((IData)(
                                                                                (0x1ffffU 
                                                                                == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_186)) 
                                                                                << 4U) 
                                                                                | (((IData)(
                                                                                (0xa0000053U 
                                                                                == 
                                                                                (0xfc00507fU 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                                                << 3U) 
                                                                                | (((IData)(
                                                                                (0xa0000053U 
                                                                                == 
                                                                                (0xfc00607fU 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits))) 
                                                                                << 2U) 
                                                                                | (((IData)(
                                                                                (0xffffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_256))) 
                                                                                << 1U) 
                                                                                | (0xfffffU 
                                                                                == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_264))))))))))))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5555(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5555\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T_55 
        = (((IData)((0x7fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T))) 
            << 0x1aU) | (((IData)((0xffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_4))) 
                          << 0x19U) | (((IData)((0x7fU 
                                                 == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_6))) 
                                        << 0x18U) | 
                                       (((IData)((0x1ffU 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_16))) 
                                         << 0x17U) 
                                        | (((IData)(
                                                    (0x7fffU 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_26))) 
                                            << 0x16U) 
                                           | (((IData)(
                                                       (0x1fffU 
                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_30))) 
                                               << 0x15U) 
                                              | (((IData)(
                                                          (0x7fffU 
                                                           == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_32))) 
                                                  << 0x14U) 
                                                 | (((IData)(
                                                             (0xffU 
                                                              == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_46))) 
                                                     << 0x13U) 
                                                    | (((IData)(
                                                                (0x3fffU 
                                                                 == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_60))) 
                                                        << 0x12U) 
                                                       | (((IData)(
                                                                   (0x7fffU 
                                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_64))) 
                                                           << 0x11U) 
                                                          | (((IData)(
                                                                      (0x1ffU 
                                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_72))) 
                                                              << 0x10U) 
                                                             | (((IData)(
                                                                         (0x7fU 
                                                                          == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_76))) 
                                                                 << 0xfU) 
                                                                | (((IData)(
                                                                            (0x7fU 
                                                                             == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_84))) 
                                                                    << 0xeU) 
                                                                   | (((IData)(
                                                                               (0xffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_86))) 
                                                                       << 0xdU) 
                                                                      | (((IData)(
                                                                                (0x7ffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_94))) 
                                                                          << 0xcU) 
                                                                         | (((IData)(
                                                                                (0x7fU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_100))) 
                                                                             << 0xbU) 
                                                                            | (((IData)(
                                                                                (0xffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_106))) 
                                                                                << 0xaU) 
                                                                               | (((IData)(
                                                                                (0xffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_126))) 
                                                                                << 9U) 
                                                                                | (((IData)(
                                                                                (0x7fffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_128))) 
                                                                                << 8U) 
                                                                                | (((IData)(
                                                                                (0x7fffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_132))) 
                                                                                << 7U) 
                                                                                | (((IData)(
                                                                                (0x7fffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_138))) 
                                                                                << 6U) 
                                                                                | (((IData)(
                                                                                (0x3fffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_178))) 
                                                                                << 5U) 
                                                                                | (((IData)(
                                                                                (0x1fffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_184))) 
                                                                                << 4U) 
                                                                                | (((IData)(
                                                                                (0x1ffffU 
                                                                                == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_186)) 
                                                                                << 3U) 
                                                                                | (((IData)(
                                                                                (0x3ffffU 
                                                                                == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_200)) 
                                                                                << 2U) 
                                                                                | (((IData)(
                                                                                (0xffffU 
                                                                                == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_260))) 
                                                                                << 1U) 
                                                                                | (0x1fffffU 
                                                                                == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_270)))))))))))))))))))))))))));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___GEN_5) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__fq__io_enq_bits_btb_entry = 0x1cU;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__fq__io_enq_bits_btb_bridx 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__taken)));
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__fq__io_enq_bits_btb_entry 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_btb_resp_bits_entry;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__fq__io_enq_bits_btb_bridx 
            = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_imem_checker_mode)
                      ? ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_pc_match)) 
                         | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_bjl_cpc 
                             == (0xffffffffffULL & 
                                 (~ (3ULL | (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_pc)))))
                             ? (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_bjl_is_rvc) 
                                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_bjl_taken)))
                             : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_bjl_cpc 
                                > (0xffffffffffULL 
                                   & (~ (3ULL | (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_pc)))))))
                      : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_btb_resp_bits_bridx)));
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__fq__io_enq_bits_btb_taken 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___GEN_5) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_106));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5556(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5556\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_heb0c5f1f__0;
    VlWide<3>/*95:0*/ __Vtemp_h1c26dfd1__0;
    VlWide<3>/*95:0*/ __Vtemp_h918635c5__0;
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__lfsr_prng__DOT__state_0 
        = vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__lfsr_prng__DOT__state_0;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0_prng__DOT__state_0 
        = vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0_prng__DOT__state_0;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_26 
        = (1U & ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__wdata 
                          >> 1U)) & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mideleg 
                                             >> 1U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_39 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__csr_wen) 
            & (0x1fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___decoded_decoded_T_24))) 
           & ((0U == (0xfU & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__wdata 
                                      >> 0x3cU)))) 
              | (8U == (0xfU & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__wdata 
                                        >> 0x3cU))))));
    __Vtemp_heb0c5f1f__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT__shin);
    __Vtemp_heb0c5f1f__0[1U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT__shin 
                                        >> 0x20U));
    __Vtemp_heb0c5f1f__0[2U] = (IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_fn) 
                                         >> 3U) & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT__shin 
                                                   >> 0x3fU)));
    __Vtemp_h1c26dfd1__0[0U] = (((IData)((QData)((IData)(
                                                         ((IData)(
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__alu__io_in2 
                                                                   >> 5U)) 
                                                          & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_dw))))) 
                                 << 5U) | (0x1fU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__alu__io_in2)));
    __Vtemp_h1c26dfd1__0[1U] = (((IData)((QData)((IData)(
                                                         ((IData)(
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__alu__io_in2 
                                                                   >> 5U)) 
                                                          & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_dw))))) 
                                 >> 0x1bU) | ((IData)(
                                                      ((QData)((IData)(
                                                                       ((IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__alu__io_in2 
                                                                                >> 5U)) 
                                                                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_dw)))) 
                                                       >> 0x20U)) 
                                              << 5U));
    __Vtemp_h1c26dfd1__0[2U] = ((IData)(((QData)((IData)(
                                                         ((IData)(
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__alu__io_in2 
                                                                   >> 5U)) 
                                                          & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_dw)))) 
                                         >> 0x20U)) 
                                >> 0x1bU);
    VL_SHIFTRS_WWW(65,65,65, __Vtemp_h918635c5__0, __Vtemp_heb0c5f1f__0, __Vtemp_h1c26dfd1__0);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
        = __Vtemp_h918635c5__0[0U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
        = __Vtemp_h918635c5__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[2U] 
        = (1U & __Vtemp_h918635c5__0[2U]);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT__in1_xor_in2 
        = (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__alu__io_in1 
           ^ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT__in2_inv);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___io_adder_out_output 
        = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__alu__io_in1 
            + vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT__in2_inv) 
           + (QData)((IData)((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_fn) 
                                    >> 3U)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT___T_4 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT____Vcellinp__u_channel_rocc_0__io_enq_valid) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__fullReg))) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_deq_valid_0)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__emptyReg)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT___T_10 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT____Vcellinp__u_channel_rocc_0__io_enq_valid) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__fullReg))) 
           & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_deq_valid_0) 
                 & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__emptyReg)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5557(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5557\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT___T_16 
        = (((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT____Vcellinp__u_channel_rocc_0__io_enq_valid) 
                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__fullReg)))) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_deq_valid_0)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__emptyReg)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT___T_4 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT____Vcellinp__u_channel_rocc_1__io_enq_valid) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__fullReg))) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_deq_valid_1)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__emptyReg)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT___T_10 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT____Vcellinp__u_channel_rocc_1__io_enq_valid) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__fullReg))) 
           & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_deq_valid_1) 
                 & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__emptyReg)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT___T_16 
        = (((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT____Vcellinp__u_channel_rocc_1__io_enq_valid) 
                & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__fullReg)))) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_deq_valid_1)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__emptyReg)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__do_bypass_1 
        = ((((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2)) 
             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_bypass_src_1_1)) 
            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_bypass_src_1_2)) 
           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___dcache_kill_mem_T_3) 
              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_mem_T_3)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_csr_ren 
        = (((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_ctrl_csr)) 
            | (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_ctrl_csr))) 
           & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_csr_en 
        = (((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_ctrl_csr)) 
            | (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_ctrl_csr))) 
           | (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_ctrl_csr)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_411 
        = ((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T_57)) 
           & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_413 
        = ((0U != vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T_10) 
           & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rd)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_409 
        = ((0U != vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T_55) 
           & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1)));
}

extern const VlWide<16>/*511:0*/ VTestHarness__ConstPool__CONST_h1c449781_0;

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5558(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5558\n"); );
    // Init
    VlWide<16>/*511:0*/ __Vtemp_h8e0d838e__0;
    VlWide<16>/*511:0*/ __Vtemp_h6893ba42__0;
    VlWide<16>/*511:0*/ __Vtemp_ha5613e44__0;
    // Body
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__fq__DOT__valid_0) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_entry 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__fq__DOT__elts_0_btb_entry;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_taken 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__fq__DOT__elts_0_btb_taken;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_bridx 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__fq__DOT__elts_0_btb_bridx;
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_entry 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__fq__io_enq_bits_btb_entry;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_taken 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__fq__io_enq_bits_btb_taken;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_bridx 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT____Vcellinp__fq__io_enq_bits_btb_bridx;
    }
    VL_EXTEND_WI(504,1, __Vtemp_h8e0d838e__0, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0_prng__DOT__state_2));
    __Vtemp_h6893ba42__0[0U] = ((__Vtemp_h8e0d838e__0[0U] 
                                 << 8U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0_prng__DOT__state_1) 
                                            << 7U) 
                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0_prng__DOT__state_0) 
                                               << 6U) 
                                              | (0x3fU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__refill_paddr 
                                                    >> 6U)))));
    __Vtemp_h6893ba42__0[1U] = ((__Vtemp_h8e0d838e__0[0U] 
                                 >> 0x18U) | (__Vtemp_h8e0d838e__0[1U] 
                                              << 8U));
    __Vtemp_h6893ba42__0[2U] = ((__Vtemp_h8e0d838e__0[1U] 
                                 >> 0x18U) | (__Vtemp_h8e0d838e__0[2U] 
                                              << 8U));
    __Vtemp_h6893ba42__0[3U] = ((__Vtemp_h8e0d838e__0[2U] 
                                 >> 0x18U) | (__Vtemp_h8e0d838e__0[3U] 
                                              << 8U));
    __Vtemp_h6893ba42__0[4U] = ((__Vtemp_h8e0d838e__0[3U] 
                                 >> 0x18U) | (__Vtemp_h8e0d838e__0[4U] 
                                              << 8U));
    __Vtemp_h6893ba42__0[5U] = ((__Vtemp_h8e0d838e__0[4U] 
                                 >> 0x18U) | (__Vtemp_h8e0d838e__0[5U] 
                                              << 8U));
    __Vtemp_h6893ba42__0[6U] = ((__Vtemp_h8e0d838e__0[5U] 
                                 >> 0x18U) | (__Vtemp_h8e0d838e__0[6U] 
                                              << 8U));
    __Vtemp_h6893ba42__0[7U] = ((__Vtemp_h8e0d838e__0[6U] 
                                 >> 0x18U) | (__Vtemp_h8e0d838e__0[7U] 
                                              << 8U));
    __Vtemp_h6893ba42__0[8U] = ((__Vtemp_h8e0d838e__0[7U] 
                                 >> 0x18U) | (__Vtemp_h8e0d838e__0[8U] 
                                              << 8U));
    __Vtemp_h6893ba42__0[9U] = ((__Vtemp_h8e0d838e__0[8U] 
                                 >> 0x18U) | (__Vtemp_h8e0d838e__0[9U] 
                                              << 8U));
    __Vtemp_h6893ba42__0[0xaU] = ((__Vtemp_h8e0d838e__0[9U] 
                                   >> 0x18U) | (__Vtemp_h8e0d838e__0[0xaU] 
                                                << 8U));
    __Vtemp_h6893ba42__0[0xbU] = ((__Vtemp_h8e0d838e__0[0xaU] 
                                   >> 0x18U) | (__Vtemp_h8e0d838e__0[0xbU] 
                                                << 8U));
    __Vtemp_h6893ba42__0[0xcU] = ((__Vtemp_h8e0d838e__0[0xbU] 
                                   >> 0x18U) | (__Vtemp_h8e0d838e__0[0xcU] 
                                                << 8U));
    __Vtemp_h6893ba42__0[0xdU] = ((__Vtemp_h8e0d838e__0[0xcU] 
                                   >> 0x18U) | (__Vtemp_h8e0d838e__0[0xdU] 
                                                << 8U));
    __Vtemp_h6893ba42__0[0xeU] = ((__Vtemp_h8e0d838e__0[0xdU] 
                                   >> 0x18U) | (__Vtemp_h8e0d838e__0[0xeU] 
                                                << 8U));
    __Vtemp_h6893ba42__0[0xfU] = ((__Vtemp_h8e0d838e__0[0xeU] 
                                   >> 0x18U) | (__Vtemp_h8e0d838e__0[0xfU] 
                                                << 8U));
    VL_SHIFTL_WWW(512,512,512, __Vtemp_ha5613e44__0, VTestHarness__ConstPool__CONST_h1c449781_0, __Vtemp_h6893ba42__0);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___vb_array_T_3[0U] 
        = __Vtemp_ha5613e44__0[0U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___vb_array_T_3[1U] 
        = __Vtemp_ha5613e44__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___vb_array_T_3[2U] 
        = __Vtemp_ha5613e44__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___vb_array_T_3[3U] 
        = __Vtemp_ha5613e44__0[3U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___vb_array_T_3[4U] 
        = __Vtemp_ha5613e44__0[4U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___vb_array_T_3[5U] 
        = __Vtemp_ha5613e44__0[5U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___vb_array_T_3[6U] 
        = __Vtemp_ha5613e44__0[6U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___vb_array_T_3[7U] 
        = __Vtemp_ha5613e44__0[7U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___vb_array_T_3[8U] 
        = __Vtemp_ha5613e44__0[8U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___vb_array_T_3[9U] 
        = __Vtemp_ha5613e44__0[9U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___vb_array_T_3[0xaU] 
        = __Vtemp_ha5613e44__0[0xaU];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___vb_array_T_3[0xbU] 
        = __Vtemp_ha5613e44__0[0xbU];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___vb_array_T_3[0xcU] 
        = __Vtemp_ha5613e44__0[0xcU];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___vb_array_T_3[0xdU] 
        = __Vtemp_ha5613e44__0[0xdU];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___vb_array_T_3[0xeU] 
        = __Vtemp_ha5613e44__0[0xeU];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___vb_array_T_3[0xfU] 
        = __Vtemp_ha5613e44__0[0xfU];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0_prng__DOT__state_2) 
            << 2U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0_prng__DOT__state_1) 
                       << 1U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0_prng__DOT__state_0)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT__slt 
        = (1U & (((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__alu__io_in1 
                                 >> 0x3fU))) == (1U 
                                                 & (IData)(
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__alu__io_in2 
                                                            >> 0x3fU))))
                  ? (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___io_adder_out_output 
                             >> 0x3fU)) : ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_fn))
                                            ? (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__alu__io_in2 
                                                       >> 0x3fU))
                                            : (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__alu__io_in1 
                                                       >> 0x3fU)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_mem_req_bits_addr 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___ptw_io_mem_req_valid)
            ? (((QData)((IData)((0xfffffU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn)))) 
                << 0xcU) | (QData)((IData)(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pte_addr_vpn_idx) 
                                            << 3U))))
            : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output)
                ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output)
                    ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits)
                        ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_1_addr
                        : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__reqs_0_addr)
                    : 0ULL) : (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
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
                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___io_adder_out_output)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5559(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5559\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_56 
        = ((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T_57)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__do_bypass_1)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_illegal_insn 
        = (1U & (((((((((~ (IData)((0U != vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T_67))) 
                        | ((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T_12)) 
                           & (~ (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_misa 
                                         >> 0xcU))))) 
                       | ((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T_2)) 
                          & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_misa)))) 
                      | ((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T_65)) 
                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_decode_0_fp_illegal_output) 
                            | (((5U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                              >> 0xcU))) 
                                | (6U == (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                >> 0xcU)))) 
                               | (IData)(((0x7000U 
                                           == (0x7000U 
                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits)) 
                                          & (4U < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_fpu_fcsr_rm)))))))) 
                     | ((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T)) 
                        & (~ (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_misa 
                                      >> 3U))))) | 
                    ((3U != (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst)) 
                     & (~ (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_misa 
                                   >> 2U))))) | ((0U 
                                                  != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T_63)) 
                                                 & (~ (IData)(
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_misa 
                                                               >> 0x17U))))) 
                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_csr_en) 
                     & ((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_decode_0_system_illegal_T) 
                            | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__csr_exists))) 
                           | (((0x180U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                           >> 0x14U)) 
                               | (0x680U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                             >> 0x14U))) 
                              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__allow_sfence_vma)))) 
                          | ((((0xbffU < (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                          >> 0x14U)) 
                               & (0xc20U > (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                            >> 0x14U))) 
                              | ((0xc7fU < (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                            >> 0x14U)) 
                                 & (0xca0U > (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                              >> 0x14U)))) 
                             & (~ ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_prv) 
                                     >> 1U) | ((0x1fU 
                                                >= 
                                                (0x1fU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                    >> 0x14U)))
                                                ? (
                                                   (7U 
                                                    & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mcounteren) 
                                                   >> 
                                                   (0x1fU 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                       >> 0x14U)))
                                                : 0U)) 
                                   & ((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mstatus_prv)) 
                                      | ((0x1fU >= 
                                          (0x1fU & 
                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                            >> 0x14U)))
                                          ? ((7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_scounteren) 
                                             >> (0x1fU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                    >> 0x14U)))
                                          : 0U)))))) 
                         | ((0xfU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_decode_0_fp_csr_T)) 
                            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_decode_0_fp_illegal_output))) 
                        | ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_csr_ren)) 
                           & (3U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                     >> 0x1eU)))))) 
                 | (((3U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst)) 
                     & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_ctrl_csr))) 
                    & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___csr_io_decode_0_system_illegal))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5560(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5560\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_wb_hazard 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_valid) 
           & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_wxd) 
                & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_409) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_wb_T_1)) 
                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_411) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_wb_T_3))) 
                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_413) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_wb_T_7)))) 
               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_set_sboard)) 
              | (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T_65)) 
                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_wfd)) 
                 & (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___fp_decoder_io_sigs_ren1) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_wb_T_1)) 
                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___fp_decoder_io_sigs_ren2) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_wb_T_3))) 
                     | ((0x1fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T)) 
                        & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                            >> 0x1bU) == (0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_inst 
                                                   >> 7U))))) 
                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_dec_wen) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_wb_T_7))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_ex_hazard 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_valid) 
           & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_wxd) 
                & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_409) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_ex_T_1)) 
                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_411) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_ex_T_3))) 
                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_413) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_ex_T_7)))) 
               & ((((((((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_csr)) 
                        | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_jalr)) 
                       | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_mem)) 
                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_mul)) 
                     | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_div)) 
                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_fp)) 
                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_rocc)) 
                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_scie_pipelined))) 
              | (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T_65)) 
                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_wfd)) 
                 & (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___fp_decoder_io_sigs_ren1) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_ex_T_1)) 
                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___fp_decoder_io_sigs_ren2) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_ex_T_3))) 
                     | ((0x1fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T)) 
                        & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                            >> 0x1bU) == (0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_inst 
                                                   >> 7U))))) 
                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_dec_wen) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_ex_T_7))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5561(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5561\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__data_hazard_mem 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_wxd) 
           & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_409) 
                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_mem_T_1)) 
               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_411) 
                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_mem_T_3))) 
              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_413) 
                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_mem_T_7))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__nIC 
        = (3U & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_taken)
                   ? ((IData)(1U) + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_bridx))
                   : 2U) - (1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_pc 
                                          >> 1U)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__tag_array__RW0_wmask 
        = (((IData)((7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0))) 
            << 7U) | (((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0)) 
                       << 6U) | (((5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0)) 
                                  << 5U) | (((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0)) 
                                             << 4U) 
                                            | (((3U 
                                                 == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0)) 
                                                << 3U) 
                                               | (((2U 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0)) 
                                                   << 2U) 
                                                  | (((1U 
                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0)) 
                                                      << 1U) 
                                                     | (1U 
                                                        & (~ (IData)(
                                                                     (0U 
                                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__data_arrays_0__RW0_wmask 
        = (((IData)((7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0))) 
            << 7U) | (((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0)) 
                       << 6U) | (((5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0)) 
                                  << 5U) | (((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0)) 
                                             << 4U) 
                                            | (((3U 
                                                 == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0)) 
                                                << 3U) 
                                               | (((2U 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0)) 
                                                   << 2U) 
                                                  | (((1U 
                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0)) 
                                                      << 1U) 
                                                     | (1U 
                                                        & (~ (IData)(
                                                                     (0U 
                                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT____Vcellinp__data_arrays_1__RW0_wmask 
        = (((IData)((7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0))) 
            << 7U) | (((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0)) 
                       << 6U) | (((5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0)) 
                                  << 5U) | (((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0)) 
                                             << 4U) 
                                            | (((3U 
                                                 == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0)) 
                                                << 3U) 
                                               | (((2U 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0)) 
                                                   << 2U) 
                                                  | (((1U 
                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0)) 
                                                      << 1U) 
                                                     | (1U 
                                                        & (~ (IData)(
                                                                     (0U 
                                                                      != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5562(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5562\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT__out 
        = (((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_fn)) 
            | (0xaU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_fn)))
            ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___io_adder_out_output
            : (((((QData)((IData)(((0xbU < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_fn)) 
                                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT__slt)))) 
                  | (((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_fn)) 
                      | (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_fn)))
                      ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT__in1_xor_in2
                      : 0ULL)) | (((6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_fn)) 
                                   | (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_fn)))
                                   ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__alu__io_in1 
                                      & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT____Vcellinp__alu__io_in2)
                                   : 0ULL)) | (((5U 
                                                 == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_fn)) 
                                                | (0xbU 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_fn)))
                                                ? (
                                                   ((QData)((IData)(
                                                                    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U])) 
                                                    << 0x20U) 
                                                   | (QData)((IData)(
                                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U])))
                                                : 0ULL)) 
               | ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_alu_fn))
                   ? (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                         << 0x1fU) 
                                        | ((0x40000000U 
                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                               << 0x1dU)) 
                                           | ((0x20000000U 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                  << 0x1bU)) 
                                              | ((0x10000000U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                     << 0x19U)) 
                                                 | ((0x8000000U 
                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                        << 0x17U)) 
                                                    | ((0x4000000U 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                           << 0x15U)) 
                                                       | ((0x2000000U 
                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                              << 0x13U)) 
                                                          | ((0x1000000U 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                                 << 0x11U)) 
                                                             | ((0x800000U 
                                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                                    << 0xfU)) 
                                                                | ((0x400000U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                                       << 0xdU)) 
                                                                   | ((0x200000U 
                                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                                          << 0xbU)) 
                                                                      | ((0x100000U 
                                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                                             << 9U)) 
                                                                         | ((0x80000U 
                                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                                                << 7U)) 
                                                                            | ((0x40000U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                                                << 5U)) 
                                                                               | ((0x20000U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                                                << 3U)) 
                                                                                | ((0x10000U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                                                << 1U)) 
                                                                                | ((0x8000U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                                                >> 1U)) 
                                                                                | ((0x4000U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                                                >> 3U)) 
                                                                                | ((0x2000U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                                                >> 5U)) 
                                                                                | ((0x1000U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                                                >> 7U)) 
                                                                                | ((0x800U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                                                >> 9U)) 
                                                                                | ((0x400U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                                                >> 0xbU)) 
                                                                                | ((0x200U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                                                >> 0xdU)) 
                                                                                | ((0x100U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                                                >> 0xfU)) 
                                                                                | ((0x80U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                                                >> 0x11U)) 
                                                                                | ((0x40U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                                                >> 0x13U)) 
                                                                                | ((0x20U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                                                >> 0x15U)) 
                                                                                | ((0x10U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                                                >> 0x17U)) 
                                                                                | ((8U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                                                >> 0x19U)) 
                                                                                | ((4U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                                                >> 0x1bU)) 
                                                                                | ((2U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                                                >> 0x1dU)) 
                                                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[0U] 
                                                                                >> 0x1fU)))))))))))))))))))))))))))))))))) 
                       << 0x20U) | (QData)((IData)(
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                     << 0x1fU) 
                                                    | ((0x40000000U 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                           << 0x1dU)) 
                                                       | ((0x20000000U 
                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                              << 0x1bU)) 
                                                          | ((0x10000000U 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                 << 0x19U)) 
                                                             | ((0x8000000U 
                                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                    << 0x17U)) 
                                                                | ((0x4000000U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                       << 0x15U)) 
                                                                   | ((0x2000000U 
                                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                          << 0x13U)) 
                                                                      | ((0x1000000U 
                                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                             << 0x11U)) 
                                                                         | ((0x800000U 
                                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                                << 0xfU)) 
                                                                            | ((0x400000U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                                << 0xdU)) 
                                                                               | ((0x200000U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                                << 0xbU)) 
                                                                                | ((0x100000U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                                << 9U)) 
                                                                                | ((0x80000U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                                << 7U)) 
                                                                                | ((0x40000U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                                << 5U)) 
                                                                                | ((0x20000U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                                << 3U)) 
                                                                                | ((0x10000U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                                << 1U)) 
                                                                                | ((0x8000U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                                >> 1U)) 
                                                                                | ((0x4000U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                                >> 3U)) 
                                                                                | ((0x2000U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                                >> 5U)) 
                                                                                | ((0x1000U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                                >> 7U)) 
                                                                                | ((0x800U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                                >> 9U)) 
                                                                                | ((0x400U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                                >> 0xbU)) 
                                                                                | ((0x200U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                                >> 0xdU)) 
                                                                                | ((0x100U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                                >> 0xfU)) 
                                                                                | ((0x80U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                                >> 0x11U)) 
                                                                                | ((0x40U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                                >> 0x13U)) 
                                                                                | ((0x20U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                                >> 0x15U)) 
                                                                                | ((0x10U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                                >> 0x17U)) 
                                                                                | ((8U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                                >> 0x19U)) 
                                                                                | ((4U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                                >> 0x1bU)) 
                                                                                | ((2U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                                >> 0x1dU)) 
                                                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__alu__DOT___shout_r_T_5[1U] 
                                                                                >> 0x1fU)))))))))))))))))))))))))))))))))))
                   : 0ULL)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5563(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5563\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_xcpt 
        = (((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___csr_io_interrupt) 
                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__bpu__DOT___T_5)) 
               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_xcpt0_pf_inst)) 
              | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_xcpt0_gf_inst)) 
             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_xcpt0_ae_inst)) 
            | (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT___io_inst_0_bits_xcpt1_WIRE_1))) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_illegal_insn));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_mem_hazard 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_valid) 
           & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__data_hazard_mem) 
               & ((((((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_csr)) 
                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_mem) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_slow_bypass))) 
                     | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_mul)) 
                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_div)) 
                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_fp)) 
                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_rocc))) 
              | (((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T_65)) 
                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_wfd)) 
                 & (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___fp_decoder_io_sigs_ren1) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_mem_T_1)) 
                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___fp_decoder_io_sigs_ren2) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_mem_T_3))) 
                     | ((0x1fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fp_decoder__DOT___decoder_decoded_T)) 
                        & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__inst 
                            >> 0x1bU) == (0x1fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                   >> 7U))))) 
                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_dec_wen) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___fp_data_hazard_mem_T_7))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__load_use_RAW 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_ex_hazard) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_mem)) 
            | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_mem_hazard) 
               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_mem))) 
           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_wb_hazard) 
              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_ctrl_mem)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_427 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__load_use_RAW) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
              | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5564(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5564\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_tileClockGroup_tile_4_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT___tileResetSetter_auto_clock_out_member_allClocks_tileClockGroup_tile_4_reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_tileClockGroup_tile_4_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_tileClockGroup_tile_4_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT___tileResetSetter_auto_clock_out_member_allClocks_tileClockGroup_tile_4_reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_tileClockGroup_tile_4_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_2));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_tileClockGroup_tile_4_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_2 
        = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__prci_ctrl_domain__DOT___tileResetSetter_auto_clock_out_member_allClocks_tileClockGroup_tile_4_reset)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5574(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5574\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5575(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5575\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_data_cdc_3__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_arfs_cdc_3__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__source__DOT__sink_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_l2b_ctrl_cdc_3__DOT__sink__DOT__sink_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__sink__DOT__source_extend__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_u_b2l_ctrl_cdc_3__DOT__source__DOT__source_valid_1__DOT__io_out_source_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5576(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5576\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_1 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_a_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_d_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_d_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__source_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__bundleIn_0_b_source__DOT__source_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_c_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_e_source__DOT__sink_extend__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_2 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__x1_a_source__DOT____Vcellinp__source_valid_0__reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_e_sink__DOT__sink_valid_1__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8387(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8387\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeated_repeater__DOT__saved_corrupt 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeated_repeater__DOT__saved_corrupt;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__ghm_debug_gcounter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__ghm_debug_gcounter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8388(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8388\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_xcpt_ma_if 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_xcpt_ma_if;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_iw_p2_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_iw_p2_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_iw_p1_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_iw_p1_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_ctrl_is_std 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_ctrl_is_std;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_ctrl_is_sta 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_ctrl_is_sta;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_ctrl_is_load 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_ctrl_is_load;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_ctrl_fcn_dw 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_ctrl_fcn_dw;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_xcpt_ma_if 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_xcpt_ma_if;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_iw_p2_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_iw_p2_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_iw_p1_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_iw_p1_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_ctrl_is_std 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_ctrl_is_std;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_ctrl_is_sta 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_ctrl_is_sta;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_ctrl_is_load 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_ctrl_is_load;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_ctrl_fcn_dw 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_ctrl_fcn_dw;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_xcpt_ma_if 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_xcpt_ma_if;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_iw_p2_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_iw_p2_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_iw_p1_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_iw_p1_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_ctrl_is_std 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_ctrl_is_std;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_ctrl_is_sta 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_ctrl_is_sta;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_ctrl_is_load 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_ctrl_is_load;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_ctrl_fcn_dw 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_ctrl_fcn_dw;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_xcpt_ma_if 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_xcpt_ma_if;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_iw_p2_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_iw_p2_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_iw_p1_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_iw_p1_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_ctrl_is_std 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_ctrl_is_std;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_ctrl_is_sta 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_ctrl_is_sta;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_ctrl_is_load 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_ctrl_is_load;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_ctrl_fcn_dw 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_ctrl_fcn_dw;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_xcpt_ma_if 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_xcpt_ma_if;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_iw_p2_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_iw_p2_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_iw_p1_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_iw_p1_poisoned;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8389(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8389\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_ctrl_is_std 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_ctrl_is_std;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_ctrl_is_sta 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_ctrl_is_sta;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_ctrl_is_load 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_ctrl_is_load;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_xcpt_ma_if 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_xcpt_ma_if;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_iw_p2_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_iw_p2_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_iw_p1_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_iw_p1_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_ctrl_is_std 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_ctrl_is_std;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_ctrl_is_sta 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_ctrl_is_sta;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_ctrl_is_load 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_ctrl_is_load;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_ctrl_fcn_dw 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_ctrl_fcn_dw;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_xcpt_ma_if 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_xcpt_ma_if;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_iw_p2_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_iw_p2_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_iw_p1_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_iw_p1_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_ctrl_is_std 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_ctrl_is_std;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_ctrl_is_sta 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_ctrl_is_sta;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_ctrl_is_load 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_ctrl_is_load;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_ctrl_fcn_dw 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_ctrl_fcn_dw;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_xcpt_ma_if 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_xcpt_ma_if;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_iw_p2_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_iw_p2_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_iw_p1_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_iw_p1_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_ctrl_is_std 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_ctrl_is_std;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_ctrl_is_sta 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_ctrl_is_sta;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_ctrl_is_load 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_ctrl_is_load;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_ctrl_fcn_dw 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_ctrl_fcn_dw;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_xcpt_ma_if 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_xcpt_ma_if;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_iw_p2_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_iw_p2_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_iw_p1_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_iw_p1_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_ctrl_is_std 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_ctrl_is_std;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_ctrl_is_sta 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_ctrl_is_sta;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_ctrl_is_load 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_ctrl_is_load;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_ctrl_fcn_dw 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_ctrl_fcn_dw;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_xcpt_ma_if 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_xcpt_ma_if;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_iw_p2_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_iw_p2_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_iw_p1_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_iw_p1_poisoned;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8390(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8390\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_ctrl_is_std 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_ctrl_is_std;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_ctrl_is_sta 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_ctrl_is_sta;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_ctrl_is_load 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_ctrl_is_load;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_ctrl_fcn_dw 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_ctrl_fcn_dw;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_iw_p2_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_iw_p2_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_iw_p1_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_iw_p1_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_ctrl_is_std 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_ctrl_is_std;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_ctrl_fcn_dw 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_ctrl_fcn_dw;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_ctrl_is_sta 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_ctrl_is_sta;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_iw_p2_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_iw_p2_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_iw_p1_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_iw_p1_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_ctrl_is_std 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_ctrl_is_std;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_ctrl_is_sta 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_ctrl_is_sta;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_ctrl_is_load 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_ctrl_is_load;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_ctrl_is_sta 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_ctrl_is_sta;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_iw_p2_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_iw_p2_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_iw_p1_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_iw_p1_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_ctrl_is_std 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_ctrl_is_std;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_ctrl_is_sta 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_ctrl_is_sta;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_ctrl_fcn_dw 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_ctrl_fcn_dw;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_ctrl_is_sta 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_ctrl_is_sta;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_ctrl_is_sta 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_ctrl_is_sta;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_iw_p1_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_iw_p1_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_ctrl_fcn_dw 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_ctrl_fcn_dw;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_iw_p2_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_iw_p2_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_ctrl_is_std 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_ctrl_is_std;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_ctrl_is_sta 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_ctrl_is_sta;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_iw_p1_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_iw_p1_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_ctrl_is_std 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_ctrl_is_std;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_ctrl_is_load 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_ctrl_is_load;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_ctrl_fcn_dw 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_ctrl_fcn_dw;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_iw_p2_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_iw_p2_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_ctrl_is_std 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_ctrl_is_std;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_ctrl_is_sta 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_ctrl_is_sta;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8391(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8391\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_ctrl_is_load 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_ctrl_is_load;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_ctrl_is_load 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_ctrl_is_load;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_ctrl_is_std 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_ctrl_is_std;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_ctrl_is_sta 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_ctrl_is_sta;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_ctrl_is_load 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_ctrl_is_load;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_ctrl_fcn_dw 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_ctrl_fcn_dw;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_xcpt_ma_if 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_xcpt_ma_if;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_iw_p1_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_iw_p1_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_ctrl_fcn_dw 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_ctrl_fcn_dw;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_iw_p1_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_iw_p1_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_ctrl_is_sta 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_ctrl_is_sta;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_ctrl_is_sta 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_ctrl_is_sta;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_iw_p2_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_iw_p2_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_iw_p1_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_iw_p1_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_ctrl_fcn_dw 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_ctrl_fcn_dw;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_ctrl_is_load 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_ctrl_is_load;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_ctrl_is_sta 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_ctrl_is_sta;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_iw_p2_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_iw_p2_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_ctrl_is_sta 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_ctrl_is_sta;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_ctrl_fcn_dw 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_ctrl_fcn_dw;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_ctrl_is_load 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_ctrl_is_load;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_ctrl_is_sta 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_ctrl_is_sta;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_ctrl_is_std 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_ctrl_is_std;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_iw_p1_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_iw_p1_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_iw_p2_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_iw_p2_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_xcpt_ma_if 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_xcpt_ma_if;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_ctrl_fcn_dw 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_ctrl_fcn_dw;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_ctrl_is_load 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_ctrl_is_load;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_ctrl_is_std 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_ctrl_is_std;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_iw_p1_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_iw_p1_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_iw_p2_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_iw_p2_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_xcpt_ma_if 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_xcpt_ma_if;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_xcpt_ma_if 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_xcpt_ma_if;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_ctrl_fcn_dw 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_ctrl_fcn_dw;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8392(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8392\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_ctrl_is_load 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_ctrl_is_load;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_ctrl_is_std 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_ctrl_is_std;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_iw_p1_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_iw_p1_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_iw_p2_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_iw_p2_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_xcpt_ma_if 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_xcpt_ma_if;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_xcpt_ma_if 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_xcpt_ma_if;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_ctrl_fcn_dw 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_ctrl_fcn_dw;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_ctrl_is_load 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_ctrl_is_load;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_ctrl_is_std 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_ctrl_is_std;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_iw_p2_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_iw_p2_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_xcpt_ma_if 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_xcpt_ma_if;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_xcpt_ma_if 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_xcpt_ma_if;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_ctrl_fcn_dw 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_ctrl_fcn_dw;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_ctrl_is_load 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_ctrl_is_load;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_ctrl_is_std 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_ctrl_is_std;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_iw_p1_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_iw_p1_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_iw_p2_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_iw_p2_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_xcpt_ma_if 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_xcpt_ma_if;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_xcpt_ma_if 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_xcpt_ma_if;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_ctrl_fcn_dw 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_ctrl_fcn_dw;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_ctrl_is_load 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_ctrl_is_load;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_ctrl_is_std 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_ctrl_is_std;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_iw_p1_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_iw_p1_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_iw_p2_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_iw_p2_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_xcpt_ma_if 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_xcpt_ma_if;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_xcpt_ma_if 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_xcpt_ma_if;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_ctrl_fcn_dw 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_ctrl_fcn_dw;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_ctrl_is_load 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_ctrl_is_load;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_ctrl_is_std 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_ctrl_is_std;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_iw_p1_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_iw_p1_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_iw_p2_poisoned 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_iw_p2_poisoned;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_xcpt_ma_if 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_xcpt_ma_if;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_xcpt_ma_if 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_xcpt_ma_if;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_ctrl_fcn_dw 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_ctrl_fcn_dw;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8393(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8393\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_ctrl_is_load 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_ctrl_is_load;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT__next_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__putbuffer__DOT__next_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8394(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8394\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkA__DOT__putbuffer__DOT__next_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8396(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8396\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__deq__DOT__ram_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8398(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8398\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rcq_rs2__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rcq_rs1__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_0__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_1__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8399(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8399\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_2__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_3__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_4__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_5__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_6__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB0Way_7__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_0__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_1__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_2__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_3__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_4__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_5__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_6__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__dataArrayB1Way_7__DOT__dataArrayB0Way_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT__tail_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__data__DOT__array_0_0__DOT__array_0_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__data__DOT__array_0_0__DOT__array_0_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8400(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8400\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__data__DOT__array_1_0__DOT__array_0_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__data__DOT__array_1_0__DOT__array_0_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__data__DOT__array_2_0__DOT__array_0_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__data__DOT__array_2_0__DOT__array_0_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__data__DOT__array_3_0__DOT__array_0_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__data__DOT__array_3_0__DOT__array_0_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__data__DOT__array_4_0__DOT__array_0_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__data__DOT__array_4_0__DOT__array_0_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__data__DOT__array_5_0__DOT__array_0_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__data__DOT__array_5_0__DOT__array_0_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__data__DOT__array_6_0__DOT__array_0_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__data__DOT__array_6_0__DOT__array_0_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__data__DOT__array_7_0__DOT__array_0_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__data__DOT__array_7_0__DOT__array_0_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8403(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8403\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_0__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_0__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_0__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_0__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_0__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_0__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_0__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_0__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_1__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_1__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_1__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_1__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_1__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_1__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_1__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_1__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_2__DOT__hi_us__DOT__hi_us_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_2__DOT__hi_us__DOT__hi_us_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_2__DOT__hi_us__DOT__hi_us_0_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_2__DOT__hi_us__DOT__hi_us_0_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_2__DOT__lo_us__DOT__hi_us_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_2__DOT__lo_us__DOT__hi_us_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_2__DOT__lo_us__DOT__hi_us_0_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_2__DOT__lo_us__DOT__hi_us_0_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_3__DOT__hi_us__DOT__hi_us_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_3__DOT__hi_us__DOT__hi_us_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_3__DOT__hi_us__DOT__hi_us_0_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_3__DOT__hi_us__DOT__hi_us_0_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_3__DOT__lo_us__DOT__hi_us_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_3__DOT__lo_us__DOT__hi_us_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_3__DOT__lo_us__DOT__hi_us_0_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8404(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8404\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_3__DOT__lo_us__DOT__hi_us_0_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_4__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_4__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_4__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_4__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_4__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_4__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_4__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_4__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_5__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_5__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_5__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_5__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_5__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_5__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_5__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_5__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_0__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_0__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_0__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_0__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_0__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_0__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_0__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_0__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_1__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_1__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_1__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_1__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_1__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_1__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_1__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_1__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_2__DOT__hi_us__DOT__hi_us_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8405(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8405\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_2__DOT__hi_us__DOT__hi_us_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_2__DOT__hi_us__DOT__hi_us_0_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_2__DOT__hi_us__DOT__hi_us_0_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_2__DOT__lo_us__DOT__hi_us_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_2__DOT__lo_us__DOT__hi_us_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_2__DOT__lo_us__DOT__hi_us_0_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_2__DOT__lo_us__DOT__hi_us_0_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_3__DOT__hi_us__DOT__hi_us_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_3__DOT__hi_us__DOT__hi_us_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_3__DOT__hi_us__DOT__hi_us_0_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_3__DOT__hi_us__DOT__hi_us_0_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_3__DOT__lo_us__DOT__hi_us_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_3__DOT__lo_us__DOT__hi_us_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_3__DOT__lo_us__DOT__hi_us_0_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_3__DOT__lo_us__DOT__hi_us_0_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_4__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_4__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_4__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_4__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_4__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_4__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_4__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_4__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_5__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_5__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_5__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_5__DOT__hi_us__DOT__hi_us_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_5__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_5__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_5__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_5__DOT__lo_us__DOT__hi_us_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__putbuffer__DOT__tail_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8406(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8406\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkA__DOT__putbuffer__DOT__tail_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_0__DOT__table_0__DOT__table_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_0__DOT__table_0__DOT__table_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_0__DOT__table_0__DOT__table_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_0__DOT__table_0__DOT__table_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_1__DOT__table_0__DOT__table_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_1__DOT__table_0__DOT__table_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_1__DOT__table_0__DOT__table_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_1__DOT__table_0__DOT__table_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_2__DOT__table_0__DOT__table_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_2__DOT__table_0__DOT__table_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_2__DOT__table_0__DOT__table_0_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_2__DOT__table_0__DOT__table_0_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_3__DOT__table_0__DOT__table_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_3__DOT__table_0__DOT__table_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_3__DOT__table_0__DOT__table_0_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_3__DOT__table_0__DOT__table_0_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_4__DOT__table_0__DOT__table_1_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_4__DOT__table_0__DOT__table_1_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_4__DOT__table_0__DOT__table_1_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_4__DOT__table_0__DOT__table_1_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_5__DOT__table_0__DOT__table_1_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_5__DOT__table_0__DOT__table_1_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_5__DOT__table_0__DOT__table_1_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_5__DOT__table_0__DOT__table_1_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_0__DOT__table_0__DOT__table_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_0__DOT__table_0__DOT__table_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_0__DOT__table_0__DOT__table_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_0__DOT__table_0__DOT__table_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8407(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8407\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_1__DOT__table_0__DOT__table_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_1__DOT__table_0__DOT__table_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_1__DOT__table_0__DOT__table_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_1__DOT__table_0__DOT__table_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_2__DOT__table_0__DOT__table_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_2__DOT__table_0__DOT__table_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_2__DOT__table_0__DOT__table_0_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_2__DOT__table_0__DOT__table_0_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_3__DOT__table_0__DOT__table_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_3__DOT__table_0__DOT__table_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_3__DOT__table_0__DOT__table_0_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_3__DOT__table_0__DOT__table_0_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_4__DOT__table_0__DOT__table_1_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_4__DOT__table_0__DOT__table_1_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_4__DOT__table_0__DOT__table_1_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_4__DOT__table_0__DOT__table_1_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_5__DOT__table_0__DOT__table_1_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_5__DOT__table_0__DOT__table_1_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_5__DOT__table_0__DOT__table_1_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_5__DOT__table_0__DOT__table_1_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8408(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8408\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_4__DOT__data__DOT__data_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_4__DOT__data__DOT__data_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_4__DOT__data__DOT__data_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_4__DOT__data__DOT__data_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_4__DOT__data__DOT__data_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_4__DOT__data__DOT__data_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_4__DOT__data__DOT__data_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_4__DOT__data__DOT__data_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8409(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8409\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxq__DOT__ram_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8412(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8412\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__int_rtc_tick_c_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__int_rtc_tick_c_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8419(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8419\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__d_first_counter_2;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8422(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8422\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__d_first_counter_1;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8423(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8423\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__d_first_counter_1;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8424(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8424\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_2__DOT__btb_0__DOT__btb_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_2__DOT__btb_0__DOT__btb_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_2__DOT__btb_0__DOT__btb_0_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_2__DOT__btb_0__DOT__btb_0_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_2__DOT__btb_1__DOT__btb_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_2__DOT__btb_1__DOT__btb_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_2__DOT__btb_1__DOT__btb_0_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_2__DOT__btb_1__DOT__btb_0_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_2__DOT__btb_0__DOT__btb_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_2__DOT__btb_0__DOT__btb_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_2__DOT__btb_0__DOT__btb_0_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_2__DOT__btb_0__DOT__btb_0_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_2__DOT__btb_1__DOT__btb_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_2__DOT__btb_1__DOT__btb_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_2__DOT__btb_1__DOT__btb_0_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_2__DOT__btb_1__DOT__btb_0_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8432(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8432\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__monitor__DOT__a_first_counter_1;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8453(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8453\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__d_first_counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8455(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8455\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxq__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxq__DOT__enq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxq__DOT__deq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxq__DOT__deq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__a_first_counter_1;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8460(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8460\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__a_first_counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8463(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8463\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__d_first_counter_2;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8465(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8465\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txq__DOT__deq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txq__DOT__deq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txq__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txq__DOT__enq_ptr_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8471(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8471\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__d_first_counter_1;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8472(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8472\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__maybe_full 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__maybe_full;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__monitor__DOT__a_first_counter_1;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8478(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8478\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8490(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8490\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_2__DOT__ebtb__DOT__ebtb_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_2__DOT__ebtb__DOT__ebtb_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__d_first_counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8491(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8491\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__d_first_counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8505(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8505\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__c_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__c_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__monitor__DOT__c_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__monitor__DOT__c_first_counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8506(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8506\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a__DOT__ram_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8507(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8507\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a_last_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__error__DOT__a_last_counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8511(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8511\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__maybe_full 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__x1_a_q__DOT__maybe_full;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8513(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8513\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__d_first_counter_1;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8515(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8515\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__d_first_counter_1;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8516(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8516\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8517(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8517\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_ldst_is_rs1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_2_ldst_is_rs1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_ldst_is_rs1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_ldst_is_rs1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_ldst_is_rs1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_ldst_is_rs1;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8518(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8518\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__monitor__DOT__d_first_counter_2;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8519(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8519\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__atomics__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__atomics__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__atomics__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__atomics__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_2__DOT__meta_1__DOT__meta_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_2__DOT__meta_1__DOT__meta_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_2__DOT__meta_1__DOT__meta_0_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_2__DOT__meta_1__DOT__meta_0_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_2__DOT__meta_1__DOT__meta_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_2__DOT__meta_1__DOT__meta_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_2__DOT__meta_1__DOT__meta_0_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_2__DOT__meta_1__DOT__meta_0_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8521(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8521\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__atomics__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__atomics__DOT__monitor__DOT__d_first_counter_1;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8523(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8523\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__out_back__DOT__ram_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8563(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8563\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__queue__DOT__ram_data_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8564(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8564\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_1__DOT__num_contentReg 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_1__DOT__num_contentReg;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_0__DOT__num_contentReg 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_0__DOT__num_contentReg;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__state_reg_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__state_reg_1;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8569(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8569\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rcq_rs2__DOT__deq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rcq_rs2__DOT__deq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rcq_rs1__DOT__deq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rcq_rs1__DOT__deq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rcq_rs2__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rcq_rs2__DOT__enq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rcq_rs1__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rcq_rs1__DOT__enq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor__DOT__d_first_counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8570(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8570\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__meta_hazard 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__meta_hazard;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_3__DOT__meta_hazard 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_3__DOT__meta_hazard;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_2__DOT__meta_hazard 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_2__DOT__meta_hazard;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__meta_hazard 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__meta_hazard;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__monitor__DOT__c_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__monitor__DOT__c_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__c_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__c_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__monitor__DOT__c_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__monitor__DOT__c_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__c_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__c_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_1__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_1__DOT__d_first_counter_2;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8571(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8571\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_1__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_1__DOT__d_first_counter_2;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__meta_0__DOT__tag_array__DOT__tag_array_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__meta_0__DOT__tag_array__DOT__tag_array_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__meta_0__DOT__tag_array__DOT__tag_array_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__meta_0__DOT__tag_array__DOT__tag_array_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__meta_0__DOT__tag_array__DOT__tag_array_ext__DOT__mem_0_4__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__meta_0__DOT__tag_array__DOT__tag_array_ext__DOT__mem_0_5__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__meta_0__DOT__tag_array__DOT__tag_array_ext__DOT__mem_0_6__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__meta_0__DOT__tag_array__DOT__tag_array_ext__DOT__mem_0_7__DOT__ram__v0 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_1__DOT__d_first_counter_3 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_1__DOT__d_first_counter_3;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_1__DOT__d_first_counter_3 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_1__DOT__d_first_counter_3;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_5__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_5__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_4__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_4__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_3__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_3__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_5__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_5__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_4__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_4__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_3__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_3__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_2__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_2__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_5__DOT__d_first_counter_3 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_5__DOT__d_first_counter_3;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_4__DOT__d_first_counter_3 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_4__DOT__d_first_counter_3;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_3__DOT__d_first_counter_3 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_3__DOT__d_first_counter_3;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__d_first_counter_3 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__d_first_counter_3;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_5__DOT__d_first_counter_3 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_5__DOT__d_first_counter_3;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_4__DOT__d_first_counter_3 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_4__DOT__d_first_counter_3;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_3__DOT__d_first_counter_3 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_3__DOT__d_first_counter_3;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8572(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8572\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_2__DOT__d_first_counter_3 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_2__DOT__d_first_counter_3;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_1__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_1__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_1__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_1__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_1__DOT__c_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_1__DOT__c_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_1__DOT__c_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_1__DOT__c_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_5__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_5__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_4__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_4__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_3__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_3__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_5__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_5__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_4__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_4__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_3__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_3__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_2__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_2__DOT__d_first_counter_1;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8574(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8574\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_1__DOT__c_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_1__DOT__c_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_1__DOT__c_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_1__DOT__c_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_1__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_1__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_1__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_1__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__c_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__c_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__c_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__c_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_5__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_5__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_4__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_4__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_3__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_3__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_5__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_5__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_4__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_4__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_3__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_3__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_2__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_2__DOT__d_first_counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8575(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8575\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_5__DOT__c_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_5__DOT__c_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_4__DOT__c_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_4__DOT__c_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_3__DOT__c_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_3__DOT__c_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__c_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__c_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_5__DOT__c_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_5__DOT__c_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_4__DOT__c_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_4__DOT__c_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_3__DOT__c_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_3__DOT__c_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_2__DOT__c_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_2__DOT__c_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_83 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_83;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_80 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_80;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_79 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_79;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_78 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_78;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_77 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_77;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_75 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_75;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_74 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_74;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_73 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_73;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_70 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_70;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_67 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_67;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_65 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_65;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_63 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_63;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_62 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_62;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_61 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_61;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_59 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_59;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_58 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_58;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_57 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_57;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_55 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_55;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_54 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_54;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_53 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_53;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_51 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_51;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_49 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_49;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_47 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_47;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8576(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8576\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_46 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_46;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_44 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_44;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_42 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_42;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_40 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_40;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_38 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_38;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_36 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_36;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_34 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_34;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_32 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_32;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_30 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_30;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_28 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_28;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_24 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_24;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_22 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_22;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_20 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_20;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_18 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_18;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_45 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_45;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_41 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_41;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_29 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_29;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_37 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_37;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_25 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_25;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_33 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_33;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_82 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_82;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_81 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_81;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_21 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_21;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_48 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_48;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_52 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_52;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_56 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_56;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_60 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_60;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_64 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_64;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_68 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_68;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_72 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_72;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_76 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_76;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_19 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_19;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_23 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_23;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_27 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_27;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8577(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8577\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_31 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_31;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_35 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_35;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_39 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_39;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_43 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_43;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_50 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_50;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_66 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_66;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_71 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_71;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_5__DOT__c_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_5__DOT__c_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_4__DOT__c_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_4__DOT__c_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_3__DOT__c_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_3__DOT__c_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__c_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__c_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_5__DOT__c_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_5__DOT__c_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_4__DOT__c_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_4__DOT__c_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_3__DOT__c_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_3__DOT__c_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_2__DOT__c_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_2__DOT__c_first_counter_1;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__monitor__DOT__a_first_counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8578(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8578\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeat_count_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeat_count_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__atomics__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__atomics__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT__enq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__deq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__deq_ptr_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8584(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8584\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__beatsLeft_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__beatsLeft_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater_1__DOT__full 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater_1__DOT__full;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8585(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8585\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__monitor__DOT__a_first_counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8586(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8586\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8588(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8588\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__enq_ptr_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8589(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8589\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__bundleIn_0_b_q__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__bundleIn_0_b_q__DOT__enq_ptr_value;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_0__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8590(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8590\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT__deq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT__deq_ptr_value;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_2__DOT__meta_0__DOT__meta_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_2__DOT__meta_0__DOT__meta_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_2__DOT__meta_0__DOT__meta_0_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_2__DOT__meta_0__DOT__meta_0_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_2__DOT__meta_0__DOT__meta_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_2__DOT__meta_0__DOT__meta_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_2__DOT__meta_0__DOT__meta_0_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_2__DOT__meta_0__DOT__meta_0_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__acknum 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_bootrom__DOT__fragmenter__DOT__acknum;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__deq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__deq_ptr_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8591(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8591\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT__deq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4_btb_corrections__DOT__deq_ptr_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8626(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8626\n"); );
    // Init
    VlWide<130>/*4159:0*/ __Vtemp_h2dd246c8__0;
    VlWide<130>/*4159:0*/ __Vtemp_h287d30ea__0;
    VlWide<130>/*4159:0*/ __Vtemp_h2dd246c8__1;
    VlWide<130>/*4159:0*/ __Vtemp_hb9e75b32__0;
    VlWide<130>/*4159:0*/ __Vtemp_h2dd246c8__2;
    VlWide<130>/*4159:0*/ __Vtemp_h6268330d__0;
    VlWide<130>/*4159:0*/ __Vtemp_h2dd246c8__3;
    VlWide<130>/*4159:0*/ __Vtemp_h03072757__0;
    // Body
    VL_EXTEND_WI(4158,11, __Vtemp_h2dd246c8__0, (0x7ffU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 8U)));
    VL_CONCAT_WWI(4160,4158,2, __Vtemp_h287d30ea__0, __Vtemp_h2dd246c8__0, 0U);
    VL_EXTEND_WI(4158,11, __Vtemp_h2dd246c8__1, (0x7ffU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 8U)));
    VL_CONCAT_WWI(4160,4158,2, __Vtemp_hb9e75b32__0, __Vtemp_h2dd246c8__1, 0U);
    VL_EXTEND_WI(4158,11, __Vtemp_h2dd246c8__2, (0x7ffU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 8U)));
    VL_CONCAT_WWI(4160,4158,2, __Vtemp_h6268330d__0, __Vtemp_h2dd246c8__2, 0U);
    VL_EXTEND_WI(4158,11, __Vtemp_h2dd246c8__3, (0x7ffU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 8U)));
    VL_CONCAT_WWI(4160,4158,2, __Vtemp_h03072757__0, __Vtemp_h2dd246c8__3, 0U);
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8627(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8627\n"); );
    // Init
    VlWide<130>/*4159:0*/ __Vtemp_h2dd246c8__0;
    VlWide<130>/*4159:0*/ __Vtemp_h287d30ea__0;
    // Body
    VL_EXTEND_WI(4158,11, __Vtemp_h2dd246c8__0, (0x7ffU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 8U)));
    VL_CONCAT_WWI(4160,4158,2, __Vtemp_h287d30ea__0, __Vtemp_h2dd246c8__0, 0U);
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8658(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8658\n"); );
    // Init
    VlWide<130>/*4159:0*/ __Vtemp_hc8ab27da__0;
    VlWide<130>/*4159:0*/ __Vtemp_hbe776029__0;
    VlWide<130>/*4159:0*/ __Vtemp_hc8ab27da__1;
    VlWide<130>/*4159:0*/ __Vtemp_h2129fad8__0;
    VlWide<130>/*4159:0*/ __Vtemp_hc8ab27da__2;
    VlWide<130>/*4159:0*/ __Vtemp_hec2fb6f5__0;
    VlWide<130>/*4159:0*/ __Vtemp_hc8ab27da__3;
    VlWide<130>/*4159:0*/ __Vtemp_ha0e90c3c__0;
    // Body
    VL_EXTEND_WI(4158,11, __Vtemp_hc8ab27da__0, (0x7ffU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 8U)));
    VL_CONCAT_WWI(4160,4158,2, __Vtemp_hbe776029__0, __Vtemp_hc8ab27da__0, 0U);
    VL_EXTEND_WI(4158,11, __Vtemp_hc8ab27da__1, (0x7ffU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 8U)));
    VL_CONCAT_WWI(4160,4158,2, __Vtemp_h2129fad8__0, __Vtemp_hc8ab27da__1, 0U);
    VL_EXTEND_WI(4158,11, __Vtemp_hc8ab27da__2, (0x7ffU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 8U)));
    VL_CONCAT_WWI(4160,4158,2, __Vtemp_hec2fb6f5__0, __Vtemp_hc8ab27da__2, 0U);
    VL_EXTEND_WI(4158,11, __Vtemp_hc8ab27da__3, (0x7ffU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 8U)));
    VL_CONCAT_WWI(4160,4158,2, __Vtemp_ha0e90c3c__0, __Vtemp_hc8ab27da__3, 0U);
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8659(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8659\n"); );
    // Init
    VlWide<130>/*4159:0*/ __Vtemp_hc8ab27da__0;
    VlWide<130>/*4159:0*/ __Vtemp_hbe776029__0;
    // Body
    VL_EXTEND_WI(4158,11, __Vtemp_hc8ab27da__0, (0x7ffU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 8U)));
    VL_CONCAT_WWI(4160,4158,2, __Vtemp_hbe776029__0, __Vtemp_hc8ab27da__0, 0U);
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8661(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8661\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s1_tsrc 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s1_tsrc;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8667(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8667\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__serdesser__DOT__monitor__DOT__d_first_counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8668(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8668\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_69 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_69;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_26 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_26;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_16 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_16;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_14 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_14;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_12 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_12;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_10 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_10;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_8 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_8;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_6 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_6;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_4 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_4;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_13 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_13;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_11 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_11;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_7 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_7;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_3 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_3;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_9 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_9;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_5 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_5;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_17 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_17;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8669(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8669\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_15 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_15;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_coupler_from_port_named_serial_tl_ctrl__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__iregfile__DOT__regfile_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__iregfile__DOT__regfile_ext__DOT__Memory__v1 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__iregfile__DOT__regfile_ext__DOT__Memory__v2 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__iregfile__DOT__regfile_ext__DOT__Memory__v3 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8672(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8672\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__a_first_counter_1;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8673(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8673\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__ghist_1__DOT__ghist_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__resp_ae_ptw 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__resp_ae_ptw;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8684(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8684\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rsu_master__DOT__merge_cdc_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rsu_master__DOT__merge_cdc_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__beatsLeft 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__beatsLeft;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8685(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8685\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rsu_master__DOT__merge_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rsu_master__DOT__merge_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rsu_master__DOT__merging 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rsu_master__DOT__merging;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8686(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8686\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT__full 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT__full;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT__full 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT__full;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT__full 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT__full;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8687(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8687\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rsu_master__DOT__merge_cdc_counter_priv 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rsu_master__DOT__merge_cdc_counter_priv;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8688(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8688\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__state_reg 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__state_reg;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__meta_0__DOT__rst_cnt 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__meta_0__DOT__rst_cnt;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8689(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8689\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rsu_master__DOT__csr_merge_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rsu_master__DOT__csr_merge_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rsu_master__DOT__merge_counter_priv 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rsu_master__DOT__merge_counter_priv;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rsu_master__DOT__merging_priv 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rsu_master__DOT__merging_priv;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8690(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8690\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__atomics__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__atomics__DOT__monitor__DOT__a_first_counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8691(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8691\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__atomics__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__atomics__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__iregister_read__DOT__exe_reg_rs2_data_3 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__iregister_read__DOT__exe_reg_rs2_data_3;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8697(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8697\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__a_first_counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8700(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8700\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__atomics__DOT__beatsLeft 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__atomics__DOT__beatsLeft;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8708(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8708\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__count 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__count;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8714(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8714\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_1;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8716(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8716\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor__DOT__a_first_counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8717(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8717\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__fixer__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__fixer__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__a_first_counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8719(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8719\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__x1_a_q__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__x1_a_q__DOT__enq_ptr_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8720(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8720\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__queue_arw_deq__DOT__ram_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8721(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8721\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeat_count 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeat_count;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__atomics__DOT__cam_s_0_state 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__atomics__DOT__cam_s_0_state;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_4__DOT__wrbypass_enq_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_4__DOT__wrbypass_enq_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_4__DOT__wrbypass_enq_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_4__DOT__wrbypass_enq_idx;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8724(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8724\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way_prng__DOT__state_14 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way_prng__DOT__state_14;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way_prng__DOT__state_13 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way_prng__DOT__state_13;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way_prng__DOT__state_11 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way_prng__DOT__state_11;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way_prng__DOT__state_0 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__repl_way_prng__DOT__state_0;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s1_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s1_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__alloc_lfsr_prng_3__DOT__state_5 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__alloc_lfsr_prng_3__DOT__state_5;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__alloc_lfsr_prng_2__DOT__state_5 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__alloc_lfsr_prng_2__DOT__state_5;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__alloc_lfsr_prng_1__DOT__state_5 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__alloc_lfsr_prng_1__DOT__state_5;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__alloc_lfsr_prng__DOT__state_5 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__alloc_lfsr_prng__DOT__state_5;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__alloc_lfsr_prng_3__DOT__state_5 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__alloc_lfsr_prng_3__DOT__state_5;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__alloc_lfsr_prng_2__DOT__state_5 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__alloc_lfsr_prng_2__DOT__state_5;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__alloc_lfsr_prng_1__DOT__state_5 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__alloc_lfsr_prng_1__DOT__state_5;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__alloc_lfsr_prng__DOT__state_5 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__alloc_lfsr_prng__DOT__state_5;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeat_count 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeat_count;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8732(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8732\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__store_blocked_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__store_blocked_counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8740(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8740\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__x1_a_q__DOT__deq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__x1_a_q__DOT__deq_ptr_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8741(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8741\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__bundleIn_0_b_q__DOT__deq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__bundleIn_0_b_q__DOT__deq_ptr_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8744(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8744\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__alloc_lfsr_prng_3__DOT__state_4 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__alloc_lfsr_prng_3__DOT__state_4;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__alloc_lfsr_prng_2__DOT__state_4 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__alloc_lfsr_prng_2__DOT__state_4;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8745(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8745\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__alloc_lfsr_prng_1__DOT__state_4 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__alloc_lfsr_prng_1__DOT__state_4;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__alloc_lfsr_prng__DOT__state_4 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__alloc_lfsr_prng__DOT__state_4;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__alloc_lfsr_prng_3__DOT__state_4 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__alloc_lfsr_prng_3__DOT__state_4;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__alloc_lfsr_prng_2__DOT__state_4 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__alloc_lfsr_prng_2__DOT__state_4;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__alloc_lfsr_prng_1__DOT__state_4 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__alloc_lfsr_prng_1__DOT__state_4;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__alloc_lfsr_prng__DOT__state_4 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__alloc_lfsr_prng__DOT__state_4;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__fixer__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__fixer__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__subsystem_mbus_xbar__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__binder__DOT__monitor__DOT__d_first_counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8746(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8746\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__bundleIn_0_b_q__DOT__ram_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8747(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8747\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mpie 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mpie;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8748(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8748\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_0 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_counter_0;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_1__DOT__writePtr 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_1__DOT__writePtr;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_0__DOT__writePtr 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_0__DOT__writePtr;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_1__DOT__fullReg 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_1__DOT__fullReg;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_0__DOT__fullReg 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_0__DOT__fullReg;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_2__DOT__writePtr 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_2__DOT__writePtr;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_2__DOT__fullReg 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_2__DOT__fullReg;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater__DOT__full 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__repeated_repeater__DOT__full;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8749(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8749\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_1__DOT__readPtr 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_1__DOT__readPtr;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_0__DOT__readPtr 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_0__DOT__readPtr;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_2__DOT__readPtr 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_2__DOT__readPtr;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8750(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8750\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__enq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8751(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8751\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeated_repeater__DOT__full 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__repeated_repeater__DOT__full;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8752(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8752\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8755(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8755\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__picker__DOT__monitor_1__DOT__d_first_counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8758(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8758\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mie 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mie;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_1__DOT__emptyReg 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_1__DOT__emptyReg;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_0__DOT__emptyReg 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_0__DOT__emptyReg;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_2__DOT__emptyReg 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_2__DOT__emptyReg;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fdivsqrt__DOT__divsqrt__DOT__ds__DOT__divSqrtRecF64ToRaw__DOT__cycleNum_A 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fdivsqrt__DOT__divsqrt__DOT__ds__DOT__divSqrtRecF64ToRaw__DOT__cycleNum_A;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8762(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8762\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__acknum 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__acknum;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8764(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8764\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_e_q__DOT__ram_sink_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__acknum 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__acknum;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8767(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8767\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__c_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__c_first_counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8770(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8770\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__axi4yank__DOT__Queue_19__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__axi4yank__DOT__Queue_18__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__axi4yank__DOT__Queue_17__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__axi4yank__DOT__Queue_16__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__axi4yank__DOT__Queue_15__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__axi4yank__DOT__Queue_14__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__axi4yank__DOT__Queue_13__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__axi4yank__DOT__Queue_12__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__axi4yank__DOT__Queue_11__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__axi4yank__DOT__Queue_10__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__axi4yank__DOT__Queue_9__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__axi4yank__DOT__Queue_8__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__axi4yank__DOT__Queue_7__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__axi4yank__DOT__Queue_6__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__axi4yank__DOT__Queue_5__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__axi4yank__DOT__Queue_4__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__axi4yank__DOT__Queue_3__DOT__ram_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8771(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8771\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__axi4yank__DOT__Queue_2__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__axi4yank__DOT__Queue_1__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__axi4yank__DOT__Queue__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__enq_ptr_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8772(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8772\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[0U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[0U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[1U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[1U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[2U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[2U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[3U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[3U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[4U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[4U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[5U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[5U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[6U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[6U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[7U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[7U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[8U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[8U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[9U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[9U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[0xaU] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[0xaU];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[0xbU] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[0xbU];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[0xcU] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[0xcU];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[0xdU] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[0xdU];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[0xeU] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[0xeU];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[0xfU] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__vb_array[0xfU];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__invalidated 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__invalidated;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_4__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_5__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_6__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__tag_array__DOT__tag_array_0_ext__DOT__mem_0_7__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q__DOT__ram_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8773(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8773\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__refill_valid 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__refill_valid;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__cork__DOT__q_1__DOT__ram_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8777(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8777\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__beatsLeft 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__beatsLeft;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__beatsLeft 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__beatsLeft;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8778(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8778\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_5__DOT__wrbypass_enq_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_5__DOT__wrbypass_enq_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_4__DOT__wrbypass_enq_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_4__DOT__wrbypass_enq_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_3__DOT__wrbypass_enq_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_3__DOT__wrbypass_enq_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_2__DOT__wrbypass_enq_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_2__DOT__wrbypass_enq_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_1__DOT__wrbypass_enq_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_1__DOT__wrbypass_enq_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_0__DOT__wrbypass_enq_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_0__DOT__wrbypass_enq_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_5__DOT__wrbypass_enq_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_5__DOT__wrbypass_enq_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_4__DOT__wrbypass_enq_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_4__DOT__wrbypass_enq_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_3__DOT__wrbypass_enq_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_3__DOT__wrbypass_enq_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_2__DOT__wrbypass_enq_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_2__DOT__wrbypass_enq_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_1__DOT__wrbypass_enq_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_1__DOT__wrbypass_enq_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_0__DOT__wrbypass_enq_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_0__DOT__wrbypass_enq_idx;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8783(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8783\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__beatsLeft_3 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__beatsLeft_3;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8784(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8784\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_ppc 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_ppc;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_0 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_0;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_30 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_30;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_29 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_29;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_28 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_28;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_27 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_27;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_26 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_26;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8785(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8785\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_25 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_25;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_24 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_24;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_23 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_23;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_22 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_22;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_21 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_21;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_20 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_20;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_19 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_19;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_18 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_18;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_17 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_17;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_16 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_16;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_15 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_15;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_14 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_14;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_13 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_13;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_12 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_12;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_11 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_11;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_10 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_10;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_9 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_9;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_8 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_8;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_7 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_7;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_6 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_6;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_5 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_5;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_4 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_4;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_3 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_3;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__large_2;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8786(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8786\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_e_q__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_e_q__DOT__enq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_e_q__DOT__deq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_e_q__DOT__deq_ptr_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8787(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8787\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__cc_dir__DOT__cc_dir_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__cc_dir__DOT__cc_dir_ext__DOT__mem_0_1__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__cc_dir__DOT__cc_dir_ext__DOT__mem_0_2__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__cc_dir__DOT__cc_dir_ext__DOT__mem_0_3__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__cc_dir__DOT__cc_dir_ext__DOT__mem_0_4__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__cc_dir__DOT__cc_dir_ext__DOT__mem_0_5__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__cc_dir__DOT__cc_dir_ext__DOT__mem_0_6__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__cc_dir__DOT__cc_dir_ext__DOT__mem_0_7__DOT__ram__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8788(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8788\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_tlb_resp_ae_inst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_tlb_resp_ae_inst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_tlb_resp_pf_inst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s2_tlb_resp_pf_inst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s1_ghist_new_saw_branch_taken 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s1_ghist_new_saw_branch_taken;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__a_first_counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8796(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8796\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__write__DOT__ram_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8800(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8800\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s1_ghist_old_history 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s1_ghist_old_history;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkD__DOT__d__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkD__DOT__d__DOT__enq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT__enq_ptr_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8802(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8802\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_c_q__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s1_ghist_new_saw_branch_not_taken 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s1_ghist_new_saw_branch_not_taken;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8809(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8809\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mprv 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mprv;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8811(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8811\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txq__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__bootAddrReg 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__bootAddrReg;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8812(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8812\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxm__DOT__sample 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxm__DOT__sample;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxm__DOT__debounce 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxm__DOT__debounce;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxm__DOT__state 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxm__DOT__state;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__victimLFSR_prng__DOT__state_0 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__victimLFSR_prng__DOT__state_0;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8813(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8813\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__victimLFSR_prng__DOT__state_14 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__victimLFSR_prng__DOT__state_14;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__victimLFSR_prng__DOT__state_11 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__victimLFSR_prng__DOT__state_11;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__d_first_counter_2;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8814(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8814\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor_1__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__d_first_counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8824(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8824\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8827(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8827\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8828(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8828\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__d_first_counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8830(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8830\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txm__DOT__prescaler 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txm__DOT__prescaler;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txm__DOT__counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txm__DOT__counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxm__DOT__prescaler 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__rxm__DOT__prescaler;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__respArb_io_in_0_q__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__respArb_io_in_0_q__DOT__enq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__respArb_io_in_0_q__DOT__deq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__respArb_io_in_0_q__DOT__deq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rcq__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rcq__DOT__enq_ptr_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8886(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8886\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rcq__DOT__ram_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8887(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8887\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_s_0_state 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__cam_s_0_state;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8888(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8888\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_c_q__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_c_q__DOT__enq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_c_q__DOT__deq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_c_q__DOT__deq_ptr_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8889(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8889\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_dcsr_prv 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_dcsr_prv;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8890(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8890\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rcq__DOT__deq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rcq__DOT__deq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__gateways_gateway__DOT__inFlight 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__gateways_gateway__DOT__inFlight;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tsi_domain__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mpp 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_mstatus_mpp;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_debug 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_debug;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__lb_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8891(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8891\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT__deq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT__deq_ptr_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8892(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8892\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_mstatus_prv 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_mstatus_prv;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_2__DOT__num_contentReg 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf__DOT__u_buffer_2__DOT__num_contentReg;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__beatsLeft 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__beatsLeft;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8893(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8893\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__deq__DOT__maybe_full 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_mbus__DOT__coupler_to_memory_controller_port_named_axi4__DOT__tl2axi4__DOT__deq__DOT__maybe_full;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT__head_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT__head_ext__DOT__Memory__v1 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8894(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8894\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__request_valid 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__request_valid;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__request_valid 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__request_valid;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__request_valid 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__request_valid;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__request_valid 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__request_valid;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_valid 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_valid;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8915(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8915\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8916(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8916\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__acknum 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__acknum;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8917(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8917\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__acknum 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__acknum;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkD__DOT__d__DOT__ram_ext__DOT__Memory__v0 = 0U;
    if (VL_UNLIKELY(((
                    // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/UARTTx.sv:120:13
verbose&&done_reset
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txm__DOT___io_in_ready_output) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txq__DOT__empty)))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset))))) {
        VL_FWRITEF(0x80000002U,"UART TX (%x): %c\n",
                   8,vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txq__DOT__ram_ext__DOT__Memory
                   [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txq__DOT__deq_ptr_value],
                   8,vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txq__DOT__ram_ext__DOT__Memory
                   [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__uartClockDomainWrapper__DOT__uart_0__DOT__txq__DOT__deq_ptr_value]);
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__8947(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__8947\n"); );
    // Init
    VlWide<130>/*4159:0*/ __Vtemp_h697d0e6f__0;
    VlWide<130>/*4159:0*/ __Vtemp_h5865b9bf__0;
    VlWide<130>/*4159:0*/ __Vtemp_h697d0e6f__1;
    VlWide<130>/*4159:0*/ __Vtemp_h3d261864__0;
    VlWide<130>/*4159:0*/ __Vtemp_h697d0e6f__2;
    VlWide<130>/*4159:0*/ __Vtemp_h25053848__0;
    VlWide<130>/*4159:0*/ __Vtemp_h697d0e6f__3;
    VlWide<130>/*4159:0*/ __Vtemp_hd6281c9d__0;
    // Body
    VL_EXTEND_WI(4158,11, __Vtemp_h697d0e6f__0, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_pbus_auto_coupler_to_device_named_uart_0_control_xing_out_a_bits_source));
    VL_CONCAT_WWI(4160,4158,2, __Vtemp_h5865b9bf__0, __Vtemp_h697d0e6f__0, 0U);
    VL_EXTEND_WI(4158,11, __Vtemp_h697d0e6f__1, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_pbus_auto_coupler_to_device_named_uart_0_control_xing_out_a_bits_source));
    VL_CONCAT_WWI(4160,4158,2, __Vtemp_h3d261864__0, __Vtemp_h697d0e6f__1, 0U);
    VL_EXTEND_WI(4158,11, __Vtemp_h697d0e6f__2, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_pbus_auto_coupler_to_device_named_uart_0_control_xing_out_a_bits_source));
    VL_CONCAT_WWI(4160,4158,2, __Vtemp_h25053848__0, __Vtemp_h697d0e6f__2, 0U);
    VL_EXTEND_WI(4158,11, __Vtemp_h697d0e6f__3, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_pbus_auto_coupler_to_device_named_uart_0_control_xing_out_a_bits_source));
    VL_CONCAT_WWI(4160,4158,2, __Vtemp_hd6281c9d__0, __Vtemp_h697d0e6f__3, 0U);
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9060(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9060\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__exception_mode_test 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__exception_mode_test;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__maybe_full 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__maybe_full;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_back__DOT__maybe_full 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_back__DOT__maybe_full;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__acknum 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__acknum;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__acknum 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__acknum;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9062(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9062\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__requests__DOT__data_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9063(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9063\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__enq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__deq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__deq_ptr_value;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__acknum 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__acknum;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__acknum 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__acknum;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9065(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9065\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkA__DOT__putbuffer__DOT__data_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9073(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9073\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkX__DOT__x__DOT__ram_address_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9078(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9078\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__enq_ptr_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9079(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9079\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkX__DOT__x__DOT__maybe_full 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkX__DOT__x__DOT__maybe_full;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9080(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9080\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_edge_inst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_23_edge_inst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_edge_inst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_22_edge_inst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_edge_inst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_21_edge_inst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_edge_inst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_20_edge_inst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_edge_inst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_19_edge_inst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_edge_inst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_18_edge_inst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_edge_inst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_17_edge_inst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_edge_inst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_16_edge_inst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_edge_inst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_15_edge_inst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_edge_inst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_14_edge_inst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_edge_inst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_5_edge_inst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_edge_inst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_4_edge_inst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_edge_inst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_13_edge_inst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_edge_inst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_3_edge_inst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_edge_inst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_10_edge_inst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_edge_inst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_2_edge_inst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_edge_inst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_11_edge_inst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_edge_inst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_0_edge_inst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_edge_inst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_1_edge_inst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_edge_inst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_12_edge_inst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_edge_inst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_6_edge_inst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_edge_inst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_7_edge_inst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_edge_inst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_8_edge_inst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_edge_inst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__fb_uop_ram_9_edge_inst;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9081(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9081\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__meta__DOT__meta_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9085(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9085\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__wb__DOT__acked 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__wb__DOT__acked;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__wb__DOT__r1_data_req_cnt 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__wb__DOT__r1_data_req_cnt;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__wb__DOT__data_req_cnt 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__wb__DOT__data_req_cnt;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__maybe_full 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__maybe_full;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9089(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9089\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT__deq_ptr_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9091(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9091\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_count 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_count;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__stage2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__stage2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__state 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__state;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__count 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__count;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__l2_tlb_ram_0__DOT__l2_tlb_ram_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9092(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9092\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_custom_0 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_custom_0;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__pnr_maybe_at_tail 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__pnr_maybe_at_tail;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9093(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9093\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_3__DOT__counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_3__DOT__counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_2__DOT__counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_2__DOT__counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_1__DOT__counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9094(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9094\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__monitor__DOT__d_first_counter_3 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__monitor__DOT__d_first_counter_3;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__d_first_counter_3 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__d_first_counter_3;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_first_counter_3 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_first_counter_3;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__monitor__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__monitor__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__monitor__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget_1__DOT__monitor__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__icache__DOT__counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_first_counter_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_first_counter_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__tlMasterXbar__DOT__monitor_1__DOT__d_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshrs_0__DOT__counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__wb__DOT__req_voluntary 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__wb__DOT__req_voluntary;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__count 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__widget__DOT__count;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9343(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9343\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_2__DOT__reset_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_2__DOT__reset_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_2__DOT__reset_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_2__DOT__reset_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_2__DOT__doing_reset 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_2__DOT__doing_reset;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_2__DOT__doing_reset 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_2__DOT__doing_reset;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__head 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__head;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__sdq_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__state_reg 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__state_reg;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rxq_head 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rxq_head;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__ram_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9347(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9347\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__large_0 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__large_0;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9348(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9348\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__io_status_cease_r 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__io_status_cease_r;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_wfi 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_wfi;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9349(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9349\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__maybe_full 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f4__DOT__maybe_full;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9362(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9362\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__putbuffer__DOT__data_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9363(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9363\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bankedStore__DOT__cc_banks_0__DOT__cc_banks_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bankedStore__DOT__cc_banks_1__DOT__cc_banks_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bankedStore__DOT__cc_banks_2__DOT__cc_banks_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bankedStore__DOT__cc_banks_3__DOT__cc_banks_0_ext__DOT__mem_0_0__DOT__ram__v0 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__meta_state 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__meta_state;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__meta_state 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__meta_state;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__meta_state 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__meta_state;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_state 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_state;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_state 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_state;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__meta_state 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__meta_state;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__meta_state 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__meta_state;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__meta_hit 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__meta_hit;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__meta_hit 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__meta_hit;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__meta_hit 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__meta_hit;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_hit 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_hit;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__meta_hit 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__meta_hit;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__meta_hit 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__meta_hit;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__meta_dirty 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__meta_dirty;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9364(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9364\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__meta_dirty 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__meta_dirty;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__meta_dirty 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__meta_dirty;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_dirty 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_dirty;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__meta_dirty 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__meta_dirty;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__meta_dirty 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__meta_dirty;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__repeater__DOT__full 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__repeater__DOT__full;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__hella_state 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__hella_state;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__state_reg_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__state_reg_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_0_valid_0 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_0_valid_0;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_2_valid_0 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_2_valid_0;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9365(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9365\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_1_valid_0 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_1_valid_0;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_3_valid_0 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_3_valid_0;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_0 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_0;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_3 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_3;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_4 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__timecmp_4;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__out_xbar__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__fixer__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9366(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9366\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__clint__DOT__time_0;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9367(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9367\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__plicDomainWrapper__DOT__plic__DOT__out_back__DOT__ram_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9376(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9376\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__enq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT__enq_ptr_value;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__respArb_io_in_0_q__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__respq__DOT__ram_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9377(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9377\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_fflags_2_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_fflags_2_ext__DOT__Memory__v1 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_fflags_2_ext__DOT__Memory__v2 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_fflags_1_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_fflags_1_ext__DOT__Memory__v1 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_fflags_1_ext__DOT__Memory__v2 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__debug_gtimer 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__debug_gtimer;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT__debug_perf_BCounter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT__debug_perf_BCounter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT__debug_perf_SchState_Allbusy 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT__debug_perf_SchState_Allbusy;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_fflags_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_fflags_ext__DOT__Memory__v1 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_fflags_ext__DOT__Memory__v2 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT__debug_perf_SchState 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT__debug_perf_SchState;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT__debug_perf_SchState_OT 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT__debug_perf_SchState_OT;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT__debug_perf_OtherThread 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT__debug_perf_OtherThread;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_4__DOT__reset_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_4__DOT__reset_idx;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9378(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9378\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_4__DOT__reset_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_4__DOT__reset_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT__end_0 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT__end_0;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT__ic_exit_isax_buffer 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT__ic_exit_isax_buffer;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT__debug_perf_CheckState 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT__debug_perf_CheckState;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT__ctrl 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT__ctrl;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT__fsm_state 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__ic_master__DOT__fsm_state;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fdivsqrt__DOT__r_divsqrt_uop_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fdivsqrt__DOT__r_divsqrt_uop_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fdivsqrt__DOT__r_buffer_req_uop_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fdivsqrt__DOT__r_buffer_req_uop_br_mask;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9420(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9420\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__state 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__state;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9421(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9421\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_4__DOT__doing_reset 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_4__DOT__doing_reset;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_4__DOT__doing_reset 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_4__DOT__doing_reset;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__large_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__large_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__large_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__large_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__large_4 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__large_4;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__large_3 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__large_3;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_30_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_30_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_29_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_29_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_28_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_28_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_27_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_27_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_25_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_25_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_24_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_24_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_23_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_23_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_22_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_22_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_15_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_15_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_10_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_10_br_mask;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9422(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9422\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_9_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_9_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_8_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_8_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_7_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_7_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_5_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_5_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_4_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_4_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_3_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_3_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_20_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_20_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_19_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_19_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_18_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_18_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_17_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_17_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_14_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_14_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_2_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_2_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_13_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_13_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_12_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_12_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_0_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_0_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_26_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_26_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_16_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_16_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_11_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_11_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_6_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_6_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_1_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_1_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_21_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_21_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_30_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_30_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_29_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_29_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_27_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_27_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_24_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_24_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_23_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_23_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_22_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_22_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_28_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_28_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_25_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_25_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_21_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_21_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_20_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_20_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_19_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_19_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_18_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_18_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_17_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_17_br_mask;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9423(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9423\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_16_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_16_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_15_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_15_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_9_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_9_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_8_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_8_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_7_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_7_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_5_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_5_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_4_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_4_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_3_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_3_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_12_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_12_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_26_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_26_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_6_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_6_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_10_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_10_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_11_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_11_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_13_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_13_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_14_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_14_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_0_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_0_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_1_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_1_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_2_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_2_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_28_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_28_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_27_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_27_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_26_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_26_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_25_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_25_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_24_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_24_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_23_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_23_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_22_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_22_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_21_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_21_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_20_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_20_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_19_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_19_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_18_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_18_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_17_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_17_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_16_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_16_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_15_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_15_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_14_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_14_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_11_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_11_br_mask;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9863(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9863\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_14_bits_uop_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_14_bits_uop_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_13_bits_uop_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_13_bits_uop_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_12_bits_uop_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_12_bits_uop_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_11_bits_uop_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_11_bits_uop_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_10_bits_uop_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_10_bits_uop_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_9_bits_uop_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_9_bits_uop_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_8_bits_uop_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_8_bits_uop_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_7_bits_uop_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_7_bits_uop_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_6_bits_uop_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_6_bits_uop_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_5_bits_uop_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_5_bits_uop_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_4_bits_uop_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_4_bits_uop_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_3_bits_uop_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_3_bits_uop_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_2_bits_uop_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_2_bits_uop_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_1_bits_uop_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_1_bits_uop_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_0_bits_uop_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_0_bits_uop_br_mask;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9869(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9869\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[0U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[0U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[1U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[1U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[2U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[2U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[3U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[3U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[4U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[4U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[5U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[5U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[6U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[6U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[7U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[7U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[8U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[8U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[9U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[9U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[0xaU] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[0xaU];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[0xbU] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[0xbU];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[0xcU] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[0xcU];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[0xdU] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[0xdU];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[0xeU] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[0xeU];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[0xfU] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_0[0xfU];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[0U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[0U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[1U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[1U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[2U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[2U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[3U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[3U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[4U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[4U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[5U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[5U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[6U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[6U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[7U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[7U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[8U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[8U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[9U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[9U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[0xaU] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[0xaU];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[0xbU] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[0xbU];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[0xcU] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[0xcU];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[0xdU] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[0xdU];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[0xeU] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[0xeU];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[0xfU] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__REG_1_0[0xfU];
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9878(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9878\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__flushOutValid 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__flushOutValid;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__lfsr_prng__DOT__state_14 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__lfsr_prng__DOT__state_14;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__lfsr_prng__DOT__state_13 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__lfsr_prng__DOT__state_13;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__lfsr_prng__DOT__state_11 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__lfsr_prng__DOT__state_11;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__lfsr_prng__DOT__state_0 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__lfsr_prng__DOT__state_0;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__state_vec_0 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__state_vec_0;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9881(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9881\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__s_grantack 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__s_grantack;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__s_grantack 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__s_grantack;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__s_grantack 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__s_grantack;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__w_grantfirst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__w_grantfirst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__w_grantfirst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__w_grantfirst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__w_grantfirst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__w_grantfirst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__s_grantack 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__s_grantack;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__w_grantfirst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__w_grantfirst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__s_grantack 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__s_grantack;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__w_grantfirst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__w_grantfirst;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9882(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9882\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_grantack 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_grantack;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__w_grantfirst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__w_grantfirst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_grantack 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_grantack;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_grantfirst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_grantfirst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__fill 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__fill;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s1_req_reg_bad 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s1_req_reg_bad;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s1_req_reg_sink 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s1_req_reg_sink;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s1_req_reg_put 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s1_req_reg_put;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s1_req_reg_source 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s1_req_reg_source;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s1_req_reg_prio_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s1_req_reg_prio_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s1_req_reg_size 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s1_req_reg_size;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s1_req_reg_prio_0 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s1_req_reg_prio_0;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s1_req_reg_param 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s1_req_reg_param;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9883(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9883\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s1_req_reg_opcode 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s1_req_reg_opcode;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s2_pdata_r_corrupt 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s2_pdata_r_corrupt;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s2_pdata_r_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s2_pdata_r_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s2_pdata_r_data 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s2_pdata_r_data;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s2_valid_pb 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s2_valid_pb;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s1_req_reg_way 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s1_req_reg_way;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s1_req_reg_set 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s1_req_reg_set;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__counter;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fp_sdq__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__ram_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9884(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9884\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__s_execute 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__s_execute;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__w_pprobeack 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__w_pprobeack;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__w_grant 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__w_grant;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__s_execute 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__s_execute;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__w_pprobeack 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__w_pprobeack;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__w_grant 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__w_grant;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__s_execute 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__s_execute;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__w_pprobeack 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__w_pprobeack;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__w_grant 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__w_grant;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__s_execute 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__s_execute;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__w_pprobeack 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__w_pprobeack;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__w_grant 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__w_grant;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__s_execute 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__s_execute;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__w_pprobeack 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__w_pprobeack;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__w_grant 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__w_grant;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9885(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9885\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__state_reg_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__state_reg_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_execute 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_execute;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__w_pprobeack 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__w_pprobeack;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__w_grant 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__w_grant;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_execute 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_execute;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_pprobeack 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_pprobeack;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_grant 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_grant;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__s_flush 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__s_flush;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__s_flush 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__s_flush;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9886(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9886\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__s_flush 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__s_flush;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__s_flush 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__s_flush;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__s_flush 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__s_flush;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__request_valid 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__request_valid;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_flush 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_flush;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_flush 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_flush;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__w_releaseack 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__w_releaseack;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__w_releaseack 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__w_releaseack;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__w_releaseack 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__w_releaseack;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__w_releaseack 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__w_releaseack;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__busy 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__busy;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__putbuffer__DOT__head_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__putbuffer__DOT__head_ext__DOT__Memory__v1 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkA__DOT__putbuffer__DOT__head_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkA__DOT__putbuffer__DOT__head_ext__DOT__Memory__v1 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__req_r_tag 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__req_r_tag;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__req_r_source 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__req_r_source;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__req_r_param 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__req_r_param;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__req_r_opcode 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__req_r_opcode;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s6_dat 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s6_dat;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s5_beat 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s5_beat;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s5_req_way 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s5_req_way;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s5_req_set 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s5_req_set;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s7_dat 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s7_dat;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s6_beat 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s6_beat;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9887(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9887\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s6_req_way 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s6_req_way;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s6_req_set 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s6_req_set;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__req_r_set 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__req_r_set;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s4_full 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s4_full;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceE__DOT__io_e_q__DOT__ram_sink_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__w_releaseack 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__w_releaseack;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__w_releaseack 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__w_releaseack;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_releaseack 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_releaseack;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__s_acquire 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__s_acquire;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__s_acquire 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__s_acquire;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__s_acquire 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__s_acquire;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__s_acquire 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__s_acquire;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__s_acquire 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__s_acquire;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_acquire 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_acquire;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_acquire 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_acquire;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__io_bs_adr_q__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__s_pprobe 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__s_pprobe;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__s_pprobe 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__s_pprobe;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__s_pprobe 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__s_pprobe;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__w_rprobeackfirst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__w_rprobeackfirst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__w_rprobeackfirst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__w_rprobeackfirst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__w_rprobeackfirst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__w_rprobeackfirst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__s_pprobe 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__s_pprobe;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__w_rprobeackfirst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__w_rprobeackfirst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__s_pprobe 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__s_pprobe;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9888(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9888\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__w_rprobeackfirst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__w_rprobeackfirst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_pprobe 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_pprobe;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__w_rprobeackfirst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__w_rprobeackfirst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_pprobe 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_pprobe;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_rprobeackfirst 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_rprobeackfirst;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__s_release 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__s_release;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__s_release 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__s_release;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__s_release 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__s_release;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__s_release 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__s_release;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__s_release 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__s_release;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_release 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_release;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_release 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_release;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9997(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9997\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__busy 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__busy;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__monitor__DOT__d_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__monitor__DOT__d_first_counter;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fp_sdq__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fp_sdq__DOT__enq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__enq_ptr_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__9999(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__9999\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceA__DOT__io_a_q__DOT__ram_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10002(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10002\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_1__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_1__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_1__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_1__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_1__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_1__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_1__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_1__DOT__a_first_counter_1;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10012(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10012\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_2__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_2__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_2__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_2__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_2__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_3__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_3__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_3__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_3__DOT__a_first_counter;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10013(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10013\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_3__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_3__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_3__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_3__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_4__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_4__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_4__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_4__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_4__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_4__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_4__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_4__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_5__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_5__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_5__DOT__a_first_counter 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_5__DOT__a_first_counter;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_5__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__fixer__DOT__monitor_5__DOT__a_first_counter_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_5__DOT__a_first_counter_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__monitor_5__DOT__a_first_counter_1;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10019(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10019\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT__enq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_a_q__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_a_q__DOT__enq_ptr_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__10022(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__10022\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fdivsqrt__DOT__divsqrt__DOT__ds__DOT__divSqrtRecF64ToRaw__DOT__cycleNum_B 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fdivsqrt__DOT__divsqrt__DOT__ds__DOT__divSqrtRecF64ToRaw__DOT__cycleNum_B;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_fbus_buffer__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_a_q__DOT__ram_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceC__DOT__queue__DOT__ram_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11017(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11017\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mmios_0__DOT__state 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mmios_0__DOT__state;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11739(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11739\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fdivsqrt__DOT__divsqrt__DOT__ds__DOT__divSqrtRecF64ToRaw__DOT__cycleNum_C 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fdivsqrt__DOT__divsqrt__DOT__ds__DOT__divSqrtRecF64ToRaw__DOT__cycleNum_C;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fdivsqrt__DOT__divsqrt__DOT__ds__DOT__divSqrtRecF64ToRaw__DOT__cycleNum_E 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fdivsqrt__DOT__divsqrt__DOT__ds__DOT__divSqrtRecF64ToRaw__DOT__cycleNum_E;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11743(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11743\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshr_head 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__mshr_head;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11744(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11744\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_debug_wdata_2_ext__DOT__Memory__v0 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_debug_wdata_2_ext__DOT__Memory__v1 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_debug_wdata_2_ext__DOT__Memory__v2 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_debug_wdata_2_ext__DOT__Memory__v3 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_debug_wdata_2_ext__DOT__Memory__v4 = 0U;
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_debug_wdata_2_ext__DOT__Memory__v5 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12695(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12695\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__sdq_val 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__sdq_val;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12698(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12698\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fdivsqrt__DOT__divsqrt__DOT__mul__DOT__reg_result_s3[0U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fdivsqrt__DOT__divsqrt__DOT__mul__DOT__reg_result_s3[0U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fdivsqrt__DOT__divsqrt__DOT__mul__DOT__reg_result_s3[1U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fdivsqrt__DOT__divsqrt__DOT__mul__DOT__reg_result_s3[1U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fdivsqrt__DOT__divsqrt__DOT__mul__DOT__reg_result_s3[2U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fdivsqrt__DOT__divsqrt__DOT__mul__DOT__reg_result_s3[2U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fdivsqrt__DOT__divsqrt__DOT__mul__DOT__reg_result_s3[3U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fdivsqrt__DOT__divsqrt__DOT__mul__DOT__reg_result_s3[3U];
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_5__DOT__reset_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_5__DOT__reset_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_5__DOT__reset_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_5__DOT__reset_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_5__DOT__clear_u_ctr 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_5__DOT__clear_u_ctr;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_5__DOT__clear_u_ctr 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_5__DOT__clear_u_ctr;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_5__DOT__doing_reset 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_5__DOT__doing_reset;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_5__DOT__doing_reset 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_5__DOT__doing_reset;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__maybe_full 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__maybe_full;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12699(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12699\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fp_sdq__DOT__valids_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fp_sdq__DOT__valids_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fp_sdq__DOT__valids_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fp_sdq__DOT__valids_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fp_sdq__DOT__valids_0 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fp_sdq__DOT__valids_0;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__valids_6 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__valids_6;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__valids_5 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__valids_5;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__valids_4 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__valids_4;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__valids_3 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__valids_3;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__valids_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__valids_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__valids_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__valids_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__valids_0 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__valids_0;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fp_sdq__DOT__deq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fp_sdq__DOT__deq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__deq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__deq_ptr_value;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12701(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12701\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_4__DOT__reset_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_4__DOT__reset_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_4__DOT__reset_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_4__DOT__reset_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_4__DOT__clear_u_ctr 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_4__DOT__clear_u_ctr;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_4__DOT__clear_u_ctr 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_4__DOT__clear_u_ctr;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_4__DOT__doing_reset 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_4__DOT__doing_reset;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12702(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12702\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_4__DOT__doing_reset 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_4__DOT__doing_reset;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rxq_com_head 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rxq_com_head;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rxq_committed_3 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rxq_committed_3;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rxq_committed_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rxq_committed_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rxq_committed_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rxq_committed_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rxq_committed_0 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rxq_committed_0;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rxq_val_3 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rxq_val_3;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rxq_val_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rxq_val_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rxq_val_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rxq_val_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rxq_val_0 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rxq_val_0;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12704(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12704\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_31__DOT__slot_uop_rxq_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_31__DOT__slot_uop_rxq_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_30__DOT__slot_uop_rxq_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_30__DOT__slot_uop_rxq_idx;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12705(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12705\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_29__DOT__slot_uop_rxq_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_29__DOT__slot_uop_rxq_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_pnr 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_pnr;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_tail 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_tail;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_31_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_31_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_31_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_31_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_31_br_mask 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_31_br_mask;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_head 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_head;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__respq__DOT__valids_3 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__respq__DOT__valids_3;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__respq__DOT__valids_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__respq__DOT__valids_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__respq__DOT__valids_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__respq__DOT__valids_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__respq__DOT__valids_0 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__respq__DOT__valids_0;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__respq__DOT__enq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__respq__DOT__enq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__respq__DOT__deq_ptr_value 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__respq__DOT__deq_ptr_value;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_repair_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_repair_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_update_mispredict 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_update_mispredict;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12706(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12706\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_update_repair 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__ftq__DOT__bpd_update_repair;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12718(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12718\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_29__DOT__slot_uop_ldq_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_29__DOT__slot_uop_ldq_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_30__DOT__slot_uop_ldq_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_30__DOT__slot_uop_ldq_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_31__DOT__slot_uop_ldq_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_31__DOT__slot_uop_ldq_idx;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12720(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12720\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_29__DOT__slot_uop_stq_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_29__DOT__slot_uop_stq_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_30__DOT__slot_uop_stq_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_30__DOT__slot_uop_stq_idx;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12722(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12722\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_31__DOT__slot_uop_stq_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_31__DOT__slot_uop_stq_idx;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12726(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12726\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_3__DOT__reset_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_3__DOT__reset_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_3__DOT__reset_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_3__DOT__reset_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_3__DOT__clear_u_ctr 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_3__DOT__clear_u_ctr;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_3__DOT__clear_u_ctr 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_3__DOT__clear_u_ctr;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_3__DOT__doing_reset 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_3__DOT__doing_reset;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_3__DOT__doing_reset 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_3__DOT__doing_reset;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12727(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12727\n"); );
    // Body
    vlSelf->__Vdlyvset__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__queue__DOT__ram_ext__DOT__Memory__v0 = 0U;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12728(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12728\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_2__DOT__reset_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_2__DOT__reset_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_2__DOT__reset_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_2__DOT__reset_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_2__DOT__clear_u_ctr 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_2__DOT__clear_u_ctr;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_2__DOT__clear_u_ctr 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_2__DOT__clear_u_ctr;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_2__DOT__doing_reset 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_1__DOT__tables_2__DOT__doing_reset;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_2__DOT__doing_reset 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_1__DOT__tables_2__DOT__doing_reset;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_0__DOT__columns_3__DOT__reset_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_0__DOT__columns_3__DOT__reset_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_0__DOT__columns_3__DOT__reset_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_0__DOT__columns_3__DOT__reset_idx;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12729(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12729\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_0__DOT__columns_3__DOT__doing_reset 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_0__DOT__columns_3__DOT__doing_reset;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_0__DOT__columns_3__DOT__doing_reset 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_0__DOT__columns_3__DOT__doing_reset;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12733(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12733\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_0__DOT__columns_2__DOT__reset_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_0__DOT__columns_2__DOT__reset_idx;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_0__DOT__columns_2__DOT__reset_idx 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_0__DOT__columns_2__DOT__reset_idx;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12734(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12734\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_0__DOT__columns_2__DOT__doing_reset 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_1__DOT__components_0__DOT__columns_2__DOT__doing_reset;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_0__DOT__columns_2__DOT__doing_reset 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__bpd__DOT__banked_predictors_0__DOT__components_0__DOT__columns_2__DOT__doing_reset;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12737(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12737\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_31 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_31;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_30 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_30;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__12738(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__12738\n"); );
    // Body
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_29 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_29;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_28 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_28;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_27 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_27;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_10 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_10;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_9 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_9;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_6 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_6;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_5 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_5;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_4 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_4;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_3 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_3;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_2;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_1;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_8 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_8;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_7 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_7;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_12 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_12;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_11 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_11;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_14 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_14;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_13 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_13;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_16 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_16;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_15 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_15;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_18 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_18;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_17 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_17;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_20 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_20;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_19 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_19;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_22 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_22;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_21 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_21;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_24 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_24;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_23 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_23;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_26 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_26;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_25 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__maptable__DOT__map_table_25;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__maptable__DOT__map_table_31 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__maptable__DOT__map_table_31;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__maptable__DOT__map_table_30 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__maptable__DOT__map_table_30;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__maptable__DOT__map_table_29 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__maptable__DOT__map_table_29;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__maptable__DOT__map_table_28 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__maptable__DOT__map_table_28;
    vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__maptable__DOT__map_table_11 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__maptable__DOT__map_table_11;
}
