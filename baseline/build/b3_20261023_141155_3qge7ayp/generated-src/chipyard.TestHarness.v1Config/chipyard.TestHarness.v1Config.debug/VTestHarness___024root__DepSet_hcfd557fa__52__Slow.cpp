// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTestHarness.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTestHarness___024root.h"

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__2352(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__2352\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___dcache_io_cpu_resp_bits_data 
        = (((((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_size)) 
              | (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd)))
              ? (- (QData)((IData)(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_signed) 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_resp_bits_data_zeroed_2) 
                                       >> 7U))))) : 
             ((0xffffffffffff00ULL & (((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_size))
                                        ? (- (QData)((IData)(
                                                             ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_signed) 
                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_resp_bits_data_shifted_1) 
                                                                 >> 0xfU)))))
                                        : (((QData)((IData)(
                                                            ((2U 
                                                              == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_size))
                                                              ? 
                                                             (- (IData)(
                                                                        ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_signed) 
                                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_resp_bits_data_shifted 
                                                                            >> 0x1fU))))
                                                              : (IData)(
                                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_data 
                                                                         >> 0x20U))))) 
                                            << 0x10U) 
                                           | (QData)((IData)(
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_resp_bits_data_shifted 
                                                              >> 0x10U))))) 
                                      << 8U)) | (QData)((IData)(
                                                                (0xffU 
                                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_resp_bits_data_shifted_1) 
                                                                    >> 8U)))))) 
            << 8U) | (QData)((IData)(((0xfeU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_resp_bits_data_zeroed_2)) 
                                      | (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_resp_bits_data_zeroed_2) 
                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_sc_fail)))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___dcache_io_cpu_resp_bits_data 
        = (((((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_size)) 
              | (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_cmd)))
              ? (- (QData)((IData)(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_signed) 
                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_resp_bits_data_zeroed_2) 
                                       >> 7U))))) : 
             ((0xffffffffffff00ULL & (((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_size))
                                        ? (- (QData)((IData)(
                                                             ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_signed) 
                                                              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_resp_bits_data_shifted_1) 
                                                                 >> 0xfU)))))
                                        : (((QData)((IData)(
                                                            ((2U 
                                                              == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_size))
                                                              ? 
                                                             (- (IData)(
                                                                        ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_req_signed) 
                                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_resp_bits_data_shifted 
                                                                            >> 0x1fU))))
                                                              : (IData)(
                                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_data 
                                                                         >> 0x20U))))) 
                                            << 0x10U) 
                                           | (QData)((IData)(
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_resp_bits_data_shifted 
                                                              >> 0x10U))))) 
                                      << 8U)) | (QData)((IData)(
                                                                (0xffU 
                                                                 & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_resp_bits_data_shifted_1) 
                                                                    >> 8U)))))) 
            << 8U) | (QData)((IData)(((0xfeU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_resp_bits_data_zeroed_2)) 
                                      | (1U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__io_cpu_resp_bits_data_zeroed_2) 
                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_sc_fail)))))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__2353(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__2353\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__roundIncr 
        = (((((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
              & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[1U] 
                   >> 0x1fU) & ((3U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__shiftedSig[1U] 
                                              >> 0x13U))) 
                                | (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT___roundIncr_near_even_T_6)))) 
                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__magJustBelowOne) 
                    & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT___roundIncr_near_even_T_6))))) 
             | ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
                & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[1U] 
                     >> 0x1fU) & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__shiftedSig[1U] 
                                  >> 0x13U)) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__magJustBelowOne)))) 
            | ((((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
                 | (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm))) 
                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[2U]) 
               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__common_inexact))) 
           | (((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
               & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[2U])) 
              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__common_inexact)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__roundIncr 
        = (((((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
              & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[1U] 
                   >> 0x1fU) & ((3U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__shiftedSig[1U] 
                                              >> 0x13U))) 
                                | (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT___roundIncr_near_even_T_6)))) 
                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__magJustBelowOne) 
                    & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT___roundIncr_near_even_T_6))))) 
             | ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
                & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[1U] 
                     >> 0x1fU) & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__shiftedSig[1U] 
                                  >> 0x13U)) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__magJustBelowOne)))) 
            | ((((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
                 | (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm))) 
                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[2U]) 
               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__common_inexact))) 
           | (((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
               & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[2U])) 
              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__common_inexact)));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__2354(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__2354\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__roundIncr 
        = (((((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
              & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[1U] 
                   >> 0x1fU) & ((3U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__shiftedSig[1U] 
                                              >> 0x13U))) 
                                | (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT___roundIncr_near_even_T_6)))) 
                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__magJustBelowOne) 
                    & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT___roundIncr_near_even_T_6))))) 
             | ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
                & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[1U] 
                     >> 0x1fU) & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__shiftedSig[1U] 
                                  >> 0x13U)) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__magJustBelowOne)))) 
            | ((((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
                 | (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm))) 
                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[2U]) 
               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__common_inexact))) 
           | (((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
               & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[2U])) 
              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__common_inexact)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__roundIncr 
        = (((((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
              & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[1U] 
                   >> 0x1fU) & ((3U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__shiftedSig[1U] 
                                              >> 0x13U))) 
                                | (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT___roundIncr_near_even_T_6)))) 
                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__magJustBelowOne) 
                    & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT___roundIncr_near_even_T_6))))) 
             | ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
                & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[1U] 
                     >> 0x1fU) & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__shiftedSig[1U] 
                                  >> 0x13U)) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__magJustBelowOne)))) 
            | ((((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
                 | (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm))) 
                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[2U]) 
               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__common_inexact))) 
           | (((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
               & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[2U])) 
              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__narrow__DOT__common_inexact)));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__2355(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__2355\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__roundIncr 
        = (((((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
              & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[1U] 
                   >> 0x1fU) & ((3U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__shiftedSig[1U] 
                                              >> 0x13U))) 
                                | (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT___roundIncr_near_even_T_6)))) 
                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__magJustBelowOne) 
                    & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT___roundIncr_near_even_T_6))))) 
             | ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
                & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[1U] 
                     >> 0x1fU) & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__shiftedSig[1U] 
                                  >> 0x13U)) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__magJustBelowOne)))) 
            | ((((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
                 | (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm))) 
                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[2U]) 
               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__common_inexact))) 
           | (((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
               & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[2U])) 
              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__common_inexact)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__roundIncr 
        = (((((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
              & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[1U] 
                   >> 0x1fU) & ((3U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__shiftedSig[1U] 
                                              >> 0x13U))) 
                                | (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT___roundIncr_near_even_T_6)))) 
                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__magJustBelowOne) 
                    & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT___roundIncr_near_even_T_6))))) 
             | ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
                & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[1U] 
                     >> 0x1fU) & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__shiftedSig[1U] 
                                  >> 0x13U)) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__magJustBelowOne)))) 
            | ((((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
                 | (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm))) 
                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[2U]) 
               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__common_inexact))) 
           | (((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
               & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[2U])) 
              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__common_inexact)));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__2356(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__2356\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__roundIncr 
        = (((((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
              & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[1U] 
                   >> 0x1fU) & ((3U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__shiftedSig[1U] 
                                              >> 0x13U))) 
                                | (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT___roundIncr_near_even_T_6)))) 
                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__magJustBelowOne) 
                    & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT___roundIncr_near_even_T_6))))) 
             | ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
                & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[1U] 
                     >> 0x1fU) & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__shiftedSig[1U] 
                                  >> 0x13U)) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__magJustBelowOne)))) 
            | ((((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
                 | (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm))) 
                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[2U]) 
               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__common_inexact))) 
           | (((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
               & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[2U])) 
              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__common_inexact)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__roundIncr 
        = (((((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
              & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[1U] 
                   >> 0x1fU) & ((3U == (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__shiftedSig[1U] 
                                              >> 0x13U))) 
                                | (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT___roundIncr_near_even_T_6)))) 
                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__magJustBelowOne) 
                    & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT___roundIncr_near_even_T_6))))) 
             | ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
                & (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[1U] 
                     >> 0x1fU) & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__shiftedSig[1U] 
                                  >> 0x13U)) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__magJustBelowOne)))) 
            | ((((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
                 | (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm))) 
                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[2U]) 
               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__common_inexact))) 
           | (((3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_rm)) 
               & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__in_in1[2U])) 
              & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__fpiu__DOT__conv__DOT__common_inexact)));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__2357(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__2357\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_raw_hazard 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_read) 
           & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_valid_likely) 
                & ((0xffU & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_addr 
                                     >> 3U))) == (0xffU 
                                                  & (IData)(
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_req_addr 
                                                             >> 3U))))) 
               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_write)
                   ? (0U != ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_mask) 
                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_mask_xwr)))
                   : (0U != ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_mask) 
                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_mask_xwr))))) 
              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_valid) 
                  & ((0xffU & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_addr 
                                       >> 3U))) == 
                     (0xffU & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_req_addr 
                                       >> 3U))))) & 
                 ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_write)
                   ? (0U != ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_mask) 
                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_mask_xwr)))
                   : (0U != ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_mask) 
                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_mask_xwr)))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_raw_hazard 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_read) 
           & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_valid_likely) 
                & ((0xffU & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_addr 
                                     >> 3U))) == (0xffU 
                                                  & (IData)(
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_req_addr 
                                                             >> 3U))))) 
               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_write)
                   ? (0U != ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_mask) 
                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_mask_xwr)))
                   : (0U != ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_mask) 
                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_mask_xwr))))) 
              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_valid) 
                  & ((0xffU & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_addr 
                                       >> 3U))) == 
                     (0xffU & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_req_addr 
                                       >> 3U))))) & 
                 ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_write)
                   ? (0U != ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_mask) 
                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_mask_xwr)))
                   : (0U != ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_mask) 
                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_mask_xwr)))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_raw_hazard 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_read) 
           & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_valid_likely) 
                & ((0xffU & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_addr 
                                     >> 3U))) == (0xffU 
                                                  & (IData)(
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_req_addr 
                                                             >> 3U))))) 
               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_write)
                   ? (0U != ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_mask) 
                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_mask_xwr)))
                   : (0U != ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_mask) 
                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_mask_xwr))))) 
              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_valid) 
                  & ((0xffU & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_addr 
                                       >> 3U))) == 
                     (0xffU & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_req_addr 
                                       >> 3U))))) & 
                 ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_write)
                   ? (0U != ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_mask) 
                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_mask_xwr)))
                   : (0U != ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_mask) 
                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_mask_xwr)))))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__2358(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__2358\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_raw_hazard 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_read) 
           & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_valid_likely) 
                & ((0xffU & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_addr 
                                     >> 3U))) == (0xffU 
                                                  & (IData)(
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_req_addr 
                                                             >> 3U))))) 
               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_write)
                   ? (0U != ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_mask) 
                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_mask_xwr)))
                   : (0U != ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore1_mask) 
                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_mask_xwr))))) 
              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_valid) 
                  & ((0xffU & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_addr 
                                       >> 3U))) == 
                     (0xffU & (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_req_addr 
                                       >> 3U))))) & 
                 ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_write)
                   ? (0U != ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_mask) 
                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_mask_xwr)))
                   : (0U != ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__pstore2_storegen_mask) 
                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s1_mask_xwr)))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___unrolls_T_7 
        = ((1U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_1[2U])
            ? ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___unrolls_T_2 
                << 1U) | (QData)((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U] 
                                          >> 0x1fU))))
            : (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_1[1U])) 
                << 0x20U) | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_1[0U]))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___unrolls_T_7 
        = ((1U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_1[2U])
            ? ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___unrolls_T_2 
                << 1U) | (QData)((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U] 
                                          >> 0x1fU))))
            : (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_1[1U])) 
                << 0x20U) | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_1[0U]))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___unrolls_T_7 
        = ((1U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_1[2U])
            ? ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___unrolls_T_2 
                << 1U) | (QData)((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U] 
                                          >> 0x1fU))))
            : (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_1[1U])) 
                << 0x20U) | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_1[0U]))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__2359(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__2359\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___unrolls_T_7 
        = ((1U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_1[2U])
            ? ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___unrolls_T_2 
                << 1U) | (QData)((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT__remainder[1U] 
                                          >> 0x1fU))))
            : (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_1[1U])) 
                << 0x20U) | (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__div__DOT___GEN_1[0U]))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_in_1_valid 
        = ((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___s2_meta_error_T)) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_masked) 
              | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_probe)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_hit_maybe_flush_pre_data_ecc_and_waw 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_masked) 
            & (~ (IData)((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___s2_meta_error_T))))) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_hit));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_miss 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_masked) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_readwrite)) 
            & (~ (IData)((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT___s2_meta_error_T))))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_hit)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_in_1_valid 
        = ((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___s2_meta_error_T)) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_masked) 
              | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_probe)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_hit_maybe_flush_pre_data_ecc_and_waw 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_masked) 
            & (~ (IData)((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___s2_meta_error_T))))) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_hit));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_miss 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_masked) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_readwrite)) 
            & (~ (IData)((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT___s2_meta_error_T))))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_hit)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_in_1_valid 
        = ((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___s2_meta_error_T)) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_masked) 
              | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_probe)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_hit_maybe_flush_pre_data_ecc_and_waw 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_masked) 
            & (~ (IData)((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___s2_meta_error_T))))) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_hit));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_miss 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_masked) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_readwrite)) 
            & (~ (IData)((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT___s2_meta_error_T))))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_hit)));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__2360(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__2360\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__metaArb_io_in_1_valid 
        = ((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___s2_meta_error_T)) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_masked) 
              | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_probe)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_hit_maybe_flush_pre_data_ecc_and_waw 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_masked) 
            & (~ (IData)((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___s2_meta_error_T))))) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_hit));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_miss 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_valid_masked) 
             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_readwrite)) 
            & (~ (IData)((0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT___s2_meta_error_T))))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__dcache__DOT__s2_hit)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT____Vcellinp__l2_tlb_ram_0__RW0_en 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__readEnable) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__writeEnable));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__hits 
        = (((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tags_7)) 
              == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tag) 
             << 7U) | ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tags_6)) 
                         == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tag) 
                        << 6U) | ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tags_5)) 
                                    == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tag) 
                                   << 5U) | ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tags_4)) 
                                               == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tag) 
                                              << 4U) 
                                             | ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tags_3)) 
                                                  == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tag) 
                                                 << 3U) 
                                                | ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tags_2)) 
                                                     == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tag) 
                                                    << 2U) 
                                                   | ((((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tags_1)) 
                                                        == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tag) 
                                                       << 1U) 
                                                      | ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tags_0)) 
                                                         == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__tag)))))))) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__valid));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___T_83 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__mem_resp_valid) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__traverse));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT___r_pte_T_8 
        = (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__traverse)) 
            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__r_req_vstage1)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__stage2));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__success 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__aux_pte_pte_v) 
             & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__ae))) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__pf))) 
           & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__ptw__DOT__gf)));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__2361(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__2361\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_10 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_leftOne_10) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_9));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_leftOne_2 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__hitsVec_0) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_4 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__hitsVec_3) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_3));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___T_36 
        = (IData)((0U != (5U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___GEN_106))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT____Vcellinp__icache__io_s1_paddr 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s1_is_replay)
            ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__s1_ppc_REG
            : vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT___tlb_io_resp_paddr);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__tlb_miss 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT___vm_enabled_T_1) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__bad_va))) 
           & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__real_hits)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_leftOne_8 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__hitsVec_6) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_6));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__newEntry_eff 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__legal_address) 
           & ((((((0U == ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                    >> 0xcU)) | ((0x40U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                                     >> 0xaU)) 
                                                 | ((0x30U 
                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                                        >> 9U)) 
                                                    | ((8U 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                                           >> 5U)) 
                                                       | ((6U 
                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                                              >> 3U)) 
                                                          | (1U 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                                                >> 1U)))))))) 
                  | (0U == ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                      >> 0xdU)) | (
                                                   (0x20U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                                       >> 0xbU)) 
                                                   | ((0x18U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                                          >> 0xaU)) 
                                                      | ((4U 
                                                          & ((~ 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                                               >> 8U)) 
                                                             << 2U)) 
                                                         | ((2U 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                                                >> 4U)) 
                                                            | (1U 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                                                  >> 1U))))))))) 
                 | (0U == ((0x40U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                     >> 0xdU)) | ((0x20U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                                      >> 0xbU)) 
                                                  | ((0x18U 
                                                      & (8U 
                                                         ^ 
                                                         (0x3ffff8U 
                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                                             >> 0xaU)))) 
                                                     | ((4U 
                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                                            >> 6U)) 
                                                        | (3U 
                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                                              >> 4U)))))))) 
                | (0U == ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                    >> 0xcU)) | ((0x40U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                                     >> 0xaU)) 
                                                 | ((0x30U 
                                                     & (0x10U 
                                                        ^ 
                                                        (0x7ffff0U 
                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                                            >> 9U)))) 
                                                    | ((8U 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                                           >> 5U)) 
                                                       | ((6U 
                                                           & (2U 
                                                              ^ 
                                                              (0x1ffffffeU 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                                                  >> 3U)))) 
                                                          | (1U 
                                                             & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                                                >> 1U))))))))) 
               | (0U == ((4U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                >> 0x11U)) | ((2U & 
                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                                >> 0xfU)) 
                                              | (1U 
                                                 & (~ 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                                     >> 0xeU))))))) 
              | (0U == ((0x80U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                  >> 0xcU)) | ((0x40U 
                                                & (0x40U 
                                                   ^ 
                                                   (0x3fffc0U 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                                       >> 0xaU)))) 
                                               | ((0x30U 
                                                   & (0x20U 
                                                      ^ 
                                                      (0x7ffff0U 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                                          >> 9U)))) 
                                                  | ((8U 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                                         >> 5U)) 
                                                     | ((6U 
                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                                            >> 3U)) 
                                                        | (1U 
                                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__mpu_ppn 
                                                              >> 1U))))))))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__2370(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__2370\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT__pmp__DOT__res_aligned_6 
        = (1U & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_cfg_a))
                  ? (0xfU == (0xfU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT___core_io_ptw_pmp_1_mask))
                  : (~ (((0U == (0xfffffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT____Vcellinp__pmp__io_addr 
                                                >> 4U) 
                                               ^ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr 
                                                  >> 2U)))) 
                         & (0U != (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr 
                                         & (~ (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT____Vcellinp__pmp__io_addr 
                                               >> 2U)))))) 
                        | ((0U == (0xfffffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__frontend__DOT__tlb__DOT____Vcellinp__pmp__io_addr 
                                                  >> 4U) 
                                                 ^ 
                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr 
                                                  >> 2U)))) 
                           & (0U != (3U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr)))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT__CIsDominant 
        = ((0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__in_in3[1U] 
                   >> 0x1dU)) & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT__isMinCAlign) 
                                 | (0x36U > (0x1fffU 
                                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT___sNatCAlignDist_T_1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT__CAlignDist 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT__isMinCAlign)
            ? 0U : ((0xa1U > (0x1fffU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT___sNatCAlignDist_T_1)))
                     ? (0xffU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT___sNatCAlignDist_T_1))
                     : 0xa1U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT__CIsDominant 
        = ((0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__in_in3[1U] 
                   >> 0x1dU)) & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT__isMinCAlign) 
                                 | (0x36U > (0x1fffU 
                                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT___sNatCAlignDist_T_1)))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__2371(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__2371\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT__CAlignDist 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT__isMinCAlign)
            ? 0U : ((0xa1U > (0x1fffU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT___sNatCAlignDist_T_1)))
                     ? (0xffU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT___sNatCAlignDist_T_1))
                     : 0xa1U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT__CIsDominant 
        = ((0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__in_in3[1U] 
                   >> 0x1dU)) & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT__isMinCAlign) 
                                 | (0x36U > (0x1fffU 
                                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT___sNatCAlignDist_T_1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT__CAlignDist 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT__isMinCAlign)
            ? 0U : ((0xa1U > (0x1fffU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT___sNatCAlignDist_T_1)))
                     ? (0xffU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT___sNatCAlignDist_T_1))
                     : 0xa1U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT__CIsDominant 
        = ((0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__in_in3[1U] 
                   >> 0x1dU)) & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT__isMinCAlign) 
                                 | (0x36U > (0x1fffU 
                                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT___sNatCAlignDist_T_1)))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT__CAlignDist 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT__isMinCAlign)
            ? 0U : ((0xa1U > (0x1fffU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT___sNatCAlignDist_T_1)))
                     ? (0xffU & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__fpuOpt__DOT__dfma__DOT__fma__DOT__mulAddRecFNToRaw_preMul__DOT___sNatCAlignDist_T_1))
                     : 0xa1U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__homogeneous 
        = ((((((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                    ? (((((((((((0ULL == ((0x7fffffffffcULL 
                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                              >> 1U)) 
                                          | (QData)((IData)(
                                                            (3U 
                                                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn)))))) 
                                | (3ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn)) 
                               | (1ULL == (0xffffffffffULL 
                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                              >> 4U)))) 
                              | (2ULL == (0xffffffffffULL 
                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                             >> 4U)))) 
                             | (0ULL == ((0x7fffffffff0ULL 
                                          & (0x80ULL 
                                             ^ (0x7ffffffffffffff0ULL 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                   >> 1U)))) 
                                         | (QData)((IData)(
                                                           (0xfU 
                                                            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn))))))) 
                            | (0x200ULL == (0xffffffffffULL 
                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                               >> 4U)))) 
                           | (0x2010ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn)) 
                          | (3U == (0x3fffffffU & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                           >> 0xeU))))) 
                         | (0x10000ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn)) 
                        | (0x54000ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn)) 
                       | (8U == (0xfffffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                       >> 0x10U)))))
                    : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count)) 
                       & ((3U == (0x3fffffffU & (IData)(
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                         >> 0xeU)))) 
                          | (8U == (0xfffffffU & (IData)(
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                          >> 0x10U))))))) 
                  & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_cfg_a))
                      ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                           ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_0_mask 
                              >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                           ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_0_mask 
                                              >> 0x14U)
                                           : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_0_mask 
                                              >> 0x1dU))) 
                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                             ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                       ^ (QData)((IData)(
                                                         (0xfffffU 
                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr 
                                                             >> 0xaU))))))
                             : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                 ? (0U != (0x7ffffffffULL 
                                           & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                               >> 9U) 
                                              ^ (QData)((IData)(
                                                                (0x7ffU 
                                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr 
                                                                    >> 0x13U)))))))
                                 : (0U != (0x3ffffffU 
                                           & ((IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                       >> 0x12U)) 
                                              ^ (3U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr 
                                                    >> 0x1cU))))))))
                      : (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_cfg_a)) 
                          | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                              << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr)) 
                                           << 2U))) 
                         | (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                              << 0xcU) & (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask))) 
                            < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr 
                                                << 2U) 
                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask))))))) 
                 & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_cfg_a))
                     ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                          ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_1_mask 
                             >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                          ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_1_mask 
                                             >> 0x14U)
                                          : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_1_mask 
                                             >> 0x1dU))) 
                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                            ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                      ^ (QData)((IData)(
                                                        (0xfffffU 
                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr 
                                                            >> 0xaU))))))
                            : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                ? (0U != (0x7ffffffffULL 
                                          & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                              >> 9U) 
                                             ^ (QData)((IData)(
                                                               (0x7ffU 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr 
                                                                   >> 0x13U)))))))
                                : (0U != (0x3ffffffU 
                                          & ((IData)(
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                      >> 0x12U)) 
                                             ^ (3U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr 
                                                   >> 0x1cU))))))))
                     : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_cfg_a)) 
                          | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_6 
                             < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr 
                                                 << 2U) 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_1))))) 
                         | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                             << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr)) 
                                          << 2U))) 
                        | (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                             << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr)) 
                                          << 2U)) & 
                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_6 
                            < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr 
                                                << 2U) 
                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_1)))))))) 
                & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_cfg_a))
                    ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                         ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_2_mask 
                            >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                         ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_2_mask 
                                            >> 0x14U)
                                         : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_2_mask 
                                            >> 0x1dU))) 
                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                           ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                     ^ (QData)((IData)(
                                                       (0xfffffU 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr 
                                                           >> 0xaU))))))
                           : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                               ? (0U != (0x7ffffffffULL 
                                         & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                             >> 9U) 
                                            ^ (QData)((IData)(
                                                              (0x7ffU 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr 
                                                                  >> 0x13U)))))))
                               : (0U != (0x3ffffffU 
                                         & ((IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                     >> 0x12U)) 
                                            ^ (3U & 
                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr 
                                                >> 0x1cU))))))))
                    : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_cfg_a)) 
                         | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_12 
                            < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr 
                                                << 2U) 
                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_2))))) 
                        | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                            << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr)) 
                                         << 2U))) | 
                       (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                          << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr)) 
                                       << 2U)) & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_12 
                                                  < (QData)((IData)(
                                                                    ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr 
                                                                      << 2U) 
                                                                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_2)))))))) 
               & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_cfg_a))
                   ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                        ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_3_mask 
                           >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                        ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_3_mask 
                                           >> 0x14U)
                                        : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_3_mask 
                                           >> 0x1dU))) 
                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                          ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                    ^ (QData)((IData)(
                                                      (0xfffffU 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr 
                                                          >> 0xaU))))))
                          : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                              ? (0U != (0x7ffffffffULL 
                                        & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                            >> 9U) 
                                           ^ (QData)((IData)(
                                                             (0x7ffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr 
                                                                 >> 0x13U)))))))
                              : (0U != (0x3ffffffU 
                                        & ((IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                    >> 0x12U)) 
                                           ^ (3U & 
                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr 
                                               >> 0x1cU))))))))
                   : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_cfg_a)) 
                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_18 
                           < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr 
                                               << 2U) 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_3))))) 
                       | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                           << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr)) 
                                        << 2U))) | 
                      (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                         << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr)) 
                                      << 2U)) & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_18 
                                                 < (QData)((IData)(
                                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr 
                                                                     << 2U) 
                                                                    & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_3)))))))) 
              & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_cfg_a))
                  ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                       ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_4_mask 
                          >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                       ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_4_mask 
                                          >> 0x14U)
                                       : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_4_mask 
                                          >> 0x1dU))) 
                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                         ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                   ^ (QData)((IData)(
                                                     (0xfffffU 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr 
                                                         >> 0xaU))))))
                         : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                             ? (0U != (0x7ffffffffULL 
                                       & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                           >> 9U) ^ (QData)((IData)(
                                                                    (0x7ffU 
                                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr 
                                                                        >> 0x13U)))))))
                             : (0U != (0x3ffffffU & 
                                       ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                 >> 0x12U)) 
                                        ^ (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr 
                                                 >> 0x1cU))))))))
                  : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_cfg_a)) 
                       | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_24 
                          < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr 
                                              << 2U) 
                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_4))))) 
                      | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                          << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr)) 
                                       << 2U))) | (
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                     << 0xcU) 
                                                    >= 
                                                    ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr)) 
                                                     << 2U)) 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_24 
                                                      < (QData)((IData)(
                                                                        ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr 
                                                                          << 2U) 
                                                                         & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_4)))))))) 
             & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_cfg_a))
                 ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                      ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_5_mask 
                         >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                      ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_5_mask 
                                         >> 0x14U) : 
                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_5_mask 
                                      >> 0x1dU))) | 
                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                      ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                ^ (QData)((IData)((0xfffffU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr 
                                                      >> 0xaU))))))
                      : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                          ? (0U != (0x7ffffffffULL 
                                    & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                        >> 9U) ^ (QData)((IData)(
                                                                 (0x7ffU 
                                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr 
                                                                     >> 0x13U)))))))
                          : (0U != (0x3ffffffU & ((IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                           >> 0x12U)) 
                                                  ^ 
                                                  (3U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr 
                                                      >> 0x1cU))))))))
                 : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_cfg_a)) 
                      | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_30 
                         < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr 
                                             << 2U) 
                                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_5))))) 
                     | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                         << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr)) 
                                      << 2U))) | ((
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                    << 0xcU) 
                                                   >= 
                                                   ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr)) 
                                                    << 2U)) 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_30 
                                                     < (QData)((IData)(
                                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr 
                                                                         << 2U) 
                                                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_5)))))))) 
            & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_cfg_a))
                ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                     ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_6_mask 
                        >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                     ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_6_mask 
                                        >> 0x14U) : 
                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_6_mask 
                                     >> 0x1dU))) | 
                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                     ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                               ^ (QData)((IData)((0xfffffU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr 
                                                     >> 0xaU))))))
                     : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                         ? (0U != (0x7ffffffffULL & 
                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                     >> 9U) ^ (QData)((IData)(
                                                              (0x7ffU 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr 
                                                                  >> 0x13U)))))))
                         : (0U != (0x3ffffffU & ((IData)(
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                          >> 0x12U)) 
                                                 ^ 
                                                 (3U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr 
                                                     >> 0x1cU))))))))
                : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_cfg_a)) 
                     | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_36 
                        < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr 
                                            << 2U) 
                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_6))))) 
                    | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                        << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr)) 
                                     << 2U))) | (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                   << 0xcU) 
                                                  >= 
                                                  ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr)) 
                                                   << 2U)) 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_36 
                                                    < (QData)((IData)(
                                                                      ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr 
                                                                        << 2U) 
                                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_6)))))))) 
           & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_cfg_a))
               ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                    ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_7_mask 
                       >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                    ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_7_mask 
                                       >> 0x14U) : 
                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_7_mask 
                                    >> 0x1dU))) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                                                    ? 
                                                   (0U 
                                                    != 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                     ^ (QData)((IData)(
                                                                       (0xfffffU 
                                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_addr 
                                                                           >> 0xaU))))))
                                                    : 
                                                   ((1U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                                     ? 
                                                    (0U 
                                                     != 
                                                     (0x7ffffffffULL 
                                                      & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                          >> 9U) 
                                                         ^ (QData)((IData)(
                                                                           (0x7ffU 
                                                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_addr 
                                                                               >> 0x13U)))))))
                                                     : 
                                                    (0U 
                                                     != 
                                                     (0x3ffffffU 
                                                      & ((IData)(
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                                  >> 0x12U)) 
                                                         ^ 
                                                         (3U 
                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_addr 
                                                             >> 0x1cU))))))))
               : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_cfg_a)) 
                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_42 
                       < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr 
                                           << 2U) & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_7))))) 
                   | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                       << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_addr)) 
                                    << 2U))) | (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                  << 0xcU) 
                                                 >= 
                                                 ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr)) 
                                                  << 2U)) 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_42 
                                                   < (QData)((IData)(
                                                                     ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_addr 
                                                                       << 2U) 
                                                                      & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_7))))))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__2372(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__2372\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__homogeneous 
        = ((((((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                    ? (((((((((((0ULL == ((0x7fffffffffcULL 
                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                              >> 1U)) 
                                          | (QData)((IData)(
                                                            (3U 
                                                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn)))))) 
                                | (3ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn)) 
                               | (1ULL == (0xffffffffffULL 
                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                              >> 4U)))) 
                              | (2ULL == (0xffffffffffULL 
                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                             >> 4U)))) 
                             | (0ULL == ((0x7fffffffff0ULL 
                                          & (0x80ULL 
                                             ^ (0x7ffffffffffffff0ULL 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                   >> 1U)))) 
                                         | (QData)((IData)(
                                                           (0xfU 
                                                            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn))))))) 
                            | (0x200ULL == (0xffffffffffULL 
                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                               >> 4U)))) 
                           | (0x2010ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn)) 
                          | (3U == (0x3fffffffU & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                           >> 0xeU))))) 
                         | (0x10000ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn)) 
                        | (0x54000ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn)) 
                       | (8U == (0xfffffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                       >> 0x10U)))))
                    : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count)) 
                       & ((3U == (0x3fffffffU & (IData)(
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                         >> 0xeU)))) 
                          | (8U == (0xfffffffU & (IData)(
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                          >> 0x10U))))))) 
                  & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_cfg_a))
                      ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                           ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_0_mask 
                              >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                           ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_0_mask 
                                              >> 0x14U)
                                           : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_0_mask 
                                              >> 0x1dU))) 
                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                             ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                       ^ (QData)((IData)(
                                                         (0xfffffU 
                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr 
                                                             >> 0xaU))))))
                             : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                 ? (0U != (0x7ffffffffULL 
                                           & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                               >> 9U) 
                                              ^ (QData)((IData)(
                                                                (0x7ffU 
                                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr 
                                                                    >> 0x13U)))))))
                                 : (0U != (0x3ffffffU 
                                           & ((IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                       >> 0x12U)) 
                                              ^ (3U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr 
                                                    >> 0x1cU))))))))
                      : (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_cfg_a)) 
                          | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                              << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr)) 
                                           << 2U))) 
                         | (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                              << 0xcU) & (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask))) 
                            < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr 
                                                << 2U) 
                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask))))))) 
                 & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_cfg_a))
                     ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                          ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_1_mask 
                             >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                          ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_1_mask 
                                             >> 0x14U)
                                          : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_1_mask 
                                             >> 0x1dU))) 
                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                            ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                      ^ (QData)((IData)(
                                                        (0xfffffU 
                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr 
                                                            >> 0xaU))))))
                            : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                ? (0U != (0x7ffffffffULL 
                                          & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                              >> 9U) 
                                             ^ (QData)((IData)(
                                                               (0x7ffU 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr 
                                                                   >> 0x13U)))))))
                                : (0U != (0x3ffffffU 
                                          & ((IData)(
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                      >> 0x12U)) 
                                             ^ (3U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr 
                                                   >> 0x1cU))))))))
                     : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_cfg_a)) 
                          | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_6 
                             < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr 
                                                 << 2U) 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_1))))) 
                         | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                             << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr)) 
                                          << 2U))) 
                        | (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                             << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr)) 
                                          << 2U)) & 
                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_6 
                            < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr 
                                                << 2U) 
                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_1)))))))) 
                & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_cfg_a))
                    ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                         ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_2_mask 
                            >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                         ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_2_mask 
                                            >> 0x14U)
                                         : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_2_mask 
                                            >> 0x1dU))) 
                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                           ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                     ^ (QData)((IData)(
                                                       (0xfffffU 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr 
                                                           >> 0xaU))))))
                           : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                               ? (0U != (0x7ffffffffULL 
                                         & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                             >> 9U) 
                                            ^ (QData)((IData)(
                                                              (0x7ffU 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr 
                                                                  >> 0x13U)))))))
                               : (0U != (0x3ffffffU 
                                         & ((IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                     >> 0x12U)) 
                                            ^ (3U & 
                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr 
                                                >> 0x1cU))))))))
                    : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_cfg_a)) 
                         | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_12 
                            < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr 
                                                << 2U) 
                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_2))))) 
                        | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                            << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr)) 
                                         << 2U))) | 
                       (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                          << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr)) 
                                       << 2U)) & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_12 
                                                  < (QData)((IData)(
                                                                    ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr 
                                                                      << 2U) 
                                                                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_2)))))))) 
               & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_cfg_a))
                   ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                        ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_3_mask 
                           >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                        ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_3_mask 
                                           >> 0x14U)
                                        : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_3_mask 
                                           >> 0x1dU))) 
                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                          ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                    ^ (QData)((IData)(
                                                      (0xfffffU 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr 
                                                          >> 0xaU))))))
                          : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                              ? (0U != (0x7ffffffffULL 
                                        & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                            >> 9U) 
                                           ^ (QData)((IData)(
                                                             (0x7ffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr 
                                                                 >> 0x13U)))))))
                              : (0U != (0x3ffffffU 
                                        & ((IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                    >> 0x12U)) 
                                           ^ (3U & 
                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr 
                                               >> 0x1cU))))))))
                   : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_cfg_a)) 
                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_18 
                           < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr 
                                               << 2U) 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_3))))) 
                       | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                           << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr)) 
                                        << 2U))) | 
                      (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                         << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr)) 
                                      << 2U)) & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_18 
                                                 < (QData)((IData)(
                                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr 
                                                                     << 2U) 
                                                                    & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_3)))))))) 
              & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_cfg_a))
                  ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                       ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_4_mask 
                          >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                       ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_4_mask 
                                          >> 0x14U)
                                       : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_4_mask 
                                          >> 0x1dU))) 
                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                         ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                   ^ (QData)((IData)(
                                                     (0xfffffU 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr 
                                                         >> 0xaU))))))
                         : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                             ? (0U != (0x7ffffffffULL 
                                       & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                           >> 9U) ^ (QData)((IData)(
                                                                    (0x7ffU 
                                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr 
                                                                        >> 0x13U)))))))
                             : (0U != (0x3ffffffU & 
                                       ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                 >> 0x12U)) 
                                        ^ (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr 
                                                 >> 0x1cU))))))))
                  : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_cfg_a)) 
                       | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_24 
                          < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr 
                                              << 2U) 
                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_4))))) 
                      | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                          << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr)) 
                                       << 2U))) | (
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                     << 0xcU) 
                                                    >= 
                                                    ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr)) 
                                                     << 2U)) 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_24 
                                                      < (QData)((IData)(
                                                                        ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr 
                                                                          << 2U) 
                                                                         & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_4)))))))) 
             & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_cfg_a))
                 ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                      ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_5_mask 
                         >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                      ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_5_mask 
                                         >> 0x14U) : 
                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_5_mask 
                                      >> 0x1dU))) | 
                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                      ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                ^ (QData)((IData)((0xfffffU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr 
                                                      >> 0xaU))))))
                      : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                          ? (0U != (0x7ffffffffULL 
                                    & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                        >> 9U) ^ (QData)((IData)(
                                                                 (0x7ffU 
                                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr 
                                                                     >> 0x13U)))))))
                          : (0U != (0x3ffffffU & ((IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                           >> 0x12U)) 
                                                  ^ 
                                                  (3U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr 
                                                      >> 0x1cU))))))))
                 : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_cfg_a)) 
                      | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_30 
                         < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr 
                                             << 2U) 
                                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_5))))) 
                     | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                         << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr)) 
                                      << 2U))) | ((
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                    << 0xcU) 
                                                   >= 
                                                   ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr)) 
                                                    << 2U)) 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_30 
                                                     < (QData)((IData)(
                                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr 
                                                                         << 2U) 
                                                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_5)))))))) 
            & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_cfg_a))
                ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                     ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_6_mask 
                        >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                     ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_6_mask 
                                        >> 0x14U) : 
                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_6_mask 
                                     >> 0x1dU))) | 
                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                     ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                               ^ (QData)((IData)((0xfffffU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr 
                                                     >> 0xaU))))))
                     : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                         ? (0U != (0x7ffffffffULL & 
                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                     >> 9U) ^ (QData)((IData)(
                                                              (0x7ffU 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr 
                                                                  >> 0x13U)))))))
                         : (0U != (0x3ffffffU & ((IData)(
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                          >> 0x12U)) 
                                                 ^ 
                                                 (3U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr 
                                                     >> 0x1cU))))))))
                : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_cfg_a)) 
                     | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_36 
                        < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr 
                                            << 2U) 
                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_6))))) 
                    | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                        << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr)) 
                                     << 2U))) | (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                   << 0xcU) 
                                                  >= 
                                                  ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr)) 
                                                   << 2U)) 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_36 
                                                    < (QData)((IData)(
                                                                      ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr 
                                                                        << 2U) 
                                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_6)))))))) 
           & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_cfg_a))
               ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                    ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_7_mask 
                       >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                    ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_7_mask 
                                       >> 0x14U) : 
                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_7_mask 
                                    >> 0x1dU))) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                                                    ? 
                                                   (0U 
                                                    != 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                     ^ (QData)((IData)(
                                                                       (0xfffffU 
                                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_addr 
                                                                           >> 0xaU))))))
                                                    : 
                                                   ((1U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                                     ? 
                                                    (0U 
                                                     != 
                                                     (0x7ffffffffULL 
                                                      & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                          >> 9U) 
                                                         ^ (QData)((IData)(
                                                                           (0x7ffU 
                                                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_addr 
                                                                               >> 0x13U)))))))
                                                     : 
                                                    (0U 
                                                     != 
                                                     (0x3ffffffU 
                                                      & ((IData)(
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                                  >> 0x12U)) 
                                                         ^ 
                                                         (3U 
                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_addr 
                                                             >> 0x1cU))))))))
               : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_cfg_a)) 
                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_42 
                       < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr 
                                           << 2U) & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_7))))) 
                   | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                       << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_addr)) 
                                    << 2U))) | (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                  << 0xcU) 
                                                 >= 
                                                 ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr)) 
                                                  << 2U)) 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_42 
                                                   < (QData)((IData)(
                                                                     ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_addr 
                                                                       << 2U) 
                                                                      & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_7))))))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__2373(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__2373\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__homogeneous 
        = ((((((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                    ? (((((((((((0ULL == ((0x7fffffffffcULL 
                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                              >> 1U)) 
                                          | (QData)((IData)(
                                                            (3U 
                                                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn)))))) 
                                | (3ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn)) 
                               | (1ULL == (0xffffffffffULL 
                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                              >> 4U)))) 
                              | (2ULL == (0xffffffffffULL 
                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                             >> 4U)))) 
                             | (0ULL == ((0x7fffffffff0ULL 
                                          & (0x80ULL 
                                             ^ (0x7ffffffffffffff0ULL 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                   >> 1U)))) 
                                         | (QData)((IData)(
                                                           (0xfU 
                                                            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn))))))) 
                            | (0x200ULL == (0xffffffffffULL 
                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                               >> 4U)))) 
                           | (0x2010ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn)) 
                          | (3U == (0x3fffffffU & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                           >> 0xeU))))) 
                         | (0x10000ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn)) 
                        | (0x54000ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn)) 
                       | (8U == (0xfffffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                       >> 0x10U)))))
                    : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count)) 
                       & ((3U == (0x3fffffffU & (IData)(
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                         >> 0xeU)))) 
                          | (8U == (0xfffffffU & (IData)(
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                          >> 0x10U))))))) 
                  & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_cfg_a))
                      ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                           ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_0_mask 
                              >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                           ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_0_mask 
                                              >> 0x14U)
                                           : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_0_mask 
                                              >> 0x1dU))) 
                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                             ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                       ^ (QData)((IData)(
                                                         (0xfffffU 
                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr 
                                                             >> 0xaU))))))
                             : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                 ? (0U != (0x7ffffffffULL 
                                           & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                               >> 9U) 
                                              ^ (QData)((IData)(
                                                                (0x7ffU 
                                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr 
                                                                    >> 0x13U)))))))
                                 : (0U != (0x3ffffffU 
                                           & ((IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                       >> 0x12U)) 
                                              ^ (3U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr 
                                                    >> 0x1cU))))))))
                      : (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_cfg_a)) 
                          | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                              << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr)) 
                                           << 2U))) 
                         | (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                              << 0xcU) & (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask))) 
                            < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr 
                                                << 2U) 
                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask))))))) 
                 & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_cfg_a))
                     ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                          ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_1_mask 
                             >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                          ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_1_mask 
                                             >> 0x14U)
                                          : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_1_mask 
                                             >> 0x1dU))) 
                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                            ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                      ^ (QData)((IData)(
                                                        (0xfffffU 
                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr 
                                                            >> 0xaU))))))
                            : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                ? (0U != (0x7ffffffffULL 
                                          & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                              >> 9U) 
                                             ^ (QData)((IData)(
                                                               (0x7ffU 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr 
                                                                   >> 0x13U)))))))
                                : (0U != (0x3ffffffU 
                                          & ((IData)(
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                      >> 0x12U)) 
                                             ^ (3U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr 
                                                   >> 0x1cU))))))))
                     : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_cfg_a)) 
                          | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_6 
                             < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr 
                                                 << 2U) 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_1))))) 
                         | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                             << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr)) 
                                          << 2U))) 
                        | (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                             << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr)) 
                                          << 2U)) & 
                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_6 
                            < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr 
                                                << 2U) 
                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_1)))))))) 
                & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_cfg_a))
                    ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                         ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_2_mask 
                            >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                         ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_2_mask 
                                            >> 0x14U)
                                         : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_2_mask 
                                            >> 0x1dU))) 
                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                           ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                     ^ (QData)((IData)(
                                                       (0xfffffU 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr 
                                                           >> 0xaU))))))
                           : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                               ? (0U != (0x7ffffffffULL 
                                         & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                             >> 9U) 
                                            ^ (QData)((IData)(
                                                              (0x7ffU 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr 
                                                                  >> 0x13U)))))))
                               : (0U != (0x3ffffffU 
                                         & ((IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                     >> 0x12U)) 
                                            ^ (3U & 
                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr 
                                                >> 0x1cU))))))))
                    : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_cfg_a)) 
                         | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_12 
                            < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr 
                                                << 2U) 
                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_2))))) 
                        | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                            << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr)) 
                                         << 2U))) | 
                       (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                          << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr)) 
                                       << 2U)) & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_12 
                                                  < (QData)((IData)(
                                                                    ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr 
                                                                      << 2U) 
                                                                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_2)))))))) 
               & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_cfg_a))
                   ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                        ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_3_mask 
                           >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                        ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_3_mask 
                                           >> 0x14U)
                                        : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_3_mask 
                                           >> 0x1dU))) 
                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                          ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                    ^ (QData)((IData)(
                                                      (0xfffffU 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr 
                                                          >> 0xaU))))))
                          : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                              ? (0U != (0x7ffffffffULL 
                                        & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                            >> 9U) 
                                           ^ (QData)((IData)(
                                                             (0x7ffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr 
                                                                 >> 0x13U)))))))
                              : (0U != (0x3ffffffU 
                                        & ((IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                    >> 0x12U)) 
                                           ^ (3U & 
                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr 
                                               >> 0x1cU))))))))
                   : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_cfg_a)) 
                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_18 
                           < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr 
                                               << 2U) 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_3))))) 
                       | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                           << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr)) 
                                        << 2U))) | 
                      (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                         << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr)) 
                                      << 2U)) & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_18 
                                                 < (QData)((IData)(
                                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr 
                                                                     << 2U) 
                                                                    & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_3)))))))) 
              & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_cfg_a))
                  ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                       ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_4_mask 
                          >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                       ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_4_mask 
                                          >> 0x14U)
                                       : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_4_mask 
                                          >> 0x1dU))) 
                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                         ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                   ^ (QData)((IData)(
                                                     (0xfffffU 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr 
                                                         >> 0xaU))))))
                         : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                             ? (0U != (0x7ffffffffULL 
                                       & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                           >> 9U) ^ (QData)((IData)(
                                                                    (0x7ffU 
                                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr 
                                                                        >> 0x13U)))))))
                             : (0U != (0x3ffffffU & 
                                       ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                 >> 0x12U)) 
                                        ^ (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr 
                                                 >> 0x1cU))))))))
                  : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_cfg_a)) 
                       | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_24 
                          < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr 
                                              << 2U) 
                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_4))))) 
                      | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                          << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr)) 
                                       << 2U))) | (
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                     << 0xcU) 
                                                    >= 
                                                    ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr)) 
                                                     << 2U)) 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_24 
                                                      < (QData)((IData)(
                                                                        ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr 
                                                                          << 2U) 
                                                                         & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_4)))))))) 
             & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_cfg_a))
                 ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                      ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_5_mask 
                         >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                      ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_5_mask 
                                         >> 0x14U) : 
                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_5_mask 
                                      >> 0x1dU))) | 
                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                      ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                ^ (QData)((IData)((0xfffffU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr 
                                                      >> 0xaU))))))
                      : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                          ? (0U != (0x7ffffffffULL 
                                    & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                        >> 9U) ^ (QData)((IData)(
                                                                 (0x7ffU 
                                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr 
                                                                     >> 0x13U)))))))
                          : (0U != (0x3ffffffU & ((IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                           >> 0x12U)) 
                                                  ^ 
                                                  (3U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr 
                                                      >> 0x1cU))))))))
                 : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_cfg_a)) 
                      | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_30 
                         < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr 
                                             << 2U) 
                                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_5))))) 
                     | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                         << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr)) 
                                      << 2U))) | ((
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                    << 0xcU) 
                                                   >= 
                                                   ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr)) 
                                                    << 2U)) 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_30 
                                                     < (QData)((IData)(
                                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr 
                                                                         << 2U) 
                                                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_5)))))))) 
            & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_cfg_a))
                ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                     ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_6_mask 
                        >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                     ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_6_mask 
                                        >> 0x14U) : 
                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_6_mask 
                                     >> 0x1dU))) | 
                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                     ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                               ^ (QData)((IData)((0xfffffU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr 
                                                     >> 0xaU))))))
                     : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                         ? (0U != (0x7ffffffffULL & 
                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                     >> 9U) ^ (QData)((IData)(
                                                              (0x7ffU 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr 
                                                                  >> 0x13U)))))))
                         : (0U != (0x3ffffffU & ((IData)(
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                          >> 0x12U)) 
                                                 ^ 
                                                 (3U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr 
                                                     >> 0x1cU))))))))
                : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_cfg_a)) 
                     | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_36 
                        < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr 
                                            << 2U) 
                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_6))))) 
                    | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                        << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr)) 
                                     << 2U))) | (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                   << 0xcU) 
                                                  >= 
                                                  ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr)) 
                                                   << 2U)) 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_36 
                                                    < (QData)((IData)(
                                                                      ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr 
                                                                        << 2U) 
                                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_6)))))))) 
           & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_cfg_a))
               ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                    ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_7_mask 
                       >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                    ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_7_mask 
                                       >> 0x14U) : 
                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_7_mask 
                                    >> 0x1dU))) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                                                    ? 
                                                   (0U 
                                                    != 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                     ^ (QData)((IData)(
                                                                       (0xfffffU 
                                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_addr 
                                                                           >> 0xaU))))))
                                                    : 
                                                   ((1U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                                     ? 
                                                    (0U 
                                                     != 
                                                     (0x7ffffffffULL 
                                                      & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                          >> 9U) 
                                                         ^ (QData)((IData)(
                                                                           (0x7ffU 
                                                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_addr 
                                                                               >> 0x13U)))))))
                                                     : 
                                                    (0U 
                                                     != 
                                                     (0x3ffffffU 
                                                      & ((IData)(
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                                  >> 0x12U)) 
                                                         ^ 
                                                         (3U 
                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_addr 
                                                             >> 0x1cU))))))))
               : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_cfg_a)) 
                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_42 
                       < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr 
                                           << 2U) & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_7))))) 
                   | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                       << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_addr)) 
                                    << 2U))) | (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                  << 0xcU) 
                                                 >= 
                                                 ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr)) 
                                                  << 2U)) 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_42 
                                                   < (QData)((IData)(
                                                                     ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_addr 
                                                                       << 2U) 
                                                                      & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_7))))))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__2374(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__2374\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__homogeneous 
        = ((((((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                    ? (((((((((((0ULL == ((0x7fffffffffcULL 
                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                              >> 1U)) 
                                          | (QData)((IData)(
                                                            (3U 
                                                             & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn)))))) 
                                | (3ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn)) 
                               | (1ULL == (0xffffffffffULL 
                                           & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                              >> 4U)))) 
                              | (2ULL == (0xffffffffffULL 
                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                             >> 4U)))) 
                             | (0ULL == ((0x7fffffffff0ULL 
                                          & (0x80ULL 
                                             ^ (0x7ffffffffffffff0ULL 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                   >> 1U)))) 
                                         | (QData)((IData)(
                                                           (0xfU 
                                                            & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn))))))) 
                            | (0x200ULL == (0xffffffffffULL 
                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                               >> 4U)))) 
                           | (0x2010ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn)) 
                          | (3U == (0x3fffffffU & (IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                           >> 0xeU))))) 
                         | (0x10000ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn)) 
                        | (0x54000ULL == vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn)) 
                       | (8U == (0xfffffffU & (IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                       >> 0x10U)))))
                    : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count)) 
                       & ((3U == (0x3fffffffU & (IData)(
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                         >> 0xeU)))) 
                          | (8U == (0xfffffffU & (IData)(
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                          >> 0x10U))))))) 
                  & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_cfg_a))
                      ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                           ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_0_mask 
                              >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                           ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_0_mask 
                                              >> 0x14U)
                                           : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_0_mask 
                                              >> 0x1dU))) 
                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                             ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                       ^ (QData)((IData)(
                                                         (0xfffffU 
                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr 
                                                             >> 0xaU))))))
                             : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                 ? (0U != (0x7ffffffffULL 
                                           & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                               >> 9U) 
                                              ^ (QData)((IData)(
                                                                (0x7ffU 
                                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr 
                                                                    >> 0x13U)))))))
                                 : (0U != (0x3ffffffU 
                                           & ((IData)(
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                       >> 0x12U)) 
                                              ^ (3U 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr 
                                                    >> 0x1cU))))))))
                      : (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_cfg_a)) 
                          | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                              << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr)) 
                                           << 2U))) 
                         | (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                              << 0xcU) & (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask))) 
                            < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr 
                                                << 2U) 
                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask))))))) 
                 & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_cfg_a))
                     ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                          ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_1_mask 
                             >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                          ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_1_mask 
                                             >> 0x14U)
                                          : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_1_mask 
                                             >> 0x1dU))) 
                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                            ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                      ^ (QData)((IData)(
                                                        (0xfffffU 
                                                         & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr 
                                                            >> 0xaU))))))
                            : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                ? (0U != (0x7ffffffffULL 
                                          & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                              >> 9U) 
                                             ^ (QData)((IData)(
                                                               (0x7ffU 
                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr 
                                                                   >> 0x13U)))))))
                                : (0U != (0x3ffffffU 
                                          & ((IData)(
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                      >> 0x12U)) 
                                             ^ (3U 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr 
                                                   >> 0x1cU))))))))
                     : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_cfg_a)) 
                          | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_6 
                             < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr 
                                                 << 2U) 
                                                & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_1))))) 
                         | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                             << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr)) 
                                          << 2U))) 
                        | (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                             << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_0_addr)) 
                                          << 2U)) & 
                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_6 
                            < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr 
                                                << 2U) 
                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_1)))))))) 
                & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_cfg_a))
                    ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                         ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_2_mask 
                            >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                         ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_2_mask 
                                            >> 0x14U)
                                         : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_2_mask 
                                            >> 0x1dU))) 
                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                           ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                     ^ (QData)((IData)(
                                                       (0xfffffU 
                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr 
                                                           >> 0xaU))))))
                           : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                               ? (0U != (0x7ffffffffULL 
                                         & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                             >> 9U) 
                                            ^ (QData)((IData)(
                                                              (0x7ffU 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr 
                                                                  >> 0x13U)))))))
                               : (0U != (0x3ffffffU 
                                         & ((IData)(
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                     >> 0x12U)) 
                                            ^ (3U & 
                                               (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr 
                                                >> 0x1cU))))))))
                    : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_cfg_a)) 
                         | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_12 
                            < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr 
                                                << 2U) 
                                               & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_2))))) 
                        | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                            << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr)) 
                                         << 2U))) | 
                       (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                          << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_1_addr)) 
                                       << 2U)) & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_12 
                                                  < (QData)((IData)(
                                                                    ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr 
                                                                      << 2U) 
                                                                     & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_2)))))))) 
               & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_cfg_a))
                   ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                        ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_3_mask 
                           >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                        ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_3_mask 
                                           >> 0x14U)
                                        : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_3_mask 
                                           >> 0x1dU))) 
                      | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                          ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                    ^ (QData)((IData)(
                                                      (0xfffffU 
                                                       & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr 
                                                          >> 0xaU))))))
                          : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                              ? (0U != (0x7ffffffffULL 
                                        & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                            >> 9U) 
                                           ^ (QData)((IData)(
                                                             (0x7ffU 
                                                              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr 
                                                                 >> 0x13U)))))))
                              : (0U != (0x3ffffffU 
                                        & ((IData)(
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                    >> 0x12U)) 
                                           ^ (3U & 
                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr 
                                               >> 0x1cU))))))))
                   : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_cfg_a)) 
                        | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_18 
                           < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr 
                                               << 2U) 
                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_3))))) 
                       | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                           << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr)) 
                                        << 2U))) | 
                      (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                         << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_2_addr)) 
                                      << 2U)) & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_18 
                                                 < (QData)((IData)(
                                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr 
                                                                     << 2U) 
                                                                    & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_3)))))))) 
              & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_cfg_a))
                  ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                       ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_4_mask 
                          >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                       ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_4_mask 
                                          >> 0x14U)
                                       : (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_4_mask 
                                          >> 0x1dU))) 
                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                         ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                   ^ (QData)((IData)(
                                                     (0xfffffU 
                                                      & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr 
                                                         >> 0xaU))))))
                         : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                             ? (0U != (0x7ffffffffULL 
                                       & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                           >> 9U) ^ (QData)((IData)(
                                                                    (0x7ffU 
                                                                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr 
                                                                        >> 0x13U)))))))
                             : (0U != (0x3ffffffU & 
                                       ((IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                 >> 0x12U)) 
                                        ^ (3U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr 
                                                 >> 0x1cU))))))))
                  : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_cfg_a)) 
                       | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_24 
                          < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr 
                                              << 2U) 
                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_4))))) 
                      | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                          << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr)) 
                                       << 2U))) | (
                                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                     << 0xcU) 
                                                    >= 
                                                    ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_3_addr)) 
                                                     << 2U)) 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_24 
                                                      < (QData)((IData)(
                                                                        ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr 
                                                                          << 2U) 
                                                                         & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_4)))))))) 
             & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_cfg_a))
                 ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                      ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_5_mask 
                         >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                      ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_5_mask 
                                         >> 0x14U) : 
                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_5_mask 
                                      >> 0x1dU))) | 
                    ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                      ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                ^ (QData)((IData)((0xfffffU 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr 
                                                      >> 0xaU))))))
                      : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                          ? (0U != (0x7ffffffffULL 
                                    & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                        >> 9U) ^ (QData)((IData)(
                                                                 (0x7ffU 
                                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr 
                                                                     >> 0x13U)))))))
                          : (0U != (0x3ffffffU & ((IData)(
                                                          (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                           >> 0x12U)) 
                                                  ^ 
                                                  (3U 
                                                   & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr 
                                                      >> 0x1cU))))))))
                 : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_cfg_a)) 
                      | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_30 
                         < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr 
                                             << 2U) 
                                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_5))))) 
                     | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                         << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr)) 
                                      << 2U))) | ((
                                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                    << 0xcU) 
                                                   >= 
                                                   ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_4_addr)) 
                                                    << 2U)) 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_30 
                                                     < (QData)((IData)(
                                                                       ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr 
                                                                         << 2U) 
                                                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_5)))))))) 
            & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_cfg_a))
                ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                     ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_6_mask 
                        >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                     ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_6_mask 
                                        >> 0x14U) : 
                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_6_mask 
                                     >> 0x1dU))) | 
                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                     ? (0U != (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                               ^ (QData)((IData)((0xfffffU 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr 
                                                     >> 0xaU))))))
                     : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                         ? (0U != (0x7ffffffffULL & 
                                   ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                     >> 9U) ^ (QData)((IData)(
                                                              (0x7ffU 
                                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr 
                                                                  >> 0x13U)))))))
                         : (0U != (0x3ffffffU & ((IData)(
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                          >> 0x12U)) 
                                                 ^ 
                                                 (3U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr 
                                                     >> 0x1cU))))))))
                : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_cfg_a)) 
                     | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_36 
                        < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr 
                                            << 2U) 
                                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_6))))) 
                    | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                        << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr)) 
                                     << 2U))) | (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                   << 0xcU) 
                                                  >= 
                                                  ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_5_addr)) 
                                                   << 2U)) 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_36 
                                                    < (QData)((IData)(
                                                                      ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr 
                                                                        << 2U) 
                                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_6)))))))) 
           & ((2U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_cfg_a))
               ? (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                    ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_7_mask 
                       >> 0xbU) : ((1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                    ? (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_7_mask 
                                       >> 0x14U) : 
                                   (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___core_io_ptw_pmp_7_mask 
                                    >> 0x1dU))) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___GEN_0)
                                                    ? 
                                                   (0U 
                                                    != 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                     ^ (QData)((IData)(
                                                                       (0xfffffU 
                                                                        & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_addr 
                                                                           >> 0xaU))))))
                                                    : 
                                                   ((1U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__count))
                                                     ? 
                                                    (0U 
                                                     != 
                                                     (0x7ffffffffULL 
                                                      & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                          >> 9U) 
                                                         ^ (QData)((IData)(
                                                                           (0x7ffU 
                                                                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_addr 
                                                                               >> 0x13U)))))))
                                                     : 
                                                    (0U 
                                                     != 
                                                     (0x3ffffffU 
                                                      & ((IData)(
                                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                                  >> 0x12U)) 
                                                         ^ 
                                                         (3U 
                                                          & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_addr 
                                                             >> 0x1cU))))))))
               : ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_cfg_a)) 
                    | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_42 
                       < (QData)((IData)(((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr 
                                           << 2U) & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_7))))) 
                   | ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                       << 0xcU) >= ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_addr)) 
                                    << 2U))) | (((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__r_pte_ppn 
                                                  << 0xcU) 
                                                 >= 
                                                 ((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_6_addr)) 
                                                  << 2U)) 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT___pmpHomogeneous_endsBeforeUpper_T_42 
                                                   < (QData)((IData)(
                                                                     ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__csr__DOT__reg_pmp_7_addr 
                                                                       << 2U) 
                                                                      & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ptw__DOT__pmpHomogeneous_pgMask_7))))))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__2375(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__2375\n"); );
    // Init
    VlWide<32>/*1023:0*/ __Vtemp_h5b7c424c__0;
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__do_enq 
        = ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__ptr_match) 
               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__maybe_full))) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                 >> 0xeU)));
    __Vtemp_h5b7c424c__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT___GEN_3);
    __Vtemp_h5b7c424c__0[1U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT___GEN_3 
                                        >> 0x20U));
    __Vtemp_h5b7c424c__0[2U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_checking);
    __Vtemp_h5b7c424c__0[3U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_checking 
                                        >> 0x20U));
    __Vtemp_h5b7c424c__0[4U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_postchecking);
    __Vtemp_h5b7c424c__0[5U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_postchecking 
                                        >> 0x20U));
    __Vtemp_h5b7c424c__0[6U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_otherthread);
    __Vtemp_h5b7c424c__0[7U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_otherthread 
                                        >> 0x20U));
    __Vtemp_h5b7c424c__0[8U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_nonchecking);
    __Vtemp_h5b7c424c__0[9U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_nonchecking 
                                        >> 0x20U));
    __Vtemp_h5b7c424c__0[0xaU] = 0U;
    __Vtemp_h5b7c424c__0[0xbU] = 0U;
    __Vtemp_h5b7c424c__0[0xcU] = 0U;
    __Vtemp_h5b7c424c__0[0xdU] = 0U;
    __Vtemp_h5b7c424c__0[0xeU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_howmany_checkpoints);
    __Vtemp_h5b7c424c__0[0xfU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_howmany_checkpoints 
                                          >> 0x20U));
    __Vtemp_h5b7c424c__0[0x10U] = 0U;
    __Vtemp_h5b7c424c__0[0x11U] = 0U;
    __Vtemp_h5b7c424c__0[0x12U] = 0U;
    __Vtemp_h5b7c424c__0[0x13U] = 0U;
    __Vtemp_h5b7c424c__0[0x14U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_CPStrans);
    __Vtemp_h5b7c424c__0[0x15U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_CPStrans 
                                           >> 0x20U));
    __Vtemp_h5b7c424c__0[0x16U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_L_timer_worest);
    __Vtemp_h5b7c424c__0[0x17U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_L_timer_worest 
                                           >> 0x20U));
    __Vtemp_h5b7c424c__0[0x18U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_num_st);
    __Vtemp_h5b7c424c__0[0x19U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_num_st 
                                           >> 0x20U));
    __Vtemp_h5b7c424c__0[0x1aU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_num_ld);
    __Vtemp_h5b7c424c__0[0x1bU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_num_ld 
                                           >> 0x20U));
    __Vtemp_h5b7c424c__0[0x1cU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT___GEN_3);
    __Vtemp_h5b7c424c__0[0x1dU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT___GEN_3 
                                           >> 0x20U));
    __Vtemp_h5b7c424c__0[0x1eU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT___GEN_3);
    __Vtemp_h5b7c424c__0[0x1fU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT___GEN_3 
                                           >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ghe_rd_val 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
            & (0U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                      >> 0x19U))) ? 1ULL : (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                             & (7U 
                                                == 
                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                 >> 0x19U)))
                                             ? (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ghe_ghe_status_reg))
                                             : (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                 & (0x10U 
                                                    == 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                     >> 0x19U)))
                                                 ? 0ULL
                                                 : 
                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                  & (6U 
                                                     == 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                      >> 0x19U)))
                                                  ? 
                                                 (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ghe_bigComp_reg)) 
                                                   << 0x10U) 
                                                  | (QData)((IData)(
                                                                    (0xffffU 
                                                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_wdata)))))
                                                  : 
                                                 (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                   & (0x1bU 
                                                      == 
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                       >> 0x19U)))
                                                   ? 0ULL
                                                   : 
                                                  (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                    & (8U 
                                                       == 
                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                        >> 0x19U)))
                                                    ? 0ULL
                                                    : 
                                                   (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                     & (0x49U 
                                                        == 
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                         >> 0x19U)))
                                                     ? (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ghe_ght_critial_reg))
                                                     : 
                                                    (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                      & (0x61U 
                                                         == 
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                          >> 0x19U)))
                                                      ? 
                                                     ((QData)((IData)(
                                                                      (1U 
                                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rsu_status)))) 
                                                      << 3U)
                                                      : 
                                                     (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                       & (((0x1dU 
                                                            == 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                             >> 0x19U)) 
                                                           | (0x1eU 
                                                              == 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                               >> 0x19U))) 
                                                          | (0x1fU 
                                                             == 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                              >> 0x19U))))
                                                       ? 0ULL
                                                       : 
                                                      (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                        & (0x77U 
                                                           == 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                            >> 0x19U)))
                                                        ? 
                                                       (((QData)((IData)(
                                                                         __Vtemp_h5b7c424c__0[
                                                                         (((IData)(0x3fU) 
                                                                           + 
                                                                           (0x3c0U 
                                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ghe_debug_perf_ctrl) 
                                                                               << 5U))) 
                                                                          >> 5U)])) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          __Vtemp_h5b7c424c__0[
                                                                          (0x1eU 
                                                                           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ghe_debug_perf_ctrl))])))
                                                        : 
                                                       (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                         & (0x55U 
                                                            == 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                             >> 0x19U)))
                                                         ? 0ULL
                                                         : 
                                                        (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                          & (0x78U 
                                                             == 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                              >> 0x19U)))
                                                          ? (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__RAW_counter))
                                                          : 0ULL))))))))))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__2376(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__2376\n"); );
    // Init
    VlWide<32>/*1023:0*/ __Vtemp_h0b44ba76__0;
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT____Vcellinp__cmdRouter__io_elu_deq_in 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
           & (0x63U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                        >> 0x19U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT____Vcellinp__cmdRouter__io_record_and_store_in 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
             & (0x75U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                          >> 0x19U))) << 1U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ghe_store_from_checker));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__ghe_doPID_Cfg 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
           & (0x16U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                        >> 0x19U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__do_enq 
        = ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__ptr_match) 
               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__maybe_full))) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                 >> 0xeU)));
    __Vtemp_h0b44ba76__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT___GEN_3);
    __Vtemp_h0b44ba76__0[1U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT___GEN_3 
                                        >> 0x20U));
    __Vtemp_h0b44ba76__0[2U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_checking);
    __Vtemp_h0b44ba76__0[3U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_checking 
                                        >> 0x20U));
    __Vtemp_h0b44ba76__0[4U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_postchecking);
    __Vtemp_h0b44ba76__0[5U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_postchecking 
                                        >> 0x20U));
    __Vtemp_h0b44ba76__0[6U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_otherthread);
    __Vtemp_h0b44ba76__0[7U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_otherthread 
                                        >> 0x20U));
    __Vtemp_h0b44ba76__0[8U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_nonchecking);
    __Vtemp_h0b44ba76__0[9U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_nonchecking 
                                        >> 0x20U));
    __Vtemp_h0b44ba76__0[0xaU] = 0U;
    __Vtemp_h0b44ba76__0[0xbU] = 0U;
    __Vtemp_h0b44ba76__0[0xcU] = 0U;
    __Vtemp_h0b44ba76__0[0xdU] = 0U;
    __Vtemp_h0b44ba76__0[0xeU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_howmany_checkpoints);
    __Vtemp_h0b44ba76__0[0xfU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_howmany_checkpoints 
                                          >> 0x20U));
    __Vtemp_h0b44ba76__0[0x10U] = 0U;
    __Vtemp_h0b44ba76__0[0x11U] = 0U;
    __Vtemp_h0b44ba76__0[0x12U] = 0U;
    __Vtemp_h0b44ba76__0[0x13U] = 0U;
    __Vtemp_h0b44ba76__0[0x14U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_CPStrans);
    __Vtemp_h0b44ba76__0[0x15U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_CPStrans 
                                           >> 0x20U));
    __Vtemp_h0b44ba76__0[0x16U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_L_timer_worest);
    __Vtemp_h0b44ba76__0[0x17U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_L_timer_worest 
                                           >> 0x20U));
    __Vtemp_h0b44ba76__0[0x18U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_num_st);
    __Vtemp_h0b44ba76__0[0x19U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_num_st 
                                           >> 0x20U));
    __Vtemp_h0b44ba76__0[0x1aU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_num_ld);
    __Vtemp_h0b44ba76__0[0x1bU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_num_ld 
                                           >> 0x20U));
    __Vtemp_h0b44ba76__0[0x1cU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT___GEN_3);
    __Vtemp_h0b44ba76__0[0x1dU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT___GEN_3 
                                           >> 0x20U));
    __Vtemp_h0b44ba76__0[0x1eU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT___GEN_3);
    __Vtemp_h0b44ba76__0[0x1fU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT___GEN_3 
                                           >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ghe_rd_val 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
            & (0U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                      >> 0x19U))) ? 1ULL : (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                             & (7U 
                                                == 
                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                 >> 0x19U)))
                                             ? (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ghe_ghe_status_reg))
                                             : (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                 & (0x10U 
                                                    == 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                     >> 0x19U)))
                                                 ? 0ULL
                                                 : 
                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                  & (6U 
                                                     == 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                      >> 0x19U)))
                                                  ? 
                                                 (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ghe_bigComp_reg)) 
                                                   << 0x10U) 
                                                  | (QData)((IData)(
                                                                    (0xffffU 
                                                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_wdata)))))
                                                  : 
                                                 (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                   & (0x1bU 
                                                      == 
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                       >> 0x19U)))
                                                   ? 0ULL
                                                   : 
                                                  (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                    & (8U 
                                                       == 
                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                        >> 0x19U)))
                                                    ? 0ULL
                                                    : 
                                                   (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                     & (0x49U 
                                                        == 
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                         >> 0x19U)))
                                                     ? (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ghe_ght_critial_reg))
                                                     : 
                                                    (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                      & (0x61U 
                                                         == 
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                          >> 0x19U)))
                                                      ? 
                                                     ((QData)((IData)(
                                                                      (1U 
                                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rsu_status)))) 
                                                      << 3U)
                                                      : 
                                                     (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                       & (((0x1dU 
                                                            == 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                             >> 0x19U)) 
                                                           | (0x1eU 
                                                              == 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                               >> 0x19U))) 
                                                          | (0x1fU 
                                                             == 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                              >> 0x19U))))
                                                       ? 0ULL
                                                       : 
                                                      (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                        & (0x77U 
                                                           == 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                            >> 0x19U)))
                                                        ? 
                                                       (((QData)((IData)(
                                                                         __Vtemp_h0b44ba76__0[
                                                                         (((IData)(0x3fU) 
                                                                           + 
                                                                           (0x3c0U 
                                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ghe_debug_perf_ctrl) 
                                                                               << 5U))) 
                                                                          >> 5U)])) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          __Vtemp_h0b44ba76__0[
                                                                          (0x1eU 
                                                                           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ghe_debug_perf_ctrl))])))
                                                        : 
                                                       (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                         & (0x55U 
                                                            == 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                             >> 0x19U)))
                                                         ? 0ULL
                                                         : 
                                                        (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                          & (0x78U 
                                                             == 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                              >> 0x19U)))
                                                          ? (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__RAW_counter))
                                                          : 0ULL))))))))))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__2377(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__2377\n"); );
    // Init
    VlWide<32>/*1023:0*/ __Vtemp_h4f867a16__0;
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT____Vcellinp__cmdRouter__io_elu_deq_in 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
           & (0x63U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                        >> 0x19U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT____Vcellinp__cmdRouter__io_record_and_store_in 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
             & (0x75U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                          >> 0x19U))) << 1U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ghe_store_from_checker));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__ghe_doPID_Cfg 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
           & (0x16U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                        >> 0x19U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__do_enq 
        = ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__ptr_match) 
               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__maybe_full))) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                 >> 0xeU)));
    __Vtemp_h4f867a16__0[0U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT___GEN_3);
    __Vtemp_h4f867a16__0[1U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT___GEN_3 
                                        >> 0x20U));
    __Vtemp_h4f867a16__0[2U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_checking);
    __Vtemp_h4f867a16__0[3U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_checking 
                                        >> 0x20U));
    __Vtemp_h4f867a16__0[4U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_postchecking);
    __Vtemp_h4f867a16__0[5U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_postchecking 
                                        >> 0x20U));
    __Vtemp_h4f867a16__0[6U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_otherthread);
    __Vtemp_h4f867a16__0[7U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_otherthread 
                                        >> 0x20U));
    __Vtemp_h4f867a16__0[8U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_nonchecking);
    __Vtemp_h4f867a16__0[9U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_nonchecking 
                                        >> 0x20U));
    __Vtemp_h4f867a16__0[0xaU] = 0U;
    __Vtemp_h4f867a16__0[0xbU] = 0U;
    __Vtemp_h4f867a16__0[0xcU] = 0U;
    __Vtemp_h4f867a16__0[0xdU] = 0U;
    __Vtemp_h4f867a16__0[0xeU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_howmany_checkpoints);
    __Vtemp_h4f867a16__0[0xfU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_howmany_checkpoints 
                                          >> 0x20U));
    __Vtemp_h4f867a16__0[0x10U] = 0U;
    __Vtemp_h4f867a16__0[0x11U] = 0U;
    __Vtemp_h4f867a16__0[0x12U] = 0U;
    __Vtemp_h4f867a16__0[0x13U] = 0U;
    __Vtemp_h4f867a16__0[0x14U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_CPStrans);
    __Vtemp_h4f867a16__0[0x15U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_CPStrans 
                                           >> 0x20U));
    __Vtemp_h4f867a16__0[0x16U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_L_timer_worest);
    __Vtemp_h4f867a16__0[0x17U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_L_timer_worest 
                                           >> 0x20U));
    __Vtemp_h4f867a16__0[0x18U] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_num_st);
    __Vtemp_h4f867a16__0[0x19U] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_num_st 
                                           >> 0x20U));
    __Vtemp_h4f867a16__0[0x1aU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_num_ld);
    __Vtemp_h4f867a16__0[0x1bU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT__debug_perf_num_ld 
                                           >> 0x20U));
    __Vtemp_h4f867a16__0[0x1cU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT___GEN_3);
    __Vtemp_h4f867a16__0[0x1dU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT___GEN_3 
                                           >> 0x20U));
    __Vtemp_h4f867a16__0[0x1eU] = (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT___GEN_3);
    __Vtemp_h4f867a16__0[0x1fU] = (IData)((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__icsl__DOT___GEN_3 
                                           >> 0x20U));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ghe_rd_val 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
            & (0U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                      >> 0x19U))) ? 1ULL : (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                             & (7U 
                                                == 
                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                 >> 0x19U)))
                                             ? (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ghe_ghe_status_reg))
                                             : (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                 & (0x10U 
                                                    == 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                     >> 0x19U)))
                                                 ? 0ULL
                                                 : 
                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                  & (6U 
                                                     == 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                      >> 0x19U)))
                                                  ? 
                                                 (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ghe_bigComp_reg)) 
                                                   << 0x10U) 
                                                  | (QData)((IData)(
                                                                    (0xffffU 
                                                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_wdata)))))
                                                  : 
                                                 (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                   & (0x1bU 
                                                      == 
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                       >> 0x19U)))
                                                   ? 0ULL
                                                   : 
                                                  (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                    & (8U 
                                                       == 
                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                        >> 0x19U)))
                                                    ? 0ULL
                                                    : 
                                                   (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                     & (0x49U 
                                                        == 
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                         >> 0x19U)))
                                                     ? (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ghe_ght_critial_reg))
                                                     : 
                                                    (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                      & (0x61U 
                                                         == 
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                          >> 0x19U)))
                                                      ? 
                                                     ((QData)((IData)(
                                                                      (1U 
                                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rsu_status)))) 
                                                      << 3U)
                                                      : 
                                                     (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                       & (((0x1dU 
                                                            == 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                             >> 0x19U)) 
                                                           | (0x1eU 
                                                              == 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                               >> 0x19U))) 
                                                          | (0x1fU 
                                                             == 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                              >> 0x19U))))
                                                       ? 0ULL
                                                       : 
                                                      (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                        & (0x77U 
                                                           == 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                            >> 0x19U)))
                                                        ? 
                                                       (((QData)((IData)(
                                                                         __Vtemp_h4f867a16__0[
                                                                         (((IData)(0x3fU) 
                                                                           + 
                                                                           (0x3c0U 
                                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ghe_debug_perf_ctrl) 
                                                                               << 5U))) 
                                                                          >> 5U)])) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          __Vtemp_h4f867a16__0[
                                                                          (0x1eU 
                                                                           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ghe_debug_perf_ctrl))])))
                                                        : 
                                                       (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                         & (0x55U 
                                                            == 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                             >> 0x19U)))
                                                         ? 0ULL
                                                         : 
                                                        (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                          & (0x78U 
                                                             == 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                              >> 0x19U)))
                                                          ? (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__RAW_counter))
                                                          : 0ULL))))))))))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__2378(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__2378\n"); );
    // Init
    VlWide<32>/*1023:0*/ __Vtemp_h3ea52170__0;
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT____Vcellinp__cmdRouter__io_elu_deq_in 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
           & (0x63U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                        >> 0x19U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT____Vcellinp__cmdRouter__io_record_and_store_in 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
             & (0x75U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                          >> 0x19U))) << 1U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ghe_store_from_checker));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__ghe_doPID_Cfg 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
           & (0x16U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                        >> 0x19U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__do_enq 
        = ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__ptr_match) 
               & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__respArb_io_in_0_q__DOT__maybe_full))) 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
              & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                 >> 0xeU)));
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
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_rd_val 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
            & (0U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                      >> 0x19U))) ? 1ULL : (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                             & (7U 
                                                == 
                                                (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                 >> 0x19U)))
                                             ? (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_ghe_status_reg))
                                             : (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                 & (0x10U 
                                                    == 
                                                    (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                     >> 0x19U)))
                                                 ? 0ULL
                                                 : 
                                                (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                  & (6U 
                                                     == 
                                                     (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                      >> 0x19U)))
                                                  ? 
                                                 (((QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_bigComp_reg)) 
                                                   << 0x10U) 
                                                  | (QData)((IData)(
                                                                    (0xffffU 
                                                                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_wdata)))))
                                                  : 
                                                 (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                   & (0x1bU 
                                                      == 
                                                      (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                       >> 0x19U)))
                                                   ? 0ULL
                                                   : 
                                                  (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                    & (8U 
                                                       == 
                                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                        >> 0x19U)))
                                                    ? 0ULL
                                                    : 
                                                   (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                     & (0x49U 
                                                        == 
                                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                         >> 0x19U)))
                                                     ? (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_ght_critial_reg))
                                                     : 
                                                    (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                      & (0x61U 
                                                         == 
                                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                          >> 0x19U)))
                                                      ? 
                                                     ((QData)((IData)(
                                                                      (1U 
                                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT___rsu_slave_io_rsu_status)))) 
                                                      << 3U)
                                                      : 
                                                     (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                       & (((0x1dU 
                                                            == 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                             >> 0x19U)) 
                                                           | (0x1eU 
                                                              == 
                                                              (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                               >> 0x19U))) 
                                                          | (0x1fU 
                                                             == 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                              >> 0x19U))))
                                                       ? 0ULL
                                                       : 
                                                      (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                        & (0x77U 
                                                           == 
                                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                            >> 0x19U)))
                                                        ? 
                                                       (((QData)((IData)(
                                                                         __Vtemp_h3ea52170__0[
                                                                         (((IData)(0x3fU) 
                                                                           + 
                                                                           (0x3c0U 
                                                                            & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_debug_perf_ctrl) 
                                                                               << 5U))) 
                                                                          >> 5U)])) 
                                                         << 0x20U) 
                                                        | (QData)((IData)(
                                                                          __Vtemp_h3ea52170__0[
                                                                          (0x1eU 
                                                                           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_debug_perf_ctrl))])))
                                                        : 
                                                       (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                         & (0x55U 
                                                            == 
                                                            (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                             >> 0x19U)))
                                                         ? 0ULL
                                                         : 
                                                        (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
                                                          & (0x78U 
                                                             == 
                                                             (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                                                              >> 0x19U)))
                                                          ? (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__RAW_counter))
                                                          : 0ULL))))))))))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__2379(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__2379\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT____Vcellinp__cmdRouter__io_elu_deq_in 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
           & (0x63U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                        >> 0x19U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT____Vcellinp__cmdRouter__io_record_and_store_in 
        = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
             & (0x75U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                          >> 0x19U))) << 1U) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_store_from_checker));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__ghe_doPID_Cfg 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT___cmdRouter_io_out_0_valid) 
           & (0x16U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__core__DOT__mem_reg_inst 
                        >> 0x19U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__do_enq 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__full)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_0_a_valid));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___T_1203 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__x1_a_q__DOT__full)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_0_a_valid));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT___same_cycle_resp_T_1 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_0_a_valid) 
           & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__wrapped_error_device__DOT__buffer__DOT__monitor__DOT__a_first_counter_1)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__x1_a_q__DOT__do_enq 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__x1_a_q__DOT__full)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_bus_named_subsystem_pbus_bus_xing_out_a_valid));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___T_1260 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__x1_a_q__DOT__full)) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_bus_named_subsystem_pbus_bus_xing_out_a_valid));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT___same_cycle_resp_T_1 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_bus_named_subsystem_pbus_bus_xing_out_a_valid) 
           & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer_1__DOT__monitor__DOT__a_first_counter_1)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT___T_1194 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_enq_ready_output) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_1_a_valid));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT___same_cycle_resp_T_1 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_1_a_valid) 
           & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_1_a_valid) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT__full));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT___T_1194 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_enq_ready_output) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_3_a_valid));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT___same_cycle_resp_T_1 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_3_a_valid) 
           & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_3_a_valid) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT__full));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__2380(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__2380\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1194 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_enq_ready_output) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_7_a_valid));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___same_cycle_resp_T_1 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_7_a_valid) 
           & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_7_a_valid) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT__full));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT___T_1194 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_enq_ready_output) 
           & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_8_a_valid));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT___same_cycle_resp_T_1 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_8_a_valid) 
           & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___out_xbar_auto_out_8_a_valid) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__repeater__DOT__full));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT____Vcellinp__repeater__io_repeat 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode) 
            >> 2U) & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__old_gennum1)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT___fragmenter_auto_out_a_bits_source 
        = ((0x7f0U & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT__full)
                        ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT__saved_source)
                        : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                            << 0x16U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                         >> 0xaU))) 
                      << 4U)) | ((8U & ((~ ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__gennum))
                                             ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__dToggle)
                                             : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__aToggle_r))) 
                                        << 3U)) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__old_gennum1)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT___fragmenter_auto_out_a_bits_address 
        = (0x3ffffffU & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT__full)
                           ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__repeater__DOT__saved_address
                           : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                               << 0xfU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                           >> 0x11U))) 
                         | (0x3fU & (~ (7U | ((0x1fffU 
                                               & ((IData)(0x3fU) 
                                                  << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT___repeater_io_deq_bits_size))) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__old_gennum1) 
                                                  << 3U) 
                                                 | (7U 
                                                    & (~ 
                                                       (0x3ffU 
                                                        & ((IData)(7U) 
                                                           << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_l2_ctrl__DOT__fragmenter__DOT__aFrag))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT____Vcellinp__repeater__io_repeat 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode) 
            >> 2U) & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__old_gennum1)));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__2381(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__2381\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_plic_fragmenter_out_a_bits_source 
        = ((0x7f0U & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT__full)
                        ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT__saved_source)
                        : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                            << 0x16U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                         >> 0xaU))) 
                      << 4U)) | ((8U & ((~ ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__gennum))
                                             ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__dToggle)
                                             : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__aToggle_r))) 
                                        << 3U)) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__old_gennum1)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_plic_fragmenter_out_a_bits_address 
        = (0xfffffffU & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT__full)
                           ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__repeater__DOT__saved_address
                           : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                               << 0xfU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                           >> 0x11U))) 
                         | (0x3fU & (~ (7U | ((0x1fffU 
                                               & ((IData)(0x3fU) 
                                                  << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT___repeater_io_deq_bits_size))) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__old_gennum1) 
                                                  << 3U) 
                                                 | (7U 
                                                    & (~ 
                                                       (0x3ffU 
                                                        & ((IData)(7U) 
                                                           << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_plic__DOT__fragmenter__DOT__aFrag))))))))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT____Vcellinp__repeater__io_repeat 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT___repeater_io_deq_bits_opcode) 
            >> 2U) & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__old_gennum1)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT___fragmenter_auto_out_a_bits_source 
        = ((0x7f0U & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT__full)
                        ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT__saved_source)
                        : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                            << 0x16U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                         >> 0xaU))) 
                      << 4U)) | ((8U & ((~ ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__gennum))
                                             ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__dToggle)
                                             : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__aToggle_r))) 
                                        << 3U)) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__old_gennum1)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT___fragmenter_auto_out_a_bits_address 
        = (0x1fffffU & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT__full)
                          ? vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__repeater__DOT__saved_address
                          : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                              << 0xfU) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                          >> 0x11U))) 
                        | (0x3fU & (~ (7U | ((0x1fffU 
                                              & ((IData)(0x3fU) 
                                                 << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT___repeater_io_deq_bits_size))) 
                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__old_gennum1) 
                                                 << 3U) 
                                                | (7U 
                                                   & (~ 
                                                      (0x3ffU 
                                                       & ((IData)(7U) 
                                                          << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__aFrag))))))))))));
}

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__2384(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__2384\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_debug_fragmenter_out_a_bits_source 
        = ((0x7f0U & (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__repeater__DOT__full)
                        ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__repeater__DOT__saved_source)
                        : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                            << 0x16U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                         >> 0xaU))) 
                      << 4U)) | ((8U & ((~ ((0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__gennum))
                                             ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__dToggle)
                                             : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__aToggle_r))) 
                                        << 3U)) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__old_gennum1)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__victimWay 
        = (((IData)((0U != (0xfU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__victimWayOH) 
                                    >> 4U)))) << 2U) 
           | (((IData)((0U != (3U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT___GEN_1) 
                                     >> 1U)))) << 1U) 
              | (IData)((0U != (5U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT___GEN_1))))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_10 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_leftOne_10) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_9));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_10 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_leftOne_10) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_9));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_10 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_leftOne_10) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_9));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_10 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_leftOne_10) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_9));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_leftOne_2 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__hitsVec_0) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_leftOne_2 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__hitsVec_0) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_leftOne_2 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__hitsVec_0) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_3__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_leftOne_2 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__hitsVec_0) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_4__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_1));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_4 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__hitsVec_3) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_3));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___T_36 
        = (IData)((0U != (5U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_109))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__tlb_miss 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___vm_enabled_T_1) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__bad_va))) 
           & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__real_hits)));
}

