// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VTestHarness.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "VTestHarness__Syms.h"
#include "VTestHarness___024root.h"

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11219(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11219\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source)) 
                                    | ((~ (IData)((0U 
                                                   != 
                                                   (7U 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source) 
                                                       >> 3U))))) 
                                       & (5U > (7U 
                                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))))) 
                                   | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                  | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                 | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                               | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                              | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                             | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                            | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                           | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:575: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel PutFull carries invalid source ID (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 575, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:576:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:577: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 577, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11220(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11220\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (0x3fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address 
                                        & (~ ((0xcU 
                                               >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_size))
                                               ? (0x1fffU 
                                                  & ((IData)(0x3fU) 
                                                     << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_size)))
                                               : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:581: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel PutFull address not aligned to size (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 581, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:582:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:583: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 583, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:587: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel PutFull carries invalid param (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 587, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:588:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:589: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 589, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11221(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11221\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_mask) 
                        != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_5) 
                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_5) 
                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address)) 
                             << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_5) 
                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_5) 
                                            & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address))) 
                                        << 6U) | ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_4) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_4) 
                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address)) 
                                                   << 5U) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_4) 
                                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_4) 
                                                          & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address))) 
                                                      << 4U) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_3) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_3) 
                                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address)) 
                                                         << 3U) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_3) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_3) 
                                                                & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address))) 
                                                            << 2U) 
                                                           | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_2) 
                                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_2) 
                                                                    & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address)))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:593: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel PutFull contains invalid mask (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 593, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:594:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:595: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 595, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11222(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11222\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source)) 
                                      | ((~ (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source) 
                                                         >> 3U))))) 
                                         & (5U > (7U 
                                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))))) 
                                     | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                    | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                   | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                  | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                 | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                               | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                              | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                             | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                            & (7U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_size))) 
                           & ((0x10000U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address 
                                            >> 0xcU)) 
                              | (8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address 
                                        >> 0x1cU)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:599: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel carries PutPartial type which is unexpected using diplomatic parameters (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 599, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:600:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:601: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 601, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11223(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11223\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source)) 
                                    | ((~ (IData)((0U 
                                                   != 
                                                   (7U 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source) 
                                                       >> 3U))))) 
                                       & (5U > (7U 
                                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))))) 
                                   | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                  | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                 | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                               | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                              | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                             | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                            | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                           | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:605: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel PutPartial carries invalid source ID (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 605, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:606:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:607: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 607, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11224(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11224\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (0x3fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address 
                                        & (~ ((0xcU 
                                               >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_size))
                                               ? (0x1fffU 
                                                  & ((IData)(0x3fU) 
                                                     << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_size)))
                                               : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:611: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel PutPartial address not aligned to size (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 611, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:612:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:613: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 613, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:617: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel PutPartial carries invalid param (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 617, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:618:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:619: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 619, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11225(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11225\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_mask) 
                               & (~ ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_5) 
                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_5) 
                                          & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address)) 
                                      << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_5) 
                                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_5) 
                                                     & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address))) 
                                                 << 6U) 
                                                | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_4) 
                                                     | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_4) 
                                                        & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address)) 
                                                    << 5U) 
                                                   | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_4) 
                                                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_4) 
                                                           & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address))) 
                                                       << 4U) 
                                                      | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_3) 
                                                           | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_3) 
                                                              & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address)) 
                                                          << 3U) 
                                                         | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_3) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_3) 
                                                                 & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address))) 
                                                             << 2U) 
                                                            | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_2) 
                                                                    & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address)) 
                                                                << 1U) 
                                                               | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_2) 
                                                                  | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_2) 
                                                                     & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address)))))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:623: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel PutPartial contains invalid mask (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 623, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:624:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:625: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 625, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11226(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11226\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source)) 
                                      | ((~ (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source) 
                                                         >> 3U))))) 
                                         & (5U > (7U 
                                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))))) 
                                     | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                    | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                   | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                  | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                 | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                               | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                              | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                             | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                            & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_size) 
                                  >> 2U))) & ((0x10000U 
                                               == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address 
                                                   >> 0xcU)) 
                                              | (8U 
                                                 == 
                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address 
                                                  >> 0x1cU)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:629: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel carries Arithmetic type which is unexpected using diplomatic parameters (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 629, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:630:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:631: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 631, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11227(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11227\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source)) 
                                    | ((~ (IData)((0U 
                                                   != 
                                                   (7U 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source) 
                                                       >> 3U))))) 
                                       & (5U > (7U 
                                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))))) 
                                   | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                  | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                 | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                               | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                              | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                             | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                            | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                           | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:635: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel Arithmetic carries invalid source ID (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 635, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:636:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:637: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 637, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11228(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11228\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (0x3fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address 
                                        & (~ ((0xcU 
                                               >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_size))
                                               ? (0x1fffU 
                                                  & ((IData)(0x3fU) 
                                                     << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_size)))
                                               : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:641: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel Arithmetic address not aligned to size (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 641, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:642:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:643: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 643, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (4U < (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:647: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel Arithmetic carries invalid opcode param (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 647, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:648:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:649: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 649, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11229(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11229\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_mask) 
                        != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_5) 
                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_5) 
                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address)) 
                             << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_5) 
                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_5) 
                                            & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address))) 
                                        << 6U) | ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_4) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_4) 
                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address)) 
                                                   << 5U) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_4) 
                                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_4) 
                                                          & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address))) 
                                                      << 4U) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_3) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_3) 
                                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address)) 
                                                         << 3U) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_3) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_3) 
                                                                & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address))) 
                                                            << 2U) 
                                                           | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_2) 
                                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_2) 
                                                                    & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address)))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:653: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel Arithmetic contains invalid mask (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 653, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:654:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:655: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 655, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11230(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11230\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source)) 
                                      | ((~ (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source) 
                                                         >> 3U))))) 
                                         & (5U > (7U 
                                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))))) 
                                     | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                    | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                   | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                  | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                 | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                               | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                              | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                             | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                            & (~ ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_size) 
                                  >> 2U))) & ((0x10000U 
                                               == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address 
                                                   >> 0xcU)) 
                                              | (8U 
                                                 == 
                                                 (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address 
                                                  >> 0x1cU)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:659: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel carries Logical type which is unexpected using diplomatic parameters (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 659, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:660:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:661: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 661, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11231(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11231\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source)) 
                                    | ((~ (IData)((0U 
                                                   != 
                                                   (7U 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source) 
                                                       >> 3U))))) 
                                       & (5U > (7U 
                                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))))) 
                                   | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                  | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                 | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                               | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                              | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                             | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                            | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                           | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:665: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel Logical carries invalid source ID (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 665, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:666:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:667: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 667, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11232(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11232\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (0x3fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address 
                                        & (~ ((0xcU 
                                               >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_size))
                                               ? (0x1fffU 
                                                  & ((IData)(0x3fU) 
                                                     << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_size)))
                                               : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:671: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel Logical address not aligned to size (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 671, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:672:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:673: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 673, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_param) 
                        >> 2U)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:677: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel Logical carries invalid opcode param (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 677, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:678:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:679: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 679, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11233(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11233\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_mask) 
                        != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_5) 
                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_5) 
                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address)) 
                             << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_5) 
                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_5) 
                                            & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address))) 
                                        << 6U) | ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_4) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_4) 
                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address)) 
                                                   << 5U) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_4) 
                                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_4) 
                                                          & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address))) 
                                                      << 4U) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_3) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_3) 
                                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address)) 
                                                         << 3U) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_3) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_3) 
                                                                & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address))) 
                                                            << 2U) 
                                                           | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_2) 
                                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_2) 
                                                                    & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address)))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:683: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel Logical contains invalid mask (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 683, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:684:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:685: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 685, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11234(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11234\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source)) 
                                      | ((~ (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source) 
                                                         >> 3U))))) 
                                         & (5U > (7U 
                                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))))) 
                                     | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                    | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                   | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                  | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                 | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                               | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                              | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                             | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                            & (7U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_size))) 
                           & (((2U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address 
                                       >> 0x10U)) | 
                               (0x10000U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address 
                                             >> 0xcU))) 
                              | (8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address 
                                        >> 0x1cU)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:689: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel carries Hint type which is unexpected using diplomatic parameters (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 689, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:690:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:691: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 691, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11235(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11235\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source)) 
                                    | ((~ (IData)((0U 
                                                   != 
                                                   (7U 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source) 
                                                       >> 3U))))) 
                                       & (5U > (7U 
                                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))))) 
                                   | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                  | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                 | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                                | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                               | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                              | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                             | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                            | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))) 
                           | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:695: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel Hint carries invalid source ID (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 695, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:696:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:697: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 697, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11236(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11236\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (0x3fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address 
                                        & (~ ((0xcU 
                                               >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_size))
                                               ? (0x1fffU 
                                                  & ((IData)(0x3fU) 
                                                     << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_size)))
                                               : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:701: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel Hint address not aligned to size (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 701, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:702:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:703: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 703, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (3U & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_param) 
                                     >> 1U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:707: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel Hint carries invalid opcode param (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 707, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:708:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:709: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 709, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11237(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11237\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_mask) 
                        != ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_5) 
                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_5) 
                                 & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address)) 
                             << 7U) | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_5) 
                                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_5) 
                                            & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address))) 
                                        << 6U) | ((
                                                   ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_4) 
                                                    | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_4) 
                                                       & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address)) 
                                                   << 5U) 
                                                  | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_4) 
                                                       | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_4) 
                                                          & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address))) 
                                                      << 4U) 
                                                     | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_3) 
                                                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_3) 
                                                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address)) 
                                                         << 3U) 
                                                        | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_3) 
                                                             | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_3) 
                                                                & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address))) 
                                                            << 2U) 
                                                           | ((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_2) 
                                                                | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_2) 
                                                                   & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address)) 
                                                               << 1U) 
                                                              | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_acc_2) 
                                                                 | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__mask_eq_2) 
                                                                    & (~ vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address)))))))))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:713: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel Hint contains invalid mask (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 713, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:714:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:715: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 715, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11238(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11238\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:719: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel Hint is corrupt (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 719, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:720:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:721: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 721, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:725: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel has invalid opcode (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 725, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:726:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:727: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 727, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source)) 
                                    | (IData)(((0U 
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
                           | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:731: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel ReleaseAck carries invalid source ID (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 731, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:732:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:733: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 733, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11239(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11239\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (3U > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:737: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel ReleaseAck smaller than a beat (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 737, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:738:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:739: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 739, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:743: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel ReleaseeAck carries invalid param (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 743, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:744:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:745: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 745, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11240(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11240\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:749: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel ReleaseAck is corrupt (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 749, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:750:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:751: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 751, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_denied)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:755: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel ReleaseAck is denied (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 755, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:756:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:757: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 757, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11241(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11241\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source)) 
                                    | (IData)(((0U 
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
                           | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:761: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel Grant carries invalid source ID (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 761, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:762:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:763: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 763, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11242(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11242\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_sink))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:767: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel Grant carries invalid sink ID (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 767, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:768:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:769: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 769, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (3U > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:773: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel Grant smaller than a beat (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 773, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:774:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:775: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 775, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11243(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11243\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:779: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel Grant carries invalid cap param (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 779, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:780:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:781: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 781, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:785: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel Grant carries toN param (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 785, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:786:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:787: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 787, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11244(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11244\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:791: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel Grant is corrupt (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 791, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:792:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:793: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 793, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source)) 
                                    | (IData)(((0U 
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
                           | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:797: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel GrantData carries invalid source ID (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 797, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:798:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:799: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 799, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11245(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11245\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_sink))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:803: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel GrantData carries invalid sink ID (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 803, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:804:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:805: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 805, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (3U > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:809: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel GrantData smaller than a beat (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 809, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:810:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:811: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 811, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11246(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11246\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:815: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel GrantData carries invalid cap param (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 815, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:816:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:817: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 817, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:821: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel GrantData carries toN param (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 821, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:822:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:823: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 823, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11247(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11247\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_denied)) 
                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_corrupt)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:827: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel GrantData is denied but not corrupt (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 827, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:828:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:829: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 829, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source)) 
                                    | (IData)(((0U 
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
                           | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:833: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel AccessAck carries invalid source ID (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 833, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:834:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:835: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 835, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11248(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11248\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:839: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel AccessAck carries invalid param (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 839, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:840:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:841: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 841, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:845: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel AccessAck is corrupt (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 845, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:846:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:847: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 847, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11249(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11249\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source)) 
                                    | (IData)(((0U 
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
                           | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:851: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel AccessAckData carries invalid source ID (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 851, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:852:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:853: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 853, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11250(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11250\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:857: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel AccessAckData carries invalid param (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 857, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:858:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:859: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 859, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_denied)) 
                           | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_corrupt)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:863: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel AccessAckData is denied but not corrupt (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 863, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:864:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:865: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 865, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11251(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11251\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source)) 
                                    | (IData)(((0U 
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
                           | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:869: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel HintAck carries invalid source ID (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 869, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:870:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:871: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 871, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11252(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11252\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:875: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel HintAck carries invalid param (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 875, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:876:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:877: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 877, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_corrupt)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:881: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel HintAck is corrupt (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 881, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:882:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:883: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 883, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11253(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11253\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceB__DOT__b_valid) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ ((((((IData)(((0U == (0x38U 
                                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))) 
                                        & (5U > (7U 
                                                 & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))))) 
                               | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))) 
                              | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))) 
                             | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))) 
                            | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))) 
                           & (((2U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                       >> 0x10U)) | 
                               (0x10000U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                             >> 0xcU))) 
                              | (8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                        >> 0x1cU)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:887: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'B' channel carries Probe type which is unexpected using diplomatic parameters (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 887, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:888:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:889: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 889, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceB__DOT__b_valid) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                    >> 0x1cU)) | (0x10000U 
                                                  == 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                                   >> 0xcU))) 
                           | (2U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address 
                                     >> 0x10U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:893: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'B' channel Probe carries unmanaged address (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 893, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:894:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:895: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 895, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11254(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11254\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceB__DOT__b_valid) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source)) 
                          << 5U) | ((0x10U & ((((((
                                                   (0xfffffff0U 
                                                    & (((0x1cU 
                                                         == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))
                                                         ? 0x1cU
                                                         : 0U) 
                                                       | ((0x1eU 
                                                           == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))
                                                           ? 0x1eU
                                                           : 0U))) 
                                                   | ((0x18U 
                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source)) 
                                                      << 4U)) 
                                                  | ((0x1aU 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))
                                                      ? 0x10U
                                                      : 0U)) 
                                                 | ((0x14U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))
                                                     ? 0x10U
                                                     : 0U)) 
                                                | ((0x16U 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))
                                                    ? 0x10U
                                                    : 0U)) 
                                               | ((0x10U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source)) 
                                                  << 4U)) 
                                              | ((0x12U 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))
                                                  ? 0x10U
                                                  : 0U))) 
                                    | ((8U & ((((((8U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source)) 
                                                  << 3U) 
                                                 | ((0x1cU 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))
                                                     ? 0x18U
                                                     : 0U)) 
                                                | ((0x1eU 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))
                                                    ? 0x18U
                                                    : 0U)) 
                                               | ((0x18U 
                                                   == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source)) 
                                                  << 3U)) 
                                              | ((0x1aU 
                                                  == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))
                                                  ? 0x18U
                                                  : 0U))) 
                                       | (7U & ((((
                                                   (((0x1cU 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))
                                                      ? 0x1cU
                                                      : 0U) 
                                                    | ((0x1eU 
                                                        == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))
                                                        ? 0x1eU
                                                        : 0U)) 
                                                   | ((0x1aU 
                                                       == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))
                                                       ? 0x1aU
                                                       : 0U)) 
                                                  | ((0x14U 
                                                      == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))
                                                      ? 0x14U
                                                      : 0U)) 
                                                 | ((0x16U 
                                                     == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))
                                                     ? 0x16U
                                                     : 0U)) 
                                                | ((0x12U 
                                                    == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))
                                                    ? 0x12U
                                                    : 0U)))))) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_source))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:899: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'B' channel Probe carries source that is not first source (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 899, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:900:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:901: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 901, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11255(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11255\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceB__DOT__b_valid) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (0x3fU & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__bundleIn_0_b_bits_address))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:905: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'B' channel Probe address not aligned to size (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 905, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:906:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:907: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 907, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT__mods_0__DOT__sourceB__DOT__b_valid) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (3U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__l2__DOT___mods_0_io_in_b_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:911: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'B' channel Probe carries invalid cap param (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 911, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:912:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:913: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 913, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                    >> 0x1cU)) | (0x10000U 
                                                  == 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                                   >> 0xcU))) 
                           | (2U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                     >> 0x10U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:917: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel ProbeAck carries unmanaged address (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 917, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:918:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:919: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 919, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11256(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11256\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source)) 
                                    | ((~ (IData)((0U 
                                                   != 
                                                   (7U 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source) 
                                                       >> 3U))))) 
                                       & (5U > (7U 
                                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))))) 
                                   | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                  | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                 | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                               | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                              | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                             | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                            | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                           | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:923: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel ProbeAck carries invalid source ID (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 923, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:924:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:925: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 925, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11257(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11257\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (3U > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:929: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel ProbeAck smaller than a beat (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 929, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:930:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:931: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 931, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (0x3fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                        & (~ ((0xcU 
                                               >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_size))
                                               ? (0x1fffU 
                                                  & ((IData)(0x3fU) 
                                                     << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_size)))
                                               : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:935: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel ProbeAck address not aligned to size (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 935, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:936:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:937: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 937, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11258(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11258\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_param)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:941: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel ProbeAck carries invalid report param (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 941, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:942:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:943: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 943, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (4U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_0) 
                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_c_q__DOT___ram_ext_R0_data[3U] 
                               >> 0xeU)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_1) 
                                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_2) 
                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_3) 
                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_4) 
                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:947: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel ProbeAck is corrupt (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 947, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:948:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:949: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 949, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11259(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11259\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                    >> 0x1cU)) | (0x10000U 
                                                  == 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                                   >> 0xcU))) 
                           | (2U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                     >> 0x10U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:953: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel ProbeAckData carries unmanaged address (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 953, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:954:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:955: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 955, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source)) 
                                    | ((~ (IData)((0U 
                                                   != 
                                                   (7U 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source) 
                                                       >> 3U))))) 
                                       & (5U > (7U 
                                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))))) 
                                   | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                  | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                 | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                               | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                              | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                             | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                            | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                           | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:959: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel ProbeAckData carries invalid source ID (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 959, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:960:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:961: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 961, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11260(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11260\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (3U > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:965: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel ProbeAckData smaller than a beat (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 965, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:966:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:967: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 967, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (0x3fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                        & (~ ((0xcU 
                                               >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_size))
                                               ? (0x1fffU 
                                                  & ((IData)(0x3fU) 
                                                     << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_size)))
                                               : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:971: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel ProbeAckData address not aligned to size (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 971, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:972:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:973: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 973, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11261(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11261\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (5U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_param)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:977: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel ProbeAckData carries invalid report param (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 977, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:978:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:979: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 979, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source)) 
                                      | ((~ (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source) 
                                                         >> 3U))))) 
                                         & (5U > (7U 
                                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))))) 
                                     | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                    | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                   | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                  | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                 | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                               | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                              | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                             | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                            & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_size))) 
                           & (((2U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                       >> 0x10U)) | 
                               (0x10000U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                             >> 0xcU))) 
                              | (8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                        >> 0x1cU)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:983: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel carries Release type unsupported by manager (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 983, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:984:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:985: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 985, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11262(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11262\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ ((((((((~ (IData)((0U != 
                                             (7U & 
                                              ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source) 
                                               >> 3U))))) 
                                 & (5U > (7U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source)))) 
                                | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                               | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                              | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                             | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                            & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_size))) 
                           & (((2U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                       >> 0x10U)) | 
                               (0x10000U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                             >> 0xcU))) 
                              | (8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                        >> 0x1cU)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:989: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel carries Release from a client which does not support Probe (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 989, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:990:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:991: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 991, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11263(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11263\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source)) 
                                    | ((~ (IData)((0U 
                                                   != 
                                                   (7U 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source) 
                                                       >> 3U))))) 
                                       & (5U > (7U 
                                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))))) 
                                   | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                  | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                 | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                               | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                              | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                             | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                            | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                           | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:995: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel Release carries invalid source ID (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 995, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:996:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:997: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 997, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11264(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11264\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (3U > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1001: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel Release smaller than a beat (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1001, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1002:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1003: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1003, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (0x3fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                        & (~ ((0xcU 
                                               >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_size))
                                               ? (0x1fffU 
                                                  & ((IData)(0x3fU) 
                                                     << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_size)))
                                               : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1007: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel Release address not aligned to size (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1007, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1008:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1009: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1009, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11265(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11265\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_param)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1013: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel Release carries invalid report param (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1013, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1014:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1015: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1015, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_0) 
                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_c_q__DOT___ram_ext_R0_data[3U] 
                               >> 0xeU)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_1) 
                                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_2) 
                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_3) 
                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_4) 
                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1019: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel Release is corrupt (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1019, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1020:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1021: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1021, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11266(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11266\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source)) 
                                      | ((~ (IData)(
                                                    (0U 
                                                     != 
                                                     (7U 
                                                      & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source) 
                                                         >> 3U))))) 
                                         & (5U > (7U 
                                                  & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))))) 
                                     | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                    | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                   | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                  | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                 | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                               | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                              | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                             | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                            & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_size))) 
                           & (((2U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                       >> 0x10U)) | 
                               (0x10000U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                             >> 0xcU))) 
                              | (8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                        >> 0x1cU)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1025: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel carries ReleaseData type unsupported by manager (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1025, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1026:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1027: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1027, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11267(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11267\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ ((((((((~ (IData)((0U != 
                                             (7U & 
                                              ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source) 
                                               >> 3U))))) 
                                 & (5U > (7U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source)))) 
                                | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                               | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                              | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                             | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                            & (6U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_size))) 
                           & (((2U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                       >> 0x10U)) | 
                               (0x10000U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                             >> 0xcU))) 
                              | (8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                        >> 0x1cU)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1031: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel carries Release from a client which does not support Probe (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1031, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1032:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1033: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1033, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11268(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11268\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source)) 
                                    | ((~ (IData)((0U 
                                                   != 
                                                   (7U 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source) 
                                                       >> 3U))))) 
                                       & (5U > (7U 
                                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))))) 
                                   | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                  | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                 | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                               | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                              | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                             | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                            | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                           | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1037: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel ReleaseData carries invalid source ID (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1037, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1038:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1039: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1039, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11269(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11269\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (3U > (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1043: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel ReleaseData smaller than a beat (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1043, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1044:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1045: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1045, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (0x3fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                        & (~ ((0xcU 
                                               >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_size))
                                               ? (0x1fffU 
                                                  & ((IData)(0x3fU) 
                                                     << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_size)))
                                               : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1049: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel ReleaseData address not aligned to size (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1049, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1050:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1051: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1051, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11270(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11270\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (6U == (6U & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_param)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1055: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel ReleaseData carries invalid report param (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1055, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1056:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1057: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1057, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                    >> 0x1cU)) | (0x10000U 
                                                  == 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                                   >> 0xcU))) 
                           | (2U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                     >> 0x10U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1061: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel AccessAck carries unmanaged address (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1061, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1062:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1063: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1063, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11271(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11271\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source)) 
                                    | ((~ (IData)((0U 
                                                   != 
                                                   (7U 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source) 
                                                       >> 3U))))) 
                                       & (5U > (7U 
                                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))))) 
                                   | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                  | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                 | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                               | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                              | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                             | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                            | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                           | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1067: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel AccessAck carries invalid source ID (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1067, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1068:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1069: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1069, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11272(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11272\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (0x3fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                        & (~ ((0xcU 
                                               >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_size))
                                               ? (0x1fffU 
                                                  & ((IData)(0x3fU) 
                                                     << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_size)))
                                               : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1073: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel AccessAck address not aligned to size (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1073, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1074:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1075: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1075, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1079: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel AccessAck carries invalid param (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1079, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1080:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1081: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1081, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11273(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11273\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_0) 
                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_c_q__DOT___ram_ext_R0_data[3U] 
                               >> 0xeU)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_1) 
                                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_2) 
                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_3) 
                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_4) 
                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1085: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel AccessAck is corrupt (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1085, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1086:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1087: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1087, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                    >> 0x1cU)) | (0x10000U 
                                                  == 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                                   >> 0xcU))) 
                           | (2U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                     >> 0x10U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1091: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel AccessAckData carries unmanaged address (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1091, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1092:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1093: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1093, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11274(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11274\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source)) 
                                    | ((~ (IData)((0U 
                                                   != 
                                                   (7U 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source) 
                                                       >> 3U))))) 
                                       & (5U > (7U 
                                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))))) 
                                   | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                  | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                 | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                               | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                              | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                             | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                            | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                           | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1097: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel AccessAckData carries invalid source ID (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1097, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1098:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1099: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1099, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11275(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11275\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (0x3fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                        & (~ ((0xcU 
                                               >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_size))
                                               ? (0x1fffU 
                                                  & ((IData)(0x3fU) 
                                                     << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_size)))
                                               : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1103: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel AccessAckData address not aligned to size (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1103, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1104:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1105: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1105, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (1U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1109: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel AccessAckData carries invalid param (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1109, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1110:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1111: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1111, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11276(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11276\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((8U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                    >> 0x1cU)) | (0x10000U 
                                                  == 
                                                  (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                                   >> 0xcU))) 
                           | (2U == (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                     >> 0x10U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1115: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel HintAck carries unmanaged address (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1115, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1116:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1117: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1117, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((((((((((0x20U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source)) 
                                    | ((~ (IData)((0U 
                                                   != 
                                                   (7U 
                                                    & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source) 
                                                       >> 3U))))) 
                                       & (5U > (7U 
                                                & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))))) 
                                   | (8U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                  | (0x1cU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                 | (0x1eU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                                | (0x18U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                               | (0x1aU == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                              | (0x14U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                             | (0x16U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                            | (0x10U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))) 
                           | (0x12U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1121: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel HintAck carries invalid source ID (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1121, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1122:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1123: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1123, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11277(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11277\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (0x3fU & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                                        & (~ ((0xcU 
                                               >= (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_size))
                                               ? (0x1fffU 
                                                  & ((IData)(0x3fU) 
                                                     << (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_size)))
                                               : 0U)))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1127: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel HintAck address not aligned to size (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1127, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1128:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1129: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1129, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1133: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel HintAck carries invalid param (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1133, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1134:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1135: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1135, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11278(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11278\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (2U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_0) 
                            & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__tile_prci_domain__DOT__buffer_1__DOT__x1_c_q__DOT___ram_ext_R0_data[3U] 
                               >> 0xeU)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_1) 
                                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                          | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_2) 
                             & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_1__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                         | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_3) 
                            & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_2__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U])) 
                        | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__muxStateEarly_2_4) 
                           & vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__coupler_from_tile_3__DOT__asink__DOT__x1_c_sink__DOT__io_deq_bits_deq_bits_reg__DOT__cdc_reg[0U]))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1139: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel HintAck is corrupt (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1139, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1140:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1141: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1141, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_e_valid) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (7U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_e_bits_sink))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1145: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'E' channels carries invalid sink ID (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1145, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1146:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1147: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1147, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11279(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11279\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__a_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__opcode))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1151: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel opcode changed within multibeat operation (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1151, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1152:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1153: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1153, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__a_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_param) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__param))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1157: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel param changed within multibeat operation (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1157, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1158:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1159: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1159, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11280(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11280\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__a_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_size) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1163: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel size changed within multibeat operation (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1163, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1164:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1165: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1165, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__a_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__source))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1169: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel source changed within multibeat operation (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1169, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1170:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1171: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1171, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11281(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11281\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__a_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_address 
                        != vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__address)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1175: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel address changed with multibeat operation (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1175, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1176:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1177: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1177, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__d_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__opcode_1))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1181: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel opcode changed within multibeat operation (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1181, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1182:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1183: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1183, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11282(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11282\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__d_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_param) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__param_1))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1187: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel param changed within multibeat operation (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1187, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1188:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1189: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1189, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__d_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_size) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__size_1))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1193: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel size changed within multibeat operation (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1193, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1194:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1195: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1195, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11283(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11283\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__d_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__source_1))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1199: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel source changed within multibeat operation (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1199, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1200:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1201: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1201, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__d_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_sink) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__sink))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1205: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel sink changed with multibeat operation (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1205, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1206:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1207: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1207, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11284(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11284\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__d_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_denied) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__denied))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1211: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel denied changed with multibeat operation (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1211, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1212:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1213: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1213, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__c_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_opcode) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__opcode_3))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1217: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel opcode changed within multibeat operation (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1217, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1218:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1219: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1219, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11285(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11285\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__c_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_param) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__param_3))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1223: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel param changed within multibeat operation (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1223, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1224:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1225: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1225, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__c_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_size) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__size_3))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1229: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel size changed within multibeat operation (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1229, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1230:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1231: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1231, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11286(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11286\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__c_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_source) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__source_3))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1235: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel source changed within multibeat operation (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1235, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1236:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1237: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1237, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_c_valid) 
                       & (0U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__c_first_counter))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_c_bits_address 
                        != vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__address_2)))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1241: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'C' channel address changed with multibeat operation (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1241, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1242:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1243: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1243, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11287(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11287\n"); );
    // Body
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT___T_2071) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (IData)((0x1ffffffffULL & (vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__inflight 
                                                  >> (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1247: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'A' channel re-used a source ID (connected at Configs.scala:112:26)\n    at Monitor.scala:42 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1247, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1248:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1249: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1249, "");
        }
    }
    if (VL_UNLIKELY((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT___T_2090) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ ((IData)(((0x20ULL >= (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source)))
                                     ? (0x1ffffffffULL 
                                        & VL_SHIFTR_QQQ(33,33,33, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__inflight, (QData)((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source))))
                                     : 0ULL)) | (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__same_cycle_resp)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1253: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel acknowledged for nothing inflight (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1253, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1254:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1255: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1255, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11288(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11288\n"); );
    // Body
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT___T_2090) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__same_cycle_resp)) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode)))))
                                 : 0U)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode) 
                                           == ((0x17U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(3U) 
                                                    * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode))))
                                                ? (7U 
                                                   & (0x951240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_opcode)))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1259: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel contains improper opcode response (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1259, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1260:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1261: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1261, "");
        }
    }
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT___T_2090) 
                       & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__same_cycle_resp)) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_size) 
                        != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_size))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1265: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel contains improper response size (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1265, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1266:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1267: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1267, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11289(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11289\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_h784f817f__0;
    VlWide<5>/*159:0*/ __Vtemp_h0dafea3a__0;
    VlWide<5>/*159:0*/ __Vtemp_h4cf76fbe__0;
    VlWide<5>/*159:0*/ __Vtemp_h784f817f__1;
    VlWide<5>/*159:0*/ __Vtemp_hb0ff957e__0;
    VlWide<5>/*159:0*/ __Vtemp_hc9ca4393__0;
    VlWide<5>/*159:0*/ __Vtemp_h784f817f__2;
    VlWide<5>/*159:0*/ __Vtemp_hc1868f3d__0;
    VlWide<5>/*159:0*/ __Vtemp_h427af19b__0;
    VlWide<5>/*159:0*/ __Vtemp_h784f817f__3;
    VlWide<5>/*159:0*/ __Vtemp_h4385e11a__0;
    VlWide<5>/*159:0*/ __Vtemp_h4b0c405f__0;
    // Body
    VL_EXTEND_WI(130,6, __Vtemp_h784f817f__0, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source));
    __Vtemp_h0dafea3a__0[0U] = (__Vtemp_h784f817f__0[0U] 
                                << 2U);
    __Vtemp_h0dafea3a__0[1U] = ((__Vtemp_h784f817f__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h784f817f__0[1U] 
                                              << 2U));
    __Vtemp_h0dafea3a__0[2U] = ((__Vtemp_h784f817f__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h784f817f__0[2U] 
                                              << 2U));
    __Vtemp_h0dafea3a__0[3U] = ((__Vtemp_h784f817f__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h784f817f__0[3U] 
                                              << 2U));
    __Vtemp_h0dafea3a__0[4U] = ((__Vtemp_h784f817f__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h784f817f__0[4U] 
                                              << 2U));
    VL_SHIFTR_WWW(132,132,132, __Vtemp_h4cf76fbe__0, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__inflight_opcodes, __Vtemp_h0dafea3a__0);
    VL_EXTEND_WI(130,6, __Vtemp_h784f817f__1, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source));
    __Vtemp_hb0ff957e__0[0U] = (__Vtemp_h784f817f__1[0U] 
                                << 2U);
    __Vtemp_hb0ff957e__0[1U] = ((__Vtemp_h784f817f__1[0U] 
                                 >> 0x1eU) | (__Vtemp_h784f817f__1[1U] 
                                              << 2U));
    __Vtemp_hb0ff957e__0[2U] = ((__Vtemp_h784f817f__1[1U] 
                                 >> 0x1eU) | (__Vtemp_h784f817f__1[2U] 
                                              << 2U));
    __Vtemp_hb0ff957e__0[3U] = ((__Vtemp_h784f817f__1[2U] 
                                 >> 0x1eU) | (__Vtemp_h784f817f__1[3U] 
                                              << 2U));
    __Vtemp_hb0ff957e__0[4U] = ((__Vtemp_h784f817f__1[3U] 
                                 >> 0x1eU) | (__Vtemp_h784f817f__1[4U] 
                                              << 2U));
    VL_SHIFTR_WWW(132,132,132, __Vtemp_hc9ca4393__0, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__inflight_opcodes, __Vtemp_hb0ff957e__0);
    VL_EXTEND_WI(130,6, __Vtemp_h784f817f__2, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source));
    __Vtemp_hc1868f3d__0[0U] = (__Vtemp_h784f817f__2[0U] 
                                << 2U);
    __Vtemp_hc1868f3d__0[1U] = ((__Vtemp_h784f817f__2[0U] 
                                 >> 0x1eU) | (__Vtemp_h784f817f__2[1U] 
                                              << 2U));
    __Vtemp_hc1868f3d__0[2U] = ((__Vtemp_h784f817f__2[1U] 
                                 >> 0x1eU) | (__Vtemp_h784f817f__2[2U] 
                                              << 2U));
    __Vtemp_hc1868f3d__0[3U] = ((__Vtemp_h784f817f__2[2U] 
                                 >> 0x1eU) | (__Vtemp_h784f817f__2[3U] 
                                              << 2U));
    __Vtemp_hc1868f3d__0[4U] = ((__Vtemp_h784f817f__2[3U] 
                                 >> 0x1eU) | (__Vtemp_h784f817f__2[4U] 
                                              << 2U));
    VL_SHIFTR_WWW(132,132,132, __Vtemp_h427af19b__0, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__inflight_opcodes, __Vtemp_hc1868f3d__0);
    VL_EXTEND_WI(130,6, __Vtemp_h784f817f__3, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source));
    __Vtemp_h4385e11a__0[0U] = (__Vtemp_h784f817f__3[0U] 
                                << 2U);
    __Vtemp_h4385e11a__0[1U] = ((__Vtemp_h784f817f__3[0U] 
                                 >> 0x1eU) | (__Vtemp_h784f817f__3[1U] 
                                              << 2U));
    __Vtemp_h4385e11a__0[2U] = ((__Vtemp_h784f817f__3[1U] 
                                 >> 0x1eU) | (__Vtemp_h784f817f__3[2U] 
                                              << 2U));
    __Vtemp_h4385e11a__0[3U] = ((__Vtemp_h784f817f__3[2U] 
                                 >> 0x1eU) | (__Vtemp_h784f817f__3[3U] 
                                              << 2U));
    __Vtemp_h4385e11a__0[4U] = ((__Vtemp_h784f817f__3[3U] 
                                 >> 0x1eU) | (__Vtemp_h784f817f__3[4U] 
                                              << 2U));
    VL_SHIFTR_WWW(132,132,132, __Vtemp_h4b0c405f__0, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__inflight_opcodes, __Vtemp_h4385e11a__0);
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT___T_2090) 
                       & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__same_cycle_resp))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ (((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode) 
                            == ((0x17U >= (0x1fU & 
                                           ((IData)(3U) 
                                            * (7U & 
                                               (__Vtemp_h4cf76fbe__0[0U] 
                                                >> 1U)))))
                                 ? (7U & (0x911240U 
                                          >> (0x1fU 
                                              & ((IData)(3U) 
                                                 * 
                                                 (7U 
                                                  & (__Vtemp_hc9ca4393__0[0U] 
                                                     >> 1U))))))
                                 : 0U)) | ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode) 
                                           == ((0x17U 
                                                >= 
                                                (0x1fU 
                                                 & ((IData)(3U) 
                                                    * 
                                                    (7U 
                                                     & (__Vtemp_h427af19b__0[0U] 
                                                        >> 1U)))))
                                                ? (7U 
                                                   & (0x951240U 
                                                      >> 
                                                      (0x1fU 
                                                       & ((IData)(3U) 
                                                          * 
                                                          (7U 
                                                           & (__Vtemp_h4b0c405f__0[0U] 
                                                              >> 1U))))))
                                                : 0U))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1271: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel contains improper opcode response (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1271, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1272:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1273: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1273, "");
        }
    }
}

