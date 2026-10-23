// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTestHarness.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTestHarness___024root.h"

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__14595(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__14595\n"); );
    // Body
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset) {
        vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1 = 0U;
        vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1 = 0U;
        vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__a_first_counter_1 = 0U;
        vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__a_first_counter_1 = 0U;
    } else {
        if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1187) {
            vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1 
                = (7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__a_first_1)
                          ? ((4U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])
                              ? 0U : (~ (((0xcU >= 
                                           (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 6U)))
                                           ? (0x1fffU 
                                              & ((IData)(0x3fU) 
                                                 << 
                                                 (7U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 6U))))
                                           : 0U) >> 3U)))
                          : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1) 
                             - (IData)(1U))));
        }
        if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1187) {
            vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1 
                = (7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__a_first_1)
                          ? ((4U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])
                              ? 0U : (~ (((0xcU >= 
                                           (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 6U)))
                                           ? (0x1fffU 
                                              & ((IData)(0x3fU) 
                                                 << 
                                                 (7U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 6U))))
                                           : 0U) >> 3U)))
                          : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__a_first_counter_1) 
                             - (IData)(1U))));
        }
        if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT___T_1247) {
            vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__a_first_counter_1 
                = (7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__a_first_1)
                          ? ((4U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])
                              ? 0U : (~ (((0xcU >= 
                                           (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 6U)))
                                           ? (0x1fffU 
                                              & ((IData)(0x3fU) 
                                                 << 
                                                 (7U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 6U))))
                                           : 0U) >> 3U)))
                          : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__out_xbar__DOT__monitor__DOT__a_first_counter_1) 
                             - (IData)(1U))));
        }
        if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT___T_1247) {
            vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__a_first_counter_1 
                = (7U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__a_first_1)
                          ? ((4U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U])
                              ? 0U : (~ (((0xcU >= 
                                           (7U & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 6U)))
                                           ? (0x1fffU 
                                              & ((IData)(0x3fU) 
                                                 << 
                                                 (7U 
                                                  & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                     >> 6U))))
                                           : 0U) >> 3U)))
                          : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__fixer__DOT__monitor__DOT__a_first_counter_1) 
                             - (IData)(1U))));
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__14596(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__14596\n"); );
    // Body
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__repeater__DOT___T_1) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__repeater__DOT__saved_address 
            = (0x7fffffffU & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[1U] 
                               << 0x10U) | (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                            >> 0x10U)));
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__repeater__DOT___T_1) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__repeater__DOT__saved_address 
            = (0x7fffU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                          >> 0x10U));
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1358) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_31_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1356) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_29_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1355) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_28_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1353) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_26_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1352) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_25_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1350) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_23_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1349) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_22_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1347) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_20_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1351) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_24_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1348) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_21_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1345) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_18_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1331) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_4_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1342) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_15_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1344) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_17_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1333) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_6_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1336) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_9_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1327) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_0_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
}

