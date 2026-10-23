// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTestHarness.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTestHarness__Syms.h"
#include "VTestHarness___024root.h"

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11476(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11476\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__no_wait)) 
                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH) 
                           >> 1U)) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (6U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_hit)
                                 ? (0xfU & ((0x4208U 
                                             | (((0x2000U 
                                                  & ((~ (IData)(
                                                                (0U 
                                                                 != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                     << 0xdU)) 
                                                 | (0x1000U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 0xcU))) 
                                                | ((0x100U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 8U)) 
                                                   | (0x10U 
                                                      & ((~ (IData)(
                                                                    (0U 
                                                                     != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                         << 4U))))) 
                                            >> (0xfU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_state) 
                                                   << 2U))))
                                 : 8U))) & (7U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
                                                            & ((~ (IData)(
                                                                          (0U 
                                                                           != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                               << 0xdU)) 
                                                           | (0x1000U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 0xcU))) 
                                                          | ((0x100U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 8U)) 
                                                             | (0x10U 
                                                                & ((~ (IData)(
                                                                              (0U 
                                                                               != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                                   << 4U))))) 
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:648: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1: Assertion failed: State transition from S_TIP_D to S_TIP should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 648, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:649:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:650: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 650, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11477(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11477\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__no_wait)) 
                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH) 
                           >> 1U)) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (6U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_hit)
                                 ? (0xfU & ((0x4208U 
                                             | (((0x2000U 
                                                  & ((~ (IData)(
                                                                (0U 
                                                                 != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                     << 0xdU)) 
                                                 | (0x1000U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 0xcU))) 
                                                | ((0x100U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 8U)) 
                                                   | (0x10U 
                                                      & ((~ (IData)(
                                                                    (0U 
                                                                     != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                         << 4U))))) 
                                            >> (0xfU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_state) 
                                                   << 2U))))
                                 : 8U))) & (5U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
                                                            & ((~ (IData)(
                                                                          (0U 
                                                                           != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                               << 0xdU)) 
                                                           | (0x1000U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 0xcU))) 
                                                          | ((0x100U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 8U)) 
                                                             | (0x10U 
                                                                & ((~ (IData)(
                                                                              (0U 
                                                                               != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                                   << 4U))))) 
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:654: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1: Assertion failed: State transition from S_TIP_D to S_TIP_C should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 654, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:655:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:656: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 656, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11478(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11478\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__no_wait)) 
                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH) 
                           >> 1U)) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (6U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_hit)
                                 ? (0xfU & ((0x4208U 
                                             | (((0x2000U 
                                                  & ((~ (IData)(
                                                                (0U 
                                                                 != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                     << 0xdU)) 
                                                 | (0x1000U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 0xcU))) 
                                                | ((0x100U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 8U)) 
                                                   | (0x10U 
                                                      & ((~ (IData)(
                                                                    (0U 
                                                                     != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                         << 4U))))) 
                                            >> (0xfU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_state) 
                                                   << 2U))))
                                 : 8U))) & (4U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
                                                            & ((~ (IData)(
                                                                          (0U 
                                                                           != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                               << 0xdU)) 
                                                           | (0x1000U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 0xcU))) 
                                                          | ((0x100U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 8U)) 
                                                             | (0x10U 
                                                                & ((~ (IData)(
                                                                              (0U 
                                                                               != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                                   << 4U))))) 
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:660: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1: Assertion failed: State transition from S_TIP_D to S_TIP_CD should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 660, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:661:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:662: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 662, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11479(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11479\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__no_wait)) 
                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH) 
                           >> 1U)) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (6U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_hit)
                                 ? (0xfU & ((0x4208U 
                                             | (((0x2000U 
                                                  & ((~ (IData)(
                                                                (0U 
                                                                 != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                     << 0xdU)) 
                                                 | (0x1000U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 0xcU))) 
                                                | ((0x100U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 8U)) 
                                                   | (0x10U 
                                                      & ((~ (IData)(
                                                                    (0U 
                                                                     != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                         << 4U))))) 
                                            >> (0xfU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_state) 
                                                   << 2U))))
                                 : 8U))) & (3U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
                                                            & ((~ (IData)(
                                                                          (0U 
                                                                           != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                               << 0xdU)) 
                                                           | (0x1000U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 0xcU))) 
                                                          | ((0x100U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 8U)) 
                                                             | (0x10U 
                                                                & ((~ (IData)(
                                                                              (0U 
                                                                               != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                                   << 4U))))) 
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:666: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1: Assertion failed: State transition from S_TIP_D to S_TRUNK_C should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 666, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:667:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:668: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 668, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11480(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11480\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__no_wait)) 
                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH) 
                           >> 1U)) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (4U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_hit)
                                 ? (0xfU & ((0x4208U 
                                             | (((0x2000U 
                                                  & ((~ (IData)(
                                                                (0U 
                                                                 != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                     << 0xdU)) 
                                                 | (0x1000U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 0xcU))) 
                                                | ((0x100U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 8U)) 
                                                   | (0x10U 
                                                      & ((~ (IData)(
                                                                    (0U 
                                                                     != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                         << 4U))))) 
                                            >> (0xfU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_state) 
                                                   << 2U))))
                                 : 8U))) & (8U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
                                                            & ((~ (IData)(
                                                                          (0U 
                                                                           != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                               << 0xdU)) 
                                                           | (0x1000U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 0xcU))) 
                                                          | ((0x100U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 8U)) 
                                                             | (0x10U 
                                                                & ((~ (IData)(
                                                                              (0U 
                                                                               != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                                   << 4U))))) 
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:672: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1: Assertion failed: State transition from S_TIP_CD to S_INVALID should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 672, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:673:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:674: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 674, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11481(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11481\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__no_wait)) 
                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH) 
                           >> 1U)) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (4U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_hit)
                                 ? (0xfU & ((0x4208U 
                                             | (((0x2000U 
                                                  & ((~ (IData)(
                                                                (0U 
                                                                 != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                     << 0xdU)) 
                                                 | (0x1000U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 0xcU))) 
                                                | ((0x100U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 8U)) 
                                                   | (0x10U 
                                                      & ((~ (IData)(
                                                                    (0U 
                                                                     != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                         << 4U))))) 
                                            >> (0xfU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_state) 
                                                   << 2U))))
                                 : 8U))) & (1U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
                                                            & ((~ (IData)(
                                                                          (0U 
                                                                           != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                               << 0xdU)) 
                                                           | (0x1000U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 0xcU))) 
                                                          | ((0x100U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 8U)) 
                                                             | (0x10U 
                                                                & ((~ (IData)(
                                                                              (0U 
                                                                               != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                                   << 4U))))) 
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:678: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1: Assertion failed: State transition from S_TIP_CD to S_BRANCH should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 678, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:679:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:680: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 680, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11482(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11482\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__no_wait)) 
                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH) 
                           >> 1U)) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (4U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_hit)
                                 ? (0xfU & ((0x4208U 
                                             | (((0x2000U 
                                                  & ((~ (IData)(
                                                                (0U 
                                                                 != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                     << 0xdU)) 
                                                 | (0x1000U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 0xcU))) 
                                                | ((0x100U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 8U)) 
                                                   | (0x10U 
                                                      & ((~ (IData)(
                                                                    (0U 
                                                                     != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                         << 4U))))) 
                                            >> (0xfU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_state) 
                                                   << 2U))))
                                 : 8U))) & (0U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
                                                            & ((~ (IData)(
                                                                          (0U 
                                                                           != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                               << 0xdU)) 
                                                           | (0x1000U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 0xcU))) 
                                                          | ((0x100U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 8U)) 
                                                             | (0x10U 
                                                                & ((~ (IData)(
                                                                              (0U 
                                                                               != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                                   << 4U))))) 
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:684: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1: Assertion failed: State transition from S_TIP_CD to S_BRANCH_C should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 684, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:685:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:686: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 686, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11483(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11483\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__no_wait)) 
                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH) 
                           >> 1U)) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (4U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_hit)
                                 ? (0xfU & ((0x4208U 
                                             | (((0x2000U 
                                                  & ((~ (IData)(
                                                                (0U 
                                                                 != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                     << 0xdU)) 
                                                 | (0x1000U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 0xcU))) 
                                                | ((0x100U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 8U)) 
                                                   | (0x10U 
                                                      & ((~ (IData)(
                                                                    (0U 
                                                                     != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                         << 4U))))) 
                                            >> (0xfU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_state) 
                                                   << 2U))))
                                 : 8U))) & (7U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
                                                            & ((~ (IData)(
                                                                          (0U 
                                                                           != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                               << 0xdU)) 
                                                           | (0x1000U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 0xcU))) 
                                                          | ((0x100U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 8U)) 
                                                             | (0x10U 
                                                                & ((~ (IData)(
                                                                              (0U 
                                                                               != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                                   << 4U))))) 
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:690: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1: Assertion failed: State transition from S_TIP_CD to S_TIP should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 690, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:691:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:692: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 692, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11484(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11484\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__no_wait)) 
                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH) 
                           >> 1U)) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (4U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_hit)
                                 ? (0xfU & ((0x4208U 
                                             | (((0x2000U 
                                                  & ((~ (IData)(
                                                                (0U 
                                                                 != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                     << 0xdU)) 
                                                 | (0x1000U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 0xcU))) 
                                                | ((0x100U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 8U)) 
                                                   | (0x10U 
                                                      & ((~ (IData)(
                                                                    (0U 
                                                                     != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                         << 4U))))) 
                                            >> (0xfU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_state) 
                                                   << 2U))))
                                 : 8U))) & (5U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
                                                            & ((~ (IData)(
                                                                          (0U 
                                                                           != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                               << 0xdU)) 
                                                           | (0x1000U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 0xcU))) 
                                                          | ((0x100U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 8U)) 
                                                             | (0x10U 
                                                                & ((~ (IData)(
                                                                              (0U 
                                                                               != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                                   << 4U))))) 
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:696: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1: Assertion failed: State transition from S_TIP_CD to S_TIP_C should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 696, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:697:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:698: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 698, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11485(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11485\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__no_wait)) 
                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH) 
                           >> 1U)) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (4U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_hit)
                                 ? (0xfU & ((0x4208U 
                                             | (((0x2000U 
                                                  & ((~ (IData)(
                                                                (0U 
                                                                 != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                     << 0xdU)) 
                                                 | (0x1000U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 0xcU))) 
                                                | ((0x100U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 8U)) 
                                                   | (0x10U 
                                                      & ((~ (IData)(
                                                                    (0U 
                                                                     != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                         << 4U))))) 
                                            >> (0xfU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_state) 
                                                   << 2U))))
                                 : 8U))) & (3U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
                                                            & ((~ (IData)(
                                                                          (0U 
                                                                           != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                               << 0xdU)) 
                                                           | (0x1000U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 0xcU))) 
                                                          | ((0x100U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 8U)) 
                                                             | (0x10U 
                                                                & ((~ (IData)(
                                                                              (0U 
                                                                               != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                                   << 4U))))) 
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:702: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1: Assertion failed: State transition from S_TIP_CD to S_TRUNK_C should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 702, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:703:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:704: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 704, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11486(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11486\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__no_wait)) 
                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH) 
                           >> 1U)) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (3U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_hit)
                                 ? (0xfU & ((0x4208U 
                                             | (((0x2000U 
                                                  & ((~ (IData)(
                                                                (0U 
                                                                 != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                     << 0xdU)) 
                                                 | (0x1000U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 0xcU))) 
                                                | ((0x100U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 8U)) 
                                                   | (0x10U 
                                                      & ((~ (IData)(
                                                                    (0U 
                                                                     != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                         << 4U))))) 
                                            >> (0xfU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_state) 
                                                   << 2U))))
                                 : 8U))) & (8U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
                                                            & ((~ (IData)(
                                                                          (0U 
                                                                           != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                               << 0xdU)) 
                                                           | (0x1000U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 0xcU))) 
                                                          | ((0x100U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 8U)) 
                                                             | (0x10U 
                                                                & ((~ (IData)(
                                                                              (0U 
                                                                               != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                                   << 4U))))) 
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:708: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1: Assertion failed: State transition from S_TRUNK_C to S_INVALID should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 708, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:709:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:710: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 710, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11487(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11487\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__no_wait)) 
                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH) 
                           >> 1U)) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (3U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_hit)
                                 ? (0xfU & ((0x4208U 
                                             | (((0x2000U 
                                                  & ((~ (IData)(
                                                                (0U 
                                                                 != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                     << 0xdU)) 
                                                 | (0x1000U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 0xcU))) 
                                                | ((0x100U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 8U)) 
                                                   | (0x10U 
                                                      & ((~ (IData)(
                                                                    (0U 
                                                                     != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                         << 4U))))) 
                                            >> (0xfU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_state) 
                                                   << 2U))))
                                 : 8U))) & (1U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
                                                            & ((~ (IData)(
                                                                          (0U 
                                                                           != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                               << 0xdU)) 
                                                           | (0x1000U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 0xcU))) 
                                                          | ((0x100U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 8U)) 
                                                             | (0x10U 
                                                                & ((~ (IData)(
                                                                              (0U 
                                                                               != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                                   << 4U))))) 
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:714: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1: Assertion failed: State transition from S_TRUNK_C to S_BRANCH should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 714, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:715:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:716: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 716, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11488(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11488\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__no_wait)) 
                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH) 
                           >> 1U)) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (3U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_hit)
                                 ? (0xfU & ((0x4208U 
                                             | (((0x2000U 
                                                  & ((~ (IData)(
                                                                (0U 
                                                                 != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                     << 0xdU)) 
                                                 | (0x1000U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 0xcU))) 
                                                | ((0x100U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 8U)) 
                                                   | (0x10U 
                                                      & ((~ (IData)(
                                                                    (0U 
                                                                     != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                         << 4U))))) 
                                            >> (0xfU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_state) 
                                                   << 2U))))
                                 : 8U))) & (0U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
                                                            & ((~ (IData)(
                                                                          (0U 
                                                                           != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                               << 0xdU)) 
                                                           | (0x1000U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 0xcU))) 
                                                          | ((0x100U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 8U)) 
                                                             | (0x10U 
                                                                & ((~ (IData)(
                                                                              (0U 
                                                                               != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                                   << 4U))))) 
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:720: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1: Assertion failed: State transition from S_TRUNK_C to S_BRANCH_C should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 720, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:721:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:722: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 722, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11489(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11489\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__no_wait)) 
                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH) 
                           >> 1U)) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (2U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_hit)
                                 ? (0xfU & ((0x4208U 
                                             | (((0x2000U 
                                                  & ((~ (IData)(
                                                                (0U 
                                                                 != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                     << 0xdU)) 
                                                 | (0x1000U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 0xcU))) 
                                                | ((0x100U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 8U)) 
                                                   | (0x10U 
                                                      & ((~ (IData)(
                                                                    (0U 
                                                                     != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                         << 4U))))) 
                                            >> (0xfU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_state) 
                                                   << 2U))))
                                 : 8U))) & (8U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
                                                            & ((~ (IData)(
                                                                          (0U 
                                                                           != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                               << 0xdU)) 
                                                           | (0x1000U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 0xcU))) 
                                                          | ((0x100U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 8U)) 
                                                             | (0x10U 
                                                                & ((~ (IData)(
                                                                              (0U 
                                                                               != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                                   << 4U))))) 
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:726: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1: Assertion failed: State transition from S_TRUNK_CD to S_INVALID should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 726, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:727:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:728: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 728, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11490(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11490\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__no_wait)) 
                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH) 
                           >> 1U)) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (2U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_hit)
                                 ? (0xfU & ((0x4208U 
                                             | (((0x2000U 
                                                  & ((~ (IData)(
                                                                (0U 
                                                                 != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                     << 0xdU)) 
                                                 | (0x1000U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 0xcU))) 
                                                | ((0x100U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 8U)) 
                                                   | (0x10U 
                                                      & ((~ (IData)(
                                                                    (0U 
                                                                     != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                         << 4U))))) 
                                            >> (0xfU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_state) 
                                                   << 2U))))
                                 : 8U))) & (1U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
                                                            & ((~ (IData)(
                                                                          (0U 
                                                                           != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                               << 0xdU)) 
                                                           | (0x1000U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 0xcU))) 
                                                          | ((0x100U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 8U)) 
                                                             | (0x10U 
                                                                & ((~ (IData)(
                                                                              (0U 
                                                                               != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                                   << 4U))))) 
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:732: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1: Assertion failed: State transition from S_TRUNK_CD to S_BRANCH should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 732, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:733:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:734: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 734, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11491(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11491\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__no_wait)) 
                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH) 
                           >> 1U)) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (2U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_hit)
                                 ? (0xfU & ((0x4208U 
                                             | (((0x2000U 
                                                  & ((~ (IData)(
                                                                (0U 
                                                                 != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                     << 0xdU)) 
                                                 | (0x1000U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 0xcU))) 
                                                | ((0x100U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 8U)) 
                                                   | (0x10U 
                                                      & ((~ (IData)(
                                                                    (0U 
                                                                     != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                         << 4U))))) 
                                            >> (0xfU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_state) 
                                                   << 2U))))
                                 : 8U))) & (0U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
                                                            & ((~ (IData)(
                                                                          (0U 
                                                                           != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                               << 0xdU)) 
                                                           | (0x1000U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 0xcU))) 
                                                          | ((0x100U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 8U)) 
                                                             | (0x10U 
                                                                & ((~ (IData)(
                                                                              (0U 
                                                                               != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                                   << 4U))))) 
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:738: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1: Assertion failed: State transition from S_TRUNK_CD to S_BRANCH_C should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 738, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:739:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:740: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 740, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11492(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11492\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__no_wait)) 
                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH) 
                           >> 1U)) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (2U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_hit)
                                 ? (0xfU & ((0x4208U 
                                             | (((0x2000U 
                                                  & ((~ (IData)(
                                                                (0U 
                                                                 != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                     << 0xdU)) 
                                                 | (0x1000U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 0xcU))) 
                                                | ((0x100U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 8U)) 
                                                   | (0x10U 
                                                      & ((~ (IData)(
                                                                    (0U 
                                                                     != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                         << 4U))))) 
                                            >> (0xfU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_state) 
                                                   << 2U))))
                                 : 8U))) & (7U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
                                                            & ((~ (IData)(
                                                                          (0U 
                                                                           != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                               << 0xdU)) 
                                                           | (0x1000U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 0xcU))) 
                                                          | ((0x100U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 8U)) 
                                                             | (0x10U 
                                                                & ((~ (IData)(
                                                                              (0U 
                                                                               != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                                   << 4U))))) 
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:744: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1: Assertion failed: State transition from S_TRUNK_CD to S_TIP should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 744, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:745:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:746: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 746, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11493(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11493\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__no_wait)) 
                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH) 
                           >> 1U)) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (2U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_hit)
                                 ? (0xfU & ((0x4208U 
                                             | (((0x2000U 
                                                  & ((~ (IData)(
                                                                (0U 
                                                                 != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                     << 0xdU)) 
                                                 | (0x1000U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 0xcU))) 
                                                | ((0x100U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 8U)) 
                                                   | (0x10U 
                                                      & ((~ (IData)(
                                                                    (0U 
                                                                     != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                         << 4U))))) 
                                            >> (0xfU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_state) 
                                                   << 2U))))
                                 : 8U))) & (5U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
                                                            & ((~ (IData)(
                                                                          (0U 
                                                                           != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                               << 0xdU)) 
                                                           | (0x1000U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 0xcU))) 
                                                          | ((0x100U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 8U)) 
                                                             | (0x10U 
                                                                & ((~ (IData)(
                                                                              (0U 
                                                                               != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                                   << 4U))))) 
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:750: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1: Assertion failed: State transition from S_TRUNK_CD to S_TIP_C should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 750, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:751:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:752: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 752, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11494(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11494\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__no_wait)) 
                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH) 
                           >> 1U)) & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (2U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_hit)
                                 ? (0xfU & ((0x4208U 
                                             | (((0x2000U 
                                                  & ((~ (IData)(
                                                                (0U 
                                                                 != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                     << 0xdU)) 
                                                 | (0x1000U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 0xcU))) 
                                                | ((0x100U 
                                                    & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_dirty)) 
                                                       << 8U)) 
                                                   | (0x10U 
                                                      & ((~ (IData)(
                                                                    (0U 
                                                                     != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_clients)))) 
                                                         << 4U))))) 
                                            >> (0xfU 
                                                & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__meta_state) 
                                                   << 2U))))
                                 : 8U))) & (3U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
                                                            & ((~ (IData)(
                                                                          (0U 
                                                                           != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                               << 0xdU)) 
                                                           | (0x1000U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 0xcU))) 
                                                          | ((0x100U 
                                                              & ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_dirty)) 
                                                                 << 8U)) 
                                                             | (0x10U 
                                                                & ((~ (IData)(
                                                                              (0U 
                                                                               != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_clients)))) 
                                                                   << 4U))))) 
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:756: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1: Assertion failed: State transition from S_TRUNK_CD to S_TRUNK_C should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 756, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:757:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:758: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 758, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11495(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11495\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT____Vcellinp__abc_mshrs_1__io_allocate_valid) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__request_valid)) 
                           | (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__no_wait) 
                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH) 
                                  >> 1U)) & (((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_a_valid_output) 
                                                  | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_b_valid_output)) 
                                                 | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_c_valid_output)) 
                                                | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_d_valid_output)) 
                                               | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_e_valid_output)) 
                                              | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_x_valid_output)) 
                                             | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___io_schedule_bits_dir_valid_output)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:762: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1: Assertion failed\n    at MSHR.scala:531 assert (!request_valid || (no_wait && io.schedule.fire()))\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 762, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:763:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:764: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 764, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT___T_510) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__new_request_prio_2)) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_1__DOT__new_meta_hit))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:768: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1: Assertion failed\n    at MSHR.scala:583 assert (new_meta.hit)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 768, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:769:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:770: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_1\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 770, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11496(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11496\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_state))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_clients))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:450: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed\n    at MSHR.scala:103 assert (!meta.clients.orR)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 450, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:451:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:452: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 452, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_state))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_dirty)))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:456: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed\n    at MSHR.scala:104 assert (!meta.dirty)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 456, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:457:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:458: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 458, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11497(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11497\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_valid) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_state))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_dirty)))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:462: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed\n    at MSHR.scala:107 assert (!meta.dirty)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 462, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:463:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:464: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 464, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_valid) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_state))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_clients))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:468: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed\n    at MSHR.scala:110 assert (meta.clients.orR)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 468, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:469:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:470: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 470, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11498(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11498\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_valid) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_state))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_clients) 
                               & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_clients) 
                                  - (IData)(1U))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:474: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed\n    at MSHR.scala:111 assert ((meta.clients & (meta.clients - UInt(1))) === UInt(0)) // at most one\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 474, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:475:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:476: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 476, "");
        }
    }
    if (VL_UNLIKELY(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0) 
                     & (~ ((~ (((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_valid) 
                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_releaseack)) 
                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_rprobeacklast)) 
                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_pprobeacklast)) 
                               & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_grantfirst)))) 
                           | (~ ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_valid)) 
                                 | ((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_releaseack)) 
                                      | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_rprobeacklast))) 
                                     | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_pprobeacklast))) 
                                    & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_grantfirst)))))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:480: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed\n    at MSHR.scala:177 assert (!io.status.bits.nestB || !io.status.bits.blockB)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 480, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:481:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:482: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 482, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11499(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11499\n"); );
    // Body
    if (VL_UNLIKELY(((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0) 
                     & (~ ((~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_valid) 
                               & (((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_rprobeackfirst)) 
                                   | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_pprobeackfirst))) 
                                  | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__w_grantfirst))))) 
                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_valid)))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:486: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed\n    at MSHR.scala:178 assert (!io.status.bits.nestC || !io.status.bits.blockC)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 486, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:487:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:488: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 488, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__bad_grant) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_valid)) 
                           | (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_state))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:492: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed\n    at MSHR.scala:252 assert (!meta_valid || meta.state === BRANCH)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 492, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:493:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:494: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 494, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11500(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11500\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (8U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (5U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:498: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_INVALID to S_TIP_C should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 498, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:499:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:500: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 500, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11501(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11501\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (8U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (4U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:504: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_INVALID to S_TIP_CD should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 504, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:505:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:506: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 506, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11502(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11502\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (8U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (2U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:510: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_INVALID to S_TRUNK_CD should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 510, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:511:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:512: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 512, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11503(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11503\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (1U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (8U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:516: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_BRANCH to S_INVALID should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 516, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:517:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:518: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 518, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11504(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11504\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (1U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (5U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:522: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_BRANCH to S_TIP_C should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 522, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:523:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:524: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 524, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11505(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11505\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (1U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (4U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:528: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_BRANCH to S_TIP_CD should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 528, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:529:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:530: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 530, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11506(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11506\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (1U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (2U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:534: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_BRANCH to S_TRUNK_CD should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 534, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:535:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:536: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 536, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11507(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11507\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (0U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (8U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:540: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_BRANCH_C to S_INVALID should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 540, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:541:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:542: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 542, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11508(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11508\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (0U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (5U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:546: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_BRANCH_C to S_TIP_C should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 546, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:547:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:548: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 548, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11509(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11509\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (0U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (4U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:552: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_BRANCH_C to S_TIP_CD should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 552, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:553:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:554: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 554, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11510(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11510\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (0U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (2U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:558: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_BRANCH_C to S_TRUNK_CD should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 558, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:559:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:560: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 560, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11511(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11511\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (7U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (8U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:564: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TIP to S_INVALID should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 564, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:565:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:566: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 566, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11512(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11512\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (7U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (1U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:570: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TIP to S_BRANCH should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 570, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:571:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:572: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 572, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11513(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11513\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (7U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (0U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:576: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TIP to S_BRANCH_C should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 576, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:577:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:578: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 578, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11514(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11514\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (7U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (5U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:582: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TIP to S_TIP_C should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 582, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:583:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:584: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 584, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11515(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11515\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (7U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (4U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:588: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TIP to S_TIP_CD should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 588, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:589:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:590: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 590, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11516(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11516\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (7U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (2U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:594: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TIP to S_TRUNK_CD should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 594, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:595:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:596: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 596, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11517(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11517\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (5U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (8U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:600: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TIP_C to S_INVALID should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 600, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:601:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:602: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 602, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11518(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11518\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (5U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (1U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:606: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TIP_C to S_BRANCH should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 606, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:607:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:608: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 608, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11519(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11519\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (5U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (0U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:612: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TIP_C to S_BRANCH_C should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 612, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:613:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:614: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 614, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11520(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11520\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (5U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (4U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:618: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TIP_C to S_TIP_CD should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 618, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:619:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:620: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 620, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11521(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11521\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (5U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (2U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:624: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TIP_C to S_TRUNK_CD should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 624, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:625:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:626: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 626, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11522(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11522\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (6U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (8U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:630: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TIP_D to S_INVALID should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 630, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:631:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:632: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 632, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11523(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11523\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (6U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (1U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:636: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TIP_D to S_BRANCH should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 636, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:637:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:638: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 638, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11524(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11524\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (6U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (0U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:642: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TIP_D to S_BRANCH_C should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 642, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:643:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:644: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 644, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11525(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11525\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (6U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (7U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:648: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TIP_D to S_TIP should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 648, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:649:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:650: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 650, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11526(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11526\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (6U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (5U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:654: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TIP_D to S_TIP_C should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 654, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:655:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:656: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 656, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11527(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11527\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (6U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (4U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:660: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TIP_D to S_TIP_CD should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 660, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:661:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:662: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 662, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11528(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11528\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (6U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (3U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:666: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TIP_D to S_TRUNK_C should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 666, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:667:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:668: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 668, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11529(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11529\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (4U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (8U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:672: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TIP_CD to S_INVALID should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 672, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:673:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:674: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 674, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11530(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11530\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (4U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (1U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:678: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TIP_CD to S_BRANCH should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 678, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:679:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:680: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 680, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11531(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11531\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (4U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (0U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:684: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TIP_CD to S_BRANCH_C should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 684, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:685:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:686: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 686, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11532(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11532\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (4U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (7U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:690: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TIP_CD to S_TIP should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 690, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:691:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:692: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 692, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11533(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11533\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (4U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (5U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:696: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TIP_CD to S_TIP_C should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 696, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:697:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:698: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 698, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11534(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11534\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (4U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (3U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:702: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TIP_CD to S_TRUNK_C should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 702, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:703:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:704: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 704, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11535(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11535\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (3U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (8U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:708: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TRUNK_C to S_INVALID should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 708, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:709:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:710: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 710, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11536(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11536\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (3U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (1U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:714: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TRUNK_C to S_BRANCH should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 714, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:715:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:716: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 716, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11537(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11537\n"); );
    // Body
    if (VL_UNLIKELY(((((((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__s_writeback)) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__no_wait)) 
                        & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__mshr_selectOH)) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                      & (3U == ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT__meta_hit)
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
                                 : 8U))) & (0U == (0xfU 
                                                   & ((0x4208U 
                                                       | (((0x2000U 
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
                                                      >> 
                                                      (0xfU 
                                                       & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__abc_mshrs_0__DOT___io_schedule_bits_dir_bits_data_WIRE_state) 
                                                          << 2U)))))))) {
        VL_WRITEF("[%0t] %%Error: MSHR.sv:720: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0: Assertion failed: State transition from S_TRUNK_C to S_BRANCH_C should be impossible (false,true,true,true,true)\n    at MSHR.scala:357 assert(!(before === from.code && after === to.code), cf\"State transition from ${from} to ${to} should be impossible ${cfg}\")\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 720, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv:721:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: MSHR.sv:722: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.l2.mods_0.abc_mshrs_0\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/MSHR.sv", 722, "");
        }
    }
}
