// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTestHarness.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTestHarness___024root.h"

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5136(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5136\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__nextSmall_1 
        = (0x7fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__small_1) 
                    + (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___io_csr_stall_output)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT___data_arrays_0_RW0_rdata[0U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT__data_arrays_0__DOT__data_arrays_0_ext__DOT___GEN_8[0U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT___data_arrays_0_RW0_rdata[1U] 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT__data_arrays_0__DOT__data_arrays_0_ext__DOT___GEN_8[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT___data_arrays_0_RW0_rdata[2U] 
        = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT__data_arrays_0__DOT__data_arrays_0_ext__DOT__mem_0_11__DOT__ram
            [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT__data_arrays_0__DOT__data_arrays_0_ext__DOT__mem_0_11__DOT__ram_RW_0_r_addr_pipe_0] 
            << 0x18U) | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT__data_arrays_0__DOT__data_arrays_0_ext__DOT__mem_0_10__DOT__ram
                          [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT__data_arrays_0__DOT__data_arrays_0_ext__DOT__mem_0_10__DOT__ram_RW_0_r_addr_pipe_0] 
                          << 0x10U) | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT__data_arrays_0__DOT__data_arrays_0_ext__DOT___GEN_8[2U]));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT___data_arrays_0_RW0_rdata[3U] 
        = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT__data_arrays_0__DOT__data_arrays_0_ext__DOT__mem_0_15__DOT__ram
            [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT__data_arrays_0__DOT__data_arrays_0_ext__DOT__mem_0_15__DOT__ram_RW_0_r_addr_pipe_0] 
            << 0x18U) | (0xffffffU & ((0xff0000U & 
                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT__data_arrays_0__DOT__data_arrays_0_ext__DOT__mem_0_14__DOT__ram
                                        [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT__data_arrays_0__DOT__data_arrays_0_ext__DOT__mem_0_14__DOT__ram_RW_0_r_addr_pipe_0] 
                                        << 0x10U)) 
                                      | ((0xffff00U 
                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT__data_arrays_0__DOT__data_arrays_0_ext__DOT__mem_0_13__DOT__ram
                                             [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT__data_arrays_0__DOT__data_arrays_0_ext__DOT__mem_0_13__DOT__ram_RW_0_r_addr_pipe_0] 
                                             << 8U)) 
                                         | ((0xffffffU 
                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT__data_arrays_0__DOT__data_arrays_0_ext__DOT__mem_0_12__DOT__ram
                                             [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT__data_arrays_0__DOT__data_arrays_0_ext__DOT__mem_0_12__DOT__ram_RW_0_r_addr_pipe_0]) 
                                            | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT__data_arrays_0__DOT__data_arrays_0_ext__DOT__mem_0_11__DOT__ram
                                               [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__data__DOT__data_arrays_0__DOT__data_arrays_0_ext__DOT__mem_0_11__DOT__ram_RW_0_r_addr_pipe_0] 
                                               >> 8U))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__inWriteback 
        = ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__release_state)) 
           | (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__release_state)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5137(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5137\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___tile_prci_domain_4_auto_tile_reset_domain_tile_ghe_revent_out_sr_out 
        = (IData)(((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__num_contentReg) 
                       | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__num_contentReg)) 
                      | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__num_contentReg)) 
                     | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__num_contentReg)) 
                    >> 3U) | ((((0xeaU < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT__num_contentReg)) 
                                | (0xeaU < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT__num_contentReg))) 
                               | (0xfcU < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT___GEN_0))) 
                              | (0xfcU < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT___GEN_0)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT___io_near_full_output 
        = ((0xfdU < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_0__DOT___GEN_0)) 
           | (0xfdU < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__BJL__DOT__u_channel_bj_1__DOT___GEN_0)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5138(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5138\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_signed 
        = vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_signed;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_hls 
        = vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_hls;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_speculative 
        = vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_speculative;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_3 
        = (QData)((IData)((0x2aaaU & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mip_sgeip) 
                                       << 0xcU) | (
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink_2__DOT__chain__DOT__output_chain__DOT__sync_0) 
                                                    << 0xbU) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mip_vseip) 
                                                       << 0xaU) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mip_seip) 
                                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink_3__DOT__chain__DOT__output_chain__DOT__sync_0)) 
                                                          << 9U) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mip_ueip) 
                                                             << 8U) 
                                                            | ((0x80U 
                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink_1__DOT___chain_io_q) 
                                                                   << 6U)) 
                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mip_vstip) 
                                                                   << 6U) 
                                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mip_stip) 
                                                                      << 5U) 
                                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mip_utip) 
                                                                         << 4U) 
                                                                        | ((8U 
                                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink_1__DOT___chain_io_q) 
                                                                               << 3U)) 
                                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mip_vssip) 
                                                                               << 2U) 
                                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mip_ssip) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mip_usip))))))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__checking_counter_memdelay 
        = vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__checking_counter_memdelay;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___s2_meta_error_T 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_meta_uncorrectable_errors) 
           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_meta_correctable_errors_r_1) 
               << 1U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_meta_correctable_errors_r)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5139(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5139\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_0_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [0U][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [0U][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0U][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0U][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0U][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [0U][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_0_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0U][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0U][0U]))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_0_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_0_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [0U][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_1_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [1U][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [1U][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [1U][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [1U][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [1U][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [1U][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_1_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [1U][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [1U][0U]))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5140(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5140\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_1_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_1_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [1U][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_2_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [2U][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [2U][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [2U][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [2U][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [2U][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [2U][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_2_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [2U][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [2U][0U]))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_2_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_2_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [2U][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_3_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [3U][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [3U][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [3U][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [3U][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [3U][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [3U][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_3_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [3U][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [3U][0U]))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5141(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5141\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_3_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_3_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [3U][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_4_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [4U][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [4U][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [4U][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [4U][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [4U][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [4U][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_4_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [4U][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [4U][0U]))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_4_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_4_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [4U][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_5_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [5U][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [5U][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [5U][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [5U][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [5U][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [5U][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_5_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [5U][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [5U][0U]))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5142(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5142\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_5_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_5_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [5U][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_6_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [6U][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [6U][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [6U][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [6U][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [6U][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [6U][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_6_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [6U][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [6U][0U]))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_6_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_6_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [6U][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_7_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [7U][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [7U][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [7U][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [7U][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [7U][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [7U][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_7_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [7U][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [7U][0U]))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5143(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5143\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_7_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_7_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [7U][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_8_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [8U][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [8U][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [8U][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [8U][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [8U][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [8U][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_8_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [8U][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [8U][0U]))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_8_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_8_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [8U][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_9_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [9U][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [9U][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [9U][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [9U][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [9U][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [9U][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_9_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [9U][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [9U][0U]))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5144(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5144\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_9_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_9_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [9U][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_10_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [0xaU][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [0xaU][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0xaU][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0xaU][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0xaU][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [0xaU][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_10_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0xaU][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0xaU][0U]))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_10_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_10_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [0xaU][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_11_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [0xbU][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [0xbU][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0xbU][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0xbU][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0xbU][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [0xbU][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_11_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0xbU][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0xbU][0U]))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5145(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5145\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_11_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_11_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [0xbU][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_12_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [0xcU][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [0xcU][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0xcU][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0xcU][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0xcU][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [0xcU][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_12_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0xcU][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0xcU][0U]))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_12_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_12_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [0xcU][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_13_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [0xdU][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [0xdU][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0xdU][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0xdU][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0xdU][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [0xdU][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_13_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0xdU][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0xdU][0U]))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5146(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5146\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_13_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_13_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [0xdU][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_14_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [0xeU][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [0xeU][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0xeU][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0xeU][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0xeU][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [0xeU][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_14_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0xeU][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0xeU][0U]))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_14_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_14_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [0xeU][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_15_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [0xfU][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [0xfU][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0xfU][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0xfU][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0xfU][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [0xfU][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_15_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0xfU][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0xfU][0U]))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5147(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5147\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_15_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_15_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [0xfU][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_16_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [0x10U][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [0x10U][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x10U][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x10U][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x10U][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [0x10U][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_16_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x10U][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x10U][0U]))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_16_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_16_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [0x10U][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_17_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [0x11U][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [0x11U][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x11U][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x11U][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x11U][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [0x11U][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_17_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x11U][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x11U][0U]))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5148(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5148\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_17_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_17_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [0x11U][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_18_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [0x12U][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [0x12U][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x12U][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x12U][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x12U][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [0x12U][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_18_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x12U][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x12U][0U]))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_18_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_18_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [0x12U][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_19_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [0x13U][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [0x13U][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x13U][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x13U][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x13U][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [0x13U][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_19_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x13U][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x13U][0U]))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5149(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5149\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_19_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_19_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [0x13U][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_20_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [0x14U][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [0x14U][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x14U][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x14U][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x14U][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [0x14U][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_20_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x14U][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x14U][0U]))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_20_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_20_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [0x14U][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_21_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [0x15U][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [0x15U][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x15U][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x15U][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x15U][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [0x15U][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_21_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x15U][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x15U][0U]))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5150(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5150\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_21_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_21_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [0x15U][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_22_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [0x16U][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [0x16U][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x16U][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x16U][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x16U][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [0x16U][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_22_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x16U][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x16U][0U]))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_22_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_22_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [0x16U][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_23_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [0x17U][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [0x17U][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x17U][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x17U][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x17U][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [0x17U][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_23_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x17U][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x17U][0U]))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5151(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5151\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_23_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_23_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [0x17U][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_24_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [0x18U][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [0x18U][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x18U][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x18U][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x18U][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [0x18U][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_24_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x18U][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x18U][0U]))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_24_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_24_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [0x18U][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_25_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [0x19U][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [0x19U][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x19U][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x19U][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x19U][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [0x19U][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_25_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x19U][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x19U][0U]))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5152(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5152\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_25_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_25_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [0x19U][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_26_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [0x1aU][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [0x1aU][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x1aU][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x1aU][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x1aU][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [0x1aU][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_26_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x1aU][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x1aU][0U]))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_26_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_26_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [0x1aU][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_27_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [0x1bU][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [0x1bU][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x1bU][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x1bU][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x1bU][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [0x1bU][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_27_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x1bU][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x1bU][0U]))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5153(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5153\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_27_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_27_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [0x1bU][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_28_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [0x1cU][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [0x1cU][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x1cU][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x1cU][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x1cU][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [0x1cU][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_28_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x1cU][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x1cU][0U]))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_28_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_28_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [0x1cU][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_29_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [0x1dU][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [0x1dU][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x1dU][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x1dU][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x1dU][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [0x1dU][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_29_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x1dU][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x1dU][0U]))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5154(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5154\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_29_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_29_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [0x1dU][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_30_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [0x1eU][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [0x1eU][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x1eU][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x1eU][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x1eU][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [0x1eU][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_30_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x1eU][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x1eU][0U]))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_30_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_30_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [0x1eU][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_31_unrecoded_fractOut 
        = (0xfffffffffffffULL & (VL_GTS_III(13, 0x402U, 
                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                             [0x1fU][1U] 
                                             >> 0x14U))
                                  ? (0x1fffffffffffffULL 
                                     & ((((QData)((IData)(
                                                          (0U 
                                                           != 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [0x1fU][1U] 
                                                            >> 0x1dU)))) 
                                          << 0x33U) 
                                         | (0x7ffffffffffffULL 
                                            & (((QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0x1fU][1U])) 
                                                << 0x1fU) 
                                               | ((QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x1fU][0U])) 
                                                  >> 1U)))) 
                                        >> (0x3fU & 
                                            ((IData)(1U) 
                                             - ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0x1fU][1U] 
                                                 << 0xcU) 
                                                | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [0x1fU][1U] 
                                                   >> 0x14U))))))
                                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_31_unrecoded_rawIn_isInf)
                                      ? 0ULL : (((QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0x1fU][1U])) 
                                                 << 0x20U) 
                                                | (QData)((IData)(
                                                                  vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0x1fU][0U]))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5155(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5155\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_31_prevUnrecoded_rawIn_isInf 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_31_prevUnrecoded_rawIn_isSpecial_T)) 
           & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                 [0x1fU][0U] >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_reg_inst 
        = vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_reg_inst;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_toint 
        = vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_toint;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_fromint 
        = vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_fromint;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_typeTagOut 
        = vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_typeTagOut;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_fma 
        = vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_fma;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_reg_valid 
        = vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_reg_valid;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5156(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5156\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wen 
        = vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wen;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_div 
        = vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_div;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_sqrt 
        = vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__mem_ctrl_sqrt;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_14 
        = (1U & ((((((((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_write)) 
                           | (0x11U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                          | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_read))) 
                         | (0xfU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                        | (0xeU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                       | (0xdU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                      | (0xcU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                     | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                    | (0xbU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                   | (0xaU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                  | (9U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                 | (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_perf_canAcceptLoadThenLoad_T_55 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_write));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_readwrite 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_read) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_write));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5157(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5157\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter 
        = vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__do_check 
        = vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__do_check;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__check_done 
        = vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__check_done;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__rviCall 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___hasCF_this_idx_T) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_partial_insn) 
              >> 7U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_55 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__prevRVI) 
           & (0x63U == (0x7fU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_partial_insn))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT__history 
        = vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__btb__DOT__history;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wdata_rawIn_normDist_1 
        = ((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                          >> 0x16U))) ? 0U : ((1U & (IData)(
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                             >> 0x15U)))
                                               ? 1U
                                               : ((1U 
                                                   & (IData)(
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                              >> 0x14U)))
                                                   ? 2U
                                                   : 
                                                  ((1U 
                                                    & (IData)(
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                               >> 0x13U)))
                                                    ? 3U
                                                    : 
                                                   ((1U 
                                                     & (IData)(
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                >> 0x12U)))
                                                     ? 4U
                                                     : 
                                                    ((1U 
                                                      & (IData)(
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                 >> 0x11U)))
                                                      ? 5U
                                                      : 
                                                     ((1U 
                                                       & (IData)(
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                  >> 0x10U)))
                                                       ? 6U
                                                       : 
                                                      ((1U 
                                                        & (IData)(
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                   >> 0xfU)))
                                                        ? 7U
                                                        : 
                                                       ((1U 
                                                         & (IData)(
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                    >> 0xeU)))
                                                         ? 8U
                                                         : 
                                                        ((1U 
                                                          & (IData)(
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                     >> 0xdU)))
                                                          ? 9U
                                                          : 
                                                         ((1U 
                                                           & (IData)(
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                      >> 0xcU)))
                                                           ? 0xaU
                                                           : 
                                                          ((1U 
                                                            & (IData)(
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                       >> 0xbU)))
                                                            ? 0xbU
                                                            : 
                                                           ((1U 
                                                             & (IData)(
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                        >> 0xaU)))
                                                             ? 0xcU
                                                             : 
                                                            ((1U 
                                                              & (IData)(
                                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                         >> 9U)))
                                                              ? 0xdU
                                                              : 
                                                             ((1U 
                                                               & (IData)(
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                          >> 8U)))
                                                               ? 0xeU
                                                               : 
                                                              ((1U 
                                                                & (IData)(
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                           >> 7U)))
                                                                ? 0xfU
                                                                : 
                                                               ((1U 
                                                                 & (IData)(
                                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                            >> 6U)))
                                                                 ? 0x10U
                                                                 : 
                                                                ((1U 
                                                                  & (IData)(
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                             >> 5U)))
                                                                  ? 0x11U
                                                                  : 
                                                                 ((1U 
                                                                   & (IData)(
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                              >> 4U)))
                                                                   ? 0x12U
                                                                   : 
                                                                  ((1U 
                                                                    & (IData)(
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                               >> 3U)))
                                                                    ? 0x13U
                                                                    : 
                                                                   ((1U 
                                                                     & (IData)(
                                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 2U)))
                                                                     ? 0x14U
                                                                     : 
                                                                    ((1U 
                                                                      & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 1U)))
                                                                      ? 0x15U
                                                                      : 0x16U))))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5158(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5158\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__wdata_rawIn_normDist 
        = ((1U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                          >> 0x33U))) ? 0U : ((1U & (IData)(
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                             >> 0x32U)))
                                               ? 1U
                                               : ((1U 
                                                   & (IData)(
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                              >> 0x31U)))
                                                   ? 2U
                                                   : 
                                                  ((1U 
                                                    & (IData)(
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                               >> 0x30U)))
                                                    ? 3U
                                                    : 
                                                   ((1U 
                                                     & (IData)(
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                >> 0x2fU)))
                                                     ? 4U
                                                     : 
                                                    ((1U 
                                                      & (IData)(
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                 >> 0x2eU)))
                                                      ? 5U
                                                      : 
                                                     ((1U 
                                                       & (IData)(
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                  >> 0x2dU)))
                                                       ? 6U
                                                       : 
                                                      ((1U 
                                                        & (IData)(
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                   >> 0x2cU)))
                                                        ? 7U
                                                        : 
                                                       ((1U 
                                                         & (IData)(
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                    >> 0x2bU)))
                                                         ? 8U
                                                         : 
                                                        ((1U 
                                                          & (IData)(
                                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                     >> 0x2aU)))
                                                          ? 9U
                                                          : 
                                                         ((1U 
                                                           & (IData)(
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                      >> 0x29U)))
                                                           ? 0xaU
                                                           : 
                                                          ((1U 
                                                            & (IData)(
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                       >> 0x28U)))
                                                            ? 0xbU
                                                            : 
                                                           ((1U 
                                                             & (IData)(
                                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                        >> 0x27U)))
                                                             ? 0xcU
                                                             : 
                                                            ((1U 
                                                              & (IData)(
                                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                         >> 0x26U)))
                                                              ? 0xdU
                                                              : 
                                                             ((1U 
                                                               & (IData)(
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                          >> 0x25U)))
                                                               ? 0xeU
                                                               : 
                                                              ((1U 
                                                                & (IData)(
                                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                           >> 0x24U)))
                                                                ? 0xfU
                                                                : 
                                                               ((1U 
                                                                 & (IData)(
                                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                            >> 0x23U)))
                                                                 ? 0x10U
                                                                 : 
                                                                ((1U 
                                                                  & (IData)(
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                             >> 0x22U)))
                                                                  ? 0x11U
                                                                  : 
                                                                 ((1U 
                                                                   & (IData)(
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                              >> 0x21U)))
                                                                   ? 0x12U
                                                                   : 
                                                                  ((1U 
                                                                    & (IData)(
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                               >> 0x20U)))
                                                                    ? 0x13U
                                                                    : 
                                                                   ((1U 
                                                                     & (IData)(
                                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 0x1fU)))
                                                                     ? 0x14U
                                                                     : 
                                                                    ((1U 
                                                                      & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 0x1eU)))
                                                                      ? 0x15U
                                                                      : 
                                                                     ((1U 
                                                                       & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 0x1dU)))
                                                                       ? 0x16U
                                                                       : 
                                                                      ((1U 
                                                                        & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 0x1cU)))
                                                                        ? 0x17U
                                                                        : 
                                                                       ((1U 
                                                                         & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 0x1bU)))
                                                                         ? 0x18U
                                                                         : 
                                                                        ((1U 
                                                                          & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 0x1aU)))
                                                                          ? 0x19U
                                                                          : 
                                                                         ((1U 
                                                                           & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 0x19U)))
                                                                           ? 0x1aU
                                                                           : 
                                                                          ((1U 
                                                                            & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 0x18U)))
                                                                            ? 0x1bU
                                                                            : 
                                                                           ((1U 
                                                                             & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 0x17U)))
                                                                             ? 0x1cU
                                                                             : 
                                                                            ((1U 
                                                                              & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 0x16U)))
                                                                              ? 0x1dU
                                                                              : 
                                                                             ((1U 
                                                                               & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 0x15U)))
                                                                               ? 0x1eU
                                                                               : 
                                                                              ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 0x14U)))
                                                                                ? 0x1fU
                                                                                : 
                                                                               ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 0x13U)))
                                                                                 ? 0x20U
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 0x12U)))
                                                                                 ? 0x21U
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 0x11U)))
                                                                                 ? 0x22U
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 0x10U)))
                                                                                 ? 0x23U
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 0xfU)))
                                                                                 ? 0x24U
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 0xeU)))
                                                                                 ? 0x25U
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 0xdU)))
                                                                                 ? 0x26U
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 0xcU)))
                                                                                 ? 0x27U
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 0xbU)))
                                                                                 ? 0x28U
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 0xaU)))
                                                                                 ? 0x29U
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 9U)))
                                                                                 ? 0x2aU
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 8U)))
                                                                                 ? 0x2bU
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 7U)))
                                                                                 ? 0x2cU
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 6U)))
                                                                                 ? 0x2dU
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 5U)))
                                                                                 ? 0x2eU
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 4U)))
                                                                                 ? 0x2fU
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 3U)))
                                                                                 ? 0x30U
                                                                                 : 
                                                                                ((1U 
                                                                                & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 2U)))
                                                                                 ? 0x31U
                                                                                 : 
                                                                                (0x32U 
                                                                                | (1U 
                                                                                & (~ (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___wdata_T_2 
                                                                                >> 1U)))))))))))))))))))))))))))))))))))))))))))))))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5159(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5159\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT___GEN_0 
        = ((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__lsl_deq_ptr))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT__emptyReg)
            : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT__emptyReg));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___T_320) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_size = 6U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_opcode 
            = (6U | (9U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__release_state)));
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_size 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_size;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tl_out_c_bits_opcode 
            = (4U | (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__release_state)));
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__lrscCount 
        = vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__lrscCount;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__uncachedReqs_0_size 
        = vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__uncachedReqs_0_size;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_state_reg_1 
        = vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_state_reg_1;
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5160(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5160\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_vm_enabled 
        = (IData)(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_satp_mode) 
                     >> 3U) & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_prv) 
                                  >> 1U))) & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_tlb_req_passthrough))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___nackq_io_deq_bits 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__ram_ext__DOT__Memory
        [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__deq_ptr_value];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___r_sectored_repl_addr_valids_T_2 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___r_sectored_repl_addr_valids_T) 
            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_0_valid_2)) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_0_valid_3));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5161(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5161\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___r_sectored_repl_addr_valids_T_11 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___r_sectored_repl_addr_valids_T_9) 
            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_3_valid_2)) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_3_valid_3));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___r_sectored_repl_addr_valids_T_20 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___r_sectored_repl_addr_valids_T_18) 
            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_6_valid_2)) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_6_valid_3));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___r_sectored_repl_addr_valids_T_14 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___r_sectored_repl_addr_valids_T_12) 
            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_4_valid_2)) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_4_valid_3));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___r_sectored_repl_addr_valids_T_8 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___r_sectored_repl_addr_valids_T_6) 
            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_2_valid_2)) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_2_valid_3));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___r_sectored_repl_addr_valids_T_5 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___r_sectored_repl_addr_valids_T_3) 
            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_1_valid_2)) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_1_valid_3));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___r_sectored_repl_addr_valids_T_17 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___r_sectored_repl_addr_valids_T_15) 
            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_5_valid_2)) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__sectored_entries_0_5_valid_3));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5162(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5162\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__empty 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__ptr_match) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__maybe_full)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5163(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5163\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__empty 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__ptr_match) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT__nackq__DOT__maybe_full)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT__s1_id 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___ptw_io_mem_req_valid)
            ? 0U : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output)
                     ? 1U : 2U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__s1_req_fire 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__s0_req_fire;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s1_valid 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_4_reset)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s0_valid));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___s2_tag_disparity_T 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_tag_disparity_r_7) 
            << 7U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_tag_disparity_r_6) 
                       << 6U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_tag_disparity_r_5) 
                                  << 5U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_tag_disparity_r_4) 
                                             << 4U) 
                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_tag_disparity_r_3) 
                                                << 3U) 
                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_tag_disparity_r_2) 
                                                   << 2U) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_tag_disparity_r_1) 
                                                      << 1U) 
                                                     | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_tag_disparity_r_0))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_valid 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_valid) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_hit));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___icache_io_resp_bits_data 
        = (((((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_tag_hit_0)
                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_dout_0
                   : 0U) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_tag_hit_1)
                             ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_dout_1
                             : 0U)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_tag_hit_2)
                                        ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_dout_2
                                        : 0U)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_tag_hit_3)
                                                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_dout_3
                                                   : 0U)) 
              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_tag_hit_4)
                  ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_dout_4
                  : 0U)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_tag_hit_5)
                             ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_dout_5
                             : 0U)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_tag_hit_6)
                                        ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_dout_6
                                        : 0U)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_tag_hit_7)
                                                   ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s2_dout_7
                                                   : 0U));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5164(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5164\n"); );
    // Body
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_bypass_0) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_rs0 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ex_rs_T_5;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__coreMonitorBundle_rd0val_REG 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ex_rs_T_5;
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_rs0 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ex_rs_T_6;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__coreMonitorBundle_rd0val_REG 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ex_rs_T_6;
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__coreMonitorBundle_rd1val_REG 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_rs_bypass_1)
            ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ex_rs_T_12
            : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ex_rs_T_13);
    if ((1U & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_71) 
                  | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_pc_valid)))))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_rxs1 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_rxs1;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_cause 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_cause;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_rfs1 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_rfs1;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_rfs2 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_rfs2;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_wfd 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_wfd;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_raw_inst 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_raw_inst;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_scie_pipelined 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_scie_pipelined;
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__tval_any_addr 
        = (1U & (((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_xcpt)) 
                    | (3ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_cause)) 
                   | (1ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_cause)) 
                  | (0xcULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_cause)) 
                 | (0x14ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_reg_cause)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5165(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5165\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_scie_pipelined 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killd) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_scie_pipelined));
    if ((1U & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_71) 
                  | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_pc_valid)))))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_fp 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_fp;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_wxd 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_wxd;
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_xcpt_interrupt 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem_wb)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_xcpt_interrupt));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_xcpt 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killx)) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_xcpt_interrupt) 
              | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_xcpt)));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT____Vcellinp__fpiu__io_in_valid) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_fmt 
            = (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ex_reg_inst 
                     >> 0x19U));
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__u_channel__DOT___nextVal_T 
        = (0x31U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__u_channel__DOT__readPtr));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__u_channel__DOT___nextVal_T_2 
        = (0x3fU & ((IData)(1U) + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__u_channel__DOT__readPtr)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__u_channel__DOT___nextVal_T_3 
        = (0x31U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__u_channel__DOT__writePtr));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__u_channel__DOT___nextVal_T_5 
        = (0x3fU & ((IData)(1U) + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__u_channel__DOT__writePtr)));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_fpu_valid) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ex_reg_ctrl_typeTagIn 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___fp_decoder_io_sigs_typeTagIn;
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT___mux_data_T_2 
        = (((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT__inPipe_bits_typeTagIn))
             ? 0ULL : 0xffffffff00000000ULL) | vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT__inPipe_bits_in1);
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_4_reset) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__lfsr_prng__DOT__state_9 = 0U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0_prng__DOT__state_9 = 0U;
    } else {
        if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT____Vcellinp__lfsr_prng__io_increment) {
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__lfsr_prng__DOT__state_9 
                = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__lfsr_prng__DOT__state_8;
        }
        if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___refill_fire_T) {
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0_prng__DOT__state_9 
                = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__repl_way_v0_prng__DOT__state_8;
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5166(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5166\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT___lsl_enq_ptr_T_1 
        = (3U & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__lsl_enq_ptr) 
                  + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__enq_valid_0)) 
                 + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__enq_valid_1)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__enq_OH_0 
        = ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__enq_offset_0)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__enq_valid_0));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__enq_OH_0_1 
        = ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__enq_offset_0)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__enq_valid_0));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT___enq_offset_T_10 
        = (3U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__lsl_enq_ptr) 
                 + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__enq_valid_0)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT___csr_enq_ptr_T_1 
        = (3U & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_enq_ptr) 
                  + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_enq_valid_0)) 
                 + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_enq_valid_1)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_enq_OH_0 
        = ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_enq_offset_0)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_enq_valid_0));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_enq_OH_0_1 
        = ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_enq_offset_0)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_enq_valid_0));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT___csr_enq_offset_T_10 
        = (3U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_enq_ptr) 
                 + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__csr_enq_valid_0)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT___rocc_enq_ptr_T_1 
        = (3U & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_enq_ptr) 
                  + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_enq_valid_0)) 
                 + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_enq_valid_1)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_enq_OH_0 
        = ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_enq_offset_0)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_enq_valid_0));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_enq_OH_0_1 
        = ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_enq_offset_0)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_enq_valid_0));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT___rocc_enq_offset_T_10 
        = (3U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_enq_ptr) 
                 + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__rocc_enq_valid_0)));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_4_reset) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__writePtr = 0U;
    } else if (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT___T_10) 
                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT___T_4))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__writePtr 
            = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT___nextVal_T_3)
                ? 0U : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT___nextVal_T_5));
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5167(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5167\n"); );
    // Body
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_4_reset) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__writePtr = 0U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__writePtr = 0U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__writePtr = 0U;
    } else {
        if (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT___T_10) 
             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT___T_4))) {
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__writePtr 
                = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT___nextVal_T_3)
                    ? 0U : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT___nextVal_T_5));
        }
        if (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT___T_10) 
             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT___T_4))) {
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__writePtr 
                = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT___nextVal_T_3)
                    ? 0U : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT___nextVal_T_5));
        }
        if (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT___T_10) 
             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT___T_4))) {
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__writePtr 
                = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT___nextVal_T_3)
                    ? 0U : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT___nextVal_T_5));
        }
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__commonCase 
        = (1U & (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__isNaNOut)) 
                  & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__notNaN_isSpecialInfOut))) 
                 & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__isZero_Z))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_1__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__commonCase 
        = (1U & (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_1__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__isNaNOut)) 
                  & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_1__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__notNaN_isSpecialInfOut))) 
                 & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_1__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__isZero_Z))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT___T_2 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__inPipe_bits_wflags) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__inPipe_bits_ren2)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__isNaNOut 
        = ((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__inPipe_bits_in1[1U] 
                   >> 0x1dU)) & (7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__inPipe_bits_in2[1U] 
                                        >> 0x1dU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT___fsgnj_T 
        = (1U & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__inPipe_bits_rm))
                  ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__inPipe_bits_in1[2U] 
                     ^ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__inPipe_bits_in2[2U])
                  : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__inPipe_bits_rm) 
                     ^ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__inPipe_bits_in2[2U])));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5168(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5168\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__narrower__DOT____Vcellinp__roundAnyRawFNToRecFN__io_in_isInf 
        = (IData)((0xc0000000U == (0xe0000000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__inPipe_bits_in1[1U])));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__narrower__DOT__roundAnyRawFNToRecFN__DOT__roundMagUp 
        = (((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__inPipe_bits_rm)) 
            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__inPipe_bits_in1[2U]) 
           | ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__inPipe_bits_rm)) 
              & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__inPipe_bits_in1[2U])));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__narrower__DOT__rawIn_isNaN 
        = (IData)((0xe0000000U == (0xe0000000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__inPipe_bits_in1[1U])));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__narrower__DOT____Vcellinp__roundAnyRawFNToRecFN__io_in_sig 
        = (((QData)((IData)((0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__inPipe_bits_in1[1U] 
                                    >> 0x1dU)))) << 0x34U) 
           | (0xfffffffffffffULL & (((QData)((IData)(
                                                     vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__inPipe_bits_in1[1U])) 
                                     << 0x20U) | (QData)((IData)(
                                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__inPipe_bits_in1[0U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__narrower__DOT__roundAnyRawFNToRecFN__DOT__sAdjustedExp 
        = (0x3fffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpmu__DOT__inPipe_bits_in1[1U] 
                       >> 0x14U) - (IData)(0x700U)));
    if ((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killd)))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_fence_i 
            = (0x3ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_58));
    }
    if (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_stalld)) 
         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT___T_7))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ibufBTBResp_bht_value 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_bht_value;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ibufBTBResp_target 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_target;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ibufBTBResp_cfiType 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_cfiType;
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5169(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5169\n"); );
    // Body
    if (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_stalld)) 
         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT___T_7))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ibufBTBResp_mask 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_mask;
    }
    if ((1U & (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killd)) 
                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___csr_io_interrupt)) 
               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_replay)))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_btb_resp_entry 
            = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT___T_23)
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ibufBTBResp_entry)
                : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_entry));
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__valid) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_fromPreMul_b_isNaNC 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT__rawC_isNaN;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_fromPreMul_b_isNaNAOrB 
            = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT__rawA_isNaN) 
               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT__rawB_isNaN));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_fromPreMul_b_CIsDominant 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT__CIsDominant;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_roundingMode_b 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__in_rm;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundingMode_stage0_b 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__in_rm;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_fromPreMul_b_signProd 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT__signProd;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_fromPreMul_b_doSubMags 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT__doSubMags;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_fromPreMul_b_isZeroA 
            = (1U & (~ (IData)((0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__in_in1[1U] 
                                       >> 0x1dU)))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_fromPreMul_b_isInfA 
            = (IData)((0xc0000000U == (0xe0000000U 
                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__in_in1[1U])));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_fromPreMul_b_isZeroB 
            = (1U & (~ (IData)((0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__in_in2[1U] 
                                       >> 0x1dU)))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__valid_stage0_v 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_4_reset)));
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__valid_stage0_v = 0U;
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__isNaNOut 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_invalidExc_b) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_isNaN));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5170(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5170\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__0;
    VlWide<3>/*95:0*/ __Vtemp_hd5804cc9__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__1;
    VlWide<3>/*95:0*/ __Vtemp_h48a4f13d__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__2;
    VlWide<3>/*95:0*/ __Vtemp_h23f17cd0__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__3;
    VlWide<3>/*95:0*/ __Vtemp_hf9be91e8__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__4;
    VlWide<3>/*95:0*/ __Vtemp_h4b15faf5__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__5;
    VlWide<3>/*95:0*/ __Vtemp_hbfd7d933__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__6;
    VlWide<3>/*95:0*/ __Vtemp_hfc65fb72__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__7;
    VlWide<3>/*95:0*/ __Vtemp_h7c44d4ba__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__8;
    VlWide<3>/*95:0*/ __Vtemp_hf10e72ce__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__9;
    VlWide<3>/*95:0*/ __Vtemp_h5c9514d2__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__10;
    VlWide<3>/*95:0*/ __Vtemp_h2ac9b076__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__11;
    VlWide<3>/*95:0*/ __Vtemp_hd235a5a3__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__12;
    VlWide<3>/*95:0*/ __Vtemp_hd460f4f2__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__13;
    VlWide<3>/*95:0*/ __Vtemp_h42d7bc1b__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__14;
    VlWide<3>/*95:0*/ __Vtemp_hafc17311__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__15;
    VlWide<3>/*95:0*/ __Vtemp_h95c917fc__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__16;
    VlWide<3>/*95:0*/ __Vtemp_h662c623f__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__17;
    VlWide<3>/*95:0*/ __Vtemp_he2028f23__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__18;
    VlWide<3>/*95:0*/ __Vtemp_h7049c5bc__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__19;
    VlWide<3>/*95:0*/ __Vtemp_h98d458c4__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__20;
    VlWide<3>/*95:0*/ __Vtemp_h88e5a187__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__21;
    VlWide<3>/*95:0*/ __Vtemp_hd29239e1__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__22;
    VlWide<3>/*95:0*/ __Vtemp_hd703056c__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__23;
    VlWide<3>/*95:0*/ __Vtemp_h219fb702__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__24;
    VlWide<3>/*95:0*/ __Vtemp_h1b0c3f2e__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__25;
    VlWide<3>/*95:0*/ __Vtemp_h53d5d654__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__26;
    VlWide<3>/*95:0*/ __Vtemp_h9a220410__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__27;
    VlWide<3>/*95:0*/ __Vtemp_he4186cea__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__28;
    VlWide<3>/*95:0*/ __Vtemp_h8892cda8__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__29;
    VlWide<3>/*95:0*/ __Vtemp_haa4e0269__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__30;
    VlWide<3>/*95:0*/ __Vtemp_h088fc989__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__31;
    VlWide<3>/*95:0*/ __Vtemp_h3434425e__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__32;
    VlWide<3>/*95:0*/ __Vtemp_ha70f29fd__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__33;
    VlWide<3>/*95:0*/ __Vtemp_h5ae7feba__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__34;
    VlWide<3>/*95:0*/ __Vtemp_hb19583b4__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__35;
    VlWide<3>/*95:0*/ __Vtemp_hda056d9f__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__36;
    VlWide<3>/*95:0*/ __Vtemp_hc6263e1a__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__37;
    VlWide<3>/*95:0*/ __Vtemp_h449e8a75__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__38;
    VlWide<3>/*95:0*/ __Vtemp_h15d05d04__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__39;
    VlWide<3>/*95:0*/ __Vtemp_h58bc3c77__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__40;
    VlWide<3>/*95:0*/ __Vtemp_h14739508__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__41;
    VlWide<3>/*95:0*/ __Vtemp_h27fcda8b__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__42;
    VlWide<3>/*95:0*/ __Vtemp_h8ccf991f__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__43;
    VlWide<3>/*95:0*/ __Vtemp_h2490b1c7__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__44;
    VlWide<3>/*95:0*/ __Vtemp_h3dfb01ed__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__45;
    VlWide<3>/*95:0*/ __Vtemp_h461414ba__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__46;
    VlWide<3>/*95:0*/ __Vtemp_h57e618ca__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__47;
    VlWide<3>/*95:0*/ __Vtemp_h570b8902__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__48;
    VlWide<3>/*95:0*/ __Vtemp_h02f5e130__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__49;
    VlWide<3>/*95:0*/ __Vtemp_h0d39d963__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__50;
    VlWide<3>/*95:0*/ __Vtemp_hb8348215__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__51;
    VlWide<3>/*95:0*/ __Vtemp_h861d5df4__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__52;
    VlWide<3>/*95:0*/ __Vtemp_h572e6077__0;
    VlWide<3>/*95:0*/ __Vtemp_h5f174993__53;
    VlWide<3>/*95:0*/ __Vtemp_h2e727092__0;
    // Body
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__valid) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_fromPreMul_b_isInfB 
            = (IData)((0xc0000000U == (0xe0000000U 
                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__in_in2[1U])));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_fromPreMul_b_isInfC 
            = (IData)((0xc0000000U == (0xe0000000U 
                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__in_in3[1U])));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_fromPreMul_b_sExpSum 
            = (0x1fffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT__CIsDominant)
                           ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__in_in3[1U] 
                              >> 0x14U) : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT___sExpAlignedProd_T_2) 
                                           - (IData)(0x35U))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_fromPreMul_b_isSigNaNAny 
            = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT__rawA_isNaN) 
                 & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__in_in1[1U] 
                       >> 0x13U))) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT__rawB_isNaN) 
                                      & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__in_in2[1U] 
                                            >> 0x13U)))) 
               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT__rawC_isNaN) 
                  & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__in_in3[1U] 
                        >> 0x13U))));
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT___overflow_roundMagUp_T 
        = ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_roundingMode_b)) 
           | (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_roundingMode_b)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT__roundMagUp 
        = (((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_roundingMode_b)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sign)) 
           | ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_roundingMode_b)) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sign))));
    __Vtemp_h5f174993__0[0U] = 0U;
    __Vtemp_h5f174993__0[1U] = 0U;
    __Vtemp_h5f174993__0[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_hd5804cc9__0, __Vtemp_h5f174993__0, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__1[0U] = 0U;
    __Vtemp_h5f174993__1[1U] = 0U;
    __Vtemp_h5f174993__1[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h48a4f13d__0, __Vtemp_h5f174993__1, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__2[0U] = 0U;
    __Vtemp_h5f174993__2[1U] = 0U;
    __Vtemp_h5f174993__2[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h23f17cd0__0, __Vtemp_h5f174993__2, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__3[0U] = 0U;
    __Vtemp_h5f174993__3[1U] = 0U;
    __Vtemp_h5f174993__3[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_hf9be91e8__0, __Vtemp_h5f174993__3, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__4[0U] = 0U;
    __Vtemp_h5f174993__4[1U] = 0U;
    __Vtemp_h5f174993__4[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h4b15faf5__0, __Vtemp_h5f174993__4, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__5[0U] = 0U;
    __Vtemp_h5f174993__5[1U] = 0U;
    __Vtemp_h5f174993__5[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_hbfd7d933__0, __Vtemp_h5f174993__5, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__6[0U] = 0U;
    __Vtemp_h5f174993__6[1U] = 0U;
    __Vtemp_h5f174993__6[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_hfc65fb72__0, __Vtemp_h5f174993__6, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__7[0U] = 0U;
    __Vtemp_h5f174993__7[1U] = 0U;
    __Vtemp_h5f174993__7[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h7c44d4ba__0, __Vtemp_h5f174993__7, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__8[0U] = 0U;
    __Vtemp_h5f174993__8[1U] = 0U;
    __Vtemp_h5f174993__8[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_hf10e72ce__0, __Vtemp_h5f174993__8, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__9[0U] = 0U;
    __Vtemp_h5f174993__9[1U] = 0U;
    __Vtemp_h5f174993__9[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h5c9514d2__0, __Vtemp_h5f174993__9, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__10[0U] = 0U;
    __Vtemp_h5f174993__10[1U] = 0U;
    __Vtemp_h5f174993__10[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h2ac9b076__0, __Vtemp_h5f174993__10, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__11[0U] = 0U;
    __Vtemp_h5f174993__11[1U] = 0U;
    __Vtemp_h5f174993__11[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_hd235a5a3__0, __Vtemp_h5f174993__11, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__12[0U] = 0U;
    __Vtemp_h5f174993__12[1U] = 0U;
    __Vtemp_h5f174993__12[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_hd460f4f2__0, __Vtemp_h5f174993__12, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__13[0U] = 0U;
    __Vtemp_h5f174993__13[1U] = 0U;
    __Vtemp_h5f174993__13[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h42d7bc1b__0, __Vtemp_h5f174993__13, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__14[0U] = 0U;
    __Vtemp_h5f174993__14[1U] = 0U;
    __Vtemp_h5f174993__14[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_hafc17311__0, __Vtemp_h5f174993__14, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__15[0U] = 0U;
    __Vtemp_h5f174993__15[1U] = 0U;
    __Vtemp_h5f174993__15[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h95c917fc__0, __Vtemp_h5f174993__15, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__16[0U] = 0U;
    __Vtemp_h5f174993__16[1U] = 0U;
    __Vtemp_h5f174993__16[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h662c623f__0, __Vtemp_h5f174993__16, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__17[0U] = 0U;
    __Vtemp_h5f174993__17[1U] = 0U;
    __Vtemp_h5f174993__17[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_he2028f23__0, __Vtemp_h5f174993__17, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__18[0U] = 0U;
    __Vtemp_h5f174993__18[1U] = 0U;
    __Vtemp_h5f174993__18[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h7049c5bc__0, __Vtemp_h5f174993__18, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__19[0U] = 0U;
    __Vtemp_h5f174993__19[1U] = 0U;
    __Vtemp_h5f174993__19[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h98d458c4__0, __Vtemp_h5f174993__19, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__20[0U] = 0U;
    __Vtemp_h5f174993__20[1U] = 0U;
    __Vtemp_h5f174993__20[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h88e5a187__0, __Vtemp_h5f174993__20, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__21[0U] = 0U;
    __Vtemp_h5f174993__21[1U] = 0U;
    __Vtemp_h5f174993__21[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_hd29239e1__0, __Vtemp_h5f174993__21, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__22[0U] = 0U;
    __Vtemp_h5f174993__22[1U] = 0U;
    __Vtemp_h5f174993__22[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_hd703056c__0, __Vtemp_h5f174993__22, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__23[0U] = 0U;
    __Vtemp_h5f174993__23[1U] = 0U;
    __Vtemp_h5f174993__23[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h219fb702__0, __Vtemp_h5f174993__23, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__24[0U] = 0U;
    __Vtemp_h5f174993__24[1U] = 0U;
    __Vtemp_h5f174993__24[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h1b0c3f2e__0, __Vtemp_h5f174993__24, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__25[0U] = 0U;
    __Vtemp_h5f174993__25[1U] = 0U;
    __Vtemp_h5f174993__25[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h53d5d654__0, __Vtemp_h5f174993__25, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__26[0U] = 0U;
    __Vtemp_h5f174993__26[1U] = 0U;
    __Vtemp_h5f174993__26[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h9a220410__0, __Vtemp_h5f174993__26, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__27[0U] = 0U;
    __Vtemp_h5f174993__27[1U] = 0U;
    __Vtemp_h5f174993__27[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_he4186cea__0, __Vtemp_h5f174993__27, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__28[0U] = 0U;
    __Vtemp_h5f174993__28[1U] = 0U;
    __Vtemp_h5f174993__28[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h8892cda8__0, __Vtemp_h5f174993__28, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__29[0U] = 0U;
    __Vtemp_h5f174993__29[1U] = 0U;
    __Vtemp_h5f174993__29[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_haa4e0269__0, __Vtemp_h5f174993__29, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__30[0U] = 0U;
    __Vtemp_h5f174993__30[1U] = 0U;
    __Vtemp_h5f174993__30[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h088fc989__0, __Vtemp_h5f174993__30, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__31[0U] = 0U;
    __Vtemp_h5f174993__31[1U] = 0U;
    __Vtemp_h5f174993__31[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h3434425e__0, __Vtemp_h5f174993__31, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__32[0U] = 0U;
    __Vtemp_h5f174993__32[1U] = 0U;
    __Vtemp_h5f174993__32[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_ha70f29fd__0, __Vtemp_h5f174993__32, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__33[0U] = 0U;
    __Vtemp_h5f174993__33[1U] = 0U;
    __Vtemp_h5f174993__33[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h5ae7feba__0, __Vtemp_h5f174993__33, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__34[0U] = 0U;
    __Vtemp_h5f174993__34[1U] = 0U;
    __Vtemp_h5f174993__34[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_hb19583b4__0, __Vtemp_h5f174993__34, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__35[0U] = 0U;
    __Vtemp_h5f174993__35[1U] = 0U;
    __Vtemp_h5f174993__35[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_hda056d9f__0, __Vtemp_h5f174993__35, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__36[0U] = 0U;
    __Vtemp_h5f174993__36[1U] = 0U;
    __Vtemp_h5f174993__36[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_hc6263e1a__0, __Vtemp_h5f174993__36, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__37[0U] = 0U;
    __Vtemp_h5f174993__37[1U] = 0U;
    __Vtemp_h5f174993__37[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h449e8a75__0, __Vtemp_h5f174993__37, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__38[0U] = 0U;
    __Vtemp_h5f174993__38[1U] = 0U;
    __Vtemp_h5f174993__38[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h15d05d04__0, __Vtemp_h5f174993__38, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__39[0U] = 0U;
    __Vtemp_h5f174993__39[1U] = 0U;
    __Vtemp_h5f174993__39[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h58bc3c77__0, __Vtemp_h5f174993__39, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__40[0U] = 0U;
    __Vtemp_h5f174993__40[1U] = 0U;
    __Vtemp_h5f174993__40[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h14739508__0, __Vtemp_h5f174993__40, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__41[0U] = 0U;
    __Vtemp_h5f174993__41[1U] = 0U;
    __Vtemp_h5f174993__41[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h27fcda8b__0, __Vtemp_h5f174993__41, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__42[0U] = 0U;
    __Vtemp_h5f174993__42[1U] = 0U;
    __Vtemp_h5f174993__42[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h8ccf991f__0, __Vtemp_h5f174993__42, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__43[0U] = 0U;
    __Vtemp_h5f174993__43[1U] = 0U;
    __Vtemp_h5f174993__43[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h2490b1c7__0, __Vtemp_h5f174993__43, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__44[0U] = 0U;
    __Vtemp_h5f174993__44[1U] = 0U;
    __Vtemp_h5f174993__44[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h3dfb01ed__0, __Vtemp_h5f174993__44, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__45[0U] = 0U;
    __Vtemp_h5f174993__45[1U] = 0U;
    __Vtemp_h5f174993__45[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h461414ba__0, __Vtemp_h5f174993__45, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__46[0U] = 0U;
    __Vtemp_h5f174993__46[1U] = 0U;
    __Vtemp_h5f174993__46[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h57e618ca__0, __Vtemp_h5f174993__46, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__47[0U] = 0U;
    __Vtemp_h5f174993__47[1U] = 0U;
    __Vtemp_h5f174993__47[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h570b8902__0, __Vtemp_h5f174993__47, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__48[0U] = 0U;
    __Vtemp_h5f174993__48[1U] = 0U;
    __Vtemp_h5f174993__48[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h02f5e130__0, __Vtemp_h5f174993__48, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__49[0U] = 0U;
    __Vtemp_h5f174993__49[1U] = 0U;
    __Vtemp_h5f174993__49[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h0d39d963__0, __Vtemp_h5f174993__49, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__50[0U] = 0U;
    __Vtemp_h5f174993__50[1U] = 0U;
    __Vtemp_h5f174993__50[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_hb8348215__0, __Vtemp_h5f174993__50, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__51[0U] = 0U;
    __Vtemp_h5f174993__51[1U] = 0U;
    __Vtemp_h5f174993__51[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h861d5df4__0, __Vtemp_h5f174993__51, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__52[0U] = 0U;
    __Vtemp_h5f174993__52[1U] = 0U;
    __Vtemp_h5f174993__52[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h572e6077__0, __Vtemp_h5f174993__52, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    __Vtemp_h5f174993__53[0U] = 0U;
    __Vtemp_h5f174993__53[1U] = 0U;
    __Vtemp_h5f174993__53[2U] = 1U;
    VL_SHIFTRS_WWI(65,65,6, __Vtemp_h2e727092__0, __Vtemp_h5f174993__53, 
                   (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT___roundMask_T_129 
        = (((0x800U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))
             ? 0ULL : ((0x400U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))
                        ? (QData)((IData)(((IData)(
                                                   (0U 
                                                    == 
                                                    (0x3c0U 
                                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))))
                                            ? ((4U 
                                                & (__Vtemp_hd5804cc9__0[0U] 
                                                   << 2U)) 
                                               | ((2U 
                                                   & __Vtemp_h48a4f13d__0[0U]) 
                                                  | (1U 
                                                     & (__Vtemp_h23f17cd0__0[0U] 
                                                        >> 2U))))
                                            : 0U)))
                        : (7ULL | (0x3ffffffffffff8ULL 
                                   & ((~ ((IData)((0x3c0U 
                                                   != 
                                                   (0x3c0U 
                                                    & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sExp))))
                                           ? 0ULL : 
                                          (~ (((QData)((IData)(
                                                               ((0x80000000U 
                                                                 & (__Vtemp_hf9be91e8__0[0U] 
                                                                    << 0x12U)) 
                                                                | ((0x40000000U 
                                                                    & (__Vtemp_h4b15faf5__0[0U] 
                                                                       << 0x10U)) 
                                                                   | ((0x20000000U 
                                                                       & (__Vtemp_hbfd7d933__0[0U] 
                                                                          << 0xeU)) 
                                                                      | ((0x10000000U 
                                                                          & (__Vtemp_hfc65fb72__0[0U] 
                                                                             << 0xcU)) 
                                                                         | ((0x8000000U 
                                                                             & (__Vtemp_h7c44d4ba__0[0U] 
                                                                                << 0xaU)) 
                                                                            | ((0x4000000U 
                                                                                & (__Vtemp_hf10e72ce__0[0U] 
                                                                                << 8U)) 
                                                                               | ((0x2000000U 
                                                                                & (__Vtemp_h5c9514d2__0[0U] 
                                                                                << 6U)) 
                                                                                | ((0x1000000U 
                                                                                & (__Vtemp_h2ac9b076__0[0U] 
                                                                                << 4U)) 
                                                                                | ((0x800000U 
                                                                                & (__Vtemp_hd235a5a3__0[0U] 
                                                                                << 2U)) 
                                                                                | ((0x400000U 
                                                                                & __Vtemp_hd460f4f2__0[0U]) 
                                                                                | ((0x200000U 
                                                                                & (__Vtemp_h42d7bc1b__0[0U] 
                                                                                >> 2U)) 
                                                                                | ((0x100000U 
                                                                                & (__Vtemp_hafc17311__0[0U] 
                                                                                >> 4U)) 
                                                                                | ((0x80000U 
                                                                                & (__Vtemp_h95c917fc__0[0U] 
                                                                                >> 6U)) 
                                                                                | ((0x40000U 
                                                                                & (__Vtemp_h662c623f__0[0U] 
                                                                                >> 8U)) 
                                                                                | ((0x20000U 
                                                                                & (__Vtemp_he2028f23__0[0U] 
                                                                                >> 0xaU)) 
                                                                                | ((0x10000U 
                                                                                & (__Vtemp_h7049c5bc__0[0U] 
                                                                                >> 0xcU)) 
                                                                                | ((0x8000U 
                                                                                & (__Vtemp_h98d458c4__0[0U] 
                                                                                >> 0xeU)) 
                                                                                | ((0x4000U 
                                                                                & (__Vtemp_h88e5a187__0[0U] 
                                                                                >> 0x10U)) 
                                                                                | ((0x2000U 
                                                                                & (__Vtemp_hd29239e1__0[0U] 
                                                                                >> 0x12U)) 
                                                                                | ((0x1000U 
                                                                                & (__Vtemp_hd703056c__0[1U] 
                                                                                << 0xcU)) 
                                                                                | ((0x800U 
                                                                                & (__Vtemp_h219fb702__0[1U] 
                                                                                << 0xaU)) 
                                                                                | ((0x400U 
                                                                                & (__Vtemp_h1b0c3f2e__0[1U] 
                                                                                << 8U)) 
                                                                                | ((0x200U 
                                                                                & (__Vtemp_h53d5d654__0[1U] 
                                                                                << 6U)) 
                                                                                | ((0x100U 
                                                                                & (__Vtemp_h9a220410__0[1U] 
                                                                                << 4U)) 
                                                                                | ((0x80U 
                                                                                & (__Vtemp_he4186cea__0[1U] 
                                                                                << 2U)) 
                                                                                | ((0x40U 
                                                                                & __Vtemp_h8892cda8__0[1U]) 
                                                                                | ((0x20U 
                                                                                & (__Vtemp_haa4e0269__0[1U] 
                                                                                >> 2U)) 
                                                                                | ((0x10U 
                                                                                & (__Vtemp_h088fc989__0[1U] 
                                                                                >> 4U)) 
                                                                                | ((8U 
                                                                                & (__Vtemp_h3434425e__0[1U] 
                                                                                >> 6U)) 
                                                                                | ((4U 
                                                                                & (__Vtemp_ha70f29fd__0[1U] 
                                                                                >> 8U)) 
                                                                                | ((2U 
                                                                                & (__Vtemp_h5ae7feba__0[1U] 
                                                                                >> 0xaU)) 
                                                                                | (1U 
                                                                                & (__Vtemp_hb19583b4__0[1U] 
                                                                                >> 0xcU))))))))))))))))))))))))))))))))))) 
                                               << 0x13U) 
                                              | (QData)((IData)(
                                                                ((0x40000U 
                                                                  & (__Vtemp_hda056d9f__0[1U] 
                                                                     << 5U)) 
                                                                 | ((0x20000U 
                                                                     & (__Vtemp_hc6263e1a__0[1U] 
                                                                        << 3U)) 
                                                                    | ((0x10000U 
                                                                        & (__Vtemp_h449e8a75__0[1U] 
                                                                           << 1U)) 
                                                                       | ((0x8000U 
                                                                           & (__Vtemp_h15d05d04__0[1U] 
                                                                              >> 1U)) 
                                                                          | ((0x4000U 
                                                                              & (__Vtemp_h58bc3c77__0[1U] 
                                                                                >> 3U)) 
                                                                             | ((0x2000U 
                                                                                & (__Vtemp_h14739508__0[1U] 
                                                                                >> 5U)) 
                                                                                | ((0x1000U 
                                                                                & (__Vtemp_h27fcda8b__0[1U] 
                                                                                >> 7U)) 
                                                                                | ((0x800U 
                                                                                & (__Vtemp_h8ccf991f__0[1U] 
                                                                                >> 9U)) 
                                                                                | ((0x400U 
                                                                                & (__Vtemp_h2490b1c7__0[1U] 
                                                                                >> 0xbU)) 
                                                                                | ((0x200U 
                                                                                & (__Vtemp_h3dfb01ed__0[1U] 
                                                                                >> 0xdU)) 
                                                                                | ((0x100U 
                                                                                & (__Vtemp_h461414ba__0[1U] 
                                                                                >> 0xfU)) 
                                                                                | ((0x80U 
                                                                                & (__Vtemp_h57e618ca__0[1U] 
                                                                                >> 0x11U)) 
                                                                                | ((0x40U 
                                                                                & (__Vtemp_h570b8902__0[1U] 
                                                                                >> 0x13U)) 
                                                                                | ((0x20U 
                                                                                & (__Vtemp_h02f5e130__0[1U] 
                                                                                >> 0x15U)) 
                                                                                | ((0x10U 
                                                                                & (__Vtemp_h0d39d963__0[1U] 
                                                                                >> 0x17U)) 
                                                                                | ((8U 
                                                                                & (__Vtemp_hb8348215__0[1U] 
                                                                                >> 0x19U)) 
                                                                                | ((4U 
                                                                                & (__Vtemp_h861d5df4__0[1U] 
                                                                                >> 0x1bU)) 
                                                                                | ((2U 
                                                                                & (__Vtemp_h572e6077__0[1U] 
                                                                                >> 0x1dU)) 
                                                                                | (__Vtemp_h2e727092__0[1U] 
                                                                                >> 0x1fU))))))))))))))))))))))))) 
                                      << 3U))))) | (QData)((IData)(
                                                                   (1U 
                                                                    & (IData)(
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sig 
                                                                               >> 0x37U))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5171(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5171\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT___nextVal_T 
        = (0xfeU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT__readPtr));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT___nextVal_T_2 
        = (0xffU & ((IData)(1U) + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT__readPtr)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT___nextVal_T 
        = (0xfeU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT__readPtr));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT___nextVal_T_2 
        = (0xffU & ((IData)(1U) + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT__readPtr)));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT____Vcellinp__sfma__io_in_valid) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__in_rm 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma_io_in_bits_req_rm;
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul__DOT__CDom_sign 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_fromPreMul_b_signProd) 
           ^ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_fromPreMul_b_doSubMags));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul__DOT__CDom_absSigSum 
        = (0x3ffffffffffffULL & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_fromPreMul_b_doSubMags)
                                  ? (~ (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul__DOT___sigSum_T_3)) 
                                         << 0x18U) 
                                        | (QData)((IData)(
                                                          (0xffffffU 
                                                           & (IData)(
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_mulAddResult_b 
                                                                      >> 0x18U)))))))
                                  : (((QData)((IData)(
                                                      (3U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_fromPreMul_b_highAlignedSigC 
                                                          >> 0x18U)))) 
                                      << 0x2fU) | (
                                                   ((QData)((IData)(
                                                                    (0xffffffU 
                                                                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul__DOT___sigSum_T_3))) 
                                                    << 0x17U) 
                                                   | (QData)((IData)(
                                                                     (0x7fffffU 
                                                                      & (IData)(
                                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_mulAddResult_b 
                                                                                >> 0x19U)))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul__DOT__notCDom_absSigSum 
        = (0x7ffffffffffffULL & ((4U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul__DOT___sigSum_T_3)
                                  ? (~ (((QData)((IData)(
                                                         (3U 
                                                          & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul__DOT___sigSum_T_3))) 
                                         << 0x31U) 
                                        | ((0x1fffffffffffeULL 
                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_mulAddResult_b 
                                               << 1U)) 
                                           | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_fromPreMul_b_bit0AlignedSigC)))))
                                  : ((((QData)((IData)(
                                                       (3U 
                                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul__DOT___sigSum_T_3))) 
                                       << 0x31U) | 
                                      ((0x1fffffffffffeULL 
                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_mulAddResult_b 
                                           << 1U)) 
                                       | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_fromPreMul_b_bit0AlignedSigC)))) 
                                     + (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_fromPreMul_b_doSubMags)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul__DOT__notNaN_addZeros 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_fromPreMul_b_isZeroA) 
            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_fromPreMul_b_isZeroB)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_fromPreMul_b_isZeroC));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul__DOT__notNaN_isInfProd 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_fromPreMul_b_isInfA) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__mulAddRecFNToRaw_postMul_io_fromPreMul_b_isInfB));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5172(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5172\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_h8107e494__0;
    // Body
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT____Vcellinp__sfma__io_in_valid) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__valid = 1U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__in_in1[0U] 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT____Vcellinp__sfma__io_in_bits_in1[0U];
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__in_in1[1U] 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT____Vcellinp__sfma__io_in_bits_in1[1U];
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__in_in1[2U] 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT____Vcellinp__sfma__io_in_bits_in1[2U];
        if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ex_reg_ctrl_swap23) {
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__in_in2[0U] = 0x80000000U;
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__in_in2[1U] = 0U;
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__in_in2[2U] = 0U;
        } else {
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__in_in2[0U] 
                = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT____Vcellinp__sfma__io_in_bits_in2[0U];
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__in_in2[1U] 
                = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT____Vcellinp__sfma__io_in_bits_in2[1U];
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__in_in2[2U] 
                = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT____Vcellinp__sfma__io_in_bits_in2[2U];
        }
        VL_EXTEND_WQ(65,33, __Vtemp_h8107e494__0, (
                                                   (((QData)((IData)(
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___regfile_ext_R2_data[0U] 
                                                                      >> 0x1fU))) 
                                                     << 0x20U) 
                                                    | (QData)((IData)(
                                                                      ((0x80000000U 
                                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___regfile_ext_R2_data[1U] 
                                                                           << 0xbU)) 
                                                                       | (0x7fffffffU 
                                                                          & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___regfile_ext_R2_data[0U]))))) 
                                                   | ((0x1fU 
                                                       == 
                                                       (0x1fU 
                                                        & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___regfile_ext_R2_data[2U] 
                                                            << 4U) 
                                                           | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___regfile_ext_R2_data[1U] 
                                                              >> 0x1cU))))
                                                       ? 0ULL
                                                       : 0xe0400000ULL)));
        if (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ex_reg_ctrl_ren3) 
             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ex_reg_ctrl_swap23))) {
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__in_in3[0U] 
                = __Vtemp_h8107e494__0[0U];
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__in_in3[1U] 
                = __Vtemp_h8107e494__0[1U];
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__in_in3[2U] 
                = __Vtemp_h8107e494__0[2U];
        } else {
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__in_in3[0U] = 0U;
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__in_in3[1U] 
                = (1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT____Vcellinp__sfma__io_in_bits_in1[1U] 
                         ^ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT____Vcellinp__sfma__io_in_bits_in2[1U]));
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__in_in3[2U] = 0U;
        }
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__valid = 0U;
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT___GEN_1 
        = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__roundRawFNToRecFN_io_in_b_sig 
            >> 1U) & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__sfma__DOT__fma__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT___roundedSig_T_14);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_5 
        = ((0x3ffffffeU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr 
                           << 1U)) | (1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_cfg_a)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_6 
        = ((0x3ffffffeU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr 
                           << 1U)) | (1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_cfg_a)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_7 
        = ((0x3ffffffeU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr 
                           << 1U)) | (1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_cfg_a)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_8 
        = ((0x3ffffffeU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr 
                           << 1U)) | (1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_cfg_a)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5173(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5173\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_9 
        = ((0x3ffffffeU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr 
                           << 1U)) | (1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_cfg_a)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_10 
        = ((0x3ffffffeU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr 
                           << 1U)) | (1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_cfg_a)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_11 
        = ((0x3ffffffeU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_addr 
                           << 1U)) | (1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_cfg_a)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__skipCycle2 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__cycleNum)) 
           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__sigX_Z 
              >> 0x19U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT___fractB_Z_T_25 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__inReady)
            ? 0U : (0x7fffffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__fractB_Z 
                                 >> 1U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT___GEN_2 
        = (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT___divSqrtRecFNToRaw_io_rawOut_sig 
           & (1U | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT___roundMask_T_74 
                    << 1U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT___roundedSig_T_14 
        = ((0x2000000U | (0x1ffffffU & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT___roundMask_T_74))) 
           & (1U | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT___roundMask_T_74 
                    << 1U)));
    if ((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killd)))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_jal 
            = (0x7fU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_52));
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT___nextVal_T_3 
        = (0xfeU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT__writePtr));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT___nextVal_T_5 
        = (0xffU & ((IData)(1U) + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_1__DOT__writePtr)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT___nextVal_T_3 
        = (0xfeU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT__writePtr));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT___nextVal_T_5 
        = (0xffU & ((IData)(1U) + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_0__DOT__writePtr)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT__i2f__DOT__intAsRawFloat_absIn 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT__i2f__DOT__intAsRawFloat_sign)
            ? (- vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT__intValue_res)
            : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT__intValue_res);
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5174(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5174\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT__i2f_1__DOT__intAsRawFloat_absIn 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT__i2f_1__DOT__intAsRawFloat_sign)
            ? (- vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT__intValue_res)
            : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__ifpu__DOT__intValue_res);
    if ((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killd)))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_flush_pipe 
            = (((0x3ffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_58)) 
                | (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_ctrl_csr))) 
               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_csr_en) 
                   & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_csr_ren))) 
                  & (~ ((0x33fU < (0xfffU & (0x300U 
                                             | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                >> 0x14U)))) 
                        & (0x344U > (0xfffU & (0x300U 
                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_bits 
                                                  >> 0x14U))))))));
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_1__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__skipCycle2 
        = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_1__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__cycleNum)) 
           & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_1__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__sigX_Z 
                      >> 0x36U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_typeTag 
        = (1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_1__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__rawOutValid));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_1__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT___fractB_Z_T_25 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_1__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__inReady)
            ? 0ULL : (0xfffffffffffffULL & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_1__DOT__divSqrtRecFNToRaw__DOT__divSqrtRawFN__DOT__fractB_Z 
                                            >> 1U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_1__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT___GEN_1 
        = (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_1__DOT___divSqrtRecFNToRaw_io_rawOut_sig 
           & (1ULL | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_1__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT___roundMask_T_129 
                      << 1U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_1__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT___roundedSig_T_14 
        = ((0x40000000000000ULL | (0x3fffffffffffffULL 
                                   & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_1__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT___roundMask_T_129))) 
           & (1ULL | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__divSqrt_1__DOT__roundRawFNToRecFN__DOT__roundAnyRawFNToRecFN__DOT___roundMask_T_129 
                      << 1U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink__DOT__chain__DOT__output_chain__DOT__sync_1 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink__DOT__chain__DOT__output_chain__DOT__sync_2;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT___nextVal_T 
        = (0xaU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__readPtr));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT___nextVal_T_2 
        = (0xfU & ((IData)(1U) + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_1__DOT__readPtr)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5175(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5175\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT___nextVal_T 
        = (0xaU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__readPtr));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT___nextVal_T_2 
        = (0xfU & ((IData)(1U) + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_csr_0__DOT__readPtr)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT___nextVal_T 
        = (0xaU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__readPtr));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT___nextVal_T_2 
        = (0xfU & ((IData)(1U) + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_1__DOT__readPtr)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT___nextVal_T 
        = (0xaU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__readPtr));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT___nextVal_T_2 
        = (0xfU & ((IData)(1U) + (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__lsl__DOT__u_channel_rocc_0__DOT__readPtr)));
    if ((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killd)))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_csr 
            = (((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_ctrl_csr)) 
                & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_orMatrixOutputs_T_29)))
                ? 0U : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_csr_ren)
                         ? 2U : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_ctrl_csr)));
    }
    if (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_stalld)) 
         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT___T_7))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ibufBTBResp_taken 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_taken;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ibufBTBResp_bridx 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_bridx;
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_valid 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_tileClockGroup_tile_4_reset)) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___io_cpu_req_ready_output) 
              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_mem_req_valid)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__amoalus_0__DOT__wmask 
        = (((QData)((IData)((((- (IData)((1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_mask) 
                                                >> 7U)))) 
                              << 0x18U) | ((0xff0000U 
                                            & ((- (IData)(
                                                          (1U 
                                                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_mask) 
                                                              >> 6U)))) 
                                               << 0x10U)) 
                                           | ((0xff00U 
                                               & ((- (IData)(
                                                             (1U 
                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_mask) 
                                                                 >> 5U)))) 
                                                  << 8U)) 
                                              | (0xffU 
                                                 & (- (IData)(
                                                              (1U 
                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_mask) 
                                                                  >> 4U)))))))))) 
            << 0x20U) | (QData)((IData)((((- (IData)(
                                                     (1U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_mask) 
                                                         >> 3U)))) 
                                          << 0x18U) 
                                         | ((0xff0000U 
                                             & ((- (IData)(
                                                           (1U 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_mask) 
                                                               >> 2U)))) 
                                                << 0x10U)) 
                                            | ((0xff00U 
                                                & ((- (IData)(
                                                              (1U 
                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_mask) 
                                                                  >> 1U)))) 
                                                   << 8U)) 
                                               | (0xffU 
                                                  & (- (IData)(
                                                               (1U 
                                                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_mask)))))))))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5176(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5176\n"); );
    // Body
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s0_clk_en) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_req_cmd 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_mem_req_bits_cmd;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_req_addr 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s0_tlb_req_vaddr;
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__s1_req_tag 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT___req_arb_io_out_bits_tag;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink_3__DOT__chain__DOT__output_chain__DOT__sync_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource_14__DOT__reg_0__DOT__reg_0;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink_2__DOT__chain__DOT__output_chain__DOT__sync_2 
        = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource_13__DOT__reg_0__DOT__reg_0;
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_victimize) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_address 
            = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_flush_line)
                  ? (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_addr 
                             >> 0xbU)) : (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_victim_way_r)
                                            ? 0U : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_meta_corrected_r) 
                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_victim_way_r)
                                              ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_meta_corrected_r_1
                                              : 0U))) 
                << 0xbU) | (0x7c0U & ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_addr 
                                               >> 6U)) 
                                      << 6U)));
    } else if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___probe_bits_T) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__probe_bits_address 
            = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[3U] 
                << 0x17U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[2U] 
                             >> 9U));
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_62) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__uncachedReqs_0_addr 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_addr;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___T_256) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__lrscAddr 
            = (0x3ffffffffULL & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_addr 
                                 >> 6U));
    }
    if ((1U & (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killd)) 
                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___csr_io_interrupt)) 
               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_replay)))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_btb_resp_bht_history 
            = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT___T_23)
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ibuf__DOT__ibufBTBResp_bht_history)
                : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___frontend_io_cpu_resp_bits_btb_bht_history));
    }
    if ((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killd)))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_branch 
            = ((0xffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_44)) 
               | (0xffU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___id_ctrl_decoder_decoded_T_126)));
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___mem_cfi_taken_T 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_ctrl_branch) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_br_taken));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_kill_speculative_tlb_refill 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_speculative) 
           & (~ (IData)((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__recent_progress_counter)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5177(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5177\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink_1__DOT__chain__DOT__output_chain_1__DOT__sync_2 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource_12__DOT__reg_0__DOT__reg_0) 
                 >> 1U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__pending_interrupts 
        = (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___GEN_3 
           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_mie);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__intsink_1__DOT__chain__DOT__output_chain__DOT__sync_2 
        = (1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__intsource_12__DOT__reg_0__DOT__reg_0));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__if_check_completed 
        = (0xcU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__checking_counter_memdelay));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT___T_442 
        = (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__shadow_status));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_uncached 
        = (1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_pma_cacheable)) 
                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_no_alloc) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_pma_must_alloc))) 
                    & (~ (IData)((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_hit_state_state)))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___T_58 
        = ((((((((((((((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd)) 
                       | (0x11U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                      | (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                     | (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                    | (9U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                   | (0xaU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                  | (0xbU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                 | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                | (0xcU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
               | (0xdU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
              | (0xeU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
             | (0xfU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
            << 3U) | ((((((((((((((((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd)) 
                                    | (0x11U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                                   | (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                                  | (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                                 | (9U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                                | (0xaU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                               | (0xbU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                              | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                             | (0xcU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                            | (0xdU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                           | (0xeU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                          | (0xfU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                         | (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                        | (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd))) 
                       << 2U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_hit_state_state)));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5178(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5178\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_0 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [0U][2U] << 0x1fU) | 
                             ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [0U][1U] 
                                                            >> 0x14U))
                                                 ? 0U
                                                 : 
                                                ((IData)(0x3ffU) 
                                                 + 
                                                 ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [0U][1U] 
                                                   << 0xcU) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [0U][1U] 
                                                     >> 0x14U)))) 
                                               | (- (IData)(
                                                            (((3U 
                                                               == 
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0U][1U] 
                                                                >> 0x1eU)) 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0U][1U] 
                                                                 >> 0x1dU)) 
                                                             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_0_unrecoded_rawIn_isInf))))) 
                                              << 0x14U)) 
                              | (0xfffffU & (IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_0_unrecoded_fractOut 
                                                     >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [0U][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [0U][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_0_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [0U][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [0U][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_0_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0U][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_0_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_0_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0U][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [0U][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [0U][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [0U][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [0U][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_0_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [0U][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_0_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5179(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5179\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_1 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [1U][2U] << 0x1fU) | 
                             ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [1U][1U] 
                                                            >> 0x14U))
                                                 ? 0U
                                                 : 
                                                ((IData)(0x3ffU) 
                                                 + 
                                                 ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [1U][1U] 
                                                   << 0xcU) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [1U][1U] 
                                                     >> 0x14U)))) 
                                               | (- (IData)(
                                                            (((3U 
                                                               == 
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [1U][1U] 
                                                                >> 0x1eU)) 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [1U][1U] 
                                                                 >> 0x1dU)) 
                                                             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_1_unrecoded_rawIn_isInf))))) 
                                              << 0x14U)) 
                              | (0xfffffU & (IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_1_unrecoded_fractOut 
                                                     >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [1U][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [1U][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_1_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [1U][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [1U][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_1_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [1U][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_1_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_1_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [1U][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [1U][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [1U][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [1U][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [1U][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_1_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [1U][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_1_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5180(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5180\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_2 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [2U][2U] << 0x1fU) | 
                             ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [2U][1U] 
                                                            >> 0x14U))
                                                 ? 0U
                                                 : 
                                                ((IData)(0x3ffU) 
                                                 + 
                                                 ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [2U][1U] 
                                                   << 0xcU) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [2U][1U] 
                                                     >> 0x14U)))) 
                                               | (- (IData)(
                                                            (((3U 
                                                               == 
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [2U][1U] 
                                                                >> 0x1eU)) 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [2U][1U] 
                                                                 >> 0x1dU)) 
                                                             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_2_unrecoded_rawIn_isInf))))) 
                                              << 0x14U)) 
                              | (0xfffffU & (IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_2_unrecoded_fractOut 
                                                     >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [2U][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [2U][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_2_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [2U][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [2U][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_2_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [2U][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_2_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_2_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [2U][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [2U][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [2U][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [2U][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [2U][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_2_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [2U][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_2_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5181(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5181\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_3 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [3U][2U] << 0x1fU) | 
                             ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [3U][1U] 
                                                            >> 0x14U))
                                                 ? 0U
                                                 : 
                                                ((IData)(0x3ffU) 
                                                 + 
                                                 ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [3U][1U] 
                                                   << 0xcU) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [3U][1U] 
                                                     >> 0x14U)))) 
                                               | (- (IData)(
                                                            (((3U 
                                                               == 
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [3U][1U] 
                                                                >> 0x1eU)) 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [3U][1U] 
                                                                 >> 0x1dU)) 
                                                             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_3_unrecoded_rawIn_isInf))))) 
                                              << 0x14U)) 
                              | (0xfffffU & (IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_3_unrecoded_fractOut 
                                                     >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [3U][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [3U][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_3_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [3U][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [3U][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_3_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [3U][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_3_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_3_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [3U][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [3U][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [3U][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [3U][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [3U][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_3_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [3U][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_3_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5182(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5182\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_4 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [4U][2U] << 0x1fU) | 
                             ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [4U][1U] 
                                                            >> 0x14U))
                                                 ? 0U
                                                 : 
                                                ((IData)(0x3ffU) 
                                                 + 
                                                 ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [4U][1U] 
                                                   << 0xcU) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [4U][1U] 
                                                     >> 0x14U)))) 
                                               | (- (IData)(
                                                            (((3U 
                                                               == 
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [4U][1U] 
                                                                >> 0x1eU)) 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [4U][1U] 
                                                                 >> 0x1dU)) 
                                                             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_4_unrecoded_rawIn_isInf))))) 
                                              << 0x14U)) 
                              | (0xfffffU & (IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_4_unrecoded_fractOut 
                                                     >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [4U][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [4U][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_4_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [4U][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [4U][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_4_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [4U][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_4_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_4_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [4U][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [4U][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [4U][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [4U][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [4U][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_4_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [4U][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_4_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5183(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5183\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_5 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [5U][2U] << 0x1fU) | 
                             ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [5U][1U] 
                                                            >> 0x14U))
                                                 ? 0U
                                                 : 
                                                ((IData)(0x3ffU) 
                                                 + 
                                                 ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [5U][1U] 
                                                   << 0xcU) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [5U][1U] 
                                                     >> 0x14U)))) 
                                               | (- (IData)(
                                                            (((3U 
                                                               == 
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [5U][1U] 
                                                                >> 0x1eU)) 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [5U][1U] 
                                                                 >> 0x1dU)) 
                                                             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_5_unrecoded_rawIn_isInf))))) 
                                              << 0x14U)) 
                              | (0xfffffU & (IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_5_unrecoded_fractOut 
                                                     >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [5U][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [5U][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_5_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [5U][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [5U][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_5_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [5U][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_5_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_5_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [5U][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [5U][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [5U][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [5U][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [5U][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_5_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [5U][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_5_unrecoded_fractOut)))));
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__5184(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__5184\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___fpuOpt_io_farfs_6 
        = (((QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                              [6U][2U] << 0x1fU) | 
                             ((0x7ff00000U & (((VL_GTS_III(13, 0x402U, 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                            [6U][1U] 
                                                            >> 0x14U))
                                                 ? 0U
                                                 : 
                                                ((IData)(0x3ffU) 
                                                 + 
                                                 ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                   [6U][1U] 
                                                   << 0xcU) 
                                                  | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                     [6U][1U] 
                                                     >> 0x14U)))) 
                                               | (- (IData)(
                                                            (((3U 
                                                               == 
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [6U][1U] 
                                                                >> 0x1eU)) 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [6U][1U] 
                                                                 >> 0x1dU)) 
                                                             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_6_unrecoded_rawIn_isInf))))) 
                                              << 0x14U)) 
                              | (0xfffffU & (IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_6_unrecoded_fractOut 
                                                     >> 0x20U))))))) 
            << 0x20U) | (QData)((IData)(((7U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                 [6U][1U] 
                                                 >> 0x1dU))
                                          ? ((0x80000000U 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                              [6U][0U]) 
                                             | ((0x7f800000U 
                                                 & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_6_prevUnrecoded_isSubnormal)
                                                       ? 0U
                                                       : 
                                                      ((IData)(0x7fU) 
                                                       + 
                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                         [6U][0U] 
                                                         << 9U) 
                                                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                           [6U][0U] 
                                                           >> 0x17U)))) 
                                                     | (- (IData)(
                                                                  (((3U 
                                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT___io_farfs_6_prevUnrecoded_rawIn_isSpecial_T)) 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [6U][0U] 
                                                                       >> 0x1dU)) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_6_prevUnrecoded_rawIn_isInf))))) 
                                                    << 0x17U)) 
                                                | (0x7fffffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_6_prevUnrecoded_isSubnormal)
                                                       ? 
                                                      (0xffffffU 
                                                       & (((0x400000U 
                                                            & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [6U][1U] 
                                                                 >> 0x14U) 
                                                                | (0U 
                                                                   != 
                                                                   (3U 
                                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                       [6U][0U] 
                                                                       >> 0x1dU)))) 
                                                               << 0x16U)) 
                                                           | (0x3fffffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                 [6U][0U] 
                                                                 >> 1U))) 
                                                          >> 
                                                          (0x1fU 
                                                           & ((IData)(1U) 
                                                              - 
                                                              ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                [6U][0U] 
                                                                << 9U) 
                                                               | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                                  [6U][0U] 
                                                                  >> 0x17U))))))
                                                       : 
                                                      ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_6_prevUnrecoded_rawIn_isInf)
                                                        ? 0U
                                                        : 
                                                       vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__regfile_ext__DOT__Memory
                                                       [6U][0U])))))
                                          : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__io_farfs_6_unrecoded_fractOut)))));
}