extern const VlWide<33>/*1055:0*/ VTestHarness__ConstPool__CONST_h3892cc72_0;
extern const VlWide<9>/*287:0*/ VTestHarness__ConstPool__CONST_h52851b57_0;
extern const VlWide<9>/*287:0*/ VTestHarness__ConstPool__CONST_h478702bb_0;
extern const VlWide<33>/*1055:0*/ VTestHarness__ConstPool__CONST_hf1d99c76_0;
extern const VlWide<33>/*1055:0*/ VTestHarness__ConstPool__CONST_hf1d81c7e_0;

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__14597(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__14597\n"); );
    // Init
    VlWide<9>/*287:0*/ __Vtemp_hb1a1b589__0;
    VlWide<33>/*1055:0*/ __Vtemp_hffa2f4f0__0;
    VlWide<33>/*1055:0*/ __Vtemp_h2140e76b__0;
    VlWide<33>/*1055:0*/ __Vtemp_h6a657119__0;
    VlWide<33>/*1055:0*/ __Vtemp_h07df103e__0;
    VlWide<33>/*1055:0*/ __Vtemp_h94226a89__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9daf4ef3__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9cb211d0__0;
    // Body
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1328) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_1_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1339) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_12_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1354) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_27_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1334) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_7_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1357) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_30_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1337) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_10_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1340) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_13_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1329) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_2_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1330) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_3_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1332) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_5_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1335) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_8_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1338) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_11_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1341) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_14_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1343) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_16_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT___GEN_1346) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_19_flush_on_commit 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rename_stage__DOT__r_uop_1_flush_on_commit;
    }
    VL_EXTEND_WI(1027,4, __Vtemp_hffa2f4f0__0, ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                                 ? 
                                                (1U 
                                                 | (0xeU 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       << 1U)))
                                                 : 0U));
    VL_EXTEND_WI(1025,7, __Vtemp_h2140e76b__0, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 9U)));
    __Vtemp_h6a657119__0[0U] = (__Vtemp_h2140e76b__0[0U] 
                                << 2U);
    __Vtemp_h6a657119__0[1U] = ((__Vtemp_h2140e76b__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[1U] 
                                              << 2U));
    __Vtemp_h6a657119__0[2U] = ((__Vtemp_h2140e76b__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[2U] 
                                              << 2U));
    __Vtemp_h6a657119__0[3U] = ((__Vtemp_h2140e76b__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[3U] 
                                              << 2U));
    __Vtemp_h6a657119__0[4U] = ((__Vtemp_h2140e76b__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[4U] 
                                              << 2U));
    __Vtemp_h6a657119__0[5U] = ((__Vtemp_h2140e76b__0[4U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[5U] 
                                              << 2U));
    __Vtemp_h6a657119__0[6U] = ((__Vtemp_h2140e76b__0[5U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[6U] 
                                              << 2U));
    __Vtemp_h6a657119__0[7U] = ((__Vtemp_h2140e76b__0[6U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[7U] 
                                              << 2U));
    __Vtemp_h6a657119__0[8U] = ((__Vtemp_h2140e76b__0[7U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[8U] 
                                              << 2U));
    __Vtemp_h6a657119__0[9U] = ((__Vtemp_h2140e76b__0[8U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[9U] 
                                              << 2U));
    __Vtemp_h6a657119__0[0xaU] = ((__Vtemp_h2140e76b__0[9U] 
                                   >> 0x1eU) | (__Vtemp_h2140e76b__0[0xaU] 
                                                << 2U));
    __Vtemp_h6a657119__0[0xbU] = ((__Vtemp_h2140e76b__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h2140e76b__0[0xbU] 
                                                << 2U));
    __Vtemp_h6a657119__0[0xcU] = ((__Vtemp_h2140e76b__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h2140e76b__0[0xcU] 
                                                << 2U));
    __Vtemp_h6a657119__0[0xdU] = ((__Vtemp_h2140e76b__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h2140e76b__0[0xdU] 
                                                << 2U));
    __Vtemp_h6a657119__0[0xeU] = ((__Vtemp_h2140e76b__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h2140e76b__0[0xeU] 
                                                << 2U));
    __Vtemp_h6a657119__0[0xfU] = ((__Vtemp_h2140e76b__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h2140e76b__0[0xfU] 
                                                << 2U));
    __Vtemp_h6a657119__0[0x10U] = ((__Vtemp_h2140e76b__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x10U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x11U] = ((__Vtemp_h2140e76b__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x11U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x12U] = ((__Vtemp_h2140e76b__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x12U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x13U] = ((__Vtemp_h2140e76b__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x13U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x14U] = ((__Vtemp_h2140e76b__0[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x14U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x15U] = ((__Vtemp_h2140e76b__0[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x15U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x16U] = ((__Vtemp_h2140e76b__0[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x16U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x17U] = ((__Vtemp_h2140e76b__0[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x17U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x18U] = ((__Vtemp_h2140e76b__0[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x18U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x19U] = ((__Vtemp_h2140e76b__0[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x19U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x1aU] = ((__Vtemp_h2140e76b__0[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x1aU] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x1bU] = ((__Vtemp_h2140e76b__0[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x1bU] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x1cU] = ((__Vtemp_h2140e76b__0[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x1cU] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x1dU] = ((__Vtemp_h2140e76b__0[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x1dU] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x1eU] = ((__Vtemp_h2140e76b__0[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x1eU] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x1fU] = ((__Vtemp_h2140e76b__0[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x1fU] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x20U] = ((__Vtemp_h2140e76b__0[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1027,1027,1027, __Vtemp_h07df103e__0, __Vtemp_hffa2f4f0__0, __Vtemp_h6a657119__0);
    VL_EXTEND_WI(1037,7, __Vtemp_h94226a89__0, (0x7fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT___coupler_to_slave_named_bootaddressreg_auto_fragmenter_out_a_bits_source) 
                                                   >> 4U)));
    __Vtemp_h9daf4ef3__0[0U] = (__Vtemp_h94226a89__0[0U] 
                                << 2U);
    __Vtemp_h9daf4ef3__0[1U] = ((__Vtemp_h94226a89__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h94226a89__0[1U] 
                                              << 2U));
    __Vtemp_h9daf4ef3__0[2U] = ((__Vtemp_h94226a89__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h94226a89__0[2U] 
                                              << 2U));
    __Vtemp_h9daf4ef3__0[3U] = ((__Vtemp_h94226a89__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h94226a89__0[3U] 
                                              << 2U));
    __Vtemp_h9daf4ef3__0[4U] = ((__Vtemp_h94226a89__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h94226a89__0[4U] 
                                              << 2U));
    __Vtemp_h9daf4ef3__0[5U] = ((__Vtemp_h94226a89__0[4U] 
                                 >> 0x1eU) | (__Vtemp_h94226a89__0[5U] 
                                              << 2U));
    __Vtemp_h9daf4ef3__0[6U] = ((__Vtemp_h94226a89__0[5U] 
                                 >> 0x1eU) | (__Vtemp_h94226a89__0[6U] 
                                              << 2U));
    __Vtemp_h9daf4ef3__0[7U] = ((__Vtemp_h94226a89__0[6U] 
                                 >> 0x1eU) | (__Vtemp_h94226a89__0[7U] 
                                              << 2U));
    __Vtemp_h9daf4ef3__0[8U] = ((__Vtemp_h94226a89__0[7U] 
                                 >> 0x1eU) | (__Vtemp_h94226a89__0[8U] 
                                              << 2U));
    __Vtemp_h9daf4ef3__0[9U] = ((__Vtemp_h94226a89__0[8U] 
                                 >> 0x1eU) | (__Vtemp_h94226a89__0[9U] 
                                              << 2U));
    __Vtemp_h9daf4ef3__0[0xaU] = ((__Vtemp_h94226a89__0[9U] 
                                   >> 0x1eU) | (__Vtemp_h94226a89__0[0xaU] 
                                                << 2U));
    __Vtemp_h9daf4ef3__0[0xbU] = ((__Vtemp_h94226a89__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h94226a89__0[0xbU] 
                                                << 2U));
    __Vtemp_h9daf4ef3__0[0xcU] = ((__Vtemp_h94226a89__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h94226a89__0[0xcU] 
                                                << 2U));
    __Vtemp_h9daf4ef3__0[0xdU] = ((__Vtemp_h94226a89__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h94226a89__0[0xdU] 
                                                << 2U));
    __Vtemp_h9daf4ef3__0[0xeU] = ((__Vtemp_h94226a89__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h94226a89__0[0xeU] 
                                                << 2U));
    __Vtemp_h9daf4ef3__0[0xfU] = ((__Vtemp_h94226a89__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h94226a89__0[0xfU] 
                                                << 2U));
    __Vtemp_h9daf4ef3__0[0x10U] = ((__Vtemp_h94226a89__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x10U] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x11U] = ((__Vtemp_h94226a89__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x11U] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x12U] = ((__Vtemp_h94226a89__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x12U] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x13U] = ((__Vtemp_h94226a89__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x13U] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x14U] = ((__Vtemp_h94226a89__0[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x14U] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x15U] = ((__Vtemp_h94226a89__0[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x15U] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x16U] = ((__Vtemp_h94226a89__0[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x16U] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x17U] = ((__Vtemp_h94226a89__0[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x17U] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x18U] = ((__Vtemp_h94226a89__0[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x18U] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x19U] = ((__Vtemp_h94226a89__0[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x19U] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x1aU] = ((__Vtemp_h94226a89__0[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x1aU] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x1bU] = ((__Vtemp_h94226a89__0[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x1bU] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x1cU] = ((__Vtemp_h94226a89__0[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x1cU] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x1dU] = ((__Vtemp_h94226a89__0[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x1dU] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x1eU] = ((__Vtemp_h94226a89__0[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x1eU] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x1fU] = ((__Vtemp_h94226a89__0[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x1fU] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x20U] = ((__Vtemp_h94226a89__0[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1039,1039,1039, __Vtemp_h9cb211d0__0, VTestHarness__ConstPool__CONST_h3892cc72_0, __Vtemp_h9daf4ef3__0);
    __Vtemp_hb1a1b589__0[1U] = (VTestHarness__ConstPool__CONST_h52851b57_0[1U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[1U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[1U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[1U] 
                                               & __Vtemp_h07df103e__0[1U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[1U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[1U] 
                                                 & __Vtemp_h9cb211d0__0[1U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[1U])))));
    __Vtemp_hb1a1b589__0[2U] = (VTestHarness__ConstPool__CONST_h52851b57_0[2U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[2U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[2U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[2U] 
                                               & __Vtemp_h07df103e__0[2U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[2U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[2U] 
                                                 & __Vtemp_h9cb211d0__0[2U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[2U])))));
    __Vtemp_hb1a1b589__0[3U] = (VTestHarness__ConstPool__CONST_h52851b57_0[3U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[3U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[3U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[3U] 
                                               & __Vtemp_h07df103e__0[3U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[3U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[3U] 
                                                 & __Vtemp_h9cb211d0__0[3U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[3U])))));
    __Vtemp_hb1a1b589__0[4U] = (VTestHarness__ConstPool__CONST_h52851b57_0[4U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[4U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[4U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[4U] 
                                               & __Vtemp_h07df103e__0[4U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[4U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[4U] 
                                                 & __Vtemp_h9cb211d0__0[4U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[4U])))));
    __Vtemp_hb1a1b589__0[5U] = (VTestHarness__ConstPool__CONST_h52851b57_0[5U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[5U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[5U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[5U] 
                                               & __Vtemp_h07df103e__0[5U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[5U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[5U] 
                                                 & __Vtemp_h9cb211d0__0[5U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[5U])))));
    __Vtemp_hb1a1b589__0[6U] = (VTestHarness__ConstPool__CONST_h52851b57_0[6U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[6U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[6U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[6U] 
                                               & __Vtemp_h07df103e__0[6U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[6U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[6U] 
                                                 & __Vtemp_h9cb211d0__0[6U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[6U])))));
    __Vtemp_hb1a1b589__0[7U] = (VTestHarness__ConstPool__CONST_h52851b57_0[7U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[7U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[7U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[7U] 
                                               & __Vtemp_h07df103e__0[7U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[7U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[7U] 
                                                 & __Vtemp_h9cb211d0__0[7U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[7U])))));
    __Vtemp_hb1a1b589__0[8U] = (VTestHarness__ConstPool__CONST_h52851b57_0[8U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[8U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[8U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[8U] 
                                               & __Vtemp_h07df103e__0[8U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[8U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[8U] 
                                                 & __Vtemp_h9cb211d0__0[8U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[8U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[0U] 
        = (VTestHarness__ConstPool__CONST_h52851b57_0[0U] 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
               ? VTestHarness__ConstPool__CONST_h478702bb_0[0U]
               : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[0U] 
                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                       ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[0U] 
                          & __Vtemp_h07df103e__0[0U])
                       : VTestHarness__ConstPool__CONST_h478702bb_0[0U])) 
                  & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                         ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[0U] 
                            & __Vtemp_h9cb211d0__0[0U])
                         : VTestHarness__ConstPool__CONST_h478702bb_0[0U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[1U] 
        = __Vtemp_hb1a1b589__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[2U] 
        = __Vtemp_hb1a1b589__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[3U] 
        = __Vtemp_hb1a1b589__0[3U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[4U] 
        = __Vtemp_hb1a1b589__0[4U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[5U] 
        = __Vtemp_hb1a1b589__0[5U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[6U] 
        = __Vtemp_hb1a1b589__0[6U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[7U] 
        = __Vtemp_hb1a1b589__0[7U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[8U] 
        = __Vtemp_hb1a1b589__0[8U];
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__14598(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__14598\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_h1ae25c36__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__0;
    VlWide<4>/*127:0*/ __Vtemp_h4c070d9e__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__1;
    VlWide<4>/*127:0*/ __Vtemp_h11d337fa__0;
    VlWide<9>/*287:0*/ __Vtemp_hf771afeb__0;
    VlWide<33>/*1055:0*/ __Vtemp_hf1fd3d45__0;
    VlWide<33>/*1055:0*/ __Vtemp_h2140e76b__0;
    VlWide<33>/*1055:0*/ __Vtemp_h6a657119__0;
    VlWide<33>/*1055:0*/ __Vtemp_h7b4a04a4__0;
    VlWide<33>/*1055:0*/ __Vtemp_h94226a89__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9daf4ef3__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9cb211d0__0;
    VlWide<9>/*287:0*/ __Vtemp_h6cea73da__0;
    VlWide<33>/*1055:0*/ __Vtemp_heec21cf4__0;
    VlWide<33>/*1055:0*/ __Vtemp_h2140e76b__1;
    VlWide<33>/*1055:0*/ __Vtemp_hbd131450__0;
    VlWide<33>/*1055:0*/ __Vtemp_h0ff86d47__0;
    VlWide<33>/*1055:0*/ __Vtemp_h0f47d476__0;
    VlWide<33>/*1055:0*/ __Vtemp_hb5c5ee55__0;
    VlWide<33>/*1055:0*/ __Vtemp_h623ba2b7__0;
    // Body
    __Vtemp_hc961d23f__0[0U] = 1U;
    __Vtemp_hc961d23f__0[1U] = 0U;
    __Vtemp_hc961d23f__0[2U] = 0U;
    __Vtemp_hc961d23f__0[3U] = 0U;
    VL_SHIFTL_WWI(128,128,7, __Vtemp_h4c070d9e__0, __Vtemp_hc961d23f__0, 
                  (0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                            >> 9U)));
    __Vtemp_hc961d23f__1[0U] = 1U;
    __Vtemp_hc961d23f__1[1U] = 0U;
    __Vtemp_hc961d23f__1[2U] = 0U;
    __Vtemp_hc961d23f__1[3U] = 0U;
    VL_SHIFTL_WWI(128,128,7, __Vtemp_h11d337fa__0, __Vtemp_hc961d23f__1, 
                  (0x7fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT___coupler_to_slave_named_bootaddressreg_auto_fragmenter_out_a_bits_source) 
                            >> 4U)));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset) {
        __Vtemp_h1ae25c36__0[1U] = 0U;
        __Vtemp_h1ae25c36__0[2U] = 0U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight[0U] = 0U;
    } else {
        __Vtemp_h1ae25c36__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight[1U] 
                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                         ? __Vtemp_h4c070d9e__0[1U]
                                         : 0U)) & (~ 
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                                     ? 
                                                    __Vtemp_h11d337fa__0[1U]
                                                     : 0U)));
        __Vtemp_h1ae25c36__0[2U] = (1U & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight[2U] 
                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                               ? __Vtemp_h4c070d9e__0[2U]
                                               : 0U)) 
                                          & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                                 ? 
                                                __Vtemp_h11d337fa__0[2U]
                                                 : 0U))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight[0U] 
            = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight[0U] 
                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                    ? __Vtemp_h4c070d9e__0[0U] : 0U)) 
               & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                      ? __Vtemp_h11d337fa__0[0U] : 0U)));
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight[1U] 
        = __Vtemp_h1ae25c36__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight[2U] 
        = __Vtemp_h1ae25c36__0[2U];
    VL_EXTEND_WI(1027,4, __Vtemp_hf1fd3d45__0, ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                                 ? 
                                                (1U 
                                                 | (0xeU 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       >> 5U)))
                                                 : 0U));
    VL_EXTEND_WI(1025,7, __Vtemp_h2140e76b__0, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 9U)));
    __Vtemp_h6a657119__0[0U] = (__Vtemp_h2140e76b__0[0U] 
                                << 2U);
    __Vtemp_h6a657119__0[1U] = ((__Vtemp_h2140e76b__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[1U] 
                                              << 2U));
    __Vtemp_h6a657119__0[2U] = ((__Vtemp_h2140e76b__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[2U] 
                                              << 2U));
    __Vtemp_h6a657119__0[3U] = ((__Vtemp_h2140e76b__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[3U] 
                                              << 2U));
    __Vtemp_h6a657119__0[4U] = ((__Vtemp_h2140e76b__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[4U] 
                                              << 2U));
    __Vtemp_h6a657119__0[5U] = ((__Vtemp_h2140e76b__0[4U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[5U] 
                                              << 2U));
    __Vtemp_h6a657119__0[6U] = ((__Vtemp_h2140e76b__0[5U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[6U] 
                                              << 2U));
    __Vtemp_h6a657119__0[7U] = ((__Vtemp_h2140e76b__0[6U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[7U] 
                                              << 2U));
    __Vtemp_h6a657119__0[8U] = ((__Vtemp_h2140e76b__0[7U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[8U] 
                                              << 2U));
    __Vtemp_h6a657119__0[9U] = ((__Vtemp_h2140e76b__0[8U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[9U] 
                                              << 2U));
    __Vtemp_h6a657119__0[0xaU] = ((__Vtemp_h2140e76b__0[9U] 
                                   >> 0x1eU) | (__Vtemp_h2140e76b__0[0xaU] 
                                                << 2U));
    __Vtemp_h6a657119__0[0xbU] = ((__Vtemp_h2140e76b__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h2140e76b__0[0xbU] 
                                                << 2U));
    __Vtemp_h6a657119__0[0xcU] = ((__Vtemp_h2140e76b__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h2140e76b__0[0xcU] 
                                                << 2U));
    __Vtemp_h6a657119__0[0xdU] = ((__Vtemp_h2140e76b__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h2140e76b__0[0xdU] 
                                                << 2U));
    __Vtemp_h6a657119__0[0xeU] = ((__Vtemp_h2140e76b__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h2140e76b__0[0xeU] 
                                                << 2U));
    __Vtemp_h6a657119__0[0xfU] = ((__Vtemp_h2140e76b__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h2140e76b__0[0xfU] 
                                                << 2U));
    __Vtemp_h6a657119__0[0x10U] = ((__Vtemp_h2140e76b__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x10U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x11U] = ((__Vtemp_h2140e76b__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x11U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x12U] = ((__Vtemp_h2140e76b__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x12U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x13U] = ((__Vtemp_h2140e76b__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x13U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x14U] = ((__Vtemp_h2140e76b__0[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x14U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x15U] = ((__Vtemp_h2140e76b__0[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x15U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x16U] = ((__Vtemp_h2140e76b__0[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x16U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x17U] = ((__Vtemp_h2140e76b__0[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x17U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x18U] = ((__Vtemp_h2140e76b__0[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x18U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x19U] = ((__Vtemp_h2140e76b__0[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x19U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x1aU] = ((__Vtemp_h2140e76b__0[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x1aU] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x1bU] = ((__Vtemp_h2140e76b__0[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x1bU] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x1cU] = ((__Vtemp_h2140e76b__0[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x1cU] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x1dU] = ((__Vtemp_h2140e76b__0[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x1dU] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x1eU] = ((__Vtemp_h2140e76b__0[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x1eU] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x1fU] = ((__Vtemp_h2140e76b__0[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x1fU] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x20U] = ((__Vtemp_h2140e76b__0[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1027,1027,1027, __Vtemp_h7b4a04a4__0, __Vtemp_hf1fd3d45__0, __Vtemp_h6a657119__0);
    VL_EXTEND_WI(1037,7, __Vtemp_h94226a89__0, (0x7fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT___coupler_to_slave_named_bootaddressreg_auto_fragmenter_out_a_bits_source) 
                                                   >> 4U)));
    __Vtemp_h9daf4ef3__0[0U] = (__Vtemp_h94226a89__0[0U] 
                                << 2U);
    __Vtemp_h9daf4ef3__0[1U] = ((__Vtemp_h94226a89__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h94226a89__0[1U] 
                                              << 2U));
    __Vtemp_h9daf4ef3__0[2U] = ((__Vtemp_h94226a89__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h94226a89__0[2U] 
                                              << 2U));
    __Vtemp_h9daf4ef3__0[3U] = ((__Vtemp_h94226a89__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h94226a89__0[3U] 
                                              << 2U));
    __Vtemp_h9daf4ef3__0[4U] = ((__Vtemp_h94226a89__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h94226a89__0[4U] 
                                              << 2U));
    __Vtemp_h9daf4ef3__0[5U] = ((__Vtemp_h94226a89__0[4U] 
                                 >> 0x1eU) | (__Vtemp_h94226a89__0[5U] 
                                              << 2U));
    __Vtemp_h9daf4ef3__0[6U] = ((__Vtemp_h94226a89__0[5U] 
                                 >> 0x1eU) | (__Vtemp_h94226a89__0[6U] 
                                              << 2U));
    __Vtemp_h9daf4ef3__0[7U] = ((__Vtemp_h94226a89__0[6U] 
                                 >> 0x1eU) | (__Vtemp_h94226a89__0[7U] 
                                              << 2U));
    __Vtemp_h9daf4ef3__0[8U] = ((__Vtemp_h94226a89__0[7U] 
                                 >> 0x1eU) | (__Vtemp_h94226a89__0[8U] 
                                              << 2U));
    __Vtemp_h9daf4ef3__0[9U] = ((__Vtemp_h94226a89__0[8U] 
                                 >> 0x1eU) | (__Vtemp_h94226a89__0[9U] 
                                              << 2U));
    __Vtemp_h9daf4ef3__0[0xaU] = ((__Vtemp_h94226a89__0[9U] 
                                   >> 0x1eU) | (__Vtemp_h94226a89__0[0xaU] 
                                                << 2U));
    __Vtemp_h9daf4ef3__0[0xbU] = ((__Vtemp_h94226a89__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h94226a89__0[0xbU] 
                                                << 2U));
    __Vtemp_h9daf4ef3__0[0xcU] = ((__Vtemp_h94226a89__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h94226a89__0[0xcU] 
                                                << 2U));
    __Vtemp_h9daf4ef3__0[0xdU] = ((__Vtemp_h94226a89__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h94226a89__0[0xdU] 
                                                << 2U));
    __Vtemp_h9daf4ef3__0[0xeU] = ((__Vtemp_h94226a89__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h94226a89__0[0xeU] 
                                                << 2U));
    __Vtemp_h9daf4ef3__0[0xfU] = ((__Vtemp_h94226a89__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h94226a89__0[0xfU] 
                                                << 2U));
    __Vtemp_h9daf4ef3__0[0x10U] = ((__Vtemp_h94226a89__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x10U] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x11U] = ((__Vtemp_h94226a89__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x11U] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x12U] = ((__Vtemp_h94226a89__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x12U] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x13U] = ((__Vtemp_h94226a89__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x13U] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x14U] = ((__Vtemp_h94226a89__0[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x14U] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x15U] = ((__Vtemp_h94226a89__0[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x15U] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x16U] = ((__Vtemp_h94226a89__0[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x16U] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x17U] = ((__Vtemp_h94226a89__0[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x17U] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x18U] = ((__Vtemp_h94226a89__0[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x18U] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x19U] = ((__Vtemp_h94226a89__0[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x19U] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x1aU] = ((__Vtemp_h94226a89__0[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x1aU] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x1bU] = ((__Vtemp_h94226a89__0[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x1bU] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x1cU] = ((__Vtemp_h94226a89__0[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x1cU] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x1dU] = ((__Vtemp_h94226a89__0[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x1dU] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x1eU] = ((__Vtemp_h94226a89__0[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x1eU] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x1fU] = ((__Vtemp_h94226a89__0[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x1fU] 
                                                 << 2U));
    __Vtemp_h9daf4ef3__0[0x20U] = ((__Vtemp_h94226a89__0[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h94226a89__0[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1039,1039,1039, __Vtemp_h9cb211d0__0, VTestHarness__ConstPool__CONST_h3892cc72_0, __Vtemp_h9daf4ef3__0);
    __Vtemp_hf771afeb__0[1U] = (VTestHarness__ConstPool__CONST_h52851b57_0[1U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[1U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[1U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[1U] 
                                               & __Vtemp_h7b4a04a4__0[1U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[1U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[1U] 
                                                 & __Vtemp_h9cb211d0__0[1U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[1U])))));
    __Vtemp_hf771afeb__0[2U] = (VTestHarness__ConstPool__CONST_h52851b57_0[2U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[2U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[2U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[2U] 
                                               & __Vtemp_h7b4a04a4__0[2U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[2U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[2U] 
                                                 & __Vtemp_h9cb211d0__0[2U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[2U])))));
    __Vtemp_hf771afeb__0[3U] = (VTestHarness__ConstPool__CONST_h52851b57_0[3U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[3U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[3U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[3U] 
                                               & __Vtemp_h7b4a04a4__0[3U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[3U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[3U] 
                                                 & __Vtemp_h9cb211d0__0[3U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[3U])))));
    __Vtemp_hf771afeb__0[4U] = (VTestHarness__ConstPool__CONST_h52851b57_0[4U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[4U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[4U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[4U] 
                                               & __Vtemp_h7b4a04a4__0[4U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[4U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[4U] 
                                                 & __Vtemp_h9cb211d0__0[4U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[4U])))));
    __Vtemp_hf771afeb__0[5U] = (VTestHarness__ConstPool__CONST_h52851b57_0[5U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[5U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[5U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[5U] 
                                               & __Vtemp_h7b4a04a4__0[5U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[5U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[5U] 
                                                 & __Vtemp_h9cb211d0__0[5U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[5U])))));
    __Vtemp_hf771afeb__0[6U] = (VTestHarness__ConstPool__CONST_h52851b57_0[6U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[6U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[6U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[6U] 
                                               & __Vtemp_h7b4a04a4__0[6U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[6U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[6U] 
                                                 & __Vtemp_h9cb211d0__0[6U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[6U])))));
    __Vtemp_hf771afeb__0[7U] = (VTestHarness__ConstPool__CONST_h52851b57_0[7U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[7U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[7U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[7U] 
                                               & __Vtemp_h7b4a04a4__0[7U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[7U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[7U] 
                                                 & __Vtemp_h9cb211d0__0[7U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[7U])))));
    __Vtemp_hf771afeb__0[8U] = (VTestHarness__ConstPool__CONST_h52851b57_0[8U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[8U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[8U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[8U] 
                                               & __Vtemp_h7b4a04a4__0[8U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[8U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[8U] 
                                                 & __Vtemp_h9cb211d0__0[8U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[8U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[0U] 
        = (VTestHarness__ConstPool__CONST_h52851b57_0[0U] 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
               ? VTestHarness__ConstPool__CONST_h478702bb_0[0U]
               : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[0U] 
                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                       ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[0U] 
                          & __Vtemp_h7b4a04a4__0[0U])
                       : VTestHarness__ConstPool__CONST_h478702bb_0[0U])) 
                  & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                         ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[0U] 
                            & __Vtemp_h9cb211d0__0[0U])
                         : VTestHarness__ConstPool__CONST_h478702bb_0[0U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[1U] 
        = __Vtemp_hf771afeb__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[2U] 
        = __Vtemp_hf771afeb__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[3U] 
        = __Vtemp_hf771afeb__0[3U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[4U] 
        = __Vtemp_hf771afeb__0[4U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[5U] 
        = __Vtemp_hf771afeb__0[5U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[6U] 
        = __Vtemp_hf771afeb__0[6U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[7U] 
        = __Vtemp_hf771afeb__0[7U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[8U] 
        = __Vtemp_hf771afeb__0[8U];
    VL_EXTEND_WI(1027,4, __Vtemp_heec21cf4__0, ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                                 ? 
                                                (1U 
                                                 | (0xeU 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       << 1U)))
                                                 : 0U));
    VL_EXTEND_WI(1025,7, __Vtemp_h2140e76b__1, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 9U)));
    __Vtemp_hbd131450__0[0U] = (__Vtemp_h2140e76b__1[0U] 
                                << 2U);
    __Vtemp_hbd131450__0[1U] = ((__Vtemp_h2140e76b__1[0U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__1[1U] 
                                              << 2U));
    __Vtemp_hbd131450__0[2U] = ((__Vtemp_h2140e76b__1[1U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__1[2U] 
                                              << 2U));
    __Vtemp_hbd131450__0[3U] = ((__Vtemp_h2140e76b__1[2U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__1[3U] 
                                              << 2U));
    __Vtemp_hbd131450__0[4U] = ((__Vtemp_h2140e76b__1[3U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__1[4U] 
                                              << 2U));
    __Vtemp_hbd131450__0[5U] = ((__Vtemp_h2140e76b__1[4U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__1[5U] 
                                              << 2U));
    __Vtemp_hbd131450__0[6U] = ((__Vtemp_h2140e76b__1[5U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__1[6U] 
                                              << 2U));
    __Vtemp_hbd131450__0[7U] = ((__Vtemp_h2140e76b__1[6U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__1[7U] 
                                              << 2U));
    __Vtemp_hbd131450__0[8U] = ((__Vtemp_h2140e76b__1[7U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__1[8U] 
                                              << 2U));
    __Vtemp_hbd131450__0[9U] = ((__Vtemp_h2140e76b__1[8U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__1[9U] 
                                              << 2U));
    __Vtemp_hbd131450__0[0xaU] = ((__Vtemp_h2140e76b__1[9U] 
                                   >> 0x1eU) | (__Vtemp_h2140e76b__1[0xaU] 
                                                << 2U));
    __Vtemp_hbd131450__0[0xbU] = ((__Vtemp_h2140e76b__1[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h2140e76b__1[0xbU] 
                                                << 2U));
    __Vtemp_hbd131450__0[0xcU] = ((__Vtemp_h2140e76b__1[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h2140e76b__1[0xcU] 
                                                << 2U));
    __Vtemp_hbd131450__0[0xdU] = ((__Vtemp_h2140e76b__1[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h2140e76b__1[0xdU] 
                                                << 2U));
    __Vtemp_hbd131450__0[0xeU] = ((__Vtemp_h2140e76b__1[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h2140e76b__1[0xeU] 
                                                << 2U));
    __Vtemp_hbd131450__0[0xfU] = ((__Vtemp_h2140e76b__1[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h2140e76b__1[0xfU] 
                                                << 2U));
    __Vtemp_hbd131450__0[0x10U] = ((__Vtemp_h2140e76b__1[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__1[0x10U] 
                                                 << 2U));
    __Vtemp_hbd131450__0[0x11U] = ((__Vtemp_h2140e76b__1[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__1[0x11U] 
                                                 << 2U));
    __Vtemp_hbd131450__0[0x12U] = ((__Vtemp_h2140e76b__1[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__1[0x12U] 
                                                 << 2U));
    __Vtemp_hbd131450__0[0x13U] = ((__Vtemp_h2140e76b__1[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__1[0x13U] 
                                                 << 2U));
    __Vtemp_hbd131450__0[0x14U] = ((__Vtemp_h2140e76b__1[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__1[0x14U] 
                                                 << 2U));
    __Vtemp_hbd131450__0[0x15U] = ((__Vtemp_h2140e76b__1[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__1[0x15U] 
                                                 << 2U));
    __Vtemp_hbd131450__0[0x16U] = ((__Vtemp_h2140e76b__1[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__1[0x16U] 
                                                 << 2U));
    __Vtemp_hbd131450__0[0x17U] = ((__Vtemp_h2140e76b__1[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__1[0x17U] 
                                                 << 2U));
    __Vtemp_hbd131450__0[0x18U] = ((__Vtemp_h2140e76b__1[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__1[0x18U] 
                                                 << 2U));
    __Vtemp_hbd131450__0[0x19U] = ((__Vtemp_h2140e76b__1[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__1[0x19U] 
                                                 << 2U));
    __Vtemp_hbd131450__0[0x1aU] = ((__Vtemp_h2140e76b__1[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__1[0x1aU] 
                                                 << 2U));
    __Vtemp_hbd131450__0[0x1bU] = ((__Vtemp_h2140e76b__1[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__1[0x1bU] 
                                                 << 2U));
    __Vtemp_hbd131450__0[0x1cU] = ((__Vtemp_h2140e76b__1[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__1[0x1cU] 
                                                 << 2U));
    __Vtemp_hbd131450__0[0x1dU] = ((__Vtemp_h2140e76b__1[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__1[0x1dU] 
                                                 << 2U));
    __Vtemp_hbd131450__0[0x1eU] = ((__Vtemp_h2140e76b__1[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__1[0x1eU] 
                                                 << 2U));
    __Vtemp_hbd131450__0[0x1fU] = ((__Vtemp_h2140e76b__1[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__1[0x1fU] 
                                                 << 2U));
    __Vtemp_hbd131450__0[0x20U] = ((__Vtemp_h2140e76b__1[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__1[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1027,1027,1027, __Vtemp_h0ff86d47__0, __Vtemp_heec21cf4__0, __Vtemp_hbd131450__0);
    VL_EXTEND_WI(1037,7, __Vtemp_h0f47d476__0, (0x7fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_pbus_auto_coupler_to_device_named_uart_0_control_xing_out_a_bits_source) 
                                                   >> 4U)));
    __Vtemp_hb5c5ee55__0[0U] = (__Vtemp_h0f47d476__0[0U] 
                                << 2U);
    __Vtemp_hb5c5ee55__0[1U] = ((__Vtemp_h0f47d476__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h0f47d476__0[1U] 
                                              << 2U));
    __Vtemp_hb5c5ee55__0[2U] = ((__Vtemp_h0f47d476__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h0f47d476__0[2U] 
                                              << 2U));
    __Vtemp_hb5c5ee55__0[3U] = ((__Vtemp_h0f47d476__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h0f47d476__0[3U] 
                                              << 2U));
    __Vtemp_hb5c5ee55__0[4U] = ((__Vtemp_h0f47d476__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h0f47d476__0[4U] 
                                              << 2U));
    __Vtemp_hb5c5ee55__0[5U] = ((__Vtemp_h0f47d476__0[4U] 
                                 >> 0x1eU) | (__Vtemp_h0f47d476__0[5U] 
                                              << 2U));
    __Vtemp_hb5c5ee55__0[6U] = ((__Vtemp_h0f47d476__0[5U] 
                                 >> 0x1eU) | (__Vtemp_h0f47d476__0[6U] 
                                              << 2U));
    __Vtemp_hb5c5ee55__0[7U] = ((__Vtemp_h0f47d476__0[6U] 
                                 >> 0x1eU) | (__Vtemp_h0f47d476__0[7U] 
                                              << 2U));
    __Vtemp_hb5c5ee55__0[8U] = ((__Vtemp_h0f47d476__0[7U] 
                                 >> 0x1eU) | (__Vtemp_h0f47d476__0[8U] 
                                              << 2U));
    __Vtemp_hb5c5ee55__0[9U] = ((__Vtemp_h0f47d476__0[8U] 
                                 >> 0x1eU) | (__Vtemp_h0f47d476__0[9U] 
                                              << 2U));
    __Vtemp_hb5c5ee55__0[0xaU] = ((__Vtemp_h0f47d476__0[9U] 
                                   >> 0x1eU) | (__Vtemp_h0f47d476__0[0xaU] 
                                                << 2U));
    __Vtemp_hb5c5ee55__0[0xbU] = ((__Vtemp_h0f47d476__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h0f47d476__0[0xbU] 
                                                << 2U));
    __Vtemp_hb5c5ee55__0[0xcU] = ((__Vtemp_h0f47d476__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h0f47d476__0[0xcU] 
                                                << 2U));
    __Vtemp_hb5c5ee55__0[0xdU] = ((__Vtemp_h0f47d476__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h0f47d476__0[0xdU] 
                                                << 2U));
    __Vtemp_hb5c5ee55__0[0xeU] = ((__Vtemp_h0f47d476__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h0f47d476__0[0xeU] 
                                                << 2U));
    __Vtemp_hb5c5ee55__0[0xfU] = ((__Vtemp_h0f47d476__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h0f47d476__0[0xfU] 
                                                << 2U));
    __Vtemp_hb5c5ee55__0[0x10U] = ((__Vtemp_h0f47d476__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x10U] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x11U] = ((__Vtemp_h0f47d476__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x11U] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x12U] = ((__Vtemp_h0f47d476__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x12U] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x13U] = ((__Vtemp_h0f47d476__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x13U] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x14U] = ((__Vtemp_h0f47d476__0[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x14U] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x15U] = ((__Vtemp_h0f47d476__0[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x15U] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x16U] = ((__Vtemp_h0f47d476__0[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x16U] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x17U] = ((__Vtemp_h0f47d476__0[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x17U] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x18U] = ((__Vtemp_h0f47d476__0[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x18U] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x19U] = ((__Vtemp_h0f47d476__0[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x19U] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x1aU] = ((__Vtemp_h0f47d476__0[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x1aU] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x1bU] = ((__Vtemp_h0f47d476__0[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x1bU] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x1cU] = ((__Vtemp_h0f47d476__0[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x1cU] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x1dU] = ((__Vtemp_h0f47d476__0[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x1dU] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x1eU] = ((__Vtemp_h0f47d476__0[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x1eU] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x1fU] = ((__Vtemp_h0f47d476__0[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x1fU] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x20U] = ((__Vtemp_h0f47d476__0[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1039,1039,1039, __Vtemp_h623ba2b7__0, VTestHarness__ConstPool__CONST_h3892cc72_0, __Vtemp_hb5c5ee55__0);
    __Vtemp_h6cea73da__0[1U] = (VTestHarness__ConstPool__CONST_h52851b57_0[1U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[1U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[1U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[1U] 
                                               & __Vtemp_h0ff86d47__0[1U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[1U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[1U] 
                                                 & __Vtemp_h623ba2b7__0[1U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[1U])))));
    __Vtemp_h6cea73da__0[2U] = (VTestHarness__ConstPool__CONST_h52851b57_0[2U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[2U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[2U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[2U] 
                                               & __Vtemp_h0ff86d47__0[2U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[2U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[2U] 
                                                 & __Vtemp_h623ba2b7__0[2U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[2U])))));
    __Vtemp_h6cea73da__0[3U] = (VTestHarness__ConstPool__CONST_h52851b57_0[3U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[3U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[3U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[3U] 
                                               & __Vtemp_h0ff86d47__0[3U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[3U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[3U] 
                                                 & __Vtemp_h623ba2b7__0[3U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[3U])))));
    __Vtemp_h6cea73da__0[4U] = (VTestHarness__ConstPool__CONST_h52851b57_0[4U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[4U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[4U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[4U] 
                                               & __Vtemp_h0ff86d47__0[4U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[4U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[4U] 
                                                 & __Vtemp_h623ba2b7__0[4U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[4U])))));
    __Vtemp_h6cea73da__0[5U] = (VTestHarness__ConstPool__CONST_h52851b57_0[5U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[5U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[5U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[5U] 
                                               & __Vtemp_h0ff86d47__0[5U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[5U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[5U] 
                                                 & __Vtemp_h623ba2b7__0[5U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[5U])))));
    __Vtemp_h6cea73da__0[6U] = (VTestHarness__ConstPool__CONST_h52851b57_0[6U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[6U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[6U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[6U] 
                                               & __Vtemp_h0ff86d47__0[6U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[6U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[6U] 
                                                 & __Vtemp_h623ba2b7__0[6U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[6U])))));
    __Vtemp_h6cea73da__0[7U] = (VTestHarness__ConstPool__CONST_h52851b57_0[7U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[7U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[7U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[7U] 
                                               & __Vtemp_h0ff86d47__0[7U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[7U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[7U] 
                                                 & __Vtemp_h623ba2b7__0[7U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[7U])))));
    __Vtemp_h6cea73da__0[8U] = (VTestHarness__ConstPool__CONST_h52851b57_0[8U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[8U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[8U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[8U] 
                                               & __Vtemp_h0ff86d47__0[8U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[8U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[8U] 
                                                 & __Vtemp_h623ba2b7__0[8U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[8U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[0U] 
        = (VTestHarness__ConstPool__CONST_h52851b57_0[0U] 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
               ? VTestHarness__ConstPool__CONST_h478702bb_0[0U]
               : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[0U] 
                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                       ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[0U] 
                          & __Vtemp_h0ff86d47__0[0U])
                       : VTestHarness__ConstPool__CONST_h478702bb_0[0U])) 
                  & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                         ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[0U] 
                            & __Vtemp_h623ba2b7__0[0U])
                         : VTestHarness__ConstPool__CONST_h478702bb_0[0U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[1U] 
        = __Vtemp_h6cea73da__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[2U] 
        = __Vtemp_h6cea73da__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[3U] 
        = __Vtemp_h6cea73da__0[3U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[4U] 
        = __Vtemp_h6cea73da__0[4U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[5U] 
        = __Vtemp_h6cea73da__0[5U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[6U] 
        = __Vtemp_h6cea73da__0[6U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[7U] 
        = __Vtemp_h6cea73da__0[7U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[8U] 
        = __Vtemp_h6cea73da__0[8U];
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__14599(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__14599\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_h54b7b713__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__0;
    VlWide<4>/*127:0*/ __Vtemp_h4c070d9e__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__1;
    VlWide<4>/*127:0*/ __Vtemp_h8e795365__0;
    VlWide<9>/*287:0*/ __Vtemp_hc4e28e81__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9d57c221__0;
    VlWide<33>/*1055:0*/ __Vtemp_h2140e76b__0;
    VlWide<33>/*1055:0*/ __Vtemp_h6a657119__0;
    VlWide<33>/*1055:0*/ __Vtemp_hfdd19122__0;
    VlWide<33>/*1055:0*/ __Vtemp_h0f47d476__0;
    VlWide<33>/*1055:0*/ __Vtemp_hb5c5ee55__0;
    VlWide<33>/*1055:0*/ __Vtemp_h623ba2b7__0;
    // Body
    __Vtemp_hc961d23f__0[0U] = 1U;
    __Vtemp_hc961d23f__0[1U] = 0U;
    __Vtemp_hc961d23f__0[2U] = 0U;
    __Vtemp_hc961d23f__0[3U] = 0U;
    VL_SHIFTL_WWI(128,128,7, __Vtemp_h4c070d9e__0, __Vtemp_hc961d23f__0, 
                  (0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                            >> 9U)));
    __Vtemp_hc961d23f__1[0U] = 1U;
    __Vtemp_hc961d23f__1[1U] = 0U;
    __Vtemp_hc961d23f__1[2U] = 0U;
    __Vtemp_hc961d23f__1[3U] = 0U;
    VL_SHIFTL_WWI(128,128,7, __Vtemp_h8e795365__0, __Vtemp_hc961d23f__1, 
                  (0x7fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_pbus_auto_coupler_to_device_named_uart_0_control_xing_out_a_bits_source) 
                            >> 4U)));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset) {
        __Vtemp_h54b7b713__0[1U] = 0U;
        __Vtemp_h54b7b713__0[2U] = 0U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight[0U] = 0U;
    } else {
        __Vtemp_h54b7b713__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight[1U] 
                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                         ? __Vtemp_h4c070d9e__0[1U]
                                         : 0U)) & (~ 
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                                     ? 
                                                    __Vtemp_h8e795365__0[1U]
                                                     : 0U)));
        __Vtemp_h54b7b713__0[2U] = (1U & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight[2U] 
                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                               ? __Vtemp_h4c070d9e__0[2U]
                                               : 0U)) 
                                          & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                                 ? 
                                                __Vtemp_h8e795365__0[2U]
                                                 : 0U))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight[0U] 
            = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight[0U] 
                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                    ? __Vtemp_h4c070d9e__0[0U] : 0U)) 
               & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                      ? __Vtemp_h8e795365__0[0U] : 0U)));
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight[1U] 
        = __Vtemp_h54b7b713__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight[2U] 
        = __Vtemp_h54b7b713__0[2U];
    VL_EXTEND_WI(1027,4, __Vtemp_h9d57c221__0, ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                                 ? 
                                                (1U 
                                                 | (0xeU 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       >> 5U)))
                                                 : 0U));
    VL_EXTEND_WI(1025,7, __Vtemp_h2140e76b__0, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 9U)));
    __Vtemp_h6a657119__0[0U] = (__Vtemp_h2140e76b__0[0U] 
                                << 2U);
    __Vtemp_h6a657119__0[1U] = ((__Vtemp_h2140e76b__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[1U] 
                                              << 2U));
    __Vtemp_h6a657119__0[2U] = ((__Vtemp_h2140e76b__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[2U] 
                                              << 2U));
    __Vtemp_h6a657119__0[3U] = ((__Vtemp_h2140e76b__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[3U] 
                                              << 2U));
    __Vtemp_h6a657119__0[4U] = ((__Vtemp_h2140e76b__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[4U] 
                                              << 2U));
    __Vtemp_h6a657119__0[5U] = ((__Vtemp_h2140e76b__0[4U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[5U] 
                                              << 2U));
    __Vtemp_h6a657119__0[6U] = ((__Vtemp_h2140e76b__0[5U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[6U] 
                                              << 2U));
    __Vtemp_h6a657119__0[7U] = ((__Vtemp_h2140e76b__0[6U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[7U] 
                                              << 2U));
    __Vtemp_h6a657119__0[8U] = ((__Vtemp_h2140e76b__0[7U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[8U] 
                                              << 2U));
    __Vtemp_h6a657119__0[9U] = ((__Vtemp_h2140e76b__0[8U] 
                                 >> 0x1eU) | (__Vtemp_h2140e76b__0[9U] 
                                              << 2U));
    __Vtemp_h6a657119__0[0xaU] = ((__Vtemp_h2140e76b__0[9U] 
                                   >> 0x1eU) | (__Vtemp_h2140e76b__0[0xaU] 
                                                << 2U));
    __Vtemp_h6a657119__0[0xbU] = ((__Vtemp_h2140e76b__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h2140e76b__0[0xbU] 
                                                << 2U));
    __Vtemp_h6a657119__0[0xcU] = ((__Vtemp_h2140e76b__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h2140e76b__0[0xcU] 
                                                << 2U));
    __Vtemp_h6a657119__0[0xdU] = ((__Vtemp_h2140e76b__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h2140e76b__0[0xdU] 
                                                << 2U));
    __Vtemp_h6a657119__0[0xeU] = ((__Vtemp_h2140e76b__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h2140e76b__0[0xeU] 
                                                << 2U));
    __Vtemp_h6a657119__0[0xfU] = ((__Vtemp_h2140e76b__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h2140e76b__0[0xfU] 
                                                << 2U));
    __Vtemp_h6a657119__0[0x10U] = ((__Vtemp_h2140e76b__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x10U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x11U] = ((__Vtemp_h2140e76b__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x11U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x12U] = ((__Vtemp_h2140e76b__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x12U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x13U] = ((__Vtemp_h2140e76b__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x13U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x14U] = ((__Vtemp_h2140e76b__0[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x14U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x15U] = ((__Vtemp_h2140e76b__0[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x15U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x16U] = ((__Vtemp_h2140e76b__0[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x16U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x17U] = ((__Vtemp_h2140e76b__0[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x17U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x18U] = ((__Vtemp_h2140e76b__0[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x18U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x19U] = ((__Vtemp_h2140e76b__0[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x19U] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x1aU] = ((__Vtemp_h2140e76b__0[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x1aU] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x1bU] = ((__Vtemp_h2140e76b__0[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x1bU] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x1cU] = ((__Vtemp_h2140e76b__0[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x1cU] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x1dU] = ((__Vtemp_h2140e76b__0[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x1dU] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x1eU] = ((__Vtemp_h2140e76b__0[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x1eU] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x1fU] = ((__Vtemp_h2140e76b__0[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x1fU] 
                                                 << 2U));
    __Vtemp_h6a657119__0[0x20U] = ((__Vtemp_h2140e76b__0[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h2140e76b__0[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1027,1027,1027, __Vtemp_hfdd19122__0, __Vtemp_h9d57c221__0, __Vtemp_h6a657119__0);
    VL_EXTEND_WI(1037,7, __Vtemp_h0f47d476__0, (0x7fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_pbus_auto_coupler_to_device_named_uart_0_control_xing_out_a_bits_source) 
                                                   >> 4U)));
    __Vtemp_hb5c5ee55__0[0U] = (__Vtemp_h0f47d476__0[0U] 
                                << 2U);
    __Vtemp_hb5c5ee55__0[1U] = ((__Vtemp_h0f47d476__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h0f47d476__0[1U] 
                                              << 2U));
    __Vtemp_hb5c5ee55__0[2U] = ((__Vtemp_h0f47d476__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h0f47d476__0[2U] 
                                              << 2U));
    __Vtemp_hb5c5ee55__0[3U] = ((__Vtemp_h0f47d476__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h0f47d476__0[3U] 
                                              << 2U));
    __Vtemp_hb5c5ee55__0[4U] = ((__Vtemp_h0f47d476__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h0f47d476__0[4U] 
                                              << 2U));
    __Vtemp_hb5c5ee55__0[5U] = ((__Vtemp_h0f47d476__0[4U] 
                                 >> 0x1eU) | (__Vtemp_h0f47d476__0[5U] 
                                              << 2U));
    __Vtemp_hb5c5ee55__0[6U] = ((__Vtemp_h0f47d476__0[5U] 
                                 >> 0x1eU) | (__Vtemp_h0f47d476__0[6U] 
                                              << 2U));
    __Vtemp_hb5c5ee55__0[7U] = ((__Vtemp_h0f47d476__0[6U] 
                                 >> 0x1eU) | (__Vtemp_h0f47d476__0[7U] 
                                              << 2U));
    __Vtemp_hb5c5ee55__0[8U] = ((__Vtemp_h0f47d476__0[7U] 
                                 >> 0x1eU) | (__Vtemp_h0f47d476__0[8U] 
                                              << 2U));
    __Vtemp_hb5c5ee55__0[9U] = ((__Vtemp_h0f47d476__0[8U] 
                                 >> 0x1eU) | (__Vtemp_h0f47d476__0[9U] 
                                              << 2U));
    __Vtemp_hb5c5ee55__0[0xaU] = ((__Vtemp_h0f47d476__0[9U] 
                                   >> 0x1eU) | (__Vtemp_h0f47d476__0[0xaU] 
                                                << 2U));
    __Vtemp_hb5c5ee55__0[0xbU] = ((__Vtemp_h0f47d476__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h0f47d476__0[0xbU] 
                                                << 2U));
    __Vtemp_hb5c5ee55__0[0xcU] = ((__Vtemp_h0f47d476__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h0f47d476__0[0xcU] 
                                                << 2U));
    __Vtemp_hb5c5ee55__0[0xdU] = ((__Vtemp_h0f47d476__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h0f47d476__0[0xdU] 
                                                << 2U));
    __Vtemp_hb5c5ee55__0[0xeU] = ((__Vtemp_h0f47d476__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h0f47d476__0[0xeU] 
                                                << 2U));
    __Vtemp_hb5c5ee55__0[0xfU] = ((__Vtemp_h0f47d476__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h0f47d476__0[0xfU] 
                                                << 2U));
    __Vtemp_hb5c5ee55__0[0x10U] = ((__Vtemp_h0f47d476__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x10U] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x11U] = ((__Vtemp_h0f47d476__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x11U] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x12U] = ((__Vtemp_h0f47d476__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x12U] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x13U] = ((__Vtemp_h0f47d476__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x13U] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x14U] = ((__Vtemp_h0f47d476__0[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x14U] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x15U] = ((__Vtemp_h0f47d476__0[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x15U] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x16U] = ((__Vtemp_h0f47d476__0[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x16U] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x17U] = ((__Vtemp_h0f47d476__0[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x17U] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x18U] = ((__Vtemp_h0f47d476__0[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x18U] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x19U] = ((__Vtemp_h0f47d476__0[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x19U] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x1aU] = ((__Vtemp_h0f47d476__0[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x1aU] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x1bU] = ((__Vtemp_h0f47d476__0[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x1bU] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x1cU] = ((__Vtemp_h0f47d476__0[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x1cU] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x1dU] = ((__Vtemp_h0f47d476__0[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x1dU] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x1eU] = ((__Vtemp_h0f47d476__0[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x1eU] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x1fU] = ((__Vtemp_h0f47d476__0[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x1fU] 
                                                 << 2U));
    __Vtemp_hb5c5ee55__0[0x20U] = ((__Vtemp_h0f47d476__0[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h0f47d476__0[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1039,1039,1039, __Vtemp_h623ba2b7__0, VTestHarness__ConstPool__CONST_h3892cc72_0, __Vtemp_hb5c5ee55__0);
    __Vtemp_hc4e28e81__0[1U] = (VTestHarness__ConstPool__CONST_h52851b57_0[1U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[1U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[1U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[1U] 
                                               & __Vtemp_hfdd19122__0[1U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[1U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[1U] 
                                                 & __Vtemp_h623ba2b7__0[1U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[1U])))));
    __Vtemp_hc4e28e81__0[2U] = (VTestHarness__ConstPool__CONST_h52851b57_0[2U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[2U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[2U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[2U] 
                                               & __Vtemp_hfdd19122__0[2U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[2U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[2U] 
                                                 & __Vtemp_h623ba2b7__0[2U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[2U])))));
    __Vtemp_hc4e28e81__0[3U] = (VTestHarness__ConstPool__CONST_h52851b57_0[3U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[3U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[3U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[3U] 
                                               & __Vtemp_hfdd19122__0[3U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[3U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[3U] 
                                                 & __Vtemp_h623ba2b7__0[3U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[3U])))));
    __Vtemp_hc4e28e81__0[4U] = (VTestHarness__ConstPool__CONST_h52851b57_0[4U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[4U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[4U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[4U] 
                                               & __Vtemp_hfdd19122__0[4U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[4U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[4U] 
                                                 & __Vtemp_h623ba2b7__0[4U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[4U])))));
    __Vtemp_hc4e28e81__0[5U] = (VTestHarness__ConstPool__CONST_h52851b57_0[5U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[5U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[5U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[5U] 
                                               & __Vtemp_hfdd19122__0[5U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[5U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[5U] 
                                                 & __Vtemp_h623ba2b7__0[5U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[5U])))));
    __Vtemp_hc4e28e81__0[6U] = (VTestHarness__ConstPool__CONST_h52851b57_0[6U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[6U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[6U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[6U] 
                                               & __Vtemp_hfdd19122__0[6U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[6U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[6U] 
                                                 & __Vtemp_h623ba2b7__0[6U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[6U])))));
    __Vtemp_hc4e28e81__0[7U] = (VTestHarness__ConstPool__CONST_h52851b57_0[7U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[7U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[7U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[7U] 
                                               & __Vtemp_hfdd19122__0[7U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[7U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[7U] 
                                                 & __Vtemp_h623ba2b7__0[7U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[7U])))));
    __Vtemp_hc4e28e81__0[8U] = (VTestHarness__ConstPool__CONST_h52851b57_0[8U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[8U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[8U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[8U] 
                                               & __Vtemp_hfdd19122__0[8U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[8U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[8U] 
                                                 & __Vtemp_h623ba2b7__0[8U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[8U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[0U] 
        = (VTestHarness__ConstPool__CONST_h52851b57_0[0U] 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)
               ? VTestHarness__ConstPool__CONST_h478702bb_0[0U]
               : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[0U] 
                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                       ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[0U] 
                          & __Vtemp_hfdd19122__0[0U])
                       : VTestHarness__ConstPool__CONST_h478702bb_0[0U])) 
                  & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                         ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[0U] 
                            & __Vtemp_h623ba2b7__0[0U])
                         : VTestHarness__ConstPool__CONST_h478702bb_0[0U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[1U] 
        = __Vtemp_hc4e28e81__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[2U] 
        = __Vtemp_hc4e28e81__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[3U] 
        = __Vtemp_hc4e28e81__0[3U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[4U] 
        = __Vtemp_hc4e28e81__0[4U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[5U] 
        = __Vtemp_hc4e28e81__0[5U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[6U] 
        = __Vtemp_hc4e28e81__0[6U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[7U] 
        = __Vtemp_hc4e28e81__0[7U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[8U] 
        = __Vtemp_hc4e28e81__0[8U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__repeater__DOT__full 
        = ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_pbus_0_reset)) 
           & ((~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__x1_d_ready) 
                   & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__repeater__DOT___io_deq_valid_output)) 
                  & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT____Vcellinp__repeater__io_repeat)))) 
              & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__repeater__DOT___T_1) 
                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_device_named_uart_0__DOT__fragmenter__DOT__repeater__DOT__full))));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0) {
        if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__directory__io_read_valid) {
            vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__victimLFSR_prng__DOT__state_0 
                = ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__victimLFSR_prng__DOT__state_15) 
                     ^ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__victimLFSR_prng__DOT__state_13)) 
                    ^ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__victimLFSR_prng__DOT__state_12)) 
                   ^ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__victimLFSR_prng__DOT__state_10));
            vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__victimLFSR_prng__DOT__state_11 
                = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__victimLFSR_prng__DOT__state_10;
            vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__victimLFSR_prng__DOT__state_14 
                = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__victimLFSR_prng__DOT__state_13;
            vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__victimLFSR_prng__DOT__state_13 
                = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__victimLFSR_prng__DOT__state_12;
        }
    } else {
        vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__victimLFSR_prng__DOT__state_0 = 0U;
        vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__victimLFSR_prng__DOT__state_11 = 0U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__victimLFSR_prng__DOT__state_13 = 0U;
        vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__directory__DOT__victimLFSR_prng__DOT__state_14 = 0U;
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__14600(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__14600\n"); );
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__gh_buf_io_commit_uops_0_REG_is_amo 
        = (1U & ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_31_is_amo) 
                   << 0x1fU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_30_is_amo) 
                                 << 0x1eU) | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_29_is_amo) 
                                               << 0x1dU) 
                                              | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_28_is_amo) 
                                                  << 0x1cU) 
                                                 | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_27_is_amo) 
                                                     << 0x1bU) 
                                                    | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_26_is_amo) 
                                                        << 0x1aU) 
                                                       | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_25_is_amo) 
                                                           << 0x19U) 
                                                          | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_24_is_amo) 
                                                              << 0x18U) 
                                                             | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_23_is_amo) 
                                                                 << 0x17U) 
                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_22_is_amo) 
                                                                    << 0x16U) 
                                                                   | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_21_is_amo) 
                                                                       << 0x15U) 
                                                                      | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_20_is_amo) 
                                                                          << 0x14U) 
                                                                         | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_19_is_amo) 
                                                                             << 0x13U) 
                                                                            | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_18_is_amo) 
                                                                                << 0x12U) 
                                                                               | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_17_is_amo) 
                                                                                << 0x11U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_16_is_amo) 
                                                                                << 0x10U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_15_is_amo) 
                                                                                << 0xfU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_14_is_amo) 
                                                                                << 0xeU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_13_is_amo) 
                                                                                << 0xdU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_12_is_amo) 
                                                                                << 0xcU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_11_is_amo) 
                                                                                << 0xbU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_10_is_amo) 
                                                                                << 0xaU) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_9_is_amo) 
                                                                                << 9U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_8_is_amo) 
                                                                                << 8U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_7_is_amo) 
                                                                                << 7U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_6_is_amo) 
                                                                                << 6U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_5_is_amo) 
                                                                                << 5U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_4_is_amo) 
                                                                                << 4U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_3_is_amo) 
                                                                                << 3U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_2_is_amo) 
                                                                                << 2U) 
                                                                                | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_1_is_amo) 
                                                                                << 1U) 
                                                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__rob_uop_0_is_amo)))))))))))))))))))))))))))))))) 
                 >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__rob__DOT__com_idx)));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_16__DOT__ppred = 0U;
    } else if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__issue_slots_16_in_uop_valid) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_16__DOT__ppred 
            = (1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT____Vcellinp__slots_16__io_in_uop_bits_ppred_busy)));
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__repeater__DOT___T_1) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__repeater__DOT__saved_opcode 
            = (7U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U]);
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__coupler_to_slave_named_bootaddressreg__DOT__fragmenter__DOT__repeater__DOT__saved_source 
            = (0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_pbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                        >> 9U));
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset) {
        vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__d_first_counter_2 = 0U;
    } else if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1733) {
        vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__d_first_counter_2 
            = (0x1ffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__d_first_2)
                          ? ((1U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])
                              ? (~ (((0x1aU >= (0xfU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 5U)))
                                      ? (0x7ffffffU 
                                         & ((IData)(0xfffU) 
                                            << (0xfU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 5U))))
                                      : 0U) >> 3U))
                              : 0U) : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__d_first_counter_2) 
                                       - (IData)(1U))));
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__14601(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__14601\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_h1cc28e5b__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__0;
    VlWide<4>/*127:0*/ __Vtemp_h8c58709f__0;
    VlWide<4>/*127:0*/ __Vtemp_ha1f99dfd__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__1;
    VlWide<4>/*127:0*/ __Vtemp_h4a2dd5e2__0;
    VlWide<4>/*127:0*/ __Vtemp_h1abc586c__0;
    VlWide<9>/*287:0*/ __Vtemp_hf2079383__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9416ec59__0;
    VlWide<33>/*1055:0*/ __Vtemp_h7f9506cd__0;
    VlWide<33>/*1055:0*/ __Vtemp_hc5d3311f__0;
    VlWide<33>/*1055:0*/ __Vtemp_h76f0401f__0;
    VlWide<33>/*1055:0*/ __Vtemp_h49659e28__0;
    VlWide<33>/*1055:0*/ __Vtemp_h6c5e52f6__0;
    VlWide<33>/*1055:0*/ __Vtemp_h4837c245__0;
    VlWide<3>/*95:0*/ __Vtemp_hc86c2840__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__2;
    VlWide<4>/*127:0*/ __Vtemp_h557ea57f__0;
    VlWide<4>/*127:0*/ __Vtemp_hea2c6c8e__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__3;
    VlWide<4>/*127:0*/ __Vtemp_h4a2dd5e2__1;
    VlWide<4>/*127:0*/ __Vtemp_h3b0efedd__0;
    // Body
    __Vtemp_hc961d23f__0[0U] = 1U;
    __Vtemp_hc961d23f__0[1U] = 0U;
    __Vtemp_hc961d23f__0[2U] = 0U;
    __Vtemp_hc961d23f__0[3U] = 0U;
    VL_EXTEND_WI(128,7, __Vtemp_h8c58709f__0, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_out_a_bits_source));
    VL_SHIFTL_WWW(128,128,128, __Vtemp_ha1f99dfd__0, __Vtemp_hc961d23f__0, __Vtemp_h8c58709f__0);
    __Vtemp_hc961d23f__1[0U] = 1U;
    __Vtemp_hc961d23f__1[1U] = 0U;
    __Vtemp_hc961d23f__1[2U] = 0U;
    __Vtemp_hc961d23f__1[3U] = 0U;
    VL_EXTEND_WI(128,7, __Vtemp_h4a2dd5e2__0, (0x7fU 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 9U)));
    VL_SHIFTL_WWW(128,128,128, __Vtemp_h1abc586c__0, __Vtemp_hc961d23f__1, __Vtemp_h4a2dd5e2__0);
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset) {
        __Vtemp_h1cc28e5b__0[1U] = 0U;
        __Vtemp_h1cc28e5b__0[2U] = 0U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight[0U] = 0U;
    } else {
        __Vtemp_h1cc28e5b__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight[1U] 
                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                         ? __Vtemp_ha1f99dfd__0[1U]
                                         : 0U)) & (~ 
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                                                     ? 
                                                    __Vtemp_h1abc586c__0[1U]
                                                     : 0U)));
        __Vtemp_h1cc28e5b__0[2U] = (1U & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight[2U] 
                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                               ? __Vtemp_ha1f99dfd__0[2U]
                                               : 0U)) 
                                          & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                                                 ? 
                                                __Vtemp_h1abc586c__0[2U]
                                                 : 0U))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight[0U] 
            = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight[0U] 
                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                    ? __Vtemp_ha1f99dfd__0[0U] : 0U)) 
               & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                      ? __Vtemp_h1abc586c__0[0U] : 0U)));
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight[1U] 
        = __Vtemp_h1cc28e5b__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight[2U] 
        = __Vtemp_h1cc28e5b__0[2U];
    VL_EXTEND_WI(1027,4, __Vtemp_h9416ec59__0, ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                                 ? 
                                                (1U 
                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_out_a_bits_opcode) 
                                                    << 1U))
                                                 : 0U));
    VL_EXTEND_WI(1025,7, __Vtemp_h7f9506cd__0, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_out_a_bits_source));
    __Vtemp_hc5d3311f__0[0U] = (__Vtemp_h7f9506cd__0[0U] 
                                << 2U);
    __Vtemp_hc5d3311f__0[1U] = ((__Vtemp_h7f9506cd__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h7f9506cd__0[1U] 
                                              << 2U));
    __Vtemp_hc5d3311f__0[2U] = ((__Vtemp_h7f9506cd__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h7f9506cd__0[2U] 
                                              << 2U));
    __Vtemp_hc5d3311f__0[3U] = ((__Vtemp_h7f9506cd__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h7f9506cd__0[3U] 
                                              << 2U));
    __Vtemp_hc5d3311f__0[4U] = ((__Vtemp_h7f9506cd__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h7f9506cd__0[4U] 
                                              << 2U));
    __Vtemp_hc5d3311f__0[5U] = ((__Vtemp_h7f9506cd__0[4U] 
                                 >> 0x1eU) | (__Vtemp_h7f9506cd__0[5U] 
                                              << 2U));
    __Vtemp_hc5d3311f__0[6U] = ((__Vtemp_h7f9506cd__0[5U] 
                                 >> 0x1eU) | (__Vtemp_h7f9506cd__0[6U] 
                                              << 2U));
    __Vtemp_hc5d3311f__0[7U] = ((__Vtemp_h7f9506cd__0[6U] 
                                 >> 0x1eU) | (__Vtemp_h7f9506cd__0[7U] 
                                              << 2U));
    __Vtemp_hc5d3311f__0[8U] = ((__Vtemp_h7f9506cd__0[7U] 
                                 >> 0x1eU) | (__Vtemp_h7f9506cd__0[8U] 
                                              << 2U));
    __Vtemp_hc5d3311f__0[9U] = ((__Vtemp_h7f9506cd__0[8U] 
                                 >> 0x1eU) | (__Vtemp_h7f9506cd__0[9U] 
                                              << 2U));
    __Vtemp_hc5d3311f__0[0xaU] = ((__Vtemp_h7f9506cd__0[9U] 
                                   >> 0x1eU) | (__Vtemp_h7f9506cd__0[0xaU] 
                                                << 2U));
    __Vtemp_hc5d3311f__0[0xbU] = ((__Vtemp_h7f9506cd__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h7f9506cd__0[0xbU] 
                                                << 2U));
    __Vtemp_hc5d3311f__0[0xcU] = ((__Vtemp_h7f9506cd__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h7f9506cd__0[0xcU] 
                                                << 2U));
    __Vtemp_hc5d3311f__0[0xdU] = ((__Vtemp_h7f9506cd__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h7f9506cd__0[0xdU] 
                                                << 2U));
    __Vtemp_hc5d3311f__0[0xeU] = ((__Vtemp_h7f9506cd__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h7f9506cd__0[0xeU] 
                                                << 2U));
    __Vtemp_hc5d3311f__0[0xfU] = ((__Vtemp_h7f9506cd__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h7f9506cd__0[0xfU] 
                                                << 2U));
    __Vtemp_hc5d3311f__0[0x10U] = ((__Vtemp_h7f9506cd__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h7f9506cd__0[0x10U] 
                                                 << 2U));
    __Vtemp_hc5d3311f__0[0x11U] = ((__Vtemp_h7f9506cd__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h7f9506cd__0[0x11U] 
                                                 << 2U));
    __Vtemp_hc5d3311f__0[0x12U] = ((__Vtemp_h7f9506cd__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h7f9506cd__0[0x12U] 
                                                 << 2U));
    __Vtemp_hc5d3311f__0[0x13U] = ((__Vtemp_h7f9506cd__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h7f9506cd__0[0x13U] 
                                                 << 2U));
    __Vtemp_hc5d3311f__0[0x14U] = ((__Vtemp_h7f9506cd__0[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h7f9506cd__0[0x14U] 
                                                 << 2U));
    __Vtemp_hc5d3311f__0[0x15U] = ((__Vtemp_h7f9506cd__0[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h7f9506cd__0[0x15U] 
                                                 << 2U));
    __Vtemp_hc5d3311f__0[0x16U] = ((__Vtemp_h7f9506cd__0[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h7f9506cd__0[0x16U] 
                                                 << 2U));
    __Vtemp_hc5d3311f__0[0x17U] = ((__Vtemp_h7f9506cd__0[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h7f9506cd__0[0x17U] 
                                                 << 2U));
    __Vtemp_hc5d3311f__0[0x18U] = ((__Vtemp_h7f9506cd__0[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h7f9506cd__0[0x18U] 
                                                 << 2U));
    __Vtemp_hc5d3311f__0[0x19U] = ((__Vtemp_h7f9506cd__0[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h7f9506cd__0[0x19U] 
                                                 << 2U));
    __Vtemp_hc5d3311f__0[0x1aU] = ((__Vtemp_h7f9506cd__0[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h7f9506cd__0[0x1aU] 
                                                 << 2U));
    __Vtemp_hc5d3311f__0[0x1bU] = ((__Vtemp_h7f9506cd__0[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h7f9506cd__0[0x1bU] 
                                                 << 2U));
    __Vtemp_hc5d3311f__0[0x1cU] = ((__Vtemp_h7f9506cd__0[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h7f9506cd__0[0x1cU] 
                                                 << 2U));
    __Vtemp_hc5d3311f__0[0x1dU] = ((__Vtemp_h7f9506cd__0[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h7f9506cd__0[0x1dU] 
                                                 << 2U));
    __Vtemp_hc5d3311f__0[0x1eU] = ((__Vtemp_h7f9506cd__0[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h7f9506cd__0[0x1eU] 
                                                 << 2U));
    __Vtemp_hc5d3311f__0[0x1fU] = ((__Vtemp_h7f9506cd__0[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h7f9506cd__0[0x1fU] 
                                                 << 2U));
    __Vtemp_hc5d3311f__0[0x20U] = ((__Vtemp_h7f9506cd__0[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h7f9506cd__0[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1027,1027,1027, __Vtemp_h76f0401f__0, __Vtemp_h9416ec59__0, __Vtemp_hc5d3311f__0);
    VL_EXTEND_WI(1037,7, __Vtemp_h49659e28__0, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 9U)));
    __Vtemp_h6c5e52f6__0[0U] = (__Vtemp_h49659e28__0[0U] 
                                << 2U);
    __Vtemp_h6c5e52f6__0[1U] = ((__Vtemp_h49659e28__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h49659e28__0[1U] 
                                              << 2U));
    __Vtemp_h6c5e52f6__0[2U] = ((__Vtemp_h49659e28__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h49659e28__0[2U] 
                                              << 2U));
    __Vtemp_h6c5e52f6__0[3U] = ((__Vtemp_h49659e28__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h49659e28__0[3U] 
                                              << 2U));
    __Vtemp_h6c5e52f6__0[4U] = ((__Vtemp_h49659e28__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h49659e28__0[4U] 
                                              << 2U));
    __Vtemp_h6c5e52f6__0[5U] = ((__Vtemp_h49659e28__0[4U] 
                                 >> 0x1eU) | (__Vtemp_h49659e28__0[5U] 
                                              << 2U));
    __Vtemp_h6c5e52f6__0[6U] = ((__Vtemp_h49659e28__0[5U] 
                                 >> 0x1eU) | (__Vtemp_h49659e28__0[6U] 
                                              << 2U));
    __Vtemp_h6c5e52f6__0[7U] = ((__Vtemp_h49659e28__0[6U] 
                                 >> 0x1eU) | (__Vtemp_h49659e28__0[7U] 
                                              << 2U));
    __Vtemp_h6c5e52f6__0[8U] = ((__Vtemp_h49659e28__0[7U] 
                                 >> 0x1eU) | (__Vtemp_h49659e28__0[8U] 
                                              << 2U));
    __Vtemp_h6c5e52f6__0[9U] = ((__Vtemp_h49659e28__0[8U] 
                                 >> 0x1eU) | (__Vtemp_h49659e28__0[9U] 
                                              << 2U));
    __Vtemp_h6c5e52f6__0[0xaU] = ((__Vtemp_h49659e28__0[9U] 
                                   >> 0x1eU) | (__Vtemp_h49659e28__0[0xaU] 
                                                << 2U));
    __Vtemp_h6c5e52f6__0[0xbU] = ((__Vtemp_h49659e28__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h49659e28__0[0xbU] 
                                                << 2U));
    __Vtemp_h6c5e52f6__0[0xcU] = ((__Vtemp_h49659e28__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h49659e28__0[0xcU] 
                                                << 2U));
    __Vtemp_h6c5e52f6__0[0xdU] = ((__Vtemp_h49659e28__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h49659e28__0[0xdU] 
                                                << 2U));
    __Vtemp_h6c5e52f6__0[0xeU] = ((__Vtemp_h49659e28__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h49659e28__0[0xeU] 
                                                << 2U));
    __Vtemp_h6c5e52f6__0[0xfU] = ((__Vtemp_h49659e28__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h49659e28__0[0xfU] 
                                                << 2U));
    __Vtemp_h6c5e52f6__0[0x10U] = ((__Vtemp_h49659e28__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h49659e28__0[0x10U] 
                                                 << 2U));
    __Vtemp_h6c5e52f6__0[0x11U] = ((__Vtemp_h49659e28__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h49659e28__0[0x11U] 
                                                 << 2U));
    __Vtemp_h6c5e52f6__0[0x12U] = ((__Vtemp_h49659e28__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h49659e28__0[0x12U] 
                                                 << 2U));
    __Vtemp_h6c5e52f6__0[0x13U] = ((__Vtemp_h49659e28__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h49659e28__0[0x13U] 
                                                 << 2U));
    __Vtemp_h6c5e52f6__0[0x14U] = ((__Vtemp_h49659e28__0[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h49659e28__0[0x14U] 
                                                 << 2U));
    __Vtemp_h6c5e52f6__0[0x15U] = ((__Vtemp_h49659e28__0[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h49659e28__0[0x15U] 
                                                 << 2U));
    __Vtemp_h6c5e52f6__0[0x16U] = ((__Vtemp_h49659e28__0[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h49659e28__0[0x16U] 
                                                 << 2U));
    __Vtemp_h6c5e52f6__0[0x17U] = ((__Vtemp_h49659e28__0[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h49659e28__0[0x17U] 
                                                 << 2U));
    __Vtemp_h6c5e52f6__0[0x18U] = ((__Vtemp_h49659e28__0[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h49659e28__0[0x18U] 
                                                 << 2U));
    __Vtemp_h6c5e52f6__0[0x19U] = ((__Vtemp_h49659e28__0[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h49659e28__0[0x19U] 
                                                 << 2U));
    __Vtemp_h6c5e52f6__0[0x1aU] = ((__Vtemp_h49659e28__0[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h49659e28__0[0x1aU] 
                                                 << 2U));
    __Vtemp_h6c5e52f6__0[0x1bU] = ((__Vtemp_h49659e28__0[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h49659e28__0[0x1bU] 
                                                 << 2U));
    __Vtemp_h6c5e52f6__0[0x1cU] = ((__Vtemp_h49659e28__0[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h49659e28__0[0x1cU] 
                                                 << 2U));
    __Vtemp_h6c5e52f6__0[0x1dU] = ((__Vtemp_h49659e28__0[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h49659e28__0[0x1dU] 
                                                 << 2U));
    __Vtemp_h6c5e52f6__0[0x1eU] = ((__Vtemp_h49659e28__0[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h49659e28__0[0x1eU] 
                                                 << 2U));
    __Vtemp_h6c5e52f6__0[0x1fU] = ((__Vtemp_h49659e28__0[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h49659e28__0[0x1fU] 
                                                 << 2U));
    __Vtemp_h6c5e52f6__0[0x20U] = ((__Vtemp_h49659e28__0[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h49659e28__0[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1039,1039,1039, __Vtemp_h4837c245__0, VTestHarness__ConstPool__CONST_h3892cc72_0, __Vtemp_h6c5e52f6__0);
    __Vtemp_hf2079383__0[1U] = (VTestHarness__ConstPool__CONST_h52851b57_0[1U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[1U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[1U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[1U] 
                                               & __Vtemp_h76f0401f__0[1U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[1U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[1U] 
                                                 & __Vtemp_h4837c245__0[1U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[1U])))));
    __Vtemp_hf2079383__0[2U] = (VTestHarness__ConstPool__CONST_h52851b57_0[2U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[2U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[2U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[2U] 
                                               & __Vtemp_h76f0401f__0[2U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[2U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[2U] 
                                                 & __Vtemp_h4837c245__0[2U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[2U])))));
    __Vtemp_hf2079383__0[3U] = (VTestHarness__ConstPool__CONST_h52851b57_0[3U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[3U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[3U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[3U] 
                                               & __Vtemp_h76f0401f__0[3U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[3U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[3U] 
                                                 & __Vtemp_h4837c245__0[3U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[3U])))));
    __Vtemp_hf2079383__0[4U] = (VTestHarness__ConstPool__CONST_h52851b57_0[4U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[4U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[4U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[4U] 
                                               & __Vtemp_h76f0401f__0[4U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[4U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[4U] 
                                                 & __Vtemp_h4837c245__0[4U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[4U])))));
    __Vtemp_hf2079383__0[5U] = (VTestHarness__ConstPool__CONST_h52851b57_0[5U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[5U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[5U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[5U] 
                                               & __Vtemp_h76f0401f__0[5U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[5U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[5U] 
                                                 & __Vtemp_h4837c245__0[5U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[5U])))));
    __Vtemp_hf2079383__0[6U] = (VTestHarness__ConstPool__CONST_h52851b57_0[6U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[6U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[6U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[6U] 
                                               & __Vtemp_h76f0401f__0[6U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[6U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[6U] 
                                                 & __Vtemp_h4837c245__0[6U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[6U])))));
    __Vtemp_hf2079383__0[7U] = (VTestHarness__ConstPool__CONST_h52851b57_0[7U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[7U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[7U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[7U] 
                                               & __Vtemp_h76f0401f__0[7U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[7U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[7U] 
                                                 & __Vtemp_h4837c245__0[7U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[7U])))));
    __Vtemp_hf2079383__0[8U] = (VTestHarness__ConstPool__CONST_h52851b57_0[8U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[8U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[8U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[8U] 
                                               & __Vtemp_h76f0401f__0[8U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[8U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[8U] 
                                                 & __Vtemp_h4837c245__0[8U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[8U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[0U] 
        = (VTestHarness__ConstPool__CONST_h52851b57_0[0U] 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
               ? VTestHarness__ConstPool__CONST_h478702bb_0[0U]
               : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[0U] 
                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                       ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[0U] 
                          & __Vtemp_h76f0401f__0[0U])
                       : VTestHarness__ConstPool__CONST_h478702bb_0[0U])) 
                  & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                         ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[0U] 
                            & __Vtemp_h4837c245__0[0U])
                         : VTestHarness__ConstPool__CONST_h478702bb_0[0U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[1U] 
        = __Vtemp_hf2079383__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[2U] 
        = __Vtemp_hf2079383__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[3U] 
        = __Vtemp_hf2079383__0[3U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[4U] 
        = __Vtemp_hf2079383__0[4U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[5U] 
        = __Vtemp_hf2079383__0[5U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[6U] 
        = __Vtemp_hf2079383__0[6U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[7U] 
        = __Vtemp_hf2079383__0[7U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_opcodes[8U] 
        = __Vtemp_hf2079383__0[8U];
    __Vtemp_hc961d23f__2[0U] = 1U;
    __Vtemp_hc961d23f__2[1U] = 0U;
    __Vtemp_hc961d23f__2[2U] = 0U;
    __Vtemp_hc961d23f__2[3U] = 0U;
    VL_EXTEND_WI(128,7, __Vtemp_h557ea57f__0, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___in_xbar_auto_out_a_bits_source));
    VL_SHIFTL_WWW(128,128,128, __Vtemp_hea2c6c8e__0, __Vtemp_hc961d23f__2, __Vtemp_h557ea57f__0);
    __Vtemp_hc961d23f__3[0U] = 1U;
    __Vtemp_hc961d23f__3[1U] = 0U;
    __Vtemp_hc961d23f__3[2U] = 0U;
    __Vtemp_hc961d23f__3[3U] = 0U;
    VL_EXTEND_WI(128,7, __Vtemp_h4a2dd5e2__1, (0x7fU 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 9U)));
    VL_SHIFTL_WWW(128,128,128, __Vtemp_h3b0efedd__0, __Vtemp_hc961d23f__3, __Vtemp_h4a2dd5e2__1);
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset) {
        __Vtemp_hc86c2840__0[1U] = 0U;
        __Vtemp_hc86c2840__0[2U] = 0U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__inflight[0U] = 0U;
    } else {
        __Vtemp_hc86c2840__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__inflight[1U] 
                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT___T_1572)
                                         ? __Vtemp_hea2c6c8e__0[1U]
                                         : 0U)) & (~ 
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT___T_1587)
                                                     ? 
                                                    __Vtemp_h3b0efedd__0[1U]
                                                     : 0U)));
        __Vtemp_hc86c2840__0[2U] = (1U & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__inflight[2U] 
                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT___T_1572)
                                               ? __Vtemp_hea2c6c8e__0[2U]
                                               : 0U)) 
                                          & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT___T_1587)
                                                 ? 
                                                __Vtemp_h3b0efedd__0[2U]
                                                 : 0U))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__inflight[0U] 
            = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__inflight[0U] 
                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT___T_1572)
                    ? __Vtemp_hea2c6c8e__0[0U] : 0U)) 
               & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT___T_1587)
                      ? __Vtemp_h3b0efedd__0[0U] : 0U)));
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__inflight[1U] 
        = __Vtemp_hc86c2840__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__atomics__DOT__monitor__DOT__inflight[2U] 
        = __Vtemp_hc86c2840__0[2U];
}

extern const VlWide<33>/*1055:0*/ VTestHarness__ConstPool__CONST_h81905067_0;
extern const VlWide<17>/*543:0*/ VTestHarness__ConstPool__CONST_h00a540f1_0;
extern const VlWide<17>/*543:0*/ VTestHarness__ConstPool__CONST_h881bc0c4_0;
extern const VlWide<33>/*1055:0*/ VTestHarness__ConstPool__CONST_hf1d99c4e_0;

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__14602(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__14602\n"); );
    // Init
    VlWide<17>/*543:0*/ __Vtemp_h9fa8950b__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9399755f__0;
    VlWide<33>/*1055:0*/ __Vtemp_h7f9506cd__0;
    VlWide<33>/*1055:0*/ __Vtemp_hc5d3210e__0;
    VlWide<33>/*1055:0*/ __Vtemp_h32940ee2__0;
    VlWide<33>/*1055:0*/ __Vtemp_h49659e28__0;
    VlWide<33>/*1055:0*/ __Vtemp_h6c5e42e7__0;
    VlWide<33>/*1055:0*/ __Vtemp_h723db94c__0;
    // Body
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset) {
        vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__d_first_counter_1 = 0U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__inflight = 0ULL;
    } else {
        if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1733) {
            vlSelf->__Vdly__TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__d_first_counter_1 
                = (0x1ffU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__d_first_1)
                              ? ((1U & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U])
                                  ? (~ (((0x1aU >= 
                                          (0xfU & (
                                                   vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 5U)))
                                          ? (0x7ffffffU 
                                             & ((IData)(0xfffU) 
                                                << 
                                                (0xfU 
                                                 & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                    >> 5U))))
                                          : 0U) >> 3U))
                                  : 0U) : ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__d_first_counter_1) 
                                           - (IData)(1U))));
        }
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__inflight 
            = (0x1ffffffffULL & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT__inflight 
                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT___T_1541)
                                      ? VL_SHIFTL_QQQ(33,64,64, 1ULL, (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_cbus_bus_xing_out_a_bits_source)))
                                      : 0ULL)) & (~ 
                                                  ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__in_xbar__DOT__monitor__DOT___T_1556)
                                                    ? 
                                                   VL_SHIFTL_QQQ(33,64,64, 1ULL, (QData)((IData)(
                                                                                (0x3fU 
                                                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                                                >> 9U)))))
                                                    : 0ULL))));
    }
    VL_EXTEND_WI(1028,5, __Vtemp_h9399755f__0, ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                                 ? 
                                                (1U 
                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_out_a_bits_size) 
                                                    << 1U))
                                                 : 0U));
    VL_EXTEND_WI(1025,7, __Vtemp_h7f9506cd__0, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT___atomics_auto_out_a_bits_source));
    __Vtemp_hc5d3210e__0[0U] = (__Vtemp_h7f9506cd__0[0U] 
                                << 3U);
    __Vtemp_hc5d3210e__0[1U] = ((__Vtemp_h7f9506cd__0[0U] 
                                 >> 0x1dU) | (__Vtemp_h7f9506cd__0[1U] 
                                              << 3U));
    __Vtemp_hc5d3210e__0[2U] = ((__Vtemp_h7f9506cd__0[1U] 
                                 >> 0x1dU) | (__Vtemp_h7f9506cd__0[2U] 
                                              << 3U));
    __Vtemp_hc5d3210e__0[3U] = ((__Vtemp_h7f9506cd__0[2U] 
                                 >> 0x1dU) | (__Vtemp_h7f9506cd__0[3U] 
                                              << 3U));
    __Vtemp_hc5d3210e__0[4U] = ((__Vtemp_h7f9506cd__0[3U] 
                                 >> 0x1dU) | (__Vtemp_h7f9506cd__0[4U] 
                                              << 3U));
    __Vtemp_hc5d3210e__0[5U] = ((__Vtemp_h7f9506cd__0[4U] 
                                 >> 0x1dU) | (__Vtemp_h7f9506cd__0[5U] 
                                              << 3U));
    __Vtemp_hc5d3210e__0[6U] = ((__Vtemp_h7f9506cd__0[5U] 
                                 >> 0x1dU) | (__Vtemp_h7f9506cd__0[6U] 
                                              << 3U));
    __Vtemp_hc5d3210e__0[7U] = ((__Vtemp_h7f9506cd__0[6U] 
                                 >> 0x1dU) | (__Vtemp_h7f9506cd__0[7U] 
                                              << 3U));
    __Vtemp_hc5d3210e__0[8U] = ((__Vtemp_h7f9506cd__0[7U] 
                                 >> 0x1dU) | (__Vtemp_h7f9506cd__0[8U] 
                                              << 3U));
    __Vtemp_hc5d3210e__0[9U] = ((__Vtemp_h7f9506cd__0[8U] 
                                 >> 0x1dU) | (__Vtemp_h7f9506cd__0[9U] 
                                              << 3U));
    __Vtemp_hc5d3210e__0[0xaU] = ((__Vtemp_h7f9506cd__0[9U] 
                                   >> 0x1dU) | (__Vtemp_h7f9506cd__0[0xaU] 
                                                << 3U));
    __Vtemp_hc5d3210e__0[0xbU] = ((__Vtemp_h7f9506cd__0[0xaU] 
                                   >> 0x1dU) | (__Vtemp_h7f9506cd__0[0xbU] 
                                                << 3U));
    __Vtemp_hc5d3210e__0[0xcU] = ((__Vtemp_h7f9506cd__0[0xbU] 
                                   >> 0x1dU) | (__Vtemp_h7f9506cd__0[0xcU] 
                                                << 3U));
    __Vtemp_hc5d3210e__0[0xdU] = ((__Vtemp_h7f9506cd__0[0xcU] 
                                   >> 0x1dU) | (__Vtemp_h7f9506cd__0[0xdU] 
                                                << 3U));
    __Vtemp_hc5d3210e__0[0xeU] = ((__Vtemp_h7f9506cd__0[0xdU] 
                                   >> 0x1dU) | (__Vtemp_h7f9506cd__0[0xeU] 
                                                << 3U));
    __Vtemp_hc5d3210e__0[0xfU] = ((__Vtemp_h7f9506cd__0[0xeU] 
                                   >> 0x1dU) | (__Vtemp_h7f9506cd__0[0xfU] 
                                                << 3U));
    __Vtemp_hc5d3210e__0[0x10U] = ((__Vtemp_h7f9506cd__0[0xfU] 
                                    >> 0x1dU) | (__Vtemp_h7f9506cd__0[0x10U] 
                                                 << 3U));
    __Vtemp_hc5d3210e__0[0x11U] = ((__Vtemp_h7f9506cd__0[0x10U] 
                                    >> 0x1dU) | (__Vtemp_h7f9506cd__0[0x11U] 
                                                 << 3U));
    __Vtemp_hc5d3210e__0[0x12U] = ((__Vtemp_h7f9506cd__0[0x11U] 
                                    >> 0x1dU) | (__Vtemp_h7f9506cd__0[0x12U] 
                                                 << 3U));
    __Vtemp_hc5d3210e__0[0x13U] = ((__Vtemp_h7f9506cd__0[0x12U] 
                                    >> 0x1dU) | (__Vtemp_h7f9506cd__0[0x13U] 
                                                 << 3U));
    __Vtemp_hc5d3210e__0[0x14U] = ((__Vtemp_h7f9506cd__0[0x13U] 
                                    >> 0x1dU) | (__Vtemp_h7f9506cd__0[0x14U] 
                                                 << 3U));
    __Vtemp_hc5d3210e__0[0x15U] = ((__Vtemp_h7f9506cd__0[0x14U] 
                                    >> 0x1dU) | (__Vtemp_h7f9506cd__0[0x15U] 
                                                 << 3U));
    __Vtemp_hc5d3210e__0[0x16U] = ((__Vtemp_h7f9506cd__0[0x15U] 
                                    >> 0x1dU) | (__Vtemp_h7f9506cd__0[0x16U] 
                                                 << 3U));
    __Vtemp_hc5d3210e__0[0x17U] = ((__Vtemp_h7f9506cd__0[0x16U] 
                                    >> 0x1dU) | (__Vtemp_h7f9506cd__0[0x17U] 
                                                 << 3U));
    __Vtemp_hc5d3210e__0[0x18U] = ((__Vtemp_h7f9506cd__0[0x17U] 
                                    >> 0x1dU) | (__Vtemp_h7f9506cd__0[0x18U] 
                                                 << 3U));
    __Vtemp_hc5d3210e__0[0x19U] = ((__Vtemp_h7f9506cd__0[0x18U] 
                                    >> 0x1dU) | (__Vtemp_h7f9506cd__0[0x19U] 
                                                 << 3U));
    __Vtemp_hc5d3210e__0[0x1aU] = ((__Vtemp_h7f9506cd__0[0x19U] 
                                    >> 0x1dU) | (__Vtemp_h7f9506cd__0[0x1aU] 
                                                 << 3U));
    __Vtemp_hc5d3210e__0[0x1bU] = ((__Vtemp_h7f9506cd__0[0x1aU] 
                                    >> 0x1dU) | (__Vtemp_h7f9506cd__0[0x1bU] 
                                                 << 3U));
    __Vtemp_hc5d3210e__0[0x1cU] = ((__Vtemp_h7f9506cd__0[0x1bU] 
                                    >> 0x1dU) | (__Vtemp_h7f9506cd__0[0x1cU] 
                                                 << 3U));
    __Vtemp_hc5d3210e__0[0x1dU] = ((__Vtemp_h7f9506cd__0[0x1cU] 
                                    >> 0x1dU) | (__Vtemp_h7f9506cd__0[0x1dU] 
                                                 << 3U));
    __Vtemp_hc5d3210e__0[0x1eU] = ((__Vtemp_h7f9506cd__0[0x1dU] 
                                    >> 0x1dU) | (__Vtemp_h7f9506cd__0[0x1eU] 
                                                 << 3U));
    __Vtemp_hc5d3210e__0[0x1fU] = ((__Vtemp_h7f9506cd__0[0x1eU] 
                                    >> 0x1dU) | (__Vtemp_h7f9506cd__0[0x1fU] 
                                                 << 3U));
    __Vtemp_hc5d3210e__0[0x20U] = ((__Vtemp_h7f9506cd__0[0x1fU] 
                                    >> 0x1dU) | (__Vtemp_h7f9506cd__0[0x20U] 
                                                 << 3U));
    VL_SHIFTL_WWW(1028,1028,1028, __Vtemp_h32940ee2__0, __Vtemp_h9399755f__0, __Vtemp_hc5d3210e__0);
    VL_EXTEND_WI(1036,7, __Vtemp_h49659e28__0, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 9U)));
    __Vtemp_h6c5e42e7__0[0U] = (__Vtemp_h49659e28__0[0U] 
                                << 3U);
    __Vtemp_h6c5e42e7__0[1U] = ((__Vtemp_h49659e28__0[0U] 
                                 >> 0x1dU) | (__Vtemp_h49659e28__0[1U] 
                                              << 3U));
    __Vtemp_h6c5e42e7__0[2U] = ((__Vtemp_h49659e28__0[1U] 
                                 >> 0x1dU) | (__Vtemp_h49659e28__0[2U] 
                                              << 3U));
    __Vtemp_h6c5e42e7__0[3U] = ((__Vtemp_h49659e28__0[2U] 
                                 >> 0x1dU) | (__Vtemp_h49659e28__0[3U] 
                                              << 3U));
    __Vtemp_h6c5e42e7__0[4U] = ((__Vtemp_h49659e28__0[3U] 
                                 >> 0x1dU) | (__Vtemp_h49659e28__0[4U] 
                                              << 3U));
    __Vtemp_h6c5e42e7__0[5U] = ((__Vtemp_h49659e28__0[4U] 
                                 >> 0x1dU) | (__Vtemp_h49659e28__0[5U] 
                                              << 3U));
    __Vtemp_h6c5e42e7__0[6U] = ((__Vtemp_h49659e28__0[5U] 
                                 >> 0x1dU) | (__Vtemp_h49659e28__0[6U] 
                                              << 3U));
    __Vtemp_h6c5e42e7__0[7U] = ((__Vtemp_h49659e28__0[6U] 
                                 >> 0x1dU) | (__Vtemp_h49659e28__0[7U] 
                                              << 3U));
    __Vtemp_h6c5e42e7__0[8U] = ((__Vtemp_h49659e28__0[7U] 
                                 >> 0x1dU) | (__Vtemp_h49659e28__0[8U] 
                                              << 3U));
    __Vtemp_h6c5e42e7__0[9U] = ((__Vtemp_h49659e28__0[8U] 
                                 >> 0x1dU) | (__Vtemp_h49659e28__0[9U] 
                                              << 3U));
    __Vtemp_h6c5e42e7__0[0xaU] = ((__Vtemp_h49659e28__0[9U] 
                                   >> 0x1dU) | (__Vtemp_h49659e28__0[0xaU] 
                                                << 3U));
    __Vtemp_h6c5e42e7__0[0xbU] = ((__Vtemp_h49659e28__0[0xaU] 
                                   >> 0x1dU) | (__Vtemp_h49659e28__0[0xbU] 
                                                << 3U));
    __Vtemp_h6c5e42e7__0[0xcU] = ((__Vtemp_h49659e28__0[0xbU] 
                                   >> 0x1dU) | (__Vtemp_h49659e28__0[0xcU] 
                                                << 3U));
    __Vtemp_h6c5e42e7__0[0xdU] = ((__Vtemp_h49659e28__0[0xcU] 
                                   >> 0x1dU) | (__Vtemp_h49659e28__0[0xdU] 
                                                << 3U));
    __Vtemp_h6c5e42e7__0[0xeU] = ((__Vtemp_h49659e28__0[0xdU] 
                                   >> 0x1dU) | (__Vtemp_h49659e28__0[0xeU] 
                                                << 3U));
    __Vtemp_h6c5e42e7__0[0xfU] = ((__Vtemp_h49659e28__0[0xeU] 
                                   >> 0x1dU) | (__Vtemp_h49659e28__0[0xfU] 
                                                << 3U));
    __Vtemp_h6c5e42e7__0[0x10U] = ((__Vtemp_h49659e28__0[0xfU] 
                                    >> 0x1dU) | (__Vtemp_h49659e28__0[0x10U] 
                                                 << 3U));
    __Vtemp_h6c5e42e7__0[0x11U] = ((__Vtemp_h49659e28__0[0x10U] 
                                    >> 0x1dU) | (__Vtemp_h49659e28__0[0x11U] 
                                                 << 3U));
    __Vtemp_h6c5e42e7__0[0x12U] = ((__Vtemp_h49659e28__0[0x11U] 
                                    >> 0x1dU) | (__Vtemp_h49659e28__0[0x12U] 
                                                 << 3U));
    __Vtemp_h6c5e42e7__0[0x13U] = ((__Vtemp_h49659e28__0[0x12U] 
                                    >> 0x1dU) | (__Vtemp_h49659e28__0[0x13U] 
                                                 << 3U));
    __Vtemp_h6c5e42e7__0[0x14U] = ((__Vtemp_h49659e28__0[0x13U] 
                                    >> 0x1dU) | (__Vtemp_h49659e28__0[0x14U] 
                                                 << 3U));
    __Vtemp_h6c5e42e7__0[0x15U] = ((__Vtemp_h49659e28__0[0x14U] 
                                    >> 0x1dU) | (__Vtemp_h49659e28__0[0x15U] 
                                                 << 3U));
    __Vtemp_h6c5e42e7__0[0x16U] = ((__Vtemp_h49659e28__0[0x15U] 
                                    >> 0x1dU) | (__Vtemp_h49659e28__0[0x16U] 
                                                 << 3U));
    __Vtemp_h6c5e42e7__0[0x17U] = ((__Vtemp_h49659e28__0[0x16U] 
                                    >> 0x1dU) | (__Vtemp_h49659e28__0[0x17U] 
                                                 << 3U));
    __Vtemp_h6c5e42e7__0[0x18U] = ((__Vtemp_h49659e28__0[0x17U] 
                                    >> 0x1dU) | (__Vtemp_h49659e28__0[0x18U] 
                                                 << 3U));
    __Vtemp_h6c5e42e7__0[0x19U] = ((__Vtemp_h49659e28__0[0x18U] 
                                    >> 0x1dU) | (__Vtemp_h49659e28__0[0x19U] 
                                                 << 3U));
    __Vtemp_h6c5e42e7__0[0x1aU] = ((__Vtemp_h49659e28__0[0x19U] 
                                    >> 0x1dU) | (__Vtemp_h49659e28__0[0x1aU] 
                                                 << 3U));
    __Vtemp_h6c5e42e7__0[0x1bU] = ((__Vtemp_h49659e28__0[0x1aU] 
                                    >> 0x1dU) | (__Vtemp_h49659e28__0[0x1bU] 
                                                 << 3U));
    __Vtemp_h6c5e42e7__0[0x1cU] = ((__Vtemp_h49659e28__0[0x1bU] 
                                    >> 0x1dU) | (__Vtemp_h49659e28__0[0x1cU] 
                                                 << 3U));
    __Vtemp_h6c5e42e7__0[0x1dU] = ((__Vtemp_h49659e28__0[0x1cU] 
                                    >> 0x1dU) | (__Vtemp_h49659e28__0[0x1dU] 
                                                 << 3U));
    __Vtemp_h6c5e42e7__0[0x1eU] = ((__Vtemp_h49659e28__0[0x1dU] 
                                    >> 0x1dU) | (__Vtemp_h49659e28__0[0x1eU] 
                                                 << 3U));
    __Vtemp_h6c5e42e7__0[0x1fU] = ((__Vtemp_h49659e28__0[0x1eU] 
                                    >> 0x1dU) | (__Vtemp_h49659e28__0[0x1fU] 
                                                 << 3U));
    __Vtemp_h6c5e42e7__0[0x20U] = ((__Vtemp_h49659e28__0[0x1fU] 
                                    >> 0x1dU) | (__Vtemp_h49659e28__0[0x20U] 
                                                 << 3U));
    VL_SHIFTL_WWW(1039,1039,1039, __Vtemp_h723db94c__0, VTestHarness__ConstPool__CONST_h81905067_0, __Vtemp_h6c5e42e7__0);
    __Vtemp_h9fa8950b__0[1U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[1U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[1U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[1U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[1U] 
                                               & __Vtemp_h32940ee2__0[1U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[1U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[1U] 
                                                 & __Vtemp_h723db94c__0[1U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[1U])))));
    __Vtemp_h9fa8950b__0[2U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[2U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[2U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[2U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[2U] 
                                               & __Vtemp_h32940ee2__0[2U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[2U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[2U] 
                                                 & __Vtemp_h723db94c__0[2U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[2U])))));
    __Vtemp_h9fa8950b__0[3U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[3U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[3U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[3U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[3U] 
                                               & __Vtemp_h32940ee2__0[3U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[3U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[3U] 
                                                 & __Vtemp_h723db94c__0[3U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[3U])))));
    __Vtemp_h9fa8950b__0[4U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[4U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[4U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[4U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[4U] 
                                               & __Vtemp_h32940ee2__0[4U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[4U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[4U] 
                                                 & __Vtemp_h723db94c__0[4U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[4U])))));
    __Vtemp_h9fa8950b__0[5U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[5U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[5U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[5U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[5U] 
                                               & __Vtemp_h32940ee2__0[5U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[5U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[5U] 
                                                 & __Vtemp_h723db94c__0[5U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[5U])))));
    __Vtemp_h9fa8950b__0[6U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[6U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[6U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[6U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[6U] 
                                               & __Vtemp_h32940ee2__0[6U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[6U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[6U] 
                                                 & __Vtemp_h723db94c__0[6U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[6U])))));
    __Vtemp_h9fa8950b__0[7U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[7U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[7U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[7U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[7U] 
                                               & __Vtemp_h32940ee2__0[7U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[7U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[7U] 
                                                 & __Vtemp_h723db94c__0[7U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[7U])))));
    __Vtemp_h9fa8950b__0[8U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[8U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[8U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[8U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[8U] 
                                               & __Vtemp_h32940ee2__0[8U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[8U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[8U] 
                                                 & __Vtemp_h723db94c__0[8U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[8U])))));
    __Vtemp_h9fa8950b__0[9U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[9U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h881bc0c4_0[9U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[9U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[9U] 
                                               & __Vtemp_h32940ee2__0[9U])
                                            : VTestHarness__ConstPool__CONST_h881bc0c4_0[9U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[9U] 
                                                 & __Vtemp_h723db94c__0[9U])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[9U])))));
    __Vtemp_h9fa8950b__0[0xaU] = (VTestHarness__ConstPool__CONST_h00a540f1_0[0xaU] 
                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                      ? VTestHarness__ConstPool__CONST_h881bc0c4_0[0xaU]
                                      : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0xaU] 
                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                              ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[0xaU] 
                                                 & __Vtemp_h32940ee2__0[0xaU])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xaU])) 
                                         & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                                                ? (
                                                   VTestHarness__ConstPool__CONST_hf1d81c7e_0[0xaU] 
                                                   & __Vtemp_h723db94c__0[0xaU])
                                                : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xaU])))));
    __Vtemp_h9fa8950b__0[0xbU] = (VTestHarness__ConstPool__CONST_h00a540f1_0[0xbU] 
                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                      ? VTestHarness__ConstPool__CONST_h881bc0c4_0[0xbU]
                                      : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0xbU] 
                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                              ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[0xbU] 
                                                 & __Vtemp_h32940ee2__0[0xbU])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xbU])) 
                                         & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                                                ? (
                                                   VTestHarness__ConstPool__CONST_hf1d81c7e_0[0xbU] 
                                                   & __Vtemp_h723db94c__0[0xbU])
                                                : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xbU])))));
    __Vtemp_h9fa8950b__0[0xcU] = (VTestHarness__ConstPool__CONST_h00a540f1_0[0xcU] 
                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                      ? VTestHarness__ConstPool__CONST_h881bc0c4_0[0xcU]
                                      : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0xcU] 
                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                              ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[0xcU] 
                                                 & __Vtemp_h32940ee2__0[0xcU])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xcU])) 
                                         & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                                                ? (
                                                   VTestHarness__ConstPool__CONST_hf1d81c7e_0[0xcU] 
                                                   & __Vtemp_h723db94c__0[0xcU])
                                                : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xcU])))));
    __Vtemp_h9fa8950b__0[0xdU] = (VTestHarness__ConstPool__CONST_h00a540f1_0[0xdU] 
                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                      ? VTestHarness__ConstPool__CONST_h881bc0c4_0[0xdU]
                                      : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0xdU] 
                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                              ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[0xdU] 
                                                 & __Vtemp_h32940ee2__0[0xdU])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xdU])) 
                                         & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                                                ? (
                                                   VTestHarness__ConstPool__CONST_hf1d81c7e_0[0xdU] 
                                                   & __Vtemp_h723db94c__0[0xdU])
                                                : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xdU])))));
    __Vtemp_h9fa8950b__0[0xeU] = (VTestHarness__ConstPool__CONST_h00a540f1_0[0xeU] 
                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                      ? VTestHarness__ConstPool__CONST_h881bc0c4_0[0xeU]
                                      : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0xeU] 
                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                              ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[0xeU] 
                                                 & __Vtemp_h32940ee2__0[0xeU])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xeU])) 
                                         & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                                                ? (
                                                   VTestHarness__ConstPool__CONST_hf1d81c7e_0[0xeU] 
                                                   & __Vtemp_h723db94c__0[0xeU])
                                                : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xeU])))));
    __Vtemp_h9fa8950b__0[0xfU] = (VTestHarness__ConstPool__CONST_h00a540f1_0[0xfU] 
                                  & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                      ? VTestHarness__ConstPool__CONST_h881bc0c4_0[0xfU]
                                      : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0xfU] 
                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                              ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[0xfU] 
                                                 & __Vtemp_h32940ee2__0[0xfU])
                                              : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xfU])) 
                                         & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                                                ? (
                                                   VTestHarness__ConstPool__CONST_hf1d81c7e_0[0xfU] 
                                                   & __Vtemp_h723db94c__0[0xfU])
                                                : VTestHarness__ConstPool__CONST_h881bc0c4_0[0xfU])))));
    __Vtemp_h9fa8950b__0[0x10U] = (VTestHarness__ConstPool__CONST_h00a540f1_0[0x10U] 
                                   & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                       ? VTestHarness__ConstPool__CONST_h881bc0c4_0[0x10U]
                                       : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0x10U] 
                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                                               ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[0x10U] 
                                                  & __Vtemp_h32940ee2__0[0x10U])
                                               : VTestHarness__ConstPool__CONST_h881bc0c4_0[0x10U])) 
                                          & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                                                 ? 
                                                (VTestHarness__ConstPool__CONST_hf1d81c7e_0[0x10U] 
                                                 & __Vtemp_h723db94c__0[0x10U])
                                                 : 
                                                VTestHarness__ConstPool__CONST_h881bc0c4_0[0x10U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0U] 
        = (VTestHarness__ConstPool__CONST_h00a540f1_0[0U] 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
               ? VTestHarness__ConstPool__CONST_h881bc0c4_0[0U]
               : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0U] 
                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1584)
                       ? (VTestHarness__ConstPool__CONST_hf1d99c4e_0[0U] 
                          & __Vtemp_h32940ee2__0[0U])
                       : VTestHarness__ConstPool__CONST_h881bc0c4_0[0U])) 
                  & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT___T_1599)
                         ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[0U] 
                            & __Vtemp_h723db94c__0[0U])
                         : VTestHarness__ConstPool__CONST_h881bc0c4_0[0U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[1U] 
        = __Vtemp_h9fa8950b__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[2U] 
        = __Vtemp_h9fa8950b__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[3U] 
        = __Vtemp_h9fa8950b__0[3U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[4U] 
        = __Vtemp_h9fa8950b__0[4U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[5U] 
        = __Vtemp_h9fa8950b__0[5U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[6U] 
        = __Vtemp_h9fa8950b__0[6U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[7U] 
        = __Vtemp_h9fa8950b__0[7U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[8U] 
        = __Vtemp_h9fa8950b__0[8U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[9U] 
        = __Vtemp_h9fa8950b__0[9U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0xaU] 
        = __Vtemp_h9fa8950b__0[0xaU];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0xbU] 
        = __Vtemp_h9fa8950b__0[0xbU];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0xcU] 
        = __Vtemp_h9fa8950b__0[0xcU];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0xdU] 
        = __Vtemp_h9fa8950b__0[0xdU];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0xeU] 
        = __Vtemp_h9fa8950b__0[0xeU];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0xfU] 
        = __Vtemp_h9fa8950b__0[0xfU];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__monitor__DOT__inflight_sizes[0x10U] 
        = __Vtemp_h9fa8950b__0[0x10U];
}
