// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTestHarness.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTestHarness___024root.h"

extern const VlWide<33>/*1055:0*/ VTestHarness__ConstPool__CONST_h3892cc72_0;
extern const VlWide<9>/*287:0*/ VTestHarness__ConstPool__CONST_h52851b57_0;
extern const VlWide<9>/*287:0*/ VTestHarness__ConstPool__CONST_h478702bb_0;
extern const VlWide<33>/*1055:0*/ VTestHarness__ConstPool__CONST_hf1d99c76_0;
extern const VlWide<33>/*1055:0*/ VTestHarness__ConstPool__CONST_hf1d81c7e_0;

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__15236(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__15236\n"); );
    // Init
    VlWide<9>/*287:0*/ __Vtemp_hfe11e144__0;
    VlWide<33>/*1055:0*/ __Vtemp_hdca7a285__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9dd30ecc__0;
    VlWide<33>/*1055:0*/ __Vtemp_h65421e99__0;
    VlWide<33>/*1055:0*/ __Vtemp_h14c91a2a__0;
    VlWide<33>/*1055:0*/ __Vtemp_h79ba5bbc__0;
    VlWide<33>/*1055:0*/ __Vtemp_h328a2130__0;
    VlWide<33>/*1055:0*/ __Vtemp_h45b86d9b__0;
    // Body
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_3__DOT__slot_uop_br_mask 
        = ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__issue_slots_3_in_uop_valid)
            ? ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__next_5))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_6__DOT__next_br_mask)
                : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__next_4))
                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_5__DOT__next_br_mask)
                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_4__DOT__next_br_mask)))
            : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_3__DOT__next_br_mask));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_sbus_0_reset) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_3__DOT__slot_uop_uopc = 0U;
    } else if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__issue_slots_3_in_uop_valid) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_3__DOT__slot_uop_uopc 
            = ((4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__next_5))
                ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT___slots_6_io_out_uop_uopc)
                : ((2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__next_4))
                    ? (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT___slots_5_io_out_uop_uopc)
                    : (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT___slots_4_io_out_uop_uopc)));
    } else if ((1U & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_3__DOT___GEN_0)))) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__core__DOT__fp_pipeline__DOT__fp_issue_unit__DOT__slots_3__DOT__slot_uop_uopc = 3U;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__respq__DOT___GEN_10) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__respq__DOT__uops_1_is_amo 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT___resp_arb_io_out_bits_uop_is_amo;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__respq__DOT___GEN_12) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__respq__DOT__uops_2_is_amo 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT___resp_arb_io_out_bits_uop_is_amo;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__respq__DOT___GEN_13) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__respq__DOT__uops_3_is_amo 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT___resp_arb_io_out_bits_uop_is_amo;
    }
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__respq__DOT___GEN_8) {
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT__respq__DOT__uops_0_is_amo 
            = vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__tile_reset_domain_boom_tile__DOT__dcache__DOT__mshrs__DOT___resp_arb_io_out_bits_uop_is_amo;
    }
    VL_EXTEND_WI(1027,4, __Vtemp_hdca7a285__0, ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                                 ? 
                                                (1U 
                                                 | (0xeU 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       << 1U)))
                                                 : 0U));
    VL_EXTEND_WI(1025,7, __Vtemp_h9dd30ecc__0, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)));
    __Vtemp_h65421e99__0[0U] = (__Vtemp_h9dd30ecc__0[0U] 
                                << 2U);
    __Vtemp_h65421e99__0[1U] = ((__Vtemp_h9dd30ecc__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[1U] 
                                              << 2U));
    __Vtemp_h65421e99__0[2U] = ((__Vtemp_h9dd30ecc__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[2U] 
                                              << 2U));
    __Vtemp_h65421e99__0[3U] = ((__Vtemp_h9dd30ecc__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[3U] 
                                              << 2U));
    __Vtemp_h65421e99__0[4U] = ((__Vtemp_h9dd30ecc__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[4U] 
                                              << 2U));
    __Vtemp_h65421e99__0[5U] = ((__Vtemp_h9dd30ecc__0[4U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[5U] 
                                              << 2U));
    __Vtemp_h65421e99__0[6U] = ((__Vtemp_h9dd30ecc__0[5U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[6U] 
                                              << 2U));
    __Vtemp_h65421e99__0[7U] = ((__Vtemp_h9dd30ecc__0[6U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[7U] 
                                              << 2U));
    __Vtemp_h65421e99__0[8U] = ((__Vtemp_h9dd30ecc__0[7U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[8U] 
                                              << 2U));
    __Vtemp_h65421e99__0[9U] = ((__Vtemp_h9dd30ecc__0[8U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[9U] 
                                              << 2U));
    __Vtemp_h65421e99__0[0xaU] = ((__Vtemp_h9dd30ecc__0[9U] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xaU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xbU] = ((__Vtemp_h9dd30ecc__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xbU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xcU] = ((__Vtemp_h9dd30ecc__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xcU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xdU] = ((__Vtemp_h9dd30ecc__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xdU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xeU] = ((__Vtemp_h9dd30ecc__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xeU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xfU] = ((__Vtemp_h9dd30ecc__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xfU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0x10U] = ((__Vtemp_h9dd30ecc__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x10U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x11U] = ((__Vtemp_h9dd30ecc__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x11U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x12U] = ((__Vtemp_h9dd30ecc__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x12U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x13U] = ((__Vtemp_h9dd30ecc__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x13U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x14U] = ((__Vtemp_h9dd30ecc__0[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x14U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x15U] = ((__Vtemp_h9dd30ecc__0[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x15U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x16U] = ((__Vtemp_h9dd30ecc__0[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x16U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x17U] = ((__Vtemp_h9dd30ecc__0[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x17U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x18U] = ((__Vtemp_h9dd30ecc__0[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x18U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x19U] = ((__Vtemp_h9dd30ecc__0[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x19U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1aU] = ((__Vtemp_h9dd30ecc__0[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1aU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1bU] = ((__Vtemp_h9dd30ecc__0[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1bU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1cU] = ((__Vtemp_h9dd30ecc__0[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1cU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1dU] = ((__Vtemp_h9dd30ecc__0[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1dU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1eU] = ((__Vtemp_h9dd30ecc__0[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1eU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1fU] = ((__Vtemp_h9dd30ecc__0[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1fU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x20U] = ((__Vtemp_h9dd30ecc__0[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1027,1027,1027, __Vtemp_h14c91a2a__0, __Vtemp_hdca7a285__0, __Vtemp_h65421e99__0);
    VL_EXTEND_WI(1037,7, __Vtemp_h79ba5bbc__0, (0x7fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_clint_fragmenter_out_a_bits_source) 
                                                   >> 4U)));
    __Vtemp_h328a2130__0[0U] = (__Vtemp_h79ba5bbc__0[0U] 
                                << 2U);
    __Vtemp_h328a2130__0[1U] = ((__Vtemp_h79ba5bbc__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h79ba5bbc__0[1U] 
                                              << 2U));
    __Vtemp_h328a2130__0[2U] = ((__Vtemp_h79ba5bbc__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h79ba5bbc__0[2U] 
                                              << 2U));
    __Vtemp_h328a2130__0[3U] = ((__Vtemp_h79ba5bbc__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h79ba5bbc__0[3U] 
                                              << 2U));
    __Vtemp_h328a2130__0[4U] = ((__Vtemp_h79ba5bbc__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h79ba5bbc__0[4U] 
                                              << 2U));
    __Vtemp_h328a2130__0[5U] = ((__Vtemp_h79ba5bbc__0[4U] 
                                 >> 0x1eU) | (__Vtemp_h79ba5bbc__0[5U] 
                                              << 2U));
    __Vtemp_h328a2130__0[6U] = ((__Vtemp_h79ba5bbc__0[5U] 
                                 >> 0x1eU) | (__Vtemp_h79ba5bbc__0[6U] 
                                              << 2U));
    __Vtemp_h328a2130__0[7U] = ((__Vtemp_h79ba5bbc__0[6U] 
                                 >> 0x1eU) | (__Vtemp_h79ba5bbc__0[7U] 
                                              << 2U));
    __Vtemp_h328a2130__0[8U] = ((__Vtemp_h79ba5bbc__0[7U] 
                                 >> 0x1eU) | (__Vtemp_h79ba5bbc__0[8U] 
                                              << 2U));
    __Vtemp_h328a2130__0[9U] = ((__Vtemp_h79ba5bbc__0[8U] 
                                 >> 0x1eU) | (__Vtemp_h79ba5bbc__0[9U] 
                                              << 2U));
    __Vtemp_h328a2130__0[0xaU] = ((__Vtemp_h79ba5bbc__0[9U] 
                                   >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0xaU] 
                                                << 2U));
    __Vtemp_h328a2130__0[0xbU] = ((__Vtemp_h79ba5bbc__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0xbU] 
                                                << 2U));
    __Vtemp_h328a2130__0[0xcU] = ((__Vtemp_h79ba5bbc__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0xcU] 
                                                << 2U));
    __Vtemp_h328a2130__0[0xdU] = ((__Vtemp_h79ba5bbc__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0xdU] 
                                                << 2U));
    __Vtemp_h328a2130__0[0xeU] = ((__Vtemp_h79ba5bbc__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0xeU] 
                                                << 2U));
    __Vtemp_h328a2130__0[0xfU] = ((__Vtemp_h79ba5bbc__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0xfU] 
                                                << 2U));
    __Vtemp_h328a2130__0[0x10U] = ((__Vtemp_h79ba5bbc__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x10U] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x11U] = ((__Vtemp_h79ba5bbc__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x11U] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x12U] = ((__Vtemp_h79ba5bbc__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x12U] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x13U] = ((__Vtemp_h79ba5bbc__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x13U] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x14U] = ((__Vtemp_h79ba5bbc__0[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x14U] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x15U] = ((__Vtemp_h79ba5bbc__0[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x15U] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x16U] = ((__Vtemp_h79ba5bbc__0[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x16U] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x17U] = ((__Vtemp_h79ba5bbc__0[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x17U] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x18U] = ((__Vtemp_h79ba5bbc__0[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x18U] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x19U] = ((__Vtemp_h79ba5bbc__0[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x19U] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x1aU] = ((__Vtemp_h79ba5bbc__0[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x1aU] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x1bU] = ((__Vtemp_h79ba5bbc__0[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x1bU] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x1cU] = ((__Vtemp_h79ba5bbc__0[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x1cU] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x1dU] = ((__Vtemp_h79ba5bbc__0[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x1dU] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x1eU] = ((__Vtemp_h79ba5bbc__0[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x1eU] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x1fU] = ((__Vtemp_h79ba5bbc__0[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x1fU] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x20U] = ((__Vtemp_h79ba5bbc__0[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1039,1039,1039, __Vtemp_h45b86d9b__0, VTestHarness__ConstPool__CONST_h3892cc72_0, __Vtemp_h328a2130__0);
    __Vtemp_hfe11e144__0[1U] = (VTestHarness__ConstPool__CONST_h52851b57_0[1U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[1U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[1U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[1U] 
                                               & __Vtemp_h14c91a2a__0[1U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[1U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[1U] 
                                                 & __Vtemp_h45b86d9b__0[1U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[1U])))));
    __Vtemp_hfe11e144__0[2U] = (VTestHarness__ConstPool__CONST_h52851b57_0[2U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[2U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[2U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[2U] 
                                               & __Vtemp_h14c91a2a__0[2U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[2U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[2U] 
                                                 & __Vtemp_h45b86d9b__0[2U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[2U])))));
    __Vtemp_hfe11e144__0[3U] = (VTestHarness__ConstPool__CONST_h52851b57_0[3U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[3U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[3U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[3U] 
                                               & __Vtemp_h14c91a2a__0[3U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[3U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[3U] 
                                                 & __Vtemp_h45b86d9b__0[3U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[3U])))));
    __Vtemp_hfe11e144__0[4U] = (VTestHarness__ConstPool__CONST_h52851b57_0[4U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[4U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[4U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[4U] 
                                               & __Vtemp_h14c91a2a__0[4U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[4U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[4U] 
                                                 & __Vtemp_h45b86d9b__0[4U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[4U])))));
    __Vtemp_hfe11e144__0[5U] = (VTestHarness__ConstPool__CONST_h52851b57_0[5U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[5U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[5U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[5U] 
                                               & __Vtemp_h14c91a2a__0[5U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[5U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[5U] 
                                                 & __Vtemp_h45b86d9b__0[5U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[5U])))));
    __Vtemp_hfe11e144__0[6U] = (VTestHarness__ConstPool__CONST_h52851b57_0[6U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[6U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[6U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[6U] 
                                               & __Vtemp_h14c91a2a__0[6U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[6U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[6U] 
                                                 & __Vtemp_h45b86d9b__0[6U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[6U])))));
    __Vtemp_hfe11e144__0[7U] = (VTestHarness__ConstPool__CONST_h52851b57_0[7U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[7U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[7U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[7U] 
                                               & __Vtemp_h14c91a2a__0[7U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[7U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[7U] 
                                                 & __Vtemp_h45b86d9b__0[7U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[7U])))));
    __Vtemp_hfe11e144__0[8U] = (VTestHarness__ConstPool__CONST_h52851b57_0[8U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[8U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[8U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[8U] 
                                               & __Vtemp_h14c91a2a__0[8U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[8U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[8U] 
                                                 & __Vtemp_h45b86d9b__0[8U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[8U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[0U] 
        = (VTestHarness__ConstPool__CONST_h52851b57_0[0U] 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
               ? VTestHarness__ConstPool__CONST_h478702bb_0[0U]
               : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[0U] 
                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                       ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[0U] 
                          & __Vtemp_h14c91a2a__0[0U])
                       : VTestHarness__ConstPool__CONST_h478702bb_0[0U])) 
                  & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                         ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[0U] 
                            & __Vtemp_h45b86d9b__0[0U])
                         : VTestHarness__ConstPool__CONST_h478702bb_0[0U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[1U] 
        = __Vtemp_hfe11e144__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[2U] 
        = __Vtemp_hfe11e144__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[3U] 
        = __Vtemp_hfe11e144__0[3U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[4U] 
        = __Vtemp_hfe11e144__0[4U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[5U] 
        = __Vtemp_hfe11e144__0[5U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[6U] 
        = __Vtemp_hfe11e144__0[6U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[7U] 
        = __Vtemp_hfe11e144__0[7U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[8U] 
        = __Vtemp_hfe11e144__0[8U];
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__15237(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__15237\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_h751e110f__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__0;
    VlWide<4>/*127:0*/ __Vtemp_h1777d4f3__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__1;
    VlWide<4>/*127:0*/ __Vtemp_hf82b2a2b__0;
    VlWide<9>/*287:0*/ __Vtemp_ha3586b49__0;
    VlWide<33>/*1055:0*/ __Vtemp_h7cbb1c4b__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9dd30ecc__0;
    VlWide<33>/*1055:0*/ __Vtemp_h65421e99__0;
    VlWide<33>/*1055:0*/ __Vtemp_ha189cae3__0;
    VlWide<33>/*1055:0*/ __Vtemp_h79ba5bbc__0;
    VlWide<33>/*1055:0*/ __Vtemp_h328a2130__0;
    VlWide<33>/*1055:0*/ __Vtemp_h45b86d9b__0;
    VlWide<9>/*287:0*/ __Vtemp_hdf5b6358__0;
    VlWide<33>/*1055:0*/ __Vtemp_hcd01fd03__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9dd30ecc__1;
    VlWide<33>/*1055:0*/ __Vtemp_hdccc2f4a__0;
    VlWide<33>/*1055:0*/ __Vtemp_h2f083b18__0;
    VlWide<33>/*1055:0*/ __Vtemp_hdd06ca4e__0;
    VlWide<33>/*1055:0*/ __Vtemp_h970de5ad__0;
    VlWide<33>/*1055:0*/ __Vtemp_h24702107__0;
    // Body
    __Vtemp_hc961d23f__0[0U] = 1U;
    __Vtemp_hc961d23f__0[1U] = 0U;
    __Vtemp_hc961d23f__0[2U] = 0U;
    __Vtemp_hc961d23f__0[3U] = 0U;
    VL_SHIFTL_WWI(128,128,7, __Vtemp_h1777d4f3__0, __Vtemp_hc961d23f__0, 
                  (0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                            >> 0xaU)));
    __Vtemp_hc961d23f__1[0U] = 1U;
    __Vtemp_hc961d23f__1[1U] = 0U;
    __Vtemp_hc961d23f__1[2U] = 0U;
    __Vtemp_hc961d23f__1[3U] = 0U;
    VL_SHIFTL_WWI(128,128,7, __Vtemp_hf82b2a2b__0, __Vtemp_hc961d23f__1, 
                  (0x7fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_clint_fragmenter_out_a_bits_source) 
                            >> 4U)));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset) {
        __Vtemp_h751e110f__0[1U] = 0U;
        __Vtemp_h751e110f__0[2U] = 0U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight[0U] = 0U;
    } else {
        __Vtemp_h751e110f__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight[1U] 
                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                         ? __Vtemp_h1777d4f3__0[1U]
                                         : 0U)) & (~ 
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                                     ? 
                                                    __Vtemp_hf82b2a2b__0[1U]
                                                     : 0U)));
        __Vtemp_h751e110f__0[2U] = (1U & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight[2U] 
                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                               ? __Vtemp_h1777d4f3__0[2U]
                                               : 0U)) 
                                          & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                                 ? 
                                                __Vtemp_hf82b2a2b__0[2U]
                                                 : 0U))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight[0U] 
            = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight[0U] 
                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                    ? __Vtemp_h1777d4f3__0[0U] : 0U)) 
               & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                      ? __Vtemp_hf82b2a2b__0[0U] : 0U)));
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight[1U] 
        = __Vtemp_h751e110f__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight[2U] 
        = __Vtemp_h751e110f__0[2U];
    VL_EXTEND_WI(1027,4, __Vtemp_h7cbb1c4b__0, ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                                 ? 
                                                (1U 
                                                 | (0xeU 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       >> 5U)))
                                                 : 0U));
    VL_EXTEND_WI(1025,7, __Vtemp_h9dd30ecc__0, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)));
    __Vtemp_h65421e99__0[0U] = (__Vtemp_h9dd30ecc__0[0U] 
                                << 2U);
    __Vtemp_h65421e99__0[1U] = ((__Vtemp_h9dd30ecc__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[1U] 
                                              << 2U));
    __Vtemp_h65421e99__0[2U] = ((__Vtemp_h9dd30ecc__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[2U] 
                                              << 2U));
    __Vtemp_h65421e99__0[3U] = ((__Vtemp_h9dd30ecc__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[3U] 
                                              << 2U));
    __Vtemp_h65421e99__0[4U] = ((__Vtemp_h9dd30ecc__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[4U] 
                                              << 2U));
    __Vtemp_h65421e99__0[5U] = ((__Vtemp_h9dd30ecc__0[4U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[5U] 
                                              << 2U));
    __Vtemp_h65421e99__0[6U] = ((__Vtemp_h9dd30ecc__0[5U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[6U] 
                                              << 2U));
    __Vtemp_h65421e99__0[7U] = ((__Vtemp_h9dd30ecc__0[6U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[7U] 
                                              << 2U));
    __Vtemp_h65421e99__0[8U] = ((__Vtemp_h9dd30ecc__0[7U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[8U] 
                                              << 2U));
    __Vtemp_h65421e99__0[9U] = ((__Vtemp_h9dd30ecc__0[8U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[9U] 
                                              << 2U));
    __Vtemp_h65421e99__0[0xaU] = ((__Vtemp_h9dd30ecc__0[9U] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xaU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xbU] = ((__Vtemp_h9dd30ecc__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xbU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xcU] = ((__Vtemp_h9dd30ecc__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xcU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xdU] = ((__Vtemp_h9dd30ecc__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xdU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xeU] = ((__Vtemp_h9dd30ecc__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xeU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xfU] = ((__Vtemp_h9dd30ecc__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xfU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0x10U] = ((__Vtemp_h9dd30ecc__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x10U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x11U] = ((__Vtemp_h9dd30ecc__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x11U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x12U] = ((__Vtemp_h9dd30ecc__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x12U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x13U] = ((__Vtemp_h9dd30ecc__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x13U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x14U] = ((__Vtemp_h9dd30ecc__0[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x14U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x15U] = ((__Vtemp_h9dd30ecc__0[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x15U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x16U] = ((__Vtemp_h9dd30ecc__0[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x16U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x17U] = ((__Vtemp_h9dd30ecc__0[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x17U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x18U] = ((__Vtemp_h9dd30ecc__0[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x18U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x19U] = ((__Vtemp_h9dd30ecc__0[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x19U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1aU] = ((__Vtemp_h9dd30ecc__0[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1aU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1bU] = ((__Vtemp_h9dd30ecc__0[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1bU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1cU] = ((__Vtemp_h9dd30ecc__0[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1cU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1dU] = ((__Vtemp_h9dd30ecc__0[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1dU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1eU] = ((__Vtemp_h9dd30ecc__0[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1eU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1fU] = ((__Vtemp_h9dd30ecc__0[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1fU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x20U] = ((__Vtemp_h9dd30ecc__0[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1027,1027,1027, __Vtemp_ha189cae3__0, __Vtemp_h7cbb1c4b__0, __Vtemp_h65421e99__0);
    VL_EXTEND_WI(1037,7, __Vtemp_h79ba5bbc__0, (0x7fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_clint_fragmenter_out_a_bits_source) 
                                                   >> 4U)));
    __Vtemp_h328a2130__0[0U] = (__Vtemp_h79ba5bbc__0[0U] 
                                << 2U);
    __Vtemp_h328a2130__0[1U] = ((__Vtemp_h79ba5bbc__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h79ba5bbc__0[1U] 
                                              << 2U));
    __Vtemp_h328a2130__0[2U] = ((__Vtemp_h79ba5bbc__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h79ba5bbc__0[2U] 
                                              << 2U));
    __Vtemp_h328a2130__0[3U] = ((__Vtemp_h79ba5bbc__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h79ba5bbc__0[3U] 
                                              << 2U));
    __Vtemp_h328a2130__0[4U] = ((__Vtemp_h79ba5bbc__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h79ba5bbc__0[4U] 
                                              << 2U));
    __Vtemp_h328a2130__0[5U] = ((__Vtemp_h79ba5bbc__0[4U] 
                                 >> 0x1eU) | (__Vtemp_h79ba5bbc__0[5U] 
                                              << 2U));
    __Vtemp_h328a2130__0[6U] = ((__Vtemp_h79ba5bbc__0[5U] 
                                 >> 0x1eU) | (__Vtemp_h79ba5bbc__0[6U] 
                                              << 2U));
    __Vtemp_h328a2130__0[7U] = ((__Vtemp_h79ba5bbc__0[6U] 
                                 >> 0x1eU) | (__Vtemp_h79ba5bbc__0[7U] 
                                              << 2U));
    __Vtemp_h328a2130__0[8U] = ((__Vtemp_h79ba5bbc__0[7U] 
                                 >> 0x1eU) | (__Vtemp_h79ba5bbc__0[8U] 
                                              << 2U));
    __Vtemp_h328a2130__0[9U] = ((__Vtemp_h79ba5bbc__0[8U] 
                                 >> 0x1eU) | (__Vtemp_h79ba5bbc__0[9U] 
                                              << 2U));
    __Vtemp_h328a2130__0[0xaU] = ((__Vtemp_h79ba5bbc__0[9U] 
                                   >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0xaU] 
                                                << 2U));
    __Vtemp_h328a2130__0[0xbU] = ((__Vtemp_h79ba5bbc__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0xbU] 
                                                << 2U));
    __Vtemp_h328a2130__0[0xcU] = ((__Vtemp_h79ba5bbc__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0xcU] 
                                                << 2U));
    __Vtemp_h328a2130__0[0xdU] = ((__Vtemp_h79ba5bbc__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0xdU] 
                                                << 2U));
    __Vtemp_h328a2130__0[0xeU] = ((__Vtemp_h79ba5bbc__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0xeU] 
                                                << 2U));
    __Vtemp_h328a2130__0[0xfU] = ((__Vtemp_h79ba5bbc__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0xfU] 
                                                << 2U));
    __Vtemp_h328a2130__0[0x10U] = ((__Vtemp_h79ba5bbc__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x10U] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x11U] = ((__Vtemp_h79ba5bbc__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x11U] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x12U] = ((__Vtemp_h79ba5bbc__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x12U] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x13U] = ((__Vtemp_h79ba5bbc__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x13U] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x14U] = ((__Vtemp_h79ba5bbc__0[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x14U] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x15U] = ((__Vtemp_h79ba5bbc__0[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x15U] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x16U] = ((__Vtemp_h79ba5bbc__0[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x16U] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x17U] = ((__Vtemp_h79ba5bbc__0[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x17U] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x18U] = ((__Vtemp_h79ba5bbc__0[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x18U] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x19U] = ((__Vtemp_h79ba5bbc__0[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x19U] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x1aU] = ((__Vtemp_h79ba5bbc__0[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x1aU] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x1bU] = ((__Vtemp_h79ba5bbc__0[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x1bU] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x1cU] = ((__Vtemp_h79ba5bbc__0[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x1cU] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x1dU] = ((__Vtemp_h79ba5bbc__0[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x1dU] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x1eU] = ((__Vtemp_h79ba5bbc__0[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x1eU] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x1fU] = ((__Vtemp_h79ba5bbc__0[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x1fU] 
                                                 << 2U));
    __Vtemp_h328a2130__0[0x20U] = ((__Vtemp_h79ba5bbc__0[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h79ba5bbc__0[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1039,1039,1039, __Vtemp_h45b86d9b__0, VTestHarness__ConstPool__CONST_h3892cc72_0, __Vtemp_h328a2130__0);
    __Vtemp_ha3586b49__0[1U] = (VTestHarness__ConstPool__CONST_h52851b57_0[1U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[1U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[1U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[1U] 
                                               & __Vtemp_ha189cae3__0[1U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[1U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[1U] 
                                                 & __Vtemp_h45b86d9b__0[1U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[1U])))));
    __Vtemp_ha3586b49__0[2U] = (VTestHarness__ConstPool__CONST_h52851b57_0[2U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[2U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[2U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[2U] 
                                               & __Vtemp_ha189cae3__0[2U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[2U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[2U] 
                                                 & __Vtemp_h45b86d9b__0[2U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[2U])))));
    __Vtemp_ha3586b49__0[3U] = (VTestHarness__ConstPool__CONST_h52851b57_0[3U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[3U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[3U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[3U] 
                                               & __Vtemp_ha189cae3__0[3U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[3U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[3U] 
                                                 & __Vtemp_h45b86d9b__0[3U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[3U])))));
    __Vtemp_ha3586b49__0[4U] = (VTestHarness__ConstPool__CONST_h52851b57_0[4U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[4U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[4U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[4U] 
                                               & __Vtemp_ha189cae3__0[4U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[4U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[4U] 
                                                 & __Vtemp_h45b86d9b__0[4U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[4U])))));
    __Vtemp_ha3586b49__0[5U] = (VTestHarness__ConstPool__CONST_h52851b57_0[5U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[5U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[5U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[5U] 
                                               & __Vtemp_ha189cae3__0[5U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[5U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[5U] 
                                                 & __Vtemp_h45b86d9b__0[5U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[5U])))));
    __Vtemp_ha3586b49__0[6U] = (VTestHarness__ConstPool__CONST_h52851b57_0[6U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[6U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[6U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[6U] 
                                               & __Vtemp_ha189cae3__0[6U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[6U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[6U] 
                                                 & __Vtemp_h45b86d9b__0[6U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[6U])))));
    __Vtemp_ha3586b49__0[7U] = (VTestHarness__ConstPool__CONST_h52851b57_0[7U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[7U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[7U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[7U] 
                                               & __Vtemp_ha189cae3__0[7U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[7U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[7U] 
                                                 & __Vtemp_h45b86d9b__0[7U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[7U])))));
    __Vtemp_ha3586b49__0[8U] = (VTestHarness__ConstPool__CONST_h52851b57_0[8U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[8U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[8U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[8U] 
                                               & __Vtemp_ha189cae3__0[8U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[8U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[8U] 
                                                 & __Vtemp_h45b86d9b__0[8U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[8U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[0U] 
        = (VTestHarness__ConstPool__CONST_h52851b57_0[0U] 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
               ? VTestHarness__ConstPool__CONST_h478702bb_0[0U]
               : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[0U] 
                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                       ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[0U] 
                          & __Vtemp_ha189cae3__0[0U])
                       : VTestHarness__ConstPool__CONST_h478702bb_0[0U])) 
                  & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                         ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[0U] 
                            & __Vtemp_h45b86d9b__0[0U])
                         : VTestHarness__ConstPool__CONST_h478702bb_0[0U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[1U] 
        = __Vtemp_ha3586b49__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[2U] 
        = __Vtemp_ha3586b49__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[3U] 
        = __Vtemp_ha3586b49__0[3U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[4U] 
        = __Vtemp_ha3586b49__0[4U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[5U] 
        = __Vtemp_ha3586b49__0[5U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[6U] 
        = __Vtemp_ha3586b49__0[6U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[7U] 
        = __Vtemp_ha3586b49__0[7U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_clint__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[8U] 
        = __Vtemp_ha3586b49__0[8U];
    VL_EXTEND_WI(1027,4, __Vtemp_hcd01fd03__0, ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                                 ? 
                                                (1U 
                                                 | (0xeU 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       << 1U)))
                                                 : 0U));
    VL_EXTEND_WI(1025,7, __Vtemp_h9dd30ecc__1, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)));
    __Vtemp_hdccc2f4a__0[0U] = (__Vtemp_h9dd30ecc__1[0U] 
                                << 2U);
    __Vtemp_hdccc2f4a__0[1U] = ((__Vtemp_h9dd30ecc__1[0U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[1U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[2U] = ((__Vtemp_h9dd30ecc__1[1U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[2U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[3U] = ((__Vtemp_h9dd30ecc__1[2U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[3U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[4U] = ((__Vtemp_h9dd30ecc__1[3U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[4U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[5U] = ((__Vtemp_h9dd30ecc__1[4U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[5U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[6U] = ((__Vtemp_h9dd30ecc__1[5U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[6U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[7U] = ((__Vtemp_h9dd30ecc__1[6U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[7U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[8U] = ((__Vtemp_h9dd30ecc__1[7U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[8U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[9U] = ((__Vtemp_h9dd30ecc__1[8U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[9U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[0xaU] = ((__Vtemp_h9dd30ecc__1[9U] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xaU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0xbU] = ((__Vtemp_h9dd30ecc__1[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xbU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0xcU] = ((__Vtemp_h9dd30ecc__1[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xcU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0xdU] = ((__Vtemp_h9dd30ecc__1[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xdU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0xeU] = ((__Vtemp_h9dd30ecc__1[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xeU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0xfU] = ((__Vtemp_h9dd30ecc__1[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xfU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0x10U] = ((__Vtemp_h9dd30ecc__1[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x10U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x11U] = ((__Vtemp_h9dd30ecc__1[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x11U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x12U] = ((__Vtemp_h9dd30ecc__1[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x12U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x13U] = ((__Vtemp_h9dd30ecc__1[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x13U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x14U] = ((__Vtemp_h9dd30ecc__1[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x14U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x15U] = ((__Vtemp_h9dd30ecc__1[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x15U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x16U] = ((__Vtemp_h9dd30ecc__1[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x16U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x17U] = ((__Vtemp_h9dd30ecc__1[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x17U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x18U] = ((__Vtemp_h9dd30ecc__1[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x18U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x19U] = ((__Vtemp_h9dd30ecc__1[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x19U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1aU] = ((__Vtemp_h9dd30ecc__1[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1aU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1bU] = ((__Vtemp_h9dd30ecc__1[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1bU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1cU] = ((__Vtemp_h9dd30ecc__1[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1cU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1dU] = ((__Vtemp_h9dd30ecc__1[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1dU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1eU] = ((__Vtemp_h9dd30ecc__1[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1eU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1fU] = ((__Vtemp_h9dd30ecc__1[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1fU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x20U] = ((__Vtemp_h9dd30ecc__1[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1027,1027,1027, __Vtemp_h2f083b18__0, __Vtemp_hcd01fd03__0, __Vtemp_hdccc2f4a__0);
    VL_EXTEND_WI(1037,7, __Vtemp_hdd06ca4e__0, (0x7fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_debug_fragmenter_out_a_bits_source) 
                                                   >> 4U)));
    __Vtemp_h970de5ad__0[0U] = (__Vtemp_hdd06ca4e__0[0U] 
                                << 2U);
    __Vtemp_h970de5ad__0[1U] = ((__Vtemp_hdd06ca4e__0[0U] 
                                 >> 0x1eU) | (__Vtemp_hdd06ca4e__0[1U] 
                                              << 2U));
    __Vtemp_h970de5ad__0[2U] = ((__Vtemp_hdd06ca4e__0[1U] 
                                 >> 0x1eU) | (__Vtemp_hdd06ca4e__0[2U] 
                                              << 2U));
    __Vtemp_h970de5ad__0[3U] = ((__Vtemp_hdd06ca4e__0[2U] 
                                 >> 0x1eU) | (__Vtemp_hdd06ca4e__0[3U] 
                                              << 2U));
    __Vtemp_h970de5ad__0[4U] = ((__Vtemp_hdd06ca4e__0[3U] 
                                 >> 0x1eU) | (__Vtemp_hdd06ca4e__0[4U] 
                                              << 2U));
    __Vtemp_h970de5ad__0[5U] = ((__Vtemp_hdd06ca4e__0[4U] 
                                 >> 0x1eU) | (__Vtemp_hdd06ca4e__0[5U] 
                                              << 2U));
    __Vtemp_h970de5ad__0[6U] = ((__Vtemp_hdd06ca4e__0[5U] 
                                 >> 0x1eU) | (__Vtemp_hdd06ca4e__0[6U] 
                                              << 2U));
    __Vtemp_h970de5ad__0[7U] = ((__Vtemp_hdd06ca4e__0[6U] 
                                 >> 0x1eU) | (__Vtemp_hdd06ca4e__0[7U] 
                                              << 2U));
    __Vtemp_h970de5ad__0[8U] = ((__Vtemp_hdd06ca4e__0[7U] 
                                 >> 0x1eU) | (__Vtemp_hdd06ca4e__0[8U] 
                                              << 2U));
    __Vtemp_h970de5ad__0[9U] = ((__Vtemp_hdd06ca4e__0[8U] 
                                 >> 0x1eU) | (__Vtemp_hdd06ca4e__0[9U] 
                                              << 2U));
    __Vtemp_h970de5ad__0[0xaU] = ((__Vtemp_hdd06ca4e__0[9U] 
                                   >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0xaU] 
                                                << 2U));
    __Vtemp_h970de5ad__0[0xbU] = ((__Vtemp_hdd06ca4e__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0xbU] 
                                                << 2U));
    __Vtemp_h970de5ad__0[0xcU] = ((__Vtemp_hdd06ca4e__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0xcU] 
                                                << 2U));
    __Vtemp_h970de5ad__0[0xdU] = ((__Vtemp_hdd06ca4e__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0xdU] 
                                                << 2U));
    __Vtemp_h970de5ad__0[0xeU] = ((__Vtemp_hdd06ca4e__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0xeU] 
                                                << 2U));
    __Vtemp_h970de5ad__0[0xfU] = ((__Vtemp_hdd06ca4e__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0xfU] 
                                                << 2U));
    __Vtemp_h970de5ad__0[0x10U] = ((__Vtemp_hdd06ca4e__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x10U] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x11U] = ((__Vtemp_hdd06ca4e__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x11U] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x12U] = ((__Vtemp_hdd06ca4e__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x12U] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x13U] = ((__Vtemp_hdd06ca4e__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x13U] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x14U] = ((__Vtemp_hdd06ca4e__0[0x13U] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x14U] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x15U] = ((__Vtemp_hdd06ca4e__0[0x14U] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x15U] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x16U] = ((__Vtemp_hdd06ca4e__0[0x15U] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x16U] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x17U] = ((__Vtemp_hdd06ca4e__0[0x16U] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x17U] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x18U] = ((__Vtemp_hdd06ca4e__0[0x17U] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x18U] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x19U] = ((__Vtemp_hdd06ca4e__0[0x18U] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x19U] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x1aU] = ((__Vtemp_hdd06ca4e__0[0x19U] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x1aU] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x1bU] = ((__Vtemp_hdd06ca4e__0[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x1bU] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x1cU] = ((__Vtemp_hdd06ca4e__0[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x1cU] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x1dU] = ((__Vtemp_hdd06ca4e__0[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x1dU] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x1eU] = ((__Vtemp_hdd06ca4e__0[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x1eU] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x1fU] = ((__Vtemp_hdd06ca4e__0[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x1fU] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x20U] = ((__Vtemp_hdd06ca4e__0[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1039,1039,1039, __Vtemp_h24702107__0, VTestHarness__ConstPool__CONST_h3892cc72_0, __Vtemp_h970de5ad__0);
    __Vtemp_hdf5b6358__0[1U] = (VTestHarness__ConstPool__CONST_h52851b57_0[1U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[1U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[1U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[1U] 
                                               & __Vtemp_h2f083b18__0[1U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[1U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[1U] 
                                                 & __Vtemp_h24702107__0[1U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[1U])))));
    __Vtemp_hdf5b6358__0[2U] = (VTestHarness__ConstPool__CONST_h52851b57_0[2U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[2U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[2U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[2U] 
                                               & __Vtemp_h2f083b18__0[2U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[2U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[2U] 
                                                 & __Vtemp_h24702107__0[2U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[2U])))));
    __Vtemp_hdf5b6358__0[3U] = (VTestHarness__ConstPool__CONST_h52851b57_0[3U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[3U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[3U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[3U] 
                                               & __Vtemp_h2f083b18__0[3U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[3U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[3U] 
                                                 & __Vtemp_h24702107__0[3U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[3U])))));
    __Vtemp_hdf5b6358__0[4U] = (VTestHarness__ConstPool__CONST_h52851b57_0[4U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[4U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[4U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[4U] 
                                               & __Vtemp_h2f083b18__0[4U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[4U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[4U] 
                                                 & __Vtemp_h24702107__0[4U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[4U])))));
    __Vtemp_hdf5b6358__0[5U] = (VTestHarness__ConstPool__CONST_h52851b57_0[5U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[5U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[5U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[5U] 
                                               & __Vtemp_h2f083b18__0[5U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[5U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[5U] 
                                                 & __Vtemp_h24702107__0[5U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[5U])))));
    __Vtemp_hdf5b6358__0[6U] = (VTestHarness__ConstPool__CONST_h52851b57_0[6U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[6U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[6U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[6U] 
                                               & __Vtemp_h2f083b18__0[6U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[6U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[6U] 
                                                 & __Vtemp_h24702107__0[6U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[6U])))));
    __Vtemp_hdf5b6358__0[7U] = (VTestHarness__ConstPool__CONST_h52851b57_0[7U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[7U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[7U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[7U] 
                                               & __Vtemp_h2f083b18__0[7U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[7U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[7U] 
                                                 & __Vtemp_h24702107__0[7U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[7U])))));
    __Vtemp_hdf5b6358__0[8U] = (VTestHarness__ConstPool__CONST_h52851b57_0[8U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[8U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[8U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[8U] 
                                               & __Vtemp_h2f083b18__0[8U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[8U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[8U] 
                                                 & __Vtemp_h24702107__0[8U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[8U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[0U] 
        = (VTestHarness__ConstPool__CONST_h52851b57_0[0U] 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
               ? VTestHarness__ConstPool__CONST_h478702bb_0[0U]
               : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[0U] 
                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                       ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[0U] 
                          & __Vtemp_h2f083b18__0[0U])
                       : VTestHarness__ConstPool__CONST_h478702bb_0[0U])) 
                  & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                         ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[0U] 
                            & __Vtemp_h24702107__0[0U])
                         : VTestHarness__ConstPool__CONST_h478702bb_0[0U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[1U] 
        = __Vtemp_hdf5b6358__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[2U] 
        = __Vtemp_hdf5b6358__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[3U] 
        = __Vtemp_hdf5b6358__0[3U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[4U] 
        = __Vtemp_hdf5b6358__0[4U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[5U] 
        = __Vtemp_hdf5b6358__0[5U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[6U] 
        = __Vtemp_hdf5b6358__0[6U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[7U] 
        = __Vtemp_hdf5b6358__0[7U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[8U] 
        = __Vtemp_hdf5b6358__0[8U];
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__15238(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__15238\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_h73c80c38__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__0;
    VlWide<4>/*127:0*/ __Vtemp_h1777d4f3__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__1;
    VlWide<4>/*127:0*/ __Vtemp_h54dc593d__0;
    VlWide<9>/*287:0*/ __Vtemp_hb6e1b229__0;
    VlWide<33>/*1055:0*/ __Vtemp_h60fb527d__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9dd30ecc__0;
    VlWide<33>/*1055:0*/ __Vtemp_h65421e99__0;
    VlWide<33>/*1055:0*/ __Vtemp_hf7efd48a__0;
    VlWide<33>/*1055:0*/ __Vtemp_hdd06ca4e__0;
    VlWide<33>/*1055:0*/ __Vtemp_h970de5ad__0;
    VlWide<33>/*1055:0*/ __Vtemp_h24702107__0;
    VlWide<9>/*287:0*/ __Vtemp_h902ec0a1__0;
    VlWide<33>/*1055:0*/ __Vtemp_hd569ef9b__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9dd30ecc__1;
    VlWide<33>/*1055:0*/ __Vtemp_hdccc2f4a__0;
    VlWide<33>/*1055:0*/ __Vtemp_hbae320a8__0;
    VlWide<33>/*1055:0*/ __Vtemp_he9db3d2f__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9a67dfe8__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9f382ccd__0;
    // Body
    __Vtemp_hc961d23f__0[0U] = 1U;
    __Vtemp_hc961d23f__0[1U] = 0U;
    __Vtemp_hc961d23f__0[2U] = 0U;
    __Vtemp_hc961d23f__0[3U] = 0U;
    VL_SHIFTL_WWI(128,128,7, __Vtemp_h1777d4f3__0, __Vtemp_hc961d23f__0, 
                  (0x7fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                            >> 0xaU)));
    __Vtemp_hc961d23f__1[0U] = 1U;
    __Vtemp_hc961d23f__1[1U] = 0U;
    __Vtemp_hc961d23f__1[2U] = 0U;
    __Vtemp_hc961d23f__1[3U] = 0U;
    VL_SHIFTL_WWI(128,128,7, __Vtemp_h54dc593d__0, __Vtemp_hc961d23f__1, 
                  (0x7fU & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_debug_fragmenter_out_a_bits_source) 
                            >> 4U)));
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset) {
        __Vtemp_h73c80c38__0[1U] = 0U;
        __Vtemp_h73c80c38__0[2U] = 0U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight[0U] = 0U;
    } else {
        __Vtemp_h73c80c38__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight[1U] 
                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                         ? __Vtemp_h1777d4f3__0[1U]
                                         : 0U)) & (~ 
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                                     ? 
                                                    __Vtemp_h54dc593d__0[1U]
                                                     : 0U)));
        __Vtemp_h73c80c38__0[2U] = (1U & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight[2U] 
                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                               ? __Vtemp_h1777d4f3__0[2U]
                                               : 0U)) 
                                          & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                                 ? 
                                                __Vtemp_h54dc593d__0[2U]
                                                 : 0U))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight[0U] 
            = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight[0U] 
                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                    ? __Vtemp_h1777d4f3__0[0U] : 0U)) 
               & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                      ? __Vtemp_h54dc593d__0[0U] : 0U)));
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight[1U] 
        = __Vtemp_h73c80c38__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight[2U] 
        = __Vtemp_h73c80c38__0[2U];
    VL_EXTEND_WI(1027,4, __Vtemp_h60fb527d__0, ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                                 ? 
                                                (1U 
                                                 | (0xeU 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       >> 5U)))
                                                 : 0U));
    VL_EXTEND_WI(1025,7, __Vtemp_h9dd30ecc__0, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)));
    __Vtemp_h65421e99__0[0U] = (__Vtemp_h9dd30ecc__0[0U] 
                                << 2U);
    __Vtemp_h65421e99__0[1U] = ((__Vtemp_h9dd30ecc__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[1U] 
                                              << 2U));
    __Vtemp_h65421e99__0[2U] = ((__Vtemp_h9dd30ecc__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[2U] 
                                              << 2U));
    __Vtemp_h65421e99__0[3U] = ((__Vtemp_h9dd30ecc__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[3U] 
                                              << 2U));
    __Vtemp_h65421e99__0[4U] = ((__Vtemp_h9dd30ecc__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[4U] 
                                              << 2U));
    __Vtemp_h65421e99__0[5U] = ((__Vtemp_h9dd30ecc__0[4U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[5U] 
                                              << 2U));
    __Vtemp_h65421e99__0[6U] = ((__Vtemp_h9dd30ecc__0[5U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[6U] 
                                              << 2U));
    __Vtemp_h65421e99__0[7U] = ((__Vtemp_h9dd30ecc__0[6U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[7U] 
                                              << 2U));
    __Vtemp_h65421e99__0[8U] = ((__Vtemp_h9dd30ecc__0[7U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[8U] 
                                              << 2U));
    __Vtemp_h65421e99__0[9U] = ((__Vtemp_h9dd30ecc__0[8U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[9U] 
                                              << 2U));
    __Vtemp_h65421e99__0[0xaU] = ((__Vtemp_h9dd30ecc__0[9U] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xaU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xbU] = ((__Vtemp_h9dd30ecc__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xbU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xcU] = ((__Vtemp_h9dd30ecc__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xcU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xdU] = ((__Vtemp_h9dd30ecc__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xdU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xeU] = ((__Vtemp_h9dd30ecc__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xeU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xfU] = ((__Vtemp_h9dd30ecc__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xfU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0x10U] = ((__Vtemp_h9dd30ecc__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x10U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x11U] = ((__Vtemp_h9dd30ecc__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x11U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x12U] = ((__Vtemp_h9dd30ecc__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x12U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x13U] = ((__Vtemp_h9dd30ecc__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x13U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x14U] = ((__Vtemp_h9dd30ecc__0[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x14U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x15U] = ((__Vtemp_h9dd30ecc__0[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x15U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x16U] = ((__Vtemp_h9dd30ecc__0[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x16U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x17U] = ((__Vtemp_h9dd30ecc__0[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x17U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x18U] = ((__Vtemp_h9dd30ecc__0[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x18U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x19U] = ((__Vtemp_h9dd30ecc__0[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x19U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1aU] = ((__Vtemp_h9dd30ecc__0[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1aU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1bU] = ((__Vtemp_h9dd30ecc__0[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1bU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1cU] = ((__Vtemp_h9dd30ecc__0[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1cU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1dU] = ((__Vtemp_h9dd30ecc__0[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1dU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1eU] = ((__Vtemp_h9dd30ecc__0[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1eU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1fU] = ((__Vtemp_h9dd30ecc__0[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1fU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x20U] = ((__Vtemp_h9dd30ecc__0[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1027,1027,1027, __Vtemp_hf7efd48a__0, __Vtemp_h60fb527d__0, __Vtemp_h65421e99__0);
    VL_EXTEND_WI(1037,7, __Vtemp_hdd06ca4e__0, (0x7fU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_cbus_auto_coupler_to_debug_fragmenter_out_a_bits_source) 
                                                   >> 4U)));
    __Vtemp_h970de5ad__0[0U] = (__Vtemp_hdd06ca4e__0[0U] 
                                << 2U);
    __Vtemp_h970de5ad__0[1U] = ((__Vtemp_hdd06ca4e__0[0U] 
                                 >> 0x1eU) | (__Vtemp_hdd06ca4e__0[1U] 
                                              << 2U));
    __Vtemp_h970de5ad__0[2U] = ((__Vtemp_hdd06ca4e__0[1U] 
                                 >> 0x1eU) | (__Vtemp_hdd06ca4e__0[2U] 
                                              << 2U));
    __Vtemp_h970de5ad__0[3U] = ((__Vtemp_hdd06ca4e__0[2U] 
                                 >> 0x1eU) | (__Vtemp_hdd06ca4e__0[3U] 
                                              << 2U));
    __Vtemp_h970de5ad__0[4U] = ((__Vtemp_hdd06ca4e__0[3U] 
                                 >> 0x1eU) | (__Vtemp_hdd06ca4e__0[4U] 
                                              << 2U));
    __Vtemp_h970de5ad__0[5U] = ((__Vtemp_hdd06ca4e__0[4U] 
                                 >> 0x1eU) | (__Vtemp_hdd06ca4e__0[5U] 
                                              << 2U));
    __Vtemp_h970de5ad__0[6U] = ((__Vtemp_hdd06ca4e__0[5U] 
                                 >> 0x1eU) | (__Vtemp_hdd06ca4e__0[6U] 
                                              << 2U));
    __Vtemp_h970de5ad__0[7U] = ((__Vtemp_hdd06ca4e__0[6U] 
                                 >> 0x1eU) | (__Vtemp_hdd06ca4e__0[7U] 
                                              << 2U));
    __Vtemp_h970de5ad__0[8U] = ((__Vtemp_hdd06ca4e__0[7U] 
                                 >> 0x1eU) | (__Vtemp_hdd06ca4e__0[8U] 
                                              << 2U));
    __Vtemp_h970de5ad__0[9U] = ((__Vtemp_hdd06ca4e__0[8U] 
                                 >> 0x1eU) | (__Vtemp_hdd06ca4e__0[9U] 
                                              << 2U));
    __Vtemp_h970de5ad__0[0xaU] = ((__Vtemp_hdd06ca4e__0[9U] 
                                   >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0xaU] 
                                                << 2U));
    __Vtemp_h970de5ad__0[0xbU] = ((__Vtemp_hdd06ca4e__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0xbU] 
                                                << 2U));
    __Vtemp_h970de5ad__0[0xcU] = ((__Vtemp_hdd06ca4e__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0xcU] 
                                                << 2U));
    __Vtemp_h970de5ad__0[0xdU] = ((__Vtemp_hdd06ca4e__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0xdU] 
                                                << 2U));
    __Vtemp_h970de5ad__0[0xeU] = ((__Vtemp_hdd06ca4e__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0xeU] 
                                                << 2U));
    __Vtemp_h970de5ad__0[0xfU] = ((__Vtemp_hdd06ca4e__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0xfU] 
                                                << 2U));
    __Vtemp_h970de5ad__0[0x10U] = ((__Vtemp_hdd06ca4e__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x10U] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x11U] = ((__Vtemp_hdd06ca4e__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x11U] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x12U] = ((__Vtemp_hdd06ca4e__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x12U] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x13U] = ((__Vtemp_hdd06ca4e__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x13U] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x14U] = ((__Vtemp_hdd06ca4e__0[0x13U] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x14U] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x15U] = ((__Vtemp_hdd06ca4e__0[0x14U] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x15U] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x16U] = ((__Vtemp_hdd06ca4e__0[0x15U] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x16U] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x17U] = ((__Vtemp_hdd06ca4e__0[0x16U] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x17U] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x18U] = ((__Vtemp_hdd06ca4e__0[0x17U] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x18U] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x19U] = ((__Vtemp_hdd06ca4e__0[0x18U] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x19U] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x1aU] = ((__Vtemp_hdd06ca4e__0[0x19U] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x1aU] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x1bU] = ((__Vtemp_hdd06ca4e__0[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x1bU] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x1cU] = ((__Vtemp_hdd06ca4e__0[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x1cU] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x1dU] = ((__Vtemp_hdd06ca4e__0[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x1dU] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x1eU] = ((__Vtemp_hdd06ca4e__0[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x1eU] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x1fU] = ((__Vtemp_hdd06ca4e__0[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x1fU] 
                                                 << 2U));
    __Vtemp_h970de5ad__0[0x20U] = ((__Vtemp_hdd06ca4e__0[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_hdd06ca4e__0[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1039,1039,1039, __Vtemp_h24702107__0, VTestHarness__ConstPool__CONST_h3892cc72_0, __Vtemp_h970de5ad__0);
    __Vtemp_hb6e1b229__0[1U] = (VTestHarness__ConstPool__CONST_h52851b57_0[1U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[1U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[1U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[1U] 
                                               & __Vtemp_hf7efd48a__0[1U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[1U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[1U] 
                                                 & __Vtemp_h24702107__0[1U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[1U])))));
    __Vtemp_hb6e1b229__0[2U] = (VTestHarness__ConstPool__CONST_h52851b57_0[2U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[2U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[2U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[2U] 
                                               & __Vtemp_hf7efd48a__0[2U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[2U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[2U] 
                                                 & __Vtemp_h24702107__0[2U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[2U])))));
    __Vtemp_hb6e1b229__0[3U] = (VTestHarness__ConstPool__CONST_h52851b57_0[3U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[3U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[3U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[3U] 
                                               & __Vtemp_hf7efd48a__0[3U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[3U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[3U] 
                                                 & __Vtemp_h24702107__0[3U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[3U])))));
    __Vtemp_hb6e1b229__0[4U] = (VTestHarness__ConstPool__CONST_h52851b57_0[4U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[4U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[4U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[4U] 
                                               & __Vtemp_hf7efd48a__0[4U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[4U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[4U] 
                                                 & __Vtemp_h24702107__0[4U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[4U])))));
    __Vtemp_hb6e1b229__0[5U] = (VTestHarness__ConstPool__CONST_h52851b57_0[5U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[5U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[5U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[5U] 
                                               & __Vtemp_hf7efd48a__0[5U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[5U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[5U] 
                                                 & __Vtemp_h24702107__0[5U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[5U])))));
    __Vtemp_hb6e1b229__0[6U] = (VTestHarness__ConstPool__CONST_h52851b57_0[6U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[6U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[6U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[6U] 
                                               & __Vtemp_hf7efd48a__0[6U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[6U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[6U] 
                                                 & __Vtemp_h24702107__0[6U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[6U])))));
    __Vtemp_hb6e1b229__0[7U] = (VTestHarness__ConstPool__CONST_h52851b57_0[7U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[7U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[7U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[7U] 
                                               & __Vtemp_hf7efd48a__0[7U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[7U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[7U] 
                                                 & __Vtemp_h24702107__0[7U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[7U])))));
    __Vtemp_hb6e1b229__0[8U] = (VTestHarness__ConstPool__CONST_h52851b57_0[8U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[8U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[8U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[8U] 
                                               & __Vtemp_hf7efd48a__0[8U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[8U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[8U] 
                                                 & __Vtemp_h24702107__0[8U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[8U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[0U] 
        = (VTestHarness__ConstPool__CONST_h52851b57_0[0U] 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
               ? VTestHarness__ConstPool__CONST_h478702bb_0[0U]
               : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[0U] 
                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                       ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[0U] 
                          & __Vtemp_hf7efd48a__0[0U])
                       : VTestHarness__ConstPool__CONST_h478702bb_0[0U])) 
                  & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                         ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[0U] 
                            & __Vtemp_h24702107__0[0U])
                         : VTestHarness__ConstPool__CONST_h478702bb_0[0U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[1U] 
        = __Vtemp_hb6e1b229__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[2U] 
        = __Vtemp_hb6e1b229__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[3U] 
        = __Vtemp_hb6e1b229__0[3U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[4U] 
        = __Vtemp_hb6e1b229__0[4U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[5U] 
        = __Vtemp_hb6e1b229__0[5U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[6U] 
        = __Vtemp_hb6e1b229__0[6U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[7U] 
        = __Vtemp_hb6e1b229__0[7U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_debug__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[8U] 
        = __Vtemp_hb6e1b229__0[8U];
    VL_EXTEND_WI(1027,4, __Vtemp_hd569ef9b__0, ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                                 ? 
                                                (1U 
                                                 | (0xeU 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       >> 5U)))
                                                 : 0U));
    VL_EXTEND_WI(1025,7, __Vtemp_h9dd30ecc__1, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)));
    __Vtemp_hdccc2f4a__0[0U] = (__Vtemp_h9dd30ecc__1[0U] 
                                << 2U);
    __Vtemp_hdccc2f4a__0[1U] = ((__Vtemp_h9dd30ecc__1[0U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[1U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[2U] = ((__Vtemp_h9dd30ecc__1[1U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[2U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[3U] = ((__Vtemp_h9dd30ecc__1[2U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[3U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[4U] = ((__Vtemp_h9dd30ecc__1[3U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[4U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[5U] = ((__Vtemp_h9dd30ecc__1[4U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[5U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[6U] = ((__Vtemp_h9dd30ecc__1[5U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[6U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[7U] = ((__Vtemp_h9dd30ecc__1[6U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[7U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[8U] = ((__Vtemp_h9dd30ecc__1[7U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[8U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[9U] = ((__Vtemp_h9dd30ecc__1[8U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[9U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[0xaU] = ((__Vtemp_h9dd30ecc__1[9U] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xaU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0xbU] = ((__Vtemp_h9dd30ecc__1[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xbU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0xcU] = ((__Vtemp_h9dd30ecc__1[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xcU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0xdU] = ((__Vtemp_h9dd30ecc__1[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xdU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0xeU] = ((__Vtemp_h9dd30ecc__1[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xeU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0xfU] = ((__Vtemp_h9dd30ecc__1[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xfU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0x10U] = ((__Vtemp_h9dd30ecc__1[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x10U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x11U] = ((__Vtemp_h9dd30ecc__1[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x11U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x12U] = ((__Vtemp_h9dd30ecc__1[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x12U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x13U] = ((__Vtemp_h9dd30ecc__1[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x13U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x14U] = ((__Vtemp_h9dd30ecc__1[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x14U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x15U] = ((__Vtemp_h9dd30ecc__1[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x15U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x16U] = ((__Vtemp_h9dd30ecc__1[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x16U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x17U] = ((__Vtemp_h9dd30ecc__1[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x17U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x18U] = ((__Vtemp_h9dd30ecc__1[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x18U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x19U] = ((__Vtemp_h9dd30ecc__1[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x19U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1aU] = ((__Vtemp_h9dd30ecc__1[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1aU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1bU] = ((__Vtemp_h9dd30ecc__1[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1bU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1cU] = ((__Vtemp_h9dd30ecc__1[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1cU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1dU] = ((__Vtemp_h9dd30ecc__1[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1dU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1eU] = ((__Vtemp_h9dd30ecc__1[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1eU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1fU] = ((__Vtemp_h9dd30ecc__1[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1fU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x20U] = ((__Vtemp_h9dd30ecc__1[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1027,1027,1027, __Vtemp_hbae320a8__0, __Vtemp_hd569ef9b__0, __Vtemp_hdccc2f4a__0);
    VL_EXTEND_WI(1037,7, __Vtemp_he9db3d2f__0, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xbU)));
    __Vtemp_h9a67dfe8__0[0U] = (__Vtemp_he9db3d2f__0[0U] 
                                << 2U);
    __Vtemp_h9a67dfe8__0[1U] = ((__Vtemp_he9db3d2f__0[0U] 
                                 >> 0x1eU) | (__Vtemp_he9db3d2f__0[1U] 
                                              << 2U));
    __Vtemp_h9a67dfe8__0[2U] = ((__Vtemp_he9db3d2f__0[1U] 
                                 >> 0x1eU) | (__Vtemp_he9db3d2f__0[2U] 
                                              << 2U));
    __Vtemp_h9a67dfe8__0[3U] = ((__Vtemp_he9db3d2f__0[2U] 
                                 >> 0x1eU) | (__Vtemp_he9db3d2f__0[3U] 
                                              << 2U));
    __Vtemp_h9a67dfe8__0[4U] = ((__Vtemp_he9db3d2f__0[3U] 
                                 >> 0x1eU) | (__Vtemp_he9db3d2f__0[4U] 
                                              << 2U));
    __Vtemp_h9a67dfe8__0[5U] = ((__Vtemp_he9db3d2f__0[4U] 
                                 >> 0x1eU) | (__Vtemp_he9db3d2f__0[5U] 
                                              << 2U));
    __Vtemp_h9a67dfe8__0[6U] = ((__Vtemp_he9db3d2f__0[5U] 
                                 >> 0x1eU) | (__Vtemp_he9db3d2f__0[6U] 
                                              << 2U));
    __Vtemp_h9a67dfe8__0[7U] = ((__Vtemp_he9db3d2f__0[6U] 
                                 >> 0x1eU) | (__Vtemp_he9db3d2f__0[7U] 
                                              << 2U));
    __Vtemp_h9a67dfe8__0[8U] = ((__Vtemp_he9db3d2f__0[7U] 
                                 >> 0x1eU) | (__Vtemp_he9db3d2f__0[8U] 
                                              << 2U));
    __Vtemp_h9a67dfe8__0[9U] = ((__Vtemp_he9db3d2f__0[8U] 
                                 >> 0x1eU) | (__Vtemp_he9db3d2f__0[9U] 
                                              << 2U));
    __Vtemp_h9a67dfe8__0[0xaU] = ((__Vtemp_he9db3d2f__0[9U] 
                                   >> 0x1eU) | (__Vtemp_he9db3d2f__0[0xaU] 
                                                << 2U));
    __Vtemp_h9a67dfe8__0[0xbU] = ((__Vtemp_he9db3d2f__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_he9db3d2f__0[0xbU] 
                                                << 2U));
    __Vtemp_h9a67dfe8__0[0xcU] = ((__Vtemp_he9db3d2f__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_he9db3d2f__0[0xcU] 
                                                << 2U));
    __Vtemp_h9a67dfe8__0[0xdU] = ((__Vtemp_he9db3d2f__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_he9db3d2f__0[0xdU] 
                                                << 2U));
    __Vtemp_h9a67dfe8__0[0xeU] = ((__Vtemp_he9db3d2f__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_he9db3d2f__0[0xeU] 
                                                << 2U));
    __Vtemp_h9a67dfe8__0[0xfU] = ((__Vtemp_he9db3d2f__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_he9db3d2f__0[0xfU] 
                                                << 2U));
    __Vtemp_h9a67dfe8__0[0x10U] = ((__Vtemp_he9db3d2f__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x10U] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x11U] = ((__Vtemp_he9db3d2f__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x11U] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x12U] = ((__Vtemp_he9db3d2f__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x12U] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x13U] = ((__Vtemp_he9db3d2f__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x13U] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x14U] = ((__Vtemp_he9db3d2f__0[0x13U] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x14U] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x15U] = ((__Vtemp_he9db3d2f__0[0x14U] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x15U] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x16U] = ((__Vtemp_he9db3d2f__0[0x15U] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x16U] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x17U] = ((__Vtemp_he9db3d2f__0[0x16U] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x17U] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x18U] = ((__Vtemp_he9db3d2f__0[0x17U] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x18U] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x19U] = ((__Vtemp_he9db3d2f__0[0x18U] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x19U] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x1aU] = ((__Vtemp_he9db3d2f__0[0x19U] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x1aU] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x1bU] = ((__Vtemp_he9db3d2f__0[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x1bU] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x1cU] = ((__Vtemp_he9db3d2f__0[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x1cU] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x1dU] = ((__Vtemp_he9db3d2f__0[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x1dU] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x1eU] = ((__Vtemp_he9db3d2f__0[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x1eU] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x1fU] = ((__Vtemp_he9db3d2f__0[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x1fU] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x20U] = ((__Vtemp_he9db3d2f__0[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1039,1039,1039, __Vtemp_h9f382ccd__0, VTestHarness__ConstPool__CONST_h3892cc72_0, __Vtemp_h9a67dfe8__0);
    __Vtemp_h902ec0a1__0[1U] = (VTestHarness__ConstPool__CONST_h52851b57_0[1U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[1U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[1U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[1U] 
                                               & __Vtemp_hbae320a8__0[1U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[1U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[1U] 
                                                 & __Vtemp_h9f382ccd__0[1U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[1U])))));
    __Vtemp_h902ec0a1__0[2U] = (VTestHarness__ConstPool__CONST_h52851b57_0[2U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[2U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[2U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[2U] 
                                               & __Vtemp_hbae320a8__0[2U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[2U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[2U] 
                                                 & __Vtemp_h9f382ccd__0[2U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[2U])))));
    __Vtemp_h902ec0a1__0[3U] = (VTestHarness__ConstPool__CONST_h52851b57_0[3U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[3U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[3U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[3U] 
                                               & __Vtemp_hbae320a8__0[3U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[3U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[3U] 
                                                 & __Vtemp_h9f382ccd__0[3U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[3U])))));
    __Vtemp_h902ec0a1__0[4U] = (VTestHarness__ConstPool__CONST_h52851b57_0[4U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[4U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[4U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[4U] 
                                               & __Vtemp_hbae320a8__0[4U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[4U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[4U] 
                                                 & __Vtemp_h9f382ccd__0[4U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[4U])))));
    __Vtemp_h902ec0a1__0[5U] = (VTestHarness__ConstPool__CONST_h52851b57_0[5U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[5U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[5U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[5U] 
                                               & __Vtemp_hbae320a8__0[5U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[5U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[5U] 
                                                 & __Vtemp_h9f382ccd__0[5U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[5U])))));
    __Vtemp_h902ec0a1__0[6U] = (VTestHarness__ConstPool__CONST_h52851b57_0[6U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[6U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[6U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[6U] 
                                               & __Vtemp_hbae320a8__0[6U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[6U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[6U] 
                                                 & __Vtemp_h9f382ccd__0[6U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[6U])))));
    __Vtemp_h902ec0a1__0[7U] = (VTestHarness__ConstPool__CONST_h52851b57_0[7U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[7U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[7U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[7U] 
                                               & __Vtemp_hbae320a8__0[7U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[7U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[7U] 
                                                 & __Vtemp_h9f382ccd__0[7U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[7U])))));
    __Vtemp_h902ec0a1__0[8U] = (VTestHarness__ConstPool__CONST_h52851b57_0[8U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[8U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[8U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[8U] 
                                               & __Vtemp_hbae320a8__0[8U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[8U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[8U] 
                                                 & __Vtemp_h9f382ccd__0[8U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[8U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[0U] 
        = (VTestHarness__ConstPool__CONST_h52851b57_0[0U] 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
               ? VTestHarness__ConstPool__CONST_h478702bb_0[0U]
               : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[0U] 
                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                       ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[0U] 
                          & __Vtemp_hbae320a8__0[0U])
                       : VTestHarness__ConstPool__CONST_h478702bb_0[0U])) 
                  & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                         ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[0U] 
                            & __Vtemp_h9f382ccd__0[0U])
                         : VTestHarness__ConstPool__CONST_h478702bb_0[0U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[1U] 
        = __Vtemp_h902ec0a1__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[2U] 
        = __Vtemp_h902ec0a1__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[3U] 
        = __Vtemp_h902ec0a1__0[3U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[4U] 
        = __Vtemp_h902ec0a1__0[4U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[5U] 
        = __Vtemp_h902ec0a1__0[5U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[6U] 
        = __Vtemp_h902ec0a1__0[6U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[7U] 
        = __Vtemp_h902ec0a1__0[7U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[8U] 
        = __Vtemp_h902ec0a1__0[8U];
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__15239(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__15239\n"); );
    // Init
    VlWide<9>/*287:0*/ __Vtemp_he28a8599__0;
    VlWide<33>/*1055:0*/ __Vtemp_hd9c00275__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9dd30ecc__0;
    VlWide<33>/*1055:0*/ __Vtemp_h65421e99__0;
    VlWide<33>/*1055:0*/ __Vtemp_h4dc87755__0;
    VlWide<33>/*1055:0*/ __Vtemp_he9db3d2f__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9a67dfe8__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9f382ccd__0;
    VlWide<3>/*95:0*/ __Vtemp_h90020063__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__0;
    VlWide<4>/*127:0*/ __Vtemp_h9a9a6856__0;
    VlWide<4>/*127:0*/ __Vtemp_hca162495__0;
    VlWide<4>/*127:0*/ __Vtemp_hc961d23f__1;
    VlWide<4>/*127:0*/ __Vtemp_he64232b9__0;
    VlWide<4>/*127:0*/ __Vtemp_h065d5630__0;
    VlWide<9>/*287:0*/ __Vtemp_h7fa6d70d__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9f0c1c7a__0;
    VlWide<33>/*1055:0*/ __Vtemp_h9dd30ecc__1;
    VlWide<33>/*1055:0*/ __Vtemp_hdccc2f4a__0;
    VlWide<33>/*1055:0*/ __Vtemp_hb85dacb9__0;
    VlWide<33>/*1055:0*/ __Vtemp_h4ca68c52__0;
    VlWide<33>/*1055:0*/ __Vtemp_h5f27aecb__0;
    VlWide<33>/*1055:0*/ __Vtemp_hd990b716__0;
    // Body
    VL_EXTEND_WI(1027,4, __Vtemp_hd9c00275__0, ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                                 ? 
                                                (1U 
                                                 | (0xeU 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       << 1U)))
                                                 : 0U));
    VL_EXTEND_WI(1025,7, __Vtemp_h9dd30ecc__0, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)));
    __Vtemp_h65421e99__0[0U] = (__Vtemp_h9dd30ecc__0[0U] 
                                << 2U);
    __Vtemp_h65421e99__0[1U] = ((__Vtemp_h9dd30ecc__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[1U] 
                                              << 2U));
    __Vtemp_h65421e99__0[2U] = ((__Vtemp_h9dd30ecc__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[2U] 
                                              << 2U));
    __Vtemp_h65421e99__0[3U] = ((__Vtemp_h9dd30ecc__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[3U] 
                                              << 2U));
    __Vtemp_h65421e99__0[4U] = ((__Vtemp_h9dd30ecc__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[4U] 
                                              << 2U));
    __Vtemp_h65421e99__0[5U] = ((__Vtemp_h9dd30ecc__0[4U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[5U] 
                                              << 2U));
    __Vtemp_h65421e99__0[6U] = ((__Vtemp_h9dd30ecc__0[5U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[6U] 
                                              << 2U));
    __Vtemp_h65421e99__0[7U] = ((__Vtemp_h9dd30ecc__0[6U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[7U] 
                                              << 2U));
    __Vtemp_h65421e99__0[8U] = ((__Vtemp_h9dd30ecc__0[7U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[8U] 
                                              << 2U));
    __Vtemp_h65421e99__0[9U] = ((__Vtemp_h9dd30ecc__0[8U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__0[9U] 
                                              << 2U));
    __Vtemp_h65421e99__0[0xaU] = ((__Vtemp_h9dd30ecc__0[9U] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xaU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xbU] = ((__Vtemp_h9dd30ecc__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xbU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xcU] = ((__Vtemp_h9dd30ecc__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xcU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xdU] = ((__Vtemp_h9dd30ecc__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xdU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xeU] = ((__Vtemp_h9dd30ecc__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xeU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0xfU] = ((__Vtemp_h9dd30ecc__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0xfU] 
                                                << 2U));
    __Vtemp_h65421e99__0[0x10U] = ((__Vtemp_h9dd30ecc__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x10U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x11U] = ((__Vtemp_h9dd30ecc__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x11U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x12U] = ((__Vtemp_h9dd30ecc__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x12U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x13U] = ((__Vtemp_h9dd30ecc__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x13U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x14U] = ((__Vtemp_h9dd30ecc__0[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x14U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x15U] = ((__Vtemp_h9dd30ecc__0[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x15U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x16U] = ((__Vtemp_h9dd30ecc__0[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x16U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x17U] = ((__Vtemp_h9dd30ecc__0[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x17U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x18U] = ((__Vtemp_h9dd30ecc__0[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x18U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x19U] = ((__Vtemp_h9dd30ecc__0[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x19U] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1aU] = ((__Vtemp_h9dd30ecc__0[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1aU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1bU] = ((__Vtemp_h9dd30ecc__0[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1bU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1cU] = ((__Vtemp_h9dd30ecc__0[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1cU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1dU] = ((__Vtemp_h9dd30ecc__0[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1dU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1eU] = ((__Vtemp_h9dd30ecc__0[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1eU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x1fU] = ((__Vtemp_h9dd30ecc__0[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x1fU] 
                                                 << 2U));
    __Vtemp_h65421e99__0[0x20U] = ((__Vtemp_h9dd30ecc__0[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__0[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1027,1027,1027, __Vtemp_h4dc87755__0, __Vtemp_hd9c00275__0, __Vtemp_h65421e99__0);
    VL_EXTEND_WI(1037,7, __Vtemp_he9db3d2f__0, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xbU)));
    __Vtemp_h9a67dfe8__0[0U] = (__Vtemp_he9db3d2f__0[0U] 
                                << 2U);
    __Vtemp_h9a67dfe8__0[1U] = ((__Vtemp_he9db3d2f__0[0U] 
                                 >> 0x1eU) | (__Vtemp_he9db3d2f__0[1U] 
                                              << 2U));
    __Vtemp_h9a67dfe8__0[2U] = ((__Vtemp_he9db3d2f__0[1U] 
                                 >> 0x1eU) | (__Vtemp_he9db3d2f__0[2U] 
                                              << 2U));
    __Vtemp_h9a67dfe8__0[3U] = ((__Vtemp_he9db3d2f__0[2U] 
                                 >> 0x1eU) | (__Vtemp_he9db3d2f__0[3U] 
                                              << 2U));
    __Vtemp_h9a67dfe8__0[4U] = ((__Vtemp_he9db3d2f__0[3U] 
                                 >> 0x1eU) | (__Vtemp_he9db3d2f__0[4U] 
                                              << 2U));
    __Vtemp_h9a67dfe8__0[5U] = ((__Vtemp_he9db3d2f__0[4U] 
                                 >> 0x1eU) | (__Vtemp_he9db3d2f__0[5U] 
                                              << 2U));
    __Vtemp_h9a67dfe8__0[6U] = ((__Vtemp_he9db3d2f__0[5U] 
                                 >> 0x1eU) | (__Vtemp_he9db3d2f__0[6U] 
                                              << 2U));
    __Vtemp_h9a67dfe8__0[7U] = ((__Vtemp_he9db3d2f__0[6U] 
                                 >> 0x1eU) | (__Vtemp_he9db3d2f__0[7U] 
                                              << 2U));
    __Vtemp_h9a67dfe8__0[8U] = ((__Vtemp_he9db3d2f__0[7U] 
                                 >> 0x1eU) | (__Vtemp_he9db3d2f__0[8U] 
                                              << 2U));
    __Vtemp_h9a67dfe8__0[9U] = ((__Vtemp_he9db3d2f__0[8U] 
                                 >> 0x1eU) | (__Vtemp_he9db3d2f__0[9U] 
                                              << 2U));
    __Vtemp_h9a67dfe8__0[0xaU] = ((__Vtemp_he9db3d2f__0[9U] 
                                   >> 0x1eU) | (__Vtemp_he9db3d2f__0[0xaU] 
                                                << 2U));
    __Vtemp_h9a67dfe8__0[0xbU] = ((__Vtemp_he9db3d2f__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_he9db3d2f__0[0xbU] 
                                                << 2U));
    __Vtemp_h9a67dfe8__0[0xcU] = ((__Vtemp_he9db3d2f__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_he9db3d2f__0[0xcU] 
                                                << 2U));
    __Vtemp_h9a67dfe8__0[0xdU] = ((__Vtemp_he9db3d2f__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_he9db3d2f__0[0xdU] 
                                                << 2U));
    __Vtemp_h9a67dfe8__0[0xeU] = ((__Vtemp_he9db3d2f__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_he9db3d2f__0[0xeU] 
                                                << 2U));
    __Vtemp_h9a67dfe8__0[0xfU] = ((__Vtemp_he9db3d2f__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_he9db3d2f__0[0xfU] 
                                                << 2U));
    __Vtemp_h9a67dfe8__0[0x10U] = ((__Vtemp_he9db3d2f__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x10U] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x11U] = ((__Vtemp_he9db3d2f__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x11U] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x12U] = ((__Vtemp_he9db3d2f__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x12U] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x13U] = ((__Vtemp_he9db3d2f__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x13U] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x14U] = ((__Vtemp_he9db3d2f__0[0x13U] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x14U] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x15U] = ((__Vtemp_he9db3d2f__0[0x14U] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x15U] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x16U] = ((__Vtemp_he9db3d2f__0[0x15U] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x16U] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x17U] = ((__Vtemp_he9db3d2f__0[0x16U] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x17U] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x18U] = ((__Vtemp_he9db3d2f__0[0x17U] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x18U] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x19U] = ((__Vtemp_he9db3d2f__0[0x18U] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x19U] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x1aU] = ((__Vtemp_he9db3d2f__0[0x19U] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x1aU] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x1bU] = ((__Vtemp_he9db3d2f__0[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x1bU] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x1cU] = ((__Vtemp_he9db3d2f__0[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x1cU] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x1dU] = ((__Vtemp_he9db3d2f__0[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x1dU] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x1eU] = ((__Vtemp_he9db3d2f__0[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x1eU] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x1fU] = ((__Vtemp_he9db3d2f__0[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x1fU] 
                                                 << 2U));
    __Vtemp_h9a67dfe8__0[0x20U] = ((__Vtemp_he9db3d2f__0[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_he9db3d2f__0[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1039,1039,1039, __Vtemp_h9f382ccd__0, VTestHarness__ConstPool__CONST_h3892cc72_0, __Vtemp_h9a67dfe8__0);
    __Vtemp_he28a8599__0[1U] = (VTestHarness__ConstPool__CONST_h52851b57_0[1U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[1U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[1U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[1U] 
                                               & __Vtemp_h4dc87755__0[1U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[1U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[1U] 
                                                 & __Vtemp_h9f382ccd__0[1U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[1U])))));
    __Vtemp_he28a8599__0[2U] = (VTestHarness__ConstPool__CONST_h52851b57_0[2U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[2U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[2U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[2U] 
                                               & __Vtemp_h4dc87755__0[2U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[2U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[2U] 
                                                 & __Vtemp_h9f382ccd__0[2U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[2U])))));
    __Vtemp_he28a8599__0[3U] = (VTestHarness__ConstPool__CONST_h52851b57_0[3U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[3U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[3U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[3U] 
                                               & __Vtemp_h4dc87755__0[3U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[3U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[3U] 
                                                 & __Vtemp_h9f382ccd__0[3U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[3U])))));
    __Vtemp_he28a8599__0[4U] = (VTestHarness__ConstPool__CONST_h52851b57_0[4U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[4U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[4U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[4U] 
                                               & __Vtemp_h4dc87755__0[4U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[4U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[4U] 
                                                 & __Vtemp_h9f382ccd__0[4U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[4U])))));
    __Vtemp_he28a8599__0[5U] = (VTestHarness__ConstPool__CONST_h52851b57_0[5U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[5U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[5U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[5U] 
                                               & __Vtemp_h4dc87755__0[5U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[5U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[5U] 
                                                 & __Vtemp_h9f382ccd__0[5U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[5U])))));
    __Vtemp_he28a8599__0[6U] = (VTestHarness__ConstPool__CONST_h52851b57_0[6U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[6U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[6U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[6U] 
                                               & __Vtemp_h4dc87755__0[6U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[6U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[6U] 
                                                 & __Vtemp_h9f382ccd__0[6U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[6U])))));
    __Vtemp_he28a8599__0[7U] = (VTestHarness__ConstPool__CONST_h52851b57_0[7U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[7U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[7U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[7U] 
                                               & __Vtemp_h4dc87755__0[7U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[7U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[7U] 
                                                 & __Vtemp_h9f382ccd__0[7U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[7U])))));
    __Vtemp_he28a8599__0[8U] = (VTestHarness__ConstPool__CONST_h52851b57_0[8U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[8U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[8U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[8U] 
                                               & __Vtemp_h4dc87755__0[8U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[8U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[8U] 
                                                 & __Vtemp_h9f382ccd__0[8U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[8U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[0U] 
        = (VTestHarness__ConstPool__CONST_h52851b57_0[0U] 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
               ? VTestHarness__ConstPool__CONST_h478702bb_0[0U]
               : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[0U] 
                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                       ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[0U] 
                          & __Vtemp_h4dc87755__0[0U])
                       : VTestHarness__ConstPool__CONST_h478702bb_0[0U])) 
                  & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                         ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[0U] 
                            & __Vtemp_h9f382ccd__0[0U])
                         : VTestHarness__ConstPool__CONST_h478702bb_0[0U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[1U] 
        = __Vtemp_he28a8599__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[2U] 
        = __Vtemp_he28a8599__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[3U] 
        = __Vtemp_he28a8599__0[3U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[4U] 
        = __Vtemp_he28a8599__0[4U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[5U] 
        = __Vtemp_he28a8599__0[5U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[6U] 
        = __Vtemp_he28a8599__0[6U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[7U] 
        = __Vtemp_he28a8599__0[7U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight_opcodes[8U] 
        = __Vtemp_he28a8599__0[8U];
    __Vtemp_hc961d23f__0[0U] = 1U;
    __Vtemp_hc961d23f__0[1U] = 0U;
    __Vtemp_hc961d23f__0[2U] = 0U;
    __Vtemp_hc961d23f__0[3U] = 0U;
    VL_EXTEND_WI(128,7, __Vtemp_h9a9a6856__0, (0x7fU 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 0xaU)));
    VL_SHIFTL_WWW(128,128,128, __Vtemp_hca162495__0, __Vtemp_hc961d23f__0, __Vtemp_h9a9a6856__0);
    __Vtemp_hc961d23f__1[0U] = 1U;
    __Vtemp_hc961d23f__1[1U] = 0U;
    __Vtemp_hc961d23f__1[2U] = 0U;
    __Vtemp_hc961d23f__1[3U] = 0U;
    VL_EXTEND_WI(128,7, __Vtemp_he64232b9__0, (0x7fU 
                                               & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                  >> 0xbU)));
    VL_SHIFTL_WWW(128,128,128, __Vtemp_h065d5630__0, __Vtemp_hc961d23f__1, __Vtemp_he64232b9__0);
    if (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset) {
        __Vtemp_h90020063__0[1U] = 0U;
        __Vtemp_h90020063__0[2U] = 0U;
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight[0U] = 0U;
    } else {
        __Vtemp_h90020063__0[1U] = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight[1U] 
                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                         ? __Vtemp_hca162495__0[1U]
                                         : 0U)) & (~ 
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                                     ? 
                                                    __Vtemp_h065d5630__0[1U]
                                                     : 0U)));
        __Vtemp_h90020063__0[2U] = (1U & ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight[2U] 
                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                               ? __Vtemp_hca162495__0[2U]
                                               : 0U)) 
                                          & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                                 ? 
                                                __Vtemp_h065d5630__0[2U]
                                                 : 0U))));
        vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight[0U] 
            = ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight[0U] 
                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                    ? __Vtemp_hca162495__0[0U] : 0U)) 
               & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                      ? __Vtemp_h065d5630__0[0U] : 0U)));
    }
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight[1U] 
        = __Vtemp_h90020063__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_clockgater__DOT__fragmenter__DOT__monitor__DOT__inflight[2U] 
        = __Vtemp_h90020063__0[2U];
    VL_EXTEND_WI(1027,4, __Vtemp_h9f0c1c7a__0, ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                                 ? 
                                                (1U 
                                                 | (0xeU 
                                                    & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                       >> 5U)))
                                                 : 0U));
    VL_EXTEND_WI(1025,7, __Vtemp_h9dd30ecc__1, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__buffer__DOT__x1_a_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xaU)));
    __Vtemp_hdccc2f4a__0[0U] = (__Vtemp_h9dd30ecc__1[0U] 
                                << 2U);
    __Vtemp_hdccc2f4a__0[1U] = ((__Vtemp_h9dd30ecc__1[0U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[1U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[2U] = ((__Vtemp_h9dd30ecc__1[1U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[2U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[3U] = ((__Vtemp_h9dd30ecc__1[2U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[3U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[4U] = ((__Vtemp_h9dd30ecc__1[3U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[4U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[5U] = ((__Vtemp_h9dd30ecc__1[4U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[5U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[6U] = ((__Vtemp_h9dd30ecc__1[5U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[6U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[7U] = ((__Vtemp_h9dd30ecc__1[6U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[7U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[8U] = ((__Vtemp_h9dd30ecc__1[7U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[8U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[9U] = ((__Vtemp_h9dd30ecc__1[8U] 
                                 >> 0x1eU) | (__Vtemp_h9dd30ecc__1[9U] 
                                              << 2U));
    __Vtemp_hdccc2f4a__0[0xaU] = ((__Vtemp_h9dd30ecc__1[9U] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xaU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0xbU] = ((__Vtemp_h9dd30ecc__1[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xbU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0xcU] = ((__Vtemp_h9dd30ecc__1[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xcU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0xdU] = ((__Vtemp_h9dd30ecc__1[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xdU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0xeU] = ((__Vtemp_h9dd30ecc__1[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xeU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0xfU] = ((__Vtemp_h9dd30ecc__1[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0xfU] 
                                                << 2U));
    __Vtemp_hdccc2f4a__0[0x10U] = ((__Vtemp_h9dd30ecc__1[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x10U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x11U] = ((__Vtemp_h9dd30ecc__1[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x11U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x12U] = ((__Vtemp_h9dd30ecc__1[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x12U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x13U] = ((__Vtemp_h9dd30ecc__1[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x13U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x14U] = ((__Vtemp_h9dd30ecc__1[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x14U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x15U] = ((__Vtemp_h9dd30ecc__1[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x15U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x16U] = ((__Vtemp_h9dd30ecc__1[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x16U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x17U] = ((__Vtemp_h9dd30ecc__1[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x17U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x18U] = ((__Vtemp_h9dd30ecc__1[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x18U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x19U] = ((__Vtemp_h9dd30ecc__1[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x19U] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1aU] = ((__Vtemp_h9dd30ecc__1[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1aU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1bU] = ((__Vtemp_h9dd30ecc__1[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1bU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1cU] = ((__Vtemp_h9dd30ecc__1[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1cU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1dU] = ((__Vtemp_h9dd30ecc__1[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1dU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1eU] = ((__Vtemp_h9dd30ecc__1[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1eU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x1fU] = ((__Vtemp_h9dd30ecc__1[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x1fU] 
                                                 << 2U));
    __Vtemp_hdccc2f4a__0[0x20U] = ((__Vtemp_h9dd30ecc__1[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h9dd30ecc__1[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1027,1027,1027, __Vtemp_hb85dacb9__0, __Vtemp_h9f0c1c7a__0, __Vtemp_hdccc2f4a__0);
    VL_EXTEND_WI(1037,7, __Vtemp_h4ca68c52__0, (0x7fU 
                                                & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__buffer__DOT__bundleIn_0_d_q__DOT___ram_ext_R0_data[0U] 
                                                   >> 0xbU)));
    __Vtemp_h5f27aecb__0[0U] = (__Vtemp_h4ca68c52__0[0U] 
                                << 2U);
    __Vtemp_h5f27aecb__0[1U] = ((__Vtemp_h4ca68c52__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h4ca68c52__0[1U] 
                                              << 2U));
    __Vtemp_h5f27aecb__0[2U] = ((__Vtemp_h4ca68c52__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h4ca68c52__0[2U] 
                                              << 2U));
    __Vtemp_h5f27aecb__0[3U] = ((__Vtemp_h4ca68c52__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h4ca68c52__0[3U] 
                                              << 2U));
    __Vtemp_h5f27aecb__0[4U] = ((__Vtemp_h4ca68c52__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h4ca68c52__0[4U] 
                                              << 2U));
    __Vtemp_h5f27aecb__0[5U] = ((__Vtemp_h4ca68c52__0[4U] 
                                 >> 0x1eU) | (__Vtemp_h4ca68c52__0[5U] 
                                              << 2U));
    __Vtemp_h5f27aecb__0[6U] = ((__Vtemp_h4ca68c52__0[5U] 
                                 >> 0x1eU) | (__Vtemp_h4ca68c52__0[6U] 
                                              << 2U));
    __Vtemp_h5f27aecb__0[7U] = ((__Vtemp_h4ca68c52__0[6U] 
                                 >> 0x1eU) | (__Vtemp_h4ca68c52__0[7U] 
                                              << 2U));
    __Vtemp_h5f27aecb__0[8U] = ((__Vtemp_h4ca68c52__0[7U] 
                                 >> 0x1eU) | (__Vtemp_h4ca68c52__0[8U] 
                                              << 2U));
    __Vtemp_h5f27aecb__0[9U] = ((__Vtemp_h4ca68c52__0[8U] 
                                 >> 0x1eU) | (__Vtemp_h4ca68c52__0[9U] 
                                              << 2U));
    __Vtemp_h5f27aecb__0[0xaU] = ((__Vtemp_h4ca68c52__0[9U] 
                                   >> 0x1eU) | (__Vtemp_h4ca68c52__0[0xaU] 
                                                << 2U));
    __Vtemp_h5f27aecb__0[0xbU] = ((__Vtemp_h4ca68c52__0[0xaU] 
                                   >> 0x1eU) | (__Vtemp_h4ca68c52__0[0xbU] 
                                                << 2U));
    __Vtemp_h5f27aecb__0[0xcU] = ((__Vtemp_h4ca68c52__0[0xbU] 
                                   >> 0x1eU) | (__Vtemp_h4ca68c52__0[0xcU] 
                                                << 2U));
    __Vtemp_h5f27aecb__0[0xdU] = ((__Vtemp_h4ca68c52__0[0xcU] 
                                   >> 0x1eU) | (__Vtemp_h4ca68c52__0[0xdU] 
                                                << 2U));
    __Vtemp_h5f27aecb__0[0xeU] = ((__Vtemp_h4ca68c52__0[0xdU] 
                                   >> 0x1eU) | (__Vtemp_h4ca68c52__0[0xeU] 
                                                << 2U));
    __Vtemp_h5f27aecb__0[0xfU] = ((__Vtemp_h4ca68c52__0[0xeU] 
                                   >> 0x1eU) | (__Vtemp_h4ca68c52__0[0xfU] 
                                                << 2U));
    __Vtemp_h5f27aecb__0[0x10U] = ((__Vtemp_h4ca68c52__0[0xfU] 
                                    >> 0x1eU) | (__Vtemp_h4ca68c52__0[0x10U] 
                                                 << 2U));
    __Vtemp_h5f27aecb__0[0x11U] = ((__Vtemp_h4ca68c52__0[0x10U] 
                                    >> 0x1eU) | (__Vtemp_h4ca68c52__0[0x11U] 
                                                 << 2U));
    __Vtemp_h5f27aecb__0[0x12U] = ((__Vtemp_h4ca68c52__0[0x11U] 
                                    >> 0x1eU) | (__Vtemp_h4ca68c52__0[0x12U] 
                                                 << 2U));
    __Vtemp_h5f27aecb__0[0x13U] = ((__Vtemp_h4ca68c52__0[0x12U] 
                                    >> 0x1eU) | (__Vtemp_h4ca68c52__0[0x13U] 
                                                 << 2U));
    __Vtemp_h5f27aecb__0[0x14U] = ((__Vtemp_h4ca68c52__0[0x13U] 
                                    >> 0x1eU) | (__Vtemp_h4ca68c52__0[0x14U] 
                                                 << 2U));
    __Vtemp_h5f27aecb__0[0x15U] = ((__Vtemp_h4ca68c52__0[0x14U] 
                                    >> 0x1eU) | (__Vtemp_h4ca68c52__0[0x15U] 
                                                 << 2U));
    __Vtemp_h5f27aecb__0[0x16U] = ((__Vtemp_h4ca68c52__0[0x15U] 
                                    >> 0x1eU) | (__Vtemp_h4ca68c52__0[0x16U] 
                                                 << 2U));
    __Vtemp_h5f27aecb__0[0x17U] = ((__Vtemp_h4ca68c52__0[0x16U] 
                                    >> 0x1eU) | (__Vtemp_h4ca68c52__0[0x17U] 
                                                 << 2U));
    __Vtemp_h5f27aecb__0[0x18U] = ((__Vtemp_h4ca68c52__0[0x17U] 
                                    >> 0x1eU) | (__Vtemp_h4ca68c52__0[0x18U] 
                                                 << 2U));
    __Vtemp_h5f27aecb__0[0x19U] = ((__Vtemp_h4ca68c52__0[0x18U] 
                                    >> 0x1eU) | (__Vtemp_h4ca68c52__0[0x19U] 
                                                 << 2U));
    __Vtemp_h5f27aecb__0[0x1aU] = ((__Vtemp_h4ca68c52__0[0x19U] 
                                    >> 0x1eU) | (__Vtemp_h4ca68c52__0[0x1aU] 
                                                 << 2U));
    __Vtemp_h5f27aecb__0[0x1bU] = ((__Vtemp_h4ca68c52__0[0x1aU] 
                                    >> 0x1eU) | (__Vtemp_h4ca68c52__0[0x1bU] 
                                                 << 2U));
    __Vtemp_h5f27aecb__0[0x1cU] = ((__Vtemp_h4ca68c52__0[0x1bU] 
                                    >> 0x1eU) | (__Vtemp_h4ca68c52__0[0x1cU] 
                                                 << 2U));
    __Vtemp_h5f27aecb__0[0x1dU] = ((__Vtemp_h4ca68c52__0[0x1cU] 
                                    >> 0x1eU) | (__Vtemp_h4ca68c52__0[0x1dU] 
                                                 << 2U));
    __Vtemp_h5f27aecb__0[0x1eU] = ((__Vtemp_h4ca68c52__0[0x1dU] 
                                    >> 0x1eU) | (__Vtemp_h4ca68c52__0[0x1eU] 
                                                 << 2U));
    __Vtemp_h5f27aecb__0[0x1fU] = ((__Vtemp_h4ca68c52__0[0x1eU] 
                                    >> 0x1eU) | (__Vtemp_h4ca68c52__0[0x1fU] 
                                                 << 2U));
    __Vtemp_h5f27aecb__0[0x20U] = ((__Vtemp_h4ca68c52__0[0x1fU] 
                                    >> 0x1eU) | (__Vtemp_h4ca68c52__0[0x20U] 
                                                 << 2U));
    VL_SHIFTL_WWW(1039,1039,1039, __Vtemp_hd990b716__0, VTestHarness__ConstPool__CONST_h3892cc72_0, __Vtemp_h5f27aecb__0);
    __Vtemp_h7fa6d70d__0[1U] = (VTestHarness__ConstPool__CONST_h52851b57_0[1U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[1U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[1U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[1U] 
                                               & __Vtemp_hb85dacb9__0[1U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[1U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[1U] 
                                                 & __Vtemp_hd990b716__0[1U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[1U])))));
    __Vtemp_h7fa6d70d__0[2U] = (VTestHarness__ConstPool__CONST_h52851b57_0[2U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[2U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[2U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[2U] 
                                               & __Vtemp_hb85dacb9__0[2U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[2U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[2U] 
                                                 & __Vtemp_hd990b716__0[2U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[2U])))));
    __Vtemp_h7fa6d70d__0[3U] = (VTestHarness__ConstPool__CONST_h52851b57_0[3U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[3U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[3U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[3U] 
                                               & __Vtemp_hb85dacb9__0[3U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[3U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[3U] 
                                                 & __Vtemp_hd990b716__0[3U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[3U])))));
    __Vtemp_h7fa6d70d__0[4U] = (VTestHarness__ConstPool__CONST_h52851b57_0[4U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[4U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[4U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[4U] 
                                               & __Vtemp_hb85dacb9__0[4U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[4U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[4U] 
                                                 & __Vtemp_hd990b716__0[4U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[4U])))));
    __Vtemp_h7fa6d70d__0[5U] = (VTestHarness__ConstPool__CONST_h52851b57_0[5U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[5U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[5U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[5U] 
                                               & __Vtemp_hb85dacb9__0[5U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[5U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[5U] 
                                                 & __Vtemp_hd990b716__0[5U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[5U])))));
    __Vtemp_h7fa6d70d__0[6U] = (VTestHarness__ConstPool__CONST_h52851b57_0[6U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[6U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[6U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[6U] 
                                               & __Vtemp_hb85dacb9__0[6U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[6U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[6U] 
                                                 & __Vtemp_hd990b716__0[6U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[6U])))));
    __Vtemp_h7fa6d70d__0[7U] = (VTestHarness__ConstPool__CONST_h52851b57_0[7U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[7U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[7U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[7U] 
                                               & __Vtemp_hb85dacb9__0[7U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[7U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[7U] 
                                                 & __Vtemp_hd990b716__0[7U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[7U])))));
    __Vtemp_h7fa6d70d__0[8U] = (VTestHarness__ConstPool__CONST_h52851b57_0[8U] 
                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
                                    ? VTestHarness__ConstPool__CONST_h478702bb_0[8U]
                                    : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[8U] 
                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                                            ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[8U] 
                                               & __Vtemp_hb85dacb9__0[8U])
                                            : VTestHarness__ConstPool__CONST_h478702bb_0[8U])) 
                                       & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                                              ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[8U] 
                                                 & __Vtemp_hd990b716__0[8U])
                                              : VTestHarness__ConstPool__CONST_h478702bb_0[8U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[0U] 
        = (VTestHarness__ConstPool__CONST_h52851b57_0[0U] 
           & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___resetSynchronizer_auto_out_member_allClocks_subsystem_cbus_0_reset)
               ? VTestHarness__ConstPool__CONST_h478702bb_0[0U]
               : ((vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[0U] 
                   | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT___T_1118)
                       ? (VTestHarness__ConstPool__CONST_hf1d99c76_0[0U] 
                          & __Vtemp_hb85dacb9__0[0U])
                       : VTestHarness__ConstPool__CONST_h478702bb_0[0U])) 
                  & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT___T_1133)
                         ? (VTestHarness__ConstPool__CONST_hf1d81c7e_0[0U] 
                            & __Vtemp_hd990b716__0[0U])
                         : VTestHarness__ConstPool__CONST_h478702bb_0[0U])))));
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[1U] 
        = __Vtemp_h7fa6d70d__0[1U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[2U] 
        = __Vtemp_h7fa6d70d__0[2U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[3U] 
        = __Vtemp_h7fa6d70d__0[3U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[4U] 
        = __Vtemp_h7fa6d70d__0[4U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[5U] 
        = __Vtemp_h7fa6d70d__0[5U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[6U] 
        = __Vtemp_h7fa6d70d__0[6U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[7U] 
        = __Vtemp_h7fa6d70d__0[7U];
    vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_cbus__DOT__coupler_to_slave_named_tileresetsetter__DOT__fragmenter__DOT__monitor__DOT__inflight_sizes[8U] 
        = __Vtemp_h7fa6d70d__0[8U];
}