VL_INLINE_OPT void VTestHarness___024root___sequent__TOP__11290(VTestHarness___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VTestHarness__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VTestHarness___024root___sequent__TOP__11290\n"); );
    // Init
    VlWide<5>/*159:0*/ __Vtemp_h784f817f__0;
    VlWide<5>/*159:0*/ __Vtemp_h0dafea3a__0;
    VlWide<5>/*159:0*/ __Vtemp_h752df9a4__0;
    // Body
    VL_EXTEND_WI(130,6, __Vtemp_h784f817f__0, (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source));
    __Vtemp_h0dafea3a__0[0U] = (__Vtemp_h784f817f__0[0U] 
                                << 2U);
    __Vtemp_h0dafea3a__0[1U] = ((__Vtemp_h784f817f__0[0U] 
                                 >> 0x1eU) | (__Vtemp_h784f817f__0[1U] 
                                              << 2U));
    __Vtemp_h0dafea3a__0[2U] = ((__Vtemp_h784f817f__0[1U] 
                                 >> 0x1eU) | (__Vtemp_h784f817f__0[2U] 
                                              << 2U));
    __Vtemp_h0dafea3a__0[3U] = ((__Vtemp_h784f817f__0[2U] 
                                 >> 0x1eU) | (__Vtemp_h784f817f__0[3U] 
                                              << 2U));
    __Vtemp_h0dafea3a__0[4U] = ((__Vtemp_h784f817f__0[3U] 
                                 >> 0x1eU) | (__Vtemp_h784f817f__0[4U] 
                                              << 2U));
    VL_SHIFTR_WWW(132,132,132, __Vtemp_h752df9a4__0, vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__inflight_sizes, __Vtemp_h0dafea3a__0);
    if (VL_UNLIKELY(((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT___T_2090) 
                       & (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__same_cycle_resp))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_size) 
                        != (7U & (__Vtemp_h752df9a4__0[0U] 
                                  >> 1U)))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1277: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: 'D' channel contains improper response size (connected at Configs.scala:112:26)\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1277, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1278:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1279: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1279, "");
        }
    }
    if (VL_UNLIKELY(((((((((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__bundleIn_0_d_q__DOT___io_deq_valid_output) 
                           & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__d_first_counter_1))) 
                          & (0U == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__monitor__DOT__a_first_counter_1))) 
                         & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_sbus__DOT__system_bus_xbar__DOT__bundleOut_1_out_1_valid)) 
                        & ((IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_a_bits_source) 
                           == (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_source))) 
                       & (6U != (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT___bundleIn_0_d_q_io_deq_bits_opcode))) 
                      & (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__resetSynchronizer__DOT__x1_member_allClocks_subsystem_sbus_1_reset_catcher__DOT__io_sync_reset_chain__DOT__output_chain__DOT__sync_0)) 
                     & (~ ((~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT___subsystem_sbus_auto_coupler_to_bus_named_subsystem_l2_widget_out_d_ready)) 
                           | (~ (IData)(vlSelf->TestHarness__DOT__chiptop__DOT__system__DOT__subsystem_l2_wrapper__DOT__InclusiveCache_inner_TLBuffer__DOT__x1_a_q__DOT__maybe_full))))))) {
        VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1283: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor: Assertion failed: ready check\n    at Monitor.scala:49 assert(cond, message)\n\n",
                  64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name());
        VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1283, "");
        if (VL_UNLIKELY(
                // $c function at /data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv:1284:14
done_reset
            )) {
            VL_WRITEF("[%0t] %%Error: TLMonitor_47.sv:1285: Assertion failed in %NTestHarness.chiptop.system.subsystem_l2_wrapper.InclusiveCache_inner_TLBuffer.monitor\n",
                      64,VL_TIME_UNITED_Q(1000),-9,
                      vlSymsp->name());
            VL_STOP_MT("/data1/gzh/EC/baseline/build/b3_20261023_141155_3qge7ayp/generated-src/chipyard.TestHarness.v1Config/gen-collateral/TLMonitor_47.sv", 1285, "");
        }
    }
}
