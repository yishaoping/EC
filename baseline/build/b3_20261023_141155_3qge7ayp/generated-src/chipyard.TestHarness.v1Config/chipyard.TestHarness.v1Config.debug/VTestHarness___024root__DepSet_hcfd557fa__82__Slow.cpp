// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTestHarness.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTestHarness___024root.h"

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4326(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4326\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__u_channel__DOT___T_10 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__do_check) 
              & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter))) 
             & (0x1fU != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay))) 
            & (((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN[
                                  (((IData)(0x3fU) 
                                    + (0x7c0U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay) 
                                                 << 6U))) 
                                   >> 5U)])) << 0x20U) 
                 | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN[
                                   (0x3eU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay) 
                                             << 1U))]))) 
                != ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ECP_ext__DOT___GEN)
                     ? ((0x20U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ECP_ext__DOT___GEN_0))
                         ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ECP_ext__DOT__Memory
                        [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ECP_ext__DOT___GEN_0]
                         : 0ULL) : 0ULL)) | ((((QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN_0[
                                                               (((IData)(0x3fU) 
                                                                 + 
                                                                 (0x7c0U 
                                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay) 
                                                                     << 6U))) 
                                                                >> 5U)])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN_0[
                                                                (0x3eU 
                                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay) 
                                                                    << 1U))]))) 
                                             != ((0x20U 
                                                  >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss_ECP__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram_R_0_addr_pipe_0))
                                                  ? 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss_ECP__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram
                                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss_ECP__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram_R_0_addr_pipe_0]
                                                  : 0ULL)))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__u_channel__DOT__fullReg)));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___T_258) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__id_rs_0 
            = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1))
                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rf_gp
                : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1))
                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rf_sp
                    : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_4));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__id_rs_1 
            = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2))
                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rf_gp
                : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2))
                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rf_sp
                    : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_5));
    } else if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___T_335) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__id_rs_0 
            = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1))
                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rf_gp
                : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1))
                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rf_sp
                    : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_4));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__id_rs_1 
            = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2))
                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rf_gp
                : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2))
                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rf_sp
                    : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_5));
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__id_rs_0 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_4;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__id_rs_1 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_5;
    }
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4327(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4327\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__u_channel__DOT___T_10 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__do_check) 
              & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter))) 
             & (0x1fU != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay))) 
            & (((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN[
                                  (((IData)(0x3fU) 
                                    + (0x7c0U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay) 
                                                 << 6U))) 
                                   >> 5U)])) << 0x20U) 
                 | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN[
                                   (0x3eU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay) 
                                             << 1U))]))) 
                != ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ECP_ext__DOT___GEN)
                     ? ((0x20U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ECP_ext__DOT___GEN_0))
                         ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ECP_ext__DOT__Memory
                        [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ECP_ext__DOT___GEN_0]
                         : 0ULL) : 0ULL)) | ((((QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN_0[
                                                               (((IData)(0x3fU) 
                                                                 + 
                                                                 (0x7c0U 
                                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay) 
                                                                     << 6U))) 
                                                                >> 5U)])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN_0[
                                                                (0x3eU 
                                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay) 
                                                                    << 1U))]))) 
                                             != ((0x20U 
                                                  >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss_ECP__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram_R_0_addr_pipe_0))
                                                  ? 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss_ECP__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram
                                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss_ECP__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram_R_0_addr_pipe_0]
                                                  : 0ULL)))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__u_channel__DOT__fullReg)));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_258) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_rs_0 
            = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1))
                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rf_gp
                : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1))
                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rf_sp
                    : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_4));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_rs_1 
            = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2))
                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rf_gp
                : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2))
                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rf_sp
                    : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_5));
    } else if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___T_335) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_rs_0 
            = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1))
                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rf_gp
                : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_inst_rs1))
                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rf_sp
                    : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_4));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_rs_1 
            = ((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2))
                ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rf_gp
                : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_raddr2))
                    ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rf_sp
                    : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_5));
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_rs_0 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_4;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__id_rs_1 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___GEN_5;
    }
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4328(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4328\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__u_channel__DOT___T_10 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__do_check) 
              & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter))) 
             & (0x1fU != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay))) 
            & (((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN[
                                  (((IData)(0x3fU) 
                                    + (0x7c0U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay) 
                                                 << 6U))) 
                                   >> 5U)])) << 0x20U) 
                 | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN[
                                   (0x3eU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay) 
                                             << 1U))]))) 
                != ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ECP_ext__DOT___GEN)
                     ? ((0x20U >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ECP_ext__DOT___GEN_0))
                         ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ECP_ext__DOT__Memory
                        [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__arfs_ss_ECP_ext__DOT___GEN_0]
                         : 0ULL) : 0ULL)) | ((((QData)((IData)(
                                                               vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN_0[
                                                               (((IData)(0x3fU) 
                                                                 + 
                                                                 (0x7c0U 
                                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay) 
                                                                     << 6U))) 
                                                                >> 5U)])) 
                                               << 0x20U) 
                                              | (QData)((IData)(
                                                                vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT___GEN_0[
                                                                (0x3eU 
                                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__checking_counter_memdelay) 
                                                                    << 1U))]))) 
                                             != ((0x20U 
                                                  >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss_ECP__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram_R_0_addr_pipe_0))
                                                  ? 
                                                 vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss_ECP__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram
                                                 [vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__farfs_ss_ECP__DOT__farfs_ss_ext__DOT__mem_0_0__DOT__ram_R_0_addr_pipe_0]
                                                  : 0ULL)))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__rsu_slave__DOT__u_channel__DOT__fullReg)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_42 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_41)
                  ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill))
                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_0_valid_0)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_44 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_43)
                  ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill))
                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_1_valid_0)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_46 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_45)
                  ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill))
                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_2_valid_0)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_48 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_47)
                  ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill))
                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_3_valid_0)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_54 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_50)
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_0)
            : ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill)) 
               & ((0U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag)) 
                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_sectored_hit_valid) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_0)))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4329(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4329\n"); );
    // Body
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_50) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_55 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_1;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_56 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_2;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_57 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_3;
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_55 
            = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill)) 
               & ((1U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag)) 
                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_sectored_hit_valid) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_1))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_56 
            = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill)) 
               & ((2U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag)) 
                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_sectored_hit_valid) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_2))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_57 
            = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill)) 
               & ((3U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag)) 
                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_sectored_hit_valid) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_3))));
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__s0_req_fire 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT___io_requestor_1_req_ready_output) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_requestor_2_req_ready 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT___io_requestor_1_req_ready_output) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__valid 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__source_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx) 
              != (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0) 
                   << 3U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0) 
                              << 2U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0) 
                                         << 1U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index 
        = (7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx) 
                 ^ (4U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx) 
                          >> 1U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___BJL_io_bj_rollback_T_2 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem_wb) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_imem_checker_mode)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_imem_if_check_completed)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killd 
        = (1U & (((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_valid)) 
                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_replay)) 
                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem_wb)) 
                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_stalld)) 
                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___csr_io_interrupt)));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4330(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4330\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s0_valid 
        = (1U & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem_wb) 
                  | (((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___fq_io_mask) 
                          >> 2U)) | ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___fq_io_mask) 
                                         >> 3U)) & 
                                     ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_valid)) 
                                      | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_valid))))) 
                     | (((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___fq_io_mask) 
                             >> 4U)) & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_valid))) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_valid))))) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___icsl_io_icsl_stalld) 
                        & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__fsm_state))) 
                       | (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__fsm_state))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_redirect 
        = ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_106)) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__taken_2)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_116)) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem_wb));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_42 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_41)
                  ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill))
                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_0_valid_0)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_44 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_43)
                  ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill))
                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_1_valid_0)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_46 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_45)
                  ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill))
                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_2_valid_0)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_48 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_47)
                  ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill))
                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_3_valid_0)));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_50) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_54 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_0;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_55 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_1;
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_54 
            = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill)) 
               & ((0U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag)) 
                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_sectored_hit_valid) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_0))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_55 
            = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill)) 
               & ((1U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag)) 
                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_sectored_hit_valid) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_1))));
    }
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4331(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4331\n"); );
    // Body
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_50) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_56 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_2;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_57 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_3;
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_56 
            = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill)) 
               & ((2U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag)) 
                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_sectored_hit_valid) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_2))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_57 
            = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill)) 
               & ((3U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag)) 
                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_sectored_hit_valid) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_3))));
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__s0_req_fire 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT___io_requestor_1_req_ready_output) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_requestor_2_req_ready 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT___io_requestor_1_req_ready_output) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__valid 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__source_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx) 
              != (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0) 
                   << 3U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0) 
                              << 2U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0) 
                                         << 1U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index 
        = (7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx) 
                 ^ (4U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx) 
                          >> 1U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT___BJL_io_bj_rollback_T_2 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem_wb) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_imem_checker_mode)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_imem_if_check_completed)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killd 
        = (1U & (((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_valid)) 
                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_replay)) 
                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem_wb)) 
                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_stalld)) 
                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT___csr_io_interrupt)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s0_valid 
        = (1U & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem_wb) 
                  | (((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT___fq_io_mask) 
                          >> 2U)) | ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT___fq_io_mask) 
                                         >> 3U)) & 
                                     ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_valid)) 
                                      | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_valid))))) 
                     | (((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT___fq_io_mask) 
                             >> 4U)) & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_valid))) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_valid))))) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT___icsl_io_icsl_stalld) 
                        & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__fsm_state))) 
                       | (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__fsm_state))))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4332(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4332\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_redirect 
        = ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_106)) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__taken_2)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_116)) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem_wb));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_42 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_41)
                  ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill))
                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_0_valid_0)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_44 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_43)
                  ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill))
                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_1_valid_0)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_46 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_45)
                  ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill))
                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_2_valid_0)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_48 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_47)
                  ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill))
                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_3_valid_0)));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_50) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_54 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_0;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_55 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_1;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_56 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_2;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_57 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_3;
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_54 
            = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill)) 
               & ((0U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag)) 
                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_sectored_hit_valid) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_0))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_55 
            = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill)) 
               & ((1U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag)) 
                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_sectored_hit_valid) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_1))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_56 
            = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill)) 
               & ((2U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag)) 
                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_sectored_hit_valid) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_2))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_57 
            = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill)) 
               & ((3U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag)) 
                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_sectored_hit_valid) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_3))));
    }
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4333(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4333\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__s0_req_fire 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT___io_requestor_1_req_ready_output) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_requestor_2_req_ready 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT___io_requestor_1_req_ready_output) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__valid 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__source_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx) 
              != (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0) 
                   << 3U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0) 
                              << 2U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0) 
                                         << 1U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index 
        = (7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx) 
                 ^ (4U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx) 
                          >> 1U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___BJL_io_bj_rollback_T_2 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem_wb) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_imem_checker_mode)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_imem_if_check_completed)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killd 
        = (1U & (((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_valid)) 
                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_replay)) 
                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem_wb)) 
                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_stalld)) 
                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___csr_io_interrupt)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s0_valid 
        = (1U & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem_wb) 
                  | (((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___fq_io_mask) 
                          >> 2U)) | ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___fq_io_mask) 
                                         >> 3U)) & 
                                     ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_valid)) 
                                      | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_valid))))) 
                     | (((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___fq_io_mask) 
                             >> 4U)) & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_valid))) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_valid))))) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___icsl_io_icsl_stalld) 
                        & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__fsm_state))) 
                       | (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__fsm_state))))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4334(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4334\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_redirect 
        = ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_106)) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__taken_2)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_116)) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem_wb));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_42 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_41)
                  ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill))
                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_0_valid_0)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_44 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_43)
                  ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill))
                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_1_valid_0)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_46 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_45)
                  ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill))
                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_2_valid_0)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_48 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_47)
                  ? (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill))
                  : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_superpage_entries_3_valid_0)));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_50) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_54 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_0;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_55 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_1;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_56 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_2;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_57 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_3;
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_54 
            = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill)) 
               & ((0U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag)) 
                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_sectored_hit_valid) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_0))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_55 
            = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill)) 
               & ((1U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag)) 
                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_sectored_hit_valid) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_1))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_56 
            = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill)) 
               & ((2U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag)) 
                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_sectored_hit_valid) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_2))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___GEN_57 
            = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_invalidate_refill)) 
               & ((3U == (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_refill_tag)) 
                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_r_sectored_hit_valid) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__tlb_sectored_entries_0_0_valid_3))));
    }
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4335(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4335\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__s0_req_fire 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT___io_requestor_1_req_ready_output) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_requestor_2_req_ready 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcacheArb__DOT___io_requestor_1_req_ready_output) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcIF__DOT__replayq__DOT___io_replay_valid_output)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__valid 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__source_valid__DOT__io_out_sink_valid_0__DOT__output_chain__DOT__sync_0) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx) 
              != (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain_3__DOT__sync_0) 
                   << 3U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain_2__DOT__sync_0) 
                              << 2U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain_1__DOT__sync_0) 
                                         << 1U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__widx_widx_gray__DOT__output_chain__DOT__sync_0))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index 
        = (7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx) 
                 ^ (4U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__asource__DOT__bundleIn_0_b_sink__DOT__ridx) 
                          >> 1U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___BJL_io_bj_rollback_T_2 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem_wb) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_imem_checker_mode)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_imem_if_check_completed)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_killd 
        = (1U & (((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_valid)) 
                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___ibuf_io_inst_0_bits_replay)) 
                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem_wb)) 
                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__ctrl_stalld)) 
                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___csr_io_interrupt)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s0_valid 
        = (1U & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem_wb) 
                  | (((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___fq_io_mask) 
                          >> 2U)) | ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___fq_io_mask) 
                                         >> 3U)) & 
                                     ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_valid)) 
                                      | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_valid))))) 
                     | (((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___fq_io_mask) 
                             >> 4U)) & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s1_valid))) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_valid))))) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___icsl_io_icsl_stalld) 
                        & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__fsm_state))) 
                       | (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__fsm_state))))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4336(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4336\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__0;
    VlWide<4>/*127:0*/ __Vtemp_h74ad3fd3__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__1;
    VlWide<4>/*127:0*/ __Vtemp_h8777d4e5__0;
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__s2_redirect 
        = ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_106)) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__taken_2)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT___T_116)) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__take_pc_mem_wb));
    __Vtemp_hc961d23f__0[0U] = 1U;
    __Vtemp_hc961d23f__0[1U] = 0U;
    __Vtemp_hc961d23f__0[2U] = 0U;
    __Vtemp_hc961d23f__0[3U] = 0U;
    VL_SHIFTL_WWI(128,128,7, __Vtemp_h74ad3fd3__0, __Vtemp_hc961d23f__0, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__freelist__DOT__r_sel));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__freelist__DOT___GEN_17[0U] 
        = (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__freelist__DOT___GEN_16[0U] 
           | (__Vtemp_h74ad3fd3__0[0U] & (- (IData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__ren2_alloc_reqs_0)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__freelist__DOT___GEN_17[1U] 
        = (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__freelist__DOT___GEN_16[1U] 
           | (__Vtemp_h74ad3fd3__0[1U] & (- (IData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__ren2_alloc_reqs_0)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__freelist__DOT___GEN_17[2U] 
        = (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__freelist__DOT___GEN_16[2U] 
           | (__Vtemp_h74ad3fd3__0[2U] & (- (IData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__ren2_alloc_reqs_0)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__freelist__DOT___GEN_17[3U] 
        = (0xfU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__freelist__DOT___GEN_16[3U] 
                   | (__Vtemp_h74ad3fd3__0[3U] & (- (IData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__ren2_alloc_reqs_0))))));
    __Vtemp_hc961d23f__1[0U] = 1U;
    __Vtemp_hc961d23f__1[1U] = 0U;
    __Vtemp_hc961d23f__1[2U] = 0U;
    __Vtemp_hc961d23f__1[3U] = 0U;
    VL_SHIFTL_WWI(128,128,7, __Vtemp_h8777d4e5__0, __Vtemp_hc961d23f__1, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__freelist__DOT__r_sel));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__freelist__DOT___GEN_17[0U] 
        = (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__freelist__DOT___GEN_16[0U] 
           | (__Vtemp_h8777d4e5__0[0U] & (- (IData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__ren2_alloc_reqs_0)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__freelist__DOT___GEN_17[1U] 
        = (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__freelist__DOT___GEN_16[1U] 
           | (__Vtemp_h8777d4e5__0[1U] & (- (IData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__ren2_alloc_reqs_0)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__freelist__DOT___GEN_17[2U] 
        = (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__freelist__DOT___GEN_16[2U] 
           | (__Vtemp_h8777d4e5__0[2U] & (- (IData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_rename_stage__DOT__ren2_alloc_reqs_0)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT___GEN_90 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__enq_val) 
           & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rxq_tail)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT___GEN_92 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__enq_val) 
           & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rxq_tail)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT___GEN_94 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__enq_val) 
           & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rxq_tail)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT___GEN_96 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__enq_val) 
           & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rxq_tail)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT___GEN_179 = 0U;
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT___GEN_163 
        = ((0x1bU >= (0x1fU & ((IData)(7U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rocc_idx))))
            ? (0x7fU & ((0x8080U | ((0xf800000U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_tail_idx) 
                                                   << 0x15U)) 
                                    | ((0x1f0000U & 
                                        ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_tail_idx) 
                                         << 0xeU)) 
                                       | ((0x3e00U 
                                           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_tail_idx) 
                                              << 7U)) 
                                          | (0x7cU 
                                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_tail_idx)))))) 
                        >> (0x1fU & ((IData)(7U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr_exe_unit__DOT__rocc__DOT__rocc_idx)))))
            : 0U);
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4350(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4350\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1116 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1092) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_923)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_802)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_1_bits_committed));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1117 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1093) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_924)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_803)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_2_bits_committed));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1118 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1094) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_925)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_804)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_3_bits_committed));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1119 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1095) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_926)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_805)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_4_bits_committed));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1120 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1096) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_927)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_806)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_5_bits_committed));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1121 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1097) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_928)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_807)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_6_bits_committed));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1122 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1098) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_929)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_808)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_7_bits_committed));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1123 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1099) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_930)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_809)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_8_bits_committed));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1124 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1100) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_931)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_810)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_9_bits_committed));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1125 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1101) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_932)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_811)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_10_bits_committed));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1126 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1102) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_933)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_812)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_11_bits_committed));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1127 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1103) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_934)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_813)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_12_bits_committed));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4351(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4351\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1128 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1104) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_935)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_814)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_13_bits_committed));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1129 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1105) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_936)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_815)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_14_bits_committed));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1130 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1106) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_937)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_816)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_15_bits_committed));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1131 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1107) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_938)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_817)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_16_bits_committed));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1132 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1108) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_939)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_818)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_17_bits_committed));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1133 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1109) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_940)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_819)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_18_bits_committed));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1134 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1110) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_941)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_820)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_19_bits_committed));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1135 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1111) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_942)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_821)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_20_bits_committed));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1136 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1112) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_943)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_822)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_21_bits_committed));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1137 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1113) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_944)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_823)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_22_bits_committed));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1138 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1114) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_945)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_824)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_23_bits_committed));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__ll_wbarb_io_in_0_bits_data_rawIn_adjustedExp_1 
        = (0x1ffU & (((0U == (0xffU & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT___GEN 
                                               >> 0x17U))))
                       ? (0x1e0U | (0x1fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__ll_wbarb_io_in_0_bits_data_rawIn_normDist_1))))
                       : (0xffU & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT___GEN 
                                           >> 0x17U)))) 
                     + (0x80U | ((0U == (0xffU & (IData)(
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT___GEN 
                                                          >> 0x17U))))
                                  ? 2U : 1U))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4352(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4352\n"); );
    // Init
    VlWide<4>/*127:0*/ __Vtemp_h1d65a827__0;
    VlWide<4>/*127:0*/ __Vtemp_hdfd7e8d3__0;
    // Body
    VL_EXTEND_WQ(115,52, __Vtemp_h1d65a827__0, (0xfffffffffffffULL 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT___GEN));
    VL_SHIFTL_WWI(115,115,6, __Vtemp_hdfd7e8d3__0, __Vtemp_h1d65a827__0, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__ll_wbarb_io_in_0_bits_data_rawIn_normDist));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT___ll_wbarb_io_in_0_bits_data_rawIn_out_sig_T_1 
        = (0xfffffffffffffULL & ((0U == (0x7ffU & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT___GEN 
                                                           >> 0x34U))))
                                  ? (0xffffffffffffeULL 
                                     & (((QData)((IData)(
                                                         __Vtemp_hdfd7e8d3__0[1U])) 
                                         << 0x21U) 
                                        | ((QData)((IData)(
                                                           __Vtemp_hdfd7e8d3__0[0U])) 
                                           << 1U)))
                                  : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT___GEN));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__ll_wbarb_io_in_0_bits_data_rawIn_adjustedExp 
        = (0xfffU & (((0U == (0x7ffU & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT___GEN 
                                                >> 0x34U))))
                       ? (0xfc0U | (0x3fU & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__ll_wbarb_io_in_0_bits_data_rawIn_normDist))))
                       : (0x7ffU & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT___GEN 
                                            >> 0x34U)))) 
                     + (0x400U | ((0U == (0x7ffU & (IData)(
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT___GEN 
                                                            >> 0x34U))))
                                   ? 2U : 1U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_857 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_859 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (4U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_861 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (8U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_863 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0xcU == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_865 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x10U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4353(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4353\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_867 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x14U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_869 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x18U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_871 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x1cU == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_873 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x20U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_875 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x24U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_877 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x28U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_879 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x2cU == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_881 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x30U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_883 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x34U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_885 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x38U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_887 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x3cU == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4354(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4354\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_889 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x40U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_891 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x44U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_893 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x48U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_895 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x4cU == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_897 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x50U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_899 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x54U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_901 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x58U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_903 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x5cU == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_905 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x60U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_907 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x64U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_909 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x68U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4355(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4355\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_911 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x6cU == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_913 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x70U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_915 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x74U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_917 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x78U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_918 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_39) 
           & (0x7cU == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1679 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1680 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (4U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1681 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (8U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1682 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0xcU == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1683 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x10U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1684 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x14U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4356(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4356\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1685 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x18U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1686 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x1cU == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1687 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x20U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1688 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x24U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1689 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x28U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1690 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x2cU == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1691 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x30U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1692 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x34U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1693 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x38U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1694 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x3cU == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1695 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x40U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4357(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4357\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1696 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x44U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1697 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x48U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1698 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x4cU == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1699 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x50U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1700 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x54U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1701 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x58U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1702 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x5cU == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1703 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x60U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1704 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x64U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1705 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x68U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1706 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x6cU == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4358(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4358\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1707 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x70U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1708 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x74U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1709 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x78U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1710 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_472) 
           & (0x7cU == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2223 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2224 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (4U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2225 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (8U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2226 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0xcU == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2227 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x10U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2228 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x14U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2229 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x18U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4359(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4359\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2230 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x1cU == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2231 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x20U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2232 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x24U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2233 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x28U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2234 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x2cU == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2235 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x30U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2236 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x34U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2237 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x38U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2238 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x3cU == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2239 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x40U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2240 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x44U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4360(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4360\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2241 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x48U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2242 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x4cU == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2243 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x50U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2244 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x54U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2245 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x58U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2246 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x5cU == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2247 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x60U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2248 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x64U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2249 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x68U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2250 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x6cU == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2251 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x70U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4361(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4361\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2252 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x74U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2253 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x78U == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_2254 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___T_905) 
           & (0x7cU == (0x7cU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_wakeups_0_bits_uop_rob_idx))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_0__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_0__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_0__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_0__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_0__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_0__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_0__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_0__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_0__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_0__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_0__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_0__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_0__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_0__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_0__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_0__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_1__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_1__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_1__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_1__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_1__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_1__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_1__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_1__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_1__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_1__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_1__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_1__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_1__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_1__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_1__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_1__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_2__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_2__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_2__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_2__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_2__DOT__p1)))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4362(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4362\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_2__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_2__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_2__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_2__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_2__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_2__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_2__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_2__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_2__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_2__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_2__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__issue_slots_0_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_2))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_3_io_will_be_valid)
            : ((2U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_1)))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_2_io_will_be_valid)
                : ((~ (IData)((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_0__DOT__state)))) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_1_io_will_be_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__issue_slots_1_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_3))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_4_io_will_be_valid)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_2))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_3_io_will_be_valid)
                : ((1U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_1))) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_2_io_will_be_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__issue_slots_2_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_4))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_5_io_will_be_valid)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_3))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_4_io_will_be_valid)
                : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_2)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_3_io_will_be_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__issue_slots_3_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_5))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_6_io_will_be_valid)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_4))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_5_io_will_be_valid)
                : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_3)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_4_io_will_be_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__issue_slots_4_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_6))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_7_io_will_be_valid)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_5))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_6_io_will_be_valid)
                : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_4)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_5_io_will_be_valid))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4363(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4363\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__issue_slots_5_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_7))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_8_io_will_be_valid)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_6))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_7_io_will_be_valid)
                : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_5)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_6_io_will_be_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__issue_slots_6_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_8))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_9_io_will_be_valid)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_7))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_8_io_will_be_valid)
                : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_6)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_7_io_will_be_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__issue_slots_7_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_9))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_10_io_will_be_valid)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_8))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_9_io_will_be_valid)
                : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_7)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_8_io_will_be_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__issue_slots_8_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_10))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_11_io_will_be_valid)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_9))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_10_io_will_be_valid)
                : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_8)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_9_io_will_be_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__issue_slots_9_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_11))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_12_io_will_be_valid)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_10))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_11_io_will_be_valid)
                : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_9)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_10_io_will_be_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__issue_slots_10_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_12))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_13_io_will_be_valid)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_11))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_12_io_will_be_valid)
                : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_10)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_11_io_will_be_valid))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4364(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4364\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__issue_slots_11_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_13))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_14_io_will_be_valid)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_12))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_13_io_will_be_valid)
                : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_11)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_12_io_will_be_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__issue_slots_12_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_14))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_15_io_will_be_valid)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_13))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_14_io_will_be_valid)
                : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_12)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_13_io_will_be_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__issue_slots_13_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_15))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__will_be_valid_16)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_14))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_15_io_will_be_valid)
                : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_13)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_14_io_will_be_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__issue_slots_14_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_16))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__will_be_valid_17)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_15))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__will_be_valid_16)
                : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__next_14)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT___slots_15_io_will_be_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_4__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_4__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_4__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_4__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_4__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_4__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_4__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_4__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_5__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_5__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_5__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_5__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_5__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_5__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_5__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_5__DOT___T_14)));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4365(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4365\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_6__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_6__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_6__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_6__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_6__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_6__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_6__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_6__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_7__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_7__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_7__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_7__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_7__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_7__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_7__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_7__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_8__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_8__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_8__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_8__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_8__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_8__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_8__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_8__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_9__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_9__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_9__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_9__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_9__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_9__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_9__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_9__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_10__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_10__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_10__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_10__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_10__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_10__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_10__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_10__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_11__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_11__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_11__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_11__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_11__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_11__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_11__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_11__DOT___T_14)));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4366(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4366\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_12__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_12__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_12__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_12__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_12__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_12__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_12__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_12__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_13__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_13__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_13__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_13__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_13__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_13__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_13__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_13__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_14__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_14__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_14__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_14__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_14__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_14__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_14__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_14__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_15__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_15__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_15__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_15__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_15__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_15__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_15__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_15__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_4__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_4__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_4__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_4__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_4__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_4__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_4__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_4__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_5__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_5__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_5__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_5__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_5__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_5__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_5__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_5__DOT___T_14)));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4367(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4367\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_6__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_6__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_6__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_6__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_6__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_6__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_6__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_6__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_7__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_7__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_7__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_7__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_7__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_7__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_7__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_7__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_8__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_8__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_8__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_8__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_8__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_8__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_8__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_8__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_9__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_9__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_9__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_9__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_9__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_9__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_9__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_9__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_10__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_10__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_10__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_10__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_10__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_10__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_10__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_10__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_11__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_11__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_11__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_11__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_11__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_11__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_11__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_11__DOT___T_14)));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4368(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4368\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_12__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_12__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_12__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_12__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_12__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_12__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_12__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_12__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_13__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_13__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_13__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_13__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_13__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_13__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_13__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_13__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_14__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_14__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_14__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_3__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_3__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_3__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_3__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_3__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_3__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_3__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__mem_issue_unit__DOT__slots_3__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_3__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_3__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_3__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_3__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_3__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_3__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_3__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_3__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__issue_slots_0_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_2))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_3_io_will_be_valid)
            : ((2U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_1)))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_2_io_will_be_valid)
                : ((~ (IData)((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_0__DOT__state)))) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_1_io_will_be_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__issue_slots_1_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_3))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_4_io_will_be_valid)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_2))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_3_io_will_be_valid)
                : ((1U == (3U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_1))) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_2_io_will_be_valid))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4369(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4369\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__issue_slots_2_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_4))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_5_io_will_be_valid)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_3))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_4_io_will_be_valid)
                : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_2)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_3_io_will_be_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__issue_slots_3_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_5))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_6_io_will_be_valid)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_4))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_5_io_will_be_valid)
                : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_3)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_4_io_will_be_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__issue_slots_4_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_6))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_7_io_will_be_valid)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_5))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_6_io_will_be_valid)
                : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_4)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_5_io_will_be_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__issue_slots_5_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_7))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_8_io_will_be_valid)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_6))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_7_io_will_be_valid)
                : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_5)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_6_io_will_be_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__issue_slots_6_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_8))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_9_io_will_be_valid)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_7))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_8_io_will_be_valid)
                : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_6)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_7_io_will_be_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__issue_slots_7_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_9))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_10_io_will_be_valid)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_8))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_9_io_will_be_valid)
                : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_7)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_8_io_will_be_valid))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4370(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4370\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__issue_slots_8_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_10))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_11_io_will_be_valid)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_9))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_10_io_will_be_valid)
                : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_8)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_9_io_will_be_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__issue_slots_9_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_11))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_12_io_will_be_valid)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_10))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_11_io_will_be_valid)
                : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_9)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_10_io_will_be_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__issue_slots_10_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_12))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_13_io_will_be_valid)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_11))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_12_io_will_be_valid)
                : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_10)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_11_io_will_be_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__issue_slots_11_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_13))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_14_io_will_be_valid)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_12))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_13_io_will_be_valid)
                : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_11)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_12_io_will_be_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT___GEN_82 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__do_enq) 
           & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__enq_ptr_value)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT___GEN_84 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__do_enq) 
           & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__enq_ptr_value)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT___GEN_86 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__do_enq) 
           & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__enq_ptr_value)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT___GEN_88 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__do_enq) 
           & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__enq_ptr_value)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT___GEN_90 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__do_enq) 
           & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__enq_ptr_value)));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4371(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4371\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT___GEN_92 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__do_enq) 
           & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__enq_ptr_value)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT___GEN_94 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__do_enq) 
           & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__queue__DOT__enq_ptr_value)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fp_sdq__DOT__do_deq 
        = (1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fp_sdq__DOT___io_empty_output)) 
                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT___resp_arb_io_in_1_ready) 
                    | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fp_sdq__DOT___GEN_0)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fp_sdq__DOT__do_enq 
        = (((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fp_sdq__DOT___io_empty_output) 
                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT___resp_arb_io_in_1_ready))) 
            & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fp_sdq__DOT__ptr_match) 
                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT__fp_sdq__DOT__maybe_full)))) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fpiu_unit__DOT___fp_sdq_io_enq_valid_T_5));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__fp_stdata_fire 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___io_core_fp_stdata_ready_output) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT___io_to_sdq_valid_T) 
              & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT___fpiu_unit_io_ll_iresp_bits_uop_uopc))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___fp_pipeline_io_to_int_valid 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT___io_to_sdq_valid_T) 
           & (2U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT___fpiu_unit_io_ll_iresp_bits_uop_uopc)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___forwarding_age_logic_0_io_forwarding_idx 
        = ((0x800000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__forwarding_age_logic_0__DOT___matches_T_1)
            ? 0x17U : ((0x400000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__forwarding_age_logic_0__DOT___matches_T_1)
                        ? 0x16U : ((0x200000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__forwarding_age_logic_0__DOT___matches_T_1)
                                    ? 0x15U : ((0x100000U 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__forwarding_age_logic_0__DOT___matches_T_1)
                                                ? 0x14U
                                                : (
                                                   (0x80000U 
                                                    & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__forwarding_age_logic_0__DOT___matches_T_1)
                                                    ? 0x13U
                                                    : 
                                                   ((0x40000U 
                                                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__forwarding_age_logic_0__DOT___matches_T_1)
                                                     ? 0x12U
                                                     : 
                                                    ((0x20000U 
                                                      & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__forwarding_age_logic_0__DOT___matches_T_1)
                                                      ? 0x11U
                                                      : 
                                                     ((0x10000U 
                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__forwarding_age_logic_0__DOT___matches_T_1)
                                                       ? 0x10U
                                                       : 
                                                      ((0x8000U 
                                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__forwarding_age_logic_0__DOT___matches_T_1)
                                                        ? 0xfU
                                                        : 
                                                       ((0x4000U 
                                                         & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__forwarding_age_logic_0__DOT___matches_T_1)
                                                         ? 0xeU
                                                         : 
                                                        ((0x2000U 
                                                          & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__forwarding_age_logic_0__DOT___matches_T_1)
                                                          ? 0xdU
                                                          : 
                                                         ((0x1000U 
                                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__forwarding_age_logic_0__DOT___matches_T_1)
                                                           ? 0xcU
                                                           : 
                                                          ((0x800U 
                                                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__forwarding_age_logic_0__DOT___matches_T_1)
                                                            ? 0xbU
                                                            : 
                                                           ((0x400U 
                                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__forwarding_age_logic_0__DOT___matches_T_1)
                                                             ? 0xaU
                                                             : 
                                                            ((0x200U 
                                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__forwarding_age_logic_0__DOT___matches_T_1)
                                                              ? 9U
                                                              : 
                                                             ((0x100U 
                                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__forwarding_age_logic_0__DOT___matches_T_1)
                                                               ? 8U
                                                               : 
                                                              ((0x80U 
                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__forwarding_age_logic_0__DOT___matches_T_1)
                                                                ? 7U
                                                                : 
                                                               ((0x40U 
                                                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__forwarding_age_logic_0__DOT___matches_T_1)
                                                                 ? 6U
                                                                 : 
                                                                ((0x20U 
                                                                  & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__forwarding_age_logic_0__DOT___matches_T_1)
                                                                  ? 5U
                                                                  : 
                                                                 ((0x10U 
                                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__forwarding_age_logic_0__DOT___matches_T_1)
                                                                   ? 4U
                                                                   : 
                                                                  ((8U 
                                                                    & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__forwarding_age_logic_0__DOT___matches_T_1)
                                                                    ? 3U
                                                                    : 
                                                                   ((4U 
                                                                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__forwarding_age_logic_0__DOT___matches_T_1)
                                                                     ? 2U
                                                                     : 
                                                                    ((2U 
                                                                      & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__forwarding_age_logic_0__DOT___matches_T_1)
                                                                      ? 1U
                                                                      : 
                                                                     ((1U 
                                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__forwarding_age_logic_0__DOT___matches_T_1)
                                                                       ? 0U
                                                                       : 
                                                                      ((0x800000U 
                                                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__forwarding_age_logic_0__io_addr_matches)
                                                                        ? 0x17U
                                                                        : 
                                                                       ((0x400000U 
                                                                         & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__forwarding_age_logic_0__io_addr_matches)
                                                                         ? 0x16U
                                                                         : 
                                                                        ((0x200000U 
                                                                          & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__forwarding_age_logic_0__io_addr_matches)
                                                                          ? 0x15U
                                                                          : 
                                                                         ((0x100000U 
                                                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__forwarding_age_logic_0__io_addr_matches)
                                                                           ? 0x14U
                                                                           : 
                                                                          ((0x80000U 
                                                                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__forwarding_age_logic_0__io_addr_matches)
                                                                            ? 0x13U
                                                                            : 
                                                                           ((0x40000U 
                                                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__forwarding_age_logic_0__io_addr_matches)
                                                                             ? 0x12U
                                                                             : 
                                                                            ((0x20000U 
                                                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__forwarding_age_logic_0__io_addr_matches)
                                                                              ? 0x11U
                                                                              : 
                                                                             ((0x10000U 
                                                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__forwarding_age_logic_0__io_addr_matches)
                                                                               ? 0x10U
                                                                               : 
                                                                              ((0x8000U 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__forwarding_age_logic_0__io_addr_matches)
                                                                                ? 0xfU
                                                                                : 
                                                                               ((0x4000U 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__forwarding_age_logic_0__io_addr_matches)
                                                                                 ? 0xeU
                                                                                 : 
                                                                                ((0x2000U 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__forwarding_age_logic_0__io_addr_matches)
                                                                                 ? 0xdU
                                                                                 : 
                                                                                ((0x1000U 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__forwarding_age_logic_0__io_addr_matches)
                                                                                 ? 0xcU
                                                                                 : 
                                                                                ((0x800U 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__forwarding_age_logic_0__io_addr_matches)
                                                                                 ? 0xbU
                                                                                 : 
                                                                                ((0x400U 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__forwarding_age_logic_0__io_addr_matches)
                                                                                 ? 0xaU
                                                                                 : 
                                                                                ((0x200U 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__forwarding_age_logic_0__io_addr_matches)
                                                                                 ? 9U
                                                                                 : 
                                                                                ((0x100U 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__forwarding_age_logic_0__io_addr_matches)
                                                                                 ? 8U
                                                                                 : 
                                                                                ((0x80U 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__forwarding_age_logic_0__io_addr_matches)
                                                                                 ? 7U
                                                                                 : 
                                                                                ((0x40U 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__forwarding_age_logic_0__io_addr_matches)
                                                                                 ? 6U
                                                                                 : 
                                                                                ((0x20U 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__forwarding_age_logic_0__io_addr_matches)
                                                                                 ? 5U
                                                                                 : 
                                                                                ((0x10U 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__forwarding_age_logic_0__io_addr_matches)
                                                                                 ? 4U
                                                                                 : 
                                                                                ((8U 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__forwarding_age_logic_0__io_addr_matches)
                                                                                 ? 3U
                                                                                 : 
                                                                                ((4U 
                                                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__forwarding_age_logic_0__io_addr_matches)
                                                                                 ? 2U
                                                                                 : 
                                                                                (1U 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__forwarding_age_logic_0__io_addr_matches 
                                                                                >> 1U))))))))))))))))))))))))))))))))))))))))))))))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4376(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4376\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1429 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___T_1170)
            ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1405)
                ? ((0x17U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__lcam_ldq_idx_0)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1404))
                : ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___T_1184) 
                       & (0x17U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__lcam_ldq_idx_0)))) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1404)))
            : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_1404));
    if ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__next_21))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_ppred_busy 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_22__DOT__ppred)));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs3_busy 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_22__DOT__p3)));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs2_busy 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_22__DOT__p2)));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs1_busy 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_22__DOT__p1)));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs3 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_22__DOT__slot_uop_prs3;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs2 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_22__DOT__slot_uop_prs2;
    } else if ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__next_20))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_ppred_busy 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_21__DOT__ppred)));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs3_busy 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_21__DOT__p3)));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs2_busy 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_21__DOT__p2)));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs1_busy 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_21__DOT__p1)));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs3 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_21__DOT__slot_uop_prs3;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs2 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_21__DOT__slot_uop_prs2;
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_ppred_busy 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_20__DOT__ppred)));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs3_busy 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_20__DOT__p3)));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs2_busy 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_20__DOT__p2)));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs1_busy 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_20__DOT__p1)));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs3 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_20__DOT__slot_uop_prs3;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs2 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_20__DOT__slot_uop_prs2;
    }
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4377(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4377\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs1 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__next_21))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_22__DOT__slot_uop_prs1)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__next_20))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_21__DOT__slot_uop_prs1)
                : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_20__DOT__slot_uop_prs1)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__next_22 
        = (((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__next_21)) 
            & (~ (IData)((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_22__DOT__state)))))
            ? 1U : ((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__next_21) 
                              >> 2U) | (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_22__DOT__state))))
                     ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__next_21)
                     : (6U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__next_21) 
                              << 1U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_537 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_604) 
           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_7);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_540 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_604) 
           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_7 
              >> 1U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_543 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_604) 
           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_7 
              >> 2U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_546 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_604) 
           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_7 
              >> 3U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_549 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_604) 
           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_7 
              >> 4U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_552 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_604) 
           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_7 
              >> 5U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_555 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_604) 
           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_7 
              >> 6U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_558 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_604) 
           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_7 
              >> 7U));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4378(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4378\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_561 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_604) 
           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_7 
              >> 8U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_564 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_604) 
           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_7 
              >> 9U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_567 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_604) 
           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_7 
              >> 0xaU));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_570 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_604) 
           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_7 
              >> 0xbU));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_573 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_604) 
           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_7 
              >> 0xcU));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_576 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_604) 
           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_7 
              >> 0xdU));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_579 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_604) 
           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_7 
              >> 0xeU));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_582 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_604) 
           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_7 
              >> 0xfU));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_585 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_604) 
           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_7 
              >> 0x10U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_588 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_604) 
           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_7 
              >> 0x11U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_591 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_604) 
           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_7 
              >> 0x12U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_594 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_604) 
           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_7 
              >> 0x13U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_597 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_604) 
           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_7 
              >> 0x14U));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4379(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4379\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_600 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_604) 
           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_7 
              >> 0x15U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_603 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_604) 
           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_7 
              >> 0x16U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_606 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT___T_604) 
           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__fb__DOT__enq_idxs_7 
              >> 0x17U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__cmd_read_0 
        = (((((((((((((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_cmd)) 
                      | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_cmd))) 
                     | (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_cmd))) 
                    | (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_cmd))) 
                   | (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_cmd))) 
                  | (9U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_cmd))) 
                 | (0xaU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_cmd))) 
                | (0xbU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_cmd))) 
               | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_cmd))) 
              | (0xcU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_cmd))) 
             | (0xdU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_cmd))) 
            | (0xeU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_cmd))) 
           | (0xfU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_cmd)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__cmd_write_perms_0 
        = ((((((((((((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_cmd)) 
                     | (0x11U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_cmd))) 
                    | (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_cmd))) 
                   | (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_cmd))) 
                  | (9U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_cmd))) 
                 | (0xaU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_cmd))) 
                | (0xbU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_cmd))) 
               | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_cmd))) 
              | (0xcU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_cmd))) 
             | (0xdU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_cmd))) 
            | (0xeU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_cmd))) 
           | (0xfU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_cmd)));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4380(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4380\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_retry_idx_T_2 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_0_bits_addr_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_0_bits_addr_is_virtual)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_wakeup_idx_T_7 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_0_bits_addr_valid) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_0_bits_executed))) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_0_bits_succeeded))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_0_bits_addr_is_virtual))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_retry_idx_T_5 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_1_bits_addr_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_1_bits_addr_is_virtual)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_1)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_wakeup_idx_T_15 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_1_bits_addr_valid) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_1_bits_executed))) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_1_bits_succeeded))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_1_bits_addr_is_virtual))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_1)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_retry_idx_T_8 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_2_bits_addr_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_2_bits_addr_is_virtual)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_2)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_wakeup_idx_T_23 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_2_bits_addr_valid) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_2_bits_executed))) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_2_bits_succeeded))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_2_bits_addr_is_virtual))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_2)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_retry_idx_T_11 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_3_bits_addr_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_3_bits_addr_is_virtual)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_3)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_wakeup_idx_T_31 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_3_bits_addr_valid) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_3_bits_executed))) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_3_bits_succeeded))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_3_bits_addr_is_virtual))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_3)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_retry_idx_T_14 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_4_bits_addr_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_4_bits_addr_is_virtual)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_4)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_wakeup_idx_T_39 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_4_bits_addr_valid) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_4_bits_executed))) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_4_bits_succeeded))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_4_bits_addr_is_virtual))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_4)));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4381(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4381\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_retry_idx_T_17 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_5_bits_addr_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_5_bits_addr_is_virtual)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_5)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_wakeup_idx_T_47 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_5_bits_addr_valid) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_5_bits_executed))) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_5_bits_succeeded))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_5_bits_addr_is_virtual))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_5)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_retry_idx_T_20 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_6_bits_addr_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_6_bits_addr_is_virtual)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_6)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_wakeup_idx_T_55 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_6_bits_addr_valid) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_6_bits_executed))) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_6_bits_succeeded))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_6_bits_addr_is_virtual))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_6)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_retry_idx_T_23 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_7_bits_addr_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_7_bits_addr_is_virtual)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_7)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_wakeup_idx_T_63 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_7_bits_addr_valid) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_7_bits_executed))) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_7_bits_succeeded))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_7_bits_addr_is_virtual))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_7)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_retry_idx_T_26 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_8_bits_addr_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_8_bits_addr_is_virtual)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_8)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_wakeup_idx_T_71 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_8_bits_addr_valid) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_8_bits_executed))) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_8_bits_succeeded))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_8_bits_addr_is_virtual))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_8)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_retry_idx_T_29 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_9_bits_addr_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_9_bits_addr_is_virtual)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_9)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_wakeup_idx_T_79 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_9_bits_addr_valid) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_9_bits_executed))) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_9_bits_succeeded))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_9_bits_addr_is_virtual))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_9)));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4382(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4382\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_retry_idx_T_32 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_10_bits_addr_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_10_bits_addr_is_virtual)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_10)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_wakeup_idx_T_87 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_10_bits_addr_valid) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_10_bits_executed))) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_10_bits_succeeded))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_10_bits_addr_is_virtual))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_10)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_retry_idx_T_35 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_11_bits_addr_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_11_bits_addr_is_virtual)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_11)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_wakeup_idx_T_95 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_11_bits_addr_valid) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_11_bits_executed))) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_11_bits_succeeded))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_11_bits_addr_is_virtual))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_11)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_retry_idx_T_38 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_12_bits_addr_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_12_bits_addr_is_virtual)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_12)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_wakeup_idx_T_103 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_12_bits_addr_valid) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_12_bits_executed))) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_12_bits_succeeded))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_12_bits_addr_is_virtual))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_12)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_retry_idx_T_41 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_13_bits_addr_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_13_bits_addr_is_virtual)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_13)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_wakeup_idx_T_111 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_13_bits_addr_valid) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_13_bits_executed))) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_13_bits_succeeded))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_13_bits_addr_is_virtual))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_13)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_retry_idx_T_44 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_14_bits_addr_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_14_bits_addr_is_virtual)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_wakeup_idx_T_119 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_14_bits_addr_valid) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_14_bits_executed))) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_14_bits_succeeded))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_14_bits_addr_is_virtual))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_14)));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4383(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4383\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_retry_idx_T_47 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_15_bits_addr_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_15_bits_addr_is_virtual)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_15)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_wakeup_idx_T_127 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_15_bits_addr_valid) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_15_bits_executed))) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_15_bits_succeeded))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_15_bits_addr_is_virtual))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_15)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_retry_idx_T_50 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_16_bits_addr_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_16_bits_addr_is_virtual)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_16)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_wakeup_idx_T_135 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_16_bits_addr_valid) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_16_bits_executed))) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_16_bits_succeeded))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_16_bits_addr_is_virtual))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_16)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_retry_idx_T_53 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_17_bits_addr_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_17_bits_addr_is_virtual)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_17)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_wakeup_idx_T_143 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_17_bits_addr_valid) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_17_bits_executed))) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_17_bits_succeeded))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_17_bits_addr_is_virtual))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_17)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_retry_idx_T_56 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_18_bits_addr_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_18_bits_addr_is_virtual)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_18)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_wakeup_idx_T_151 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_18_bits_addr_valid) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_18_bits_executed))) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_18_bits_succeeded))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_18_bits_addr_is_virtual))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_18)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_retry_idx_T_59 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_19_bits_addr_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_19_bits_addr_is_virtual)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_19)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_wakeup_idx_T_159 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_19_bits_addr_valid) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_19_bits_executed))) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_19_bits_succeeded))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_19_bits_addr_is_virtual))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_19)));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4384(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4384\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_retry_idx_T_62 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_20_bits_addr_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_20_bits_addr_is_virtual)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_20)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_wakeup_idx_T_167 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_20_bits_addr_valid) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_20_bits_executed))) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_20_bits_succeeded))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_20_bits_addr_is_virtual))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_20)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_retry_idx_T_65 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_21_bits_addr_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_21_bits_addr_is_virtual)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_21)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_wakeup_idx_T_175 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_21_bits_addr_valid) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_21_bits_executed))) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_21_bits_succeeded))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_21_bits_addr_is_virtual))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_21)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_retry_idx_T_68 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_22_bits_addr_valid) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_22_bits_addr_is_virtual)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_22)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___ldq_wakeup_idx_T_183 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_22_bits_addr_valid) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_22_bits_executed))) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_22_bits_succeeded))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_22_bits_addr_is_virtual))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_retry_idx_block_22)));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_406) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_dmem_req_bits_0_bits_uop_uses_ldq 
            = (1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___mem_xcpt_uops_WIRE_0_uses_ldq));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_dmem_req_bits_0_bits_uop_uses_stq 
            = (1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___mem_xcpt_uops_WIRE_0_uses_stq));
    } else if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__will_fire_store_commit_0_will_fire) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_dmem_req_bits_0_bits_uop_uses_ldq 
            = (1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_63 
                     >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_execute_head)));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_dmem_req_bits_0_bits_uop_uses_stq 
            = (1U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_64 
                     >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__stq_execute_head)));
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_dmem_req_bits_0_bits_uop_uses_ldq 
            = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__will_fire_load_wakeup_0_will_fire) 
                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_208 
                        >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_wakeup_idx))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_dmem_req_bits_0_bits_uop_uses_stq 
            = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__will_fire_load_wakeup_0_will_fire) 
                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_210 
                        >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__ldq_wakeup_idx))));
    }
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4385(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4385\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT___GEN_407 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__will_fire_store_commit_0_will_fire) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__will_fire_load_wakeup_0_will_fire));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___GEN_17 
        = (0xfU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__exe_tlb_vaddr_0) 
                   & (((IData)(1U) << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT____Vcellinp__dtlb__io_req_0_bits_size)) 
                      - (IData)(1U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__hi_3 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_hits_0_3) 
            << 1U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_hits_0_2));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___T_30 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_hits_0_3) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_hits_0_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___px_array_T_4 
        = (0x200U | ((0x100U & ((~ (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__special_entry_data_0 
                                            >> 0xbU))) 
                                << 8U)) | ((0x80U & 
                                            ((~ (IData)(
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_3_data_0 
                                                         >> 0xbU))) 
                                             << 7U)) 
                                           | ((0x40U 
                                               & ((~ (IData)(
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_2_data_0 
                                                              >> 0xbU))) 
                                                  << 6U)) 
                                              | ((0x20U 
                                                  & ((~ (IData)(
                                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_1_data_0 
                                                                 >> 0xbU))) 
                                                     << 5U)) 
                                                 | ((0x10U 
                                                     & ((~ (IData)(
                                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_0_data_0 
                                                                    >> 0xbU))) 
                                                        << 4U)) 
                                                    | ((8U 
                                                        & ((~ (IData)(
                                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_7 
                                                                       >> 0xbU))) 
                                                           << 3U)) 
                                                       | ((4U 
                                                           & ((~ (IData)(
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_5 
                                                                          >> 0xbU))) 
                                                              << 2U)) 
                                                          | ((2U 
                                                              & ((~ (IData)(
                                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_3 
                                                                             >> 0xbU))) 
                                                                 << 1U)) 
                                                             | (1U 
                                                                & (~ (IData)(
                                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_1 
                                                                              >> 0xbU)))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__priv_rw_ok_0 
        = (0x1ffU & (((1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___csr_io_status_dprv)) 
                             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_mstatus_sum)))
                       ? ((0x100U & ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__special_entry_data_0 
                                              >> 0xdU)) 
                                     << 8U)) | ((0x80U 
                                                 & ((IData)(
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_3_data_0 
                                                             >> 0xdU)) 
                                                    << 7U)) 
                                                | ((0x40U 
                                                    & ((IData)(
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_2_data_0 
                                                                >> 0xdU)) 
                                                       << 6U)) 
                                                   | ((0x20U 
                                                       & ((IData)(
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_1_data_0 
                                                                   >> 0xdU)) 
                                                          << 5U)) 
                                                      | ((0x10U 
                                                          & ((IData)(
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_0_data_0 
                                                                      >> 0xdU)) 
                                                             << 4U)) 
                                                         | ((8U 
                                                             & ((IData)(
                                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_7 
                                                                         >> 0xdU)) 
                                                                << 3U)) 
                                                            | ((4U 
                                                                & ((IData)(
                                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_5 
                                                                            >> 0xdU)) 
                                                                   << 2U)) 
                                                               | ((2U 
                                                                   & ((IData)(
                                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_3 
                                                                               >> 0xdU)) 
                                                                      << 1U)) 
                                                                  | (1U 
                                                                     & (IData)(
                                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_1 
                                                                                >> 0xdU)))))))))))
                       : 0U) | ((1U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT___csr_io_status_dprv))
                                 ? (~ ((0x100U & ((IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__special_entry_data_0 
                                                           >> 0xdU)) 
                                                  << 8U)) 
                                       | ((0x80U & 
                                           ((IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_3_data_0 
                                                     >> 0xdU)) 
                                            << 7U)) 
                                          | ((0x40U 
                                              & ((IData)(
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_2_data_0 
                                                          >> 0xdU)) 
                                                 << 6U)) 
                                             | ((0x20U 
                                                 & ((IData)(
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_1_data_0 
                                                             >> 0xdU)) 
                                                    << 5U)) 
                                                | ((0x10U 
                                                    & ((IData)(
                                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__superpage_entries_0_data_0 
                                                                >> 0xdU)) 
                                                       << 4U)) 
                                                   | ((8U 
                                                       & ((IData)(
                                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_7 
                                                                   >> 0xdU)) 
                                                          << 3U)) 
                                                      | ((4U 
                                                          & ((IData)(
                                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_5 
                                                                      >> 0xdU)) 
                                                             << 2U)) 
                                                         | ((2U 
                                                             & ((IData)(
                                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_3 
                                                                         >> 0xdU)) 
                                                                << 1U)) 
                                                            | (1U 
                                                               & (IData)(
                                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___normal_entries_WIRE_1 
                                                                          >> 0xdU))))))))))))
                                 : 0U)));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4389(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4389\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__hitsVec_0_3 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__vm_enabled_0) 
            & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_3_valid_3) 
                 << 3U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_3_valid_2) 
                            << 2U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_3_valid_1) 
                                       << 1U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__sectored_entries_3_valid_0)))) 
               >> (3U & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__exe_tlb_vaddr_0 
                                 >> 0xcU))))) & (0U 
                                                 == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___sector_hits_T_25));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__mpu_ppn_0 
        = (0xfffffffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__resp_valid_0)
                          ? (0xfffffU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_pte_ppn))
                          : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__vm_enabled_0)
                              ? ((0xc0000U & ((IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__special_entry_data_0 
                                                       >> 0x20U)) 
                                              << 0x12U)) 
                                 | ((0x3fe00U & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___GEN) 
                                                  | (IData)(
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__special_entry_data_0 
                                                             >> 0x17U))) 
                                                 << 9U)) 
                                    | (0x1ffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT___GEN_0) 
                                                 | (IData)(
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__dtlb__DOT__special_entry_data_0 
                                                            >> 0xeU))))))
                              : (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__lsu__DOT__exe_tlb_vaddr_0 
                                         >> 0xcU)))));
    if ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_21))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_ppred_busy 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_22__DOT__ppred)));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs3_busy 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_22__DOT__p3)));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs2_busy 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_22__DOT__p2)));
    } else if ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_20))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_ppred_busy 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_21__DOT__ppred)));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs3_busy 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_21__DOT__p3)));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs2_busy 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_21__DOT__p2)));
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_ppred_busy 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_20__DOT__ppred)));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs3_busy 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_20__DOT__p3)));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs2_busy 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_20__DOT__p2)));
    }
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4390(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4390\n"); );
    // Body
    if ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_21))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs1_busy 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_22__DOT__p1)));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs3 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_22__DOT__slot_uop_prs3;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs2 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_22__DOT__slot_uop_prs2;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs1 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_22__DOT__slot_uop_prs1;
    } else if ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_20))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs1_busy 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_21__DOT__p1)));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs3 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_21__DOT__slot_uop_prs3;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs2 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_21__DOT__slot_uop_prs2;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs1 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_21__DOT__slot_uop_prs1;
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs1_busy 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_20__DOT__p1)));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs3 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_20__DOT__slot_uop_prs3;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs2 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_20__DOT__slot_uop_prs2;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT____Vcellinp__slots_19__io_in_uop_bits_prs1 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_20__DOT__slot_uop_prs1;
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_22 
        = (((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_21)) 
            & (~ (IData)((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_22__DOT__state)))))
            ? 1U : ((IData)((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_21) 
                              >> 2U) | (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_22__DOT__state))))
                     ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_21)
                     : (6U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_21) 
                              << 1U))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT___slots_14_io_out_uop_lrs2_rtype 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_14__DOT___GEN_1)
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_14__DOT__slot_uop_lrs2_rtype)
            : 2U);
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_14__DOT___GEN_0) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT___slots_14_io_out_uop_uopc 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_14__DOT__slot_uop_uopc;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT___slots_14_io_out_uop_lrs1_rtype 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_14__DOT__slot_uop_lrs1_rtype;
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT___slots_14_io_out_uop_uopc = 3U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT___slots_14_io_out_uop_lrs1_rtype = 2U;
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT____Vcellinp__slots_11__io_in_uop_bits_iw_state 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__next_13))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT___slots_14_io_out_uop_iw_state)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__next_12))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT___slots_13_io_out_uop_iw_state)
                : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT___slots_12_io_out_uop_iw_state)));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4391(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4391\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_15__DOT___GEN_1 
        = (1U & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_15__DOT___GEN) 
                  | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_15__DOT___T_12))) 
                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_15__DOT__p1)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_15__DOT___GEN_0 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_15__DOT___GEN) 
                 | (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_15__DOT___T_12) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_15__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT___slots_15_io_out_uop_iw_state 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_15__DOT___GEN_2)
            ? 0U : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_15__DOT___T_12)
                     ? 1U : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_15__DOT__state)));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__issue_slots_12_in_uop_valid) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_12__DOT__next_uop_prs1 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT____Vcellinp__slots_12__io_in_uop_bits_prs1;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_12__DOT__next_uop_prs2 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT____Vcellinp__slots_12__io_in_uop_bits_prs2;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_12__DOT__next_uop_prs3 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT____Vcellinp__slots_12__io_in_uop_bits_prs3;
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_12__DOT__next_uop_prs1 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_12__DOT__slot_uop_prs1;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_12__DOT__next_uop_prs2 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_12__DOT__slot_uop_prs2;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_12__DOT__next_uop_prs3 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_12__DOT__slot_uop_prs3;
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_16__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__REG_6) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_16__DOT___T_7));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_16__DOT___GEN_2 
        = (((0U != ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__b1_mispredict_mask) 
                    & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_16__DOT__slot_uop_br_mask))) 
            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__REG_6)) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_16__DOT___T_7));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__issue_slots_13_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__next_15))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT___slots_16_io_will_be_valid)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__next_14))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT___slots_15_io_will_be_valid)
                : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__next_13)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT___slots_14_io_will_be_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_17__DOT___T_12 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__issue_slots_17_grant) 
           & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_17__DOT__state)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_17__DOT___T_7 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__issue_slots_17_grant) 
            & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_17__DOT__state))) 
           | (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__issue_slots_17_grant) 
                 & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_17__DOT__state))) 
                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_17__DOT__p1)) 
               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_17__DOT__p2)) 
              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_17__DOT__ppred)));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4392(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4392\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT___slots_17_io_will_be_valid 
        = ((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_17__DOT__state)) 
           & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__issue_slots_17_grant) 
                 & ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_17__DOT__state)) 
                    | ((((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_17__DOT__state)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_17__DOT__p1)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_17__DOT__p2)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_17__DOT__ppred))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__issue_slots_18_grant 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT___slots_18_io_request) 
            & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT___can_allocate_T_18))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT___T_499)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT___T_512 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT___slots_18_io_request) 
            & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT___can_allocate_T_18))) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT___T_499));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___GEN_10 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_0__io_sinkd_valid) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___T_484));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___GEN_10 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_1__io_sinkd_valid) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___T_484));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT___GEN_10 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_2__io_sinkd_valid) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT___T_484));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT___GEN_10 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_3__io_sinkd_valid) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT___T_484));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT___GEN_10 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_4__io_sinkd_valid) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT___T_484));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT___GEN_10 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__bc_mshr__io_sinkd_valid) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT___T_484));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT___GEN_10 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__c_mshr__io_sinkd_valid) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT___T_484));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__queue__DOT__do_enq 
        = (((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__queue__DOT__empty) 
                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT____Vcellinp__queue__io_deq_ready))) 
            & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__queue__DOT__ptr_match) 
                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__queue__DOT__maybe_full)))) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__queue_io_enq_valid_REG_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s2_latch 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT___s1_valid_T) 
            & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT___io_bs_radr_valid_output)) 
               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bankedStore__DOT___sourceD_rreq_io_sourceD_radr_ready_T_1))) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s2_ready));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__pre_s3_req_set 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s3_latch)
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s2_req_set)
            : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s3_req_set));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4393(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4393\n"); );
    // Body
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s3_latch) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__pre_s3_req_way 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s2_req_way;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__pre_s3_beat 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s2_beat;
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__pre_s3_req_way 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s3_req_way;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__pre_s3_beat 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceD__DOT__s3_beat;
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__cc_dir_MPORT_en 
        = (1U & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__directory__io_read_valid)) 
                 & (((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__wipeCount) 
                         >> 0xaU)) & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__wipeOff))) 
                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__write__DOT__maybe_full))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__putbuffer__DOT__data_MPORT_en 
        = ((0xffffU != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__putbuffer__DOT__used)) 
           & (((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__resp)) 
                 & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__c__DOT__empty))) 
                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__c__DOT___ram_ext_R0_data[0U]) 
               & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__req_block))) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__set_block))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT___c_io_deq_ready_T_7 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__raw_resp)
                  ? ((~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__c__DOT___ram_ext_R0_data[0U]) 
                     | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__io_bs_adr_q__DOT___io_enq_ready_output))
                  : (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__req_block)) 
                      & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__buf_block))) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkC__DOT__set_block)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkA__DOT__putbuffer__DOT__data_MPORT_en 
        = ((0xffffffffffULL != vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkA__DOT__putbuffer__DOT__used) 
           & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT___io_deq_valid_output) 
                & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT___InclusiveCache_inner_TLBuffer_auto_out_a_bits_opcode) 
                      >> 2U))) & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkA__DOT__req_block))) 
              & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkA__DOT__set_block))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkA__DOT___io_a_ready_output 
        = (1U & (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkA__DOT__req_block)) 
                  & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkA__DOT__buf_block))) 
                 & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sinkA__DOT__set_block))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__new_request_control 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_0__io_allocate_valid)
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_0__io_allocate_bits_control)
            : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_control));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4394(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4394\n"); );
    // Body
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_0__io_allocate_valid) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__new_request_prio_2 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_0__io_allocate_bits_prio_2;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__new_request_source 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_0__io_allocate_bits_source;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__new_request_param 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_0__io_allocate_bits_param;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__new_request_opcode 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_0__io_allocate_bits_opcode;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___T_509 
            = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___T_25)) 
               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_5) 
                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_tag)));
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__new_request_prio_2 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_prio_2;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__new_request_source 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_source;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__new_request_param 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_param;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__new_request_opcode 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__request_opcode;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___T_509 = 0U;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_1__io_allocate_valid) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__new_request_control 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_1__io_allocate_bits_control;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__new_request_prio_2 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_1__io_allocate_bits_prio_2;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__new_request_source 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_1__io_allocate_bits_source;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__new_request_param 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_1__io_allocate_bits_param;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__new_request_opcode 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_1__io_allocate_bits_opcode;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___T_509 
            = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___T_29)) 
               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_4) 
                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__request_tag)));
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__new_request_control 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__request_control;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__new_request_prio_2 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__request_prio_2;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__new_request_source 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__request_source;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__new_request_param 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__request_param;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__new_request_opcode 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__request_opcode;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___T_509 = 0U;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_2__io_allocate_valid) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__new_request_control 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_2__io_allocate_bits_control;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__new_request_prio_2 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_2__io_allocate_bits_prio_2;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__new_request_source 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_2__io_allocate_bits_source;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__new_request_param 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_2__io_allocate_bits_param;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__new_request_opcode 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_2__io_allocate_bits_opcode;
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__new_request_control 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__request_control;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__new_request_prio_2 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__request_prio_2;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__new_request_source 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__request_source;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__new_request_param 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__request_param;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__new_request_opcode 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__request_opcode;
    }
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4395(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4395\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT___T_509 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_2__io_allocate_valid) 
           & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___T_33)) 
              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_3) 
                 == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_2__DOT__request_tag))));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_3__io_allocate_valid) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__new_request_control 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_3__io_allocate_bits_control;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__new_request_prio_2 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_3__io_allocate_bits_prio_2;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__new_request_source 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_3__io_allocate_bits_source;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__new_request_param 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_3__io_allocate_bits_param;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__new_request_opcode 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_3__io_allocate_bits_opcode;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT___T_509 
            = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___T_37)) 
               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_2) 
                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__request_tag)));
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__new_request_control 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__request_control;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__new_request_prio_2 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__request_prio_2;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__new_request_source 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__request_source;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__new_request_param 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__request_param;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__new_request_opcode 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT__request_opcode;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_3__DOT___T_509 = 0U;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_4__io_allocate_valid) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__new_request_control 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_4__io_allocate_bits_control;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__new_request_prio_2 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_4__io_allocate_bits_prio_2;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__new_request_source 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_4__io_allocate_bits_source;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__new_request_param 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_4__io_allocate_bits_param;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__new_request_opcode 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_4__io_allocate_bits_opcode;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT___T_509 
            = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___T_41)) 
               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_1) 
                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__request_tag)));
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__new_request_control 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__request_control;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__new_request_prio_2 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__request_prio_2;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__new_request_source 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__request_source;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__new_request_param 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__request_param;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__new_request_opcode 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT__request_opcode;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_4__DOT___T_509 = 0U;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__bc_mshr__io_allocate_valid) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__new_request_control 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__bc_mshr__io_allocate_bits_control;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__new_request_prio_2 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__bc_mshr__io_allocate_bits_prio_2;
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__new_request_control 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__request_control;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__new_request_prio_2 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__request_prio_2;
    }
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4396(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4396\n"); );
    // Init
    VlWide<8>/*255:0*/ __Vtemp_h3a0079cc__0;
    VlWide<16>/*511:0*/ __Vtemp_h4f5f090f__0;
    VlWide<3>/*95:0*/ __Vtemp_ha7e7e286__0;
    VlWide<4>/*127:0*/ __Vtemp_h0fba4d27__0;
    VlWide<4>/*127:0*/ __Vtemp_h53c014a5__0;
    VlWide<4>/*127:0*/ __Vtemp_h49dca115__0;
    // Body
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__bc_mshr__io_allocate_valid) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__new_request_source 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__bc_mshr__io_allocate_bits_source;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__new_request_param 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__bc_mshr__io_allocate_bits_param;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__new_request_opcode 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__bc_mshr__io_allocate_bits_opcode;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT___T_509 
            = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___T_45)) 
               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_0) 
                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__request_tag)));
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__new_request_source 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__request_source;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__new_request_param 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__request_param;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__new_request_opcode 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT__request_opcode;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__bc_mshr__DOT___T_509 = 0U;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__c_mshr__io_allocate_valid) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__new_request_control 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__c_mshr__io_allocate_bits_control;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__new_request_prio_2 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__c_mshr__io_allocate_bits_prio_2;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__new_request_source 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__c_mshr__io_allocate_bits_source;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__new_request_param 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__c_mshr__io_allocate_bits_param;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__new_request_opcode 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__c_mshr__io_allocate_bits_opcode;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT___T_509 
            = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN_30)) 
               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT___GEN) 
                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__request_tag)));
    } else {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__new_request_control 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__request_control;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__new_request_prio_2 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__request_prio_2;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__new_request_source 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__request_source;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__new_request_param 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__request_param;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__new_request_opcode 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT__request_opcode;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__c_mshr__DOT___T_509 = 0U;
    }
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

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4400(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4400\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_91 
        = (0x1ffU & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___GEN_90) 
                      >> 1U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___upper_mask_T_19)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___valid_T_29 
        = (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__maybe_full) 
              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                 [0U][5U] >> 0xdU)) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__valid_5)) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___T_48))) 
           & (0x3000000U == (0x3000000U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                             [0U][3U])));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3_mask_5 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__maybe_full) 
             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__f3__DOT__ram_ext__DOT__Memory
                [0U][5U] >> 0xdU)) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__valid_5)) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___T_48)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_14__DOT___GEN_1 
        = (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_14__DOT___GEN_0) 
                 | (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_14__DOT___T_12) 
                        & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_14__DOT___T_14))) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_14__DOT__p1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_15__DOT___GEN 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_15__DOT___T_12) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_15__DOT___T_14)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_15__DOT___GEN_0 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit_io_flush_pipeline_REG) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_15__DOT___T_7));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__issue_slots_12_in_uop_valid 
        = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_14))
            ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_15_io_will_be_valid)
            : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_13))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_14_io_will_be_valid)
                : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__next_12)) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_13_io_will_be_valid))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_16__DOT___T_12 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__issue_slots_16_grant) 
           & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_16__DOT__state)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_16__DOT___T_7 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__issue_slots_16_grant) 
            & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_16__DOT__state))) 
           | (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__issue_slots_16_grant) 
                 & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_16__DOT__state))) 
                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_16__DOT__p1)) 
               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_16__DOT__p2)) 
              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_16__DOT__ppred)));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4401(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4401\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_16_io_will_be_valid 
        = ((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_16__DOT__state)) 
           & (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__issue_slots_16_grant) 
                  & ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_16__DOT__state)) 
                     | ((((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_16__DOT__state)) 
                          & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_16__DOT__p1)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_16__DOT__p2)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_16__DOT__ppred)))) 
                 & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___lsu_io_core_ld_miss) 
                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_16__DOT__p1_poisoned) 
                          | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__slots_16__DOT__p2_poisoned)))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT__issue_slots_17_grant 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___T_1049) 
            | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___T_1036)) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___T_1023));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___T_1092 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_18_io_request) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___T_1083))) 
            & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___can_allocate_T_56))) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___T_1053));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___T_1088 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_18_io_request) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___T_1083))) 
            & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___can_allocate_T_56))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___T_1053)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___T_1122 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_19_io_request) 
             & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___can_allocate_T_58))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___T_1079))) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___T_1109));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___T_1118 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_19_io_request) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___T_1109))) 
            & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___can_allocate_T_58))) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___T_1079));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___T_1114 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_19_io_request) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___T_1109))) 
            & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___can_allocate_T_58))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___T_1079)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___T_1148 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_20_io_request) 
            & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___can_allocate_T_60))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___T_1105)));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__4402(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__4402\n"); );
    // Init
    VlWide<8>/*255:0*/ __Vtemp_h70999a16__0;
    VlWide<16>/*511:0*/ __Vtemp_h0939b21f__0;
    VlWide<3>/*95:0*/ __Vtemp_h694c3937__0;
    VlWide<4>/*127:0*/ __Vtemp_h94f6a9dc__0;
    VlWide<4>/*127:0*/ __Vtemp_h19a421de__0;
    VlWide<4>/*127:0*/ __Vtemp_h13f514e1__0;
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___T_1144 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_20_io_request) 
            & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___can_allocate_T_60))) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___T_1105));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___T_1140 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___slots_20_io_request) 
            & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___can_allocate_T_60))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__int_issue_unit__DOT___T_1105)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__replay_ex 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_replay) 
           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_valid) 
              & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkermode) 
                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__icsl_checkerpriv_mode))
                   ? ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_div) 
                      & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__state)))
                   : (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_mem) 
                       & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___dcacheArb_io_requestor_2_req_ready))) 
                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_ctrl_div) 
                         & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__state))))) 
                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__wb_dcache_miss) 
                    & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__ex_reg_load_use)))));
    __Vtemp_h70999a16__0[0U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_0_address;
    __Vtemp_h70999a16__0[1U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_1_address;
    __Vtemp_h70999a16__0[2U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_2_address;
    __Vtemp_h70999a16__0[3U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_3_address;
    __Vtemp_h70999a16__0[4U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_4_address;
    __Vtemp_h70999a16__0[5U] = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_5_address;
    __Vtemp_h70999a16__0[6U] = (IData)((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_7_address)) 
                                         << 0x20U) 
                                        | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_6_address))));
    __Vtemp_h70999a16__0[7U] = (IData)(((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_7_address)) 
                                          << 0x20U) 
                                         | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_6_address))) 
                                        >> 0x20U));
    __Vtemp_h0939b21f__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_0_data);
    __Vtemp_h0939b21f__0[1U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_0_data 
                                        >> 0x20U));
    __Vtemp_h0939b21f__0[2U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_1_data);
    __Vtemp_h0939b21f__0[3U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_1_data 
                                        >> 0x20U));
    __Vtemp_h0939b21f__0[4U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_2_data);
    __Vtemp_h0939b21f__0[5U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_2_data 
                                        >> 0x20U));
    __Vtemp_h0939b21f__0[6U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_3_data);
    __Vtemp_h0939b21f__0[7U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_3_data 
                                        >> 0x20U));
    __Vtemp_h0939b21f__0[8U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_4_data);
    __Vtemp_h0939b21f__0[9U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_4_data 
                                        >> 0x20U));
    __Vtemp_h0939b21f__0[0xaU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_5_data);
    __Vtemp_h0939b21f__0[0xbU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_5_data 
                                          >> 0x20U));
    __Vtemp_h0939b21f__0[0xcU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_6_data);
    __Vtemp_h0939b21f__0[0xdU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_6_data 
                                          >> 0x20U));
    __Vtemp_h0939b21f__0[0xeU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_7_data);
    __Vtemp_h0939b21f__0[0xfU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_7_data 
                                          >> 0x20U));
    __Vtemp_h694c3937__0[0U] = (((IData)((((QData)((IData)(
                                                           __Vtemp_h0939b21f__0[
                                                           (((IData)(0x3fU) 
                                                             + 
                                                             (0x1ffU 
                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                                 << 6U))) 
                                                            >> 5U)])) 
                                           << ((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                    << 6U)))
                                                ? 0x20U
                                                : ((IData)(0x40U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                       << 6U))))) 
                                          | (((0U == 
                                               (0x1fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                   << 6U)))
                                               ? 0ULL
                                               : ((QData)((IData)(
                                                                  __Vtemp_h0939b21f__0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x1ffU 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                                        << 6U))) 
                                                                   >> 5U)])) 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                       << 6U))))) 
                                             | ((QData)((IData)(
                                                                __Vtemp_h0939b21f__0[
                                                                (0xeU 
                                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                                    << 1U))])) 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                    << 6U)))))) 
                                 << 1U) | (1U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_7_corrupt) 
                                                   << 7U) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_6_corrupt) 
                                                      << 6U) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_5_corrupt) 
                                                         << 5U) 
                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_4_corrupt) 
                                                            << 4U) 
                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_3_corrupt) 
                                                               << 3U) 
                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_2_corrupt) 
                                                                  << 2U) 
                                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_1_corrupt) 
                                                                     << 1U) 
                                                                    | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_0_corrupt)))))))) 
                                                 >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index))));
    __Vtemp_h694c3937__0[1U] = (((IData)((((QData)((IData)(
                                                           __Vtemp_h0939b21f__0[
                                                           (((IData)(0x3fU) 
                                                             + 
                                                             (0x1ffU 
                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                                 << 6U))) 
                                                            >> 5U)])) 
                                           << ((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                    << 6U)))
                                                ? 0x20U
                                                : ((IData)(0x40U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                       << 6U))))) 
                                          | (((0U == 
                                               (0x1fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                   << 6U)))
                                               ? 0ULL
                                               : ((QData)((IData)(
                                                                  __Vtemp_h0939b21f__0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x1ffU 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                                        << 6U))) 
                                                                   >> 5U)])) 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                       << 6U))))) 
                                             | ((QData)((IData)(
                                                                __Vtemp_h0939b21f__0[
                                                                (0xeU 
                                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                                    << 1U))])) 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                    << 6U)))))) 
                                 >> 0x1fU) | ((IData)(
                                                      ((((QData)((IData)(
                                                                         __Vtemp_h0939b21f__0[
                                                                         (((IData)(0x3fU) 
                                                                           + 
                                                                           (0x1ffU 
                                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                                               << 6U))) 
                                                                          >> 5U)])) 
                                                         << 
                                                         ((0U 
                                                           == 
                                                           (0x1fU 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                               << 6U)))
                                                           ? 0x20U
                                                           : 
                                                          ((IData)(0x40U) 
                                                           - 
                                                           (0x1fU 
                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                               << 6U))))) 
                                                        | (((0U 
                                                             == 
                                                             (0x1fU 
                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                                 << 6U)))
                                                             ? 0ULL
                                                             : 
                                                            ((QData)((IData)(
                                                                             __Vtemp_h0939b21f__0[
                                                                             (((IData)(0x1fU) 
                                                                               + 
                                                                               (0x1ffU 
                                                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                                                << 6U))) 
                                                                              >> 5U)])) 
                                                             << 
                                                             ((IData)(0x20U) 
                                                              - 
                                                              (0x1fU 
                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                                  << 6U))))) 
                                                           | ((QData)((IData)(
                                                                              __Vtemp_h0939b21f__0[
                                                                              (0xeU 
                                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                                                << 1U))])) 
                                                              >> 
                                                              (0x1fU 
                                                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                                  << 6U))))) 
                                                       >> 0x20U)) 
                                              << 1U));
    __Vtemp_h694c3937__0[2U] = ((IData)(((((QData)((IData)(
                                                           __Vtemp_h0939b21f__0[
                                                           (((IData)(0x3fU) 
                                                             + 
                                                             (0x1ffU 
                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                                 << 6U))) 
                                                            >> 5U)])) 
                                           << ((0U 
                                                == 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                    << 6U)))
                                                ? 0x20U
                                                : ((IData)(0x40U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                       << 6U))))) 
                                          | (((0U == 
                                               (0x1fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                   << 6U)))
                                               ? 0ULL
                                               : ((QData)((IData)(
                                                                  __Vtemp_h0939b21f__0[
                                                                  (((IData)(0x1fU) 
                                                                    + 
                                                                    (0x1ffU 
                                                                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                                        << 6U))) 
                                                                   >> 5U)])) 
                                                  << 
                                                  ((IData)(0x20U) 
                                                   - 
                                                   (0x1fU 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                       << 6U))))) 
                                             | ((QData)((IData)(
                                                                __Vtemp_h0939b21f__0[
                                                                (0xeU 
                                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                                    << 1U))])) 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                    << 6U))))) 
                                         >> 0x20U)) 
                                >> 0x1fU);
    __Vtemp_h94f6a9dc__0[2U] = (((((0U == (0x1fU & 
                                           ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                            << 5U)))
                                    ? 0U : (__Vtemp_h70999a16__0[
                                            (((IData)(0x1fU) 
                                              + (0xffU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                    << 5U))) 
                                             >> 5U)] 
                                            << ((IData)(0x20U) 
                                                - (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                      << 5U))))) 
                                  | (__Vtemp_h70999a16__0[
                                     (7U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index))] 
                                     >> (0x1fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                  << 5U)))) 
                                 << 9U) | ((0x1feU 
                                            & ((IData)(
                                                       ((((QData)((IData)(
                                                                          (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_7_mask) 
                                                                            << 0x18U) 
                                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_6_mask) 
                                                                               << 0x10U) 
                                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_5_mask) 
                                                                                << 8U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_4_mask)))))) 
                                                          << 0x20U) 
                                                         | (QData)((IData)(
                                                                           (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_3_mask) 
                                                                             << 0x18U) 
                                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_2_mask) 
                                                                                << 0x10U) 
                                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_1_mask) 
                                                                                << 8U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_0_mask))))))) 
                                                        >> 
                                                        (0x3fU 
                                                         & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                            << 3U)))) 
                                               << 1U)) 
                                           | __Vtemp_h694c3937__0[2U]));
    __Vtemp_h19a421de__0[3U] = ((0x600U & (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_7_source) 
                                              << 0xeU) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_6_source) 
                                                 << 0xcU) 
                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_5_source) 
                                                    << 0xaU) 
                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_4_source) 
                                                       << 8U) 
                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_3_source) 
                                                          << 6U) 
                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_2_source) 
                                                             << 4U) 
                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_1_source) 
                                                                << 2U) 
                                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_0_source)))))))) 
                                            >> (0xfU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                   << 1U))) 
                                           << 9U)) 
                                | ((((0U == (0x1fU 
                                             & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                << 5U)))
                                      ? 0U : (__Vtemp_h70999a16__0[
                                              (((IData)(0x1fU) 
                                                + (0xffU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                      << 5U))) 
                                               >> 5U)] 
                                              << ((IData)(0x20U) 
                                                  - 
                                                  (0x1fU 
                                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                      << 5U))))) 
                                    | (__Vtemp_h70999a16__0[
                                       (7U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index))] 
                                       >> (0x1fU & 
                                           ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                            << 5U)))) 
                                   >> 0x17U));
    __Vtemp_h13f514e1__0[3U] = ((0x18000U & (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_7_param) 
                                                << 0xeU) 
                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_6_param) 
                                                   << 0xcU) 
                                                  | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_5_param) 
                                                      << 0xaU) 
                                                     | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_4_param) 
                                                         << 8U) 
                                                        | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_3_param) 
                                                            << 6U) 
                                                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_2_param) 
                                                               << 4U) 
                                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_1_param) 
                                                                  << 2U) 
                                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_0_param)))))))) 
                                              >> (0xfU 
                                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                     << 1U))) 
                                             << 0xfU)) 
                                | ((0x7800U & (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_7_size) 
                                                  << 0x1cU) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_6_size) 
                                                     << 0x18U) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_5_size) 
                                                        << 0x14U) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_4_size) 
                                                           << 0x10U) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_3_size) 
                                                              << 0xcU) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_2_size) 
                                                                 << 8U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_1_size) 
                                                                    << 4U) 
                                                                   | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_0_size)))))))) 
                                                >> 
                                                (0x1fU 
                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index) 
                                                    << 2U))) 
                                               << 0xbU)) 
                                   | __Vtemp_h19a421de__0[3U]));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[0U] 
        = __Vtemp_h694c3937__0[0U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[1U] 
        = __Vtemp_h694c3937__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[2U] 
        = __Vtemp_h94f6a9dc__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT____Vcellinp__io_deq_bits_deq_bits_reg__io_d[3U] 
        = ((((0x17U >= (0x1fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index))))
              ? (7U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_7_opcode) 
                         << 0x15U) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_6_opcode) 
                                       << 0x12U) | 
                                      (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_5_opcode) 
                                        << 0xfU) | 
                                       (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_4_opcode) 
                                         << 0xcU) | 
                                        (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_3_opcode) 
                                          << 9U) | 
                                         (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_2_opcode) 
                                           << 6U) | 
                                          (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_1_opcode) 
                                            << 3U) 
                                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__bundleIn_0_b_source__DOT__mem_0_opcode)))))))) 
                       >> (0x1fU & ((IData)(3U) * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__asource__DOT__bundleIn_0_b_sink__DOT__index)))))
              : 0U) << 0x11U) | __Vtemp_h13f514e1__0[3U]);
}