extern const VlWide<16>/*511:0*/ VTestHarness__ConstPool__CONST_h5d3db806_0;
extern const VlWide<16>/*511:0*/ VTestHarness__ConstPool__CONST_hc92a2a60_0;
extern const VlWide<16>/*511:0*/ VTestHarness__ConstPool__CONST_hb2c70161_0;
extern const VlWide<16>/*511:0*/ VTestHarness__ConstPool__CONST_h7e44c9df_0;

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__2385(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__2385\n"); );
    // Init
    VlWide<16>/*511:0*/ __Vtemp_h8dc2d6e1__0;
    VlWide<16>/*511:0*/ __Vtemp_hb1d773de__0;
    VlWide<16>/*511:0*/ __Vtemp_h2bba0e62__0;
    VlWide<16>/*511:0*/ __Vtemp_hbd919b9c__0;
    VlWide<16>/*511:0*/ __Vtemp_h35f69216__0;
    VlWide<16>/*511:0*/ __Vtemp_h8031a0db__0;
    VlWide<16>/*511:0*/ __Vtemp_hcf023001__0;
    VlWide<16>/*511:0*/ __Vtemp_hd69aa3ca__0;
    VlWide<16>/*511:0*/ __Vtemp_hae0bb386__0;
    // Body
    VL_SHIFTR_WWI(512,512,6, __Vtemp_h8dc2d6e1__0, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__vb_array, 
                  (0x3fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___tlb_io_resp_paddr 
                            >> 6U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s1_tag_hit_0 
        = (__Vtemp_h8dc2d6e1__0[0U] & ((0xfffffU & 
                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___tag_array_RW0_rdata[0U]) 
                                       == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___tlb_io_resp_paddr 
                                           >> 0xcU)));
    __Vtemp_hb1d773de__0[0U] = ((VTestHarness__ConstPool__CONST_h5d3db806_0[0U] 
                                 << 6U) | (0x3fU & 
                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___tlb_io_resp_paddr 
                                            >> 6U)));
    __Vtemp_hb1d773de__0[1U] = ((VTestHarness__ConstPool__CONST_h5d3db806_0[0U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h5d3db806_0[1U] 
                                              << 6U));
    __Vtemp_hb1d773de__0[2U] = ((VTestHarness__ConstPool__CONST_h5d3db806_0[1U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h5d3db806_0[2U] 
                                              << 6U));
    __Vtemp_hb1d773de__0[3U] = ((VTestHarness__ConstPool__CONST_h5d3db806_0[2U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h5d3db806_0[3U] 
                                              << 6U));
    __Vtemp_hb1d773de__0[4U] = ((VTestHarness__ConstPool__CONST_h5d3db806_0[3U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h5d3db806_0[4U] 
                                              << 6U));
    __Vtemp_hb1d773de__0[5U] = ((VTestHarness__ConstPool__CONST_h5d3db806_0[4U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h5d3db806_0[5U] 
                                              << 6U));
    __Vtemp_hb1d773de__0[6U] = ((VTestHarness__ConstPool__CONST_h5d3db806_0[5U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h5d3db806_0[6U] 
                                              << 6U));
    __Vtemp_hb1d773de__0[7U] = ((VTestHarness__ConstPool__CONST_h5d3db806_0[6U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h5d3db806_0[7U] 
                                              << 6U));
    __Vtemp_hb1d773de__0[8U] = ((VTestHarness__ConstPool__CONST_h5d3db806_0[7U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h5d3db806_0[8U] 
                                              << 6U));
    __Vtemp_hb1d773de__0[9U] = ((VTestHarness__ConstPool__CONST_h5d3db806_0[8U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h5d3db806_0[9U] 
                                              << 6U));
    __Vtemp_hb1d773de__0[0xaU] = ((VTestHarness__ConstPool__CONST_h5d3db806_0[9U] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_h5d3db806_0[0xaU] 
                                                << 6U));
    __Vtemp_hb1d773de__0[0xbU] = ((VTestHarness__ConstPool__CONST_h5d3db806_0[0xaU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_h5d3db806_0[0xbU] 
                                                << 6U));
    __Vtemp_hb1d773de__0[0xcU] = ((VTestHarness__ConstPool__CONST_h5d3db806_0[0xbU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_h5d3db806_0[0xcU] 
                                                << 6U));
    __Vtemp_hb1d773de__0[0xdU] = ((VTestHarness__ConstPool__CONST_h5d3db806_0[0xcU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_h5d3db806_0[0xdU] 
                                                << 6U));
    __Vtemp_hb1d773de__0[0xeU] = ((VTestHarness__ConstPool__CONST_h5d3db806_0[0xdU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_h5d3db806_0[0xeU] 
                                                << 6U));
    __Vtemp_hb1d773de__0[0xfU] = ((VTestHarness__ConstPool__CONST_h5d3db806_0[0xeU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_h5d3db806_0[0xfU] 
                                                << 6U));
    VL_SHIFTR_WWW(512,512,512, __Vtemp_h2bba0e62__0, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__vb_array, __Vtemp_hb1d773de__0);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s1_tag_hit_1 
        = (__Vtemp_h2bba0e62__0[0U] & ((0xfffffU & 
                                        ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___tag_array_RW0_rdata[1U] 
                                          << 0xbU) 
                                         | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___tag_array_RW0_rdata[0U] 
                                            >> 0x15U))) 
                                       == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___tlb_io_resp_paddr 
                                           >> 0xcU)));
    __Vtemp_hbd919b9c__0[0U] = ((VTestHarness__ConstPool__CONST_hc92a2a60_0[0U] 
                                 << 6U) | (0x3fU & 
                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___tlb_io_resp_paddr 
                                            >> 6U)));
    __Vtemp_hbd919b9c__0[1U] = ((VTestHarness__ConstPool__CONST_hc92a2a60_0[0U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hc92a2a60_0[1U] 
                                              << 6U));
    __Vtemp_hbd919b9c__0[2U] = ((VTestHarness__ConstPool__CONST_hc92a2a60_0[1U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hc92a2a60_0[2U] 
                                              << 6U));
    __Vtemp_hbd919b9c__0[3U] = ((VTestHarness__ConstPool__CONST_hc92a2a60_0[2U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hc92a2a60_0[3U] 
                                              << 6U));
    __Vtemp_hbd919b9c__0[4U] = ((VTestHarness__ConstPool__CONST_hc92a2a60_0[3U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hc92a2a60_0[4U] 
                                              << 6U));
    __Vtemp_hbd919b9c__0[5U] = ((VTestHarness__ConstPool__CONST_hc92a2a60_0[4U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hc92a2a60_0[5U] 
                                              << 6U));
    __Vtemp_hbd919b9c__0[6U] = ((VTestHarness__ConstPool__CONST_hc92a2a60_0[5U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hc92a2a60_0[6U] 
                                              << 6U));
    __Vtemp_hbd919b9c__0[7U] = ((VTestHarness__ConstPool__CONST_hc92a2a60_0[6U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hc92a2a60_0[7U] 
                                              << 6U));
    __Vtemp_hbd919b9c__0[8U] = ((VTestHarness__ConstPool__CONST_hc92a2a60_0[7U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hc92a2a60_0[8U] 
                                              << 6U));
    __Vtemp_hbd919b9c__0[9U] = ((VTestHarness__ConstPool__CONST_hc92a2a60_0[8U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hc92a2a60_0[9U] 
                                              << 6U));
    __Vtemp_hbd919b9c__0[0xaU] = ((VTestHarness__ConstPool__CONST_hc92a2a60_0[9U] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_hc92a2a60_0[0xaU] 
                                                << 6U));
    __Vtemp_hbd919b9c__0[0xbU] = ((VTestHarness__ConstPool__CONST_hc92a2a60_0[0xaU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_hc92a2a60_0[0xbU] 
                                                << 6U));
    __Vtemp_hbd919b9c__0[0xcU] = ((VTestHarness__ConstPool__CONST_hc92a2a60_0[0xbU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_hc92a2a60_0[0xcU] 
                                                << 6U));
    __Vtemp_hbd919b9c__0[0xdU] = ((VTestHarness__ConstPool__CONST_hc92a2a60_0[0xcU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_hc92a2a60_0[0xdU] 
                                                << 6U));
    __Vtemp_hbd919b9c__0[0xeU] = ((VTestHarness__ConstPool__CONST_hc92a2a60_0[0xdU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_hc92a2a60_0[0xeU] 
                                                << 6U));
    __Vtemp_hbd919b9c__0[0xfU] = ((VTestHarness__ConstPool__CONST_hc92a2a60_0[0xeU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_hc92a2a60_0[0xfU] 
                                                << 6U));
    VL_SHIFTR_WWW(512,512,512, __Vtemp_h35f69216__0, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__vb_array, __Vtemp_hbd919b9c__0);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s1_tag_hit_2 
        = (__Vtemp_h35f69216__0[0U] & ((0xfffffU & 
                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___tag_array_RW0_rdata[1U] 
                                         >> 0xaU)) 
                                       == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___tlb_io_resp_paddr 
                                           >> 0xcU)));
    __Vtemp_h8031a0db__0[0U] = ((VTestHarness__ConstPool__CONST_hb2c70161_0[0U] 
                                 << 6U) | (0x3fU & 
                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___tlb_io_resp_paddr 
                                            >> 6U)));
    __Vtemp_h8031a0db__0[1U] = ((VTestHarness__ConstPool__CONST_hb2c70161_0[0U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2c70161_0[1U] 
                                              << 6U));
    __Vtemp_h8031a0db__0[2U] = ((VTestHarness__ConstPool__CONST_hb2c70161_0[1U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2c70161_0[2U] 
                                              << 6U));
    __Vtemp_h8031a0db__0[3U] = ((VTestHarness__ConstPool__CONST_hb2c70161_0[2U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2c70161_0[3U] 
                                              << 6U));
    __Vtemp_h8031a0db__0[4U] = ((VTestHarness__ConstPool__CONST_hb2c70161_0[3U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2c70161_0[4U] 
                                              << 6U));
    __Vtemp_h8031a0db__0[5U] = ((VTestHarness__ConstPool__CONST_hb2c70161_0[4U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2c70161_0[5U] 
                                              << 6U));
    __Vtemp_h8031a0db__0[6U] = ((VTestHarness__ConstPool__CONST_hb2c70161_0[5U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2c70161_0[6U] 
                                              << 6U));
    __Vtemp_h8031a0db__0[7U] = ((VTestHarness__ConstPool__CONST_hb2c70161_0[6U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2c70161_0[7U] 
                                              << 6U));
    __Vtemp_h8031a0db__0[8U] = ((VTestHarness__ConstPool__CONST_hb2c70161_0[7U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2c70161_0[8U] 
                                              << 6U));
    __Vtemp_h8031a0db__0[9U] = ((VTestHarness__ConstPool__CONST_hb2c70161_0[8U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2c70161_0[9U] 
                                              << 6U));
    __Vtemp_h8031a0db__0[0xaU] = ((VTestHarness__ConstPool__CONST_hb2c70161_0[9U] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2c70161_0[0xaU] 
                                                << 6U));
    __Vtemp_h8031a0db__0[0xbU] = ((VTestHarness__ConstPool__CONST_hb2c70161_0[0xaU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2c70161_0[0xbU] 
                                                << 6U));
    __Vtemp_h8031a0db__0[0xcU] = ((VTestHarness__ConstPool__CONST_hb2c70161_0[0xbU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2c70161_0[0xcU] 
                                                << 6U));
    __Vtemp_h8031a0db__0[0xdU] = ((VTestHarness__ConstPool__CONST_hb2c70161_0[0xcU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2c70161_0[0xdU] 
                                                << 6U));
    __Vtemp_h8031a0db__0[0xeU] = ((VTestHarness__ConstPool__CONST_hb2c70161_0[0xdU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2c70161_0[0xeU] 
                                                << 6U));
    __Vtemp_h8031a0db__0[0xfU] = ((VTestHarness__ConstPool__CONST_hb2c70161_0[0xeU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2c70161_0[0xfU] 
                                                << 6U));
    VL_SHIFTR_WWW(512,512,512, __Vtemp_hcf023001__0, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__vb_array, __Vtemp_h8031a0db__0);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s1_tag_hit_3 
        = (__Vtemp_hcf023001__0[0U] & ((0xfffffU & 
                                        ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___tag_array_RW0_rdata[2U] 
                                          << 1U) | 
                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___tag_array_RW0_rdata[1U] 
                                          >> 0x1fU))) 
                                       == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___tlb_io_resp_paddr 
                                           >> 0xcU)));
    __Vtemp_hd69aa3ca__0[0U] = ((VTestHarness__ConstPool__CONST_h7e44c9df_0[0U] 
                                 << 6U) | (0x3fU & 
                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___tlb_io_resp_paddr 
                                            >> 6U)));
    __Vtemp_hd69aa3ca__0[1U] = ((VTestHarness__ConstPool__CONST_h7e44c9df_0[0U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h7e44c9df_0[1U] 
                                              << 6U));
    __Vtemp_hd69aa3ca__0[2U] = ((VTestHarness__ConstPool__CONST_h7e44c9df_0[1U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h7e44c9df_0[2U] 
                                              << 6U));
    __Vtemp_hd69aa3ca__0[3U] = ((VTestHarness__ConstPool__CONST_h7e44c9df_0[2U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h7e44c9df_0[3U] 
                                              << 6U));
    __Vtemp_hd69aa3ca__0[4U] = ((VTestHarness__ConstPool__CONST_h7e44c9df_0[3U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h7e44c9df_0[4U] 
                                              << 6U));
    __Vtemp_hd69aa3ca__0[5U] = ((VTestHarness__ConstPool__CONST_h7e44c9df_0[4U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h7e44c9df_0[5U] 
                                              << 6U));
    __Vtemp_hd69aa3ca__0[6U] = ((VTestHarness__ConstPool__CONST_h7e44c9df_0[5U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h7e44c9df_0[6U] 
                                              << 6U));
    __Vtemp_hd69aa3ca__0[7U] = ((VTestHarness__ConstPool__CONST_h7e44c9df_0[6U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h7e44c9df_0[7U] 
                                              << 6U));
    __Vtemp_hd69aa3ca__0[8U] = ((VTestHarness__ConstPool__CONST_h7e44c9df_0[7U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h7e44c9df_0[8U] 
                                              << 6U));
    __Vtemp_hd69aa3ca__0[9U] = ((VTestHarness__ConstPool__CONST_h7e44c9df_0[8U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h7e44c9df_0[9U] 
                                              << 6U));
    __Vtemp_hd69aa3ca__0[0xaU] = ((VTestHarness__ConstPool__CONST_h7e44c9df_0[9U] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_h7e44c9df_0[0xaU] 
                                                << 6U));
    __Vtemp_hd69aa3ca__0[0xbU] = ((VTestHarness__ConstPool__CONST_h7e44c9df_0[0xaU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_h7e44c9df_0[0xbU] 
                                                << 6U));
    __Vtemp_hd69aa3ca__0[0xcU] = ((VTestHarness__ConstPool__CONST_h7e44c9df_0[0xbU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_h7e44c9df_0[0xcU] 
                                                << 6U));
    __Vtemp_hd69aa3ca__0[0xdU] = ((VTestHarness__ConstPool__CONST_h7e44c9df_0[0xcU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_h7e44c9df_0[0xdU] 
                                                << 6U));
    __Vtemp_hd69aa3ca__0[0xeU] = ((VTestHarness__ConstPool__CONST_h7e44c9df_0[0xdU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_h7e44c9df_0[0xeU] 
                                                << 6U));
    __Vtemp_hd69aa3ca__0[0xfU] = ((VTestHarness__ConstPool__CONST_h7e44c9df_0[0xeU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_h7e44c9df_0[0xfU] 
                                                << 6U));
    VL_SHIFTR_WWW(512,512,512, __Vtemp_hae0bb386__0, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__vb_array, __Vtemp_hd69aa3ca__0);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s1_tag_hit_4 
        = (__Vtemp_hae0bb386__0[0U] & ((0xfffffU & 
                                        ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___tag_array_RW0_rdata[3U] 
                                          << 0xcU) 
                                         | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___tag_array_RW0_rdata[2U] 
                                            >> 0x14U))) 
                                       == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___tlb_io_resp_paddr 
                                           >> 0xcU)));
}

extern const VlWide<16>/*511:0*/ VTestHarness__ConstPool__CONST_h0656ae34_0;
extern const VlWide<16>/*511:0*/ VTestHarness__ConstPool__CONST_hb2bcfdf6_0;
extern const VlWide<16>/*511:0*/ VTestHarness__ConstPool__CONST_had7de141_0;

VL_ATTR_COLD void VTestHarness___024root___settle__TOP__2386(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___settle__TOP__2386\n"); );
    // Init
    VlWide<16>/*511:0*/ __Vtemp_heddac781__0;
    VlWide<16>/*511:0*/ __Vtemp_h38b6001d__0;
    VlWide<16>/*511:0*/ __Vtemp_heea74a21__0;
    VlWide<16>/*511:0*/ __Vtemp_hf903c4c9__0;
    VlWide<16>/*511:0*/ __Vtemp_h5a7b0058__0;
    VlWide<16>/*511:0*/ __Vtemp_h7fcf64a4__0;
    VlWide<16>/*511:0*/ __Vtemp_hdc96b36d__0;
    // Body
    __Vtemp_heddac781__0[0U] = ((VTestHarness__ConstPool__CONST_h0656ae34_0[0U] 
                                 << 6U) | (0x3fU & 
                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___tlb_io_resp_paddr 
                                            >> 6U)));
    __Vtemp_heddac781__0[1U] = ((VTestHarness__ConstPool__CONST_h0656ae34_0[0U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h0656ae34_0[1U] 
                                              << 6U));
    __Vtemp_heddac781__0[2U] = ((VTestHarness__ConstPool__CONST_h0656ae34_0[1U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h0656ae34_0[2U] 
                                              << 6U));
    __Vtemp_heddac781__0[3U] = ((VTestHarness__ConstPool__CONST_h0656ae34_0[2U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h0656ae34_0[3U] 
                                              << 6U));
    __Vtemp_heddac781__0[4U] = ((VTestHarness__ConstPool__CONST_h0656ae34_0[3U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h0656ae34_0[4U] 
                                              << 6U));
    __Vtemp_heddac781__0[5U] = ((VTestHarness__ConstPool__CONST_h0656ae34_0[4U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h0656ae34_0[5U] 
                                              << 6U));
    __Vtemp_heddac781__0[6U] = ((VTestHarness__ConstPool__CONST_h0656ae34_0[5U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h0656ae34_0[6U] 
                                              << 6U));
    __Vtemp_heddac781__0[7U] = ((VTestHarness__ConstPool__CONST_h0656ae34_0[6U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h0656ae34_0[7U] 
                                              << 6U));
    __Vtemp_heddac781__0[8U] = ((VTestHarness__ConstPool__CONST_h0656ae34_0[7U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h0656ae34_0[8U] 
                                              << 6U));
    __Vtemp_heddac781__0[9U] = ((VTestHarness__ConstPool__CONST_h0656ae34_0[8U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_h0656ae34_0[9U] 
                                              << 6U));
    __Vtemp_heddac781__0[0xaU] = ((VTestHarness__ConstPool__CONST_h0656ae34_0[9U] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_h0656ae34_0[0xaU] 
                                                << 6U));
    __Vtemp_heddac781__0[0xbU] = ((VTestHarness__ConstPool__CONST_h0656ae34_0[0xaU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_h0656ae34_0[0xbU] 
                                                << 6U));
    __Vtemp_heddac781__0[0xcU] = ((VTestHarness__ConstPool__CONST_h0656ae34_0[0xbU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_h0656ae34_0[0xcU] 
                                                << 6U));
    __Vtemp_heddac781__0[0xdU] = ((VTestHarness__ConstPool__CONST_h0656ae34_0[0xcU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_h0656ae34_0[0xdU] 
                                                << 6U));
    __Vtemp_heddac781__0[0xeU] = ((VTestHarness__ConstPool__CONST_h0656ae34_0[0xdU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_h0656ae34_0[0xeU] 
                                                << 6U));
    __Vtemp_heddac781__0[0xfU] = ((VTestHarness__ConstPool__CONST_h0656ae34_0[0xeU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_h0656ae34_0[0xfU] 
                                                << 6U));
    VL_SHIFTR_WWW(512,512,512, __Vtemp_h38b6001d__0, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__vb_array, __Vtemp_heddac781__0);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s1_tag_hit_5 
        = (__Vtemp_h38b6001d__0[0U] & ((0xfffffU & 
                                        (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___tag_array_RW0_rdata[3U] 
                                         >> 9U)) == 
                                       (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___tlb_io_resp_paddr 
                                        >> 0xcU)));
    __Vtemp_heea74a21__0[0U] = ((VTestHarness__ConstPool__CONST_hb2bcfdf6_0[0U] 
                                 << 6U) | (0x3fU & 
                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___tlb_io_resp_paddr 
                                            >> 6U)));
    __Vtemp_heea74a21__0[1U] = ((VTestHarness__ConstPool__CONST_hb2bcfdf6_0[0U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2bcfdf6_0[1U] 
                                              << 6U));
    __Vtemp_heea74a21__0[2U] = ((VTestHarness__ConstPool__CONST_hb2bcfdf6_0[1U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2bcfdf6_0[2U] 
                                              << 6U));
    __Vtemp_heea74a21__0[3U] = ((VTestHarness__ConstPool__CONST_hb2bcfdf6_0[2U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2bcfdf6_0[3U] 
                                              << 6U));
    __Vtemp_heea74a21__0[4U] = ((VTestHarness__ConstPool__CONST_hb2bcfdf6_0[3U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2bcfdf6_0[4U] 
                                              << 6U));
    __Vtemp_heea74a21__0[5U] = ((VTestHarness__ConstPool__CONST_hb2bcfdf6_0[4U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2bcfdf6_0[5U] 
                                              << 6U));
    __Vtemp_heea74a21__0[6U] = ((VTestHarness__ConstPool__CONST_hb2bcfdf6_0[5U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2bcfdf6_0[6U] 
                                              << 6U));
    __Vtemp_heea74a21__0[7U] = ((VTestHarness__ConstPool__CONST_hb2bcfdf6_0[6U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2bcfdf6_0[7U] 
                                              << 6U));
    __Vtemp_heea74a21__0[8U] = ((VTestHarness__ConstPool__CONST_hb2bcfdf6_0[7U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2bcfdf6_0[8U] 
                                              << 6U));
    __Vtemp_heea74a21__0[9U] = ((VTestHarness__ConstPool__CONST_hb2bcfdf6_0[8U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2bcfdf6_0[9U] 
                                              << 6U));
    __Vtemp_heea74a21__0[0xaU] = ((VTestHarness__ConstPool__CONST_hb2bcfdf6_0[9U] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2bcfdf6_0[0xaU] 
                                                << 6U));
    __Vtemp_heea74a21__0[0xbU] = ((VTestHarness__ConstPool__CONST_hb2bcfdf6_0[0xaU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2bcfdf6_0[0xbU] 
                                                << 6U));
    __Vtemp_heea74a21__0[0xcU] = ((VTestHarness__ConstPool__CONST_hb2bcfdf6_0[0xbU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2bcfdf6_0[0xcU] 
                                                << 6U));
    __Vtemp_heea74a21__0[0xdU] = ((VTestHarness__ConstPool__CONST_hb2bcfdf6_0[0xcU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2bcfdf6_0[0xdU] 
                                                << 6U));
    __Vtemp_heea74a21__0[0xeU] = ((VTestHarness__ConstPool__CONST_hb2bcfdf6_0[0xdU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2bcfdf6_0[0xeU] 
                                                << 6U));
    __Vtemp_heea74a21__0[0xfU] = ((VTestHarness__ConstPool__CONST_hb2bcfdf6_0[0xeU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_hb2bcfdf6_0[0xfU] 
                                                << 6U));
    VL_SHIFTR_WWW(512,512,512, __Vtemp_hf903c4c9__0, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__vb_array, __Vtemp_heea74a21__0);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s1_tag_hit_6 
        = (__Vtemp_hf903c4c9__0[0U] & ((0xfffffU & 
                                        ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___tag_array_RW0_rdata[4U] 
                                          << 2U) | 
                                         (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___tag_array_RW0_rdata[3U] 
                                          >> 0x1eU))) 
                                       == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___tlb_io_resp_paddr 
                                           >> 0xcU)));
    __Vtemp_h5a7b0058__0[0U] = ((VTestHarness__ConstPool__CONST_had7de141_0[0U] 
                                 << 6U) | (0x3fU & 
                                           (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___tlb_io_resp_paddr 
                                            >> 6U)));
    __Vtemp_h5a7b0058__0[1U] = ((VTestHarness__ConstPool__CONST_had7de141_0[0U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_had7de141_0[1U] 
                                              << 6U));
    __Vtemp_h5a7b0058__0[2U] = ((VTestHarness__ConstPool__CONST_had7de141_0[1U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_had7de141_0[2U] 
                                              << 6U));
    __Vtemp_h5a7b0058__0[3U] = ((VTestHarness__ConstPool__CONST_had7de141_0[2U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_had7de141_0[3U] 
                                              << 6U));
    __Vtemp_h5a7b0058__0[4U] = ((VTestHarness__ConstPool__CONST_had7de141_0[3U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_had7de141_0[4U] 
                                              << 6U));
    __Vtemp_h5a7b0058__0[5U] = ((VTestHarness__ConstPool__CONST_had7de141_0[4U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_had7de141_0[5U] 
                                              << 6U));
    __Vtemp_h5a7b0058__0[6U] = ((VTestHarness__ConstPool__CONST_had7de141_0[5U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_had7de141_0[6U] 
                                              << 6U));
    __Vtemp_h5a7b0058__0[7U] = ((VTestHarness__ConstPool__CONST_had7de141_0[6U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_had7de141_0[7U] 
                                              << 6U));
    __Vtemp_h5a7b0058__0[8U] = ((VTestHarness__ConstPool__CONST_had7de141_0[7U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_had7de141_0[8U] 
                                              << 6U));
    __Vtemp_h5a7b0058__0[9U] = ((VTestHarness__ConstPool__CONST_had7de141_0[8U] 
                                 >> 0x1aU) | (VTestHarness__ConstPool__CONST_had7de141_0[9U] 
                                              << 6U));
    __Vtemp_h5a7b0058__0[0xaU] = ((VTestHarness__ConstPool__CONST_had7de141_0[9U] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_had7de141_0[0xaU] 
                                                << 6U));
    __Vtemp_h5a7b0058__0[0xbU] = ((VTestHarness__ConstPool__CONST_had7de141_0[0xaU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_had7de141_0[0xbU] 
                                                << 6U));
    __Vtemp_h5a7b0058__0[0xcU] = ((VTestHarness__ConstPool__CONST_had7de141_0[0xbU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_had7de141_0[0xcU] 
                                                << 6U));
    __Vtemp_h5a7b0058__0[0xdU] = ((VTestHarness__ConstPool__CONST_had7de141_0[0xcU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_had7de141_0[0xdU] 
                                                << 6U));
    __Vtemp_h5a7b0058__0[0xeU] = ((VTestHarness__ConstPool__CONST_had7de141_0[0xdU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_had7de141_0[0xeU] 
                                                << 6U));
    __Vtemp_h5a7b0058__0[0xfU] = ((VTestHarness__ConstPool__CONST_had7de141_0[0xeU] 
                                   >> 0x1aU) | (VTestHarness__ConstPool__CONST_had7de141_0[0xfU] 
                                                << 6U));
    VL_SHIFTR_WWW(512,512,512, __Vtemp_h7fcf64a4__0, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__vb_array, __Vtemp_h5a7b0058__0);
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s1_tag_hit_7 
        = (__Vtemp_h7fcf64a4__0[0U] & ((0xfffffU & 
                                        ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___tag_array_RW0_rdata[5U] 
                                          << 0xdU) 
                                         | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___tag_array_RW0_rdata[4U] 
                                            >> 0x13U))) 
                                       == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT___tlb_io_resp_paddr 
                                           >> 0xcU)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_leftOne_8 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__hitsVec_6) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_1__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_6));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_4 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__hitsVec_3) 
           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__multipleHits_rightOne_3));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___T_36 
        = (IData)((0U != (5U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___GEN_109))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__tlb_miss 
        = (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT___vm_enabled_T_1) 
            & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__bad_va))) 
           & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__tlb__DOT__real_hits)));
    VL_SHIFTR_WWI(512,512,6, __Vtemp_hdc96b36d__0, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__vb_array, 
                  (0x3fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT___tlb_io_resp_paddr 
                            >> 6U)));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT__s1_tag_hit_0 
        = (__Vtemp_hdc96b36d__0[0U] & ((0xfffffU & 
                                        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT__icache__DOT___tag_array_RW0_rdata[0U]) 
                                       == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain_2__DOT__tile_reset_domain_tile__DOT__frontend__DOT___tlb_io_resp_paddr 
                                           >> 0xcU)));
}
